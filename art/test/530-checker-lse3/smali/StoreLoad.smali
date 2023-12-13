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

.class public LStoreLoad;

.super Ljava/lang/Object;

## CHECK-START: int StoreLoad.test(int) load_store_elimination (before)
## CHECK-DAG:     <<Arg:i\d+>>    ParameterValue
## CHECK-DAG:                     StaticFieldSet [{{l\d+}},<<Arg>>] field_name:StoreLoad.byteField
## CHECK-DAG:                     StaticFieldSet [{{l\d+}},<<Arg>>] field_name:StoreLoad.byteField2
## CHECK-DAG:     <<Val:b\d+>>    StaticFieldGet [{{l\d+}}] field_name:StoreLoad.byteField
## CHECK-DAG:     <<Val2:b\d+>>   StaticFieldGet [{{l\d+}}] field_name:StoreLoad.byteField2
## CHECK-DAG:     <<Val3:i\d+>>   Add [<<Val>>,<<Val2>>]
## CHECK-DAG:                     Return [<<Val3>>]

## CHECK-START: int StoreLoad.test(int) load_store_elimination (after)
## CHECK-NOT:                     StaticFieldGet

## CHECK-START: int StoreLoad.test(int) load_store_elimination (after)
## CHECK-DAG:     <<Arg:i\d+>>    ParameterValue
## CHECK-DAG:                     StaticFieldSet [{{l\d+}},<<Arg>>] field_name:StoreLoad.byteField
## CHECK-DAG:                     StaticFieldSet [{{l\d+}},<<Arg>>] field_name:StoreLoad.byteField2
## CHECK-DAG:     <<Conv:b\d+>>   TypeConversion [<<Arg>>]
## CHECK-DAG:     <<Val3:i\d+>>   Add [<<Conv>>,<<Conv>>]
## CHECK-DAG:                     Return [<<Val3>>]
.method public static test(I)I
    .registers 2
    sput-byte v1, LStoreLoad;->byteField:B
    sput-byte v1, LStoreLoad;->byteField2:B
    sget-byte v0, LStoreLoad;->byteField:B
    sget-byte v1, LStoreLoad;->byteField2:B
    add-int/2addr v0, v1
    return v0
.end method

## CHECK-START: int StoreLoad.test2(int) load_store_elimination (before)
## CHECK-DAG:     <<Arg:i\d+>>    ParameterValue
## CHECK-DAG:                     StaticFieldSet [{{l\d+}},<<Arg>>] field_name:StoreLoad.byteField
## CHECK-DAG:                     Return [<<Arg>>]

## CHECK-START: int StoreLoad.test2(int) load_store_elimination (after)
## CHECK-NOT:                     TypeConversion
.method public static test2(I)I
    .registers 1
    sput-byte v0, LStoreLoad;->byteField:B
    return v0
.end method

## CHECK-START: int StoreLoad.test3(int) load_store_elimination (before)
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldGet
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     TypeConversion
## CHECK-DAG:                     Phi
## CHECK-DAG:                     StaticFieldGet

## CHECK-START: int StoreLoad.test3(int) load_store_elimination (after)
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     TypeConversion
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     Phi
## CHECK-DAG:                     Phi

## CHECK-START: int StoreLoad.test3(int) load_store_elimination (after)
## CHECK:                         Phi
## CHECK:                         Phi
## CHECK-NOT:                     Phi

## CHECK-START: int StoreLoad.test3(int) load_store_elimination (after)
## CHECK:                         TypeConversion
## CHECK-NOT:                     TypeConversion

## CHECK-START: int StoreLoad.test3(int) load_store_elimination (after)
## CHECK-NOT:                     StaticFieldGet
.method public static test3(I)I
    .registers 3
    const/4 v0, 0
    sput p0, LStoreLoad;->intField:I
    and-int/lit8 v1, p0, 1
    if-eqz v1, :skip

    sput-byte p0, LStoreLoad;->byteField:B
    sget-byte v1, LStoreLoad;->byteField:B
    sput v1, LStoreLoad;->intField:I
    # Test that this TypeConversion is moved and used for the
    # sget-byte above instead of creating a new one.
    int-to-byte v0, p0

    :skip
    sget v1, LStoreLoad;->intField:I
    add-int v0, v1, v0
    return v0
.end method

## CHECK-START: int StoreLoad.test4(int) load_store_elimination (before)
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldSet

## CHECK-START: int StoreLoad.test4(int) load_store_elimination (after)
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldSet
## CHECK-DAG:                     StaticFieldSet
.method public static test4(I)I
    # Test that stores are kept properly for an irreducible loop.
    .registers 3
    const/4 v0, 0
    const/4 v1, 7
    if-gt p0, v1, :skip1

    const/4 v1, 1
    sput v1, LStoreLoad;->intField:I
    goto :irreducible_loop_middle

    :skip1
    const/4 v1, 2
    sput v1, LStoreLoad;->intField:I
    # Fall through to the irreducible loop

    :irreducible_loop
    const/4 v1, 3
    sput v1, LStoreLoad;->intField:I
    if-eq v0, p0, :end

    :irreducible_loop_middle
    const/4 v1, 4
    sput v1, LStoreLoad;->intField:I
    add-int/lit8 v0, v0, 1
    goto :irreducible_loop

    :end
    return p0
.end method

.field public static intField:I
.field public static byteField:B
.field public static byteField2:B
