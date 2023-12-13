#!/bin/bash
#
# Run tests in this directory.
#

if [ "$SYNC_FINISHED" != true ]; then
  if [ -z "$ANDROID_BUILD_TOP" ]; then
      echo "Android build environment not set"
      exit -1
  fi

  # ensure we have mm
  . $ANDROID_BUILD_TOP/build/envsetup.sh

  mm

  echo "waiting for device"

  adb root && adb wait-for-device remount && adb sync
fi

echo "========================================"

echo "testing TranscodingClientManager"
#adb shell /data/nativetest64/TranscodingClientManager_tests/TranscodingClientManager_tests
adb shell /data/nativetest/TranscodingClientManager_tests/TranscodingClientManager_tests

echo "testing AdjustableMaxPriorityQueue"
#adb shell /data/nativetest64/AdjustableMaxPriorityQueue_tests/AdjustableMaxPriorityQueue_tests
adb shell /data/nativetest/AdjustableMaxPriorityQueue_tests/AdjustableMaxPriorityQueue_tests

echo "testing TranscodingSessionController"
#adb shell /data/nativetest64/TranscodingSessionController_tests/TranscodingSessionController_tests
adb shell /data/nativetest/TranscodingSessionController_tests/TranscodingSessionController_tests

echo "testing TranscodingLogger"
#adb shell /data/nativetest64/TranscodingLogger_tests/TranscodingLogger_tests
adb shell /data/nativetest/TranscodingLogger_tests/TranscodingLogger_tests
