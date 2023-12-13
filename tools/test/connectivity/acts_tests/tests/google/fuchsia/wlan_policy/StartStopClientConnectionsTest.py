#!/usr/bin/env python3
#
#   Copyright 2020 - The Android Open Source Project
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

from acts import signals
from acts.controllers.access_point import setup_ap
from acts.controllers.ap_lib import hostapd_constants
from acts.controllers.ap_lib import hostapd_security
from acts_contrib.test_utils.wifi.WifiBaseTest import WifiBaseTest
from acts.utils import rand_ascii_str

DISCONNECTED = "Disconnected"
CONNECTION_STOPPED = "ConnectionStopped"
CONNECTIONS_ENABLED = "ConnectionsEnabled"
CONNECTIONS_DISABLED = "ConnectionsDisabled"
WPA2 = "wpa2"


class StartStopClientConnectionsTest(WifiBaseTest):
    """ Tests that we see the expected behavior with enabling and disabling
        client connections

    Test Bed Requirement:
    * One or more Fuchsia devices
    * One Access Point
    """
    def setup_class(self):
        super().setup_class()
        # Start an AP with a hidden network
        self.ssid = rand_ascii_str(hostapd_constants.AP_SSID_LENGTH_2G)
        self.access_point = self.access_points[0]
        self.password = rand_ascii_str(
            hostapd_constants.AP_PASSPHRASE_LENGTH_2G)
        self.security_type = WPA2
        security = hostapd_security.Security(security_mode=self.security_type,
                                             password=self.password)

        self.access_point.stop_all_aps()
        # TODO(63719) use varying values for AP that shouldn't affect the test.
        setup_ap(self.access_point,
                 'whirlwind',
                 hostapd_constants.AP_DEFAULT_CHANNEL_5G,
                 self.ssid,
                 security=security)

        if len(self.fuchsia_devices) < 1:
            raise EnvironmentError("No Fuchsia devices found.")
        for fd in self.fuchsia_devices:
            fd.configure_wlan(association_mechanism='policy',
                              preserve_saved_networks=True)

    def setup_test(self):
        for fd in self.fuchsia_devices:
            if not fd.wlan_policy_controller.remove_all_networks():
                raise EnvironmentError(
                    "Failed to remove all networks in setup")

    def teardown_class(self):
        self.access_point.stop_all_aps()

    def connect_and_validate(self, fd, ssid, security_type, expected_response):
        """ Sends a connect request to the device and verifies we get a response
            without error. This does not validate that a connection will be
            attempted. This will fail the test if there is an error sending the
            connect request, or if we don't get the expected connect response."""
        result_connect = fd.wlan_policy_lib.wlanConnect(ssid, security_type)
        if result_connect.get("error") != None:
            self.log.error("Error occurred requesting a connection: %s" %
                           result_connect.get("error"))
            raise EnvironmentError("Failed to send connect request")
        response = result_connect.get("result")
        if response != expected_response:
            self.log.error(
                "Incorrect connect request response. Expected: \"%s\", Actual: %s"
                % (expected_response, response))
            raise signals.TestFailure(
                "Failed to get expected connect response")

    def test_stop_client_connections_update(self):
        for fd in self.fuchsia_devices:
            if not fd.wlan_policy_controller.stop_client_connections():
                raise EnvironmentError("Failed to stop client connecions")

            # Check that the most recent update says that the device is not
            # connected to anything and client connections are disabled
            fd.wlan_policy_lib.wlanSetNewListener()
            result_update = fd.wlan_policy_lib.wlanGetUpdate()
            if result_update.get("error") != None:
                self.log.error("Error occurred getting status update: %s" %
                               result_update.get("error"))
                raise EnvironmentError("Failed to get update")

            expected_update = {"networks": [], "state": CONNECTIONS_DISABLED}
            if result_update.get("result") != expected_update:
                self.log.error(
                    "Most recent status update does not indicate client "
                    "connections have stopped. Expected update: %s Actual update: %s"
                    % (expected_update, result_update.get('result')))
                raise signals.TestFailure(
                    "Incorrect update after stopping client connections")

    def test_start_client_connections_update(self):
        for fd in self.fuchsia_devices:
            if not fd.wlan_policy_controller.start_client_connections():
                raise EnvironmentError("Failed to start client connecions")

            # Check that the most recent update says that the device is not
            # connected to anything and client connections are disabled
            fd.wlan_policy_lib.wlanSetNewListener()
            result_update = fd.wlan_policy_lib.wlanGetUpdate()
            if result_update.get("error") != None:
                self.log.error("Error occurred getting status update: %s" %
                               result_update.get("error"))
                raise EnvironmentError("Failed to get update")

            expected_update = {"networks": [], "state": CONNECTIONS_ENABLED}
            if result_update.get("result") != expected_update:
                self.log.error(
                    "Most recent status update does not indicate client "
                    "connections are enabled. Expected update: %s\nActual update:"
                    % (expected_update, result_update))
                raise signals.TestFailure(
                    "Incorrect update after starting client connections")

    def test_stop_client_connections_rejects_connections(self):
        # Test that if we turn client connections off, our requests to connect
        # are rejected.
        for fd in self.fuchsia_devices:
            if not fd.wlan_policy_controller.stop_client_connections():
                raise EnvironmentError("Failed to stop client connecions")

            # Save the network, otherwise connecting may fail because the
            # network is not saved instead of client connections being off
            if not fd.wlan_policy_controller.save_network(
                    self.ssid, self.security_type, password=self.password):
                raise EnvironmentError("Failed to save network")
            expected_response = "RejectedIncompatibleMode"
            self.connect_and_validate(fd, self.ssid, self.security_type,
                                      expected_response)

    def test_start_stop_client_connections(self):
        # Test that if we turn client connections on the device will connect,
        # and if we turn of client connections the device will disconnect.
        for fd in self.fuchsia_devices:
            # Start client connections and check that we can
            if not fd.wlan_policy_controller.save_network(
                    self.ssid, self.security_type, password=self.password):
                raise EnvironmentError("Failed to save network")
            if not fd.wlan_policy_controller.start_client_connections():
                raise EnvironmentError("Failed to start client connections")

            expected_response = "Acknowledged"
            self.connect_and_validate(fd, self.ssid, self.security_type,
                                      expected_response)

            if not fd.wlan_policy_controller.wait_for_connect(
                    self.ssid, self.security_type):
                raise signals.TestFailure(
                    "Failed to connect after starting client connections")

            # Stop client connections again and check that we disconnect
            if not fd.wlan_policy_controller.stop_client_connections():
                raise EnvironmentError("Failed to stop client connecions")
            if not fd.wlan_policy_controller.wait_for_disconnect(
                    self.ssid, self.security_type, DISCONNECTED,
                    CONNECTION_STOPPED):
                raise signals.TestFailure(
                    "Failed to disconnect after client connections stopped")
