#!/bin/bash -eux
#
# Copyright 2018 Google Inc.
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

# Install Boost headers
cd $SRC/
tar jxf boost_1_74_0.tar.bz2
cd boost_1_74_0/
CFLAGS="" CXXFLAGS="" ./bootstrap.sh
CFLAGS="" CXXFLAGS="" ./b2 headers
cp -R boost/ /usr/include/

# Prevent Boost compilation error with -std=c++17
export CXXFLAGS="$CXXFLAGS -D_LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR"

mkdir -p $WORK/libressl
cd $WORK/libressl

CMAKE_DEFINES=""
if [[ $CFLAGS = *sanitize=memory* ]]
then
  CMAKE_DEFINES+=" -DOPENSSL_NO_ASM=1"
fi

cmake -DCMAKE_C_COMPILER=$CC -DCMAKE_CXX_COMPILER=$CXX \
      -DCMAKE_C_FLAGS="$CFLAGS" -DCMAKE_CXX_FLAGS="$CXXFLAGS" \
      $CMAKE_DEFINES $SRC/libressl/
make -j$(nproc)

LIBRESSL_FUZZERS=$SRC/libressl.fuzzers
fuzzerFiles=$(find $LIBRESSL_FUZZERS -name "*.c" | egrep -v 'driver.c|test-corpus.c')

find . -name "*.a"

$CC -c $CFLAGS \
    -o $WORK/driver.o \
    $LIBRESSL_FUZZERS/driver.c \
    -I $SRC/libressl/include -I $SRC/libressl

for F in $fuzzerFiles; do
  fuzzerName=$(basename $F .c)
  echo "Building fuzzer $fuzzerName"
  $CC -c $CFLAGS \
      -o $WORK/${fuzzerName}.o \
      $F -I $SRC/libressl/include -I $SRC/libressl

  $CXX $CXXFLAGS \
      -o $OUT/${fuzzerName} -fsanitize-recover=address \
      $WORK/driver.o $WORK/${fuzzerName}.o ./ssl/libssl.a ./crypto/libcrypto.a ./tls/libtls.a $LIB_FUZZING_ENGINE

  if [ -d "$LIBRESSL_FUZZERS/corpora/${fuzzerName}/" ]; then
    zip -j $OUT/${fuzzerName}_seed_corpus.zip $LIBRESSL_FUZZERS/corpora/${fuzzerName}/*
  fi
done

cp $SRC/*.options $OUT/
cp $LIBRESSL_FUZZERS/oids.txt $OUT/asn1.dict
cp $LIBRESSL_FUZZERS/oids.txt $OUT/x509.dict

# Cryptofuzz
cd $SRC/cryptofuzz/
if [[ $CFLAGS = *sanitize=memory* ]]
then
    export CXXFLAGS="$CXXFLAGS -DMSAN"
fi
# Generate lookup tables
python3 gen_repository.py
# Compile Cryptofuzz LibreSSL module
cd $SRC/cryptofuzz/modules/openssl
OPENSSL_INCLUDE_PATH="$SRC/libressl/include" OPENSSL_LIBCRYPTO_A_PATH="$WORK/libressl/crypto/libcrypto.a" CXXFLAGS="$CXXFLAGS -DCRYPTOFUZZ_LIBRESSL" make
# Compile Cryptofuzz
cd $SRC/cryptofuzz/
LIBFUZZER_LINK="$LIB_FUZZING_ENGINE" CXXFLAGS="$CXXFLAGS -DCRYPTOFUZZ_LIBRESSL -I $SRC/libressl/include" make -j$(nproc)
# Generate dictionary
./generate_dict
# Copy fuzzer
cp $SRC/cryptofuzz/cryptofuzz $OUT/cryptofuzz
# Copy dictionary
cp $SRC/cryptofuzz/cryptofuzz-dict.txt $OUT/cryptofuzz.dict
# Copy seed corpus
cp $SRC/cryptofuzz-corpora/libressl_latest.zip $OUT/cryptofuzz_seed_corpus.zip
