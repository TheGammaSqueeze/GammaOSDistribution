#!/usr/bin/env python3
#
#   Copyright 2019 - The Android Open Source Project
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

from datetime import timedelta
import logging

from cert.captures import HalCaptures, HciCaptures
from cert.gd_base_test import GdBaseTestClass
from cert.matchers import HciMatchers
from cert.py_hal import PyHal
from cert.py_hci import PyHci
from cert.truth import assertThat
from hci.facade import hci_facade_pb2 as hci_facade
from facade import common_pb2 as common
from bluetooth_packets_python3.hci_packets import EventCode
from bluetooth_packets_python3.hci_packets import LoopbackMode
from bluetooth_packets_python3.hci_packets import WriteLoopbackModeBuilder
from bluetooth_packets_python3.hci_packets import ReadLocalNameBuilder
from bluetooth_packets_python3.hci_packets import WriteScanEnableBuilder
from bluetooth_packets_python3.hci_packets import ScanEnable
from bluetooth_packets_python3.hci_packets import InquiryBuilder
from bluetooth_packets_python3.hci_packets import SubeventCode
from bluetooth_packets_python3.hci_packets import LeSetRandomAddressBuilder
from bluetooth_packets_python3.hci_packets import PhyScanParameters
from bluetooth_packets_python3.hci_packets import LeScanType
from bluetooth_packets_python3.hci_packets import LeSetExtendedScanParametersBuilder
from bluetooth_packets_python3.hci_packets import OwnAddressType
from bluetooth_packets_python3.hci_packets import LeScanningFilterPolicy
from bluetooth_packets_python3.hci_packets import Enable
from bluetooth_packets_python3.hci_packets import FilterDuplicates
from bluetooth_packets_python3.hci_packets import LeSetExtendedAdvertisingLegacyParametersBuilder
from bluetooth_packets_python3.hci_packets import LegacyAdvertisingProperties
from bluetooth_packets_python3.hci_packets import PeerAddressType
from bluetooth_packets_python3.hci_packets import AdvertisingFilterPolicy
from bluetooth_packets_python3.hci_packets import LeSetExtendedAdvertisingRandomAddressBuilder
from bluetooth_packets_python3.hci_packets import GapData
from bluetooth_packets_python3.hci_packets import GapDataType
from bluetooth_packets_python3.hci_packets import LeSetExtendedAdvertisingDataBuilder
from bluetooth_packets_python3.hci_packets import Operation
from bluetooth_packets_python3.hci_packets import FragmentPreference
from bluetooth_packets_python3.hci_packets import LeSetExtendedAdvertisingScanResponseBuilder
from bluetooth_packets_python3.hci_packets import LeSetExtendedAdvertisingEnableBuilder
from bluetooth_packets_python3.hci_packets import LeSetExtendedScanEnableBuilder
from bluetooth_packets_python3.hci_packets import EnabledSet
from bluetooth_packets_python3.hci_packets import LeCreateConnPhyScanParameters
from bluetooth_packets_python3.hci_packets import LeExtendedCreateConnectionBuilder
from bluetooth_packets_python3.hci_packets import InitiatorFilterPolicy
from bluetooth_packets_python3.hci_packets import AddressType
from bluetooth_packets_python3.hci_packets import BroadcastFlag
from bluetooth_packets_python3.hci_packets import ConnectListAddressType
from bluetooth_packets_python3.hci_packets import LeAddDeviceToConnectListBuilder
from bluetooth_packets_python3.hci_packets import LeSetRandomAddressBuilder
from bluetooth_packets_python3.hci_packets import LeReadRemoteFeaturesBuilder
from bluetooth_packets_python3.hci_packets import WritePageTimeoutBuilder
from bluetooth_packets_python3.hci_packets import ReadBdAddrBuilder
from bluetooth_packets_python3.hci_packets import CreateConnectionBuilder
from bluetooth_packets_python3.hci_packets import PageScanRepetitionMode
from bluetooth_packets_python3.hci_packets import ClockOffsetValid
from bluetooth_packets_python3.hci_packets import CreateConnectionRoleSwitch
from bluetooth_packets_python3.hci_packets import AcceptConnectionRequestBuilder
from bluetooth_packets_python3.hci_packets import AcceptConnectionRequestRole
from bluetooth_packets_python3.hci_packets import PacketBoundaryFlag
from bluetooth_packets_python3.hci_packets import ResetBuilder
from bluetooth_packets_python3.hci_packets import Lap
from bluetooth_packets_python3.hci_packets import OpCode
from bluetooth_packets_python3.hci_packets import AclBuilder
from bluetooth_packets_python3 import RawBuilder


class DirectHciTest(GdBaseTestClass):

    def setup_class(self):
        super().setup_class(dut_module='HCI', cert_module='HAL')

    def setup_test(self):
        super().setup_test()
        self.dut_hci = PyHci(self.dut, acl_streaming=True)
        self.cert_hal = PyHal(self.cert)
        self.cert_hal.send_hci_command(ResetBuilder())

    def teardown_test(self):
        self.dut_hci.close()
        self.cert_hal.close()
        super().teardown_test()

    def enqueue_acl_data(self, handle, pb_flag, b_flag, data):
        acl = AclBuilder(handle, pb_flag, b_flag, RawBuilder(data))
        self.dut.hci.SendAcl(common.Data(payload=bytes(acl.Serialize())))

    def test_local_hci_cmd_and_event(self):
        # Loopback mode responds with ACL and SCO connection complete
        self.dut_hci.register_for_events(EventCode.LOOPBACK_COMMAND)
        self.dut_hci.send_command(WriteLoopbackModeBuilder(LoopbackMode.ENABLE_LOCAL))

        self.dut_hci.send_command(ReadLocalNameBuilder())
        assertThat(self.dut_hci.get_event_stream()).emits(HciMatchers.LoopbackOf(ReadLocalNameBuilder()))

    def test_inquiry_from_dut(self):
        self.dut_hci.register_for_events(EventCode.INQUIRY_RESULT)

        self.cert_hal.enable_inquiry_and_page_scan()
        lap = Lap()
        lap.lap = 0x33
        self.dut_hci.send_command(InquiryBuilder(lap, 0x30, 0xff))
        assertThat(self.dut_hci.get_event_stream()).emits(HciMatchers.EventWithCode(EventCode.INQUIRY_RESULT))

    def test_le_ad_scan_cert_advertises(self):
        self.dut_hci.register_for_le_events(SubeventCode.EXTENDED_ADVERTISING_REPORT, SubeventCode.ADVERTISING_REPORT)

        # DUT Scans
        self.dut_hci.send_command(LeSetRandomAddressBuilder('0D:05:04:03:02:01'))
        phy_scan_params = PhyScanParameters()
        phy_scan_params.le_scan_interval = 6553
        phy_scan_params.le_scan_window = 6553
        phy_scan_params.le_scan_type = LeScanType.ACTIVE

        self.dut_hci.send_command(
            LeSetExtendedScanParametersBuilder(OwnAddressType.RANDOM_DEVICE_ADDRESS, LeScanningFilterPolicy.ACCEPT_ALL,
                                               1, [phy_scan_params]))
        self.dut_hci.send_command(LeSetExtendedScanEnableBuilder(Enable.ENABLED, FilterDuplicates.DISABLED, 0, 0))

        # CERT Advertises
        advertising_handle = 0
        self.cert_hal.send_hci_command(
            LeSetExtendedAdvertisingLegacyParametersBuilder(
                advertising_handle,
                LegacyAdvertisingProperties.ADV_IND,
                512,
                768,
                7,
                OwnAddressType.RANDOM_DEVICE_ADDRESS,
                PeerAddressType.PUBLIC_DEVICE_OR_IDENTITY_ADDRESS,
                'A6:A5:A4:A3:A2:A1',
                AdvertisingFilterPolicy.ALL_DEVICES,
                0xF7,
                1,  # SID
                Enable.DISABLED  # Scan request notification
            ))

        self.cert_hal.send_hci_command(
            LeSetExtendedAdvertisingRandomAddressBuilder(advertising_handle, '0C:05:04:03:02:01'))
        gap_name = GapData()
        gap_name.data_type = GapDataType.COMPLETE_LOCAL_NAME
        gap_name.data = list(bytes(b'Im_A_Cert'))

        self.cert_hal.send_hci_command(
            LeSetExtendedAdvertisingDataBuilder(advertising_handle, Operation.COMPLETE_ADVERTISEMENT,
                                                FragmentPreference.CONTROLLER_SHOULD_NOT, [gap_name]))

        gap_short_name = GapData()
        gap_short_name.data_type = GapDataType.SHORTENED_LOCAL_NAME
        gap_short_name.data = list(bytes(b'Im_A_C'))

        self.cert_hal.send_hci_command(
            LeSetExtendedAdvertisingScanResponseBuilder(advertising_handle, Operation.COMPLETE_ADVERTISEMENT,
                                                        FragmentPreference.CONTROLLER_SHOULD_NOT, [gap_short_name]))

        enabled_set = EnabledSet()
        enabled_set.advertising_handle = 0
        enabled_set.duration = 0
        enabled_set.max_extended_advertising_events = 0
        self.cert_hal.send_hci_command(LeSetExtendedAdvertisingEnableBuilder(Enable.ENABLED, [enabled_set]))

        assertThat(self.dut_hci.get_le_event_stream()).emits(lambda packet: b'Im_A_Cert' in packet.payload)

        self.cert_hal.send_hci_command(LeSetExtendedAdvertisingEnableBuilder(Enable.DISABLED, [enabled_set]))
        self.dut_hci.send_command(LeSetExtendedScanEnableBuilder(Enable.DISABLED, FilterDuplicates.DISABLED, 0, 0))

    def _verify_le_connection_complete(self):
        cert_conn_complete_capture = HalCaptures.LeConnectionCompleteCapture()
        assertThat(self.cert_hal.get_hci_event_stream()).emits(cert_conn_complete_capture)
        cert_handle = cert_conn_complete_capture.get().GetConnectionHandle()

        dut_conn_complete_capture = HciCaptures.LeConnectionCompleteCapture()
        assertThat(self.dut_hci.get_le_event_stream()).emits(dut_conn_complete_capture)
        dut_handle = dut_conn_complete_capture.get().GetConnectionHandle()

        return (dut_handle, cert_handle)

    @staticmethod
    def _create_phy_scan_params():
        phy_scan_params = LeCreateConnPhyScanParameters()
        phy_scan_params.scan_interval = 0x60
        phy_scan_params.scan_window = 0x30
        phy_scan_params.conn_interval_min = 0x18
        phy_scan_params.conn_interval_max = 0x28
        phy_scan_params.conn_latency = 0
        phy_scan_params.supervision_timeout = 0x1f4
        phy_scan_params.min_ce_length = 0
        phy_scan_params.max_ce_length = 0
        return phy_scan_params

    def test_le_connection_dut_advertises(self):
        self.dut_hci.register_for_le_events(SubeventCode.CONNECTION_COMPLETE, SubeventCode.ADVERTISING_SET_TERMINATED,
                                            SubeventCode.ENHANCED_CONNECTION_COMPLETE,
                                            SubeventCode.READ_REMOTE_FEATURES_COMPLETE)
        # Cert Connects
        self.cert_hal.send_hci_command(LeSetRandomAddressBuilder('0C:05:04:03:02:01'))
        phy_scan_params = DirectHciTest._create_phy_scan_params()
        self.cert_hal.send_hci_command(
            LeExtendedCreateConnectionBuilder(InitiatorFilterPolicy.USE_PEER_ADDRESS,
                                              OwnAddressType.RANDOM_DEVICE_ADDRESS, AddressType.RANDOM_DEVICE_ADDRESS,
                                              '0D:05:04:03:02:01', 1, [phy_scan_params]))

        advertisement = self.dut_hci.create_advertisement(0, '0D:05:04:03:02:01')
        advertisement.set_data(b'Im_The_DUT')
        advertisement.set_scan_response(b'Im_The_D')
        advertisement.start()

        (dut_handle, cert_handle) = self._verify_le_connection_complete()

        self.dut_hci.send_command(LeReadRemoteFeaturesBuilder(dut_handle))
        assertThat(self.dut_hci.get_le_event_stream()).emits(
            lambda packet: packet.payload[0] == int(EventCode.LE_META_EVENT) and packet.payload[2] == int(SubeventCode.READ_REMOTE_FEATURES_COMPLETE)
        )

        # Send ACL Data
        self.enqueue_acl_data(dut_handle, PacketBoundaryFlag.FIRST_NON_AUTOMATICALLY_FLUSHABLE,
                              BroadcastFlag.POINT_TO_POINT, bytes(b'Just SomeAclData'))
        self.cert_hal.send_acl_first(cert_handle, bytes(b'Just SomeMoreAclData'))

        assertThat(self.cert_hal.get_acl_stream()).emits(
            lambda packet: logging.debug(packet.payload) or b'SomeAclData' in packet.payload)
        assertThat(self.dut_hci.get_raw_acl_stream()).emits(
            lambda packet: logging.debug(packet.payload) or b'SomeMoreAclData' in packet.payload)

    def test_le_connect_list_connection_cert_advertises(self):
        self.dut_hci.register_for_le_events(SubeventCode.CONNECTION_COMPLETE, SubeventCode.ENHANCED_CONNECTION_COMPLETE)
        # DUT Connects
        self.dut_hci.send_command(LeSetRandomAddressBuilder('0D:05:04:03:02:01'))
        self.dut_hci.send_command(LeAddDeviceToConnectListBuilder(ConnectListAddressType.RANDOM, '0C:05:04:03:02:01'))
        phy_scan_params = DirectHciTest._create_phy_scan_params()
        self.dut_hci.send_command(
            LeExtendedCreateConnectionBuilder(InitiatorFilterPolicy.USE_CONNECT_LIST,
                                              OwnAddressType.RANDOM_DEVICE_ADDRESS, AddressType.RANDOM_DEVICE_ADDRESS,
                                              'BA:D5:A4:A3:A2:A1', 1, [phy_scan_params]))

        advertisement = self.cert_hal.create_advertisement(
            1,
            '0C:05:04:03:02:01',
            min_interval=512,
            max_interval=768,
            peer_address='A6:A5:A4:A3:A2:A1',
            tx_power=0x7f,
            sid=0)
        advertisement.set_data(b'Im_A_Cert')
        advertisement.start()

        # LeConnectionComplete
        self._verify_le_connection_complete()

    def test_connection_dut_connects(self):
        self.dut_hci.send_command(WritePageTimeoutBuilder(0x4000))

        self.cert_hal.enable_inquiry_and_page_scan()
        address = self.cert_hal.read_own_address()

        self.dut_hci.initiate_connection(address)
        cert_acl = self.cert_hal.accept_connection()
        dut_acl = self.dut_hci.complete_connection()

        # Send ACL Data
        dut_acl.send_first(b'Just SomeAclData')
        cert_acl.send_first(b'Just SomeMoreAclData')

        assertThat(self.cert_hal.get_acl_stream()).emits(lambda packet: b'SomeAclData' in packet.payload)
        assertThat(self.dut_hci.get_raw_acl_stream()).emits(lambda packet: b'SomeMoreAclData' in packet.payload)

    def test_connection_cert_connects(self):
        self.cert_hal.send_hci_command(WritePageTimeoutBuilder(0x4000))

        self.dut_hci.enable_inquiry_and_page_scan()
        address = self.dut_hci.read_own_address()

        self.cert_hal.initiate_connection(address)
        dut_acl = self.dut_hci.accept_connection()
        cert_acl = self.cert_hal.complete_connection()

        # Send ACL Data
        dut_acl.send_first(b'This is just SomeAclData')
        cert_acl.send_first(b'This is just SomeMoreAclData')

        assertThat(self.cert_hal.get_acl_stream()).emits(lambda packet: b'SomeAclData' in packet.payload)
        assertThat(self.dut_hci.get_raw_acl_stream()).emits(lambda packet: b'SomeMoreAclData' in packet.payload)
