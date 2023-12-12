# Copyright 2018 The Android Open Source Project
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
"""Verify multiple cameras take images in same time base."""


import logging
import multiprocessing
import os
import time
import matplotlib
from matplotlib import pylab
from mobly import test_runner
import numpy

import cv2
import its_base_test
import camera_properties_utils
import capture_request_utils
import image_processing_utils
import its_session_utils
import opencv_processing_utils
import sensor_fusion_utils

_ANGLE_90_MASK = 10  # (degrees) mask around 0/90 as rotated squares look same
_ANGLE_JUMP_90 = 60  # 90 - 2*ANGLE_90_MASK - 2*5 degree slop on top/bottom
_ANGULAR_DIFF_THRESH_API30 = 10  # degrees
_ANGULAR_DIFF_THRESH_CALIBRATED = 1.8  # degrees (180 deg / 1000 ms * 10 ms)
_ANGULAR_MOVEMENT_THRESHOLD = 35  # degrees
_FRAMES_WITH_SQUARES_MIN = 20  # min number of frames with angles extracted
_NAME = os.path.basename(__file__).split('.')[0]
_NUM_CAPTURES = 100
_NUM_ROTATIONS = 10
_ROT_INIT_WAIT_TIME = 2  # seconds
_CHART_DISTANCE_SF = 25  # cm
_CM_TO_M = 1/100.0


def _determine_max_frame_to_frame_shift(angle_pairs):
  """Detemine max frame to frame shift from 10-80 data."""
  frame_to_frame_diff_max = 0
  for i in range(1, len(angle_pairs)):
    for j in [0, 1]:
      frame_to_frame_diff = abs(
          angle_pairs[i][j] - angle_pairs[i-1][j])
      if _ANGLE_JUMP_90 > frame_to_frame_diff > frame_to_frame_diff_max:
        frame_to_frame_diff_max = frame_to_frame_diff
      logging.debug('cam: %d frame_to_frame_diff: %.2f', j, frame_to_frame_diff)
  logging.debug('frame_to_frame_diff_max: %.2f', frame_to_frame_diff_max)
  return frame_to_frame_diff_max


def _determine_angular_diff_thresh(first_api_level, sync_calibrated,
                                   frame_to_frame_max):
  """Determine angular difference threshold based on first API & sync type."""
  if first_api_level < 31:  # Original constraint.
    angular_diff_thresh = _ANGULAR_DIFF_THRESH_API30
    logging.debug('first API level < 31')
  else:  # Change depending on APPROX or CALIBRATED time source.
    if sync_calibrated:  # CALIBRATED sync
      angular_diff_thresh = _ANGULAR_DIFF_THRESH_CALIBRATED
      logging.debug('CALIBRATED sync')
    else:  # APPROXIMATE sync
      angular_diff_thresh = frame_to_frame_max
      logging.debug('APPROXIMATE sync')
  logging.debug('angular diff threshold: %.2f', angular_diff_thresh)
  return angular_diff_thresh


def _remove_frames_without_enough_squares(frame_pairs_angles):
  """Remove any frames without enough squares."""
  filtered_pairs_angles = []
  for angle_1, angle_2 in frame_pairs_angles:
    if angle_1 is None or angle_2 is None:
      continue
    filtered_pairs_angles.append([angle_1, angle_2])

  num_filtered_pairs_angles = len(filtered_pairs_angles)
  logging.debug('Using %d image pairs to compute angular difference.',
                num_filtered_pairs_angles)

  if num_filtered_pairs_angles < _FRAMES_WITH_SQUARES_MIN:
    raise AssertionError('Unable to identify enough frames with detected '
                         f'squares. Found: {num_filtered_pairs_angles}, '
                         f'THRESH: {_FRAMES_WITH_SQUARES_MIN}.')

  return filtered_pairs_angles


def _mask_angles_near_extremes(frame_pairs_angles):
  """Mask out the data near the top and bottom of angle range."""
  masked_pairs_angles = [[i, j] for i, j in frame_pairs_angles
                         if _ANGLE_90_MASK <= abs(i) <= 90-_ANGLE_90_MASK and
                         _ANGLE_90_MASK <= abs(j) <= 90-_ANGLE_90_MASK]
  if masked_pairs_angles:
    return masked_pairs_angles
  else:
    raise AssertionError('Not enough phone movement! All angle pairs masked '
                         'out by 0/90 angle removal.')


def _plot_frame_pairs_angles(frame_pairs_angles, ids, log_path):
  """Plot the extracted angles."""
  matplotlib.pyplot.figure('Camera Rotation Angle')
  cam0_angles = [i for i, _ in frame_pairs_angles]
  cam1_angles = [j for _, j in frame_pairs_angles]
  pylab.plot(range(len(cam0_angles)), cam0_angles, '-r.', alpha=0.5,
             label='%s' % ids[0])
  pylab.plot(range(len(cam1_angles)), cam1_angles, '-g.', alpha=0.5,
             label='%s' % ids[1])
  pylab.legend()
  pylab.xlabel('Frame number')
  pylab.ylabel('Rotation angle (degrees)')
  matplotlib.pyplot.savefig(
      '%s_angles_plot.png' % os.path.join(log_path, _NAME))

  matplotlib.pyplot.figure('Angle Diffs')
  angle_diffs = [j-i for i, j in frame_pairs_angles]
  pylab.plot(range(len(angle_diffs)), angle_diffs, '-b.',
             label='cam%s-%s' % (ids[1], ids[0]))
  pylab.legend()
  pylab.xlabel('Frame number')
  pylab.ylabel('Rotation angle difference (degrees)')
  matplotlib.pyplot.savefig(
      '%s_angle_diffs_plot.png' % os.path.join(log_path, _NAME))


class MultiCameraFrameSyncTest(its_base_test.ItsBaseTest):
  """Test frame timestamps captured by logical camera are within 10ms.

  Captures data with phone moving in front of chessboard pattern.
  Extracts angles from images and calculated angles. Compares angle movement
  between the 2 cameras.
  Masks out data near 90 degrees as with the chessboard, 90 degrees will
  look like 0 degrees.
  """

  def _collect_data(self, cam, props, rot_rig):
    """Returns list of pair of gray frames and camera ids used for captures."""

    # Determine return parameters
    ids = camera_properties_utils.logical_multi_camera_physical_ids(props)

    # Define capture request
    sens, exp, _, _, _ = cam.do_3a(get_results=True, do_af=False)
    req = capture_request_utils.manual_capture_request(sens, exp)
    fd_min = props['android.lens.info.minimumFocusDistance']
    fd_chart = 1 / (_CHART_DISTANCE_SF * _CM_TO_M)
    if fd_min < fd_chart:
      req['android.lens.focusDistance'] = fd_min
    else:
      req['android.lens.focusDistance'] = fd_chart

    # Capture YUVs
    width = opencv_processing_utils.VGA_WIDTH
    height = opencv_processing_utils.VGA_HEIGHT
    out_surfaces = [{'format': 'yuv', 'width': width, 'height': height,
                     'physicalCamera': ids[0]},
                    {'format': 'yuv', 'width': width, 'height': height,
                     'physicalCamera': ids[1]}]

    out_surfaces_supported = cam.is_stream_combination_supported(out_surfaces)
    camera_properties_utils.skip_unless(out_surfaces_supported)

    # Start camera rotation & sleep shortly to let rotations start
    p = multiprocessing.Process(
        target=sensor_fusion_utils.rotation_rig,
        args=(rot_rig['cntl'], rot_rig['ch'], _NUM_ROTATIONS,))
    p.start()
    time.sleep(_ROT_INIT_WAIT_TIME)

    # Do captures
    capture_1_list, capture_2_list = cam.do_capture(
        [req]*_NUM_CAPTURES, out_surfaces)

    # Create list of capture pairs. [[cap1A, cap1B], [cap2A, cap2B], ...]
    frame_pairs = zip(capture_1_list, capture_2_list)

    # Convert captures to grayscale
    frame_pairs_gray = []
    for pair in frame_pairs:
      frame_pairs_gray.append(
          [cv2.cvtColor(image_processing_utils.convert_capture_to_rgb_image(
              f, props=props), cv2.COLOR_RGB2GRAY) for f in pair])

    # Save images
    for i, imgs in enumerate(frame_pairs_gray):
      for j in [0, 1]:
        file_name = '%s_%s_%03d.png' % (
            os.path.join(self.log_path, _NAME), ids[j], i)
        cv2.imwrite(file_name, imgs[j]*255)

    return frame_pairs_gray, ids

  def _assert_camera_movement(self, frame_pairs_angles):
    """Assert the angles between each frame pair are sufficiently different.

    Args:
      frame_pairs_angles: [normal, wide] angles extracted from images.

    Different angles is an indication of camera movement.
    """
    angles = [i for i, _ in frame_pairs_angles]
    max_angle = numpy.amax(angles)
    min_angle = numpy.amin(angles)
    logging.debug('Camera movement. min angle: %.2f, max: %.2f',
                  min_angle, max_angle)
    if max_angle-min_angle < _ANGULAR_MOVEMENT_THRESHOLD:
      raise AssertionError(
          f'Not enough phone movement! min angle: {min_angle:.2f}, max angle: '
          f'{max_angle:.2f}, THRESH: {_ANGULAR_MOVEMENT_THRESHOLD:d} deg')

  def _assert_angular_difference(self, angle_1, angle_2, angular_diff_thresh):
    """Assert angular difference is within threshold."""
    diff = abs(angle_2 - angle_1)

    # Assert difference is less than threshold
    if diff > angular_diff_thresh:
      raise AssertionError(
          f'Too much difference between cameras! Angle 1: {angle_1:.2f}, 2: '
          f'{angle_2:.2f}, diff: {diff:.3f}, TOL: {angular_diff_thresh}.')

  def test_multi_camera_frame_sync(self):
    rot_rig = {}
    rot_rig['cntl'] = self.rotator_cntl
    rot_rig['ch'] = self.rotator_ch

    with its_session_utils.ItsSession(
        device_id=self.dut.serial,
        camera_id=self.camera_id,
        hidden_physical_id=self.hidden_physical_id) as cam:
      props = cam.get_camera_properties()
      props = cam.override_with_hidden_physical_camera_props(props)

      # Check SKIP conditions.
      camera_properties_utils.skip_unless(
          camera_properties_utils.multi_camera_frame_sync_capable(props))

      # Get first API level & multi camera sync type
      first_api_level = its_session_utils.get_first_api_level(self.dut.serial)
      sync_calibrated = camera_properties_utils.multi_camera_sync_calibrated(
          props)
      logging.debug(
          'sync: %s', 'CALIBRATED' if sync_calibrated else 'APPROXIMATE')

      # Collect data
      frame_pairs_gray, ids = self._collect_data(cam, props, rot_rig)

    # Compute angles in frame pairs
    frame_pairs_angles = [
        [opencv_processing_utils.get_angle(p[0]),
         opencv_processing_utils.get_angle(p[1])] for p in frame_pairs_gray]

    # Remove frames where not enough squares were detected.
    filtered_pairs_angles = _remove_frames_without_enough_squares(
        frame_pairs_angles)

    # Mask out data near 90 degrees.
    masked_pairs_angles = _mask_angles_near_extremes(filtered_pairs_angles)

    # Plot angles and differences.
    _plot_frame_pairs_angles(filtered_pairs_angles, ids, self.log_path)

    # Ensure camera moved.
    self._assert_camera_movement(masked_pairs_angles)

    # Ensure angle between the two cameras is not too different.
    max_frame_to_frame_diff = _determine_max_frame_to_frame_shift(
        masked_pairs_angles)
    angular_diff_thresh = _determine_angular_diff_thresh(
        first_api_level, sync_calibrated, max_frame_to_frame_diff)
    for cam_1_angle, cam_2_angle in masked_pairs_angles:
      self._assert_angular_difference(
          cam_1_angle, cam_2_angle, angular_diff_thresh)

if __name__ == '__main__':
  test_runner.main()
