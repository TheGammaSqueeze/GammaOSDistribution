#!/usr/bin/env python3
#
#   Copyright 2021 - The Android Open Source Project
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
import time
import json

from acts import base_test

import acts.controllers.cellular_simulator as simulator
from acts.controllers.anritsu_lib import md8475_cellular_simulator as anritsu
from acts.controllers.rohdeschwarz_lib import cmw500_cellular_simulator as cmw
from acts.controllers.rohdeschwarz_lib import cmx500_cellular_simulator as cmx
from acts.controllers.cellular_lib import AndroidCellularDut
from acts.controllers.cellular_lib import GsmSimulation
from acts.controllers.cellular_lib import LteSimulation
from acts.controllers.cellular_lib import UmtsSimulation
from acts.controllers.cellular_lib import LteCaSimulation
from acts.controllers.cellular_lib import LteImsSimulation

from acts_contrib.test_utils.tel import tel_test_utils as telutils


class CellularBaseTest(base_test.BaseTestClass):
    """ Base class for modem functional tests. """

    # List of test name keywords that indicate the RAT to be used

    PARAM_SIM_TYPE_LTE = "lte"
    PARAM_SIM_TYPE_LTE_CA = "lteca"
    PARAM_SIM_TYPE_LTE_IMS = "lteims"
    PARAM_SIM_TYPE_UMTS = "umts"
    PARAM_SIM_TYPE_GSM = "gsm"

    # Custom files
    FILENAME_CALIBRATION_TABLE_UNFORMATTED = 'calibration_table_{}.json'

    # Name of the files in the logs directory that will contain test results
    # and other information in csv format.
    RESULTS_SUMMARY_FILENAME = 'cellular_power_results.csv'
    CALIBRATION_TABLE_FILENAME = 'calibration_table.csv'

    def __init__(self, controllers):
        """ Class initialization.

        Sets class attributes to None.
        """

        super().__init__(controllers)

        self.simulation = None
        self.cellular_simulator = None
        self.calibration_table = {}

    def setup_class(self):
        """ Executed before any test case is started.
        Connects to the cellular instrument.

        Returns:
            False if connecting to the callbox fails.
        """

        super().setup_class()

        if not hasattr(self, 'dut'):
            self.dut = self.android_devices[0]

        TEST_PARAMS = self.TAG + '_params'
        self.cellular_test_params = self.user_params.get(TEST_PARAMS, {})

        # Unpack test parameters used in this class
        self.unpack_userparams(['custom_files'],
                               md8475_version=None,
                               md8475a_ip_address=None,
                               cmw500_ip=None,
                               cmw500_port=None,
                               cmx500_ip=None,
                               cmx500_port=None,
                               qxdm_logs=None)

        # Load calibration tables
        filename_calibration_table = (
            self.FILENAME_CALIBRATION_TABLE_UNFORMATTED.format(
                self.testbed_name))

        for file in self.custom_files:
            if filename_calibration_table in file:
                self.calibration_table = self.unpack_custom_file(file, False)
                self.log.info('Loading calibration table from ' + file)
                self.log.debug(self.calibration_table)
                break

        # Ensure the calibration table only contains non-negative values
        self.ensure_valid_calibration_table(self.calibration_table)

        # Turn on airplane mode for all devices, as some might
        # be unused during the test
        for ad in self.android_devices:
            telutils.toggle_airplane_mode(self.log, ad, True)

        # Establish a connection with the cellular simulator equipment
        try:
            self.cellular_simulator = self.initialize_simulator()
        except ValueError:
            self.log.error('No cellular simulator could be selected with the '
                           'current configuration.')
            raise
        except simulator.CellularSimulatorError:
            self.log.error('Could not initialize the cellular simulator.')
            raise

    def initialize_simulator(self):
        """ Connects to Anritsu Callbox and gets handle object.

        Returns:
            False if a connection with the callbox could not be started
        """

        if self.md8475_version:

            self.log.info('Selecting Anrtisu MD8475 callbox.')

            # Verify the callbox IP address has been indicated in the configs
            if not self.md8475a_ip_address:
                raise RuntimeError(
                    'md8475a_ip_address was not included in the test '
                    'configuration.')

            if self.md8475_version == 'A':
                return anritsu.MD8475CellularSimulator(self.md8475a_ip_address)
            elif self.md8475_version == 'B':
                return anritsu.MD8475BCellularSimulator(
                    self.md8475a_ip_address)
            else:
                raise ValueError('Invalid MD8475 version.')

        elif self.cmw500_ip or self.cmw500_port:

            for key in ['cmw500_ip', 'cmw500_port']:
                if not getattr(self, key):
                    raise RuntimeError('The CMW500 cellular simulator '
                                       'requires %s to be set in the '
                                       'config file.' % key)

            return cmw.CMW500CellularSimulator(self.cmw500_ip,
                                               self.cmw500_port)
        elif self.cmx500_ip or self.cmx500_port:
            for key in ['cmx500_ip', 'cmx500_port']:
                if not getattr(self, key):
                    raise RuntimeError('The CMX500 cellular simulator '
                                       'requires %s to be set in the '
                                       'config file.' % key)

            return cmx.CMX500CellularSimulator(self.cmx500_ip,
                                               self.cmx500_port)

        else:
            raise RuntimeError(
                'The simulator could not be initialized because '
                'a callbox was not defined in the configs file.')

    def setup_test(self):
        """ Executed before every test case.

        Parses parameters from the test name and sets a simulation up according
        to those values. Also takes care of attaching the phone to the base
        station. Because starting new simulations and recalibrating takes some
        time, the same simulation object is kept between tests and is only
        destroyed and re instantiated in case the RAT is different from the
        previous tests.

        Children classes need to call the parent method first. This method will
        create the list self.parameters with the keywords separated by
        underscores in the test name and will remove the ones that were consumed
        for the simulation config. The setup_test methods in the children
        classes can then consume the remaining values.
        """

        super().setup_test()

        # Get list of parameters from the test name
        self.parameters = self.current_test_name.split('_')

        # Remove the 'test' keyword
        self.parameters.remove('test')

        # Decide what type of simulation and instantiate it if needed
        if self.consume_parameter(self.PARAM_SIM_TYPE_LTE):
            self.init_simulation(self.PARAM_SIM_TYPE_LTE)
        elif self.consume_parameter(self.PARAM_SIM_TYPE_LTE_CA):
            self.init_simulation(self.PARAM_SIM_TYPE_LTE_CA)
        elif self.consume_parameter(self.PARAM_SIM_TYPE_LTE_IMS):
            self.init_simulation(self.PARAM_SIM_TYPE_LTE_IMS)
        elif self.consume_parameter(self.PARAM_SIM_TYPE_UMTS):
            self.init_simulation(self.PARAM_SIM_TYPE_UMTS)
        elif self.consume_parameter(self.PARAM_SIM_TYPE_GSM):
            self.init_simulation(self.PARAM_SIM_TYPE_GSM)
        else:
            self.log.error(
                "Simulation type needs to be indicated in the test name.")
            return False

        # Changing cell parameters requires the phone to be detached
        self.simulation.detach()

        # Parse simulation parameters.
        # This may throw a ValueError exception if incorrect values are passed
        # or if required arguments are omitted.
        try:
            self.simulation.parse_parameters(self.parameters)
        except ValueError as error:
            self.log.error(str(error))
            return False

        # Wait for new params to settle
        time.sleep(5)

        # Enable QXDM logger if required
        if self.qxdm_logs:
            self.log.info('Enabling the QXDM logger.')
            telutils.set_qxdm_logger_command(self.dut)
            telutils.start_qxdm_logger(self.dut)

        # Start the simulation. This method will raise an exception if
        # the phone is unable to attach.
        self.simulation.start()

        return True

    def teardown_test(self):
        """ Executed after every test case, even if it failed or an exception
        happened.

        Save results to dictionary so they can be displayed after completing
        the test batch.
        """
        super().teardown_test()

        # If QXDM logging was enabled pull the results
        if self.qxdm_logs:
            self.log.info('Stopping the QXDM logger and pulling results.')
            telutils.stop_qxdm_logger(self.dut)
            self.dut.get_qxdm_logs()

    def consume_parameter(self, parameter_name, num_values=0):
        """ Parses a parameter from the test name.

        Allows the test to get parameters from its name. Deletes parameters from
        the list after consuming them to ensure that they are not used twice.

        Args:
            parameter_name: keyword to look up in the test name
            num_values: number of arguments following the parameter name in the
                test name
        Returns:
            A list containing the parameter name and the following num_values
            arguments.
        """

        try:
            i = self.parameters.index(parameter_name)
        except ValueError:
            # parameter_name is not set
            return []

        return_list = []

        try:
            for j in range(num_values + 1):
                return_list.append(self.parameters.pop(i))
        except IndexError:
            self.log.error(
                "Parameter {} has to be followed by {} values.".format(
                    parameter_name, num_values))
            raise ValueError()

        return return_list

    def teardown_class(self):
        """Clean up the test class after tests finish running.

        Stops the simulation and disconnects from the Anritsu Callbox. Then
        displays the test results.
        """
        super().teardown_class()

        try:
            if self.cellular_simulator:
                self.cellular_simulator.destroy()
        except simulator.CellularSimulatorError as e:
            self.log.error('Error while tearing down the callbox controller. '
                           'Error message: ' + str(e))

    def init_simulation(self, sim_type):
        """ Starts a new simulation only if needed.

        Only starts a new simulation if type is different from the one running
        before.

        Args:
            type: defines the type of simulation to be started.
        """

        simulation_dictionary = {
            self.PARAM_SIM_TYPE_LTE: LteSimulation.LteSimulation,
            self.PARAM_SIM_TYPE_UMTS: UmtsSimulation.UmtsSimulation,
            self.PARAM_SIM_TYPE_GSM: GsmSimulation.GsmSimulation,
            self.PARAM_SIM_TYPE_LTE_CA: LteCaSimulation.LteCaSimulation,
            self.PARAM_SIM_TYPE_LTE_IMS: LteImsSimulation.LteImsSimulation
        }

        if not sim_type in simulation_dictionary:
            raise ValueError("The provided simulation type is invalid.")

        simulation_class = simulation_dictionary[sim_type]

        if isinstance(self.simulation, simulation_class):
            # The simulation object we already have is enough.
            return

        if self.simulation:
            # Make sure the simulation is stopped before loading a new one
            self.simulation.stop()

        # If the calibration table doesn't have an entry for this simulation
        # type add an empty one
        if sim_type not in self.calibration_table:
            self.calibration_table[sim_type] = {}

        cellular_dut = AndroidCellularDut.AndroidCellularDut(
            self.dut, self.log)
        # Instantiate a new simulation
        self.simulation = simulation_class(self.cellular_simulator, self.log,
                                           cellular_dut,
                                           self.cellular_test_params,
                                           self.calibration_table[sim_type])

    def ensure_valid_calibration_table(self, calibration_table):
        """ Ensures the calibration table has the correct structure.

        A valid calibration table is a nested dictionary with non-negative
        number values

        """
        if not isinstance(calibration_table, dict):
            raise TypeError('The calibration table must be a dictionary')
        for val in calibration_table.values():
            if isinstance(val, dict):
                self.ensure_valid_calibration_table(val)
            elif not isinstance(val, float) and not isinstance(val, int):
                raise TypeError('Calibration table value must be a number')
            elif val < 0.0:
                raise ValueError('Calibration table contains negative values')

    def unpack_custom_file(self, file, test_specific=True):
        """Loads a json file.

          Args:
              file: the common file containing pass fail threshold.
              test_specific: if True, returns the JSON element within the file
                  that starts with the test class name.
          """
        with open(file, 'r') as f:
            params = json.load(f)
        if test_specific:
            try:
                return params[self.TAG]
            except KeyError:
                pass
        else:
            return params
