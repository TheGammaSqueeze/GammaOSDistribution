/*
 * Copyright (C) 2011 The Android Open Source Project
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

#include "method_verifier.h"

#include <stdio.h>

#include <memory>

#include "android-base/strings.h"
#include "base/metrics/metrics_test.h"
#include "base/utils.h"
#include "class_linker-inl.h"
#include "class_verifier.h"
#include "common_runtime_test.h"
#include "dex/dex_file-inl.h"
#include "scoped_thread_state_change-inl.h"
#include "verifier_enums.h"

namespace art {
namespace verifier {

using metrics::test::CounterValue;

class MethodVerifierTest : public CommonRuntimeTest {
 protected:
  void VerifyClass(const std::string& descriptor)
      REQUIRES_SHARED(Locks::mutator_lock_) {
    ASSERT_FALSE(descriptor.empty());
    Thread* self = Thread::Current();
    ObjPtr<mirror::Class> klass = class_linker_->FindSystemClass(self, descriptor.c_str());

    // Verify the class
    std::string error_msg;
    FailureKind failure = ClassVerifier::VerifyClass(self,
                                                     /* verifier_deps= */ nullptr,
                                                     klass,
                                                     nullptr,
                                                     true,
                                                     HardFailLogMode::kLogWarning,
                                                     /* api_level= */ 0u,
                                                     &error_msg);

    if (android::base::StartsWith(descriptor, "Ljava/lang/invoke")) {
      ASSERT_TRUE(failure == FailureKind::kSoftFailure ||
                  failure == FailureKind::kNoFailure) << error_msg;

    } else {
      ASSERT_TRUE(failure == FailureKind::kNoFailure) << error_msg;
    }
  }

  void VerifyDexFile(const DexFile& dex)
      REQUIRES_SHARED(Locks::mutator_lock_) {
    // Verify all the classes defined in this file
    for (size_t i = 0; i < dex.NumClassDefs(); i++) {
      const dex::ClassDef& class_def = dex.GetClassDef(i);
      const char* descriptor = dex.GetClassDescriptor(class_def);
      VerifyClass(descriptor);
    }
  }
};

TEST_F(MethodVerifierTest, LibCore) {
  ScopedObjectAccess soa(Thread::Current());
  ASSERT_TRUE(java_lang_dex_file_ != nullptr);
  VerifyDexFile(*java_lang_dex_file_);
}

// Make sure verification time metrics are collected.
TEST_F(MethodVerifierTest, VerificationTimeMetrics) {
  ScopedObjectAccess soa(Thread::Current());
  ASSERT_TRUE(java_lang_dex_file_ != nullptr);
  auto* class_verification_total_time = GetMetrics()->ClassVerificationTotalTime();
  auto* class_verification_count = GetMetrics()->ClassVerificationCount();
  const uint64_t original_time = CounterValue(*class_verification_total_time);
  const uint64_t original_count = CounterValue(*class_verification_count);
  VerifyDexFile(*java_lang_dex_file_);
  ASSERT_GT(CounterValue(*class_verification_total_time), original_time);
  ASSERT_GT(CounterValue(*class_verification_count), original_count);
}

}  // namespace verifier
}  // namespace art
