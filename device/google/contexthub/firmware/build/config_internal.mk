#
# Copyright (C) 2016 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_C_INCLUDES +=                                     \
    $(NANOHUB_OS_PATH)/os/inc                           \
    $(NANOHUB_OS_PATH)/os/platform/$(AUX_ARCH)/inc      \
    $(NANOHUB_OS_PATH)/os/cpu/$(AUX_CPU)/inc            \
    $(NANOHUB_OS_PATH)/../lib/include                   \
    system/chre/chre_api/include/chre_api               \

LOCAL_WHOLE_STATIC_LIBRARIES_BL += libnanohub_bl_$(AUX_CPU)
LOCAL_WHOLE_STATIC_LIBRARIES_BL += libnanohub_bl_$(AUX_ARCH)

LOCAL_WHOLE_STATIC_LIBRARIES_OS += libnanohub_os_$(AUX_CPU)
LOCAL_WHOLE_STATIC_LIBRARIES_OS += libnanohub_os_$(AUX_ARCH)
