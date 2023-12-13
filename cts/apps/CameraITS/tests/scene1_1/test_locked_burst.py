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
"""Verifies YUV image consistency with AE and AWB locked."""


import logging
import os.path
from mobly import test_runner

import its_base_test
import camera_properties_utils
import capture_request_utils
import image_processing_utils
import its_session_utils

BURST_LEN = 8
COLORS = ['R', 'G', 'B']
FPS_MAX_DIFF = 2.0
NAME = os.path.splitext(os.path.basename(__file__))[0]
PATCH_H = 0.1  # center 10%
PATCH_W = 0.1
PATCH_X = 0.5 - PATCH_W
PATCH_Y = 0.5 - PATCH_H
SPREAD_THRESH_MANUAL_SENSOR = 0.01
SPREAD_THRESH = 0.03
VALUE_THRESH = 0.1


class LockedBurstTest(its_base_test.ItsBaseTest):
  """Test 3A lock + YUV burst (using auto settings).

  This is a test designed to pass even on limited devices that
  don't have MANUAL_SENSOR or PER_FRAME_CONTROL. The test checks
  YUV image consistency while the frame rate check is in CTS.
  """

  def test_locked_burst(self):
    logging.debug('Starting %s', NAME)
    with its_session_utils.ItsSession(
        device_id=self.dut.serial,
        camera_id=self.camera_id,
        hidden_physical_id=self.hidden_physical_id) as cam:
      props = cam.get_camera_properties()
      props = cam.override_with_hidden_physical_camera_props(props)
      mono_camera = camera_properties_utils.mono_camera(props)
      log_path = self.log_path

      # check SKIP conditions
      camera_properties_utils.skip_unless(
          camera_properties_utils.ae_lock(props) and
          camera_properties_utils.awb_lock(props))

      # Load chart for scene
      its_session_utils.load_scene(
          cam, props, self.scene, self.tablet, self.chart_distance)

      # Converge 3A prior to capture.
      cam.do_3a(do_af=True, lock_ae=True, lock_awb=True,
                mono_camera=mono_camera)

      fmt = capture_request_utils.get_largest_yuv_format(props)

      # After 3A has converged, lock AE+AWB for the duration of the test.
      logging.debug('Locking AE & AWB')
      req = capture_request_utils.fastest_auto_capture_request(props)
      req['android.control.awbLock'] = True
      req['android.control.aeLock'] = True

      # Capture bursts of YUV shots.
      # Get the mean values of a center patch for each.
      r_means = []
      g_means = []
      b_means = []
      caps = cam.do_capture([req]*BURST_LEN, fmt)
      for i, cap in enumerate(caps):
        img = image_processing_utils.convert_capture_to_rgb_image(cap)
        image_processing_utils.write_image(img, '%s_frame%d.jpg' % (
            os.path.join(log_path, NAME), i))
        patch = image_processing_utils.get_image_patch(
            img, PATCH_X, PATCH_Y, PATCH_W, PATCH_H)
        means = image_processing_utils.compute_image_means(patch)
        r_means.append(means[0])
        g_means.append(means[1])
        b_means.append(means[2])

      # Assert center patch brightness & similarity
      for i, means in enumerate([r_means, g_means, b_means]):
        plane = COLORS[i]
        min_means = min(means)
        spread = max(means) - min_means
        logging.debug('%s patch mean spread %.5f. means = %s',
                      plane, spread, str(means))
        for j in range(BURST_LEN):
          e_msg = '%s frame %d too dark! mean: %.5f, THRESH: %.2f' % (
              plane, j, min_means, VALUE_THRESH)
          assert min_means > VALUE_THRESH, e_msg
          threshold = SPREAD_THRESH
          if camera_properties_utils.manual_sensor(props):
            threshold = SPREAD_THRESH_MANUAL_SENSOR
          e_msg = '%s center patch spread: %.5f, THRESH: %.2f' % (
              plane, spread, threshold)
          assert spread < threshold, e_msg

if __name__ == '__main__':
  test_runner.main()

