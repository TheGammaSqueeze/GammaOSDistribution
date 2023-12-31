#!/usr/bin/env python
#
# Copyright (C) 2016 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
import argparse
import glob
import logging
import os
import shutil
import subprocess
from tempfile import TemporaryDirectory
import textwrap


THIS_DIR = os.path.realpath(os.path.dirname(__file__))


def logger():
    return logging.getLogger(__name__)


def check_call(cmd):
    logger().debug('Running `%s`', ' '.join(cmd))
    subprocess.check_call(cmd)


def remove(path):
    logger().debug('remove `%s`', path)
    os.remove(path)


def fetch_artifact(branch, build, pattern):
    fetch_artifact_path = '/google/data/ro/projects/android/fetch_artifact'
    cmd = [fetch_artifact_path, '--branch', branch, '--target=linux',
           '--bid', build, pattern]
    check_call(cmd)


def api_str(api_level):
    return 'android-{}'.format(api_level)


def start_branch(build):
    branch_name = 'update-' + (build or 'latest')
    logger().info('Creating branch %s', branch_name)
    check_call(['repo', 'start', branch_name, '.'])


def remove_old_release(install_dir):
    if os.path.exists(os.path.join(install_dir, '.git')):
        logger().info('Removing old install directory "%s"', install_dir)
        check_call(['git', 'rm', '-rf', install_dir])

    # Need to check again because git won't remove directories if they have
    # non-git files in them.
    if os.path.exists(install_dir):
        shutil.rmtree(install_dir)


LIBUNWIND_GLOB = (
    'toolchains/llvm/prebuilt/*/lib64/clang/*/lib/linux/*/libunwind.a'
)


def unzip_single_directory(artifact, destination):
    # Use cwd so that we can use rename without having to worry about crossing
    # file systems.
    with TemporaryDirectory(dir=os.getcwd()) as temp_dir:
        cmd = [
            'unzip',
            artifact,
            '-d',
            temp_dir,
            '*/sources/android/cpufeatures/*',
            '*/sources/android/native_app_glue/*',
            '*/sources/android/support/*',
            '*/sources/cxx-stl/*',
            '*/source.properties',
            os.path.join('*', LIBUNWIND_GLOB),
        ]
        check_call(cmd)

        dirs = os.listdir(temp_dir)
        assert len(dirs) == 1
        ndk_dir = os.path.join(temp_dir, dirs[0])
        for child in os.listdir(ndk_dir):
            os.rename(os.path.join(ndk_dir, child),
                      os.path.join(destination, child))


def relocate_libunwind(install_dir):
    unwinds = glob.glob(os.path.join(install_dir, LIBUNWIND_GLOB))
    dest_base = os.path.join(install_dir, 'sources/cxx-stl/llvm-libc++/libs')
    for libunwind in unwinds:
        arch = os.path.basename(os.path.dirname(libunwind))
        abi = {
            'arm': 'armeabi-v7a',
            'aarch64': 'arm64-v8a',
            'i386': 'x86',
            'x86_64': 'x86_64',
        }[arch]
        dest_dir = os.path.join(dest_base, abi)
        dest = os.path.join(dest_dir, 'libunwind.a')
        logger().info('Relocating %s to %s', libunwind, dest)
        os.rename(libunwind, dest)


def install_new_release(branch, build, install_dir):
    os.makedirs(install_dir)

    artifact_pattern = 'android-ndk-*.zip'
    logger().info('Fetching %s from %s (artifacts matching %s)', build, branch,
                  artifact_pattern)
    fetch_artifact(branch, build, artifact_pattern)
    artifacts = glob.glob('android-ndk-*.zip')
    try:
        assert len(artifacts) == 1
        artifact = artifacts[0]

        logger().info('Extracting release')
        unzip_single_directory(artifact, install_dir)
        relocate_libunwind(install_dir)
    finally:
        for artifact in artifacts:
            os.unlink(artifact)


def commit(branch, build, install_dir):
    logger().info('Making commit')
    check_call(['git', 'add', install_dir])
    message = textwrap.dedent("""\
        Update NDK prebuilts to build {build}.

        Taken from branch {branch}.

        Bug: None
        Test: treehugger
        """).format(branch=branch, build=build)
    check_call(['git', 'commit', '-m', message])


def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '-b', '--branch', default='master-ndk',
        help='Branch to pull build from.')
    parser.add_argument(
        'major_release', help='Major release being installed, e.g. "r11".')
    parser.add_argument('--build', required=True, help='Build number to pull.')
    parser.add_argument(
        '--use-current-branch', action='store_true',
        help='Perform the update in the current branch. Do not repo start.')
    parser.add_argument(
        '-v', '--verbose', action='count', default=0,
        help='Increase output verbosity.')
    return parser.parse_args()


def main():
    os.chdir(THIS_DIR)

    args = get_args()
    verbose_map = (logging.WARNING, logging.INFO, logging.DEBUG)
    verbosity = args.verbose
    if verbosity > 2:
        verbosity = 2
    logging.basicConfig(level=verbose_map[verbosity])

    install_dir = os.path.realpath(args.major_release)

    if not args.use_current_branch:
        start_branch(args.build)
    remove_old_release(install_dir)
    install_new_release(args.branch, args.build, install_dir)
    commit(args.branch, args.build, install_dir)


if __name__ == '__main__':
    main()
