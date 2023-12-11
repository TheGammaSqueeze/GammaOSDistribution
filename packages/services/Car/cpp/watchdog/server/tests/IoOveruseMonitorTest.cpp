/*
 * Copyright 2021 The Android Open Source Project
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

#include "IoOveruseMonitor.h"
#include "MockIoOveruseConfigs.h"
#include "MockPackageInfoResolver.h"
#include "MockProcDiskStats.h"
#include "MockResourceOveruseListener.h"
#include "MockUidStatsCollector.h"
#include "MockWatchdogServiceHelper.h"
#include "PackageInfoTestUtils.h"

#include <binder/IPCThreadState.h>
#include <binder/Status.h>
#include <utils/RefBase.h>

#include <functional>
#include <tuple>
#include <unordered_map>

namespace android {
namespace automotive {
namespace watchdog {

using ::android::IPCThreadState;
using ::android::RefBase;
using ::android::sp;
using ::android::automotive::watchdog::internal::IoOveruseAlertThreshold;
using ::android::automotive::watchdog::internal::PackageIdentifier;
using ::android::automotive::watchdog::internal::PackageInfo;
using ::android::automotive::watchdog::internal::PackageIoOveruseStats;
using ::android::automotive::watchdog::internal::ResourceOveruseConfiguration;
using ::android::automotive::watchdog::internal::UidType;
using ::android::automotive::watchdog::internal::UserPackageIoUsageStats;
using ::android::base::Error;
using ::android::base::Result;
using ::android::base::StringAppendF;
using ::android::binder::Status;
using ::testing::_;
using ::testing::DoAll;
using ::testing::Eq;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::SaveArg;
using ::testing::SetArgPointee;
using ::testing::UnorderedElementsAreArray;

namespace {

constexpr size_t kTestMonitorBufferSize = 3;
constexpr int64_t KTestMinSyncWrittenBytes = 5'000;
constexpr double kTestIoOveruseWarnPercentage = 80;
constexpr std::chrono::seconds kTestMonitorInterval = 5s;
constexpr std::chrono::seconds kMaxWaitSeconds = 5s;

IoOveruseAlertThreshold toIoOveruseAlertThreshold(const int64_t durationInSeconds,
                                                  const int64_t writtenBytesPerSecond) {
    IoOveruseAlertThreshold threshold;
    threshold.durationInSeconds = durationInSeconds;
    threshold.writtenBytesPerSecond = writtenBytesPerSecond;
    return threshold;
}

struct PackageWrittenBytes {
    PackageInfo packageInfo;
    int32_t foregroundBytes;
    int32_t backgroundBytes;
};

PerStateBytes constructPerStateBytes(const int64_t fgBytes, const int64_t bgBytes,
                                     const int64_t gmBytes) {
    PerStateBytes perStateBytes;
    perStateBytes.foregroundBytes = fgBytes;
    perStateBytes.backgroundBytes = bgBytes;
    perStateBytes.garageModeBytes = gmBytes;
    return perStateBytes;
}

IoOveruseStats constructIoOveruseStats(const bool isKillable, const PerStateBytes& remaining,
                                       const PerStateBytes& written, const int totalOveruses,
                                       const int64_t startTime, const int64_t durationInSeconds) {
    IoOveruseStats stats;
    stats.killableOnOveruse = isKillable;
    stats.remainingWriteBytes = remaining;
    stats.startTime = startTime;
    stats.durationInSeconds = durationInSeconds;
    stats.writtenBytes = written;
    stats.totalOveruses = totalOveruses;

    return stats;
}

ResourceOveruseStats constructResourceOveruseStats(IoOveruseStats ioOveruseStats) {
    ResourceOveruseStats stats;
    stats.set<ResourceOveruseStats::ioOveruseStats>(ioOveruseStats);
    return stats;
}

PackageIoOveruseStats constructPackageIoOveruseStats(
        const int32_t uid, const bool shouldNotify, const bool isKillable,
        const PerStateBytes& remaining, const PerStateBytes& written, const PerStateBytes& forgiven,
        const int totalOveruses, const int64_t startTime, const int64_t durationInSeconds) {
    PackageIoOveruseStats stats;
    stats.uid = uid;
    stats.shouldNotify = shouldNotify;
    stats.forgivenWriteBytes = forgiven;
    stats.ioOveruseStats = constructIoOveruseStats(isKillable, remaining, written, totalOveruses,
                                                   startTime, durationInSeconds);

    return stats;
}

UserPackageIoUsageStats constructUserPackageIoUsageStats(userid_t userId,
                                                         const std::string& packageName,
                                                         const PerStateBytes& writtenBytes,
                                                         const PerStateBytes& forgivenWriteBytes,
                                                         int32_t totalOveruses) {
    UserPackageIoUsageStats stats;
    stats.userId = userId;
    stats.packageName = packageName;
    stats.ioUsageStats.writtenBytes = writtenBytes;
    stats.ioUsageStats.forgivenWriteBytes = forgivenWriteBytes;
    stats.ioUsageStats.totalOveruses = totalOveruses;
    return stats;
}

class ScopedChangeCallingUid : public RefBase {
public:
    explicit ScopedChangeCallingUid(uid_t uid) {
        mCallingUid = IPCThreadState::self()->getCallingUid();
        mCallingPid = IPCThreadState::self()->getCallingPid();
        if (mCallingUid == uid) {
            return;
        }
        mChangedUid = uid;
        int64_t token = ((int64_t)mChangedUid << 32) | mCallingPid;
        IPCThreadState::self()->restoreCallingIdentity(token);
    }
    ~ScopedChangeCallingUid() {
        if (mCallingUid == mChangedUid) {
            return;
        }
        int64_t token = ((int64_t)mCallingUid << 32) | mCallingPid;
        IPCThreadState::self()->restoreCallingIdentity(token);
    }

private:
    uid_t mCallingUid;
    uid_t mChangedUid;
    pid_t mCallingPid;
};

std::string toString(const std::vector<PackageIoOveruseStats>& ioOveruseStats) {
    if (ioOveruseStats.empty()) {
        return "empty";
    }
    std::string buffer;
    for (const auto& stats : ioOveruseStats) {
        StringAppendF(&buffer, "%s\n", stats.toString().c_str());
    }
    return buffer;
}

}  // namespace

namespace internal {

class IoOveruseMonitorPeer : public RefBase {
public:
    explicit IoOveruseMonitorPeer(const sp<IoOveruseMonitor>& ioOveruseMonitor) :
          mIoOveruseMonitor(ioOveruseMonitor) {}

    Result<void> init(const sp<IIoOveruseConfigs>& ioOveruseConfigs,
                      const sp<IPackageInfoResolver>& packageInfoResolver) {
        if (const auto result = mIoOveruseMonitor->init(); !result.ok()) {
            return result;
        }
        mIoOveruseMonitor->mMinSyncWrittenBytes = KTestMinSyncWrittenBytes;
        mIoOveruseMonitor->mPeriodicMonitorBufferSize = kTestMonitorBufferSize;
        mIoOveruseMonitor->mIoOveruseWarnPercentage = kTestIoOveruseWarnPercentage;
        mIoOveruseMonitor->mIoOveruseConfigs = ioOveruseConfigs;
        mIoOveruseMonitor->mPackageInfoResolver = packageInfoResolver;
        return {};
    }

private:
    sp<IoOveruseMonitor> mIoOveruseMonitor;
};

}  // namespace internal

class IoOveruseMonitorTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        mMockWatchdogServiceHelper = sp<MockWatchdogServiceHelper>::make();
        mMockIoOveruseConfigs = sp<MockIoOveruseConfigs>::make();
        mMockPackageInfoResolver = sp<MockPackageInfoResolver>::make();
        mMockUidStatsCollector = sp<MockUidStatsCollector>::make();
        mIoOveruseMonitor = sp<IoOveruseMonitor>::make(mMockWatchdogServiceHelper);
        mIoOveruseMonitorPeer = sp<internal::IoOveruseMonitorPeer>::make(mIoOveruseMonitor);
        mIoOveruseMonitorPeer->init(mMockIoOveruseConfigs, mMockPackageInfoResolver);
        setUpPackagesAndConfigurations();
    }

    virtual void TearDown() {
        mMockWatchdogServiceHelper.clear();
        mMockIoOveruseConfigs.clear();
        mMockPackageInfoResolver.clear();
        mMockUidStatsCollector.clear();
        mIoOveruseMonitor.clear();
        mIoOveruseMonitorPeer.clear();
    }

    void setUpPackagesAndConfigurations() {
        ON_CALL(*mMockPackageInfoResolver, getPackageInfosForUids(_))
                .WillByDefault(Return(kPackageInfosByUid));
        mMockIoOveruseConfigs->injectPackageConfigs({
                {"system.daemon",
                 {constructPerStateBytes(/*fgBytes=*/80'000, /*bgBytes=*/40'000,
                                         /*gmBytes=*/100'000),
                  /*isSafeToKill=*/false}},
                {"com.android.google.package",
                 {constructPerStateBytes(/*fgBytes=*/70'000, /*bgBytes=*/30'000,
                                         /*gmBytes=*/100'000),
                  /*isSafeToKill=*/true}},
                {"com.android.kitchensink",
                 {constructPerStateBytes(/*fgBytes=*/30'000, /*bgBytes=*/15'000,
                                         /*gmBytes=*/10'000),
                  /*isSafeToKill=*/true}},
        });
    }

    std::vector<UidStats> constructUidStats(
            std::unordered_map<uid_t, std::tuple<int32_t, int32_t>> writtenBytesByUid) {
        std::vector<UidStats> uidStats;
        for (const auto& [uid, writtenBytes] : writtenBytesByUid) {
            PackageInfo packageInfo;
            if (kPackageInfosByUid.find(uid) != kPackageInfosByUid.end()) {
                packageInfo = kPackageInfosByUid.at(uid);
            } else {
                packageInfo.packageIdentifier.uid = uid;
            }
            uidStats.push_back(UidStats{.packageInfo = packageInfo,
                                        .ioStats = {/*fgRdBytes=*/989'000,
                                                    /*bgRdBytes=*/678'000,
                                                    /*fgWrBytes=*/std::get<0>(writtenBytes),
                                                    /*bgWrBytes=*/std::get<1>(writtenBytes),
                                                    /*fgFsync=*/10'000, /*bgFsync=*/50'000}});
        }
        return uidStats;
    }

    void executeAsUid(uid_t uid, std::function<void()> func) {
        sp<ScopedChangeCallingUid> scopedChangeCallingUid = sp<ScopedChangeCallingUid>::make(uid);
        ASSERT_NO_FATAL_FAILURE(func());
    }

    sp<MockWatchdogServiceHelper> mMockWatchdogServiceHelper;
    sp<MockIoOveruseConfigs> mMockIoOveruseConfigs;
    sp<MockPackageInfoResolver> mMockPackageInfoResolver;
    sp<MockUidStatsCollector> mMockUidStatsCollector;
    sp<IoOveruseMonitor> mIoOveruseMonitor;
    sp<internal::IoOveruseMonitorPeer> mIoOveruseMonitorPeer;

    static const std::unordered_map<uid_t, PackageInfo> kPackageInfosByUid;
};

const std::unordered_map<uid_t, PackageInfo> IoOveruseMonitorTest::kPackageInfosByUid =
        {{1001000,
          constructPackageInfo(
                  /*packageName=*/"system.daemon",
                  /*uid=*/1001000, UidType::NATIVE)},
         {1112345,
          constructPackageInfo(
                  /*packageName=*/"com.android.google.package",
                  /*uid=*/1112345, UidType::APPLICATION)},
         {1113999,
          constructPackageInfo(
                  /*packageName=*/"com.android.google.package",
                  /*uid=*/1113999, UidType::APPLICATION)},
         {1212345,
          constructPackageInfo(
                  /*packageName=*/"com.android.google.package",
                  /*uid=*/1212345, UidType::APPLICATION)},
         {1245678,
          constructPackageInfo(
                  /*packageName=*/"com.android.kitchensink",
                  /*uid=*/1245678, UidType::APPLICATION)},
         {1312345,
          constructPackageInfo(
                  /*packageName=*/"com.android.google.package",
                  /*uid=*/1312345, UidType::APPLICATION)}};

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollection) {
    sp<MockResourceOveruseListener> mockResourceOveruseListener =
            sp<MockResourceOveruseListener>::make();
    ASSERT_NO_FATAL_FAILURE(executeAsUid(1001000, [&]() {
        ASSERT_RESULT_OK(mIoOveruseMonitor->addIoOveruseListener(mockResourceOveruseListener));
    }));

    /*
     * Package "system.daemon" (UID: 1001000) exceeds warn threshold percentage of 80% but no
     * warning is issued as it is a native UID.
     */
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/20'000}},
                                       {1112345, {/*fgWrBytes=*/35'000, /*bgWrBytes=*/15'000}},
                                       {1212345, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/20'000}}})));

    std::vector<PackageIoOveruseStats> actualIoOveruseStats;
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    std::vector<PackageIoOveruseStats> expectedIoOveruseStats =
            {constructPackageIoOveruseStats(/*uid=*/1001000, /*shouldNotify=*/false,
                                            /*isKillable=*/false, /*remaining=*/
                                            constructPerStateBytes(10'000, 20'000, 100'000),
                                            /*written=*/constructPerStateBytes(70'000, 20'000, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds),
             constructPackageIoOveruseStats(/*uid=*/1112345, /*shouldNotify=*/false,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(35'000, 15'000, 100'000),
                                            /*written=*/constructPerStateBytes(35'000, 15'000, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds),
             // Exceeds threshold.
             constructPackageIoOveruseStats(/*uid=*/1212345, /*shouldNotify=*/true,
                                            /*isKillable=*/true,
                                            /*remaining=*/
                                            constructPerStateBytes(0, 10'000, 100'000),
                                            /*written=*/constructPerStateBytes(70'000, 20'000, 0),
                                            /*forgiven=*/constructPerStateBytes(70'000, 0, 0),
                                            /*totalOveruses=*/1, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);

    ResourceOveruseStats actualOverusingNativeStats;
    // Package "com.android.google.package" for user 11 changed uid from 1112345 to 1113999.
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/30'000, /*bgWrBytes=*/0}},
                                       {1113999, {/*fgWrBytes=*/25'000, /*bgWrBytes=*/10'000}},
                                       {1212345, {/*fgWrBytes=*/20'000, /*bgWrBytes=*/30'000}}})));
    actualIoOveruseStats.clear();
    EXPECT_CALL(*mockResourceOveruseListener, onOveruse(_))
            .WillOnce(DoAll(SaveArg<0>(&actualOverusingNativeStats), Return(Status::ok())));
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    const auto expectedOverusingNativeStats = constructResourceOveruseStats(
            constructIoOveruseStats(/*isKillable=*/false,
                                    /*remaining=*/constructPerStateBytes(0, 20'000, 100'000),
                                    /*written=*/constructPerStateBytes(100'000, 20'000, 0),
                                    /*totalOveruses=*/1, startTime, durationInSeconds));
    EXPECT_THAT(actualOverusingNativeStats, Eq(expectedOverusingNativeStats))
            << "Expected: " << expectedOverusingNativeStats.toString()
            << "\nActual: " << actualOverusingNativeStats.toString();

    expectedIoOveruseStats =
            {constructPackageIoOveruseStats(/*uid=*/1001000, /*shouldNotify=*/true,
                                            /*isKillable=*/false, /*remaining=*/
                                            constructPerStateBytes(0, 20'000, 100'000),
                                            /*written=*/constructPerStateBytes(100'000, 20'000, 0),
                                            /*forgiven=*/constructPerStateBytes(80'000, 0, 0),
                                            /*totalOveruses=*/1, startTime, durationInSeconds),
             // Exceeds warn threshold percentage.
             constructPackageIoOveruseStats(/*uid=*/1113999, /*shouldNotify=*/true,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(10'000, 5'000, 100'000),
                                            /*written=*/constructPerStateBytes(60'000, 25'000, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds),
             /*
              * Exceeds threshold.
              * The package was forgiven on previous overuse so the remaining bytes should only
              * reflect the bytes written after the forgiven bytes.
              */
             constructPackageIoOveruseStats(/*uid=*/1212345, /*shouldNotify=*/true,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(50'000, 0, 100'000),
                                            /*written=*/constructPerStateBytes(90'000, 50'000, 0),
                                            /*forgiven=*/constructPerStateBytes(70'000, 30'000, 0),
                                            /*totalOveruses=*/2, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);

    /*
     * Current date changed so the daily I/O usage stats should be reset and the latest I/O overuse
     * stats should not aggregate with the previous day's stats.
     */
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/78'000, /*bgWrBytes=*/38'000}},
                                       {1113999, {/*fgWrBytes=*/55'000, /*bgWrBytes=*/23'000}},
                                       {1212345, {/*fgWrBytes=*/55'000, /*bgWrBytes=*/23'000}}})));
    actualIoOveruseStats.clear();
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    currentTime += (24 * 60 * 60);  // Change collection time to next day.
    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    const auto [nextDayStartTime, nextDayDuration] = calculateStartAndDuration(currentTime);
    expectedIoOveruseStats =
            {constructPackageIoOveruseStats(/*uid=*/1001000, /*shouldNotify=*/false,
                                            /*isKillable=*/false, /*remaining=*/
                                            constructPerStateBytes(2'000, 2'000, 100'000),
                                            /*written=*/constructPerStateBytes(78'000, 38'000, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, nextDayStartTime, nextDayDuration),
             constructPackageIoOveruseStats(/*uid=*/1113999, /*shouldNotify=*/false,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(15'000, 7'000, 100'000),
                                            /*written=*/constructPerStateBytes(55'000, 23'000, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, nextDayStartTime, nextDayDuration),
             constructPackageIoOveruseStats(/*uid=*/1212345, /*shouldNotify=*/false,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(15'000, 7'000, 100'000),
                                            /*written=*/constructPerStateBytes(55'000, 23'000, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, nextDayStartTime,
                                            nextDayDuration)};

    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollectionWithGarageMode) {
    sp<MockResourceOveruseListener> mockResourceOveruseListener =
            sp<MockResourceOveruseListener>::make();
    ASSERT_NO_FATAL_FAILURE(executeAsUid(1001000, [&]() {
        ASSERT_RESULT_OK(mIoOveruseMonitor->addIoOveruseListener(mockResourceOveruseListener));
    }));

    /*
     * Package "system.daemon" (UID: 1001000) exceeds warn threshold percentage of 80% but no
     * warning is issued as it is a native UID.
     */
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/60'000}},
                                       {1112345, {/*fgWrBytes=*/35'000, /*bgWrBytes=*/15'000}},
                                       {1212345, {/*fgWrBytes=*/90'000, /*bgWrBytes=*/20'000}}})));

    ResourceOveruseStats actualOverusingNativeStats;
    EXPECT_CALL(*mockResourceOveruseListener, onOveruse(_))
            .WillOnce(DoAll(SaveArg<0>(&actualOverusingNativeStats), Return(Status::ok())));
    std::vector<PackageIoOveruseStats> actualIoOveruseStats;
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::GARAGE_MODE,
                                                             mMockUidStatsCollector, nullptr));

    const auto expectedOverusingNativeStats = constructResourceOveruseStats(
            constructIoOveruseStats(/*isKillable=*/false,
                                    /*remaining=*/constructPerStateBytes(80'000, 40'000, 0),
                                    /*written=*/constructPerStateBytes(0, 0, 130'000),
                                    /*totalOveruses=*/1, startTime, durationInSeconds));
    EXPECT_THAT(actualOverusingNativeStats, Eq(expectedOverusingNativeStats))
            << "Expected: " << expectedOverusingNativeStats.toString()
            << "\nActual: " << actualOverusingNativeStats.toString();

    const std::vector<PackageIoOveruseStats> expectedIoOveruseStats =
            {constructPackageIoOveruseStats(/*uid=*/1001000, /*shouldNotify=*/true,
                                            /*isKillable=*/false, /*remaining=*/
                                            constructPerStateBytes(80'000, 40'000, 0),
                                            /*written=*/constructPerStateBytes(0, 0, 130'000),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 100'000),
                                            /*totalOveruses=*/1, startTime, durationInSeconds),
             constructPackageIoOveruseStats(/*uid=*/1112345, /*shouldNotify=*/false,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(70'000, 30'000, 50'000),
                                            /*written=*/constructPerStateBytes(0, 0, 50'000),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds),
             // Exceeds threshold.
             constructPackageIoOveruseStats(/*uid=*/1212345, /*shouldNotify=*/true,
                                            /*isKillable=*/true,
                                            /*remaining=*/
                                            constructPerStateBytes(70'000, 30'000, 0),
                                            /*written=*/constructPerStateBytes(0, 0, 110'000),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 100'000),
                                            /*totalOveruses=*/1, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollectionWithZeroWriteBytes) {
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(constructUidStats({{1001000, {/*fgWrBytes=*/0, /*bgWrBytes=*/0}},
                                                {1112345, {/*fgWrBytes=*/0, /*bgWrBytes=*/0}},
                                                {1212345, {/*fgWrBytes=*/0, /*bgWrBytes=*/0}}})));

    EXPECT_CALL(*mMockPackageInfoResolver, getPackageInfosForUids(_)).Times(0);
    EXPECT_CALL(*mMockIoOveruseConfigs, fetchThreshold(_)).Times(0);
    EXPECT_CALL(*mMockIoOveruseConfigs, isSafeToKill(_)).Times(0);
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_)).Times(0);

    ASSERT_RESULT_OK(
            mIoOveruseMonitor->onPeriodicCollection(std::chrono::system_clock::to_time_t(
                                                            std::chrono::system_clock::now()),
                                                    SystemState::NORMAL_MODE,
                                                    mMockUidStatsCollector, nullptr));
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollectionWithExtremeOveruse) {
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/190'000, /*bgWrBytes=*/42'000}},
                                       {1212345, {/*fgWrBytes=*/90'000, /*bgWrBytes=*/90'000}}})));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    std::vector<PackageIoOveruseStats> actualPackageIoOveruseStats;
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualPackageIoOveruseStats), Return(Status::ok())));

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    std::vector<PackageIoOveruseStats> expectedPackageIoOveruseStats =
            {constructPackageIoOveruseStats(/*uid=*/1001000, /*shouldNotify=*/true,
                                            /*isKillable=*/false, /*remaining=*/
                                            constructPerStateBytes(0, 0, 100'000),
                                            /*written=*/constructPerStateBytes(190'000, 42'000, 0),
                                            /*forgiven=*/constructPerStateBytes(160'000, 40'000, 0),
                                            /*totalOveruses=*/3, startTime, durationInSeconds),
             constructPackageIoOveruseStats(/*uid=*/1212345, /*shouldNotify=*/true,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(0, 0, 100'000),
                                            /*written=*/constructPerStateBytes(90'000, 90'000, 0),
                                            /*forgiven=*/constructPerStateBytes(70'000, 90'000, 0),
                                            /*totalOveruses=*/4, startTime, durationInSeconds)};
    EXPECT_THAT(actualPackageIoOveruseStats,
                UnorderedElementsAreArray(expectedPackageIoOveruseStats))
            << "Expected: " << toString(expectedPackageIoOveruseStats)
            << "\nActual: " << toString(actualPackageIoOveruseStats);
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollectionWithExtremeOveruseInGarageMode) {
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/190'000, /*bgWrBytes=*/42'000}},
                                       {1212345, {/*fgWrBytes=*/90'000, /*bgWrBytes=*/90'000}}})));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    std::vector<PackageIoOveruseStats> actualPackageIoOveruseStats;
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualPackageIoOveruseStats), Return(Status::ok())));

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::GARAGE_MODE,
                                                             mMockUidStatsCollector, nullptr));

    std::vector<PackageIoOveruseStats> expectedPackageIoOveruseStats =
            {constructPackageIoOveruseStats(/*uid=*/1001000, /*shouldNotify=*/true,
                                            /*isKillable=*/false, /*remaining=*/
                                            constructPerStateBytes(80'000, 40'000, 0),
                                            /*written=*/constructPerStateBytes(0, 0, 232'000),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 200'000),
                                            /*totalOveruses=*/2, startTime, durationInSeconds),
             constructPackageIoOveruseStats(/*uid=*/1212345, /*shouldNotify=*/true,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(70'000, 30'000, 0),
                                            /*written=*/constructPerStateBytes(0, 0, 180'000),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 100'000),
                                            /*totalOveruses=*/1, startTime, durationInSeconds)};
    EXPECT_THAT(actualPackageIoOveruseStats,
                UnorderedElementsAreArray(expectedPackageIoOveruseStats))
            << "Expected: " << toString(expectedPackageIoOveruseStats)
            << "\nActual: " << toString(actualPackageIoOveruseStats);
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollectionWithSmallWrittenBytes) {
    /*
     * UID 1212345 current written bytes < |KTestMinSyncWrittenBytes| so the UID's stats are not
     * synced.
     */
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/59'200, /*bgWrBytes=*/0}},
                                       {1112345, {/*fgWrBytes=*/0, /*bgWrBytes=*/25'200}},
                                       {1212345, {/*fgWrBytes=*/300, /*bgWrBytes=*/600}},
                                       {1312345, {/*fgWrBytes=*/51'200, /*bgWrBytes=*/0}}})));

    std::vector<PackageIoOveruseStats> actualIoOveruseStats;
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    std::vector<PackageIoOveruseStats> expectedIoOveruseStats =
            {constructPackageIoOveruseStats(/*uid=*/1001000, /*shouldNotify=*/false,
                                            /*isKillable=*/false, /*remaining=*/
                                            constructPerStateBytes(20'800, 40'000, 100'000),
                                            /*written=*/
                                            constructPerStateBytes(59'200, 0, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds),
             constructPackageIoOveruseStats(/*uid=*/1112345, /*shouldNotify=*/true,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(70'000, 4'800, 100'000),
                                            /*written=*/constructPerStateBytes(0, 25'200, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds),
             constructPackageIoOveruseStats(/*uid=*/1312345, /*shouldNotify=*/false,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(18'800, 30'000, 100'000),
                                            /*written=*/constructPerStateBytes(51'200, 0, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds)};

    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);

    actualIoOveruseStats.clear();
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    /*
     * UID 1001000 current written bytes is < |kTestMinSyncWrittenBytes| but exceeds warn threshold
     * but not killable so the UID's stats are not synced.
     * UID 1112345 current written bytes is < |kTestMinSyncWrittenBytes| but exceeds threshold so
     * the UID's stats are synced.
     * UID 1212345 current written bytes is < |kTestMinSyncWrittenBytes| but total written bytes
     * since last synced > |kTestMinSyncWrittenBytes| so the UID's stats are synced.
     * UID 1312345 current written bytes is < |kTestMinSyncWrittenBytes| but exceeds warn threshold
     * and killable so the UID's stat are synced.
     */
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(constructUidStats(
                    {{1001000, {/*fgWrBytes=*/KTestMinSyncWrittenBytes - 100, /*bgWrBytes=*/0}},
                     {1112345, {/*fgWrBytes=*/0, /*bgWrBytes=*/KTestMinSyncWrittenBytes - 100}},
                     {1212345, {/*fgWrBytes=*/KTestMinSyncWrittenBytes - 300, /*bgWrBytes=*/0}},
                     {1312345, {/*fgWrBytes=*/KTestMinSyncWrittenBytes - 100, /*bgWrBytes=*/0}}})));

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    expectedIoOveruseStats =
            {constructPackageIoOveruseStats(/*uid=*/1112345, /*shouldNotify=*/true,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(70'000, 0, 100'000),
                                            /*written=*/constructPerStateBytes(0, 30'100, 0),
                                            /*forgiven=*/
                                            constructPerStateBytes(0, 30'000, 0),
                                            /*totalOveruses=*/1, startTime, durationInSeconds),
             constructPackageIoOveruseStats(/*uid=*/1212345, /*shouldNotify=*/false,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(65'000, 29'400, 100'000),
                                            /*written=*/constructPerStateBytes(5'000, 600, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds),
             constructPackageIoOveruseStats(/*uid=*/1312345, /*shouldNotify=*/true,
                                            /*isKillable=*/true, /*remaining=*/
                                            constructPerStateBytes(13'900, 30'000, 100'000),
                                            /*written=*/constructPerStateBytes(56'100, 0, 0),
                                            /*forgiven=*/constructPerStateBytes(0, 0, 0),
                                            /*totalOveruses=*/0, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollectionWithNoPackageInfo) {
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{2301000, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/20'000}},
                                       {2412345, {/*fgWrBytes=*/35'000, /*bgWrBytes=*/15'000}},
                                       {2512345, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/20'000}}})));

    EXPECT_CALL(*mMockIoOveruseConfigs, fetchThreshold(_)).Times(0);
    EXPECT_CALL(*mMockIoOveruseConfigs, isSafeToKill(_)).Times(0);
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_)).Times(0);

    ASSERT_RESULT_OK(
            mIoOveruseMonitor->onPeriodicCollection(std::chrono::system_clock::to_time_t(
                                                            std::chrono::system_clock::now()),
                                                    SystemState::NORMAL_MODE,
                                                    mMockUidStatsCollector, nullptr));
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollectionWithPrevBootStats) {
    std::vector<UserPackageIoUsageStats> todayIoUsageStats =
            {constructUserPackageIoUsageStats(
                     /*userId=*/11, "com.android.google.package",
                     /*writtenBytes=*/constructPerStateBytes(100'000, 85'000, 120'000),
                     /*forgivenWriteBytes=*/constructPerStateBytes(70'000, 60'000, 100'000),
                     /*totalOveruses=*/3),
             constructUserPackageIoUsageStats(
                     /*userId=*/12, "com.android.kitchensink",
                     /*writtenBytes=*/constructPerStateBytes(50'000, 40'000, 35'000),
                     /*forgivenWriteBytes=*/constructPerStateBytes(30'000, 30'000, 30'000),
                     /*totalOveruses=*/6)};
    EXPECT_CALL(*mMockWatchdogServiceHelper, getTodayIoUsageStats(_))
            .WillOnce(DoAll(SetArgPointee<0>(todayIoUsageStats), Return(Status::ok())));

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/20'000}},
                                       {1112345, {/*fgWrBytes=*/35'000, /*bgWrBytes=*/15'000}}})));

    std::vector<PackageIoOveruseStats> actualIoOveruseStats;
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    std::vector<PackageIoOveruseStats> expectedIoOveruseStats =
            {constructPackageIoOveruseStats(
                     /*uid*=*/1001000, /*shouldNotify=*/false, /*isKillable=*/false,
                     /*remaining=*/constructPerStateBytes(10'000, 20'000, 100'000),
                     /*written=*/constructPerStateBytes(70'000, 20'000, 0),
                     /*forgiven=*/constructPerStateBytes(0, 0, 0),
                     /*totalOveruses=*/0, startTime, durationInSeconds),
             constructPackageIoOveruseStats(
                     /*uid*=*/1112345, /*shouldNotify=*/true, /*isKillable=*/true,
                     /*remaining=*/constructPerStateBytes(5'000, 0, 80'000),
                     /*written=*/constructPerStateBytes(135'000, 100'000, 120'000),
                     /*forgiven=*/constructPerStateBytes(70'000, 90'000, 100'000),
                     /*totalOveruses=*/4, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1112345, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/40'000}},
                                       {1245678, {/*fgWrBytes=*/30'000, /*bgWrBytes=*/10'000}}})));

    actualIoOveruseStats.clear();
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::GARAGE_MODE,
                                                             mMockUidStatsCollector, nullptr));

    expectedIoOveruseStats = {constructPackageIoOveruseStats(
                                      /*uid*=*/1112345, /*shouldNotify=*/true, /*isKillable=*/true,
                                      /*remaining=*/constructPerStateBytes(5'000, 20'000, 0),
                                      /*written=*/constructPerStateBytes(135'000, 100'000, 230'000),
                                      /*forgiven=*/constructPerStateBytes(70'000, 90'000, 200'000),
                                      /*totalOveruses=*/5, startTime, durationInSeconds),
                              constructPackageIoOveruseStats(
                                      /*uid*=*/1245678, /*shouldNotify=*/true, /*isKillable=*/true,
                                      /*remaining=*/constructPerStateBytes(10'000, 5'000, 0),
                                      /*written=*/constructPerStateBytes(50'000, 40'000, 75'000),
                                      /*forgiven=*/constructPerStateBytes(30'000, 30'000, 70'000),
                                      /*totalOveruses=*/10, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicCollectionWithErrorFetchingPrevBootStats) {
    EXPECT_CALL(*mMockWatchdogServiceHelper, getTodayIoUsageStats(_))
            .WillOnce(Return(Status::fromExceptionCode(Status::EX_ILLEGAL_STATE, "Illegal state")));

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1112345, {/*fgWrBytes=*/15'000, /*bgWrBytes=*/15'000}}})));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    std::vector<UserPackageIoUsageStats> todayIoUsageStats = {constructUserPackageIoUsageStats(
            /*userId=*/11, "com.android.google.package",
            /*writtenBytes=*/constructPerStateBytes(100'000, 85'000, 120'000),
            /*forgivenWriteBytes=*/constructPerStateBytes(70'000, 60'000, 100'000),
            /*totalOveruses=*/3)};
    EXPECT_CALL(*mMockWatchdogServiceHelper, getTodayIoUsageStats(_))
            .WillOnce(DoAll(SetArgPointee<0>(todayIoUsageStats), Return(Status::ok())));

    std::vector<PackageIoOveruseStats> actualIoOveruseStats;
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1112345, {/*fgWrBytes=*/20'000, /*bgWrBytes=*/40'000}}})));

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    std::vector<PackageIoOveruseStats> expectedIoOveruseStats = {constructPackageIoOveruseStats(
            /*uid*=*/1112345, /*shouldNotify=*/true, /*isKillable=*/true,
            /*remaining=*/constructPerStateBytes(5'000, 0, 80'000),
            /*written=*/constructPerStateBytes(135'000, 140'000, 120'000),
            /*forgiven=*/constructPerStateBytes(70'000, 120'000, 100'000),
            /*totalOveruses=*/5, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);
}

TEST_F(IoOveruseMonitorTest, TestOnPeriodicMonitor) {
    IIoOveruseConfigs::IoOveruseAlertThresholdSet alertThresholds =
            {toIoOveruseAlertThreshold(
                     /*durationInSeconds=*/10, /*writtenBytesPerSecond=*/15'360),
             toIoOveruseAlertThreshold(
                     /*durationInSeconds=*/17, /*writtenBytesPerSecond=*/10'240),
             toIoOveruseAlertThreshold(
                     /*durationInSeconds=*/23, /*writtenBytesPerSecond=*/7'168)};
    ON_CALL(*mMockIoOveruseConfigs, systemWideAlertThresholds())
            .WillByDefault(ReturnRef(alertThresholds));

    time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto nextCollectionTime = [&]() -> time_t {
        time += kTestMonitorInterval.count();
        return time;
    };
    bool isAlertReceived = false;
    const auto alertHandler = [&]() { isAlertReceived = true; };

    // 1st polling is ignored
    sp<MockProcDiskStats> mockProcDiskStats = sp<MockProcDiskStats>::make();
    EXPECT_CALL(*mockProcDiskStats, deltaSystemWideDiskStats()).Times(0);

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicMonitor(nextCollectionTime(), mockProcDiskStats,
                                                          alertHandler));
    EXPECT_FALSE(isAlertReceived) << "Triggered spurious alert because first polling is ignored";

    // 2nd polling - guarded by the heuristic to handle spurious alerting on partially filled buffer
    EXPECT_CALL(*mockProcDiskStats, deltaSystemWideDiskStats()).WillOnce([]() -> DiskStats {
        return DiskStats{.numKibWritten = 70};
    });

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicMonitor(nextCollectionTime(), mockProcDiskStats,
                                                          alertHandler));
    EXPECT_FALSE(isAlertReceived) << "Triggered spurious alert when not exceeding the threshold";

    // 3rd polling exceeds first threshold
    EXPECT_CALL(*mockProcDiskStats, deltaSystemWideDiskStats()).WillOnce([]() -> DiskStats {
        return DiskStats{.numKibWritten = 90};
    });

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicMonitor(nextCollectionTime(), mockProcDiskStats,
                                                          alertHandler));
    EXPECT_TRUE(isAlertReceived) << "Failed to trigger alert when exceeding the threshold";

    isAlertReceived = false;

    // 4th polling - guarded by the heuristic to handle spurious alerting on partially filled buffer
    EXPECT_CALL(*mockProcDiskStats, deltaSystemWideDiskStats()).WillOnce([]() -> DiskStats {
        return DiskStats{.numKibWritten = 10};
    });

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicMonitor(nextCollectionTime(), mockProcDiskStats,
                                                          alertHandler));
    EXPECT_FALSE(isAlertReceived) << "Triggered spurious alert when not exceeding the threshold";

    // 5th polling exceeds second threshold
    EXPECT_CALL(*mockProcDiskStats, deltaSystemWideDiskStats()).WillOnce([]() -> DiskStats {
        return DiskStats{.numKibWritten = 80};
    });

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicMonitor(nextCollectionTime(), mockProcDiskStats,
                                                          alertHandler));
    EXPECT_TRUE(isAlertReceived) << "Failed to trigger alert when exceeding the threshold";

    isAlertReceived = false;

    // 6th polling exceeds third threshold
    EXPECT_CALL(*mockProcDiskStats, deltaSystemWideDiskStats()).WillOnce([]() -> DiskStats {
        return DiskStats{.numKibWritten = 10};
    });

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicMonitor(nextCollectionTime(), mockProcDiskStats,
                                                          alertHandler));
    EXPECT_TRUE(isAlertReceived) << "Failed to trigger alert when exceeding the threshold";
}

TEST_F(IoOveruseMonitorTest, TestRegisterResourceOveruseListener) {
    sp<MockResourceOveruseListener> mockResourceOveruseListener =
            sp<MockResourceOveruseListener>::make();

    ASSERT_RESULT_OK(mIoOveruseMonitor->addIoOveruseListener(mockResourceOveruseListener));

    ASSERT_RESULT_OK(mIoOveruseMonitor->addIoOveruseListener(mockResourceOveruseListener));
}

TEST_F(IoOveruseMonitorTest, TestErrorsRegisterResourceOveruseListenerOnLinkToDeathError) {
    sp<MockResourceOveruseListener> mockResourceOveruseListener =
            sp<MockResourceOveruseListener>::make();

    mockResourceOveruseListener->injectLinkToDeathFailure();

    ASSERT_FALSE(mIoOveruseMonitor->addIoOveruseListener(mockResourceOveruseListener).ok());
}

TEST_F(IoOveruseMonitorTest, TestUnaddIoOveruseListener) {
    sp<MockResourceOveruseListener> mockResourceOveruseListener =
            sp<MockResourceOveruseListener>::make();

    ASSERT_RESULT_OK(mIoOveruseMonitor->addIoOveruseListener(mockResourceOveruseListener));

    ASSERT_RESULT_OK(mIoOveruseMonitor->removeIoOveruseListener(mockResourceOveruseListener));

    ASSERT_FALSE(mIoOveruseMonitor->removeIoOveruseListener(mockResourceOveruseListener).ok())
            << "Should error on duplicate unregister";
}

TEST_F(IoOveruseMonitorTest, TestUnaddIoOveruseListenerOnUnlinkToDeathError) {
    sp<MockResourceOveruseListener> mockResourceOveruseListener =
            sp<MockResourceOveruseListener>::make();

    ASSERT_RESULT_OK(mIoOveruseMonitor->addIoOveruseListener(mockResourceOveruseListener));

    mockResourceOveruseListener->injectUnlinkToDeathFailure();

    ASSERT_RESULT_OK(mIoOveruseMonitor->removeIoOveruseListener(mockResourceOveruseListener));
}

TEST_F(IoOveruseMonitorTest, TestGetIoOveruseStats) {
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/90'000, /*bgWrBytes=*/20'000}}})));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    const auto expected =
            constructIoOveruseStats(/*isKillable=*/false,
                                    /*remaining=*/
                                    constructPerStateBytes(70'000, 20'000, 100'000),
                                    /*written=*/
                                    constructPerStateBytes(90'000, 20'000, 0),
                                    /*totalOveruses=*/1, startTime, durationInSeconds);
    IoOveruseStats actual;
    ASSERT_NO_FATAL_FAILURE(executeAsUid(1001000, [&]() {
        ASSERT_RESULT_OK(mIoOveruseMonitor->getIoOveruseStats(&actual));
    }));
    EXPECT_THAT(actual, expected) << "Expected: " << expected.toString()
                                  << "\nActual: " << actual.toString();
}

TEST_F(IoOveruseMonitorTest, TestResetIoOveruseStats) {
    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/90'000, /*bgWrBytes=*/20'000}}})));

    ASSERT_RESULT_OK(
            mIoOveruseMonitor->onPeriodicCollection(std::chrono::system_clock::to_time_t(
                                                            std::chrono::system_clock::now()),
                                                    SystemState::NORMAL_MODE,
                                                    mMockUidStatsCollector, nullptr));

    IoOveruseStats actual;
    ASSERT_NO_FATAL_FAILURE(executeAsUid(1001000, [&]() {
        ASSERT_RESULT_OK(mIoOveruseMonitor->getIoOveruseStats(&actual));
    }));

    EXPECT_NE(actual.totalOveruses, 0);
    EXPECT_NE(actual.writtenBytes.foregroundBytes, 0);
    EXPECT_NE(actual.writtenBytes.backgroundBytes, 0);

    std::vector<std::string> packageNames = {"system.daemon"};
    EXPECT_CALL(*mMockWatchdogServiceHelper, resetResourceOveruseStats(packageNames))
            .WillOnce(Return(Status::ok()));

    ASSERT_RESULT_OK(mIoOveruseMonitor->resetIoOveruseStats(packageNames));

    ASSERT_NO_FATAL_FAILURE(executeAsUid(1001000, [&]() {
        ASSERT_RESULT_OK(mIoOveruseMonitor->getIoOveruseStats(&actual));
    }));

    EXPECT_EQ(actual.totalOveruses, 0);
    EXPECT_EQ(actual.writtenBytes.foregroundBytes, 0);
    EXPECT_EQ(actual.writtenBytes.backgroundBytes, 0);
}

TEST_F(IoOveruseMonitorTest, TestErrorsResetIoOveruseStatsOnWatchdogServiceHelperError) {
    std::vector<std::string> packageNames = {"system.daemon"};
    EXPECT_CALL(*mMockWatchdogServiceHelper, resetResourceOveruseStats(packageNames))
            .WillOnce(Return(Status::fromExceptionCode(Status::EX_ILLEGAL_STATE)));

    ASSERT_FALSE(mIoOveruseMonitor->resetIoOveruseStats(packageNames).ok())
            << "Must return error when WatchdogServiceHelper fails to reset stats";
}

TEST_F(IoOveruseMonitorTest, TestErrorsGetIoOveruseStatsOnNoStats) {
    ON_CALL(*mMockPackageInfoResolver, getPackageInfosForUids(_))
            .WillByDefault([]() -> std::unordered_map<uid_t, PackageInfo> {
                return {{1001000,
                         constructPackageInfo(/*packageName=*/"system.daemon", /*uid=*/1001000,
                                              UidType::NATIVE)}};
            });
    IoOveruseStats actual;
    ASSERT_NO_FATAL_FAILURE(executeAsUid(1001000, [&]() {
        ASSERT_FALSE(mIoOveruseMonitor->getIoOveruseStats(&actual).ok())
                << "Should fail on missing I/O overuse stats";
    }));

    ASSERT_NO_FATAL_FAILURE(executeAsUid(1102001, [&]() {
        ASSERT_FALSE(mIoOveruseMonitor->getIoOveruseStats(&actual).ok())
                << "Should fail on missing package information";
    }));
}

TEST_F(IoOveruseMonitorTest, TestUpdateResourceOveruseConfigurations) {
    EXPECT_CALL(*mMockIoOveruseConfigs, update(_)).WillOnce(Return(Result<void>{}));
    EXPECT_CALL(*mMockIoOveruseConfigs, writeToDisk()).WillOnce(Return(Result<void>{}));

    ASSERT_RESULT_OK(mIoOveruseMonitor->updateResourceOveruseConfigurations({}));
}

TEST_F(IoOveruseMonitorTest, TestFailsUpdateResourceOveruseConfigurations) {
    EXPECT_CALL(*mMockIoOveruseConfigs, update(_))
            .WillOnce([&]([[maybe_unused]] const std::vector<ResourceOveruseConfiguration>& configs)
                              -> Result<void> { return Error() << "Failed to update"; });
    EXPECT_CALL(*mMockIoOveruseConfigs, writeToDisk()).Times(0);

    ASSERT_FALSE(mIoOveruseMonitor->updateResourceOveruseConfigurations({}).ok());
}

TEST_F(IoOveruseMonitorTest, TestRemoveUser) {
    std::vector<UserPackageIoUsageStats> todayIoUsageStats =
            {constructUserPackageIoUsageStats(
                     /*userId=*/11, "com.android.google.package",
                     /*writtenBytes=*/constructPerStateBytes(100'000, 85'000, 120'000),
                     /*forgivenWriteBytes=*/constructPerStateBytes(70'000, 60'000, 100'000),
                     /*totalOveruses=*/3),
             constructUserPackageIoUsageStats(
                     /*userId=*/12, "com.android.kitchensink",
                     /*writtenBytes=*/constructPerStateBytes(50'000, 40'000, 35'000),
                     /*forgivenWriteBytes=*/constructPerStateBytes(30'000, 30'000, 30'000),
                     /*totalOveruses=*/6)};
    EXPECT_CALL(*mMockWatchdogServiceHelper, getTodayIoUsageStats(_))
            .WillOnce(DoAll(SetArgPointee<0>(todayIoUsageStats), Return(Status::ok())));

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1001000, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/20'000}},
                                       {1112345, {/*fgWrBytes=*/35'000, /*bgWrBytes=*/15'000}}})));

    std::vector<PackageIoOveruseStats> actualIoOveruseStats;
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto [startTime, durationInSeconds] = calculateStartAndDuration(currentTime);

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::NORMAL_MODE,
                                                             mMockUidStatsCollector, nullptr));

    std::vector<PackageIoOveruseStats> expectedIoOveruseStats =
            {constructPackageIoOveruseStats(
                     /*uid*=*/1001000, /*shouldNotify=*/false, /*isKillable=*/false,
                     /*remaining=*/constructPerStateBytes(10'000, 20'000, 100'000),
                     /*written=*/constructPerStateBytes(70'000, 20'000, 0),
                     /*forgiven=*/constructPerStateBytes(0, 0, 0),
                     /*totalOveruses=*/0, startTime, durationInSeconds),
             constructPackageIoOveruseStats(
                     /*uid*=*/1112345, /*shouldNotify=*/true, /*isKillable=*/true,
                     /*remaining=*/constructPerStateBytes(5'000, 0, 80'000),
                     /*written=*/constructPerStateBytes(135'000, 100'000, 120'000),
                     /*forgiven=*/constructPerStateBytes(70'000, 90'000, 100'000),
                     /*totalOveruses=*/4, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);

    mIoOveruseMonitor->removeStatsForUser(/*userId=*/11);
    mIoOveruseMonitor->removeStatsForUser(/*userId=*/12);

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats())
            .WillOnce(Return(
                    constructUidStats({{1112345, {/*fgWrBytes=*/70'000, /*bgWrBytes=*/40'000}},
                                       {1245678, {/*fgWrBytes=*/30'000, /*bgWrBytes=*/10'000}}})));

    actualIoOveruseStats.clear();
    EXPECT_CALL(*mMockWatchdogServiceHelper, latestIoOveruseStats(_))
            .WillOnce(DoAll(SaveArg<0>(&actualIoOveruseStats), Return(Status::ok())));

    ASSERT_RESULT_OK(mIoOveruseMonitor->onPeriodicCollection(currentTime, SystemState::GARAGE_MODE,
                                                             mMockUidStatsCollector, nullptr));

    expectedIoOveruseStats = {constructPackageIoOveruseStats(
                                      /*uid*=*/1112345, /*shouldNotify=*/true, /*isKillable=*/true,
                                      /*remaining=*/constructPerStateBytes(70'000, 30'000, 0),
                                      /*written=*/constructPerStateBytes(0, 0, 110'000),
                                      /*forgiven=*/constructPerStateBytes(0, 0, 100'000),
                                      /*totalOveruses=*/1, startTime, durationInSeconds),
                              constructPackageIoOveruseStats(
                                      /*uid*=*/1245678, /*shouldNotify=*/true, /*isKillable=*/true,
                                      /*remaining=*/constructPerStateBytes(30'000, 15'000, 0),
                                      /*written=*/constructPerStateBytes(0, 0, 40'000),
                                      /*forgiven=*/constructPerStateBytes(0, 0, 40'000),
                                      /*totalOveruses=*/4, startTime, durationInSeconds)};
    EXPECT_THAT(actualIoOveruseStats, UnorderedElementsAreArray(expectedIoOveruseStats))
            << "Expected: " << toString(expectedIoOveruseStats)
            << "\nActual: " << toString(actualIoOveruseStats);
}

}  // namespace watchdog
}  // namespace automotive
}  // namespace android
