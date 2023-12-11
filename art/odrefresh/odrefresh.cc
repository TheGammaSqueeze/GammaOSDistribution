/*
 * Copyright (C) 2020 The Android Open Source Project
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

#include "odrefresh/odrefresh.h"

#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sysexits.h>
#include <time.h>
#include <unistd.h>

#include <algorithm>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <initializer_list>
#include <iosfwd>
#include <iostream>
#include <memory>
#include <optional>
#include <ostream>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

#include "android-base/file.h"
#include "android-base/logging.h"
#include "android-base/macros.h"
#include "android-base/properties.h"
#include "android-base/stringprintf.h"
#include "android-base/strings.h"
#include "android/log.h"
#include "arch/instruction_set.h"
#include "base/file_utils.h"
#include "base/globals.h"
#include "base/macros.h"
#include "base/os.h"
#include "base/string_view_cpp20.h"
#include "base/unix_file/fd_file.h"
#include "com_android_apex.h"
#include "com_android_art.h"
#include "dex/art_dex_file_loader.h"
#include "dexoptanalyzer.h"
#include "exec_utils.h"
#include "log/log.h"
#include "palette/palette.h"
#include "palette/palette_types.h"

#include "odr_artifacts.h"
#include "odr_compilation_log.h"
#include "odr_config.h"
#include "odr_fs_utils.h"
#include "odr_metrics.h"

namespace art {
namespace odrefresh {

namespace apex = com::android::apex;
namespace art_apex = com::android::art;

namespace {

// Name of cache info file in the ART Apex artifact cache.
static constexpr const char* kCacheInfoFile = "cache-info.xml";

static void UsageErrorV(const char* fmt, va_list ap) {
  std::string error;
  android::base::StringAppendV(&error, fmt, ap);
  if (isatty(fileno(stderr))) {
    std::cerr << error << std::endl;
  } else {
    LOG(ERROR) << error;
  }
}

static void UsageError(const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  UsageErrorV(fmt, ap);
  va_end(ap);
}

NO_RETURN static void ArgumentError(const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  UsageErrorV(fmt, ap);
  va_end(ap);
  UsageError("Try '--help' for more information.");
  exit(EX_USAGE);
}

NO_RETURN static void UsageHelp(const char* argv0) {
  std::string name(android::base::Basename(argv0));
  UsageError("Usage: %s ACTION", name.c_str());
  UsageError("On-device refresh tool for boot class path extensions and system server");
  UsageError("following an update of the ART APEX.");
  UsageError("");
  UsageError("Valid ACTION choices are:");
  UsageError("");
  UsageError(
      "--check          Check compilation artifacts are up-to-date based on metadata (fast).");
  UsageError("--compile        Compile boot class path extensions and system_server jars");
  UsageError("                 when necessary.");
  UsageError("--force-compile  Unconditionally compile the boot class path extensions and");
  UsageError("                 system_server jars.");
  UsageError("--verify         Verify artifacts are up-to-date with dexoptanalyzer (slow).");
  UsageError("--help           Display this help information.");
  exit(EX_USAGE);
}

static std::string Concatenate(std::initializer_list<std::string_view> args) {
  std::stringstream ss;
  for (auto arg : args) {
    ss << arg;
  }
  return ss.str();
}

static std::string GetEnvironmentVariableOrDie(const char* name) {
  const char* value = getenv(name);
  LOG_ALWAYS_FATAL_IF(value == nullptr, "%s is not defined.", name);
  return value;
}

static std::string QuotePath(std::string_view path) {
  return Concatenate({"'", path, "'"});
}

static void EraseFiles(const std::vector<std::unique_ptr<File>>& files) {
  for (auto& file : files) {
    file->Erase(/*unlink=*/true);
  }
}

// Moves `files` to the directory `output_directory_path`.
//
// If any of the files cannot be moved, then all copies of the files are removed from both
// the original location and the output location.
//
// Returns true if all files are moved, false otherwise.
static bool MoveOrEraseFiles(const std::vector<std::unique_ptr<File>>& files,
                             std::string_view output_directory_path) {
  std::vector<std::unique_ptr<File>> output_files;
  for (auto& file : files) {
    const std::string file_basename(android::base::Basename(file->GetPath()));
    const std::string output_file_path = Concatenate({output_directory_path, "/", file_basename});
    const std::string input_file_path = file->GetPath();

    output_files.emplace_back(OS::CreateEmptyFileWriteOnly(output_file_path.c_str()));
    if (output_files.back() == nullptr) {
      PLOG(ERROR) << "Failed to open " << QuotePath(output_file_path);
      output_files.pop_back();
      EraseFiles(output_files);
      EraseFiles(files);
      return false;
    }

    static constexpr mode_t kFileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    if (fchmod(output_files.back()->Fd(), kFileMode) != 0) {
      PLOG(ERROR) << "Could not set file mode on " << QuotePath(output_file_path);
      EraseFiles(output_files);
      EraseFiles(files);
      return false;
    }

    const size_t file_bytes = file->GetLength();
    if (!output_files.back()->Copy(file.get(), /*offset=*/0, file_bytes)) {
      PLOG(ERROR) << "Failed to copy " << QuotePath(file->GetPath())
                  << " to " << QuotePath(output_file_path);
      EraseFiles(output_files);
      EraseFiles(files);
      return false;
    }

    if (!file->Erase(/*unlink=*/true)) {
      PLOG(ERROR) << "Failed to erase " << QuotePath(file->GetPath());
      EraseFiles(output_files);
      EraseFiles(files);
      return false;
    }

    if (output_files.back()->FlushCloseOrErase() != 0) {
      PLOG(ERROR) << "Failed to flush and close file " << QuotePath(output_file_path);
      EraseFiles(output_files);
      EraseFiles(files);
      return false;
    }
  }
  return true;
}

}  // namespace

bool ParseZygoteKind(const char* input, ZygoteKind* zygote_kind) {
  std::string_view z(input);
  if (z == "zygote32") {
    *zygote_kind = ZygoteKind::kZygote32;
    return true;
  } else if (z == "zygote32_64") {
    *zygote_kind = ZygoteKind::kZygote32_64;
    return true;
  } else if (z == "zygote64_32") {
    *zygote_kind = ZygoteKind::kZygote64_32;
    return true;
  } else if (z == "zygote64") {
    *zygote_kind = ZygoteKind::kZygote64;
    return true;
  }
  return false;
}

class OnDeviceRefresh final {
 private:
  // Maximum execution time for odrefresh from start to end.
  static constexpr time_t kMaximumExecutionSeconds = 300;

  // Maximum execution time for any child process spawned.
  static constexpr time_t kMaxChildProcessSeconds = 90;

  // Configuration to use.
  const OdrConfig& config_;

  // Path to cache information file that is used to speed up artifact checking.
  const std::string cache_info_filename_;

  // List of boot extension components that should be compiled.
  std::vector<std::string> boot_extension_compilable_jars_;

  // List of system_server components that should be compiled.
  std::vector<std::string> systemserver_compilable_jars_;

  const time_t start_time_;

 public:
  explicit OnDeviceRefresh(const OdrConfig& config)
      : config_{config},
        cache_info_filename_{Concatenate({kOdrefreshArtifactDirectory, "/", kCacheInfoFile})},
        start_time_{time(nullptr)} {
    for (const std::string& jar : android::base::Split(config_.GetDex2oatBootClasspath(), ":")) {
      // Boot class path extensions are those not in the ART APEX. Updatable APEXes should not
      // have DEX files in the DEX2OATBOOTCLASSPATH. At the time of writing i18n is a non-updatable
      // APEX and so does appear in the DEX2OATBOOTCLASSPATH.
      if (!LocationIsOnArtModule(jar)) {
        boot_extension_compilable_jars_.emplace_back(jar);
      }
    }

    for (const std::string& jar : android::base::Split(config_.GetSystemServerClasspath(), ":")) {
      // Only consider DEX files on the SYSTEMSERVERCLASSPATH for compilation that do not reside
      // in APEX modules. Otherwise, we'll recompile on boot any time one of these APEXes updates.
      if (!LocationIsOnApex(jar)) {
        systemserver_compilable_jars_.emplace_back(jar);
      }
    }
  }

  time_t GetExecutionTimeUsed() const { return time(nullptr) - start_time_; }

  time_t GetExecutionTimeRemaining() const {
    return kMaximumExecutionSeconds - GetExecutionTimeUsed();
  }

  time_t GetSubprocessTimeout() const {
    return std::max(GetExecutionTimeRemaining(), kMaxChildProcessSeconds);
  }

  // Gets the `ApexInfo` associated with the currently active ART APEX.
  std::optional<apex::ApexInfo> GetArtApexInfo() const {
    auto info_list = apex::readApexInfoList(config_.GetApexInfoListFile().c_str());
    if (!info_list.has_value()) {
      return {};
    }

    for (const apex::ApexInfo& info : info_list->getApexInfo()) {
      if (info.getIsActive() && info.getModuleName() == "com.android.art") {
        return info;
      }
    }
    return {};
  }

  // Reads the ART APEX cache information (if any) found in `kOdrefreshArtifactDirectory`.
  std::optional<art_apex::CacheInfo> ReadCacheInfo() {
    return art_apex::read(cache_info_filename_.c_str());
  }

  // Write ART APEX cache information to `kOdrefreshArtifactDirectory`.
  void WriteCacheInfo() const {
    if (OS::FileExists(cache_info_filename_.c_str())) {
      if (unlink(cache_info_filename_.c_str()) != 0) {
        PLOG(ERROR) << "Failed to unlink() file " << QuotePath(cache_info_filename_);
      }
    }

    const std::string dir_name = android::base::Dirname(cache_info_filename_);
    if (!EnsureDirectoryExists(dir_name)) {
      LOG(ERROR) << "Could not create directory: " << QuotePath(dir_name);
      return;
    }

    std::optional<art_apex::ArtModuleInfo> art_module_info = GenerateArtModuleInfo();
    if (!art_module_info.has_value()) {
      LOG(ERROR) << "Unable to generate cache provenance";
      return;
    }

    // There can be only one CacheProvence in the XML file, but `xsdc` does not have
    // minOccurs/maxOccurs in the xsd schema.
    const std::vector<art_apex::ArtModuleInfo> art_module_infos { art_module_info.value() };

    std::optional<std::vector<art_apex::Component>> bcp_components =
        GenerateBootExtensionComponents();
    if (!bcp_components.has_value()) {
      LOG(ERROR) << "No boot classpath extension components.";
      return;
    }

    std::optional<std::vector<art_apex::Component>> system_server_components =
        GenerateSystemServerComponents();
    if (!system_server_components.has_value()) {
      LOG(ERROR) << "No system_server extension components.";
      return;
    }

    std::ofstream out(cache_info_filename_.c_str());
    art_apex::CacheInfo info{art_module_infos,
                             {{art_apex::Dex2oatBootClasspath{bcp_components.value()}}},
                             {{art_apex::SystemServerClasspath{system_server_components.value()}}}};

    art_apex::write(out, info);
  }

  // Returns cache provenance information based on the current ART APEX version and filesystem
  // information.
  std::optional<art_apex::ArtModuleInfo> GenerateArtModuleInfo() const {
    auto info = GetArtApexInfo();
    if (!info.has_value()) {
      LOG(ERROR) << "Could not update " << QuotePath(cache_info_filename_) << " : no ART Apex info";
      return {};
    }
    // The lastUpdateMillis is an addition to ApexInfoList.xsd to support samegrade installs.
    int64_t last_update_millis = info->hasLastUpdateMillis() ? info->getLastUpdateMillis() : 0;
    return art_apex::ArtModuleInfo{
        info->getVersionCode(), info->getVersionName(), last_update_millis};
  }

  bool CheckComponents(const std::vector<art_apex::Component>& expected_components,
                       const std::vector<art_apex::Component>& actual_components,
                       std::string* error_msg) const {
    if (expected_components.size() != actual_components.size()) {
      return false;
    }

    for (size_t i = 0; i < expected_components.size(); ++i) {
      const art_apex::Component& expected = expected_components[i];
      const art_apex::Component& actual = actual_components[i];

      if (expected.getFile() != actual.getFile()) {
        *error_msg = android::base::StringPrintf("Component %zu file differs ('%s' != '%s')",
                                                 i,
                                                 expected.getFile().c_str(),
                                                 actual.getFile().c_str());
        return false;
      }
      if (expected.getSize() != actual.getSize()) {
        *error_msg = android::base::StringPrintf("Component %zu size differs (%" PRIu64
                                                 " != %" PRIu64 ")",
                                                 i,
                                                 expected.getSize(),
                                                 actual.getSize());
        return false;
      }
      if (expected.getChecksums() != actual.getChecksums()) {
        *error_msg = android::base::StringPrintf("Component %zu checksums differ ('%s' != '%s')",
                                                 i,
                                                 expected.getChecksums().c_str(),
                                                 actual.getChecksums().c_str());
        return false;
      }
    }

    return true;
  }

  std::vector<art_apex::Component> GenerateComponents(const std::vector<std::string>& jars) const {
    std::vector<art_apex::Component> components;

    ArtDexFileLoader loader;
    for (const std::string& path : jars) {
      struct stat sb;
      if (stat(path.c_str(), &sb) == -1) {
        PLOG(ERROR) << "Failed to get component: " << QuotePath(path);
        return {};
      }

      std::vector<uint32_t> checksums;
      std::vector<std::string> dex_locations;
      std::string error_msg;
      if (!loader.GetMultiDexChecksums(path.c_str(), &checksums, &dex_locations, &error_msg)) {
        LOG(ERROR) << "Failed to get components: " << error_msg;
        return {};
      }

      std::ostringstream oss;
      for (size_t i = 0; i < checksums.size(); ++i) {
        if (i != 0) {
          oss << ';';
        }
        oss << android::base::StringPrintf("%08x", checksums[i]);
      }
      const std::string checksum = oss.str();

      components.emplace_back(
          art_apex::Component{path, static_cast<uint64_t>(sb.st_size), checksum});
    }

    return components;
  }

  std::vector<art_apex::Component> GenerateBootExtensionComponents() const {
    return GenerateComponents(boot_extension_compilable_jars_);
  }

  std::vector<art_apex::Component> GenerateSystemServerComponents() const {
    return GenerateComponents(systemserver_compilable_jars_);
  }

  // Checks whether a group of artifacts exists. Returns true if all are present, false otherwise.
  static bool ArtifactsExist(const OdrArtifacts& artifacts, /*out*/ std::string* error_msg) {
    const auto paths = {
        artifacts.ImagePath().c_str(), artifacts.OatPath().c_str(), artifacts.VdexPath().c_str()};
    for (const char* path : paths) {
      if (!OS::FileExists(path)) {
        if (errno == EACCES) {
          PLOG(ERROR) << "Failed to stat() " << path;
        }
        *error_msg = "Missing file: " + QuotePath(path);
        return false;
      }
    }
    return true;
  }

  // Checks whether all boot extension artifacts are present on /data. Returns true if all are
  // present, false otherwise.
  WARN_UNUSED bool BootExtensionArtifactsExistOnData(const InstructionSet isa,
                                                     /*out*/ std::string* error_msg) const {
    const std::string apexdata_image_location = GetBootImageExtensionImagePath(isa);
    const OdrArtifacts artifacts = OdrArtifacts::ForBootImageExtension(apexdata_image_location);
    return ArtifactsExist(artifacts, error_msg);
  }

  // Checks whether all system_server artifacts are present on /data. The artifacts are checked in
  // their order of compilation. Returns true if all are present, false otherwise.
  WARN_UNUSED bool SystemServerArtifactsExistOnData(/*out*/ std::string* error_msg) const {
    for (const std::string& jar_path : systemserver_compilable_jars_) {
      const std::string image_location = GetSystemServerImagePath(/*on_system=*/false, jar_path);
      const OdrArtifacts artifacts = OdrArtifacts::ForSystemServer(image_location);
      if (!ArtifactsExist(artifacts, error_msg)) {
        return false;
      }
    }
    return true;
  }

  WARN_UNUSED ExitCode CheckArtifactsAreUpToDate(OdrMetrics& metrics) {
    metrics.SetStage(OdrMetrics::Stage::kCheck);

    // Clean-up helper used to simplify clean-ups and handling failures there.
    auto cleanup_return = [this](ExitCode exit_code) {
      return CleanApexdataDirectory() ? exit_code : ExitCode::kCleanupFailed;
    };

    const auto apex_info = GetArtApexInfo();
    if (!apex_info.has_value()) {
      // This should never happen, further up-to-date checks are not possible if it does.
      LOG(ERROR) << "Could not get ART APEX info.";
      metrics.SetTrigger(OdrMetrics::Trigger::kApexVersionMismatch);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    // Generate current module info for the current ART APEX.
    const auto current_info = GenerateArtModuleInfo();
    if (!current_info.has_value()) {
      // This should never happen, further up-to-date checks are not possible if it does.
      LOG(ERROR) << "Failed to generate cache provenance.";
      metrics.SetTrigger(OdrMetrics::Trigger::kUnknown);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    // Record ART APEX version for metrics reporting.
    metrics.SetArtApexVersion(current_info->getVersionCode());

    // Record ART APEX last update milliseconds (used in compilation log).
    metrics.SetArtApexLastUpdateMillis(current_info->getLastUpdateMillis());

    if (apex_info->getIsFactory()) {
      // Remove any artifacts on /data as they are not necessary and no compilation is necessary.
      LOG(INFO) << "Factory APEX mounted.";
      return cleanup_return(ExitCode::kOkay);
    }

    if (!OS::FileExists(cache_info_filename_.c_str())) {
      // If the cache info file does not exist, assume compilation is required because the
      // file is missing and because the current ART APEX is not factory installed.
      PLOG(ERROR) << "No prior cache-info file: " << QuotePath(cache_info_filename_);
      metrics.SetTrigger(OdrMetrics::Trigger::kApexVersionMismatch);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    // Get and parse the ART APEX cache info file.
    std::optional<art_apex::CacheInfo> cache_info = ReadCacheInfo();
    if (!cache_info.has_value()) {
      // This should never happen, further up-to-date checks are not possible if it does.
      PLOG(ERROR) << "Failed to read cache-info file: " << QuotePath(cache_info_filename_);
      metrics.SetTrigger(OdrMetrics::Trigger::kUnknown);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    // Check whether the current cache ART module info differs from the current ART module info.
    // Always check APEX version.
    const auto cached_info = cache_info->getFirstArtModuleInfo();

    if (cached_info->getVersionCode() != current_info->getVersionCode()) {
      LOG(INFO) << "ART APEX version code mismatch ("
                << cached_info->getVersionCode()
                << " != " << current_info->getVersionCode() << ").";
      metrics.SetTrigger(OdrMetrics::Trigger::kApexVersionMismatch);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    if (cached_info->getVersionName() != current_info->getVersionName()) {
      LOG(INFO) << "ART APEX version name mismatch ("
                << cached_info->getVersionName()
                << " != " << current_info->getVersionName() << ").";
      metrics.SetTrigger(OdrMetrics::Trigger::kApexVersionMismatch);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    // Check lastUpdateMillis for samegrade installs. If `cached_info` is missing lastUpdateMillis
    // then it is not current with the schema used by this binary so treat it as a samegrade
    // update. Otherwise check whether the lastUpdateMillis changed.
    if (!cached_info->hasLastUpdateMillis() ||
        cached_info->getLastUpdateMillis() != current_info->getLastUpdateMillis()) {
      LOG(INFO) << "ART APEX last update time mismatch ("
                << cached_info->getLastUpdateMillis()
                << " != " << current_info->getLastUpdateMillis() << ").";
      metrics.SetTrigger(OdrMetrics::Trigger::kApexVersionMismatch);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    // Check boot class components.
    //
    // This checks the size and checksums of odrefresh compilable files on the DEX2OATBOOTCLASSPATH
    // (the Odrefresh constructor determines which files are compilable). If the number of files
    // there changes, or their size or checksums change then compilation will be triggered.
    //
    // The boot class components may change unexpectedly, for example an OTA could update
    // framework.jar.
    const std::vector<art_apex::Component> expected_bcp_components =
        GenerateBootExtensionComponents();
    if (expected_bcp_components.size() != 0 &&
        (!cache_info->hasDex2oatBootClasspath() ||
         !cache_info->getFirstDex2oatBootClasspath()->hasComponent())) {
      LOG(INFO) << "Missing Dex2oatBootClasspath components.";
      metrics.SetTrigger(OdrMetrics::Trigger::kDexFilesChanged);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    std::string error_msg;
    const std::vector<art_apex::Component>& bcp_components =
        cache_info->getFirstDex2oatBootClasspath()->getComponent();
    if (!CheckComponents(expected_bcp_components, bcp_components, &error_msg)) {
      LOG(INFO) << "Dex2OatClasspath components mismatch: " << error_msg;
      metrics.SetTrigger(OdrMetrics::Trigger::kDexFilesChanged);
      return cleanup_return(ExitCode::kCompilationRequired);
    }

    // Check system server components.
    //
    // This checks the size and checksums of odrefresh compilable files on the
    // SYSTEMSERVERCLASSPATH (the Odrefresh constructor determines which files are compilable). If
    // the number of files there changes, or their size or checksums change then compilation will be
    // triggered.
    //
    // The system_server components may change unexpectedly, for example an OTA could update
    // services.jar.
    auto cleanup_system_server_return = [this](ExitCode exit_code) {
      return RemoveSystemServerArtifactsFromData() ? exit_code : ExitCode::kCleanupFailed;
    };

    const std::vector<art_apex::Component> expected_system_server_components =
        GenerateSystemServerComponents();
    if (expected_system_server_components.size() != 0 &&
        (!cache_info->hasSystemServerClasspath() ||
         !cache_info->getFirstSystemServerClasspath()->hasComponent())) {
      LOG(INFO) << "Missing SystemServerClasspath components.";
      metrics.SetTrigger(OdrMetrics::Trigger::kDexFilesChanged);
      return cleanup_system_server_return(ExitCode::kCompilationRequired);
    }

    const std::vector<art_apex::Component>& system_server_components =
        cache_info->getFirstSystemServerClasspath()->getComponent();
    if (!CheckComponents(expected_system_server_components, system_server_components, &error_msg)) {
      LOG(INFO) << "SystemServerClasspath components mismatch: " << error_msg;
      metrics.SetTrigger(OdrMetrics::Trigger::kDexFilesChanged);
      return cleanup_system_server_return(ExitCode::kCompilationRequired);
    }

    // Cache info looks good, check all compilation artifacts exist.
    auto cleanup_boot_extensions_return = [this](ExitCode exit_code, InstructionSet isa) {
      return RemoveBootExtensionArtifactsFromData(isa) ? exit_code : ExitCode::kCleanupFailed;
    };

    for (const InstructionSet isa : config_.GetBootExtensionIsas()) {
      if (!BootExtensionArtifactsExistOnData(isa, &error_msg)) {
        LOG(INFO) << "Incomplete boot extension artifacts. " << error_msg;
        metrics.SetTrigger(OdrMetrics::Trigger::kMissingArtifacts);
        return cleanup_boot_extensions_return(ExitCode::kCompilationRequired, isa);
      }
    }

    if (!SystemServerArtifactsExistOnData(&error_msg)) {
      LOG(INFO) << "Incomplete system_server artifacts. " << error_msg;
      // No clean-up is required here: we have boot extension artifacts. The method
      // `SystemServerArtifactsExistOnData()` checks in compilation order so it is possible some of
      // the artifacts are here. We likely ran out of space compiling the system_server artifacts.
      // Any artifacts present are usable.
      metrics.SetTrigger(OdrMetrics::Trigger::kMissingArtifacts);
      return ExitCode::kCompilationRequired;
    }

    return ExitCode::kOkay;
  }

  static void AddDex2OatCommonOptions(/*inout*/ std::vector<std::string>* args) {
    args->emplace_back("--android-root=out/empty");
    args->emplace_back("--abort-on-hard-verifier-error");
    args->emplace_back("--no-abort-on-soft-verifier-error");
    args->emplace_back("--compilation-reason=boot");
    args->emplace_back("--image-format=lz4");
    args->emplace_back("--force-determinism");
    args->emplace_back("--resolve-startup-const-strings=true");
  }

  static void AddDex2OatConcurrencyArguments(/*inout*/ std::vector<std::string>* args) {
    static constexpr std::pair<const char*, const char*> kPropertyArgPairs[] = {
        std::make_pair("dalvik.vm.boot-dex2oat-cpu-set", "--cpu-set="),
        std::make_pair("dalvik.vm.boot-dex2oat-threads", "-j"),
    };
    for (auto property_arg_pair : kPropertyArgPairs) {
      auto [property, arg] = property_arg_pair;
      std::string value = android::base::GetProperty(property, {});
      if (!value.empty()) {
        args->push_back(arg + value);
      }
    }
  }

  static void AddDex2OatDebugInfo(/*inout*/ std::vector<std::string>* args) {
    args->emplace_back("--generate-mini-debug-info");
    args->emplace_back("--strip");
  }

  static void AddDex2OatInstructionSet(/*inout*/ std::vector<std::string>* args,
                                       InstructionSet isa) {
    const char* isa_str = GetInstructionSetString(isa);
    args->emplace_back(Concatenate({"--instruction-set=", isa_str}));
  }


  static void AddDex2OatProfileAndCompilerFilter(/*inout*/ std::vector<std::string>* args,
                                                 const std::string& profile_file) {
    if (OS::FileExists(profile_file.c_str(), /*check_file_type=*/true)) {
      args->emplace_back(Concatenate({"--profile-file=", profile_file}));
      args->emplace_back("--compiler-filter=speed-profile");
    } else {
      args->emplace_back("--compiler-filter=speed");
    }
  }

  WARN_UNUSED bool VerifySystemServerArtifactsAreUpToDate(bool on_system) const {
    std::vector<std::string> classloader_context;
    for (const std::string& jar_path : systemserver_compilable_jars_) {
      std::vector<std::string> args;
      args.emplace_back(config_.GetDexOptAnalyzer());
      args.emplace_back("--dex-file=" + jar_path);

      const std::string image_location = GetSystemServerImagePath(on_system, jar_path);

      // odrefresh produces app-image files, but these are not guaranteed for those pre-installed
      // on /system.
      if (!on_system && !OS::FileExists(image_location.c_str(), true)) {
        LOG(INFO) << "Missing image file: " << QuotePath(image_location);
        return false;
      }

      // Generate set of artifacts that are output by compilation.
      OdrArtifacts artifacts = OdrArtifacts::ForSystemServer(image_location);
      if (!on_system) {
        CHECK_EQ(artifacts.OatPath(),
                 GetApexDataOdexFilename(jar_path, config_.GetSystemServerIsa()));
        CHECK_EQ(artifacts.ImagePath(),
                 GetApexDataDalvikCacheFilename(jar_path, config_.GetSystemServerIsa(), "art"));
        CHECK_EQ(artifacts.OatPath(),
                 GetApexDataDalvikCacheFilename(jar_path, config_.GetSystemServerIsa(), "odex"));
        CHECK_EQ(artifacts.VdexPath(),
                 GetApexDataDalvikCacheFilename(jar_path, config_.GetSystemServerIsa(), "vdex"));
      }

      // Associate inputs and outputs with dexoptanalyzer arguments.
      std::pair<const std::string, const char*> location_args[] = {
          std::make_pair(artifacts.OatPath(), "--oat-fd="),
          std::make_pair(artifacts.VdexPath(), "--vdex-fd="),
          std::make_pair(jar_path, "--zip-fd=")
      };

      // Open file descriptors for dexoptanalyzer file inputs and add to the command-line.
      std::vector<std::unique_ptr<File>> files;
      for (const auto& location_arg : location_args) {
        auto& [location, arg] = location_arg;
        std::unique_ptr<File> file(OS::OpenFileForReading(location.c_str()));
        if (file == nullptr) {
          PLOG(ERROR) << "Failed to open \"" << location << "\"";
          return false;
        }
        args.emplace_back(android::base::StringPrintf("%s%d", arg, file->Fd()));
        files.emplace_back(file.release());
      }

      const std::string basename(android::base::Basename(jar_path));
      const std::string root = GetAndroidRoot();
      const std::string profile_file = Concatenate({root, "/framework/", basename, ".prof"});
      if (OS::FileExists(profile_file.c_str())) {
        args.emplace_back("--compiler-filter=speed-profile");
      } else {
        args.emplace_back("--compiler-filter=speed");
      }

      args.emplace_back(
          Concatenate({"--image=", GetBootImage(), ":", GetBootImageExtensionImage(on_system)}));
      args.emplace_back(
          Concatenate({"--isa=", GetInstructionSetString(config_.GetSystemServerIsa())}));
      args.emplace_back("--runtime-arg");
      args.emplace_back(Concatenate({"-Xbootclasspath:", config_.GetDex2oatBootClasspath()}));
      args.emplace_back(Concatenate(
          {"--class-loader-context=PCL[", android::base::Join(classloader_context, ':'), "]"}));

      classloader_context.emplace_back(jar_path);

      LOG(INFO) << "Checking " << jar_path << ": " << android::base::Join(args, ' ');
      std::string error_msg;
      bool timed_out = false;
      const time_t timeout = GetSubprocessTimeout();
      const int dexoptanalyzer_result = ExecAndReturnCode(args, timeout, &timed_out, &error_msg);
      if (dexoptanalyzer_result == -1) {
        LOG(ERROR) << "Unexpected exit from dexoptanalyzer: " << error_msg;
        if (timed_out) {
          // TODO(oth): record metric for timeout.
        }
        return false;
      }
      LOG(INFO) << "dexoptanalyzer returned " << dexoptanalyzer_result;

      bool unexpected_result = true;
      switch (static_cast<dexoptanalyzer::ReturnCode>(dexoptanalyzer_result)) {
        case art::dexoptanalyzer::ReturnCode::kNoDexOptNeeded:
          unexpected_result = false;
          break;

        // Recompile needed
        case art::dexoptanalyzer::ReturnCode::kDex2OatFromScratch:
        case art::dexoptanalyzer::ReturnCode::kDex2OatForBootImageOat:
        case art::dexoptanalyzer::ReturnCode::kDex2OatForFilterOat:
        case art::dexoptanalyzer::ReturnCode::kDex2OatForBootImageOdex:
        case art::dexoptanalyzer::ReturnCode::kDex2OatForFilterOdex:
          return false;

        // Unexpected issues (note no default-case here to catch missing enum values, but the
        // return code from dexoptanalyzer may also be outside expected values, such as a
        // process crash.
        case art::dexoptanalyzer::ReturnCode::kFlattenClassLoaderContextSuccess:
        case art::dexoptanalyzer::ReturnCode::kErrorInvalidArguments:
        case art::dexoptanalyzer::ReturnCode::kErrorCannotCreateRuntime:
        case art::dexoptanalyzer::ReturnCode::kErrorUnknownDexOptNeeded:
          break;
      }

      if (unexpected_result) {
        LOG(ERROR) << "Unexpected result from dexoptanalyzer: " << dexoptanalyzer_result;
        return false;
      }
    }
    return true;
  }

  WARN_UNUSED bool RemoveSystemServerArtifactsFromData() const {
    if (config_.GetDryRun()) {
      LOG(INFO) << "Removal of system_server artifacts on /data skipped (dry-run).";
      return true;
    }

    bool success = true;
    for (const std::string& jar_path : systemserver_compilable_jars_) {
      const std::string image_location =
          GetSystemServerImagePath(/*on_system=*/false, jar_path);
      const OdrArtifacts artifacts = OdrArtifacts::ForSystemServer(image_location);
      LOG(INFO) << "Removing system_server artifacts on /data for " << QuotePath(jar_path);
      success &= RemoveArtifacts(artifacts);
    }
    return success;
  }

  // Verify the validity of system server artifacts on both /system and /data.
  // This method has the side-effect of removing system server artifacts on /data, if there are
  // valid artifacts on /system, or if the artifacts on /data are not valid.
  // Returns true if valid artifacts are found.
  WARN_UNUSED bool VerifySystemServerArtifactsAreUpToDate() const {
    bool system_ok = VerifySystemServerArtifactsAreUpToDate(/*on_system=*/true);
    LOG(INFO) << "system_server artifacts on /system are " << (system_ok ? "ok" : "stale");
    bool data_ok = VerifySystemServerArtifactsAreUpToDate(/*on_system=*/false);
    LOG(INFO) << "system_server artifacts on /data are " << (data_ok ? "ok" : "stale");
    return system_ok || data_ok;
  }

  // Check the validity of boot class path extension artifacts.
  //
  // Returns true if artifacts exist and are valid according to dexoptanalyzer.
  WARN_UNUSED bool VerifyBootExtensionArtifactsAreUpToDate(const InstructionSet isa,
                                                           bool on_system) const {
    const std::string dex_file = boot_extension_compilable_jars_.front();
    const std::string image_location = GetBootImageExtensionImage(on_system);

    std::vector<std::string> args;
    args.emplace_back(config_.GetDexOptAnalyzer());
    args.emplace_back("--validate-bcp");
    args.emplace_back(Concatenate({"--image=", GetBootImage(), ":", image_location}));
    args.emplace_back(Concatenate({"--isa=", GetInstructionSetString(isa)}));
    args.emplace_back("--runtime-arg");
    args.emplace_back(Concatenate({"-Xbootclasspath:", config_.GetDex2oatBootClasspath()}));

    LOG(INFO) << "Checking " << dex_file << ": " << android::base::Join(args, ' ');

    std::string error_msg;
    bool timed_out = false;
    const time_t timeout = GetSubprocessTimeout();
    const int dexoptanalyzer_result = ExecAndReturnCode(args, timeout, &timed_out, &error_msg);
    if (dexoptanalyzer_result == -1) {
      LOG(ERROR) << "Unexpected exit from dexoptanalyzer: " << error_msg;
      if (timed_out) {
        // TODO(oth): record metric for timeout.
      }
      return false;
    }
    auto rc = static_cast<dexoptanalyzer::ReturnCode>(dexoptanalyzer_result);
    if (rc == dexoptanalyzer::ReturnCode::kNoDexOptNeeded) {
      return true;
    }
    return false;
  }

  // Remove boot extension artifacts from /data.
  WARN_UNUSED bool RemoveBootExtensionArtifactsFromData(InstructionSet isa) const {
    if (config_.GetDryRun()) {
      LOG(INFO) << "Removal of bcp extension artifacts on /data skipped (dry-run).";
      return true;
    }

    bool success = true;
    if (isa == config_.GetSystemServerIsa()) {
      // system_server artifacts are invalid without boot extension artifacts.
      success &= RemoveSystemServerArtifactsFromData();
    }

    const std::string apexdata_image_location = GetBootImageExtensionImagePath(isa);
    LOG(INFO) << "Removing boot class path artifacts on /data for "
              << QuotePath(apexdata_image_location);
    success &= RemoveArtifacts(OdrArtifacts::ForBootImageExtension(apexdata_image_location));
    return success;
  }

  // Verify whether boot extension artifacts for `isa` are valid on system partition or in apexdata.
  // This method has the side-effect of removing boot classpath extension artifacts on /data,
  // if there are valid artifacts on /system, or if the artifacts on /data are not valid.
  // Returns true if valid boot externsion artifacts are valid.
  WARN_UNUSED bool VerifyBootExtensionArtifactsAreUpToDate(InstructionSet isa) const {
    bool system_ok = VerifyBootExtensionArtifactsAreUpToDate(isa, /*on_system=*/true);
    LOG(INFO) << "Boot extension artifacts on /system are " << (system_ok ? "ok" : "stale");
    bool data_ok = VerifyBootExtensionArtifactsAreUpToDate(isa, /*on_system=*/false);
    LOG(INFO) << "Boot extension artifacts on /data are " << (data_ok ? "ok" : "stale");
    return system_ok || data_ok;
  }

  // Verify all artifacts are up-to-date.
  //
  // This method checks artifacts can be loaded by the runtime.
  //
  // Returns ExitCode::kOkay if artifacts are up-to-date, ExitCode::kCompilationRequired otherwise.
  //
  // NB This is the main function used by the --check command-line option. When invoked with
  // --compile, we only recompile the out-of-date artifacts, not all (see `Odrefresh::Compile`).
  WARN_UNUSED ExitCode VerifyArtifactsAreUpToDate() {
    ExitCode exit_code = ExitCode::kOkay;
    for (const InstructionSet isa : config_.GetBootExtensionIsas()) {
      if (!VerifyBootExtensionArtifactsAreUpToDate(isa)) {
        if (!RemoveBootExtensionArtifactsFromData(isa)) {
          return ExitCode::kCleanupFailed;
        }
        exit_code = ExitCode::kCompilationRequired;
      }
    }
    if (!VerifySystemServerArtifactsAreUpToDate()) {
      if (!RemoveSystemServerArtifactsFromData()) {
        return ExitCode::kCleanupFailed;
      }
      exit_code = ExitCode::kCompilationRequired;
    }
    return exit_code;
  }

  WARN_UNUSED bool CleanApexdataDirectory() const {
    const std::string& apex_data_path = GetArtApexData();
    if (config_.GetDryRun()) {
      LOG(INFO) << "Files under `" << QuotePath(apex_data_path) << " would be removed (dry-run).";
      return true;
    }
    return CleanDirectory(apex_data_path);
  }

  WARN_UNUSED bool RemoveArtifacts(const OdrArtifacts& artifacts) const {
    bool success = true;
    for (const auto& location :
         {artifacts.ImagePath(), artifacts.OatPath(), artifacts.VdexPath()}) {
      if (config_.GetDryRun()) {
        LOG(INFO) << "Removing " << QuotePath(location) << " (dry-run).";
        continue;
      }

      if (OS::FileExists(location.c_str()) && unlink(location.c_str()) != 0) {
        PLOG(ERROR) << "Failed to remove: " << QuotePath(location);
        success = false;
      }
    }
    return success;
  }

  static std::string GetBootImage() {
    // Typically "/apex/com.android.art/javalib/boot.art".
    return GetArtRoot() + "/javalib/boot.art";
  }

  std::string GetBootImageExtensionImage(bool on_system) const {
    CHECK(!boot_extension_compilable_jars_.empty());
    const std::string leading_jar = boot_extension_compilable_jars_[0];
    if (on_system) {
      const std::string jar_name = android::base::Basename(leading_jar);
      const std::string image_name = ReplaceFileExtension(jar_name, "art");
      // Typically "/system/framework/boot-framework.art".
      return Concatenate({GetAndroidRoot(), "/framework/boot-", image_name});
    } else {
      // Typically "/data/misc/apexdata/com.android.art/dalvik-cache/boot-framework.art".
      return GetApexDataBootImage(leading_jar);
    }
  }

  std::string GetBootImageExtensionImagePath(const InstructionSet isa) const {
    // Typically "/data/misc/apexdata/com.android.art/dalvik-cache/<isa>/boot-framework.art".
    return GetSystemImageFilename(GetBootImageExtensionImage(/*on_system=*/false).c_str(), isa);
  }

  std::string GetSystemServerImagePath(bool on_system, const std::string& jar_path) const {
    if (on_system) {
      const std::string jar_name = android::base::Basename(jar_path);
      const std::string image_name = ReplaceFileExtension(jar_name, "art");
      const char* isa_str = GetInstructionSetString(config_.GetSystemServerIsa());
      // Typically "/system/framework/oat/<isa>/services.art".
      return Concatenate({GetAndroidRoot(), "/framework/oat/", isa_str, "/", image_name});
    } else {
      // Typically
      // "/data/misc/apexdata/.../dalvik-cache/<isa>/system@framework@services.jar@classes.art".
      const std::string image = GetApexDataImage(jar_path.c_str());
      return GetSystemImageFilename(image.c_str(), config_.GetSystemServerIsa());
    }
  }

  std::string GetStagingLocation(const std::string& staging_dir, const std::string& path) const {
    return Concatenate({staging_dir, "/", android::base::Basename(path)});
  }

  WARN_UNUSED bool CompileBootExtensionArtifacts(const InstructionSet isa,
                                                 const std::string& staging_dir,
                                                 OdrMetrics& metrics,
                                                 uint32_t* dex2oat_invocation_count,
                                                 std::string* error_msg) const {
    ScopedOdrCompilationTimer compilation_timer(metrics);
    std::vector<std::string> args;
    args.push_back(config_.GetDex2Oat());

    AddDex2OatCommonOptions(&args);
    AddDex2OatConcurrencyArguments(&args);
    AddDex2OatDebugInfo(&args);
    AddDex2OatInstructionSet(&args, isa);
    const std::string boot_profile_file(GetAndroidRoot() + "/etc/boot-image.prof");
    AddDex2OatProfileAndCompilerFilter(&args, boot_profile_file);

    // Compile as a single image for fewer files and slightly less memory overhead.
    args.emplace_back("--single-image");

    // Set boot-image and expectation of compiling boot classpath extensions.
    args.emplace_back("--boot-image=" + GetBootImage());

    const std::string dirty_image_objects_file(GetAndroidRoot() + "/etc/dirty-image-objects");
    if (OS::FileExists(dirty_image_objects_file.c_str())) {
      args.emplace_back(Concatenate({"--dirty-image-objects=", dirty_image_objects_file}));
    } else {
      LOG(WARNING) << "Missing dirty objects file : " << QuotePath(dirty_image_objects_file);
    }

    // Add boot extensions to compile.
    for (const std::string& component : boot_extension_compilable_jars_) {
      args.emplace_back("--dex-file=" + component);
    }

    args.emplace_back("--runtime-arg");
    args.emplace_back(Concatenate({"-Xbootclasspath:", config_.GetDex2oatBootClasspath()}));

    const std::string image_location = GetBootImageExtensionImagePath(isa);
    const OdrArtifacts artifacts = OdrArtifacts::ForBootImageExtension(image_location);
    CHECK_EQ(GetApexDataOatFilename(boot_extension_compilable_jars_.front().c_str(), isa),
             artifacts.OatPath());

    args.emplace_back("--oat-location=" + artifacts.OatPath());
    const std::pair<const std::string, const char*> location_kind_pairs[] = {
        std::make_pair(artifacts.ImagePath(), "image"),
        std::make_pair(artifacts.OatPath(), "oat"),
        std::make_pair(artifacts.VdexPath(), "output-vdex")
    };

    std::vector<std::unique_ptr<File>> staging_files;
    for (const auto& location_kind_pair : location_kind_pairs) {
      auto& [location, kind] = location_kind_pair;
      const std::string staging_location = GetStagingLocation(staging_dir, location);
      std::unique_ptr<File> staging_file(OS::CreateEmptyFile(staging_location.c_str()));
      if (staging_file == nullptr) {
        PLOG(ERROR) << "Failed to create " << kind << " file: " << staging_location;
        metrics.SetStatus(OdrMetrics::Status::kIoError);
        EraseFiles(staging_files);
        return false;
      }

      if (fchmod(staging_file->Fd(), S_IRUSR | S_IWUSR) != 0) {
        PLOG(ERROR) << "Could not set file mode on " << QuotePath(staging_location);
        metrics.SetStatus(OdrMetrics::Status::kIoError);
        EraseFiles(staging_files);
        return false;
      }

      args.emplace_back(android::base::StringPrintf("--%s-fd=%d", kind, staging_file->Fd()));
      staging_files.emplace_back(std::move(staging_file));
    }

    const std::string install_location = android::base::Dirname(image_location);
    if (!EnsureDirectoryExists(install_location)) {
      metrics.SetStatus(OdrMetrics::Status::kIoError);
      return false;
    }

    const time_t timeout = GetSubprocessTimeout();
    const std::string cmd_line = android::base::Join(args, ' ');
    LOG(INFO) << "Compiling boot extensions (" << isa << "): " << cmd_line
              << " [timeout " << timeout << "s]";
    if (config_.GetDryRun()) {
      LOG(INFO) << "Compilation skipped (dry-run).";
      return true;
    }

    bool timed_out = false;
    int dex2oat_exit_code = ExecAndReturnCode(args, timeout, &timed_out, error_msg);
    if (dex2oat_exit_code != 0) {
      if (timed_out) {
        metrics.SetStatus(OdrMetrics::Status::kTimeLimitExceeded);
      } else {
        metrics.SetStatus(OdrMetrics::Status::kDex2OatError);
      }
      EraseFiles(staging_files);
      return false;
    }

    if (!MoveOrEraseFiles(staging_files, install_location)) {
      metrics.SetStatus(OdrMetrics::Status::kInstallFailed);
      return false;
    }

    *dex2oat_invocation_count = *dex2oat_invocation_count + 1;
    ReportNextBootAnimationProgress(*dex2oat_invocation_count);

    return true;
  }

  WARN_UNUSED bool CompileSystemServerArtifacts(const std::string& staging_dir,
                                                OdrMetrics& metrics,
                                                uint32_t* dex2oat_invocation_count,
                                                std::string* error_msg) const {
    ScopedOdrCompilationTimer compilation_timer(metrics);
    std::vector<std::string> classloader_context;

    const std::string dex2oat = config_.GetDex2Oat();
    const InstructionSet isa = config_.GetSystemServerIsa();
    for (const std::string& jar : systemserver_compilable_jars_) {
      std::vector<std::string> args;
      args.emplace_back(dex2oat);
      args.emplace_back("--dex-file=" + jar);

      AddDex2OatCommonOptions(&args);
      AddDex2OatConcurrencyArguments(&args);
      AddDex2OatDebugInfo(&args);
      AddDex2OatInstructionSet(&args, isa);
      const std::string jar_name(android::base::Basename(jar));
      const std::string profile = Concatenate({GetAndroidRoot(), "/framework/", jar_name, ".prof"});
      std::string compiler_filter =
          android::base::GetProperty("dalvik.vm.systemservercompilerfilter", "speed");
      if (compiler_filter == "speed-profile") {
        AddDex2OatProfileAndCompilerFilter(&args, profile);
      } else {
        args.emplace_back("--compiler-filter=" + compiler_filter);
      }

      const std::string image_location = GetSystemServerImagePath(/*on_system=*/false, jar);
      const std::string install_location = android::base::Dirname(image_location);
      if (classloader_context.empty()) {
        // All images are in the same directory, we only need to check on the first iteration.
        if (!EnsureDirectoryExists(install_location)) {
          metrics.SetStatus(OdrMetrics::Status::kIoError);
          return false;
        }
      }

      OdrArtifacts artifacts = OdrArtifacts::ForSystemServer(image_location);
      CHECK_EQ(artifacts.OatPath(), GetApexDataOdexFilename(jar.c_str(), isa));

      const std::pair<const std::string, const char*> location_kind_pairs[] = {
          std::make_pair(artifacts.ImagePath(), "app-image"),
          std::make_pair(artifacts.OatPath(), "oat"),
          std::make_pair(artifacts.VdexPath(), "output-vdex")
      };

      std::vector<std::unique_ptr<File>> staging_files;
      for (const auto& location_kind_pair : location_kind_pairs) {
        auto& [location, kind] = location_kind_pair;
        const std::string staging_location = GetStagingLocation(staging_dir, location);
        std::unique_ptr<File> staging_file(OS::CreateEmptyFile(staging_location.c_str()));
        if (staging_file == nullptr) {
          PLOG(ERROR) << "Failed to create " << kind << " file: " << staging_location;
          metrics.SetStatus(OdrMetrics::Status::kIoError);
          EraseFiles(staging_files);
          return false;
        }
        args.emplace_back(android::base::StringPrintf("--%s-fd=%d", kind, staging_file->Fd()));
        staging_files.emplace_back(std::move(staging_file));
      }
      args.emplace_back("--oat-location=" + artifacts.OatPath());

      if (!config_.GetUpdatableBcpPackagesFile().empty()) {
        const std::string& bcp_packages = config_.GetUpdatableBcpPackagesFile();
        if (!OS::FileExists(bcp_packages.c_str())) {
          *error_msg = "Cannot compile system_server JARs: missing " + QuotePath(bcp_packages);
          metrics.SetStatus(OdrMetrics::Status::kIoError);
          EraseFiles(staging_files);
          return false;
        }
        args.emplace_back("--updatable-bcp-packages-file=" + bcp_packages);
      }

      args.emplace_back("--runtime-arg");
      args.emplace_back(Concatenate({"-Xbootclasspath:", config_.GetDex2oatBootClasspath()}));
      const std::string context_path = android::base::Join(classloader_context, ':');
      args.emplace_back(Concatenate({"--class-loader-context=PCL[", context_path, "]"}));
      const std::string extension_image = GetBootImageExtensionImage(/*on_system=*/false);
      args.emplace_back(Concatenate({"--boot-image=", GetBootImage(), ":", extension_image}));

      const time_t timeout = GetSubprocessTimeout();
      const std::string cmd_line = android::base::Join(args, ' ');
      LOG(INFO) << "Compiling " << jar << ": " << cmd_line << " [timeout " << timeout << "s]";
      if (config_.GetDryRun()) {
        LOG(INFO) << "Compilation skipped (dry-run).";
        return true;
      }

      bool timed_out = false;
      int dex2oat_exit_code = ExecAndReturnCode(args, timeout, &timed_out, error_msg);
      if (dex2oat_exit_code != 0) {
        if (timed_out) {
          metrics.SetStatus(OdrMetrics::Status::kTimeLimitExceeded);
        } else {
          metrics.SetStatus(OdrMetrics::Status::kDex2OatError);
        }
        EraseFiles(staging_files);
        return false;
      }

      if (!MoveOrEraseFiles(staging_files, install_location)) {
        metrics.SetStatus(OdrMetrics::Status::kInstallFailed);
        return false;
      }

      *dex2oat_invocation_count = *dex2oat_invocation_count + 1;
      ReportNextBootAnimationProgress(*dex2oat_invocation_count);
      classloader_context.emplace_back(jar);
    }

    return true;
  }

  void ReportNextBootAnimationProgress(uint32_t current_compilation) const {
    uint32_t number_of_compilations =
        config_.GetBootExtensionIsas().size() + systemserver_compilable_jars_.size();
    // We arbitrarily show progress until 90%, expecting that our compilations
    // take a large chunk of boot time.
    uint32_t value = (90 * current_compilation) / number_of_compilations;
    android::base::SetProperty("service.bootanim.progress", std::to_string(value));
  }

  WARN_UNUSED bool CheckCompilationSpace() const {
    // Check the available storage space against an arbitrary threshold because dex2oat does not
    // report when it runs out of storage space and we do not want to completely fill
    // the users data partition.
    //
    // We do not have a good way of pre-computing the required space for a compilation step, but
    // typically observe 16MB as the largest size of an AOT artifact. Since there are three
    // AOT artifacts per compilation step - an image file, executable file, and a verification
    // data file - the threshold is three times 16MB.
    static constexpr uint64_t kMinimumSpaceForCompilation = 3 * 16 * 1024 * 1024;

    uint64_t bytes_available;
    const std::string& art_apex_data_path = GetArtApexData();
    if (!GetFreeSpace(art_apex_data_path, &bytes_available)) {
      return false;
    }

    if (bytes_available < kMinimumSpaceForCompilation) {
      LOG(WARNING) << "Low space for " << QuotePath(art_apex_data_path) << " (" << bytes_available
                   << " bytes)";
      return false;
    }

    return true;
  }

  WARN_UNUSED ExitCode Compile(OdrMetrics& metrics, bool force_compile) const {
    const char* staging_dir = nullptr;
    metrics.SetStage(OdrMetrics::Stage::kPreparation);
    // Clean-up existing files.
    if (force_compile && !CleanApexdataDirectory()) {
      metrics.SetStatus(OdrMetrics::Status::kIoError);
      return ExitCode::kCleanupFailed;
    }

    // Create staging area and assign label for generating compilation artifacts.
    if (PaletteCreateOdrefreshStagingDirectory(&staging_dir) != PALETTE_STATUS_OK) {
      metrics.SetStatus(OdrMetrics::Status::kStagingFailed);
      return ExitCode::kCleanupFailed;
    }

    // Emit cache info before compiling. This can be used to throttle compilation attempts later.
    WriteCacheInfo();

    std::string error_msg;

    uint32_t dex2oat_invocation_count = 0;
    ReportNextBootAnimationProgress(dex2oat_invocation_count);

    const auto& bcp_instruction_sets = config_.GetBootExtensionIsas();
    DCHECK(!bcp_instruction_sets.empty() && bcp_instruction_sets.size() <= 2);
    for (const InstructionSet isa : bcp_instruction_sets) {
      auto stage = (isa == bcp_instruction_sets.front()) ?
                       OdrMetrics::Stage::kPrimaryBootClasspath :
                       OdrMetrics::Stage::kSecondaryBootClasspath;
      metrics.SetStage(stage);
      if (force_compile || !BootExtensionArtifactsExistOnData(isa, &error_msg)) {
        // Remove artifacts we are about to generate. Ordinarily these are removed in the checking
        // step, but this is not always run (e.g. during manual testing).
        if (!RemoveBootExtensionArtifactsFromData(isa)) {
            return ExitCode::kCleanupFailed;
        }

        if (!CheckCompilationSpace()) {
          metrics.SetStatus(OdrMetrics::Status::kNoSpace);
          // Return kOkay so odsign will keep and sign whatever we have been able to compile.
          return ExitCode::kOkay;
        }

        if (!CompileBootExtensionArtifacts(
                isa, staging_dir, metrics, &dex2oat_invocation_count, &error_msg)) {
          LOG(ERROR) << "Compilation of BCP failed: " << error_msg;
          if (!config_.GetDryRun() && !CleanDirectory(staging_dir)) {
            return ExitCode::kCleanupFailed;
          }
          return ExitCode::kCompilationFailed;
        }
      }
    }

    if (force_compile || !SystemServerArtifactsExistOnData(&error_msg)) {
      metrics.SetStage(OdrMetrics::Stage::kSystemServerClasspath);

      if (!CheckCompilationSpace()) {
        metrics.SetStatus(OdrMetrics::Status::kNoSpace);
        // Return kOkay so odsign will keep and sign whatever we have been able to compile.
        return ExitCode::kOkay;
      }

      if (!CompileSystemServerArtifacts(
              staging_dir, metrics, &dex2oat_invocation_count, &error_msg)) {
        LOG(ERROR) << "Compilation of system_server failed: " << error_msg;
        if (!config_.GetDryRun() && !CleanDirectory(staging_dir)) {
          return ExitCode::kCleanupFailed;
        }
        return ExitCode::kCompilationFailed;
      }
    }

    metrics.SetStage(OdrMetrics::Stage::kComplete);
    return ExitCode::kCompilationSuccess;
  }

  static bool ArgumentMatches(std::string_view argument,
                              std::string_view prefix,
                              std::string* value) {
    if (StartsWith(argument, prefix)) {
      *value = std::string(argument.substr(prefix.size()));
      return true;
    }
    return false;
  }

  static bool ArgumentEquals(std::string_view argument, std::string_view expected) {
    return argument == expected;
  }

  static bool InitializeCommonConfig(std::string_view argument, OdrConfig* config) {
    static constexpr std::string_view kDryRunArgument{"--dry-run"};
    if (ArgumentEquals(argument, kDryRunArgument)) {
      config->SetDryRun();
      return true;
    }
    return false;
  }

  static int InitializeHostConfig(int argc, const char** argv, OdrConfig* config) {
    __android_log_set_logger(__android_log_stderr_logger);

    std::string current_binary;
    if (argv[0][0] == '/') {
      current_binary = argv[0];
    } else {
      std::vector<char> buf(PATH_MAX);
      if (getcwd(buf.data(), buf.size()) == nullptr) {
        PLOG(FATAL) << "Failed getwd()";
      }
      current_binary = Concatenate({buf.data(), "/", argv[0]});
    }
    config->SetArtBinDir(android::base::Dirname(current_binary));

    int n = 1;
    for (; n < argc - 1; ++n) {
      const char* arg = argv[n];
      std::string value;
      if (ArgumentMatches(arg, "--android-root=", &value)) {
        setenv("ANDROID_ROOT", value.c_str(), 1);
      } else if (ArgumentMatches(arg, "--android-art-root=", &value)) {
        setenv("ANDROID_ART_ROOT", value.c_str(), 1);
      } else if (ArgumentMatches(arg, "--apex-info-list=", &value)) {
        config->SetApexInfoListFile(value);
      } else if (ArgumentMatches(arg, "--art-apex-data=", &value)) {
        setenv("ART_APEX_DATA", value.c_str(), 1);
      } else if (ArgumentMatches(arg, "--dex2oat-bootclasspath=", &value)) {
        config->SetDex2oatBootclasspath(value);
      } else if (ArgumentMatches(arg, "--isa=", &value)) {
        config->SetIsa(GetInstructionSetFromString(value.c_str()));
      } else if (ArgumentMatches(arg, "--system-server-classpath=", &value)) {
        config->SetSystemServerClasspath(arg);
      } else if (ArgumentMatches(arg, "--updatable-bcp-packages-file=", &value)) {
        config->SetUpdatableBcpPackagesFile(value);
      } else if (ArgumentMatches(arg, "--zygote-arch=", &value)) {
        ZygoteKind zygote_kind;
        if (!ParseZygoteKind(value.c_str(), &zygote_kind)) {
          ArgumentError("Unrecognized zygote kind: '%s'", value.c_str());
        }
        config->SetZygoteKind(zygote_kind);
      } else if (!InitializeCommonConfig(arg, config)) {
        UsageError("Unrecognized argument: '%s'", arg);
      }
    }
    return n;
  }

  static int InitializeTargetConfig(int argc, const char** argv, OdrConfig* config) {
    config->SetApexInfoListFile("/apex/apex-info-list.xml");
    config->SetArtBinDir(GetArtBinDir());
    config->SetDex2oatBootclasspath(GetEnvironmentVariableOrDie("DEX2OATBOOTCLASSPATH"));
    config->SetSystemServerClasspath(GetEnvironmentVariableOrDie("SYSTEMSERVERCLASSPATH"));
    config->SetIsa(kRuntimeISA);

    const std::string zygote = android::base::GetProperty("ro.zygote", {});
    ZygoteKind zygote_kind;
    if (!ParseZygoteKind(zygote.c_str(), &zygote_kind)) {
      LOG(FATAL) << "Unknown zygote: " << QuotePath(zygote);
    }
    config->SetZygoteKind(zygote_kind);

    const std::string updatable_packages =
        android::base::GetProperty("dalvik.vm.dex2oat-updatable-bcp-packages-file", {});
    config->SetUpdatableBcpPackagesFile(updatable_packages);

    int n = 1;
    for (; n < argc - 1; ++n) {
      if (!InitializeCommonConfig(argv[n], config)) {
        UsageError("Unrecognized argument: '%s'", argv[n]);
      }
    }
    return n;
  }

  static int InitializeConfig(int argc, const char** argv, OdrConfig* config) {
    if (kIsTargetBuild) {
      return InitializeTargetConfig(argc, argv, config);
    } else {
      return InitializeHostConfig(argc, argv, config);
    }
  }

  static int main(int argc, const char** argv) {
    OdrConfig config(argv[0]);
    int n = InitializeConfig(argc, argv, &config);
    argv += n;
    argc -= n;
    if (argc != 1) {
      UsageError("Expected 1 argument, but have %d.", argc);
    }

    OdrMetrics metrics(kOdrefreshArtifactDirectory);
    OnDeviceRefresh odr(config);
    for (int i = 0; i < argc; ++i) {
      std::string_view action(argv[i]);
      if (action == "--check") {
        // Fast determination of whether artifacts are up to date.
        return odr.CheckArtifactsAreUpToDate(metrics);
      } else if (action == "--compile") {
        const ExitCode exit_code = odr.CheckArtifactsAreUpToDate(metrics);
        if (exit_code != ExitCode::kCompilationRequired) {
          return exit_code;
        }
        OdrCompilationLog compilation_log;
        if (!compilation_log.ShouldAttemptCompile(metrics.GetArtApexVersion(),
                                                  metrics.GetArtApexLastUpdateMillis(),
                                                  metrics.GetTrigger())) {
          return ExitCode::kOkay;
        }
        ExitCode compile_result = odr.Compile(metrics, /*force_compile=*/false);
        compilation_log.Log(metrics.GetArtApexVersion(),
                            metrics.GetArtApexLastUpdateMillis(),
                            metrics.GetTrigger(),
                            compile_result);
        return compile_result;
      } else if (action == "--force-compile") {
        return odr.Compile(metrics, /*force_compile=*/true);
      } else if (action == "--verify") {
        // Slow determination of whether artifacts are up to date. These are too slow for checking
        // during boot (b/181689036).
        return odr.VerifyArtifactsAreUpToDate();
      } else if (action == "--help") {
        UsageHelp(argv[0]);
      } else {
        UsageError("Unknown argument: ", argv[i]);
      }
    }
    return ExitCode::kOkay;
  }

  DISALLOW_COPY_AND_ASSIGN(OnDeviceRefresh);
};

}  // namespace odrefresh
}  // namespace art

int main(int argc, const char** argv) {
  // odrefresh is launched by `init` which sets the umask of forked processed to
  // 077 (S_IRWXG | S_IRWXO). This blocks the ability to make files and directories readable
  // by others and prevents system_server from loading generated artifacts.
  umask(S_IWGRP | S_IWOTH);
  return art::odrefresh::OnDeviceRefresh::main(argc, argv);
}
