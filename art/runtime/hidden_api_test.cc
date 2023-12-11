/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "hidden_api.h"

#include <fstream>
#include <sstream>

#include "android-base/stringprintf.h"
#include "base/file_utils.h"
#include "base/sdk_version.h"
#include "base/stl_util.h"
#include "common_runtime_test.h"
#include "jni/jni_internal.h"
#include "proxy_test.h"
#include "well_known_classes.h"

namespace art {

using android::base::StringPrintf;
using hiddenapi::detail::MemberSignature;
using hiddenapi::detail::ShouldDenyAccessToMemberImpl;

// Should be the same as dalvik.system.VMRuntime.HIDE_MAXTARGETSDK_P_HIDDEN_APIS,
// dalvik.system.VMRuntime.HIDE_MAXTARGETSDK_Q_HIDDEN_APIS, and
// dalvik.system.VMRuntime.EXEMPT_TEST_API_ACCESS_VERIFICATION.
static constexpr uint64_t kHideMaxtargetsdkPHiddenApis = 149997251;
static constexpr uint64_t kHideMaxtargetsdkQHiddenApis = 149994052;
static constexpr uint64_t kAllowTestApiAccess = 166236554;


static bool Copy(const std::string& src, const std::string& dst, /*out*/ std::string* error_msg) {
  std::ifstream  src_stream(src, std::ios::binary);
  std::ofstream  dst_stream(dst, std::ios::binary);
  dst_stream << src_stream.rdbuf();
  src_stream.close();
  dst_stream.close();
  if (src_stream.good() && dst_stream.good()) {
    return true;
  } else {
    *error_msg = "Copy " + src + " => " + dst + " (src_good="
        + (src_stream.good() ? "true" : "false") + ", dst_good="
        + (dst_stream.good() ? "true" : "false") + ")";
    return false;
  }
}

static bool LoadDexFiles(const std::string& path,
                         ScopedObjectAccess& soa,
                         /* out */ std::vector<std::unique_ptr<const DexFile>>* dex_files,
                         /* out */ ObjPtr<mirror::ClassLoader>* class_loader,
                         /* out */ std::string* error_msg) REQUIRES_SHARED(Locks::mutator_lock_) {
  if (!ArtDexFileLoader().Open(path.c_str(),
                               path,
                               /* verify= */ true,
                               /* verify_checksum= */ true,
                               error_msg,
                               dex_files)) {
    return false;
  }

  ClassLinker* const linker = Runtime::Current()->GetClassLinker();

  StackHandleScope<2> hs(soa.Self());
  Handle<mirror::Class> h_class = hs.NewHandle(soa.Decode<mirror::Class>(
      WellKnownClasses::dalvik_system_PathClassLoader));
  Handle<mirror::ClassLoader> h_loader = hs.NewHandle(linker->CreateWellKnownClassLoader(
      soa.Self(),
      MakeNonOwningPointerVector(*dex_files),
      h_class,
      /* parent_loader= */ ScopedNullHandle<mirror::ClassLoader>(),
      /* shared_libraries= */ ScopedNullHandle<mirror::ObjectArray<mirror::ClassLoader>>()));
  for (const auto& dex_file : *dex_files) {
    linker->RegisterDexFile(*dex_file.get(), h_loader.Get());
  }

  *class_loader = h_loader.Get();
  return true;
}

static bool Remove(const std::string& path, /*out*/ std::string* error_msg) {
  if (TEMP_FAILURE_RETRY(remove(path.c_str())) == 0) {
    return true;
  }
  *error_msg = StringPrintf("Unable to remove(\"%s\"): %s", path.c_str(), strerror(errno));
  return false;
}

static bool CheckAllDexFilesInDomain(ObjPtr<mirror::ClassLoader> loader,
                                     const std::vector<std::unique_ptr<const DexFile>>& dex_files,
                                     hiddenapi::Domain expected_domain,
                                     /* out */ std::string* error_msg)
    REQUIRES_SHARED(Locks::mutator_lock_) {
  for (const auto& dex_file : dex_files) {
    hiddenapi::AccessContext context(loader, dex_file.get());
    if (context.GetDomain() != expected_domain) {
      std::stringstream ss;
      ss << dex_file->GetLocation() << ": access context domain does not match "
          << "(expected=" << static_cast<uint32_t>(expected_domain)
          << ", actual=" << static_cast<uint32_t>(context.GetDomain()) << ")";
      *error_msg = ss.str();
      return false;
    }
    if (dex_file->GetHiddenapiDomain() != expected_domain) {
      std::stringstream ss;
      ss << dex_file->GetLocation() << ": dex file domain does not match "
          << "(expected=" << static_cast<uint32_t>(expected_domain)
          << ", actual=" << static_cast<uint32_t>(dex_file->GetHiddenapiDomain()) << ")";
      *error_msg = ss.str();
      return false;
    }
  }

  return true;
}

class HiddenApiTest : public CommonRuntimeTest {
 protected:
  void SetUp() override {
    // Do the normal setup.
    CommonRuntimeTest::SetUp();
    self_ = Thread::Current();
    self_->TransitionFromSuspendedToRunnable();
    jclass_loader_ = LoadDex("HiddenApiSignatures");
    bool started = runtime_->Start();
    CHECK(started);

    class1_field1_ = GetArtField("mypackage/packagea/Class1", "field1", "I");
    class1_field12_ = GetArtField("mypackage/packagea/Class1", "field12", "I");
    class1_init_ = GetArtMethod("mypackage/packagea/Class1", "<init>", "()V");
    class1_method1_ = GetArtMethod("mypackage/packagea/Class1", "method1", "()V");
    class1_method1_i_ = GetArtMethod("mypackage/packagea/Class1", "method1", "(I)V");
    class1_method12_ = GetArtMethod("mypackage/packagea/Class1", "method12", "()V");
    class12_field1_ = GetArtField("mypackage/packagea/Class12", "field1", "I");
    class12_method1_ = GetArtMethod("mypackage/packagea/Class12", "method1", "()V");
    class2_field1_ = GetArtField("mypackage/packagea/Class2", "field1", "I");
    class2_method1_ = GetArtMethod("mypackage/packagea/Class2", "method1", "()V");
    class2_method1_i_ = GetArtMethod("mypackage/packagea/Class2", "method1", "(I)V");
    class3_field1_ = GetArtField("mypackage/packageb/Class3", "field1", "I");
    class3_method1_ = GetArtMethod("mypackage/packageb/Class3", "method1", "()V");
    class3_method1_i_ = GetArtMethod("mypackage/packageb/Class3", "method1", "(I)V");
  }

  ArtMethod* GetArtMethod(const char* class_name, const char* name, const char* signature) {
    JNIEnv* env = Thread::Current()->GetJniEnv();
    jclass klass = env->FindClass(class_name);
    jmethodID method_id = env->GetMethodID(klass, name, signature);
    ArtMethod* art_method = jni::DecodeArtMethod(method_id);
    return art_method;
  }

  ArtField* GetArtField(const char* class_name, const char* name, const char* signature) {
    JNIEnv* env = Thread::Current()->GetJniEnv();
    jclass klass = env->FindClass(class_name);
    jfieldID field_id = env->GetFieldID(klass, name, signature);
    ArtField* art_field = jni::DecodeArtField(field_id);
    return art_field;
  }

  void SetChangeIdState(uint64_t change, bool enabled) {
    CompatFramework& compat_framework = runtime_->GetCompatFramework();
    std::set<uint64_t> disabled_changes = compat_framework.GetDisabledCompatChanges();
    if (enabled) {
      disabled_changes.erase(change);
    } else {
      disabled_changes.insert(change);
    }
    compat_framework.SetDisabledCompatChanges(disabled_changes);
  }

  bool ShouldDenyAccess(hiddenapi::ApiList list) REQUIRES_SHARED(Locks::mutator_lock_) {
    // Choose parameters such that there are no side effects (AccessMethod::kNone)
    // and that the member is not on the exemptions list (here we choose one which
    // is not even in boot class path).
    return ShouldDenyAccessToMemberImpl(/* member= */ class1_field1_,
                                        list,
                                        /* access_method= */ hiddenapi::AccessMethod::kNone);
  }

  void TestLocation(const std::string& location, hiddenapi::Domain expected_domain) {
    ScopedObjectAccess soa(Thread::Current());
    std::vector<std::unique_ptr<const DexFile>> dex_files;
    std::string error_msg;
    ObjPtr<mirror::ClassLoader> class_loader;

    ASSERT_TRUE(Copy(GetTestDexFileName("Main"), location, &error_msg)) << error_msg;
    ASSERT_TRUE(LoadDexFiles(location, soa, &dex_files, &class_loader, &error_msg))
        << error_msg;
    ASSERT_GE(dex_files.size(), 1u);
    ASSERT_TRUE(CheckAllDexFilesInDomain(class_loader,
                                         dex_files,
                                         expected_domain,
                                         &error_msg)) << error_msg;

    dex_files.clear();
    ASSERT_TRUE(Remove(location, &error_msg)) << error_msg;
  }

 protected:
  Thread* self_;
  jobject jclass_loader_;
  ArtField* class1_field1_;
  ArtField* class1_field12_;
  ArtMethod* class1_init_;
  ArtMethod* class1_method1_;
  ArtMethod* class1_method1_i_;
  ArtMethod* class1_method12_;
  ArtField* class12_field1_;
  ArtMethod* class12_method1_;
  ArtField* class2_field1_;
  ArtMethod* class2_method1_;
  ArtMethod* class2_method1_i_;
  ArtField* class3_field1_;
  ArtMethod* class3_method1_;
  ArtMethod* class3_method1_i_;
};

TEST_F(HiddenApiTest, CheckGetActionFromRuntimeFlags) {
  ScopedObjectAccess soa(self_);

  runtime_->SetHiddenApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kJustWarn);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetR()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetQ()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetP()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetO()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Blocked()), false);

  runtime_->SetHiddenApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kEnabled);
  runtime_->SetTargetSdkVersion(
      static_cast<uint32_t>(hiddenapi::ApiList::MaxTargetO().GetMaxAllowedSdkVersion()));
  SetChangeIdState(kHideMaxtargetsdkPHiddenApis, false);
  SetChangeIdState(kHideMaxtargetsdkQHiddenApis, false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetR()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetQ()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetP()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetO()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Blocked()), true);

  runtime_->SetHiddenApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kEnabled);
  runtime_->SetTargetSdkVersion(
      static_cast<uint32_t>(hiddenapi::ApiList::MaxTargetO().GetMaxAllowedSdkVersion()) + 1);
  SetChangeIdState(kHideMaxtargetsdkPHiddenApis, false);
  SetChangeIdState(kHideMaxtargetsdkQHiddenApis, false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetR()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetQ()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetP()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetO()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Blocked()), true);
  SetChangeIdState(kHideMaxtargetsdkQHiddenApis, true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetQ()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetP()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetO()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Blocked()), true);

  runtime_->SetHiddenApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kEnabled);
  runtime_->SetTargetSdkVersion(
      static_cast<uint32_t>(hiddenapi::ApiList::MaxTargetP().GetMaxAllowedSdkVersion()) + 1);
  SetChangeIdState(kHideMaxtargetsdkPHiddenApis, true);
  SetChangeIdState(kHideMaxtargetsdkQHiddenApis, false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetR()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetQ()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetP()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetO()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Blocked()), true);

  runtime_->SetHiddenApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kEnabled);
  runtime_->SetTargetSdkVersion(
      static_cast<uint32_t>(hiddenapi::ApiList::MaxTargetQ().GetMaxAllowedSdkVersion()) + 1);
  SetChangeIdState(kHideMaxtargetsdkPHiddenApis, true);
  SetChangeIdState(kHideMaxtargetsdkQHiddenApis, true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetR()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetQ()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetP()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetO()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Blocked()), true);

  runtime_->SetHiddenApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kEnabled);
  runtime_->SetTargetSdkVersion(
      static_cast<uint32_t>(hiddenapi::ApiList::MaxTargetR().GetMaxAllowedSdkVersion()) + 1);
  SetChangeIdState(kHideMaxtargetsdkPHiddenApis, true);
  SetChangeIdState(kHideMaxtargetsdkQHiddenApis, true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetR()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetQ()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetP()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::MaxTargetO()), true);
  ASSERT_EQ(ShouldDenyAccess(hiddenapi::ApiList::Blocked()), true);
}

TEST_F(HiddenApiTest, CheckTestApiEnforcement) {
  ScopedObjectAccess soa(self_);

  runtime_->SetHiddenApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kEnabled);
  runtime_->SetTargetSdkVersion(
      static_cast<uint32_t>(hiddenapi::ApiList::MaxTargetR().GetMaxAllowedSdkVersion()) + 1);

  // Default case where all TestApis are treated like non-TestApi.
  runtime_->SetTestApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kEnabled);
  SetChangeIdState(kAllowTestApiAccess, false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetR()), true);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetQ()), true);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetP()), true);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetO()), true);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Blocked()), true);

  // A case where we want to allow access to TestApis.
  runtime_->SetTestApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kDisabled);
  SetChangeIdState(kAllowTestApiAccess, false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetR()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetQ()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetP()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetO()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Blocked()), false);

  // A second case where we want to allow access to TestApis.
  runtime_->SetTestApiEnforcementPolicy(hiddenapi::EnforcementPolicy::kEnabled);
  SetChangeIdState(kAllowTestApiAccess, true);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Sdk()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Unsupported()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetR()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetQ()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetP()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::MaxTargetO()), false);
  ASSERT_EQ(
      ShouldDenyAccess(hiddenapi::ApiList::TestApi() | hiddenapi::ApiList::Blocked()), false);
}

TEST_F(HiddenApiTest, CheckMembersRead) {
  ASSERT_NE(nullptr, class1_field1_);
  ASSERT_NE(nullptr, class1_field12_);
  ASSERT_NE(nullptr, class1_init_);
  ASSERT_NE(nullptr, class1_method1_);
  ASSERT_NE(nullptr, class1_method1_i_);
  ASSERT_NE(nullptr, class1_method12_);
  ASSERT_NE(nullptr, class12_field1_);
  ASSERT_NE(nullptr, class12_method1_);
  ASSERT_NE(nullptr, class2_field1_);
  ASSERT_NE(nullptr, class2_method1_);
  ASSERT_NE(nullptr, class2_method1_i_);
  ASSERT_NE(nullptr, class3_field1_);
  ASSERT_NE(nullptr, class3_method1_);
  ASSERT_NE(nullptr, class3_method1_i_);
}

TEST_F(HiddenApiTest, CheckEverythingMatchesL) {
  ScopedObjectAccess soa(self_);
  std::string prefix("L");
  ASSERT_TRUE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class12_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class12_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method12_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class2_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class2_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class2_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class3_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class3_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class3_method1_i_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckPackageMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/");
  ASSERT_TRUE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method12_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class12_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class12_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class2_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class2_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class2_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class3_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class3_method1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class3_method1_i_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckClassMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1");
  ASSERT_TRUE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method12_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class12_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class12_method1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class2_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class2_method1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class2_method1_i_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckClassExactMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;");
  ASSERT_TRUE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class12_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class12_method1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class2_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class2_method1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class2_method1_i_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckMethodMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->method1");
  ASSERT_FALSE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method12_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class12_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class12_method1_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckMethodExactMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->method1(");
  ASSERT_FALSE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method12_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckMethodSignatureMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->method1(I)");
  ASSERT_FALSE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method12_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckMethodSignatureAndReturnMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->method1()V");
  ASSERT_FALSE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method12_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckFieldMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->field1");
  ASSERT_TRUE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_TRUE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method1_i_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method12_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckFieldExactMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->field1:");
  ASSERT_TRUE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckFieldTypeMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->field1:I");
  ASSERT_TRUE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_field12_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckConstructorMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;-><init>");
  ASSERT_TRUE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckConstructorExactMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;-><init>()V");
  ASSERT_TRUE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
  ASSERT_FALSE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckMethodSignatureTrailingCharsNoMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->method1()Vfoo");
  ASSERT_FALSE(MemberSignature(class1_method1_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckConstructorTrailingCharsNoMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;-><init>()Vfoo");
  ASSERT_FALSE(MemberSignature(class1_init_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckFieldTrailingCharsNoMatch) {
  ScopedObjectAccess soa(self_);
  std::string prefix("Lmypackage/packagea/Class1;->field1:Ifoo");
  ASSERT_FALSE(MemberSignature(class1_field1_).DoesPrefixMatch(prefix));
}

TEST_F(HiddenApiTest, CheckMemberSignatureForProxyClass) {
  ScopedObjectAccess soa(self_);
  StackHandleScope<4> hs(soa.Self());
  Handle<mirror::ClassLoader> class_loader(
      hs.NewHandle(soa.Decode<mirror::ClassLoader>(jclass_loader_)));

  // Find interface we will create a proxy for.
  Handle<mirror::Class> h_iface(hs.NewHandle(
      class_linker_->FindClass(soa.Self(), "Lmypackage/packagea/Interface;", class_loader)));
  ASSERT_TRUE(h_iface != nullptr);

  // Create the proxy class.
  std::vector<Handle<mirror::Class>> interfaces;
  interfaces.push_back(h_iface);
  Handle<mirror::Class> proxyClass = hs.NewHandle(proxy_test::GenerateProxyClass(
      soa, jclass_loader_, runtime_->GetClassLinker(), "$Proxy1234", interfaces));
  ASSERT_TRUE(proxyClass != nullptr);
  ASSERT_TRUE(proxyClass->IsProxyClass());
  ASSERT_TRUE(proxyClass->IsInitialized());

  // Find the "method" virtual method.
  ArtMethod* method = nullptr;
  for (auto& m : proxyClass->GetDeclaredVirtualMethods(kRuntimePointerSize)) {
    if (strcmp("method", m.GetInterfaceMethodIfProxy(kRuntimePointerSize)->GetName()) == 0) {
      method = &m;
      break;
    }
  }
  ASSERT_TRUE(method != nullptr);

  // Find the "interfaces" static field. This is generated for all proxies.
  ArtField* field = nullptr;
  for (size_t i = 0; i < proxyClass->NumStaticFields(); ++i) {
    ArtField* f = proxyClass->GetStaticField(i);
    if (strcmp("interfaces", f->GetName()) == 0) {
      field = f;
      break;
    }
  }
  ASSERT_TRUE(field != nullptr);

  // Test the signature. We expect the signature from the interface class.
  std::ostringstream ss_method;
  MemberSignature(method->GetInterfaceMethodIfProxy(kRuntimePointerSize)).Dump(ss_method);
  ASSERT_EQ("Lmypackage/packagea/Interface;->method()V", ss_method.str());

  // Test the signature. We expect the signature of the proxy class.
  std::ostringstream ss_field;
  MemberSignature(field).Dump(ss_field);
  ASSERT_EQ("L$Proxy1234;->interfaces:[Ljava/lang/Class;", ss_field.str());
}

TEST_F(HiddenApiTest, DexDomain_DataDir) {
  // Load file from a non-system directory and check that it is not flagged as framework.
  std::string data_location_path = android_data_ + "/foo.jar";
  ASSERT_FALSE(LocationIsOnSystemFramework(data_location_path.c_str()));
  TestLocation(data_location_path, hiddenapi::Domain::kApplication);
}

TEST_F(HiddenApiTest, DexDomain_SystemDir) {
  // Load file from a system, non-framework directory and check that it is not flagged as framework.
  std::string system_location_path = GetAndroidRoot() + "/foo.jar";
  ASSERT_FALSE(LocationIsOnSystemFramework(system_location_path.c_str()));
  TestLocation(system_location_path, hiddenapi::Domain::kApplication);
}

TEST_F(HiddenApiTest, DexDomain_SystemExtDir) {
  // Load file from a system_ext, non-framework directory and check that it is not flagged as
  // framework.
  std::string system_ext_location_path = android_system_ext_ + "/foo.jar";
  ASSERT_FALSE(LocationIsOnSystemExtFramework(system_ext_location_path.c_str()));
  TestLocation(system_ext_location_path, hiddenapi::Domain::kApplication);
}

TEST_F(HiddenApiTest, DexDomain_SystemSystemExtDir) {
  // Load file from a system/system_ext, non-framework directory and check that it is not flagged as
  // framework.
  std::filesystem::create_directory(GetAndroidRoot() + "/system_ext");
  std::string system_ext_location_path =  GetAndroidRoot() + "/system_ext/foo.jar";
  ASSERT_FALSE(LocationIsOnSystemExtFramework(system_ext_location_path.c_str()));
  TestLocation(system_ext_location_path, hiddenapi::Domain::kApplication);
}

TEST_F(HiddenApiTest, DexDomain_SystemFrameworkDir) {
  // Load file from a system/framework directory and check that it is flagged as a framework dex.
  std::filesystem::create_directory(GetAndroidRoot() + "/framework");
  std::string system_framework_location_path = GetAndroidRoot() + "/framework/foo.jar";
  ASSERT_TRUE(LocationIsOnSystemFramework(system_framework_location_path.c_str()));
  TestLocation(system_framework_location_path, hiddenapi::Domain::kPlatform);
}

TEST_F(HiddenApiTest, DexDomain_SystemExtFrameworkDir) {
  // Load file from a system_ext/framework directory and check that it is flagged as a framework dex.
  std::filesystem::create_directory(android_system_ext_ + "/framework");
  std::string system_ext_framework_location_path = android_system_ext_ + "/framework/foo.jar";
  ASSERT_TRUE(LocationIsOnSystemExtFramework(system_ext_framework_location_path.c_str()));
  TestLocation(system_ext_framework_location_path, hiddenapi::Domain::kPlatform);
}

TEST_F(HiddenApiTest, DexDomain_SystemSystemExtFrameworkDir) {
  // Load file from a system/system_ext/framework directory and check that it is flagged as a
  // framework dex.
  std::filesystem::create_directory(GetAndroidRoot() + "/system_ext");
  std::filesystem::create_directory(GetAndroidRoot() + "/system_ext/framework");
  std::string system_ext_framework_location_path =
       GetAndroidRoot() + "/system_ext/framework/foo.jar";
  ASSERT_TRUE(LocationIsOnSystemExtFramework(system_ext_framework_location_path.c_str()));
  TestLocation(system_ext_framework_location_path, hiddenapi::Domain::kPlatform);
}

TEST_F(HiddenApiTest, DexDomain_DataDir_MultiDex) {
  // Load multidex file from a non-system directory and check that it is not flagged as framework.
  std::string data_multi_location_path = android_data_ + "/multifoo.jar";
  ASSERT_FALSE(LocationIsOnSystemFramework(data_multi_location_path.c_str()));
  TestLocation(data_multi_location_path, hiddenapi::Domain::kApplication);
}

TEST_F(HiddenApiTest, DexDomain_SystemDir_MultiDex) {
  // Load multidex file from a system, non-framework directory and check that it is not flagged
  // as framework.
  std::string system_multi_location_path = GetAndroidRoot() + "/multifoo.jar";
  ASSERT_FALSE(LocationIsOnSystemFramework(system_multi_location_path.c_str()));
  TestLocation(system_multi_location_path, hiddenapi::Domain::kApplication);
}

TEST_F(HiddenApiTest, DexDomain_SystemExtDir_MultiDex) {
  // Load multidex file from a system_ext, non-framework directory and check that it is not flagged
  // as framework.
  std::string system_ext_multi_location_path = android_system_ext_ + "/multifoo.jar";
  ASSERT_FALSE(LocationIsOnSystemExtFramework(system_ext_multi_location_path.c_str()));
  TestLocation(system_ext_multi_location_path, hiddenapi::Domain::kApplication);
}

TEST_F(HiddenApiTest, DexDomain_SystemSystemExtDir_MultiDex) {
  // Load multidex file from a system/system_ext, non-framework directory and check that it is not
  // flagged as framework.
  std::filesystem::create_directory(GetAndroidRoot() + "/system_ext");
  std::string system_ext_multi_location_path =
      GetAndroidRoot() + "/system_ext/multifoo.jar";
  ASSERT_FALSE(LocationIsOnSystemExtFramework(system_ext_multi_location_path.c_str()));
  TestLocation(system_ext_multi_location_path, hiddenapi::Domain::kApplication);
}

TEST_F(HiddenApiTest, DexDomain_SystemFrameworkDir_MultiDex) {
  // Load multidex file from a system/framework directory and check that it is flagged as a
  // framework dex.
  std::filesystem::create_directory(GetAndroidRoot() + "/framework");
  std::string system_framework_multi_location_path = GetAndroidRoot() + "/framework/multifoo.jar";
  ASSERT_TRUE(LocationIsOnSystemFramework(system_framework_multi_location_path.c_str()));
  TestLocation(system_framework_multi_location_path, hiddenapi::Domain::kPlatform);
}

TEST_F(HiddenApiTest, DexDomain_SystemExtFrameworkDir_MultiDex) {
  // Load multidex file from a system_ext/framework directory and check that it is flagged as a
  // framework dex.
  std::filesystem::create_directory(android_system_ext_ + "/framework");
  std::string system_ext_framework_multi_location_path =
      android_system_ext_ + "/framework/multifoo.jar";
  ASSERT_TRUE(LocationIsOnSystemExtFramework(system_ext_framework_multi_location_path.c_str()));
  TestLocation(system_ext_framework_multi_location_path, hiddenapi::Domain::kPlatform);
}

TEST_F(HiddenApiTest, DexDomain_SystemSystemExtFrameworkDir_MultiDex) {
  // Load multidex file from a system/system_ext/framework directory and check that it is flagged
  // as a framework dex.
  std::filesystem::create_directory(GetAndroidRoot() + "/system_ext");
  std::filesystem::create_directory(GetAndroidRoot() + "/system_ext/framework");
  std::string system_ext_framework_multi_location_path =
       GetAndroidRoot() + "/system_ext/framework/multifoo.jar";
  ASSERT_TRUE(LocationIsOnSystemExtFramework(system_ext_framework_multi_location_path.c_str()));
  TestLocation(system_ext_framework_multi_location_path, hiddenapi::Domain::kPlatform);
}

}  // namespace art
