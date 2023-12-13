# Copyright 2017 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import logging

from autotest_lib.client.bin import utils
from autotest_lib.client.common_lib import error
from autotest_lib.client.common_lib import lsbrelease_utils
from autotest_lib.client.common_lib.cros import chrome
from autotest_lib.client.cros.cellular import test_environment
from autotest_lib.client.cros.update_engine import nebraska_wrapper
from autotest_lib.client.cros.update_engine import update_engine_test

class autoupdate_StartOOBEUpdate(update_engine_test.UpdateEngineTest):
    """Starts a forced update at OOBE.

    Chrome OS will restart when the update is complete so this test will just
    start the update. The rest of the processing will be done in a server
    side test.
    """
    version = 1


    def initialize(self):
        """Test setup."""
        super(autoupdate_StartOOBEUpdate, self).initialize()
        self._clear_custom_lsb_release()


    def _skip_to_oobe_update_screen(self):
        """Skips to the OOBE update check screen."""
        self._oobe.WaitForJavaScriptCondition("typeof Oobe == 'function' && "
                                              "Oobe.readyForTesting",
                                              timeout=30)
        self._oobe.ExecuteJavaScript('Oobe.skipToUpdateForTesting()')


    def _start_oobe_update(self, update_url, critical_update, full_payload):
        """
        Jump to the update check screen at OOBE and wait for update to start.

        @param update_url: The omaha update URL we expect to call.
        @param critical_update: True if the update is critical.
        @param full_payload: Whether we want the full payload or delta.

        """
        self._create_custom_lsb_release(update_url,
                                        critical_update=critical_update,
                                        full_payload=full_payload)
        # Start chrome instance to interact with OOBE.
        extra_browser_args = []
        if lsbrelease_utils.get_device_type() != 'CHROMEBOOK':
            extra_browser_args.append('--disable-hid-detection-on-oobe')
        self._chrome = chrome.Chrome(auto_login=False,
                                     extra_browser_args=extra_browser_args)
        self._oobe = self._chrome.browser.oobe
        self._skip_to_oobe_update_screen()

        timeout = 180
        err_str = 'Update did not start within %d seconds.' % timeout
        try:
            utils.poll_for_condition(self._is_update_started,
                                     error.TestFail(err_str),
                                     timeout=timeout)
        except error.TestFail as e:
            if critical_update:
                if not self._get_update_requests():
                    raise error.TestFail('%s There were no update requests in'
                                         ' update_engine.log. OOBE update'
                                         ' screen was missed.' % err_str)
                err_code = self._get_last_error_string()
                if err_code is not None:
                    raise error.TestFail('%s %s' % (err_str, err_code))
                else:
                    raise e


    def run_once(self, update_url=None, payload_url=None, cellular=False,
                 critical_update=True, full_payload=None,
                 interrupt_network=False, interrupt_progress=0.0):
        """
        Test that will start a forced update at OOBE.

        @param update_url: The omaha URL to call from the OOBE update screen.
        @param payload_url: Payload url to pass to Nebraska for non-critical
                            and cellular tests.
        @param cellular: True if we should run this test using a sim card.
        @param critical_update: True if we should have deadline:now in omaha
                                response.
        @param full_payload: Whether the payload is full or delta. None if we
                             don't have to care about it.
        @param interrupt_network: True to cause a network interruption after
                                  starting the update. Should only be used
                                  during a critical update.
        @param interrupt_progress: If interrupt_network is True, we will wait
                                   for the update progress to reach this
                                   value before interrupting. Should be
                                   expressed as a number between 0 and 1.

        """

        if critical_update and not cellular:
            self._start_oobe_update(update_url, critical_update, full_payload)
            if interrupt_network:
                self._wait_for_progress(interrupt_progress)
                self._take_screenshot(self._BEFORE_INTERRUPT_FILENAME)
                completed = self._get_update_progress()
                self._disconnect_reconnect_network_test(update_url)
                self._take_screenshot(self._AFTER_INTERRUPT_FILENAME)

                if self._is_update_engine_idle():
                    raise error.TestFail(
                        'The update was IDLE after interrupt.')
                if not self._update_continued_where_it_left_off(completed):
                    raise error.TestFail('The update did not continue where '
                                         'it left off after interruption.')

                # Remove screenshots since the interrupt test succeeded.
                self._remove_screenshots()
            return

        # Setup a Nebraska instance on the DUT for cellular tests and
        # non-critical updates. Ceullar tests cannot reach devservers.
        # Non-critical tests don't need a devserver.
        with nebraska_wrapper.NebraskaWrapper(
            log_dir=self.resultsdir, payload_url=payload_url) as nebraska:

            update_url = nebraska.get_update_url(
                critical_update=critical_update)
            if not cellular:
                self._start_oobe_update(update_url, critical_update, None)
                return

            try:
                with test_environment.CellularOTATestEnvironment() as test_env:
                    service = test_env.shill.wait_for_cellular_service_object()
                    if not service:
                        raise error.TestError('No cellular service found.')
                    connect_timeout = 120
                    test_env.shill.connect_service_synchronous(service,
                                                               connect_timeout)

                    self._start_oobe_update(update_url, critical_update, None)

                    # Remove the custom omaha server from lsb release because
                    # after we reboot it will no longer be running.
                    self._clear_custom_lsb_release()

                    # Need to return from this client test before OOBE reboots
                    # or the server test will hang. Cannot return immediately
                    # when the OOBE update starts because all code for cellular
                    # connections is client side and the test will switch to
                    # ethernet. So wait for FINALIZING so payload is downloaded
                    # via cellular and won't ping omaha again. After reboot,
                    # there is a final ping to omaha and login screen is shown.
                    self._wait_for_update_status(
                        self._UPDATE_STATUS_FINALIZING)
            except error.TestError as e:
                logging.error('Failure setting up sim card.')
                raise error.TestFail(e)
