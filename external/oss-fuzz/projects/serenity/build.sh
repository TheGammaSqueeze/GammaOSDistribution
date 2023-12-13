#!/bin/bash -eu
# Copyright 2020 Google Inc.
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

# Now build the content
mkdir -p build
cd build
cmake -GNinja \
    -DBUILD_LAGOM=ON \
    -DENABLE_OSS_FUZZ=ON \
    -DCMAKE_C_COMPILER=$CC \
    -DCMAKE_CXX_COMPILER=$CXX \
    -DCMAKE_CXX_FLAGS="$CXXFLAGS -DOSS_FUZZ=ON" \
    -DLINKER_FLAGS="$LIB_FUZZING_ENGINE" \
    ..
ninja
cp Fuzzers/Fuzz* $OUT/

