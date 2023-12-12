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

import collections
import selenium
import time
from acts_contrib.test_utils.wifi.wifi_retail_ap import WifiRetailAP
from acts_contrib.test_utils.wifi.wifi_retail_ap import BlockingBrowser

BROWSER_WAIT_SHORT = 1
BROWSER_WAIT_MED = 3
BROWSER_WAIT_LONG = 30
BROWSER_WAIT_EXTRA_LONG = 60


class NetgearRAX200AP(WifiRetailAP):
    """Class that implements Netgear RAX200 AP.

    Since most of the class' implementation is shared with the R7000, this
    class inherits from NetgearR7000AP and simply redefines config parameters
    """
    def __init__(self, ap_settings):
        super().__init__(ap_settings)
        self.init_gui_data()
        # Read and update AP settings
        self.read_ap_settings()
        self.update_ap_settings(ap_settings)

    def init_gui_data(self):
        self.config_page = (
            '{protocol}://{username}:{password}@'
            '{ip_address}:{port}/WLG_wireless_tri_band.htm').format(
                protocol=self.ap_settings['protocol'],
                username=self.ap_settings['admin_username'],
                password=self.ap_settings['admin_password'],
                ip_address=self.ap_settings['ip_address'],
                port=self.ap_settings['port'])
        self.config_page_nologin = (
            '{protocol}://{ip_address}:{port}/'
            'WLG_wireless_tri_band.htm').format(
                protocol=self.ap_settings['protocol'],
                ip_address=self.ap_settings['ip_address'],
                port=self.ap_settings['port'])
        self.config_page_advanced = (
            '{protocol}://{username}:{password}@'
            '{ip_address}:{port}/WLG_adv_tri_band2.htm').format(
                protocol=self.ap_settings['protocol'],
                username=self.ap_settings['admin_username'],
                password=self.ap_settings['admin_password'],
                ip_address=self.ap_settings['ip_address'],
                port=self.ap_settings['port'])
        self.capabilities = {
            'interfaces': ['2G', '5G_1', '5G_2'],
            'channels': {
                '2G': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11],
                '5G_1': [36, 40, 44, 48, 52, 56, 60, 64],
                '5G_2': [
                    100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144,
                    149, 153, 157, 161, 165
                ]
            },
            'modes': {
                '2G': ['VHT20', 'VHT40', 'HE20', 'HE40'],
                '5G_1': [
                    'VHT20', 'VHT40', 'VHT80', 'VHT160', 'HE20', 'HE40',
                    'HE80', 'HE160'
                ],
                '5G_2': [
                    'VHT20', 'VHT40', 'VHT80', 'VHT160', 'HE20', 'HE40',
                    'HE80', 'HE160'
                ]
            },
            'default_mode': 'HE'
        }
        for interface in self.capabilities['interfaces']:
            self.ap_settings[interface] = {}

        self.region_map = {
            '3': 'Australia',
            '4': 'Canada',
            '5': 'Europe',
            '7': 'Japan',
            '8': 'Korea',
            '11': 'North America',
            '16': 'China',
            '17': 'India',
            '21': 'Middle East(Saudi Arabia/United Arab Emirates)',
            '23': 'Singapore',
            '25': 'Hong Kong',
            '26': 'Vietnam'
        }

        self.bw_mode_text = {
            '2G': {
                '11g': 'Up to 54 Mbps',
                'HE20': 'Up to 600 Mbps',
                'HE40': 'Up to 1200 Mbps',
                'VHT20': 'Up to 433 Mbps',
                'VHT40': 'Up to 1000 Mbps'
            },
            '5G_1': {
                'HE20': 'Up to 600 Mbps',
                'HE40': 'Up to 1200 Mbps',
                'HE80': 'Up to 2400 Mbps',
                'HE160': 'Up to 4800 Mbps',
                'VHT20': 'Up to 433 Mbps',
                'VHT40': 'Up to 1000 Mbps',
                'VHT80': 'Up to 2165 Mbps',
                'VHT160': 'Up to 4330'
            },
            '5G_2': {
                'HE20': 'Up to 600 Mbps',
                'HE40': 'Up to 1200 Mbps',
                'HE80': 'Up to 2400 Mbps',
                'HE160': 'Up to 4800 Mbps',
                'VHT20': 'Up to 433 Mbps',
                'VHT40': 'Up to 1000 Mbps',
                'VHT80': 'Up to 2165 Mbps',
                'VHT160': 'Up to 4330'
            }
        }
        self.bw_mode_values = {
            # first key is a boolean indicating if 11ax is enabled
            0: {
                'g and b': '11g',
                '145Mbps': 'VHT20',
                '300Mbps': 'VHT40',
                'HT80': 'VHT80',
                'HT160': 'VHT160'
            },
            1: {
                'g and b': '11g',
                '145Mbps': 'HE20',
                '300Mbps': 'HE40',
                'HT80': 'HE80',
                'HT160': 'HE160'
            }
        }

        # Config ordering intentional to avoid GUI bugs
        self.config_page_fields = collections.OrderedDict([
            ('region', 'WRegion'), ('enable_ax', 'enable_he'),
            (('2G', 'status'), 'enable_ap'),
            (('5G_1', 'status'), 'enable_ap_an'),
            (('5G_2', 'status'), 'enable_ap_an_2'), (('2G', 'ssid'), 'ssid'),
            (('5G_1', 'ssid'), 'ssid_an'), (('5G_2', 'ssid'), 'ssid_an_2'),
            (('2G', 'channel'), 'w_channel'),
            (('5G_1', 'channel'), 'w_channel_an'),
            (('5G_2', 'channel'), 'w_channel_an_2'),
            (('2G', 'bandwidth'), 'opmode'),
            (('5G_1', 'bandwidth'), 'opmode_an'),
            (('5G_2', 'bandwidth'), 'opmode_an_2'),
            (('2G', 'power'), 'enable_tpc'),
            (('5G_1', 'power'), 'enable_tpc_an'),
            (('5G_2', 'power'), 'enable_tpc_an_2'),
            (('5G_2', 'security_type'), 'security_type_an_2'),
            (('5G_1', 'security_type'), 'security_type_an'),
            (('2G', 'security_type'), 'security_type'),
            (('2G', 'password'), 'passphrase'),
            (('5G_1', 'password'), 'passphrase_an'),
            (('5G_2', 'password'), 'passphrase_an_2')
        ])

        self.power_mode_values = {
            '1': '100%',
            '2': '75%',
            '3': '50%',
            '4': '25%'
        }

    def set_bandwidth(self, network, bandwidth):
        """Function that sets network bandwidth/mode.

        Args:
            network: string containing network identifier (2G, 5G_1, 5G_2)
            bandwidth: string containing mode, e.g. 11g, VHT20, VHT40, VHT80.
        """
        if 'bw' in bandwidth:
            bandwidth = bandwidth.replace('bw',
                                          self.capabilities['default_mode'])
        if bandwidth not in self.capabilities['modes'][network]:
            self.log.error('{} mode is not supported on {} interface.'.format(
                bandwidth, network))
        setting_to_update = {network: {'bandwidth': str(bandwidth)}}
        setting_to_update['enable_ax'] = int('HE' in bandwidth)
        # Check if other interfaces need to be changed too
        requested_mode = 'HE' if 'HE' in bandwidth else 'VHT'
        for other_network in self.capabilities['interfaces']:
            if other_network == network:
                continue
            other_mode = 'HE' if 'HE' in self.ap_settings[other_network][
                'bandwidth'] else 'VHT'
            other_bw = ''.join([
                x for x in self.ap_settings[other_network]['bandwidth']
                if x.isdigit()
            ])
            if other_mode != requested_mode:
                updated_mode = '{}{}'.format(requested_mode, other_bw)
                self.log.warning('All networks must be VHT or HE. '
                                 'Updating {} to {}'.format(
                                     other_network, updated_mode))
                setting_to_update.setdefault(other_network, {})
                setting_to_update[other_network]['bandwidth'] = updated_mode

        self.update_ap_settings(setting_to_update)

    def read_ap_settings(self):
        """Function to read ap settings."""
        with BlockingBrowser(self.ap_settings['headless_browser'],
                             900) as browser:
            # Visit URL
            browser.visit_persistent(self.config_page, BROWSER_WAIT_MED, 10)

            for key, value in self.config_page_fields.items():
                if 'status' in key:
                    browser.visit_persistent(self.config_page_advanced,
                                             BROWSER_WAIT_MED, 10)
                    config_item = browser.find_by_name(value)
                    self.ap_settings[key[0]][key[1]] = int(
                        config_item.first.checked)
                    browser.visit_persistent(self.config_page,
                                             BROWSER_WAIT_MED, 10)
                else:
                    config_item = browser.find_by_name(value)
                    if 'enable_ax' in key:
                        self.ap_settings[key] = int(config_item.first.checked)
                    elif 'bandwidth' in key:
                        self.ap_settings[key[0]][key[1]] = self.bw_mode_values[
                            self.ap_settings['enable_ax']][
                                config_item.first.value]
                    elif 'power' in key:
                        self.ap_settings[key[0]][
                            key[1]] = self.power_mode_values[
                                config_item.first.value]
                    elif 'region' in key:
                        self.ap_settings['region'] = self.region_map[
                            config_item.first.value]
                    elif 'security_type' in key:
                        for item in config_item:
                            if item.checked:
                                self.ap_settings[key[0]][key[1]] = item.value
                    else:
                        config_item = browser.find_by_name(value)
                        self.ap_settings[key[0]][
                            key[1]] = config_item.first.value
        return self.ap_settings.copy()

    def configure_ap(self, **config_flags):
        """Function to configure ap wireless settings."""
        # Turn radios on or off
        if config_flags['status_toggled']:
            self.configure_radio_on_off()
        # Configure radios
        with BlockingBrowser(self.ap_settings['headless_browser'],
                             900) as browser:
            # Visit URL
            browser.visit_persistent(self.config_page, BROWSER_WAIT_MED, 10)
            browser.visit_persistent(self.config_page_nologin,
                                     BROWSER_WAIT_MED, 10, self.config_page)

            # Update region, and power/bandwidth for each network
            try:
                config_item = browser.find_by_name(
                    self.config_page_fields['region']).first
                config_item.select_by_text(self.ap_settings['region'])
            except:
                self.log.warning('Cannot change region.')
            for key, value in self.config_page_fields.items():
                if 'enable_ax' in key:
                    config_item = browser.find_by_name(value).first
                    if self.ap_settings['enable_ax']:
                        config_item.check()
                    else:
                        config_item.uncheck()
                if 'power' in key:
                    config_item = browser.find_by_name(value).first
                    config_item.select_by_text(
                        self.ap_settings[key[0]][key[1]])
                elif 'bandwidth' in key:
                    config_item = browser.find_by_name(value).first
                    try:
                        config_item.select_by_text(self.bw_mode_text[key[0]][
                            self.ap_settings[key[0]][key[1]]])
                    except AttributeError:
                        self.log.warning(
                            'Cannot select bandwidth. Keeping AP default.')

            # Update security settings (passwords updated only if applicable)
            for key, value in self.config_page_fields.items():
                if 'security_type' in key:
                    browser.choose(value, self.ap_settings[key[0]][key[1]])
                    if 'WPA' in self.ap_settings[key[0]][key[1]]:
                        config_item = browser.find_by_name(
                            self.config_page_fields[(key[0],
                                                     'password')]).first
                        config_item.fill(self.ap_settings[key[0]]['password'])

            for key, value in self.config_page_fields.items():
                if 'ssid' in key:
                    config_item = browser.find_by_name(value).first
                    config_item.fill(self.ap_settings[key[0]][key[1]])
                elif 'channel' in key:
                    config_item = browser.find_by_name(value).first
                    try:
                        config_item.select(self.ap_settings[key[0]][key[1]])
                        time.sleep(BROWSER_WAIT_SHORT)
                    except AttributeError:
                        self.log.warning(
                            'Cannot select channel. Keeping AP default.')
                    try:
                        alert = browser.get_alert()
                        alert.accept()
                    except:
                        pass
            time.sleep(BROWSER_WAIT_SHORT)
            browser.find_by_name('Apply').first.click()
            time.sleep(BROWSER_WAIT_SHORT)
            try:
                alert = browser.get_alert()
                alert.accept()
                time.sleep(BROWSER_WAIT_SHORT)
            except:
                time.sleep(BROWSER_WAIT_SHORT)
            browser.visit_persistent(self.config_page, BROWSER_WAIT_EXTRA_LONG,
                                     10)
        self.validate_ap_settings()

    def configure_radio_on_off(self):
        """Helper configuration function to turn radios on/off."""
        with BlockingBrowser(self.ap_settings['headless_browser'],
                             900) as browser:
            # Visit URL
            browser.visit_persistent(self.config_page, BROWSER_WAIT_MED, 10)
            browser.visit_persistent(self.config_page_advanced,
                                     BROWSER_WAIT_MED, 10)

            # Turn radios on or off
            for key, value in self.config_page_fields.items():
                if 'status' in key:
                    config_item = browser.find_by_name(value).first
                    if self.ap_settings[key[0]][key[1]]:
                        config_item.check()
                    else:
                        config_item.uncheck()

            time.sleep(BROWSER_WAIT_SHORT)
            browser.find_by_name('Apply').first.click()
            time.sleep(BROWSER_WAIT_EXTRA_LONG)
            browser.visit_persistent(self.config_page, BROWSER_WAIT_EXTRA_LONG,
                                     10)
