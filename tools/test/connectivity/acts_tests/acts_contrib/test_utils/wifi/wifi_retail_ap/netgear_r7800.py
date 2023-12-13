#!/usr/bin/env python3
#
#   Copyright 2020 - The Android Open Source Project
#
#   Licensed under the Apache License, Version 2.0 (the 'License');
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an 'AS IS' BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

from acts_contrib.test_utils.wifi.wifi_retail_ap import NetgearR7500AP


class NetgearR7800AP(NetgearR7500AP):
    """Class that implements Netgear R7800 AP.

    Since most of the class' implementation is shared with the R7500, this
    class inherits from NetgearR7500AP and simply redefines config parameters
    """
    def init_gui_data(self):
        super().init_gui_data()
        # Overwrite minor differences from R7500 AP
        self.bw_mode_text_2g['VHT20'] = 'Up to 347 Mbps'
