# Copyright 2014 The Android Open Source Project
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
"""Utility functions to determine what functionality the camera supports."""


import logging
import unittest
from mobly import asserts
import numpy as np
import capture_request_utils

LENS_FACING_FRONT = 0
LENS_FACING_BACK = 1
LENS_FACING_EXTERNAL = 2
MULTI_CAMERA_SYNC_CALIBRATED = 1
NUM_DISTORTION_PARAMS = 5  # number of terms in lens.distortion
NUM_INTRINSIC_CAL_PARAMS = 5  # number of terms in intrinsic calibration
NUM_POSE_ROTATION_PARAMS = 4  # number of terms in poseRotation
NUM_POSE_TRANSLATION_PARAMS = 3  # number of terms in poseTranslation
SKIP_RET_MSG = 'Test skipped'
SOLID_COLOR_TEST_PATTERN = 1
COLOR_BARS_TEST_PATTERN = 2


def legacy(props):
  """Returns whether a device is a LEGACY capability camera2 device.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device is a LEGACY camera.
  """
  return props.get('android.info.supportedHardwareLevel') == 2


def limited(props):
  """Returns whether a device is a LIMITED capability camera2 device.

  Args:
    props: Camera properties object.

  Returns:
     Boolean. True if device is a LIMITED camera.
  """
  return props.get('android.info.supportedHardwareLevel') == 0


def full_or_better(props):
  """Returns whether a device is a FULL or better camera2 device.

  Args:
    props: Camera properties object.

  Returns:
     Boolean. True if device is FULL or LEVEL3 camera.
  """
  return (props.get('android.info.supportedHardwareLevel') >= 1 and
          props.get('android.info.supportedHardwareLevel') != 2)


def level3(props):
  """Returns whether a device is a LEVEL3 capability camera2 device.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device is LEVEL3 camera.
  """
  return props.get('android.info.supportedHardwareLevel') == 3


def manual_sensor(props):
  """Returns whether a device supports MANUAL_SENSOR capabilities.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if devices supports MANUAL_SENSOR capabilities.
  """
  return 1 in props.get('android.request.availableCapabilities', [])


def manual_post_proc(props):
  """Returns whether a device supports MANUAL_POST_PROCESSING capabilities.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports MANUAL_POST_PROCESSING capabilities.
  """
  return 2 in props.get('android.request.availableCapabilities', [])


def raw(props):
  """Returns whether a device supports RAW capabilities.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports RAW capabilities.
  """
  return 3 in props.get('android.request.availableCapabilities', [])


def sensor_fusion(props):
  """Checks the camera and motion sensor timestamps.

  Returns whether the camera and motion sensor timestamps for the device
  are in the same time domain and can be compared directly.

  Args:
    props: Camera properties object.

  Returns:
     Boolean. True if camera and motion sensor timestamps in same time domain.
  """
  return props.get('android.sensor.info.timestampSource') == 1


def logical_multi_camera(props):
  """Returns whether a device is a logical multi-camera.

  Args:
    props: Camera properties object.

  Returns:
     Boolean. True if the device is a logical multi-camera.
  """
  return 11 in props.get('android.request.availableCapabilities', [])


def logical_multi_camera_physical_ids(props):
  """Returns a logical multi-camera's underlying physical cameras.

  Args:
    props: Camera properties object.

  Returns:
    list of physical cameras backing the logical multi-camera.
  """
  physical_ids_list = []
  if logical_multi_camera(props):
    physical_ids_list = props['camera.characteristics.physicalCamIds']
  return physical_ids_list


def skip_unless(cond):
  """Skips the test if the condition is false.

  If a test is skipped, then it is exited and returns the special code
  of 101 to the calling shell, which can be used by an external test
  harness to differentiate a skip from a pass or fail.

  Args:
    cond: Boolean, which must be true for the test to not skip.

  Returns:
     Nothing.
  """
  if not cond:
    asserts.skip(SKIP_RET_MSG)


def backward_compatible(props):
  """Returns whether a device supports BACKWARD_COMPATIBLE.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if the devices supports BACKWARD_COMPATIBLE.
  """
  return 0 in props.get('android.request.availableCapabilities', [])


def lens_calibrated(props):
  """Returns whether lens position is calibrated or not.

  android.lens.info.focusDistanceCalibration has 3 modes.
  0: Uncalibrated
  1: Approximate
  2: Calibrated

  Args:
    props: Camera properties objects.

  Returns:
    Boolean. True if lens is CALIBRATED.
  """
  return 'android.lens.info.focusDistanceCalibration' in props and props[
      'android.lens.info.focusDistanceCalibration'] == 2


def lens_approx_calibrated(props):
  """Returns whether lens position is calibrated or not.

  android.lens.info.focusDistanceCalibration has 3 modes.
  0: Uncalibrated
  1: Approximate
  2: Calibrated

  Args:
   props: Camera properties objects.

  Returns:
    Boolean. True if lens is APPROXIMATE or CALIBRATED.
  """
  return props.get('android.lens.info.focusDistanceCalibration') in [1, 2]


def raw10(props):
  """Returns whether a device supports RAW10 capabilities.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports RAW10 capabilities.
  """
  if capture_request_utils.get_available_output_sizes('raw10', props):
    return True
  return False


def raw12(props):
  """Returns whether a device supports RAW12 capabilities.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports RAW12 capabilities.
  """
  if capture_request_utils.get_available_output_sizes('raw12', props):
    return True
  return False


def raw16(props):
  """Returns whether a device supports RAW16 output.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports RAW16 capabilities.
  """
  if capture_request_utils.get_available_output_sizes('raw', props):
    return True
  return False


def raw_output(props):
  """Returns whether a device supports any of the RAW output formats.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports any of the RAW output formats
  """
  return raw16(props) or raw10(props) or raw12(props)


def per_frame_control(props):
  """Returns whether a device supports per frame control.

  Args:
    props: Camera properties object.

  Returns: Boolean. True if devices supports per frame control.
  """
  return 'android.sync.maxLatency' in props and props[
      'android.sync.maxLatency'] == 0


def mono_camera(props):
  """Returns whether a device is monochromatic.

  Args:
    props: Camera properties object.
  Returns: Boolean. True if MONO camera.
  """
  return 12 in props.get('android.request.availableCapabilities', [])


def fixed_focus(props):
  """Returns whether a device is fixed focus.

  props[android.lens.info.minimumFocusDistance] == 0 is fixed focus

  Args:
    props: Camera properties objects.

  Returns:
    Boolean. True if device is a fixed focus camera.
  """
  return 'android.lens.info.minimumFocusDistance' in props and props[
      'android.lens.info.minimumFocusDistance'] == 0


def face_detect(props):
  """Returns whether a device has face detection mode.

  props['android.statistics.info.availableFaceDetectModes'] != 0

  Args:
    props: Camera properties objects.

  Returns:
    Boolean. True if device supports face detection.
  """
  return 'android.statistics.info.availableFaceDetectModes' in props and props[
      'android.statistics.info.availableFaceDetectModes'] != [0]


def read_3a(props):
  """Return whether a device supports reading out the below 3A settings.

  sensitivity
  exposure time
  awb gain
  awb cct
  focus distance

  Args:
    props: Camera properties object.

  Returns:
     Boolean. True if device supports reading out 3A settings.
  """
  return manual_sensor(props) and manual_post_proc(props)


def compute_target_exposure(props):
  """Return whether a device supports target exposure computation.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports target exposure computation.
  """
  return manual_sensor(props) and manual_post_proc(props)


def y8(props):
  """Returns whether a device supports Y8 output.

  Args:
    props: Camera properties object.

  Returns:
     Boolean. True if device suupports Y8 output.
  """
  if capture_request_utils.get_available_output_sizes('y8', props):
    return True
  return False


def jpeg_quality(props):
  """Returns whether a device supports JPEG quality."""
  return ('camera.characteristics.requestKeys' in props) and (
      'android.jpeg.quality' in props['camera.characteristics.requestKeys'])


def zoom_ratio_range(props):
  """Returns whether a device supports zoom capabilities.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports zoom capabilities.
  """
  return 'android.control.zoomRatioRange' in props and props[
      'android.control.zoomRatioRange'] is not None


def sync_latency(props):
  """Returns sync latency in number of frames.

  If undefined, 8 frames.

  Args:
    props: Camera properties object.

  Returns:
    integer number of frames.
  """
  latency = props['android.sync.maxLatency']
  if latency < 0:
    latency = 8
  return latency


def get_max_digital_zoom(props):
  """Returns the maximum amount of zooming possible by the camera device.

  Args:
    props: Camera properties object.

  Returns:
    A float indicating the maximum amount of zooming possible by the
    camera device.
  """
  z_max = 1.0
  if 'android.scaler.availableMaxDigitalZoom' in props:
    z_max = props['android.scaler.availableMaxDigitalZoom']
  return z_max


def ae_lock(props):
  """Returns whether a device supports AE lock.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports AE lock.
  """
  return 'android.control.aeLockAvailable' in props and props[
      'android.control.aeLockAvailable'] == 1


def awb_lock(props):
  """Returns whether a device supports AWB lock.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports AWB lock.
  """
  return 'android.control.awbLockAvailable' in props and props[
      'android.control.awbLockAvailable'] == 1


def ev_compensation(props):
  """Returns whether a device supports ev compensation.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports EV compensation.
  """
  return 'android.control.aeCompensationRange' in props and props[
      'android.control.aeCompensationRange'] != [0, 0]


def flash(props):
  """Returns whether a device supports flash control.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports flash control.
  """
  return 'android.flash.info.available' in props and props[
      'android.flash.info.available'] == 1


def distortion_correction(props):
  """Returns whether a device supports android.lens.distortion capabilities.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports lens distortion correction capabilities.
  """
  return 'android.lens.distortion' in props and props[
      'android.lens.distortion'] is not None


def freeform_crop(props):
  """Returns whether a device supports freefrom cropping.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports freeform cropping.
  """
  return 'android.scaler.croppingType' in props and props[
      'android.scaler.croppingType'] == 1


def noise_reduction_mode(props, mode):
  """Returns whether a device supports the noise reduction mode.

  Args:
    props: Camera properties objects.
    mode: Integer indicating noise reduction mode to check for availability.

  Returns:
    Boolean. Ture if devices supports noise reduction mode(s).
  """
  return ('android.noiseReduction.availableNoiseReductionModes' in props and
          mode in props['android.noiseReduction.availableNoiseReductionModes'])


def lsc_map(props):
  """Returns whether a device supports lens shading map output.

  Args:
    props: Camera properties object.
  Returns: Boolean. True if device supports lens shading map output.
  """
  return 1 in props.get('android.statistics.info.availableLensShadingMapModes',
                        [])


def lsc_off(props):
  """Returns whether a device supports disabling lens shading correction.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports disabling lens shading correction.
  """
  return 0 in props.get('android.shading.availableModes', [])


def edge_mode(props, mode):
  """Returns whether a device supports the edge mode.

  Args:
    props: Camera properties objects.
    mode: Integer, indicating the edge mode to check for availability.

  Returns:
    Boolean. True if device supports edge mode(s).
  """
  return 'android.edge.availableEdgeModes' in props and mode in props[
      'android.edge.availableEdgeModes']


def yuv_reprocess(props):
  """Returns whether a device supports YUV reprocessing.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports YUV reprocessing.
  """
  return 'android.request.availableCapabilities' in props and 7 in props[
      'android.request.availableCapabilities']


def private_reprocess(props):
  """Returns whether a device supports PRIVATE reprocessing.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports PRIVATE reprocessing.
  """
  return 'android.request.availableCapabilities' in props and 4 in props[
      'android.request.availableCapabilities']


def intrinsic_calibration(props):
  """Returns whether a device supports android.lens.intrinsicCalibration.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if device supports android.lens.intrinsicCalibratino.
  """
  return props.get('android.lens.intrinsicCalibration') is not None


def get_intrinsic_calibration(props, debug, fd=None):
  """Get intrinsicCalibration and create intrisic matrix.

  If intrinsic android.lens.intrinsicCalibration does not exist, return None.

  Args:
    props: camera properties
    debug: bool to print more information
    fd: focal length from capture metadata

  Returns:
    intrinsic transformation matrix
    k = [[f_x, s, c_x],
         [0, f_y, c_y],
         [0,   0,   1]]
  """
  if props.get('android.lens.intrinsicCalibration'):
    ical = np.array(props['android.lens.intrinsicCalibration'])
  else:
    logging.error('Device does not have android.lens.intrinsicCalibration.')
    return None

  # basic checks for parameter correctness
  ical_len = len(ical)
  if ical_len != NUM_INTRINSIC_CAL_PARAMS:
    raise ValueError(
        f'instrisicCalibration has wrong number of params: {ical_len}.')

  if fd is not None:
    # detailed checks for parameter correctness
    # Intrinsic cal is of format: [f_x, f_y, c_x, c_y, s]
    # [f_x, f_y] is the horizontal and vertical focal lengths,
    # [c_x, c_y] is the position of the optical axis,
    # and s is skew of sensor plane vs lens plane.
    sensor_h = props['android.sensor.info.physicalSize']['height']
    sensor_w = props['android.sensor.info.physicalSize']['width']
    pixel_h = props['android.sensor.info.pixelArraySize']['height']
    pixel_w = props['android.sensor.info.pixelArraySize']['width']
    fd_w_pix = pixel_w * fd / sensor_w
    fd_h_pix = pixel_h * fd / sensor_h

    if not np.isclose(fd_w_pix, ical[0], rtol=0.20):
      raise ValueError('fd_w(pixels): %.2f\tcal[0](pixels): %.2f\tTOL=20%%' % (
          fd_w_pix, ical[0]))
    if not np.isclose(fd_h_pix, ical[1], rtol=0.20):
      raise ValueError('fd_h(pixels): %.2f\tcal[1](pixels): %.2f\tTOL=20%%' % (
          fd_h_pix, ical[0]))

  # generate instrinsic matrix
  k = np.array([[ical[0], ical[4], ical[2]],
                [0, ical[1], ical[3]],
                [0, 0, 1]])
  if debug:
    logging.debug('k: %s', str(k))
  return k


def get_translation_matrix(props, debug):
  """Get translation matrix.

  Args:
    props: dict of camera properties
    debug: boolean flag to log more info

  Returns:
    android.lens.poseTranslation matrix if it exists, otherwise None.
  """
  if props['android.lens.poseTranslation']:
    t = np.array(props['android.lens.poseTranslation'])
  else:
    logging.error('Device does not have android.lens.poseTranslation.')
    return None

  if debug:
    logging.debug('translation: %s', str(t))
  t_len = len(t)
  if t_len != NUM_POSE_TRANSLATION_PARAMS:
    raise ValueError(f'poseTranslation has wrong # of params: {t_len}.')
  return t


def get_rotation_matrix(props, debug):
  """Convert the rotation parameters to 3-axis data.

  Args:
    props: camera properties
    debug: boolean for more information

  Returns:
    3x3 matrix w/ rotation parameters if poseRotation exists, otherwise None
  """
  if props['android.lens.poseRotation']:
    rotation = np.array(props['android.lens.poseRotation'])
  else:
    logging.error('Device does not have android.lens.poseRotation.')
    return None

  if debug:
    logging.debug('rotation: %s', str(rotation))
    rotation_len = len(rotation)
    if rotation_len != NUM_POSE_ROTATION_PARAMS:
      raise ValueError(f'poseRotation has wrong # of params: {rotation_len}.')
  x = rotation[0]
  y = rotation[1]
  z = rotation[2]
  w = rotation[3]
  return np.array([[1-2*y**2-2*z**2, 2*x*y-2*z*w, 2*x*z+2*y*w],
                   [2*x*y+2*z*w, 1-2*x**2-2*z**2, 2*y*z-2*x*w],
                   [2*x*z-2*y*w, 2*y*z+2*x*w, 1-2*x**2-2*y**2]])


def get_distortion_matrix(props):
  """Get android.lens.distortion matrix and convert to cv2 fmt.

  Args:
    props: dict of camera properties

  Returns:
    cv2 reordered android.lens.distortion if it exists, otherwise None.
  """
  if props['android.lens.distortion']:
    dist = np.array(props['android.lens.distortion'])
  else:
    logging.error('Device does not have android.lens.distortion.')
    return None

  dist_len = len(dist)
  if len(dist) != NUM_DISTORTION_PARAMS:
    raise ValueError(f'lens.distortion has wrong # of params: {dist_len}.')
  cv2_distort = np.array([dist[0], dist[1], dist[3], dist[4], dist[2]])
  logging.debug('cv2 distortion params: %s', str(cv2_distort))
  return cv2_distort


def post_raw_sensitivity_boost(props):
  """Returns whether a device supports post RAW sensitivity boost.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if android.control.postRawSensitivityBoost is supported.
  """
  return (
      'android.control.postRawSensitivityBoostRange' in props['camera.characteristics.keys'] and
      props.get('android.control.postRawSensitivityBoostRange') != [100, 100])


def sensor_fusion_capable(props):
  """Determine if test_sensor_fusion is run."""
  return all([sensor_fusion(props),
              manual_sensor(props),
              props['android.lens.facing'] != LENS_FACING_EXTERNAL])


def continuous_picture(props):
  """Returns whether a device supports CONTINUOUS_PICTURE.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if CONTINUOUS_PICTURE in android.control.afAvailableModes.
  """
  return 4 in props.get('android.control.afAvailableModes', [])


def af_scene_change(props):
  """Returns whether a device supports AF_SCENE_CHANGE.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if android.control.afSceneChange supported.
  """
  return 'android.control.afSceneChange' in props.get(
      'camera.characteristics.resultKeys')


def multi_camera_frame_sync_capable(props):
  """Determines if test_multi_camera_frame_sync can be run."""
  return all([
      read_3a(props),
      per_frame_control(props),
      logical_multi_camera(props),
      sensor_fusion(props),
  ])


def multi_camera_sync_calibrated(props):
  """Determines if multi-camera sync type is CALIBRATED or APPROXIMATE.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if android.logicalMultiCamera.sensorSyncType is CALIBRATED.
  """
  return props.get('android.logicalMultiCamera.sensorSyncType'
                  ) == MULTI_CAMERA_SYNC_CALIBRATED


def solid_color_test_pattern(props):
  """Determines if camera supports solid color test pattern.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if android.sensor.availableTestPatternModes has
             SOLID_COLOR_TEST_PATTERN.
  """
  return SOLID_COLOR_TEST_PATTERN in props.get(
      'android.sensor.availableTestPatternModes')


def color_bars_test_pattern(props):
  """Determines if camera supports color bars test pattern.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if android.sensor.availableTestPatternModes has
             COLOR_BARS_TEST_PATTERN.
  """
  return COLOR_BARS_TEST_PATTERN in props.get(
      'android.sensor.availableTestPatternModes')


def linear_tonemap(props):
  """Determines if camera supports CONTRAST_CURVE or GAMMA_VALUE in tonemap.

  Args:
    props: Camera properties object.

  Returns:
    Boolean. True if android.tonemap.availableToneMapModes has
             CONTRAST_CURVE (0) or GAMMA_VALUE (3).
  """
  return ('android.tonemap.availableToneMapModes' in props and
         (0 in props.get('android.tonemap.availableToneMapModes') or
          3 in props.get('android.tonemap.availableToneMapModes')))


if __name__ == '__main__':
  unittest.main()

