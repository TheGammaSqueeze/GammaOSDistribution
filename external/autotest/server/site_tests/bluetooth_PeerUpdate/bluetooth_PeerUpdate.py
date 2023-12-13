# Copyright 2019 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
"""
Test which updates chameleond on the Bluetooth Peer device

This is not a test per se. This 'test' checks if the chameleond commit on the
Bluetooth peer device and updates it if it below the expected value.

The expected commit and the installation bundle is downloaded from google cloud
storage.
"""

from autotest_lib.client.common_lib import error
from autotest_lib.server import test
from autotest_lib.server.cros.bluetooth import bluetooth_peer_update

class bluetooth_PeerUpdate(test.test):
    """
    This test updates chameleond on Bluetooth peer devices

    """

    version = 1

    def run_once(self, host, btpeer_args=[]):
        """ Update Bluetooth peer device

        @param host: the DUT, usually a chromebook
        """
        try:
            self.host = host
            self.host.initialize_btpeer(btpeer_args=btpeer_args)
            commit = None
            (_, commit) = bluetooth_peer_update.get_latest_commit()
            if commit is None:
                raise error.TestFail('Unable to get current commit')
            if not bluetooth_peer_update.download_installation_files(self.host,
                                                                     commit):
                raise error.TestFail('Unable to download installation files ')
            bluetooth_peer_update.update_peers(self.host, commit)
        finally:
            if not bluetooth_peer_update.cleanup(host, commit):
                raise error.TestFail('Cleanup failed')
