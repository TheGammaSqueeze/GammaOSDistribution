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

cd $SRC/kamailio

export CC_OPT="${CFLAGS}"
export LD_EXTRA_OPTS="${CFLAGS}"

sed -i 's/int main(/int main2(/g' ./src/main.c

make || true
cd src
mkdir objects && find . -name "*.o" -exec cp {} ./objects/ \;
ar -r libkamilio.a ./objects/*.o
cd ../
$CC $CFLAGS $LIB_FUZZING_ENGINE ./misc/fuzz/fuzz_uri.c -o $OUT/fuzz_uri \
    -DFAST_LOCK -D__CPU_i386 ./src/libkamilio.a \
    -I./src/ -I./src/core/parser -ldl -lresolv -lm
