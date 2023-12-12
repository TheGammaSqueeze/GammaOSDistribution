# Copyright 2018, The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
Integration Finder class.
"""

# pylint: disable=line-too-long

import copy
import logging
import os
import re
import shutil
import tempfile
import xml.etree.ElementTree as ElementTree

from zipfile import ZipFile

import atest_error
import constants

from test_finders import test_info
from test_finders import test_finder_base
from test_finders import test_finder_utils
from test_runners import atest_tf_test_runner

# Find integration name based on file path of integration config xml file.
# Group matches "foo/bar" given "blah/res/config/foo/bar.xml from source code
# res directory or "blah/config/foo/bar.xml from prebuilt jars.
_INT_NAME_RE = re.compile(r'^.*\/config\/(?P<int_name>.*).xml$')
_TF_TARGETS = frozenset(['tradefed', 'tradefed-contrib'])
_GTF_TARGETS = frozenset(['google-tradefed', 'google-tradefed-contrib'])
_CONTRIB_TARGETS = frozenset(['google-tradefed-contrib'])
_TF_RES_DIRS = frozenset(['../res/config', 'res/config'])


class TFIntegrationFinder(test_finder_base.TestFinderBase):
    """Integration Finder class."""
    NAME = 'INTEGRATION'
    _TEST_RUNNER = atest_tf_test_runner.AtestTradefedTestRunner.NAME


    def __init__(self, module_info=None):
        super().__init__()
        self.root_dir = os.environ.get(constants.ANDROID_BUILD_TOP)
        self.module_info = module_info
        # TODO: Break this up into AOSP/google_tf integration finders.
        self.tf_dirs, self.gtf_dirs = self._get_integration_dirs()
        self.integration_dirs = self.tf_dirs + self.gtf_dirs
        self.temp_dir = tempfile.TemporaryDirectory()

    def _get_mod_paths(self, module_name):
        """Return the paths of the given module name."""
        if self.module_info:
            # Since aosp/801774 merged, the path of test configs have been
            # changed to ../res/config.
            if module_name in _CONTRIB_TARGETS:
                mod_paths = self.module_info.get_paths(module_name)
                return [os.path.join(path, res_path) for path in mod_paths
                        for res_path in _TF_RES_DIRS]
            return self.module_info.get_paths(module_name)
        return []

    def _get_integration_dirs(self):
        """Get integration dirs from MODULE_INFO based on targets.

        Returns:
            A tuple of lists of strings of integration dir rel to repo root.
        """
        tf_dirs = list(filter(None, [d for x in _TF_TARGETS for d in self._get_mod_paths(x)]))
        gtf_dirs = list(filter(None, [d for x in _GTF_TARGETS for d in self._get_mod_paths(x)]))
        return tf_dirs, gtf_dirs

    def _get_build_targets(self, rel_config):
        config_file = os.path.join(self.root_dir, rel_config)
        xml_root = self._load_xml_file(config_file)
        targets = test_finder_utils.get_targets_from_xml_root(xml_root,
                                                              self.module_info)
        if self.gtf_dirs:
            targets.add(constants.GTF_TARGET)
        return frozenset(targets)

    def _load_xml_file(self, path):
        """Load an xml file with option to expand <include> tags

        Args:
            path: A string of path to xml file.

        Returns:
            An xml.etree.ElementTree.Element instance of the root of the tree.
        """
        tree = ElementTree.parse(path)
        root = tree.getroot()
        self._load_include_tags(root)
        return root

    #pylint: disable=invalid-name
    def _load_include_tags(self, root):
        """Recursively expand in-place the <include> tags in a given xml tree.

        Python xml libraries don't support our type of <include> tags. Logic
        used below is modified version of the built-in ElementInclude logic
        found here:
        https://github.com/python/cpython/blob/2.7/Lib/xml/etree/ElementInclude.py

        Args:
            root: The root xml.etree.ElementTree.Element.

        Returns:
            An xml.etree.ElementTree.Element instance with
            include tags expanded.
        """
        i = 0
        while i < len(root):
            elem = root[i]
            if elem.tag == 'include':
                # expand included xml file
                integration_name = elem.get('name')
                if not integration_name:
                    logging.warning('skipping <include> tag with no "name" value')
                    continue
                full_paths = self._search_integration_dirs(integration_name)
                if not full_paths:
                    full_paths = self._search_prebuilt_jars(integration_name)
                node = None
                if full_paths:
                    node = self._load_xml_file(full_paths[0])
                if node is None:
                    raise atest_error.FatalIncludeError("can't load %r" %
                                                        integration_name)
                node = copy.copy(node)
                if elem.tail:
                    node.tail = (node.tail or "") + elem.tail
                root[i] = node
            i = i + 1

    def _search_integration_dirs(self, name):
        """Search integration dirs for name and return full path.
        Args:
            name: A string of integration name as seen in tf's list configs.

        Returns:
            A list of test path.
        """
        test_files = []
        for integration_dir in self.integration_dirs:
            abs_path = os.path.join(self.root_dir, integration_dir)
            found_test_files = test_finder_utils.run_find_cmd(
                test_finder_utils.FIND_REFERENCE_TYPE.INTEGRATION,
                abs_path, name)
            if found_test_files:
                test_files.extend(found_test_files)
        return test_files

    def find_test_by_integration_name(self, name):
        """Find the test info matching the given integration name.

        Args:
            name: A string of integration name as seen in tf's list configs.

        Returns:
            A populated TestInfo namedtuple if test found, else None
        """
        class_name = None
        if ':' in name:
            name, class_name = name.split(':')
        test_files = self._search_integration_dirs(name)
        if not test_files:
            # Check prebuilt jars if input name is in jars.
            test_files = self._search_prebuilt_jars(name)
        # Don't use names that simply match the path,
        # must be the actual name used by TF to run the test.
        t_infos = []
        for test_file in test_files:
            t_info = self._get_test_info(name, test_file, class_name)
            if t_info:
                t_infos.append(t_info)
        return t_infos

    def _get_prebuilt_jars(self):
        """Get prebuilt jars based on targets.

        Returns:
            A tuple of lists of strings of prebuilt jars.
        """
        prebuilt_jars = []
        for tf_dir in self.tf_dirs:
            for tf_target in _TF_TARGETS:
                jar_path = os.path.join(
                    self.root_dir, tf_dir, '..', 'filegroups', 'tradefed',
                    tf_target + '.jar')
                if os.path.exists(jar_path):
                    prebuilt_jars.append(jar_path)
        for gtf_dir in self.gtf_dirs:
            for gtf_target in _GTF_TARGETS:
                jar_path = os.path.join(
                    self.root_dir, gtf_dir, '..', 'filegroups',
                    'google-tradefed', gtf_target + '.jar')
                if os.path.exists(jar_path):
                    prebuilt_jars.append(jar_path)
        return prebuilt_jars

    def _search_prebuilt_jars(self, name):
        """Search tradefed prebuilt jar which has matched name.

        Search if input name matched prebuilt tradefed jar. If matched, extract
        the jar file to temp directly for later on test info handling.

        Args:
            name: A string of integration name as seen in tf's list configs.

        Returns:
            A list of test path.
        """

        xml_path = 'config/{}.xml'.format(name)
        test_files = []
        prebuilt_jars = self._get_prebuilt_jars()
        logging.debug('Found prebuilt_jars=%s', prebuilt_jars)
        for prebuilt_jar in prebuilt_jars:
            with ZipFile(prebuilt_jar, 'r') as jar_file:
                jar_contents = jar_file.namelist()
                if xml_path in jar_contents:
                    extract_path = os.path.join(
                        self.temp_dir.name, os.path.basename(prebuilt_jar))
                    if not os.path.exists(extract_path):
                        logging.debug('Extracting %s to %s',
                                      prebuilt_jar, extract_path)
                        jar_file.extractall(extract_path)
                    test_files.append(os.path.join(extract_path, xml_path))

        # TODO(b/194362862): Remove below logic after prebuilt jars could be
        # loaded by atest_tradefed.sh from prebuilt folder directly.
        # If found in prebuilt jars, manually copy tradefed related jars
        # to out/host as tradefed's java path.
        if test_files:
            host_framework_dir = os.path.join(
                os.getenv(constants.ANDROID_HOST_OUT, ''), 'framework')
            if not os.path.isdir(host_framework_dir):
                os.makedirs(host_framework_dir)
            prebuilt_dirs = []
            for prebuilt_jar in prebuilt_jars:
                prebuilt_dir = os.path.dirname(prebuilt_jar)
                if prebuilt_dir not in prebuilt_dirs:
                    prebuilt_dirs.append(prebuilt_dir)
            for prebuilt_dir in prebuilt_dirs:
                prebuilts = os.listdir(prebuilt_dir)
                for prebuilt in prebuilts:
                    if os.path.splitext(prebuilt)[1] == '.jar':
                        prebuilt_jar = os.path.join(prebuilt_dir, prebuilt)
                        logging.debug('Copy %s to %s',
                                      prebuilt_jar, host_framework_dir)
                        shutil.copy2(prebuilt_jar, host_framework_dir)
        return test_files

    def _get_test_info(self, name, test_file, class_name):
        """Find the test info matching the given test_file and class_name.

        Args:
            name: A string of integration name as seen in tf's list configs.
            test_file: A string of test_file full path.
            class_name: A string of user's input.

        Returns:
            A populated TestInfo namedtuple if test found, else None.
        """
        match = _INT_NAME_RE.match(test_file)
        if not match:
            logging.error('Integration test outside config dir: %s',
                          test_file)
            return None
        int_name = match.group('int_name')
        if int_name != name:
            logging.warning('Input (%s) not valid integration name, '
                            'did you mean: %s?', name, int_name)
            return None
        rel_config = os.path.relpath(test_file, self.root_dir)
        filters = frozenset()
        if class_name:
            class_name, methods = test_finder_utils.split_methods(class_name)
            test_filters = []
            if '.' in class_name:
                test_filters.append(test_info.TestFilter(class_name, methods))
            else:
                logging.warning('Looking up fully qualified class name for: %s.'
                                'Improve speed by using fully qualified names.',
                                class_name)
                paths = test_finder_utils.find_class_file(self.root_dir,
                                                          class_name)
                if not paths:
                    return None
                for path in paths:
                    class_name = (
                        test_finder_utils.get_fully_qualified_class_name(
                            path))
                    test_filters.append(test_info.TestFilter(
                        class_name, methods))
            filters = frozenset(test_filters)
        return test_info.TestInfo(
            test_name=name,
            test_runner=self._TEST_RUNNER,
            build_targets=self._get_build_targets(rel_config),
            data={constants.TI_REL_CONFIG: rel_config,
                  constants.TI_FILTER: filters})

    def find_int_test_by_path(self, path):
        """Find the first test info matching the given path.

        Strategy:
            path_to_integration_file --> Resolve to INTEGRATION
            # If the path is a dir, we return nothing.
            path_to_dir_with_integration_files --> Return None

        Args:
            path: A string of the test's path.

        Returns:
            A list of populated TestInfo namedtuple if test found, else None
        """
        path, _ = test_finder_utils.split_methods(path)

        # Make sure we're looking for a config.
        if not path.endswith('.xml'):
            return None

        # TODO: See if this can be generalized and shared with methods above
        # create absolute path from cwd and remove symbolic links
        path = os.path.realpath(path)
        if not os.path.exists(path):
            logging.debug('"%s": file not found!', path)
            return None
        int_dir = test_finder_utils.get_int_dir_from_path(path,
                                                          self.integration_dirs)
        if int_dir:
            rel_config = os.path.relpath(path, self.root_dir)
            match = _INT_NAME_RE.match(rel_config)
            if not match:
                logging.error('Integration test outside config dir: %s',
                              rel_config)
                return None
            int_name = match.group('int_name')
            return [test_info.TestInfo(
                test_name=int_name,
                test_runner=self._TEST_RUNNER,
                build_targets=self._get_build_targets(rel_config),
                data={constants.TI_REL_CONFIG: rel_config,
                      constants.TI_FILTER: frozenset()})]
        return None
