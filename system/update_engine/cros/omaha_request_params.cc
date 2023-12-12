//
// Copyright (C) 2011 The Android Open Source Project
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

#include "update_engine/cros/omaha_request_params.h"

#include <errno.h>
#include <fcntl.h>
#include <sys/utsname.h>

#include <map>
#include <string>
#include <vector>

#include <base/files/file_util.h>
#include <base/stl_util.h>
#include <base/strings/string_util.h>
#include <base/strings/stringprintf.h>
#include <brillo/key_value_store.h>
#include <brillo/strings/string_utils.h>
#include <policy/device_policy.h>

#include "update_engine/common/constants.h"
#include "update_engine/common/hardware_interface.h"
#include "update_engine/common/platform_constants.h"
#include "update_engine/common/system_state.h"
#include "update_engine/common/utils.h"
#include "update_engine/update_manager/policy.h"

#define CALL_MEMBER_FN(object, member) ((object).*(member))

using chromeos_update_manager::UpdateCheckParams;
using std::string;

namespace chromeos_update_engine {

const char OmahaRequestParams::kOsVersion[] = "Indy";

const char* kChannelsByStability[] = {
    // This list has to be sorted from least stable to most stable channel.
    "canary-channel",
    "dev-channel",
    "beta-channel",
    "stable-channel",
};

OmahaRequestParams::~OmahaRequestParams() {
  if (!root_.empty())
    test::SetImagePropertiesRootPrefix(nullptr);
}

bool OmahaRequestParams::Init(const string& app_version,
                              const string& update_url,
                              const UpdateCheckParams& params) {
  LOG(INFO) << "Initializing parameters for this update attempt";
  image_props_ = LoadImageProperties();
  mutable_image_props_ = LoadMutableImageProperties();

  // Validation check the channel names.
  if (!IsValidChannel(image_props_.current_channel))
    image_props_.current_channel = "stable-channel";
  if (!IsValidChannel(mutable_image_props_.target_channel))
    mutable_image_props_.target_channel = image_props_.current_channel;
  UpdateDownloadChannel();

  LOG(INFO) << "Running from channel " << image_props_.current_channel;

  os_platform_ = constants::kOmahaPlatformName;
  os_version_ = OmahaRequestParams::kOsVersion;
  if (!app_version.empty())
    image_props_.version = app_version;

  os_sp_ = image_props_.version + "_" + GetMachineType();
  app_lang_ = "en-US";
  hwid_ = SystemState::Get()->hardware()->GetHardwareClass();
  device_requisition_ = SystemState::Get()->hardware()->GetDeviceRequisition();

  if (image_props_.current_channel == mutable_image_props_.target_channel) {
    // deltas are only okay if the /.nodelta file does not exist.  if we don't
    // know (i.e. stat() returns some unexpected error), then err on the side of
    // caution and say deltas are not okay.
    struct stat stbuf;
    delta_okay_ =
        (stat((root_ + "/.nodelta").c_str(), &stbuf) < 0) && (errno == ENOENT);
  } else {
    LOG(INFO) << "Disabling deltas as a channel change to "
              << mutable_image_props_.target_channel
              << " is pending, with is_powerwash_allowed="
              << utils::ToString(mutable_image_props_.is_powerwash_allowed);
    // For now, disable delta updates if the current channel is different from
    // the channel that we're sending to the update server because such updates
    // are destined to fail -- the current rootfs hash will be different than
    // the expected hash due to the different channel in /etc/lsb-release.
    delta_okay_ = false;
  }

  if (update_url.empty())
    update_url_ = image_props_.omaha_url;
  else
    update_url_ = update_url;

  // Set the interactive flag accordingly.
  interactive_ = params.interactive;

  dlc_apps_params_.clear();
  // Set false so it will do update by default.
  is_install_ = false;

  target_version_prefix_ = params.target_version_prefix;

  lts_tag_ = params.lts_tag;

  autoupdate_token_ = params.quick_fix_build_token;

  rollback_allowed_ = params.rollback_allowed;

  // Set whether saving data over rollback is requested.
  rollback_data_save_requested_ = params.rollback_data_save_requested;

  // Set how many milestones of rollback are allowed.
  rollback_allowed_milestones_ = params.rollback_allowed_milestones;

  // Set the target channel, if one was provided.
  if (params.target_channel.empty()) {
    LOG(INFO) << "No target channel mandated by policy.";
  } else {
    LOG(INFO) << "Setting target channel as mandated: "
              << params.target_channel;
    string error_message;
    if (!SetTargetChannel(params.target_channel,
                          params.rollback_on_channel_downgrade,
                          &error_message)) {
      LOG(ERROR) << "Setting the channel failed: " << error_message;
    }

    // Since this is the beginning of a new attempt, update the download
    // channel. The download channel won't be updated until the next attempt,
    // even if target channel changes meanwhile, so that how we'll know if we
    // should cancel the current download attempt if there's such a change in
    // target channel.
    UpdateDownloadChannel();
  }

  return true;
}

bool OmahaRequestParams::IsUpdateUrlOfficial() const {
  return (update_url_ == constants::kOmahaDefaultAUTestURL ||
          update_url_ == image_props_.omaha_url);
}

bool OmahaRequestParams::SetTargetChannel(const string& new_target_channel,
                                          bool is_powerwash_allowed,
                                          string* error_message) {
  LOG(INFO) << "SetTargetChannel called with " << new_target_channel
            << ", Is Powerwash Allowed = "
            << utils::ToString(is_powerwash_allowed)
            << ". Current channel = " << image_props_.current_channel
            << ", existing target channel = "
            << mutable_image_props_.target_channel
            << ", download channel = " << download_channel_;
  if (!IsValidChannel(new_target_channel, error_message)) {
    return false;
  }

  MutableImageProperties new_props;
  new_props.target_channel = new_target_channel;
  new_props.is_powerwash_allowed = is_powerwash_allowed;

  if (!StoreMutableImageProperties(new_props)) {
    if (error_message)
      *error_message = "Error storing the new channel value.";
    return false;
  }
  mutable_image_props_ = new_props;
  return true;
}

void OmahaRequestParams::UpdateDownloadChannel() {
  if (download_channel_ != mutable_image_props_.target_channel) {
    download_channel_ = mutable_image_props_.target_channel;
    LOG(INFO) << "Download channel for this attempt = " << download_channel_;
  }
}

string OmahaRequestParams::GetMachineType() const {
  struct utsname buf;
  string ret;
  if (uname(&buf) == 0)
    ret = buf.machine;
  return ret;
}

bool OmahaRequestParams::IsValidChannel(const string& channel,
                                        string* error_message) const {
  if (image_props_.allow_arbitrary_channels) {
    if (!base::EndsWith(channel, "-channel", base::CompareCase::SENSITIVE)) {
      if (error_message) {
        *error_message = base::StringPrintf(
            "Invalid channel name \"%s\", must ends with -channel.",
            channel.c_str());
      }
      return false;
    }
    return true;
  }
  if (GetChannelIndex(channel) < 0) {
    string valid_channels = brillo::string_utils::JoinRange(
        ", ", std::begin(kChannelsByStability), std::end(kChannelsByStability));
    if (error_message) {
      *error_message =
          base::StringPrintf("Invalid channel name \"%s\", valid names are: %s",
                             channel.c_str(),
                             valid_channels.c_str());
    }
    return false;
  }
  return true;
}

void OmahaRequestParams::set_root(const string& root) {
  root_ = root;
  test::SetImagePropertiesRootPrefix(root_.c_str());
}

int OmahaRequestParams::GetChannelIndex(const string& channel) const {
  for (size_t t = 0; t < base::size(kChannelsByStability); ++t)
    if (channel == kChannelsByStability[t])
      return t;

  return -1;
}

bool OmahaRequestParams::ToMoreStableChannel() const {
  int current_channel_index = GetChannelIndex(image_props_.current_channel);
  int download_channel_index = GetChannelIndex(download_channel_);

  return download_channel_index > current_channel_index;
}

bool OmahaRequestParams::ShouldPowerwash() const {
  if (!mutable_image_props_.is_powerwash_allowed)
    return false;
  // If arbitrary channels are allowed, always powerwash on channel change.
  if (image_props_.allow_arbitrary_channels)
    return image_props_.current_channel != download_channel_;
  // Otherwise only powerwash if we are moving from less stable (higher version)
  // to more stable channel (lower version).
  return ToMoreStableChannel();
}

string OmahaRequestParams::GetAppId() const {
  return download_channel_ == "canary-channel" ? image_props_.canary_product_id
                                               : image_props_.product_id;
}

string OmahaRequestParams::GetDlcAppId(const std::string& dlc_id) const {
  // Create APP ID according to |dlc_id| (sticking the current AppID to the
  // DLC module ID with an underscode).
  return GetAppId() + "_" + dlc_id;
}

bool OmahaRequestParams::IsDlcAppId(const std::string& app_id) const {
  return dlc_apps_params().find(app_id) != dlc_apps_params().end();
}

bool OmahaRequestParams::GetDlcId(const string& app_id, string* dlc_id) const {
  auto itr = dlc_apps_params_.find(app_id);
  if (itr == dlc_apps_params_.end())
    return false;
  *dlc_id = itr->second.name;
  return true;
}

void OmahaRequestParams::SetDlcNoUpdate(const string& app_id) {
  auto itr = dlc_apps_params_.find(app_id);
  if (itr == dlc_apps_params_.end())
    return;
  itr->second.updated = false;
}

}  // namespace chromeos_update_engine
