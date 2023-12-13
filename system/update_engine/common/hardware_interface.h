//
// Copyright (C) 2013 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef UPDATE_ENGINE_COMMON_HARDWARE_INTERFACE_H_
#define UPDATE_ENGINE_COMMON_HARDWARE_INTERFACE_H_

#include <stdint.h>

#include <string>
#include <vector>

#include <base/files/file_path.h>
#include <base/time/time.h>

#include "update_engine/common/error_code.h"

namespace chromeos_update_engine {

// The hardware interface allows access to the crossystem exposed properties,
// such as the firmware version, hwid, verified boot mode.
// These stateless functions are tied together in this interface to facilitate
// unit testing.
class HardwareInterface {
 public:
  virtual ~HardwareInterface() {}

  // Returns whether this is an official build. Official build means that the
  // server maintains and updates the build, so update_engine should run and
  // periodically check for updates.
  virtual bool IsOfficialBuild() const = 0;

  // Returns true if the boot mode is normal or if it's unable to
  // determine the boot mode. Returns false if the boot mode is
  // developer. A dev-mode boot will allow the user to access developer-only
  // features.
  virtual bool IsNormalBootMode() const = 0;

  // Returns whether the developer features are enabled.
  virtual bool AreDevFeaturesEnabled() const = 0;

  // Returns whether the device has an OOBE flow that the user must go through
  // before getting non-critical updates. Use IsOOBEComplete() to determine if
  // that flow is complete.
  virtual bool IsOOBEEnabled() const = 0;

  // Returns true if the OOBE process has been completed and EULA accepted,
  // False otherwise. If True is returned, and |out_time_of_oobe| isn't null,
  // the time-stamp of when OOBE happened is stored at |out_time_of_oobe|.
  virtual bool IsOOBEComplete(base::Time* out_time_of_oobe) const = 0;

  // Returns the HWID or an empty string on error.
  virtual std::string GetHardwareClass() const = 0;

  // Returns the OEM device requisition or an empty string if the system does
  // not have a requisition, or if not running Chrome OS.
  virtual std::string GetDeviceRequisition() const = 0;

  // Returns the minimum kernel key version that verified boot on Chrome OS
  // will allow to boot. This is the value of crossystem tpm_kernver. Returns
  // -1 on error, or if not running on Chrome OS.
  virtual int GetMinKernelKeyVersion() const = 0;

  // Returns the minimum firmware key version that verified boot on Chrome OS
  // will allow to boot. This is the value of crossystem tpm_fwver. Returns
  // -1 on error, or if not running on Chrome OS.
  virtual int GetMinFirmwareKeyVersion() const = 0;

  // Returns the maximum firmware key version that verified boot should roll
  // forward to. This is the value of crossystem firmware_max_rollforward.
  // Returns -1 on error, if this board does not yet support this value, or
  // if not running on Chrome OS.
  virtual int GetMaxFirmwareKeyRollforward() const = 0;

  // Sets the maximum firmware key version that verified boot should roll
  // forward to. This is the value of crossystem firmware_max_rollforward.
  // This value is not available on all Chrome OS devices.
  virtual bool SetMaxFirmwareKeyRollforward(int firmware_max_rollforward) = 0;

  // Sets the maximum kernel key version that verified boot should roll
  // forward to. This is the value of crossystem kernel_max_rollforward.
  // Returns false if the value cannot be set, or if not running on Chrome OS.
  virtual bool SetMaxKernelKeyRollforward(int kernel_max_rollforward) = 0;

  // Returns the powerwash_count from the stateful. If the file is not found
  // or is invalid, returns -1. Brand new machines out of the factory or after
  // recovery don't have this value set.
  virtual int GetPowerwashCount() const = 0;

  // Signals that a powerwash (stateful partition wipe) should be performed
  // after reboot. If |save_rollback_data| is true additional state is
  // preserved during shutdown that can be restored after the powerwash.
  virtual bool SchedulePowerwash(bool save_rollback_data) = 0;

  // Cancel the powerwash operation scheduled to be performed on next boot.
  virtual bool CancelPowerwash() = 0;

  // Store in |path| the path to a non-volatile directory (persisted across
  // reboots) available for this daemon. In case of an error, such as no
  // directory available, returns false.
  virtual bool GetNonVolatileDirectory(base::FilePath* path) const = 0;

  // Store in |path| the path to a non-volatile directory persisted across
  // powerwash cycles. In case of an error, such as no directory available,
  // returns false.
  virtual bool GetPowerwashSafeDirectory(base::FilePath* path) const = 0;

  // Returns the timestamp of the current OS build.
  virtual int64_t GetBuildTimestamp() const = 0;

  // Returns true if the current OS build allows installing the payload with an
  // older timestamp.
  virtual bool AllowDowngrade() const = 0;

  // Returns whether the first active ping was sent to Omaha at some point, and
  // that the value is persisted across recovery (and powerwash) once set with
  // |SetFirstActiveOmahaPingSent()|.
  virtual bool GetFirstActiveOmahaPingSent() const = 0;

  // Persist the fact that first active ping was sent to omaha and returns false
  // if failed to persist it.
  virtual bool SetFirstActiveOmahaPingSent() = 0;

  // If |warm_reset| is true, sets the warm reset to indicate a warm reset is
  // needed on the next reboot. Otherwise, clears the flag.
  virtual void SetWarmReset(bool warm_reset) = 0;

  // If not reset, sets the vbmeta digest of the inactive slot as a sysprop.
  // Otherwise, clears the sysprop.
  virtual void SetVbmetaDigestForInactiveSlot(bool reset) = 0;

  // Return the version/timestamp for partition `partition_name`.
  // Don't make any assumption about the formatting of returned string.
  // Only used for logging/debugging purposes.
  virtual std::string GetVersionForLogging(
      const std::string& partition_name) const = 0;

  // Return true if and only if `new_version` is "newer" than the
  // version number of partition `partition_name`. The notion of
  // "newer" is defined by this function. Caller should not make
  // any assumption about the underlying logic.
  // Return:
  // - kSuccess if update is valid.
  // - kPayloadTimestampError if downgrade is detected
  // - kDownloadManifestParseError if |new_version| has an incorrect format
  // - Other error values if the source of error is known, or kError for
  //   a generic error on the device.
  virtual ErrorCode IsPartitionUpdateValid(
      const std::string& partition_name,
      const std::string& new_version) const = 0;

  virtual const char* GetPartitionMountOptions(
      const std::string& partition_name) const = 0;
};

}  // namespace chromeos_update_engine

#endif  // UPDATE_ENGINE_COMMON_HARDWARE_INTERFACE_H_
