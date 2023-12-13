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
"""Verifies 3 faces with different skin tones are detected."""


import logging
import os.path
from mobly import test_runner

import its_base_test
import camera_properties_utils
import capture_request_utils
import image_processing_utils
import its_session_utils
import cv2

FD_MODE_OFF = 0
FD_MODE_SIMPLE = 1
FD_MODE_FULL = 2
NAME = os.path.splitext(os.path.basename(__file__))[0]
NUM_TEST_FRAMES = 20
NUM_FACES = 3
W, H = 640, 480


def draw_face_rectangles(img, faces, aw, ah):
  """Draw rectangles on top of image.

  Args:
    img:    image array
    faces:  list of dicts with face information
    aw:     int; active array width
    ah:     int; active array height
  Returns:
    img with face rectangles drawn on it
  """
  for rect in [face['bounds'] for face in faces]:
    top_left = (int(round(rect['left']*W/aw)),
                int(round(rect['top']*H/ah)))
    bot_rght = (int(round(rect['right']*W/aw)),
                int(round(rect['bottom']*H/ah)))
    cv2.rectangle(img, top_left, bot_rght, (0, 1, 0), 2)
  return img


class NumFacesTest(its_base_test.ItsBaseTest):
  """Test face detection with different skin tones.
  """

  def test_num_faces(self):
    """Test face detection."""
    with its_session_utils.ItsSession(
        device_id=self.dut.serial,
        camera_id=self.camera_id,
        hidden_physical_id=self.hidden_physical_id) as cam:
      props = cam.get_camera_properties()
      props = cam.override_with_hidden_physical_camera_props(props)

      # Load chart for scene
      its_session_utils.load_scene(
          cam, props, self.scene, self.tablet, self.chart_distance)

      # Check skip conditions
      camera_properties_utils.skip_unless(
          camera_properties_utils.face_detect(props))
      mono_camera = camera_properties_utils.mono_camera(props)
      fd_modes = props['android.statistics.info.availableFaceDetectModes']
      a = props['android.sensor.info.activeArraySize']
      aw, ah = a['right'] - a['left'], a['bottom'] - a['top']

      if camera_properties_utils.read_3a(props):
        _, _, _, _, _ = cam.do_3a(get_results=True, mono_camera=mono_camera)

      for fd_mode in fd_modes:
        assert FD_MODE_OFF <= fd_mode <= FD_MODE_FULL
        req = capture_request_utils.auto_capture_request()
        req['android.statistics.faceDetectMode'] = fd_mode
        fmt = {'format': 'yuv', 'width': W, 'height': H}
        caps = cam.do_capture([req]*NUM_TEST_FRAMES, fmt)
        for i, cap in enumerate(caps):
          md = cap['metadata']
          assert md['android.statistics.faceDetectMode'] == fd_mode
          faces = md['android.statistics.faces']

          # 0 faces should be returned for OFF mode
          if fd_mode == FD_MODE_OFF:
            assert not faces
            continue
          # Face detection could take several frames to warm up,
          # but should detect the correct number of faces in last frame
          if i == NUM_TEST_FRAMES - 1:
            img = image_processing_utils.convert_capture_to_rgb_image(
                cap, props=props)
            fnd_faces = len(faces)
            logging.debug('Found %d face(s), expected %d.',
                          fnd_faces, NUM_FACES)
            # draw boxes around faces
            img = draw_face_rectangles(img, faces, aw, ah)
            # save image with rectangles
            img_name = '%s_fd_mode_%s.jpg' % (os.path.join(self.log_path,
                                                           NAME), fd_mode)
            image_processing_utils.write_image(img, img_name)
            assert fnd_faces == NUM_FACES
          if not faces:
            continue

          logging.debug('Frame %d face metadata:', i)
          logging.debug(' Faces: %s', str(faces))

          # Reasonable scores for faces
          face_scores = [face['score'] for face in faces]
          for score in face_scores:
            assert 1 <= score <= 100
          # Face bounds should be within active array
          face_rectangles = [face['bounds'] for face in faces]
          for rect in face_rectangles:
            assert rect['top'] < rect['bottom']
            assert rect['left'] < rect['right']
            assert 0 <= rect['top'] <= ah
            assert 0 <= rect['bottom'] <= ah
            assert 0 <= rect['left'] <= aw
            assert 0 <= rect['right'] <= aw

if __name__ == '__main__':
  test_runner.main()
