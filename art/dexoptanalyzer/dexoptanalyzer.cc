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

#include "dexoptanalyzer.h"

#include <iostream>
#include <string>
#include <string_view>

#include "android-base/stringprintf.h"
#include "android-base/strings.h"
#include "base/compiler_filter.h"
#include "base/file_utils.h"
#include "base/logging.h"  // For InitLogging.
#include "base/mutex.h"
#include "base/os.h"
#include "base/string_view_cpp20.h"
#include "base/utils.h"
#include "class_linker.h"
#include "class_loader_context.h"
#include "dex/dex_file.h"
#include "gc/heap.h"
#include "gc/space/image_space.h"
#include "noop_compiler_callbacks.h"
#include "oat.h"
#include "oat_file_assistant.h"
#include "runtime.h"
#include "thread-inl.h"
#include "vdex_file.h"

namespace art {
namespace dexoptanalyzer {

static int original_argc;
static char** original_argv;

static std::string CommandLine() {
  std::vector<std::string> command;
  command.reserve(original_argc);
  for (int i = 0; i < original_argc; ++i) {
    command.push_back(original_argv[i]);
  }
  return android::base::Join(command, ' ');
}

static void UsageErrorV(const char* fmt, va_list ap) {
  std::string error;
  android::base::StringAppendV(&error, fmt, ap);
  LOG(ERROR) << error;
}

static void UsageError(const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  UsageErrorV(fmt, ap);
  va_end(ap);
}

NO_RETURN static void Usage(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  UsageErrorV(fmt, ap);
  va_end(ap);

  UsageError("Command: %s", CommandLine().c_str());
  UsageError("  Performs a dexopt analysis on the given dex file and returns whether or not");
  UsageError("  the dex file needs to be dexopted.");
  UsageError("Usage: dexoptanalyzer [options]...");
  UsageError("");
  UsageError("  --dex-file=<filename>: the dex file which should be analyzed.");
  UsageError("");
  UsageError("  --isa=<string>: the instruction set for which the analysis should be performed.");
  UsageError("");
  UsageError("  --compiler-filter=<string>: the target compiler filter to be used as reference");
  UsageError("       when deciding if the dex file needs to be optimized.");
  UsageError("");
  UsageError("  --profile_analysis_result=<int>: the result of the profile analysis, used in");
  UsageError("       deciding if the dex file needs to be optimized.");
  UsageError("");
  UsageError("  --image=<filename>: optional, the image to be used to decide if the associated");
  UsageError("       oat file is up to date. Defaults to $ANDROID_ROOT/framework/boot.art.");
  UsageError("       Example: --image=/system/framework/boot.art");
  UsageError("");
  UsageError("  --runtime-arg <argument>: used to specify various arguments for the runtime,");
  UsageError("      such as initial heap size, maximum heap size, and verbose output.");
  UsageError("      Use a separate --runtime-arg switch for each argument.");
  UsageError("      Example: --runtime-arg -Xms256m");
  UsageError("");
  UsageError("  --android-data=<directory>: optional, the directory which should be used as");
  UsageError("       android-data. By default ANDROID_DATA env variable is used.");
  UsageError("");
  UsageError("  --oat-fd=number: file descriptor of the oat file which should be analyzed");
  UsageError("");
  UsageError("  --vdex-fd=number: file descriptor of the vdex file corresponding to the oat file");
  UsageError("");
  UsageError("  --zip-fd=number: specifies a file descriptor corresponding to the dex file.");
  UsageError("");
  UsageError("  --downgrade: optional, if the purpose of dexopt is to downgrade the dex file");
  UsageError("       By default, dexopt considers upgrade case.");
  UsageError("");
  UsageError("  --class-loader-context=<string spec>: a string specifying the intended");
  UsageError("      runtime loading context for the compiled dex files.");
  UsageError("");
  UsageError("  --class-loader-context-fds=<fds>: a colon-separated list of file descriptors");
  UsageError("      for dex files in --class-loader-context. Their order must be the same as");
  UsageError("      dex files in flattened class loader context.");
  UsageError("");
  UsageError("  --flatten-class-loader-context: parse --class-loader-context, flatten it and");
  UsageError("      print a colon-separated list of its dex files to standard output. Dexopt");
  UsageError("      needed analysis is not performed when this option is set.");
  UsageError("");
  UsageError("  --validate-bcp: validates the boot class path files (.art, .oat, .vdex).");
  UsageError("      Requires --isa and --image options to locate artifacts.");
  UsageError("");
  UsageError("Return code:");
  UsageError("  To make it easier to integrate with the internal tools this command will make");
  UsageError("    available its result (dexoptNeeded) as the exit/return code. i.e. it will not");
  UsageError("    return 0 for success and a non zero values for errors as the conventional");
  UsageError("    commands. The following return codes are possible:");
  UsageError("        kNoDexOptNeeded = 0");
  UsageError("        kDex2OatFromScratch = 1");
  UsageError("        kDex2OatForBootImageOat = 2");
  UsageError("        kDex2OatForFilterOat = 3");
  UsageError("        kDex2OatForBootImageOdex = 4");
  UsageError("        kDex2OatForFilterOdex = 5");

  UsageError("        kErrorInvalidArguments = 101");
  UsageError("        kErrorCannotCreateRuntime = 102");
  UsageError("        kErrorUnknownDexOptNeeded = 103");
  UsageError("");

  exit(static_cast<int>(ReturnCode::kErrorInvalidArguments));
}

class DexoptAnalyzer final {
 public:
  DexoptAnalyzer() :
      only_flatten_context_(false),
      only_validate_bcp_(false),
      downgrade_(false) {}

  void ParseArgs(int argc, char **argv) {
    original_argc = argc;
    original_argv = argv;

    Locks::Init();
    InitLogging(argv, Runtime::Abort);
    // Skip over the command name.
    argv++;
    argc--;

    if (argc == 0) {
      Usage("No arguments specified");
    }

    for (int i = 0; i < argc; ++i) {
      const char* raw_option = argv[i];
      const std::string_view option(raw_option);

      if (StartsWith(option, "--profile-analysis-result=")) {
        int parse_result = std::stoi(std::string(
            option.substr(strlen("--profile-analysis-result="))), nullptr, 0);
        if (parse_result != static_cast<int>(ProfileAnalysisResult::kOptimize) &&
            parse_result != static_cast<int>(ProfileAnalysisResult::kDontOptimizeSmallDelta) &&
            parse_result != static_cast<int>(ProfileAnalysisResult::kDontOptimizeEmptyProfiles)) {
          Usage("Invalid --profile-analysis-result= %d", parse_result);
        }
        profile_analysis_result_ = static_cast<ProfileAnalysisResult>(parse_result);
      } else if (StartsWith(option, "--dex-file=")) {
        dex_file_ = std::string(option.substr(strlen("--dex-file=")));
      } else if (StartsWith(option, "--compiler-filter=")) {
        const char* filter_str = raw_option + strlen("--compiler-filter=");
        if (!CompilerFilter::ParseCompilerFilter(filter_str, &compiler_filter_)) {
          Usage("Invalid compiler filter '%s'", raw_option);
        }
      } else if (StartsWith(option, "--isa=")) {
        const char* isa_str = raw_option + strlen("--isa=");
        isa_ = GetInstructionSetFromString(isa_str);
        if (isa_ == InstructionSet::kNone) {
          Usage("Invalid isa '%s'", raw_option);
        }
      } else if (StartsWith(option, "--image=")) {
        image_ = std::string(option.substr(strlen("--image=")));
      } else if (option == "--runtime-arg") {
        if (i + 1 == argc) {
          Usage("Missing argument for --runtime-arg\n");
        }
        ++i;
        runtime_args_.push_back(argv[i]);
      } else if (StartsWith(option, "--android-data=")) {
        // Overwrite android-data if needed (oat file assistant relies on a valid directory to
        // compute dalvik-cache folder). This is mostly used in tests.
        const char* new_android_data = raw_option + strlen("--android-data=");
        setenv("ANDROID_DATA", new_android_data, 1);
      } else if (option == "--downgrade") {
        downgrade_ = true;
      } else if (StartsWith(option, "--oat-fd=")) {
        oat_fd_ = std::stoi(std::string(option.substr(strlen("--oat-fd="))), nullptr, 0);
        if (oat_fd_ < 0) {
          Usage("Invalid --oat-fd %d", oat_fd_);
        }
      } else if (StartsWith(option, "--vdex-fd=")) {
        vdex_fd_ = std::stoi(std::string(option.substr(strlen("--vdex-fd="))), nullptr, 0);
        if (vdex_fd_ < 0) {
          Usage("Invalid --vdex-fd %d", vdex_fd_);
        }
      } else if (StartsWith(option, "--zip-fd=")) {
        zip_fd_ = std::stoi(std::string(option.substr(strlen("--zip-fd="))), nullptr, 0);
        if (zip_fd_ < 0) {
          Usage("Invalid --zip-fd %d", zip_fd_);
        }
      } else if (StartsWith(option, "--class-loader-context=")) {
        context_str_ = std::string(option.substr(strlen("--class-loader-context=")));
      } else if (StartsWith(option, "--class-loader-context-fds=")) {
        std::string str_context_fds_arg =
            std::string(option.substr(strlen("--class-loader-context-fds=")));
        std::vector<std::string> str_fds = android::base::Split(str_context_fds_arg, ":");
        for (const std::string& str_fd : str_fds) {
          context_fds_.push_back(std::stoi(str_fd, nullptr, 0));
          if (context_fds_.back() < 0) {
            Usage("Invalid --class-loader-context-fds %s", str_context_fds_arg.c_str());
          }
        }
      } else if (option == "--flatten-class-loader-context") {
        only_flatten_context_ = true;
      } else if (option == "--validate-bcp") {
        only_validate_bcp_ = true;
      } else {
        Usage("Unknown argument '%s'", raw_option);
      }
    }

    if (image_.empty()) {
      // If we don't receive the image, try to use the default one.
      // Tests may specify a different image (e.g. core image).
      std::string error_msg;
      image_ = GetDefaultBootImageLocation(&error_msg);

      if (image_.empty()) {
        LOG(ERROR) << error_msg;
        Usage("--image unspecified and ANDROID_ROOT not set or image file does not exist.");
      }
    }
  }

  bool CreateRuntime() const {
    RuntimeOptions options;
    // The image could be custom, so make sure we explicitly pass it.
    std::string img = "-Ximage:" + image_;
    options.push_back(std::make_pair(img, nullptr));
    // The instruction set of the image should match the instruction set we will test.
    const void* isa_opt = reinterpret_cast<const void*>(GetInstructionSetString(isa_));
    options.push_back(std::make_pair("imageinstructionset", isa_opt));
    // Explicit runtime args.
    for (const char* runtime_arg : runtime_args_) {
      options.push_back(std::make_pair(runtime_arg, nullptr));
    }
     // Disable libsigchain. We don't don't need it to evaluate DexOptNeeded status.
    options.push_back(std::make_pair("-Xno-sig-chain", nullptr));
    // Pretend we are a compiler so that we can re-use the same infrastructure to load a different
    // ISA image and minimize the amount of things that get started.
    NoopCompilerCallbacks callbacks;
    options.push_back(std::make_pair("compilercallbacks", &callbacks));
    // Make sure we don't attempt to relocate. The tool should only retrieve the DexOptNeeded
    // status and not attempt to relocate the boot image.
    options.push_back(std::make_pair("-Xnorelocate", nullptr));

    if (!Runtime::Create(options, false)) {
      LOG(ERROR) << "Unable to initialize runtime";
      return false;
    }
    // Runtime::Create acquired the mutator_lock_ that is normally given away when we
    // Runtime::Start. Give it away now.
    Thread::Current()->TransitionFromRunnableToSuspended(kNative);

    return true;
  }

  ReturnCode GetDexOptNeeded() const {
    if (!CreateRuntime()) {
      return ReturnCode::kErrorCannotCreateRuntime;
    }
    std::unique_ptr<Runtime> runtime(Runtime::Current());

    // Only when the runtime is created can we create the class loader context: the
    // class loader context will open dex file and use the MemMap global lock that the
    // runtime owns.
    std::unique_ptr<ClassLoaderContext> class_loader_context;
    if (!context_str_.empty()) {
      class_loader_context = ClassLoaderContext::Create(context_str_);
      if (class_loader_context == nullptr) {
        Usage("Invalid --class-loader-context '%s'", context_str_.c_str());
      }
    }
    if (class_loader_context != nullptr) {
      size_t dir_index = dex_file_.rfind('/');
      std::string classpath_dir = (dir_index != std::string::npos)
          ? dex_file_.substr(0, dir_index)
          : "";

      if (!class_loader_context->OpenDexFiles(classpath_dir,
                                              context_fds_,
                                              /*only_read_checksums=*/ true)) {
        return ReturnCode::kDex2OatFromScratch;
      }
    }

    std::unique_ptr<OatFileAssistant> oat_file_assistant;
    oat_file_assistant = std::make_unique<OatFileAssistant>(dex_file_.c_str(),
                                                            isa_,
                                                            class_loader_context.get(),
                                                            /*load_executable=*/ false,
                                                            /*only_load_trusted_executable=*/ false,
                                                            vdex_fd_,
                                                            oat_fd_,
                                                            zip_fd_);
    // Always treat elements of the bootclasspath as up-to-date.
    // TODO(calin): this check should be in OatFileAssistant.
    if (oat_file_assistant->IsInBootClassPath()) {
      return ReturnCode::kNoDexOptNeeded;
    }

    // If the compiler filter depends on profiles but the profiles are empty,
    // change the test filter to kVerify. It's what dex2oat also does.
    CompilerFilter::Filter actual_compiler_filter = compiler_filter_;
    if (CompilerFilter::DependsOnProfile(compiler_filter_) &&
        profile_analysis_result_ == ProfileAnalysisResult::kDontOptimizeEmptyProfiles) {
      actual_compiler_filter = CompilerFilter::kVerify;
    }

    // TODO: GetDexOptNeeded should get the raw analysis result instead of assume_profile_changed.
    bool assume_profile_changed = profile_analysis_result_ == ProfileAnalysisResult::kOptimize;
    int dexoptNeeded = oat_file_assistant->GetDexOptNeeded(actual_compiler_filter,
                                                           assume_profile_changed,
                                                           downgrade_);

    // Convert OatFileAssistant codes to dexoptanalyzer codes.
    switch (dexoptNeeded) {
      case OatFileAssistant::kNoDexOptNeeded: return ReturnCode::kNoDexOptNeeded;
      case OatFileAssistant::kDex2OatFromScratch: return ReturnCode::kDex2OatFromScratch;
      case OatFileAssistant::kDex2OatForBootImage: return ReturnCode::kDex2OatForBootImageOat;
      case OatFileAssistant::kDex2OatForFilter: return ReturnCode::kDex2OatForFilterOat;

      case -OatFileAssistant::kDex2OatForBootImage: return ReturnCode::kDex2OatForBootImageOdex;
      case -OatFileAssistant::kDex2OatForFilter: return ReturnCode::kDex2OatForFilterOdex;
      default:
        LOG(ERROR) << "Unknown dexoptNeeded " << dexoptNeeded;
        return ReturnCode::kErrorUnknownDexOptNeeded;
    }
  }

  // Validates the boot classpath and boot classpath extensions by checking the image checksums,
  // the oat files and the vdex files.
  //
  // Returns `ReturnCode::kNoDexOptNeeded` when all the files are up-to-date,
  // `ReturnCode::kDex2OatFromScratch` if any of the files are missing or out-of-date, and
  // `ReturnCode::kErrorCannotCreateRuntime` if the files could not be tested due to problem
  // creating a runtime.
  ReturnCode ValidateBcp() const {
    using ImageSpace = gc::space::ImageSpace;

    if (!CreateRuntime()) {
      return ReturnCode::kErrorCannotCreateRuntime;
    }
    std::unique_ptr<Runtime> runtime(Runtime::Current());

    auto dex_files = ArrayRef<const DexFile* const>(runtime->GetClassLinker()->GetBootClassPath());
    auto boot_image_spaces = ArrayRef<ImageSpace* const>(runtime->GetHeap()->GetBootImageSpaces());
    const std::string checksums = ImageSpace::GetBootClassPathChecksums(boot_image_spaces,
                                                                        dex_files);

    std::string error_msg;
    const std::vector<std::string>& bcp = runtime->GetBootClassPath();
    const std::vector<std::string>& bcp_locations = runtime->GetBootClassPathLocations();
    const std::string bcp_locations_path = android::base::Join(bcp_locations, ':');
    if (!ImageSpace::VerifyBootClassPathChecksums(checksums,
                                                  bcp_locations_path,
                                                  runtime->GetImageLocation(),
                                                  ArrayRef<const std::string>(bcp_locations),
                                                  ArrayRef<const std::string>(bcp),
                                                  runtime->GetInstructionSet(),
                                                  &error_msg)) {
      LOG(INFO) << "Failed to verify boot class path checksums: " << error_msg;
      return ReturnCode::kDex2OatFromScratch;
    }

    const auto& image_spaces = runtime->GetHeap()->GetBootImageSpaces();
    size_t bcp_component_count = 0;
    for (const auto& image_space : image_spaces) {
      if (!image_space->GetImageHeader().IsValid()) {
        LOG(INFO) << "Image header is not valid: " << image_space->GetImageFilename();
        return ReturnCode::kDex2OatFromScratch;
      }
      const OatFile* oat_file = image_space->GetOatFile();
      if (oat_file == nullptr) {
        const std::string oat_path = ReplaceFileExtension(image_space->GetImageFilename(), "oat");
        LOG(INFO) << "Oat file missing: " << oat_path;
        return ReturnCode::kDex2OatFromScratch;
      }
      if (!oat_file->GetOatHeader().IsValid() ||
          !ImageSpace::ValidateOatFile(*oat_file, &error_msg)) {
        LOG(INFO) << "Oat file is not valid: " << oat_file->GetLocation() << " " << error_msg;
        return ReturnCode::kDex2OatFromScratch;
      }
      const VdexFile* vdex_file = oat_file->GetVdexFile();
      if (vdex_file == nullptr || !vdex_file->IsValid()) {
        LOG(INFO) << "Vdex file is not valid : " << oat_file->GetLocation();
        return ReturnCode::kDex2OatFromScratch;
      }
      bcp_component_count += image_space->GetComponentCount();
    }

    // If the number of components encountered in the image spaces does not match the number
    // of components expected from the boot classpath locations then something is missing.
    if (bcp_component_count != bcp_locations.size()) {
      for (size_t i = bcp_component_count; i < bcp_locations.size(); ++i) {
        LOG(INFO) << "Missing image file for " << bcp_locations[i];
      }
      return ReturnCode::kDex2OatFromScratch;
    }

    return ReturnCode::kNoDexOptNeeded;
  }

  ReturnCode FlattenClassLoaderContext() const {
    DCHECK(only_flatten_context_);
    if (context_str_.empty()) {
      return ReturnCode::kErrorInvalidArguments;
    }

    std::unique_ptr<ClassLoaderContext> context = ClassLoaderContext::Create(context_str_);
    if (context == nullptr) {
      Usage("Invalid --class-loader-context '%s'", context_str_.c_str());
    }

    std::cout << context->FlattenDexPaths() << std::flush;
    return ReturnCode::kFlattenClassLoaderContextSuccess;
  }

  ReturnCode Run() const {
    if (only_flatten_context_) {
      return FlattenClassLoaderContext();
    } else if (only_validate_bcp_) {
      return ValidateBcp();
    } else {
      return GetDexOptNeeded();
    }
  }

 private:
  std::string dex_file_;
  InstructionSet isa_;
  CompilerFilter::Filter compiler_filter_;
  std::string context_str_;
  bool only_flatten_context_;
  bool only_validate_bcp_;
  ProfileAnalysisResult profile_analysis_result_;
  bool downgrade_;
  std::string image_;
  std::vector<const char*> runtime_args_;
  int oat_fd_ = -1;
  int vdex_fd_ = -1;
  // File descriptor corresponding to apk, dex_file, or zip.
  int zip_fd_ = -1;
  std::vector<int> context_fds_;
};

static ReturnCode dexoptAnalyze(int argc, char** argv) {
  DexoptAnalyzer analyzer;

  // Parse arguments. Argument mistakes will lead to exit(kErrorInvalidArguments) in UsageError.
  analyzer.ParseArgs(argc, argv);
  return analyzer.Run();
}

}  // namespace dexoptanalyzer
}  // namespace art

int main(int argc, char **argv) {
  art::dexoptanalyzer::ReturnCode return_code = art::dexoptanalyzer::dexoptAnalyze(argc, argv);
  return static_cast<int>(return_code);
}
