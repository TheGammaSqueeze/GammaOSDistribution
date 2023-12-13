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
"""Cloud function that requests coverage builds."""
import base64

import google.auth
from google.cloud import ndb

import build_and_run_coverage
import request_build

BASE_PROJECT = 'oss-fuzz-base'


def get_build_steps(project_name, image_project, base_images_project):
  """Retrieve build steps."""
  project_yaml_contents, dockerfile_lines = request_build.get_project_data(
      project_name)
  return build_and_run_coverage.get_build_steps(project_name,
                                                project_yaml_contents,
                                                dockerfile_lines, image_project,
                                                base_images_project)


def request_coverage_build(event, context):
  """Entry point for coverage build cloud function."""
  del context  #unused
  if 'data' in event:
    project_name = base64.b64decode(event['data']).decode('utf-8')
  else:
    raise RuntimeError('Project name missing from payload')

  with ndb.Client().context():
    credentials, image_project = google.auth.default()
    build_steps = get_build_steps(project_name, image_project, BASE_PROJECT)
    if not build_steps:
      return
    request_build.run_build(project_name, image_project, build_steps,
                            credentials,
                            build_and_run_coverage.COVERAGE_BUILD_TAG)
