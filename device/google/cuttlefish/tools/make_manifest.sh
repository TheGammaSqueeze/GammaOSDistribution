#!/bin/bash

# Copyright 2019 Google Inc. All rights reserved.

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

source "${ANDROID_BUILD_TOP}/external/shflags/src/shflags"

DEFINE_string loader1 \
  "" "Path to loader1 image (partition 1)" "l"
DEFINE_string env \
  "" "Path to env image (partition 2)" "e"
DEFINE_string loader2 \
  "" "Path to loader2 image (partition 3)" "u"
DEFINE_string trust \
  "" "Path to trust image (partition 4)" "t"
DEFINE_string rootfs \
  "" "Path to rootfs image (partition 5)" "r"
DEFINE_string tftp \
  "192.168.0.1" "TFTP server address" "f"
DEFINE_string tftpdir \
  "/tftpboot" "TFTP server directory" "d"
DEFINE_string version \
  "2" "Specify which manifest version to use (default: latest)" "v"
DEFINE_string ethaddr \
  "" "MAC address of device to DFU (default: all)" "m"
DEFINE_string kernel \
  "" "Path to kernel build dir" "k"

FLAGS_HELP="USAGE: $0 --kernel <dir> [flags]"

FLAGS "$@" || exit $?
eval set -- "${FLAGS_ARGV}"

for arg in "$@" ; do
	flags_help
	exit 1
done

if [ -z ${FLAGS_kernel} ]; then
	flags_help
	exit 1
fi

confirm() {
    read -r -p "${1:-Are you sure you want to continue? [y/N]} " response
    case "$response" in
        [yY][eE][sS]|[yY])
            true
            ;;
        *)
            false
            ;;
    esac
}

createManifest() {
	>>manifest.txt
}

addKVToManifest() {
	key=$1
	value=$2
	grep -q "^${key}=" manifest.txt && \
		sed -i "s/^${key}=.*/${key}=${value}/" manifest.txt || \
		echo "${key}=${value}" >> manifest.txt
}

addShaToManifest() {
	DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
	addKVToManifest "Sha" `${DIR}/gen_sha.sh --kernel ${FLAGS_kernel}`
}

addPathToManifest() {
	key=$1
	path=$2

	if [ "${path}" != "" ]; then
		filename=$(basename $path)
		filetype=`file -b --mime-type "${path}"`
		if [ "$key" == "UbootEnv" ] && [ "${filetype}" == "application/gzip" ]; then
			echo "error: gzip not supported for env images"
		fi
		if [ "$key" != "UbootEnv" ] && [ "${filetype}" != "application/gzip" ]; then
			echo "warning: gzip recommended for all non-env images"
			confirm || exit 1
		fi
		if [ ! "${path}" -ef "${FLAGS_tftpdir}/${filename}" ]; then
			cp "${path}" "${FLAGS_tftpdir}/"
		fi
	else
		unset filename
	fi

	addKVToManifest "${key}" "${filename}"
}

createManifest
addKVToManifest ManifestVersion ${FLAGS_version}
addKVToManifest TftpServer ${FLAGS_tftp}
addKVToManifest DFUethaddr ${FLAGS_ethaddr}
addPathToManifest RootfsImg ${FLAGS_rootfs}
addPathToManifest UbootEnv ${FLAGS_env}
addPathToManifest TplSplImg ${FLAGS_loader1}
addPathToManifest UbootItb ${FLAGS_loader2}
addShaToManifest
