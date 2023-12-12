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

# pylint: disable=import-outside-toplevel
# pylint: disable=line-too-long

"""
Result Reporter

The result reporter formats and prints test results.

----
Example Output for command to run following tests:
CtsAnimationTestCases:EvaluatorTest, HelloWorldTests, and WmTests

Running Tests ...

CtsAnimationTestCases
---------------------

android.animation.cts.EvaluatorTest.UnitTests (7 Tests)
[1/7] android.animation.cts.EvaluatorTest#testRectEvaluator: PASSED (153ms)
[2/7] android.animation.cts.EvaluatorTest#testIntArrayEvaluator: PASSED (0ms)
[3/7] android.animation.cts.EvaluatorTest#testIntEvaluator: PASSED (0ms)
[4/7] android.animation.cts.EvaluatorTest#testFloatArrayEvaluator: PASSED (1ms)
[5/7] android.animation.cts.EvaluatorTest#testPointFEvaluator: PASSED (1ms)
[6/7] android.animation.cts.EvaluatorTest#testArgbEvaluator: PASSED (0ms)
[7/7] android.animation.cts.EvaluatorTest#testFloatEvaluator: PASSED (1ms)

HelloWorldTests
---------------

android.test.example.helloworld.UnitTests(2 Tests)
[1/2] android.test.example.helloworld.HelloWorldTest#testHalloWelt: PASSED (0ms)
[2/2] android.test.example.helloworld.HelloWorldTest#testHelloWorld: PASSED (1ms)

WmTests
-------

com.android.tradefed.targetprep.UnitTests (1 Test)
RUNNER ERROR: com.android.tradefed.targetprep.TargetSetupError:
Failed to install WmTests.apk on 127.0.0.1:54373. Reason:
    error message ...


Summary
-------
CtsAnimationTestCases: Passed: 7, Failed: 0
HelloWorldTests: Passed: 2, Failed: 0
WmTests: Passed: 0, Failed: 0 (Completed With ERRORS)

1 test failed
"""

from __future__ import print_function

from collections import OrderedDict

import constants
import atest_utils as au

from test_runners import test_runner_base

UNSUPPORTED_FLAG = 'UNSUPPORTED_RUNNER'
FAILURE_FLAG = 'RUNNER_FAILURE'
BENCHMARK_ESSENTIAL_KEYS = {'repetition_index', 'cpu_time', 'name', 'repetitions',
                            'run_type', 'threads', 'time_unit', 'iterations',
                            'run_name', 'real_time'}
# TODO(b/146875480): handle the optional benchmark events
BENCHMARK_OPTIONAL_KEYS = {'bytes_per_second', 'label'}
BENCHMARK_EVENT_KEYS = BENCHMARK_ESSENTIAL_KEYS.union(BENCHMARK_OPTIONAL_KEYS)
INT_KEYS = {'cpu_time', 'real_time'}
ITER_SUMMARY = {}

class PerfInfo():
    """Class for storing performance test of a test run."""

    def __init__(self):
        """Initialize a new instance of PerfInfo class."""
        # perf_info: A list of benchmark_info(dict).
        self.perf_info = []

    def update_perf_info(self, test):
        """Update perf_info with the given result of a single test.

        Args:
            test: A TestResult namedtuple.
        """
        all_additional_keys = set(test.additional_info.keys())
        # Ensure every key is in all_additional_keys.
        if not BENCHMARK_ESSENTIAL_KEYS.issubset(all_additional_keys):
            return
        benchmark_info = {}
        benchmark_info['test_name'] = test.test_name
        for key, data in test.additional_info.items():
            if key in INT_KEYS:
                data_to_int = data.split('.')[0]
                benchmark_info[key] = data_to_int
            elif key in BENCHMARK_EVENT_KEYS:
                benchmark_info[key] = data
        if benchmark_info:
            self.perf_info.append(benchmark_info)

    def print_perf_info(self):
        """Print summary of a perf_info."""
        if not self.perf_info:
            return
        classify_perf_info, max_len = self._classify_perf_info()
        separator = '-' * au.get_terminal_size()[0]
        print(separator)
        print("{:{name}}    {:^{real_time}}    {:^{cpu_time}}    "
              "{:>{iterations}}".format(
                  'Benchmark', 'Time', 'CPU', 'Iteration',
                  name=max_len['name']+3,
                  real_time=max_len['real_time']+max_len['time_unit']+1,
                  cpu_time=max_len['cpu_time']+max_len['time_unit']+1,
                  iterations=max_len['iterations']))
        print(separator)
        for module_name, module_perf_info in classify_perf_info.items():
            print("{}:".format(module_name))
            for benchmark_info in module_perf_info:
                # BpfBenchMark/MapWriteNewEntry/1    1530 ns     1522 ns   460517
                print("  #{:{name}}    {:>{real_time}} {:{time_unit}}    "
                      "{:>{cpu_time}} {:{time_unit}}    "
                      "{:>{iterations}}".format(benchmark_info['name'],
                                                benchmark_info['real_time'],
                                                benchmark_info['time_unit'],
                                                benchmark_info['cpu_time'],
                                                benchmark_info['time_unit'],
                                                benchmark_info['iterations'],
                                                name=max_len['name'],
                                                real_time=max_len['real_time'],
                                                time_unit=max_len['time_unit'],
                                                cpu_time=max_len['cpu_time'],
                                                iterations=max_len['iterations']))

    def _classify_perf_info(self):
        """Classify the perf_info by test module name.

        Returns:
            A tuple of (classified_perf_info, max_len), where
            classified_perf_info: A dict of perf_info and each perf_info are
                                 belong to different modules.
                e.g.
                    { module_name_01: [perf_info of module_1],
                      module_name_02: [perf_info of module_2], ...}
            max_len: A dict which stores the max length of each event.
                     It contains the max string length of 'name', real_time',
                     'time_unit', 'cpu_time', 'iterations'.
                e.g.
                    {name: 56, real_time: 9, time_unit: 2, cpu_time: 8,
                     iterations: 12}
        """
        module_categories = set()
        max_len = {}
        all_name = []
        all_real_time = []
        all_time_unit = []
        all_cpu_time = []
        all_iterations = ['Iteration']
        for benchmark_info in self.perf_info:
            module_categories.add(benchmark_info['test_name'].split('#')[0])
            all_name.append(benchmark_info['name'])
            all_real_time.append(benchmark_info['real_time'])
            all_time_unit.append(benchmark_info['time_unit'])
            all_cpu_time.append(benchmark_info['cpu_time'])
            all_iterations.append(benchmark_info['iterations'])
        classified_perf_info = {}
        for module_name in module_categories:
            module_perf_info = []
            for benchmark_info in self.perf_info:
                if benchmark_info['test_name'].split('#')[0] == module_name:
                    module_perf_info.append(benchmark_info)
            classified_perf_info[module_name] = module_perf_info
        max_len = {'name': len(max(all_name, key=len)),
                   'real_time': len(max(all_real_time, key=len)),
                   'time_unit': len(max(all_time_unit, key=len)),
                   'cpu_time': len(max(all_cpu_time, key=len)),
                   'iterations': len(max(all_iterations, key=len))}
        return classified_perf_info, max_len


class RunStat:
    """Class for storing stats of a test run."""

    def __init__(self, passed=0, failed=0, ignored=0, run_errors=False,
                 assumption_failed=0):
        """Initialize a new instance of RunStat class.

        Args:
            passed: Count of passing tests.
            failed: Count of failed tests.
            ignored: Count of ignored tests.
            assumption_failed: Count of assumption failure tests.
            run_errors: A boolean if there were run errors
        """
        # TODO(b/109822985): Track group and run estimated totals for updating
        # summary line
        self.passed = passed
        self.failed = failed
        self.ignored = ignored
        self.assumption_failed = assumption_failed
        self.perf_info = PerfInfo()
        # Run errors are not for particular tests, they are runner errors.
        self.run_errors = run_errors

    @property
    def total(self):
        """Getter for total tests actually ran. Accessed via self.total"""
        return self.passed + self.failed


class ResultReporter:
    """Result Reporter class.

    As each test is run, the test runner will call self.process_test_result()
    with a TestResult namedtuple that contains the following information:
    - runner_name:   Name of the test runner
    - group_name:    Name of the test group if any.
                     In Tradefed that's the Module name.
    - test_name:     Name of the test.
                     In Tradefed that's qualified.class#Method
    - status:        The strings FAILED or PASSED.
    - stacktrace:    The stacktrace if the test failed.
    - group_total:   The total tests scheduled to be run for a group.
                     In Tradefed this is provided when the Module starts.
    - runner_total:  The total tests scheduled to be run for the runner.
                     In Tradefed this is not available so is None.

    The Result Reporter will print the results of this test and then update
    its stats state.

    Test stats are stored in the following structure:
    - self.run_stats: Is RunStat instance containing stats for the overall run.
                      This include pass/fail counts across ALL test runners.

    - self.runners:  Is of the form: {RunnerName: {GroupName: RunStat Instance}}
                     Where {} is an ordered dict.

                     The stats instance contains stats for each test group.
                     If the runner doesn't support groups, then the group
                     name will be None.

    For example this could be a state of ResultReporter:

    run_stats: RunStat(passed:10, failed:5)
    runners: {'AtestTradefedTestRunner':
                            {'Module1': RunStat(passed:1, failed:1),
                             'Module2': RunStat(passed:0, failed:4)},
              'RobolectricTestRunner': {None: RunStat(passed:5, failed:0)},
              'VtsTradefedTestRunner': {'Module1': RunStat(passed:4, failed:0)}}
    """

    def __init__(self, silent=False, collect_only=False, flakes_info=False):
        """Init ResultReporter.

        Args:
            silent: A boolean of silence or not.
        """
        self.run_stats = RunStat()
        self.runners = OrderedDict()
        self.failed_tests = []
        self.all_test_results = []
        self.pre_test = None
        self.log_path = None
        self.silent = silent
        self.rerun_options = ''
        self.collect_only = collect_only
        self.flakes_info = flakes_info
        self.test_result_link = None

    def process_test_result(self, test):
        """Given the results of a single test, update stats and print results.

        Args:
            test: A TestResult namedtuple.
        """
        if test.runner_name not in self.runners:
            self.runners[test.runner_name] = OrderedDict()
        assert self.runners[test.runner_name] != FAILURE_FLAG
        self.all_test_results.append(test)
        if test.group_name not in self.runners[test.runner_name]:
            self.runners[test.runner_name][test.group_name] = RunStat()
            self._print_group_title(test)
        self._update_stats(test,
                           self.runners[test.runner_name][test.group_name])
        self._print_result(test)

    def runner_failure(self, runner_name, failure_msg):
        """Report a runner failure.

        Use instead of process_test_result() when runner fails separate from
        any particular test, e.g. during setup of runner.

        Args:
            runner_name: A string of the name of the runner.
            failure_msg: A string of the failure message to pass to user.
        """
        self.runners[runner_name] = FAILURE_FLAG
        print('\n', runner_name, '\n', '-' * len(runner_name), sep='')
        print('Runner encountered a critical failure. Skipping.\n'
              'FAILURE: %s' % failure_msg)

    def register_unsupported_runner(self, runner_name):
        """Register an unsupported runner.

           Prints the following to the screen:

           RunnerName
           ----------
           This runner does not support normal results formatting.
           Below is the raw output of the test runner.

           RAW OUTPUT:
           <Raw Runner Output>

           Args:
              runner_name: A String of the test runner's name.
        """
        assert runner_name not in self.runners
        self.runners[runner_name] = UNSUPPORTED_FLAG
        print('\n', runner_name, '\n', '-' * len(runner_name), sep='')
        print('This runner does not support normal results formatting. Below '
              'is the raw output of the test runner.\n\nRAW OUTPUT:')

    def print_starting_text(self):
        """Print starting text for running tests."""
        print(au.colorize('\nRunning Tests...', constants.CYAN))

    def set_current_summary(self, run_num):
        """Set current test summary to ITER_SUMMARY."""
        run_summary = []
        for runner_name, groups in self.runners.items():
            for group_name, stats in groups.items():
                name = group_name if group_name else runner_name
                summary = self.process_summary(name, stats)
                run_summary.append(summary)
        summary_list = ITER_SUMMARY.get(run_num, [])
        # Not contain redundant item
        if not set(run_summary).issubset(set(summary_list)):
            summary_list.extend(run_summary)
            ITER_SUMMARY[run_num] = summary_list

    # pylint: disable=too-many-branches
    def print_summary(self):
        """Print summary of all test runs.

        Returns:
            0 if all tests pass, non-zero otherwise.

        """
        if self.collect_only:
            return self.print_collect_tests()
        tests_ret = constants.EXIT_CODE_SUCCESS
        if not self.runners:
            return tests_ret
        print('\n{}'.format(au.colorize('Summary', constants.CYAN)))
        print(au.delimiter('-', 7))
        iterations = len(ITER_SUMMARY)
        for iter_num, summary_list in ITER_SUMMARY.items():
            if iterations > 1:
                print(au.colorize("ITERATION %s" % (int(iter_num) + 1),
                                  constants.BLUE))
            for summary in summary_list:
                print(summary)
        failed_sum = len(self.failed_tests)
        for runner_name, groups in self.runners.items():
            if groups == UNSUPPORTED_FLAG:
                print(runner_name, 'Unsupported. See raw output above.')
                continue
            if groups == FAILURE_FLAG:
                tests_ret = constants.EXIT_CODE_TEST_FAILURE
                print(runner_name, 'Crashed. No results to report.')
                failed_sum += 1
                continue
            for group_name, stats in groups.items():
                name = group_name if group_name else runner_name
                summary = self.process_summary(name, stats)
                if stats.failed > 0:
                    tests_ret = constants.EXIT_CODE_TEST_FAILURE
                if stats.run_errors:
                    tests_ret = constants.EXIT_CODE_TEST_FAILURE
                    failed_sum += 1 if not stats.failed else 0
                if not ITER_SUMMARY:
                    print(summary)
        self.run_stats.perf_info.print_perf_info()
        print()
        if tests_ret == constants.EXIT_CODE_SUCCESS:
            print(au.colorize('All tests passed!', constants.GREEN))
        else:
            message = '%d %s failed' % (failed_sum,
                                        'tests' if failed_sum > 1 else 'test')
            print(au.colorize(message, constants.RED))
            print('-'*len(message))
            self.print_failed_tests()
        if self.log_path:
            print('Test Logs have saved in %s' % self.log_path)
        # TODO(b/174535786) Error handling while uploading test results has
        # unexpected exceptions.
        # TODO (b/174627499) Saving this information in atest history.
        if self.test_result_link:
            print('Test Result uploaded to %s'
                  % au.colorize(self.test_result_link, constants.GREEN))
        return tests_ret

    def print_collect_tests(self):
        """Print summary of collect tests only.

        Returns:
            0 if all tests collection done.

        """
        tests_ret = constants.EXIT_CODE_SUCCESS
        if not self.runners:
            return tests_ret
        print('\n{}'.format(au.colorize('Summary:' + constants.COLLECT_TESTS_ONLY,
                                        constants.CYAN)))
        print(au.delimiter('-', 26))
        for runner_name, groups in self.runners.items():
            for group_name, _ in groups.items():
                name = group_name if group_name else runner_name
                print(name)
        print()
        if self.log_path:
            print('Test Logs have saved in %s' % self.log_path)
        return constants.EXIT_CODE_SUCCESS

    def print_failed_tests(self):
        """Print the failed tests if existed."""
        if self.failed_tests:
            for test_name in self.failed_tests:
                failed_details = test_name
                if self.flakes_info:
                    flakes_method = test_name.replace('#', '.')
                    flakes_info = au.get_flakes(test_method=flakes_method)
                    if (flakes_info and
                            flakes_info.get(constants.FLAKE_PERCENT, None)):
                        failed_details += (
                            ': flakes percent: {}%, flakes postsubmit per week:'
                            ' {}'.format(float(flakes_info.get(
                                constants.FLAKE_PERCENT)),
                                         flakes_info.get(
                                             constants.FLAKE_POSTSUBMIT, '0')))
                print(failed_details)

    # pylint: disable=too-many-locals
    def process_summary(self, name, stats):
        """Process the summary line.

        Strategy:
            Error status happens ->
                SomeTests: Passed: 2, Failed: 0 <red>(Completed With ERRORS)</red>
                SomeTests: Passed: 2, <red>Failed</red>: 2 <red>(Completed With ERRORS)</red>
            More than 1 test fails ->
                SomeTests: Passed: 2, <red>Failed</red>: 5
            No test fails ->
                SomeTests: <green>Passed</green>: 2, Failed: 0

        Args:
            name: A string of test name.
            stats: A RunStat instance for a test group.

        Returns:
            A summary of the test result.
        """
        passed_label = 'Passed'
        failed_label = 'Failed'
        flakes_label = ''
        ignored_label = 'Ignored'
        assumption_failed_label = 'Assumption Failed'
        error_label = ''
        host_log_content = ''
        flakes_percent = ''
        if stats.failed > 0:
            failed_label = au.colorize(failed_label, constants.RED)
            mod_list = name.split()
            module = ''
            if len(mod_list) > 1:
                module = mod_list[1]
            if module and self.flakes_info:
                flakes_info = au.get_flakes(test_module=module)
                if (flakes_info and
                        flakes_info.get(constants.FLAKE_PERCENT, None)):
                    flakes_label = au.colorize('Flakes Percent:',
                                               constants.RED)
                    flakes_percent = '{:.2f}%'.format(float(flakes_info.get(
                        constants.FLAKE_PERCENT)))
        if stats.run_errors:
            error_label = au.colorize('(Completed With ERRORS)', constants.RED)
            # Only extract host_log_content if test name is tradefed
            # Import here to prevent circular-import error.
            from test_runners import atest_tf_test_runner
            if name == atest_tf_test_runner.AtestTradefedTestRunner.NAME:
                find_logs = au.find_files(self.log_path,
                                          file_name=constants.TF_HOST_LOG)
                if find_logs:
                    host_log_content = au.colorize(
                        '\n\nTradefederation host log:', constants.RED)
                for tf_log_zip in find_logs:
                    host_log_content = host_log_content + au.extract_zip_text(
                        tf_log_zip)
        elif stats.failed == 0:
            passed_label = au.colorize(passed_label, constants.GREEN)
        summary = ('%s: %s: %s, %s: %s, %s: %s, %s: %s, %s %s %s %s'
                   % (name,
                      passed_label,
                      stats.passed,
                      failed_label,
                      stats.failed,
                      ignored_label,
                      stats.ignored,
                      assumption_failed_label,
                      stats.assumption_failed,
                      flakes_label,
                      flakes_percent,
                      error_label,
                      host_log_content))
        return summary

    def _update_stats(self, test, group):
        """Given the results of a single test, update test run stats.

        Args:
            test: a TestResult namedtuple.
            group: a RunStat instance for a test group.
        """
        # TODO(109822985): Track group and run estimated totals for updating
        # summary line
        if test.status == test_runner_base.PASSED_STATUS:
            self.run_stats.passed += 1
            group.passed += 1
        elif test.status == test_runner_base.IGNORED_STATUS:
            self.run_stats.ignored += 1
            group.ignored += 1
        elif test.status == test_runner_base.ASSUMPTION_FAILED:
            self.run_stats.assumption_failed += 1
            group.assumption_failed += 1
        elif test.status == test_runner_base.FAILED_STATUS:
            self.run_stats.failed += 1
            self.failed_tests.append(test.test_name)
            group.failed += 1
        elif test.status == test_runner_base.ERROR_STATUS:
            self.run_stats.run_errors = True
            group.run_errors = True
        self.run_stats.perf_info.update_perf_info(test)

    def _print_group_title(self, test):
        """Print the title line for a test group.

        Test Group/Runner Name
        ----------------------

        Args:
            test: A TestResult namedtuple.
        """
        if self.silent:
            return
        title = test.group_name or test.runner_name
        underline = '-' * (len(title))
        print('\n%s\n%s' % (title, underline))

    # pylint: disable=too-many-branches
    def _print_result(self, test):
        """Print the results of a single test.

           Looks like:
           fully.qualified.class#TestMethod: PASSED/FAILED

        Args:
            test: a TestResult namedtuple.
        """
        if self.silent:
            return
        if not self.pre_test or (test.test_run_name !=
                                 self.pre_test.test_run_name):
            print('%s (%s %s)' % (au.colorize(test.test_run_name,
                                              constants.BLUE),
                                  test.group_total,
                                  'Test' if test.group_total <= 1 else 'Tests'))
        if test.status == test_runner_base.ERROR_STATUS:
            print('RUNNER ERROR: %s\n' % test.details)
            self.pre_test = test
            return
        if test.test_name:
            color = ''
            if test.status == test_runner_base.PASSED_STATUS:
                # Example of output:
                # [78/92] test_name: PASSED (92ms)
                color = constants.GREEN
            elif test.status in (test_runner_base.IGNORED_STATUS,
                                 test_runner_base.ASSUMPTION_FAILED):
                # Example: [33/92] test_name: IGNORED (12ms)
                # Example: [33/92] test_name: ASSUMPTION_FAILED (12ms)
                color = constants.MAGENTA
            else:
                # Example: [26/92] test_name: FAILED (32ms)
                color = constants.RED
            print('[{}/{}] {}'.format(test.test_count,
                                      test.group_total,
                                      test.test_name), end='')
            if self.collect_only:
                print()
            else:
                print(': {} {}'.format(au.colorize(test.status, color),
                                       test.test_time))
            if test.status == test_runner_base.PASSED_STATUS:
                for key, data in test.additional_info.items():
                    if key not in BENCHMARK_EVENT_KEYS:
                        print('\t%s: %s' % (au.colorize(key, constants.BLUE),
                                            data))
            if test.status == test_runner_base.FAILED_STATUS:
                print('\nSTACKTRACE:\n%s' % test.details)
        self.pre_test = test
