#!/bin/bash
#
# Copyright (C) 2017 The Android Open Source Project
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
# This script lists the boot jars that an ART bootclasspath would need.
#

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
TOP="$DIR/../.."

source "${TOP}/art/tools/build/var_cache.sh" >&/dev/null # import get_build_var

selected_env_var=
core_jars_only=n
print_file_path=n
mode=target
while true; do
  case $1 in
    --help)
      echo "Usage: $0 [--core] [--path] [--host|--target] [--help]"
      exit 0
      ;;
    --core)
      core_jars_only=y
      ;;
    --path)
      print_file_path=y
      ;;
    --host)
      mode=host
      ;;
    --target)
      mode=target
      ;;
    *)
      break
      ;;
  esac
  shift
done

if [[ $mode == target ]]; then
  if [[ $core_jars_only == y ]]; then
    selected_env_var=TARGET_TEST_CORE_JARS
  else
    selected_env_var=PRODUCT_BOOT_JARS
  fi
  intermediates_env_var=TARGET_OUT_COMMON_INTERMEDIATES
elif [[ $mode == host ]]; then
  if [[ $core_jars_only == n ]]; then
    echo "Error: --host does not have non-core boot jars, --core required" >&2
    exit 1
  fi
  selected_env_var=HOST_TEST_CORE_JARS
  intermediates_env_var=HOST_OUT_COMMON_INTERMEDIATES
fi

if [[ $core_jars_only == y ]]; then
  # FIXME: The soong invocation we're using for getting the variables does not give us anything
  # defined in Android.common_path.mk, otherwise we would just use HOST-/TARGET_TEST_CORE_JARS.

  # Note: This must start with the CORE_IMG_JARS in Android.common_path.mk
  # because that's what we use for compiling the boot.art image.
  # It may contain additional modules from TEST_CORE_JARS.
  core_jars_list="core-oj core-libart okhttp bouncycastle apache-xml core-icu4j"
  boot_jars_list=""
  boot_separator=""
  for boot_module in ${core_jars_list}; do
    jar_suffix=
    if [[ $mode == host ]]; then
      if [[ $boot_module == core-icu4j ]]; then
        jar_suffix="-host-hostdex"
      else
        jar_suffix="-hostdex"
      fi
    fi
    boot_jars_list+="${boot_separator}${boot_module}${jar_suffix}"
    boot_separator=" "
  done
else
  boot_jars_list=$(get_build_var "$selected_env_var")
fi

# Print only the list of boot jars.
if [[ $print_file_path == n ]]; then
  echo $boot_jars_list
  exit 0
fi

# Print the file path (relative to $TOP) to the classes.jar of each boot jar in the intermediates directory.
intermediates_dir=$(get_build_var "$intermediates_env_var")

# turn the file path into an absolute path if needed
pushd "$TOP" >/dev/null
intermediates_dir=$(readlink -m "$intermediates_dir")
popd >/dev/null

if [[ $mode == target ]]; then
  for jar in $boot_jars_list; do
    if [[ $jar == "conscrypt" ]]; then
      echo "$intermediates_dir/JAVA_LIBRARIES/${jar}.com.android.conscrypt_intermediates/classes.jar"
    elif [[ $jar == "core-icu4j" ]]; then
      # The location of ICU is different on an unbundled build.
      if [[ -f "$intermediates_dir/JAVA_LIBRARIES/${jar}.com.android.i18n_intermediates/classes.jar" ]]; then
        echo "$intermediates_dir/JAVA_LIBRARIES/${jar}.com.android.i18n_intermediates/classes.jar"
      else
        echo "$intermediates_dir/JAVA_LIBRARIES/${jar}_intermediates/classes.jar"
      fi
    else
      echo "$intermediates_dir/JAVA_LIBRARIES/${jar}.com.android.art.testing_intermediates/classes.jar"
    fi
  done
else
  for jar in $boot_jars_list; do
    echo "$intermediates_dir/JAVA_LIBRARIES/${jar}_intermediates/classes.jar"
  done
fi
