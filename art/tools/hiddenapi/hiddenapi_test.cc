/*
 * Copyright (C) 2017 The Android Open Source Project
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

#include <fstream>

#include "android-base/strings.h"

#include "base/unix_file/fd_file.h"
#include "base/zip_archive.h"
#include "common_runtime_test.h"
#include "dex/art_dex_file_loader.h"
#include "dex/class_accessor-inl.h"
#include "dex/dex_file-inl.h"
#include "exec_utils.h"

namespace art {

class HiddenApiTest : public CommonRuntimeTest {
 protected:
  std::string GetHiddenApiCmd() {
    std::string file_path = GetArtBinDir() + "/hiddenapi";
    if (kIsDebugBuild) {
      file_path += 'd';
    }
    if (!OS::FileExists(file_path.c_str())) {
      LOG(FATAL) << "Could not find binary " << file_path;
      UNREACHABLE();
    }
    return file_path;
  }

  std::unique_ptr<const DexFile> RunHiddenapiEncode(const ScratchFile& flags_csv,
                                                    const std::vector<std::string>& extra_args,
                                                    const ScratchFile& out_dex) {
    std::string error;
    ScratchFile in_dex;
    std::unique_ptr<ZipArchive> jar(
        ZipArchive::Open(GetTestDexFileName("HiddenApi").c_str(), &error));
    if (jar == nullptr) {
      LOG(FATAL) << "Could not open test file " << GetTestDexFileName("HiddenApi") << ": " << error;
      UNREACHABLE();
    }
    std::unique_ptr<ZipEntry> jar_classes_dex(jar->Find("classes.dex", &error));
    if (jar_classes_dex == nullptr) {
      LOG(FATAL) << "Could not find classes.dex in test file " << GetTestDexFileName("HiddenApi")
                 << ": " << error;
      UNREACHABLE();
    } else if (!jar_classes_dex->ExtractToFile(*in_dex.GetFile(), &error)) {
      LOG(FATAL) << "Could not extract classes.dex from test file "
                 << GetTestDexFileName("HiddenApi") << ": " << error;
      UNREACHABLE();
    }

    std::vector<std::string> argv_str;
    argv_str.push_back(GetHiddenApiCmd());
    argv_str.push_back("encode");
    argv_str.insert(argv_str.end(), extra_args.begin(), extra_args.end());
    argv_str.push_back("--input-dex=" + in_dex.GetFilename());
    argv_str.push_back("--output-dex=" + out_dex.GetFilename());
    argv_str.push_back("--api-flags=" + flags_csv.GetFilename());
    argv_str.push_back("--no-force-assign-all");
    int return_code = ExecAndReturnCode(argv_str, &error);
    if (return_code == 0) {
      return OpenDex(out_dex);
    } else {
      LOG(ERROR) << "HiddenApi binary exited with unexpected return code " << return_code;
      return nullptr;
    }
  }

  bool RunHiddenapiList(const ScratchFile& out_flags_csv) {
    std::string error;
    std::string boot_jar = GetTestDexFileName("HiddenApi");
    std::string stub_jar = GetTestDexFileName("HiddenApiStubs");
    std::string boot_cp = android::base::Join(GetLibCoreDexFileNames(), ":");

    std::vector<std::string> argv_str;
    argv_str.push_back(GetHiddenApiCmd());
    argv_str.push_back("list");
    for (const std::string& core_jar : GetLibCoreDexFileNames()) {
      argv_str.push_back("--boot-dex=" + core_jar);
    }
    argv_str.push_back("--boot-dex=" + boot_jar);
    argv_str.push_back("--public-stub-classpath=" + boot_cp + ":" + stub_jar);
    argv_str.push_back("--out-api-flags=" + out_flags_csv.GetFilename());
    int return_code = ExecAndReturnCode(argv_str, &error);
    if (return_code == 0) {
      return true;
    } else {
      LOG(ERROR) << "HiddenApi binary exited with unexpected return code " << return_code;
      return false;
    }
  }

  std::unique_ptr<const DexFile> OpenDex(const ScratchFile& file) {
    ArtDexFileLoader dex_loader;
    std::string error_msg;

    File fd(file.GetFilename(), O_RDONLY, /* check_usage= */ false);
    if (fd.Fd() == -1) {
      PLOG(FATAL) << "Unable to open file '" << file.GetFilename() << "'";
      UNREACHABLE();
    }

    std::unique_ptr<const DexFile> dex_file(dex_loader.OpenDex(
        fd.Release(), /* location= */ file.GetFilename(), /* verify= */ true,
        /* verify_checksum= */ true, /* mmap_shared= */ false, &error_msg));
    if (dex_file.get() == nullptr) {
      LOG(FATAL) << "Open failed for '" << file.GetFilename() << "' " << error_msg;
      UNREACHABLE();
    } else if (!dex_file->IsStandardDexFile()) {
      LOG(FATAL) << "Expected a standard dex file '" << file.GetFilename() << "'";
      UNREACHABLE();
    }

    return dex_file;
  }

  std::ofstream OpenStream(const ScratchFile& file) {
    std::ofstream ofs(file.GetFilename(), std::ofstream::out);
    if (ofs.fail()) {
      PLOG(FATAL) << "Open failed for '" << file.GetFilename() << "'";
      UNREACHABLE();
    }
    return ofs;
  }

  std::map<std::string, std::string> ReadFlagsCsvFile(const ScratchFile& file) {
    std::ifstream ifs(file.GetFilename());
    std::map<std::string, std::string> flags;

    for (std::string line; std::getline(ifs, line);) {
      std::size_t comma = line.find(",");
      if (comma == std::string::npos) {
        flags.emplace(line, "");
      } else {
        flags.emplace(line.substr(0, comma), line.substr(comma + 1));
      }
    }

    return flags;
  }

  std::string SafeMapGet(const std::string& key, const std::map<std::string, std::string>& map) {
    auto it = map.find(key);
    if (it == map.end()) {
      LOG(FATAL) << "Key not found: " << key;
      UNREACHABLE();
    }
    return it->second;
  }

  const dex::ClassDef& FindClass(const char* desc, const DexFile& dex_file) {
    const dex::TypeId* type_id = dex_file.FindTypeId(desc);
    CHECK(type_id != nullptr) << "Could not find class " << desc;
    const dex::ClassDef* found = dex_file.FindClassDef(dex_file.GetIndexForTypeId(*type_id));
    CHECK(found != nullptr) << "Could not find class " << desc;
    return *found;
  }

  hiddenapi::ApiList GetFieldHiddenFlags(const char* name,
                                         uint32_t expected_visibility,
                                         const dex::ClassDef& class_def,
                                         const DexFile& dex_file) {
    ClassAccessor accessor(dex_file, class_def, /* parse hiddenapi flags */ true);
    CHECK(accessor.HasClassData()) << "Class " << accessor.GetDescriptor() << " has no data";

    if (!accessor.HasHiddenapiClassData()) {
      return hiddenapi::ApiList::Sdk();
    }

    for (const ClassAccessor::Field& field : accessor.GetFields()) {
      const dex::FieldId& fid = dex_file.GetFieldId(field.GetIndex());
      if (strcmp(name, dex_file.GetFieldName(fid)) == 0) {
        const uint32_t actual_visibility = field.GetAccessFlags() & kAccVisibilityFlags;
        CHECK_EQ(actual_visibility, expected_visibility)
            << "Field " << name << " in class " << accessor.GetDescriptor();
        return hiddenapi::ApiList(field.GetHiddenapiFlags());
      }
    }

    LOG(FATAL) << "Could not find field " << name << " in class "
               << dex_file.GetClassDescriptor(class_def);
    UNREACHABLE();
  }

  hiddenapi::ApiList GetMethodHiddenFlags(const char* name,
                                          uint32_t expected_visibility,
                                          bool expected_native,
                                          const dex::ClassDef& class_def,
                                          const DexFile& dex_file) {
    ClassAccessor accessor(dex_file, class_def, /* parse hiddenapi flags */ true);
    CHECK(accessor.HasClassData()) << "Class " << accessor.GetDescriptor() << " has no data";

    if (!accessor.HasHiddenapiClassData()) {
      return hiddenapi::ApiList::Sdk();
    }

    for (const ClassAccessor::Method& method : accessor.GetMethods()) {
      const dex::MethodId& mid = dex_file.GetMethodId(method.GetIndex());
      if (strcmp(name, dex_file.GetMethodName(mid)) == 0) {
        CHECK_EQ(expected_native, method.MemberIsNative())
            << "Method " << name << " in class " << accessor.GetDescriptor();
        const uint32_t actual_visibility = method.GetAccessFlags() & kAccVisibilityFlags;
        CHECK_EQ(actual_visibility, expected_visibility)
            << "Method " << name << " in class " << accessor.GetDescriptor();
        return hiddenapi::ApiList(method.GetHiddenapiFlags());
      }
    }

    LOG(FATAL) << "Could not find method " << name << " in class "
               << dex_file.GetClassDescriptor(class_def);
    UNREACHABLE();
  }

  hiddenapi::ApiList GetIFieldHiddenFlags(const DexFile& dex_file) {
    return GetFieldHiddenFlags("ifield", kAccPublic, FindClass("LMain;", dex_file), dex_file);
  }

  hiddenapi::ApiList GetSFieldHiddenFlags(const DexFile& dex_file) {
    return GetFieldHiddenFlags("sfield", kAccPrivate, FindClass("LMain;", dex_file), dex_file);
  }

  hiddenapi::ApiList GetIMethodHiddenFlags(const DexFile& dex_file) {
    return GetMethodHiddenFlags(
        "imethod", 0, /* expected_native= */ false, FindClass("LMain;", dex_file), dex_file);
  }

  hiddenapi::ApiList GetSMethodHiddenFlags(const DexFile& dex_file) {
    return GetMethodHiddenFlags("smethod",
                                kAccPublic,
                                /* expected_native= */ false,
                                FindClass("LMain;", dex_file),
                                dex_file);
  }

  hiddenapi::ApiList GetINMethodHiddenFlags(const DexFile& dex_file) {
    return GetMethodHiddenFlags("inmethod",
                                kAccPublic,
                                /* expected_native= */ true,
                                FindClass("LMain;", dex_file),
                                dex_file);
  }

  hiddenapi::ApiList GetSNMethodHiddenFlags(const DexFile& dex_file) {
    return GetMethodHiddenFlags("snmethod",
                                kAccProtected,
                                /* expected_native= */ true,
                                FindClass("LMain;", dex_file),
                                dex_file);
  }
};

TEST_F(HiddenApiTest, InstanceFieldNoMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:LBadType1;,unsupported" << std::endl
      << "LMain;->ifield:LBadType2;,max-target-o" << std::endl
      << "LMain;->ifield:LBadType3;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Sdk(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldLightunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:I,unsupported" << std::endl
      << "LMain;->ifield:LBadType2;,max-target-o" << std::endl
      << "LMain;->ifield:LBadType3;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Unsupported(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldDarkunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:LBadType1;,unsupported" << std::endl
      << "LMain;->ifield:I,max-target-o" << std::endl
      << "LMain;->ifield:LBadType3;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::MaxTargetO(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldblockedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:LBadType1;,unsupported" << std::endl
      << "LMain;->ifield:LBadType2;,max-target-o" << std::endl
      << "LMain;->ifield:I,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Blocked(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldTwoListsMatch1) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:LBadType1;,unsupported" << std::endl
      << "LMain;->ifield:I,blocked,max-target-o" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceFieldTwoListsMatch2) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:LBadType2;,max-target-o" << std::endl
      << "LMain;->ifield:I,blocked,unsupported" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceFieldTwoListsMatch3) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:I,unsupported,max-target-o" << std::endl
      << "LMain;->ifield:LBadType3;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticFieldNoMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->sfield:LBadType1;,unsupported" << std::endl
      << "LMain;->sfield:LBadType2;,max-target-o" << std::endl
      << "LMain;->sfield:LBadType3;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Sdk(), GetSFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticFieldLightunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->sfield:Ljava/lang/Object;,unsupported" << std::endl
      << "LMain;->sfield:LBadType2;,max-target-o" << std::endl
      << "LMain;->sfield:LBadType3;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Unsupported(), GetSFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticFieldDarkunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->sfield:LBadType1;,unsupported" << std::endl
      << "LMain;->sfield:Ljava/lang/Object;,max-target-o" << std::endl
      << "LMain;->sfield:LBadType3;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::MaxTargetO(), GetSFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticFieldblockedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->sfield:LBadType1;,unsupported" << std::endl
      << "LMain;->sfield:LBadType2;,max-target-o" << std::endl
      << "LMain;->sfield:Ljava/lang/Object;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Blocked(), GetSFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticFieldTwoListsMatch1) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->sfield:LBadType1;,unsupported" << std::endl
      << "LMain;->sfield:Ljava/lang/Object;,blocked,max-target-o" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticFieldTwoListsMatch2) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->sfield:LBadType2;,max-target-o" << std::endl
      << "LMain;->sfield:Ljava/lang/Object;,blocked,unsupported" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticFieldTwoListsMatch3) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->sfield:Ljava/lang/Object;,unsupported,max-target-o" << std::endl
      << "LMain;->sfield:LBadType3;,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceMethodNoMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->imethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->imethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->imethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Sdk(), GetIMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceMethodLightunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->imethod(J)V,unsupported" << std::endl
      << "LMain;->imethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->imethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Unsupported(), GetIMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceMethodDarkunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->imethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->imethod(J)V,max-target-o" << std::endl
      << "LMain;->imethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::MaxTargetO(), GetIMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceMethodblockedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->imethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->imethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->imethod(J)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Blocked(), GetIMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceMethodTwoListsMatch1) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->imethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->imethod(J)V,blocked,max-target-o" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceMethodTwoListsMatch2) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->imethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->imethod(J)V,blocked,unsupported" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceMethodTwoListsMatch3) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->imethod(J)V,unsupported,max-target-o" << std::endl
      << "LMain;->imethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticMethodNoMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->smethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->smethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->smethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Sdk(), GetSMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticMethodLightunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->smethod(Ljava/lang/Object;)V,unsupported" << std::endl
      << "LMain;->smethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->smethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Unsupported(), GetSMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticMethodDarkunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->smethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->smethod(Ljava/lang/Object;)V,max-target-o" << std::endl
      << "LMain;->smethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::MaxTargetO(), GetSMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticMethodblockedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->smethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->smethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->smethod(Ljava/lang/Object;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Blocked(), GetSMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticMethodTwoListsMatch1) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->smethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->smethod(Ljava/lang/Object;)V,blocked,max-target-o" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticMethodTwoListsMatch2) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->smethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->smethod(Ljava/lang/Object;)V,blocked,unsupported" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticMethodTwoListsMatch3) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->smethod(Ljava/lang/Object;)V,unsupported,max-target-o" << std::endl
      << "LMain;->smethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceNativeMethodNoMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->inmethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->inmethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->inmethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Sdk(), GetINMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceNativeMethodLightunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->inmethod(C)V,unsupported" << std::endl
      << "LMain;->inmethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->inmethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Unsupported(), GetINMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceNativeMethodDarkunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->inmethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->inmethod(C)V,max-target-o" << std::endl
      << "LMain;->inmethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::MaxTargetO(), GetINMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceNativeMethodblockedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->inmethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->inmethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->inmethod(C)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Blocked(), GetINMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceNativeMethodTwoListsMatch1) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->inmethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->inmethod(C)V,blocked,max-target-o" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceNativeMethodTwoListsMatch2) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->inmethod(C)V,blocked,unsupported" << std::endl
      << "LMain;->inmethod(LBadType2;)V,max-target-o" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceNativeMethodTwoListsMatch3) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->inmethod(C)V,unsupported,max-target-o" << std::endl
      << "LMain;->inmethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticNativeMethodNoMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->snmethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->snmethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->snmethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Sdk(), GetSNMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticNativeMethodLightunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->snmethod(Ljava/lang/Integer;)V,unsupported" << std::endl
      << "LMain;->snmethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->snmethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Unsupported(), GetSNMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticNativeMethodDarkunsupportedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->snmethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->snmethod(Ljava/lang/Integer;)V,max-target-o" << std::endl
      << "LMain;->snmethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::MaxTargetO(), GetSNMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticNativeMethodblockedMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->snmethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->snmethod(LBadType2;)V,max-target-o" << std::endl
      << "LMain;->snmethod(Ljava/lang/Integer;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Blocked(), GetSNMethodHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, StaticNativeMethodTwoListsMatch1) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->snmethod(LBadType1;)V,unsupported" << std::endl
      << "LMain;->snmethod(Ljava/lang/Integer;)V,blocked,max-target-o" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticNativeMethodTwoListsMatch2) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->snmethod(Ljava/lang/Integer;)V,blocked,unsupported" << std::endl
      << "LMain;->snmethod(LBadType2;)V,max-target-o" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, StaticNativeMethodTwoListsMatch3) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->snmethod(Ljava/lang/Integer;)V,unsupported,max-target-o" << std::endl
      << "LMain;->snmethod(LBadType3;)V,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceFieldCorePlatformApiMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:LBadType1;,unsupported" << std::endl
      << "LMain;->ifield:LBadType2;,max-target-o" << std::endl
      << "LMain;->ifield:I,unsupported,core-platform-api" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::CorePlatformApi() |
  hiddenapi::ApiList::Unsupported(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldTestApiMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:LBadType1;,unsupported" << std::endl
      << "LMain;->ifield:LBadType2;,max-target-o" << std::endl
      << "LMain;->ifield:I,unsupported,test-api" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::TestApi()
  | hiddenapi::ApiList::Unsupported(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldUnknownFlagMatch) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:LBadType1;,unsupported" << std::endl
      << "LMain;->ifield:LBadType2;,max-target-o" << std::endl
      << "LMain;->ifield:I,unsupported,unknown-flag" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {}, dex);
  ASSERT_EQ(dex_file.get(), nullptr);
}

TEST_F(HiddenApiTest, InstanceFieldMaxSdkHigherThanMaxHiddenApiLevel) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:I,max-target-r" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {"--max-hiddenapi-level=max-target-q"}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Unsupported(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldMaxSdkEqualsMaxHiddenApiLevel) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:I,max-target-r" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {"--max-hiddenapi-level=max-target-r"}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::MaxTargetR(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldMaxSdkLowerThanMaxHiddenApiLevel) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:I,max-target-q" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {"--max-hiddenapi-level=max-target-r"}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::MaxTargetQ(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldBlockedUnchangedByMaxHiddenApiLevel) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:I,blocked" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {"--max-hiddenapi-level=max-target-r"}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Blocked(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldUnsupportedUnchangedByMaxHiddenApiLevel) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:I,unsupported" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {"--max-hiddenapi-level=max-target-r"}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Unsupported(), GetIFieldHiddenFlags(*dex_file));
}

TEST_F(HiddenApiTest, InstanceFieldSdkUnchangedByMaxHiddenApiLevel) {
  ScratchFile dex, flags_csv;
  OpenStream(flags_csv)
      << "LMain;->ifield:I,sdk" << std::endl;
  auto dex_file = RunHiddenapiEncode(flags_csv, {"--max-hiddenapi-level=max-target-r"}, dex);
  ASSERT_NE(dex_file.get(), nullptr);
  ASSERT_EQ(hiddenapi::ApiList::Sdk(), GetIFieldHiddenFlags(*dex_file));
}

// The following tests use this class hierarchy:
//
//    AbstractPackageClass  PublicInterface
//           |                     |
//           |    ┌----------------┘
//           |    |
//        PackageClass
//
// Only PublicInterface is in stubs.

// Test a method declared in PublicInterface and defined in PackageClass.
TEST_F(HiddenApiTest, InterfaceMethodImplemented) {
  ScratchFile flags_csv;
  ASSERT_TRUE(RunHiddenapiList(flags_csv));
  auto flags = ReadFlagsCsvFile(flags_csv);
  ASSERT_EQ(SafeMapGet("LPackageClass;->publicMethod1()V", flags), "public-api");
}

// Test a method declared in PublicInterface, defined in AbstractPackageClass and
// inherited by PackageClass.
TEST_F(HiddenApiTest, InterfaceMethodImplementedInParent) {
  ScratchFile flags_csv;
  ASSERT_TRUE(RunHiddenapiList(flags_csv));
  auto flags = ReadFlagsCsvFile(flags_csv);
  ASSERT_EQ(SafeMapGet("LAbstractPackageClass;->publicMethod2()V", flags), "public-api");
}

}  // namespace art
