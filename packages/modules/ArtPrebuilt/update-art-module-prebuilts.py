#!/usr/bin/env -S python3 -B
#
# Copyright (C) 2021 The Android Open Source Project
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

"""Downloads ART Module prebuilts and creates CLs to update them in git."""

import argparse
import collections
import os
import re
import subprocess
import sys
import tempfile


# Prebuilt description used in commit message
PREBUILT_DESCR = "ART Module"

# fetch_artifact branch and target
BRANCH = "aosp-master-art"
TARGET = "aosp_art_module"

ARCHES = ["arm", "arm64", "x86", "x86_64"]

# Where to install the APEX packages
PACKAGE_PATH = "packages/modules/ArtPrebuilt"

# Where to install the SDKs and module exports
SDK_PATH = "prebuilts/module_sdk/art"

SDK_VERSION = "current"

# Paths to git projects to prepare CLs in
GIT_PROJECT_ROOTS = [PACKAGE_PATH, SDK_PATH]

SCRIPT_PATH = PACKAGE_PATH + "/update-art-module-prebuilts.py"


InstallEntry = collections.namedtuple("InstallEntry", [
    # Artifact path in the build, passed to fetch_target
    "source_path",
    # Local install path
    "install_path",
    # True if this is a module SDK, to be skipped by --skip-module-sdk.
    "module_sdk",
    # True if the entry is a zip file that should be unzipped to install_path
    "install_unzipped",
])


def install_apex_entries(apex_name):
  res = []
  for arch in ARCHES:
    res.append(InstallEntry(
        os.path.join(arch, apex_name + ".apex"),
        os.path.join(PACKAGE_PATH, apex_name + "-" + arch + ".apex"),
        module_sdk=False,
        install_unzipped=False))
  return res


def install_sdk_entries(mainline_sdk_name, sdk_dir):
  return [InstallEntry(
      os.path.join("mainline-sdks",
                   mainline_sdk_name + "-" + SDK_VERSION + ".zip"),
      os.path.join(SDK_PATH, SDK_VERSION, sdk_dir),
      module_sdk=True,
      install_unzipped=True)]


install_entries = (
    install_apex_entries("com.android.art") +
    install_apex_entries("com.android.art.debug") +
    install_sdk_entries("art-module-sdk", "sdk") +
    install_sdk_entries("art-module-host-exports", "host-exports") +
    install_sdk_entries("art-module-test-exports", "test-exports")
)


def rewrite_bp_for_art_module_source_build(bp_path):
  """Rewrites an Android.bp file to conditionally prefer prebuilts."""
  print("Rewriting {} for SOONG_CONFIG_art_module_source_build use."
        .format(bp_path))
  bp_file = open(bp_path, "r+")

  # TODO(b/174997203): Remove this when we have a proper way to control prefer
  # flags in Mainline modules.

  header_lines = []
  for line in bp_file:
    line = line.rstrip("\n")
    if not line.startswith("//"):
      break
    header_lines.append(line)

  art_module_types = set()

  content_lines = []
  for line in bp_file:
    line = line.rstrip("\n")
    module_header = re.match("([a-z0-9_]+) +{$", line)
    if not module_header:
      content_lines.append(line)
    else:
      # Iterate over one Soong module.
      module_start = line
      soong_config_clause = False
      module_content = []

      for module_line in bp_file:
        module_line = module_line.rstrip("\n")
        if module_line == "}":
          break
        if module_line == "    prefer: false,":
          module_content.extend([
              ("    // Do not prefer prebuilt if "
               "SOONG_CONFIG_art_module_source_build is true."),
              "    prefer: true,",
              "    soong_config_variables: {",
              "        source_build: {",
              "            prefer: false,",
              "        },",
              "    },"])
          soong_config_clause = True
        else:
          module_content.append(module_line)

      if soong_config_clause:
        module_type = "art_prebuilt_" + module_header.group(1)
        module_start = module_type + " {"
        art_module_types.add(module_type)

      content_lines.append(module_start)
      content_lines.extend(module_content)
      content_lines.append("}")

  header_lines.extend(
      ["",
       "// Soong config variable stanza added by {}.".format(SCRIPT_PATH),
       "soong_config_module_type_import {",
       "    from: \"prebuilts/module_sdk/art/SoongConfig.bp\",",
       "    module_types: ["] +
      ["        \"{}\",".format(art_module)
       for art_module in sorted(art_module_types)] +
      ["    ],",
       "}",
       ""])

  bp_file.seek(0)
  bp_file.truncate()
  bp_file.write("\n".join(header_lines + content_lines))
  bp_file.close()


def check_call(cmd, **kwargs):
  """Proxy for subprocess.check_call with logging."""
  msg = " ".join(cmd) if isinstance(cmd, list) else cmd
  if "cwd" in kwargs:
    msg = "In " + kwargs["cwd"] + ": " + msg
  print(msg)
  subprocess.check_call(cmd, **kwargs)


def fetch_artifact(branch, target, build, fetch_pattern, local_dir):
  """Fetches artifact from the build server."""
  fetch_artifact_path = "/google/data/ro/projects/android/fetch_artifact"
  cmd = [fetch_artifact_path, "--branch", branch, "--target", target,
         "--bid", build, fetch_pattern]
  check_call(cmd, cwd=local_dir)


def start_branch(branch_name, git_dirs):
  """Creates a new repo branch in the given projects."""
  check_call(["repo", "start", branch_name] + git_dirs)
  # In case the branch already exists we reset it to upstream, to get a clean
  # update CL.
  for git_dir in git_dirs:
    check_call(["git", "reset", "--hard", "@{upstream}"], cwd=git_dir)


def upload_branch(git_root, branch_name):
  """Uploads the CLs in the given branch in the given project."""
  # Set the branch as topic to bundle with the CLs in other git projects (if
  # any).
  check_call(["repo", "upload", "-t", "--br=" + branch_name, git_root])


def remove_files(git_root, subpaths, stage_removals):
  """Removes files in the work tree, optionally staging them in git."""
  if stage_removals:
    check_call(["git", "rm", "-qrf", "--ignore-unmatch"] + subpaths, cwd=git_root)
  # Need a plain rm afterwards even if git rm was executed, because git won't
  # remove directories if they have non-git files in them.
  check_call(["rm", "-rf"] + subpaths, cwd=git_root)


def commit(git_root, prebuilt_descr, branch, target, build, add_paths, bug_number):
  """Commits the new prebuilts."""
  check_call(["git", "add"] + add_paths, cwd=git_root)

  if build:
    message = (
        "Update {prebuilt_descr} prebuilts to build {build}.\n\n"
        "Taken from branch {branch}, target {target}."
        .format(prebuilt_descr=prebuilt_descr, branch=branch, target=target,
                build=build))
  else:
    message = (
        "DO NOT SUBMIT: Update {prebuilt_descr} prebuilts from local build."
        .format(prebuilt_descr=prebuilt_descr))
  message += ("\n\nCL prepared by {}."
              "\n\nTest: Presubmits".format(SCRIPT_PATH))
  if bug_number:
    message += ("\nBug: {}".format(bug_number))
  msg_fd, msg_path = tempfile.mkstemp()
  with os.fdopen(msg_fd, "w") as f:
    f.write(message)

  # Do a diff first to skip the commit without error if there are no changes to
  # commit.
  check_call("git diff-index --quiet --cached HEAD -- || "
             "git commit -F " + msg_path, shell=True, cwd=git_root)
  os.unlink(msg_path)


def install_entry(build, local_dist, entry):
  """Installs one file specified by entry."""

  install_dir, install_file = os.path.split(entry.install_path)
  if install_dir and not os.path.exists(install_dir):
    os.makedirs(install_dir)

  if build:
    fetch_artifact(BRANCH, TARGET, build, entry.source_path, install_dir)
  else:
    check_call(["cp", os.path.join(local_dist, entry.source_path), install_dir])
  source_file = os.path.basename(entry.source_path)

  if entry.install_unzipped:
    check_call(["mkdir", install_file], cwd=install_dir)
    # Add -DD to not extract timestamps that may confuse the build system.
    check_call(["unzip", "-DD", source_file, "-d", install_file],
               cwd=install_dir)
    check_call(["rm", source_file], cwd=install_dir)

  elif source_file != install_file:
    check_call(["mv", source_file, install_file], cwd=install_dir)


def install_paths_per_git_root(roots, paths):
  """Partitions the given paths into subpaths within the given roots.

  Args:
    roots: List of root paths.
    paths: List of paths relative to the same directory as the root paths.

  Returns:
    A dict mapping each root to the subpaths under it. It's an error if some
    path doesn't go into any root.
  """
  res = collections.defaultdict(list)
  for path in paths:
    found = False
    for root in roots:
      if path.startswith(root + "/"):
        res[root].append(path[len(root) + 1:])
        found = True
        break
    if not found:
      sys.exit("Install path {} is not in any of the git roots: {}"
               .format(path, " ".join(roots)))
  return res


def get_args():
  """Parses and returns command line arguments."""
  parser = argparse.ArgumentParser(
      epilog="Either --build or --local-dist is required.")

  parser.add_argument("--build", metavar="NUMBER",
                      help="Build number to fetch from branch {}, target {}"
                      .format(BRANCH, TARGET))
  parser.add_argument("--local-dist", metavar="PATH",
                      help="Take prebuilts from this local dist dir instead of "
                      "using fetch_artifact")
  parser.add_argument("--skip-apex", action="store_true",
                      help="Do not fetch .apex files.")
  parser.add_argument("--skip-module-sdk", action="store_true",
                      help="Do not fetch and unpack sdk and module_export zips.")
  parser.add_argument("--skip-cls", action="store_true",
                      help="Do not create branches or git commits")
  parser.add_argument("--bug", metavar="NUMBER",
                      help="Add a 'Bug' line with this number to commit "
                      "messages.")
  parser.add_argument("--upload", action="store_true",
                      help="Upload the CLs to Gerrit")

  args = parser.parse_args()
  if ((not args.build and not args.local_dist) or
      (args.build and args.local_dist)):
    sys.exit(parser.format_help())
  return args


def main():
  """Program entry point."""
  args = get_args()

  if any(path for path in GIT_PROJECT_ROOTS if not os.path.exists(path)):
    sys.exit("This script must be run in the root of the Android build tree.")

  entries = install_entries
  if args.skip_apex:
    entries = [entry for entry in entries if entry.module_sdk]
  if args.skip_module_sdk:
    entries = [entry for entry in entries if not entry.module_sdk]
  if not entries:
    sys.exit("Both APEXes and SDKs skipped - nothing to do.")

  install_paths = [entry.install_path for entry in entries]
  install_paths_per_root = install_paths_per_git_root(
      GIT_PROJECT_ROOTS, install_paths)

  branch_name = PREBUILT_DESCR.lower().replace(" ", "-") + "-update"
  if args.build:
    branch_name += "-" + args.build

  if not args.skip_cls:
    git_paths = list(install_paths_per_root.keys())
    start_branch(branch_name, git_paths)

  for git_root, subpaths in install_paths_per_root.items():
    remove_files(git_root, subpaths, not args.skip_cls)
  for entry in entries:
    install_entry(args.build, args.local_dist, entry)

  # Postprocess the Android.bp files in the SDK snapshot to control prefer flags
  # on the prebuilts through SOONG_CONFIG_art_module_source_build.
  # TODO(b/174997203): Replace this with a better way to control prefer flags on
  # Mainline module prebuilts.
  for entry in entries:
    if entry.install_unzipped:
      bp_path = os.path.join(entry.install_path, "Android.bp")
      if os.path.exists(bp_path):
        rewrite_bp_for_art_module_source_build(bp_path)

  if not args.skip_cls:
    for git_root, subpaths in install_paths_per_root.items():
      commit(git_root, PREBUILT_DESCR, BRANCH, TARGET, args.build, subpaths,
             args.bug)

    if args.upload:
      # Don't upload all projects in a single repo upload call, because that
      # makes it pop up an interactive editor.
      for git_root in install_paths_per_root:
        upload_branch(git_root, branch_name)


if __name__ == "__main__":
  main()
