# Copyright 2021 Google LLC
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
"""Module for determining coverage of fuzz targets."""
import logging
import os
import sys
import json
import urllib.error
import urllib.request

# pylint: disable=wrong-import-position,import-error
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import utils

# The path to get project's latest report json file.
LATEST_REPORT_INFO_PATH = 'oss-fuzz-coverage/latest_report_info/'


class OssFuzzCoverageGetter:
  """Gets coverage data for a project from OSS-Fuzz."""

  def __init__(self, project_name, repo_path):
    """Constructor for OssFuzzCoverageGetter. Callers should check that
    fuzzer_stats_url is initialized."""
    self.project_name = project_name
    self.repo_path = _normalize_repo_path(repo_path)
    self.fuzzer_stats_url = _get_fuzzer_stats_dir_url(self.project_name)

  def get_target_coverage_report(self, target):
    """Get the coverage report for a specific fuzz target.

    Args:
      target: The name of the fuzz target whose coverage is requested.

    Returns:
      The target's coverage json dict or None on failure.
    """
    if not self.fuzzer_stats_url:
      return None

    target_url = utils.url_join(self.fuzzer_stats_url, target + '.json')
    return get_json_from_url(target_url)

  def get_files_covered_by_target(self, target):
    """Gets a list of source files covered by the specific fuzz target.

    Args:
      target: The name of the fuzz target whose coverage is requested.

    Returns:
      A list of files that the fuzz targets covers or None.
    """
    target_cov = self.get_target_coverage_report(target)
    if not target_cov:
      return None

    coverage_per_file = get_coverage_per_file(target_cov)
    if not coverage_per_file:
      logging.info('No files found in coverage report.')
      return None

    affected_file_list = []
    for file_cov in coverage_per_file:
      norm_file_path = os.path.normpath(file_cov['filename'])
      if not norm_file_path.startswith(self.repo_path):
        # Exclude files outside of the main repo.
        continue

      if not is_file_covered(file_cov):
        # Don't consider a file affected if code in it is never executed.
        continue

      # TODO(metzman): It's weird to me that we access file_cov['filename']
      # again and not norm_file_path, figure out if this makes sense.
      relative_path = utils.remove_prefix(file_cov['filename'], self.repo_path)
      affected_file_list.append(relative_path)

    return affected_file_list


def is_file_covered(file_cov):
  """Returns whether the file is covered."""
  return file_cov['summary']['regions']['covered']


def get_coverage_per_file(target_cov):
  """Returns the coverage per file within |target_cov|."""
  return target_cov['data'][0]['files']


def _normalize_repo_path(repo_path):
  """Normalizes and returns |repo_path| to make sure cases like /src/curl and
  /src/curl/ are both handled."""
  repo_path = os.path.normpath(repo_path)
  if not repo_path.endswith('/'):
    repo_path += '/'
  return repo_path


def _get_latest_cov_report_info(project_name):
  """Gets and returns a dictionary containing the latest coverage report info
  for |project|."""
  latest_report_info_url = utils.url_join(utils.GCS_BASE_URL,
                                          LATEST_REPORT_INFO_PATH,
                                          project_name + '.json')
  latest_cov_info = get_json_from_url(latest_report_info_url)
  if latest_cov_info is None:
    logging.error('Could not get the coverage report json from url: %s.',
                  latest_report_info_url)
    return None
  return latest_cov_info


def _get_fuzzer_stats_dir_url(project_name):
  """Gets latest coverage report info for a specific OSS-Fuzz project from GCS.

  Args:
    project_name: The name of the relevant OSS-Fuzz project.

  Returns:
    The projects coverage report info in json dict or None on failure.
  """
  latest_cov_info = _get_latest_cov_report_info(project_name)

  if not latest_cov_info:
    return None

  if 'fuzzer_stats_dir' not in latest_cov_info:
    logging.error('fuzzer_stats_dir not in latest coverage info.')
    return None

  fuzzer_stats_dir_gs_url = latest_cov_info['fuzzer_stats_dir']
  fuzzer_stats_dir_url = utils.gs_url_to_https(fuzzer_stats_dir_gs_url)
  return fuzzer_stats_dir_url


def get_json_from_url(url):
  """Gets a json object from a specified HTTP URL.

  Args:
    url: The url of the json to be downloaded.

  Returns:
    A dictionary deserialized from JSON or None on failure.
  """
  try:
    response = urllib.request.urlopen(url)
  except urllib.error.HTTPError:
    logging.error('HTTP error with url %s.', url)
    return None

  try:
    # read().decode() fixes compatibility issue with urllib response object.
    result_json = json.loads(response.read().decode())
  except (ValueError, TypeError, json.JSONDecodeError) as err:
    logging.error('Loading json from url %s failed with: %s.', url, str(err))
    return None
  return result_json
