# Copyright 2020 - The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""cvd_runtime_config class."""

import json
import os
import re

from acloud import errors

_CFG_KEY_CROSVM_BINARY = "crosvm_binary"
_CFG_KEY_X_RES = "x_res"
_CFG_KEY_Y_RES = "y_res"
_CFG_KEY_DPI = "dpi"
_CFG_KEY_VIRTUAL_DISK_PATHS = "virtual_disk_paths"
_CFG_KEY_INSTANCES = "instances"
_CFG_KEY_ADB_IP_PORT = "adb_ip_and_port"
_CFG_KEY_INSTANCE_DIR = "instance_dir"
_CFG_KEY_VNC_PORT = "vnc_server_port"
_CFG_KEY_ADB_PORT = "host_port"
_CFG_KEY_ENABLE_WEBRTC = "enable_webrtc"
# TODO(148648620): Check instance_home_[id] for backward compatible.
_RE_LOCAL_INSTANCE_ID = re.compile(r".+(?:local-instance-|instance_home_)"
                                   r"(?P<ins_id>\d+).+")


def _GetIdFromInstanceDirStr(instance_dir):
    """Look for instance id from the path of instance dir.

    Args:
        instance_dir: String, path of instance_dir.

    Returns:
        String of instance id.
    """
    match = _RE_LOCAL_INSTANCE_ID.match(instance_dir)
    if match:
        return match.group("ins_id")

    # To support the device which is not created by acloud.
    if os.path.expanduser("~") in instance_dir:
        return "1"

    return None


class CvdRuntimeConfig(object):
    """The class that hold the information from cuttlefish_config.json.

    The example of cuttlefish_config.json
    {
    "memory_mb" : 4096,
    "cpus" : 2,
    "dpi" : 320,
    "virtual_disk_paths" :
        [
            "/path-to-image"
        ],
    "adb_ip_and_port" : "0.0.0.0:6520",
    "instance_dir" : "/path-to-instance-dir",
    }

    If we launched multiple local instances, the config will be as below:
    {
    "memory_mb" : 4096,
    "cpus" : 2,
    "dpi" : 320,
    "instances" :
        {
            "1" :
            {
                "adb_ip_and_port" : "0.0.0.0:6520",
                "instance_dir" : "/path-to-instance-dir",
                "virtual_disk_paths" :
                [
                    "/path-to-image"
                ],
            }
        }
    }

    If the avd enable the webrtc, the config will be as below:
    {
    "enable_webrtc" : true,
    "vnc_server_binary" : "/home/vsoc-01/bin/vnc_server",
    "webrtc_assets_dir" : "/home/vsoc-01/usr/share/webrtc/assets",
    "webrtc_binary" : "/home/vsoc-01/bin/webRTC",
    "webrtc_certs_dir" : "/home/vsoc-01/usr/share/webrtc/certs",
    "webrtc_enable_adb_websocket" : false,
    "webrtc_public_ip" : "0.0.0.0",
    }

    """

    def __init__(self, config_path=None, raw_data=None):
        self._config_path = config_path
        self._instance_id = "1" if raw_data else _GetIdFromInstanceDirStr(
            config_path)
        self._config_dict = self._GetCuttlefishRuntimeConfig(config_path,
                                                             raw_data)
        self._x_res = self._config_dict.get(_CFG_KEY_X_RES)
        self._y_res = self._config_dict.get(_CFG_KEY_Y_RES)
        self._dpi = self._config_dict.get(_CFG_KEY_DPI)
        crosvm_bin = self._config_dict.get(_CFG_KEY_CROSVM_BINARY)
        self._cvd_tools_path = (os.path.dirname(crosvm_bin)
                                if crosvm_bin else None)

        # Below properties will be collected inside of instance id node if there
        # are more than one instance.
        self._instance_dir = self._config_dict.get(_CFG_KEY_INSTANCE_DIR)
        self._vnc_port = self._config_dict.get(_CFG_KEY_VNC_PORT)
        self._adb_port = self._config_dict.get(_CFG_KEY_ADB_PORT)
        self._adb_ip_port = self._config_dict.get(_CFG_KEY_ADB_IP_PORT)
        self._virtual_disk_paths = self._config_dict.get(
            _CFG_KEY_VIRTUAL_DISK_PATHS)
        self._enable_webrtc = self._config_dict.get(_CFG_KEY_ENABLE_WEBRTC)
        if not self._instance_dir:
            ins_cfg = self._config_dict.get(_CFG_KEY_INSTANCES)
            ins_dict = ins_cfg.get(self._instance_id)
            if not ins_dict:
                raise errors.ConfigError("instances[%s] property does not exist"
                                         " in: %s" %
                                         (self._instance_id, config_path))
            self._instance_dir = ins_dict.get(_CFG_KEY_INSTANCE_DIR)
            self._vnc_port = ins_dict.get(_CFG_KEY_VNC_PORT)
            self._adb_port = ins_dict.get(_CFG_KEY_ADB_PORT)
            self._adb_ip_port = ins_dict.get(_CFG_KEY_ADB_IP_PORT)
            self._virtual_disk_paths = ins_dict.get(_CFG_KEY_VIRTUAL_DISK_PATHS)

    @staticmethod
    def _GetCuttlefishRuntimeConfig(runtime_cf_config_path, raw_data=None):
        """Get and parse cuttlefish_config.json.

        Args:
            runtime_cf_config_path: String, path of the cvd runtime config.
            raw_data: String, data of the cvd runtime config.

        Returns:
            A dictionary that parsed from cuttlefish runtime config.

        Raises:
            errors.ConfigError: if file not found or config load failed.
        """
        if raw_data:
            # if remote instance couldn't fetch the config will return message such as
            # 'cat: .../cuttlefish_config.json: No such file or directory'.
            # Add this condition to prevent from JSONDecodeError.
            try:
                return json.loads(raw_data)
            except ValueError as e:
                raise errors.ConfigError(
                    "An exception happened when loading the raw_data of the "
                    "cvd runtime config:\n%s" % str(e))
        if not os.path.exists(runtime_cf_config_path):
            raise errors.ConfigError(
                "file does not exist: %s" % runtime_cf_config_path)
        with open(runtime_cf_config_path, "r") as cf_config:
            return json.load(cf_config)

    @property
    def cvd_tools_path(self):
        """Return string of the path to the cvd tools."""
        return self._cvd_tools_path

    @property
    def x_res(self):
        """Return x_res."""
        return self._x_res

    @property
    def y_res(self):
        """Return y_res."""
        return self._y_res

    @property
    def dpi(self):
        """Return dpi."""
        return self._dpi

    @property
    def adb_ip_port(self):
        """Return adb_ip_port."""
        return self._adb_ip_port

    @property
    def instance_dir(self):
        """Return instance_dir."""
        return self._instance_dir

    @property
    def vnc_port(self):
        """Return vnc_port."""
        return self._vnc_port

    @property
    def adb_port(self):
        """Return adb_port."""
        return self._adb_port

    @property
    def config_path(self):
        """Return config_path."""
        return self._config_path

    @property
    def virtual_disk_paths(self):
        """Return virtual_disk_paths"""
        return self._virtual_disk_paths

    @property
    def instance_id(self):
        """Return _instance_id"""
        return self._instance_id

    @property
    def enable_webrtc(self):
        """Return _enable_webrtc"""
        return self._enable_webrtc
