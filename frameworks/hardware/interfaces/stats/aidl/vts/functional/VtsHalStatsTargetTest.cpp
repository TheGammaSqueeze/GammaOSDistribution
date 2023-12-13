/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "VtsAidlHalStatsTest"

#include <aidl/Gtest.h>
#include <aidl/Vintf.h>

#include <aidl/android/frameworks/stats/IStats.h>
#include <android/binder_manager.h>
#include <android/log.h>

using aidl::android::frameworks::stats::IStats;
using aidl::android::frameworks::stats::VendorAtom;
using aidl::android::frameworks::stats::VendorAtomValue;

class StatsAidlTest : public ::testing::TestWithParam<std::string> {
   public:
    virtual void SetUp() override {
        ndk::SpAIBinder binder(AServiceManager_getService(GetParam().c_str()));
        client = IStats::fromBinder(binder);
        ASSERT_NE(client, nullptr);
    }

    virtual void TearDown() override {}

    std::shared_ptr<IStats> client;
};

// Validate IStats::reportVendorAtom.
TEST_P(StatsAidlTest, reportVendorAtom) {
    std::vector<VendorAtomValue> values;
    VendorAtomValue tmp;
    tmp.set<VendorAtomValue::longValue>(70000);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::intValue>(7);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::floatValue>(8.5);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::stringValue>("test");
    values.push_back(tmp);
    tmp.set<VendorAtomValue::intValue>(3);
    values.push_back(tmp);
    VendorAtom atom = {.reverseDomainName = "com.google.pixel", .atomId = 100001, .values = values};
    const ndk::ScopedAStatus ret = client->reportVendorAtom(atom);

    ASSERT_TRUE(ret.isOk());
}

// Validate IStats::reportVendorAtom - this is a negative test - the error is dumped to logcat
// Due to the AIDL reportVendorAtom is oneway API - the return code is not returned to the client
TEST_P(StatsAidlTest, reportVendorAtomInvalidAtomIdLow) {
    std::vector<VendorAtomValue> values;
    VendorAtomValue tmp;
    tmp.set<VendorAtomValue::longValue>(70000);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::intValue>(7);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::floatValue>(8.5);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::stringValue>("test");
    values.push_back(tmp);
    tmp.set<VendorAtomValue::intValue>(3);
    values.push_back(tmp);
    VendorAtom atom = {.reverseDomainName = "com.google.pixel", .atomId = 1000, .values = values};
    const ndk::ScopedAStatus ret = client->reportVendorAtom(atom);

    ASSERT_TRUE(ret.isOk());
}

// Validate IStats::reportVendorAtom - this is a negative test - the error is dumped to logcat
// Due to the AIDL reportVendorAtom is oneway API - the return code is not returned to the client
TEST_P(StatsAidlTest, reportVendorAtomInvalidAtomIdHigh) {
    std::vector<VendorAtomValue> values;
    VendorAtomValue tmp;
    tmp.set<VendorAtomValue::longValue>(70000);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::intValue>(7);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::floatValue>(8.5);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::stringValue>("test");
    values.push_back(tmp);
    tmp.set<VendorAtomValue::intValue>(3);
    values.push_back(tmp);
    VendorAtom atom = {.reverseDomainName = "com.google.pixel", .atomId = 300001, .values = values};
    const ndk::ScopedAStatus ret = client->reportVendorAtom(atom);

    ASSERT_TRUE(ret.isOk());
}

// Validate IStats::reportVendorAtom - this is a negative test - the error is dumped to logcat
// Due to the AIDL reportVendorAtom is oneway API - the return code is not returned to the client
TEST_P(StatsAidlTest, reportVendorAtomInvalidDomainNameTooLong) {
    std::vector<VendorAtomValue> values;
    VendorAtomValue tmp;
    tmp.set<VendorAtomValue::longValue>(70000);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::intValue>(7);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::floatValue>(8.5);
    values.push_back(tmp);
    tmp.set<VendorAtomValue::stringValue>("test");
    values.push_back(tmp);
    tmp.set<VendorAtomValue::intValue>(3);
    values.push_back(tmp);
    VendorAtom atom = {.reverseDomainName = "com.google.pixel.SubDomainName.SubDomainName.Domain",
                       .atomId = 100001,
                       .values = values};
    const ndk::ScopedAStatus ret = client->reportVendorAtom(atom);

    ASSERT_TRUE(ret.isOk());
}

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(StatsAidlTest);
INSTANTIATE_TEST_SUITE_P(PerInstance, StatsAidlTest,
                         testing::ValuesIn(android::getAidlHalInstanceNames(IStats::descriptor)),
                         android::PrintInstanceNameToString);
