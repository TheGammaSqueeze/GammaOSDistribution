# Copyright 2016 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import logging
import math
import time

from autotest_lib.client.common_lib import error
from autotest_lib.server.cros.faft.firmware_test import FirmwareTest
from autotest_lib.server.cros.servo import pd_device


class firmware_PDVbusRequest(FirmwareTest):
    """
    Servo based USB PD VBUS level test. This test is written to use both
    the DUT and PDTester test board. It requires that the DUT support
    dualrole (SRC or SNK) operation. VBUS change requests occur in two
    methods.

    The 1st test initiates the VBUS change by using special PDTester
    feature to send new SRC CAP message. This causes the DUT to request
    a new VBUS voltage matching what's in the SRC CAP message.

    The 2nd test configures the DUT in SNK mode and uses the pd console
    command 'pd 0/1 dev V' command where V is the desired voltage
    5/12/20. This test is more risky and won't be executed if the 1st
    test is failed. If the DUT max input voltage is not 20V, like 12V,
    and the FAFT config is set wrong, it may negotiate to a voltage
    higher than it can support, that may damage the DUT.

    Pass critera is all voltage transitions are successful.

    """
    version = 1
    PD_SETTLE_DELAY = 10
    USBC_SINK_VOLTAGE = 5
    VBUS_TOLERANCE = 0.12

    VOLTAGE_SEQUENCE = [5, 9, 10, 12, 15, 20, 15, 12, 9, 5, 20,
                        5, 5, 9, 9, 10, 10, 12, 12, 15, 15, 20]

    def _compare_vbus(self, expected_vbus_voltage, ok_to_fail):
        """Check VBUS using pdtester

        @param expected_vbus_voltage: nominal VBUS level (in volts)
        @param ok_to_fail: True to not treat voltage-not-matched as failure.

        @returns: a tuple containing pass/fail indication and logging string
        """
        # Get Vbus voltage and current
        vbus_voltage = self.pdtester.vbus_voltage
        # Compute voltage tolerance range. To handle the case where VBUS is
        # off, set the minimal tolerance to USBC_SINK_VOLTAGE * VBUS_TOLERANCE.
        tolerance = (self.VBUS_TOLERANCE * max(expected_vbus_voltage,
                                               self.USBC_SINK_VOLTAGE))
        voltage_difference = math.fabs(expected_vbus_voltage - vbus_voltage)
        result_str = 'Target = %02dV:\tAct = %.2f\tDelta = %.2f' % \
                     (expected_vbus_voltage, vbus_voltage, voltage_difference)
        # Verify that measured Vbus voltage is within expected range
        if voltage_difference > tolerance:
            result = 'ALLOWED_FAIL' if ok_to_fail else 'FAIL'
        else:
            result = 'PASS'
        return result, result_str

    def initialize(self, host, cmdline_args, flip_cc=False, dts_mode=False,
                   init_power_mode=None):
        super(firmware_PDVbusRequest, self).initialize(host, cmdline_args)
        # Only run on DUTs that can supply battery power.
        if not self._client.has_battery():
            raise error.TestNAError("DUT type does not have a battery.")
        self.setup_pdtester(flip_cc, dts_mode)
        # Only run in normal mode
        self.switcher.setup_mode('normal')
        if init_power_mode:
            # Set the DUT to suspend or shutdown mode
            self.set_ap_off_power_mode(init_power_mode)
        self.usbpd.send_command('chan 0')

    def cleanup(self):
        # Set back to the max 20V SRC mode at the end.
        self.pdtester.charge(self.pdtester.USBC_MAX_VOLTAGE)

        self.usbpd.send_command('chan 0xffffffff')
        self.restore_ap_on_power_mode()
        super(firmware_PDVbusRequest, self).cleanup()

    def run_once(self):
        """Exectue VBUS request test.

        """
        consoles = [self.usbpd, self.pdtester]
        port_partner = pd_device.PDPortPartner(consoles)

        # Identify a valid test port pair
        port_pair = port_partner.identify_pd_devices()
        if not port_pair:
            raise error.TestFail('No PD connection found!')

        for port in port_pair:
            if port.is_pdtester:
                self.pdtester_port = port
            else:
                self.dut_port = port

        dut_connect_state = self.dut_port.get_pd_state()
        logging.info('Initial DUT connect state = %s', dut_connect_state)

        if not self.dut_port.is_connected(dut_connect_state):
            raise error.TestFail("pd connection not found")

        dut_voltage_limit = self.faft_config.usbc_input_voltage_limit
        is_override = self.faft_config.charger_profile_override
        if is_override:
            logging.info('*** Custom charger profile takes over, which may '
                         'cause voltage-not-matched. It is OK to fail. *** ')

        pdtester_failures = []
        logging.info('Start PDTester initiated tests')
        charging_voltages = self.pdtester.get_charging_voltages()

        if dut_voltage_limit not in charging_voltages:
            raise error.TestError('Plugged a wrong charger to servo v4? '
                                  '%dV not in supported voltages %s.' %
                                  (dut_voltage_limit, str(charging_voltages)))

        for voltage in charging_voltages:
            logging.info('********* %r *********', voltage)
            # Set charging voltage
            self.pdtester.charge(voltage)
            # Wait for new PD contract to be established
            time.sleep(self.PD_SETTLE_DELAY)
            # Get current PDTester PD state
            pdtester_state = self.pdtester_port.get_pd_state()
            # If PDTester is in SNK mode and the DUT is in S0, the DUT should
            # source VBUS = USBC_SINK_VOLTAGE. If PDTester is in SNK mode, and
            # the DUT is not in S0, the DUT shouldn't source VBUS, which means
            # VBUS = 0.
            if self.pdtester_port.is_snk(pdtester_state):
                expected_vbus_voltage = (self.USBC_SINK_VOLTAGE
                        if self.get_power_state() == 'S0' else 0)
                ok_to_fail = False
            else:
                expected_vbus_voltage = min(voltage, dut_voltage_limit)
                ok_to_fail = is_override

            result, result_str = self._compare_vbus(expected_vbus_voltage,
                                                    ok_to_fail)
            logging.info('%s, %s', result_str, result)
            if result == 'FAIL':
                pdtester_failures.append(result_str)

        # PDTester is set back to 20V SRC mode.
        self.pdtester.charge(self.pdtester.USBC_MAX_VOLTAGE)
        time.sleep(self.PD_SETTLE_DELAY)

        if pdtester_failures:
            logging.error('PDTester voltage source cap failures')
            for fail in pdtester_failures:
                logging.error('%s', fail)
            number = len(pdtester_failures)
            raise error.TestFail('PDTester failed %d times' % number)

        # The DUT must be in SNK mode for the pd <port> dev <voltage>
        # command to have an effect.
        if not self.dut_port.is_snk():
            # DUT needs to be in SINK Mode, attempt to force change
            self.dut_port.drp_set('snk')
            time.sleep(self.PD_SETTLE_DELAY)
            if not self.dut_port.is_snk():
                raise error.TestFail("DUT not able to connect in SINK mode")

        logging.info('Start of DUT initiated tests')
        dut_failures = []
        for v in self.VOLTAGE_SEQUENCE:
            if v > dut_voltage_limit:
                logging.info('Target = %02dV: skipped, over the limit %0dV',
                             v, dut_voltage_limit)
                continue
            if v not in charging_voltages:
                logging.info('Target = %02dV: skipped, voltage unsupported, '
                             'update hdctools and servo_v4 firmware', v)
                continue
            # Build 'pd <port> dev <voltage> command
            cmd = 'pd %d dev %d' % (self.dut_port.port, v)
            self.dut_port.utils.send_pd_command(cmd)
            time.sleep(self.PD_SETTLE_DELAY)
            result, result_str = self._compare_vbus(v, ok_to_fail=is_override)
            logging.info('%s, %s', result_str, result)
            if result == 'FAIL':
                dut_failures.append(result_str)

        # Make sure DUT is set back to its max voltage so DUT will accept all
        # options
        cmd = 'pd %d dev %d' % (self.dut_port.port, dut_voltage_limit)
        self.dut_port.utils.send_pd_command(cmd)
        time.sleep(self.PD_SETTLE_DELAY)
        # The next group of tests need DUT to connect in SNK and SRC modes
        self.dut_port.drp_set('on')

        if dut_failures:
            logging.error('DUT voltage request failures')
            for fail in dut_failures:
                logging.error('%s', fail)
            number = len(dut_failures)
            raise error.TestFail('DUT failed %d times' % number)
