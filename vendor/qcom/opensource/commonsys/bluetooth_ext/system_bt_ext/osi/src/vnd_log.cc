/******************************************************************************
Copyright (c) 2016, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#define LOG_TAG "bt_vnd_log"

#include <errno.h>
#include <string.h>
#include <array>
#include <iostream>
#include <dlfcn.h>
#include <sys/socket.h>
#include <cutils/sockets.h>
#include "osi/include/log.h"
#include "osi/include/osi.h"
#include "osi/include/properties.h"

#define IS_DEBUGGABLE_PROPERTY "ro.debuggable"
#define BTSNOOP_LOG_MODE_PROPERTY "persist.bluetooth.btsnooplogmode"
#define BTSNOOP_DEFAULT_MODE_PROPERTY "persist.bluetooth.btsnoopdefaultmode"
#define BTSNOOP_MODE_DISABLED "disabled"
#define BTSNOOP_MODE_FILTERED "filtered"
#define BTSNOOP_MODE_FULL "full"
#define BTSNOOP_MODE_SNOOPHEADERSFILTERED "snoopheadersfiltered"
#define BTSNOOP_MODE_MEDIAPKTSFILTERED "mediapktsfiltered"
#define BTLOGGER_ENABLE_PROPERTY "persist.bluetooth.btsnoopenable"
#define LOCAL_SOCKET_NAME "bthcitraffic"

static const char *LOGGER_LIBRARY_NAME = "libbt-logClient.so";
static const char *LOGGER_LIBRARY_SYMBOL_NAME = "BLUETOOTH_LOGGER_LIB_INTERFACE";

static void *lib_handle;
bt_logger_interface_t *logger_interface = NULL;
bool bt_logger_enabled = false;
uint16_t vendor_logging_level = 0xFFFF;

void init_vnd_Logger(void)
{
  int init_ret = 0;

  if(!bt_logger_enabled)
  {
    LOG_ERROR(LOG_TAG, "%s, Logger Not enabled from config file",  __func__);
    return;
  }

  if(logger_interface)
  {
    LOG_ERROR(LOG_TAG, "%s, Vendor Logger is already initialized",  __func__);
    return;
  }

  lib_handle = dlopen(LOGGER_LIBRARY_NAME, RTLD_NOW);

  if (!lib_handle) {
    LOG_ERROR(LOG_TAG, "%s unable to open %s: %s", __func__, LOGGER_LIBRARY_NAME, dlerror());
    return;
  }

  logger_interface = (bt_logger_interface_t *)dlsym(lib_handle, LOGGER_LIBRARY_SYMBOL_NAME);
  if (!logger_interface) {
    LOG_ERROR(LOG_TAG, "%s unable to find symbol %s in %s: %s", __func__, LOGGER_LIBRARY_SYMBOL_NAME, LOGGER_LIBRARY_NAME, dlerror());
    return;
  }

  init_ret = logger_interface->init();
  if(init_ret > 0) {
    vendor_logging_level = init_ret;
  } else {
    LOG_ERROR(LOG_TAG, "%s failed to start logger process, setting snoop logging level to default", __func__);
  }
}

void clean_vnd_logger()
{
  if(!bt_logger_enabled)
    return;

  if(logger_interface)
    logger_interface->cleanup();

  logger_interface = NULL;

  if(lib_handle)
    dlclose(lib_handle);

  lib_handle = NULL;
  property_set("vendor.bluetooth.startbtlogger", "false");
}

static bool is_logging_enable()
{
  std::array<char, PROPERTY_VALUE_MAX> property = {};
  std::string default_mode = BTSNOOP_MODE_DISABLED;

  // Default mode is FILTERED on userdebug/eng build, DISABLED on user build.
  // It can also be overwritten by modifying the global setting.
  int is_debuggable = osi_property_get_int32(IS_DEBUGGABLE_PROPERTY, 0);
  if (is_debuggable) {
    int len = osi_property_get(BTSNOOP_DEFAULT_MODE_PROPERTY, property.data(),
                               BTSNOOP_MODE_FILTERED);
    default_mode = std::string(property.data(), len);
  }

  // Get the actual mode
  int len = osi_property_get(BTSNOOP_LOG_MODE_PROPERTY, property.data(),
                             default_mode.c_str());
  std::string btsnoop_mode(property.data(), len);

  if (btsnoop_mode == BTSNOOP_MODE_FULL ||
      btsnoop_mode == BTSNOOP_MODE_MEDIAPKTSFILTERED ||
      btsnoop_mode == BTSNOOP_MODE_SNOOPHEADERSFILTERED) {
    osi_property_set("persist.bluetooth.btsnoopenable", "true");
    bt_logger_enabled = true;
  } else {
    osi_property_set("persist.bluetooth.btsnoopenable", "");
    bt_logger_enabled = false;
  }
  return bt_logger_enabled;

}

void start_bt_logger()
{
  if(is_logging_enable())
    property_set("vendor.bluetooth.startbtlogger", "true");
}

int local_snoop_socket_create(void) {

  int listen_socket_local = socket(AF_LOCAL, SOCK_STREAM, 0);
  if(listen_socket_local < 0) {
    return -1;
  }

  if(socket_local_server_bind(listen_socket_local, LOCAL_SOCKET_NAME,
      ANDROID_SOCKET_NAMESPACE_ABSTRACT) < 0) {
    LOG_ERROR(LOG_TAG, "Failed to create Local Socket (%s)", strerror(errno));
    close(listen_socket_local);
    return -1;
  }

  if (listen(listen_socket_local, 1) < 0) {
    LOG_ERROR(LOG_TAG, "Local socket listen failed (%s)", strerror(errno));
    close(listen_socket_local);
    return -1;
  }
  return listen_socket_local;
}
