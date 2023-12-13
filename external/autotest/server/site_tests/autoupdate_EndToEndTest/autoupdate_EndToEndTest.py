# Copyright (c) 2012 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import logging
import os

from autotest_lib.client.common_lib.cros import kernel_utils
from autotest_lib.client.cros import constants
from autotest_lib.server import afe_utils
from autotest_lib.server.cros import provisioner
from autotest_lib.server.cros.update_engine import update_engine_test


class autoupdate_EndToEndTest(update_engine_test.UpdateEngineTest):
    """Complete update test between two Chrome OS releases.

    Performs an end-to-end test of updating a ChromeOS device from one version
    to another. The test performs the following steps:

      - Stages the source (full) and target update payloads on a devserver.
      - Installs source image on the DUT (if provided) and reboots to it.
      - Verifies that sign in works correctly on the source image.
      - Installs target image on the DUT and reboots.
      - Does a final update check.
      - Verifies that sign in works correctly on the target image.
      - Returns the hostlogs collected during each update check for
        verification against expected update events.

    This class interacts with several others:
    UpdateEngineTest: base class for comparing expected update events against
                      the events listed in the hostlog.
    UpdateEngineEvent: class representing a single expected update engine event.

    """
    version = 1

    _LOGIN_TEST = 'login_LoginSuccess'


    def cleanup(self):
        """Save the logs from stateful_partition's preserved/log dir."""
        stateful_preserved_logs = os.path.join(self.resultsdir,
                                               '~stateful_preserved_logs')
        os.makedirs(stateful_preserved_logs)
        self._host.get_file(constants.AUTOUPDATE_PRESERVE_LOG,
                            stateful_preserved_logs, safe_symlinks=True,
                            preserve_perm=False)
        super(autoupdate_EndToEndTest, self).cleanup()


    def _print_rerun_command(self, test_conf):
        """Prints the command to rerun a test run from the lab at your desk."""
        logging.debug('Rerun this test run at your desk using this command:')
        rerun_cmd = ('test_that <DUT NAME>.cros autoupdate_EndToEndTest '
                     '--args="update_type=%s source_release=%s '
                     'source_payload_uri=%s target_release=%s '
                     'target_payload_uri=%s"')
        rerun_cmd = rerun_cmd % (
                test_conf['update_type'], test_conf['source_release'],
                test_conf['source_payload_uri'], test_conf['target_release'],
                test_conf['target_payload_uri'])
        logging.debug(rerun_cmd)

    def run_update_test(self, test_conf):
        """Runs the update test and checks it succeeded.

        @param test_conf: A dictionary containing test configuration values.

        """
        # Record the active root partition.
        active, inactive = kernel_utils.get_kernel_state(self._host)
        logging.info('Source active slot: %s', active)

        source_release = test_conf['source_release']
        target_release = test_conf['target_release']

        self.update_device(test_conf['target_payload_uri'], tag='target')

        # Compare hostlog events from the update to the expected ones.
        rootfs, reboot = self._create_hostlog_files()
        self.verify_update_events(source_release, rootfs)
        self.verify_update_events(source_release, reboot, target_release)
        kernel_utils.verify_boot_expectations(inactive, host=self._host)
        logging.info('Update successful, test completed')


    def run_once(self, test_conf):
        """Performs a complete auto update test.

        @param test_conf: a dictionary containing test configuration values.

        """
        logging.debug('The test configuration supplied: %s', test_conf)
        self._print_rerun_command(test_conf)
        self._autotest_devserver = self._get_devserver_for_test(test_conf)

        afe_utils.clean_provision_labels(self._host)

        # Install source image with quick-provision.
        source_payload_uri = test_conf['source_payload_uri']
        if source_payload_uri:
            build_name, _ = self._get_update_parameters_from_uri(
                source_payload_uri)
            update_url = self._autotest_devserver.get_update_url(
                build_name)
            logging.info('Installing source image with update url: %s',
                         update_url)

            provisioner.ChromiumOSProvisioner(
                    update_url, host=self._host,
                    is_release_bucket=True).run_provision()

            self._run_client_test_and_check_result(self._LOGIN_TEST,
                                                   tag='source')
        # Start the update to the target image.
        self._stage_payloads(test_conf['target_payload_uri'],
                             test_conf['target_archive_uri'])
        self.run_update_test(test_conf)

        # Check we can login after the update.
        self._run_client_test_and_check_result(self._LOGIN_TEST, tag='target')
