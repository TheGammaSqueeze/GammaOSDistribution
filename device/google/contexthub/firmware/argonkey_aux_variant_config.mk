#
# Copyright (C) 2017 STMicroelectronics
# Copyright (C) 2017 The Android Open Source Project
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

# only locally defined variables can be used at this time

my_variant := argonkey

AUX_OS_$(my_variant)             := nanohub
AUX_ARCH_$(my_variant)           := stm32
AUX_SUBARCH_$(my_variant)        := stm32f412
AUX_CPU_$(my_variant)            := cortexm4

# variant supports building OS bootloader, main OS image and application as targets
# target should one of the following:
#   "" (empty) -- applies to all targets
#  _BL -- applies to OS bootloader target build only
#  _OS -- applies to OS image target build only
# _APP -- applies to application target build only
#
# the following variables may be defined in variant script for any target:
# NANO_VARIANT<target>_CFLAGS_<variant>
# NANO_VARIANT<target>_C_INCLUDES_<variant>
# NANO_VARIANT<target>_STATIC_LIBRARIRES_<variant>
# NANO_VARIANT<target>_WHOLE_STATIC_LIBRARIRES_<variant>
#
# the following may be defined for _OS and _BL only, to control
# what additional source files need to be included in the build;
# the file paths in this list are relative to the target (_OS or _BL) LOCAL_PATH;
# NANO_VARIANT<target>_SRC_FILES_<variant>

NANO_VARIANT_OSCFG_STATIC_LIBRARIES_$(my_variant) := libnanohub_os_$(my_variant)

NANO_VARIANT_OS_CFLAGS_$(my_variant) := \
    -DDEBUG_SWD                         \

#'Ar' -> argonkey
NANO_VARIANT_CFLAGS_$(my_variant) := -DPLATFORM_HW_TYPE=0x4172

NANO_VARIANT_C_INCLUDES_$(my_variant) := \
    device/google/contexthub/firmware/variant/$(my_variant)/inc \

# this is relative to NANOHUB_OS_PATH
NANO_VARIANT_OSCFG_SRC_FILES_$(my_variant) :=                  \
    os/algos/calibration/accelerometer/accel_cal.c             \
    os/algos/calibration/gyroscope/gyro_cal.c                  \
    os/algos/calibration/gyroscope/gyro_stillness_detect.c     \
    os/algos/calibration/magnetometer/mag_cal/mag_cal.c        \
    os/algos/calibration/diversity_checker/diversity_checker.c \
    os/algos/calibration/over_temp/over_temp_cal.c             \
    os/algos/common/math/kasa.c                                \
    os/algos/common/math/mat.c                                 \
    os/algos/common/math/quat.c                                \
    os/algos/common/math/vec.c                                 \
    os/algos/fusion.c                                          \
    os/algos/time_sync.c                                       \
    os/drivers/hall/hall.c                                     \
    os/drivers/intersil_isl29034/isl29034.c                    \
    os/drivers/leds/leds_gpio.c                                \
    os/drivers/leds/leds_lp3943.c                              \
    os/drivers/orientation/orientation.c                       \
    os/drivers/st_hts221/hts221.c                              \
    os/drivers/st_lps22hb/lps22hb.c                            \
    os/drivers/st_lsm6dsm/st_lsm6dsm.c                         \
    os/drivers/tilt_detection/tilt_detection.c                 \
    os/drivers/window_orientation/window_orientation.c         \
