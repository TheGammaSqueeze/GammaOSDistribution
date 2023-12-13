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

# For coverage build we need to remove some flags when building protobuf and icu
if [ "$SANITIZER" = "coverage" ]
then
    export OCX=$CXXFLAGS
    export OC=$CFLAGS
    CF1=${CFLAGS//-fprofile-instr-generate/}
    export CFLAGS=${CF1//-fcoverage-mapping/}
    CXF1=${CXXFLAGS//-fprofile-instr-generate/}
    export CXXFLAGS=${CXF1//-fcoverage-mapping/}
fi

# Build Protobuf
git clone https://github.com/google/protobuf.git
cd protobuf
git submodule update --init --recursive
./autogen.sh
./configure
make -j$(nproc)
make install
ldconfig


# Build icu
export DEPS_PATH=/src/deps/
mkdir $DEPS_PATH

# build ICU for linking statically.
cd $SRC/icu/source
./configure --disable-shared --enable-static --disable-layoutex \
  --disable-tests --disable-samples --with-data-packaging=static --prefix=$DEPS_PATH
make install -j$(nproc)

# Ugly ugly hack to get static linking to work for icu.
cd $DEPS_PATH/lib
ls *.a | xargs -n1 ar x
rm *.a
ar r libicu.a *.{ao,o}
ln -s libicu.a libicudata.a
ln -s libicu.a libicuuc.a
ln -s libicu.a libicui18n.a

if [ "$SANITIZER" = "coverage" ]
then
    export CFLAGS=$OC
    export CXXFLAGS=$OCX
fi

# Build libphonenumber
cd $SRC/libphonenumber/cpp
sed -i 's/set (BUILD_SHARED_LIB true)/set (BUILD_SHARED_LIB false)/g' CMakeLists.txt
sed -i 's/list (APPEND CMAKE_C_FLAGS "-pthread")/string (APPEND CMAKE_C_FLAGS " -pthread")/g' CMakeLists.txt

mkdir build && cd build
cmake -DUSE_BOOST=OFF -DBUILD_GEOCODER=OFF -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
      -DICU_UC_INCLUDE_DIR=$SRC/icu/source/comon \
      -DICU_UC_LIB=$DEPS_PATH/lib/libicuuc.a \
      -DICU_I18N_INCLUDE_DIR=$SRC/icu/source/i18n/ \
      -DICU_I18N_LIB=$DEPS_PATH/lib/libicui18n.a  ../
make
cd ../

# Build our fuzzer
cp $SRC/*fuzz.cc .
$CXX -I/src/libphonenumber/cpp/src $CXXFLAGS -o phonefuzz.o -c phonefuzz.cc

$CXX $CXXFLAGS $LIB_FUZZING_ENGINE phonefuzz.o -o phonefuzz \
     build/libphonenumber.a $SRC/protobuf/src/.libs/libprotobuf.a \
     $DEPS_PATH/lib/libicu.a -lpthread

cp phonefuzz $OUT/
