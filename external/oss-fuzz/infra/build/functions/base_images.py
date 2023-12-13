# Copyright 2020 Google Inc.
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
################################################################################
"""Cloud function to build base images on Google Cloud Builder."""

import datetime
import logging

import google.auth
from googleapiclient.discovery import build

BASE_IMAGES = [
    'base-image',
    'base-clang',
    'base-builder',
    'base-runner',
    'base-runner-debug',
]
BASE_PROJECT = 'oss-fuzz-base'
TAG_PREFIX = f'gcr.io/{BASE_PROJECT}/'

BASE_SANITIZER_LIBS_IMAGE = TAG_PREFIX + 'base-sanitizer-libs-builder'
MSAN_LIBS_IMAGE = TAG_PREFIX + 'msan-libs-builder'


def _get_base_image_steps(images, tag_prefix=TAG_PREFIX):
  """Returns build steps for given images."""
  steps = [{
      'args': [
          'clone',
          'https://github.com/google/oss-fuzz.git',
      ],
      'name': 'gcr.io/cloud-builders/git',
  }]

  for base_image in images:
    steps.append({
        'args': [
            'build',
            '-t',
            tag_prefix + base_image,
            '.',
        ],
        'dir': 'oss-fuzz/infra/base-images/' + base_image,
        'name': 'gcr.io/cloud-builders/docker',
    })

  return steps


def get_logs_url(build_id, project_id='oss-fuzz-base'):
  """Returns url that displays the build logs."""
  url_format = ('https://console.developers.google.com/logs/viewer?'
                'resource=build%2Fbuild_id%2F{0}&project={1}')
  return url_format.format(build_id, project_id)


# pylint: disable=no-member
def run_build(steps, images):
  """Execute the retrieved build steps in gcp."""
  credentials, _ = google.auth.default()
  build_body = {
      'steps': steps,
      'timeout': str(6 * 3600) + 's',
      'options': {
          'machineType': 'N1_HIGHCPU_32'
      },
      'images': images
  }
  cloudbuild = build('cloudbuild',
                     'v1',
                     credentials=credentials,
                     cache_discovery=False)
  build_info = cloudbuild.projects().builds().create(projectId=BASE_PROJECT,
                                                     body=build_body).execute()
  build_id = build_info['metadata']['build']['id']
  logging.info('Build ID: %s', build_id)
  logging.info('Logs: %s', get_logs_url(build_id, BASE_PROJECT))


def base_builder(event, context):
  """Cloud function to build base images."""
  del event, context

  tag_prefix = f'gcr.io/{BASE_PROJECT}/'
  steps = _get_base_image_steps(BASE_IMAGES, tag_prefix)
  images = [tag_prefix + base_image for base_image in BASE_IMAGES]

  run_build(steps, images)


def _get_msan_steps(image):
  """Get build steps for msan-libs-builder."""
  timestamp = datetime.datetime.utcnow().strftime('%Y%m%d%H%M')
  upload_name = 'msan-libs-' + timestamp + '.zip'

  steps = _get_base_image_steps([
      'base-sanitizer-libs-builder',
      'msan-libs-builder',
  ])
  steps.extend([{
      'name': image,
      'args': [
          'bash',
          '-c',
          'cd /msan && zip -r /workspace/libs.zip .',
      ],
  }, {
      'name':
          'gcr.io/cloud-builders/gsutil',
      'args': [
          'cp',
          '/workspace/libs.zip',
          'gs://oss-fuzz-msan-libs/' + upload_name,
      ],
  }])
  return steps


def base_msan_builder(event, context):
  """Cloud function to build base images."""
  del event, context
  steps = _get_msan_steps(MSAN_LIBS_IMAGE)
  images = [
      BASE_SANITIZER_LIBS_IMAGE,
      MSAN_LIBS_IMAGE,
  ]

  run_build(steps, images)
