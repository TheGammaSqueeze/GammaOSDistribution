#!/bin/bash -eu
# Copyright 2021 Google LLC
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
################################################################################


(
cd ../tinyxml2
make -j$(nproc) all
cp libtinyxml2.a /usr/local/lib/
cp *.h /usr/local/include/
)

(
cd ../asio/asio
sh autogen.sh
./configure
make -j$(nproc) install
)

(
cd ..
mkdir Fast-CDR/build && cd Fast-CDR/build
cmake .. -DBUILD_SHARED_LIBS=OFF
cmake --build . --target install
)

(
cd ..
cd foonathan_memory_vendor
mkdir build && cd build
cmake .. -DBUILD_SHARED_LIBS=OFF
cmake --build . --target install
)

# build project
git apply ../patch.diff
mkdir build && cd build
cmake .. -DBUILD_SHARED_LIBS=OFF
make -j $(nproc)
cp src/cpp/fuzz* $OUT/
