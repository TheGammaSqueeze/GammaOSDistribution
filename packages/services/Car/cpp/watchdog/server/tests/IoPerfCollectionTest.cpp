/*
 * Copyright 2020 The Android Open Source Project
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

#include "IoPerfCollection.h"
#include "MockProcStat.h"
#include "MockUidStatsCollector.h"
#include "MockWatchdogServiceHelper.h"
#include "PackageInfoTestUtils.h"

#include <WatchdogProperties.sysprop.h>
#include <android-base/file.h>
#include <gmock/gmock.h>
#include <utils/RefBase.h>

#include <sys/types.h>
#include <unistd.h>

#include <string>
#include <type_traits>
#include <vector>

namespace android {
namespace automotive {
namespace watchdog {

using ::android::RefBase;
using ::android::sp;
using ::android::automotive::watchdog::internal::PackageInfo;
using ::android::base::ReadFdToString;
using ::android::base::Result;
using ::testing::_;
using ::testing::AllOf;
using ::testing::ElementsAreArray;
using ::testing::Eq;
using ::testing::ExplainMatchResult;
using ::testing::Field;
using ::testing::IsSubsetOf;
using ::testing::Matcher;
using ::testing::Return;
using ::testing::Test;
using ::testing::UnorderedElementsAreArray;
using ::testing::VariantWith;

namespace {

MATCHER_P(IoStatsEq, expected, "") {
    return ExplainMatchResult(AllOf(Field("bytes", &UserPackageStats::IoStats::bytes,
                                          ElementsAreArray(expected.bytes)),
                                    Field("fsync", &UserPackageStats::IoStats::fsync,
                                          ElementsAreArray(expected.fsync))),
                              arg, result_listener);
}

MATCHER_P(ProcessCountEq, expected, "") {
    return ExplainMatchResult(AllOf(Field("comm", &UserPackageStats::ProcStats::ProcessCount::comm,
                                          Eq(expected.comm)),
                                    Field("count",
                                          &UserPackageStats::ProcStats::ProcessCount::count,
                                          Eq(expected.count))),
                              arg, result_listener);
}

MATCHER_P(ProcStatsEq, expected, "") {
    std::vector<Matcher<const UserPackageStats::ProcStats::ProcessCount&>> processCountMatchers;
    for (const auto& processCount : expected.topNProcesses) {
        processCountMatchers.push_back(ProcessCountEq(processCount));
    }
    return ExplainMatchResult(AllOf(Field("count", &UserPackageStats::ProcStats::count,
                                          Eq(expected.count)),
                                    Field("topNProcesses",
                                          &UserPackageStats::ProcStats::topNProcesses,
                                          ElementsAreArray(processCountMatchers))),
                              arg, result_listener);
}

MATCHER_P(UserPackageStatsEq, expected, "") {
    const auto uidMatcher = Field("uid", &UserPackageStats::uid, Eq(expected.uid));
    const auto packageNameMatcher =
            Field("genericPackageName", &UserPackageStats::genericPackageName,
                  Eq(expected.genericPackageName));
    return std::visit(
            [&](const auto& stats) -> bool {
                using T = std::decay_t<decltype(stats)>;
                if constexpr (std::is_same_v<T, UserPackageStats::IoStats>) {
                    return ExplainMatchResult(AllOf(uidMatcher, packageNameMatcher,
                                                    Field("stats:IoStats", &UserPackageStats::stats,
                                                          VariantWith<UserPackageStats::IoStats>(
                                                                  IoStatsEq(stats)))),
                                              arg, result_listener);
                } else if constexpr (std::is_same_v<T, UserPackageStats::ProcStats>) {
                    return ExplainMatchResult(AllOf(uidMatcher, packageNameMatcher,
                                                    Field("stats:ProcStats",
                                                          &UserPackageStats::stats,
                                                          VariantWith<UserPackageStats::ProcStats>(
                                                                  ProcStatsEq(stats)))),
                                              arg, result_listener);
                }
                *result_listener << "Unexpected variant in UserPackageStats::stats";
                return false;
            },
            expected.stats);
}

MATCHER_P(UserPackageSummaryStatsEq, expected, "") {
    const auto& userPackageStatsMatchers = [&](const std::vector<UserPackageStats>& stats) {
        std::vector<Matcher<const UserPackageStats&>> matchers;
        for (const auto& curStats : stats) {
            matchers.push_back(UserPackageStatsEq(curStats));
        }
        return ElementsAreArray(matchers);
    };
    const auto& totalIoStatsArrayMatcher = [&](const int64_t expected[][UID_STATES]) {
        std::vector<Matcher<const int64_t[UID_STATES]>> matchers;
        for (int i = 0; i < METRIC_TYPES; ++i) {
            matchers.push_back(ElementsAreArray(expected[i], UID_STATES));
        }
        return ElementsAreArray(matchers);
    };
    return ExplainMatchResult(AllOf(Field("topNIoReads", &UserPackageSummaryStats::topNIoReads,
                                          userPackageStatsMatchers(expected.topNIoReads)),
                                    Field("topNIoWrites", &UserPackageSummaryStats::topNIoWrites,
                                          userPackageStatsMatchers(expected.topNIoWrites)),
                                    Field("topNIoBlocked", &UserPackageSummaryStats::topNIoBlocked,
                                          userPackageStatsMatchers(expected.topNIoBlocked)),
                                    Field("topNMajorFaults",
                                          &UserPackageSummaryStats::topNMajorFaults,
                                          userPackageStatsMatchers(expected.topNMajorFaults)),
                                    Field("totalIoStats", &UserPackageSummaryStats::totalIoStats,
                                          totalIoStatsArrayMatcher(expected.totalIoStats)),
                                    Field("taskCountByUid",
                                          &UserPackageSummaryStats::taskCountByUid,
                                          IsSubsetOf(expected.taskCountByUid)),
                                    Field("totalMajorFaults",
                                          &UserPackageSummaryStats::totalMajorFaults,
                                          Eq(expected.totalMajorFaults)),
                                    Field("majorFaultsPercentChange",
                                          &UserPackageSummaryStats::majorFaultsPercentChange,
                                          Eq(expected.majorFaultsPercentChange))),
                              arg, result_listener);
}

MATCHER_P(SystemSummaryStatsEq, expected, "") {
    return ExplainMatchResult(AllOf(Field("cpuIoWaitTime", &SystemSummaryStats::cpuIoWaitTime,
                                          Eq(expected.cpuIoWaitTime)),
                                    Field("totalCpuTime", &SystemSummaryStats::totalCpuTime,
                                          Eq(expected.totalCpuTime)),
                                    Field("ioBlockedProcessCount",
                                          &SystemSummaryStats::ioBlockedProcessCount,
                                          Eq(expected.ioBlockedProcessCount)),
                                    Field("totalProcessCount",
                                          &SystemSummaryStats::totalProcessCount,
                                          Eq(expected.totalProcessCount))),
                              arg, result_listener);
}

MATCHER_P(PerfStatsRecordEq, expected, "") {
    return ExplainMatchResult(AllOf(Field(&PerfStatsRecord::systemSummaryStats,
                                          SystemSummaryStatsEq(expected.systemSummaryStats)),
                                    Field(&PerfStatsRecord::userPackageSummaryStats,
                                          UserPackageSummaryStatsEq(
                                                  expected.userPackageSummaryStats))),
                              arg, result_listener);
}

const std::vector<Matcher<const PerfStatsRecord&>> constructPerfStatsRecordMatchers(
        const std::vector<PerfStatsRecord>& records) {
    std::vector<Matcher<const PerfStatsRecord&>> matchers;
    for (const auto& record : records) {
        matchers.push_back(PerfStatsRecordEq(record));
    }
    return matchers;
}

MATCHER_P(CollectionInfoEq, expected, "") {
    return ExplainMatchResult(AllOf(Field("maxCacheSize", &CollectionInfo::maxCacheSize,
                                          Eq(expected.maxCacheSize)),
                                    Field("records", &CollectionInfo::records,
                                          ElementsAreArray(constructPerfStatsRecordMatchers(
                                                  expected.records)))),
                              arg, result_listener);
}

int countOccurrences(std::string str, std::string subStr) {
    size_t pos = 0;
    int occurrences = 0;
    while ((pos = str.find(subStr, pos)) != std::string::npos) {
        ++occurrences;
        pos += subStr.length();
    }
    return occurrences;
}

std::tuple<std::vector<UidStats>, UserPackageSummaryStats> sampleUidStats(int multiplier = 1) {
    /* The number of returned sample stats are less that the top N stats per category/sub-category.
     * The top N stats per category/sub-category is set to % during test setup. Thus, the default
     * testing behavior is # reported stats < top N stats.
     */
    const auto int64Multiplier = [&](int64_t bytes) -> int64_t {
        return static_cast<int64_t>(bytes * multiplier);
    };
    const auto uint64Multiplier = [&](uint64_t count) -> uint64_t {
        return static_cast<uint64_t>(count * multiplier);
    };
    std::vector<UidStats>
            uidStats{{.packageInfo = constructPackageInfo("mount", 1009),
                      .ioStats = {/*fgRdBytes=*/0,
                                  /*bgRdBytes=*/int64Multiplier(14'000),
                                  /*fgWrBytes=*/0,
                                  /*bgWrBytes=*/int64Multiplier(16'000),
                                  /*fgFsync=*/0, /*bgFsync=*/int64Multiplier(100)},
                      .procStats = {.totalMajorFaults = uint64Multiplier(11'000),
                                    .totalTasksCount = 1,
                                    .ioBlockedTasksCount = 1,
                                    .processStatsByPid =
                                            {{/*pid=*/100,
                                              {/*comm=*/"disk I/O", /*startTime=*/234,
                                               /*totalMajorFaults=*/uint64Multiplier(11'000),
                                               /*totalTasksCount=*/1,
                                               /*ioBlockedTasksCount=*/1}}}}},
                     {.packageInfo =
                              constructPackageInfo("com.google.android.car.kitchensink", 1002001),
                      .ioStats = {/*fgRdBytes=*/0,
                                  /*bgRdBytes=*/int64Multiplier(3'400),
                                  /*fgWrBytes=*/0,
                                  /*bgWrBytes=*/int64Multiplier(6'700),
                                  /*fgFsync=*/0,
                                  /*bgFsync=*/int64Multiplier(200)},
                      .procStats = {.totalMajorFaults = uint64Multiplier(22'445),
                                    .totalTasksCount = 5,
                                    .ioBlockedTasksCount = 3,
                                    .processStatsByPid =
                                            {{/*pid=*/1000,
                                              {/*comm=*/"KitchenSinkApp", /*startTime=*/467,
                                               /*totalMajorFaults=*/uint64Multiplier(12'345),
                                               /*totalTasksCount=*/2,
                                               /*ioBlockedTasksCount=*/1}},
                                             {/*pid=*/1001,
                                              {/*comm=*/"CTS", /*startTime=*/789,
                                               /*totalMajorFaults=*/uint64Multiplier(10'100),
                                               /*totalTasksCount=*/3,
                                               /*ioBlockedTasksCount=*/2}}}}},
                     {.packageInfo = constructPackageInfo("", 1012345),
                      .ioStats = {/*fgRdBytes=*/int64Multiplier(1'000),
                                  /*bgRdBytes=*/int64Multiplier(4'200),
                                  /*fgWrBytes=*/int64Multiplier(300),
                                  /*bgWrBytes=*/int64Multiplier(5'600),
                                  /*fgFsync=*/int64Multiplier(600),
                                  /*bgFsync=*/int64Multiplier(300)},
                      .procStats = {.totalMajorFaults = uint64Multiplier(50'900),
                                    .totalTasksCount = 4,
                                    .ioBlockedTasksCount = 2,
                                    .processStatsByPid =
                                            {{/*pid=*/2345,
                                              {/*comm=*/"MapsApp", /*startTime=*/6789,
                                               /*totalMajorFaults=*/uint64Multiplier(50'900),
                                               /*totalTasksCount=*/4,
                                               /*ioBlockedTasksCount=*/2}}}}},
                     {.packageInfo = constructPackageInfo("com.google.radio", 1015678),
                      .ioStats = {/*fgRdBytes=*/0,
                                  /*bgRdBytes=*/0,
                                  /*fgWrBytes=*/0,
                                  /*bgWrBytes=*/0,
                                  /*fgFsync=*/0, /*bgFsync=*/0},
                      .procStats = {.totalMajorFaults = 0,
                                    .totalTasksCount = 4,
                                    .ioBlockedTasksCount = 0,
                                    .processStatsByPid = {
                                            {/*pid=*/2345,
                                             {/*comm=*/"RadioApp", /*startTime=*/19789,
                                              /*totalMajorFaults=*/0,
                                              /*totalTasksCount=*/4,
                                              /*ioBlockedTasksCount=*/0}}}}}};

    UserPackageSummaryStats userPackageSummaryStats{
            .topNIoReads =
                    {{1009, "mount",
                      UserPackageStats::IoStats{{0, int64Multiplier(14'000)},
                                                {0, int64Multiplier(100)}}},
                     {1012345, "1012345",
                      UserPackageStats::IoStats{{int64Multiplier(1'000), int64Multiplier(4'200)},
                                                {int64Multiplier(600), int64Multiplier(300)}}},
                     {1002001, "com.google.android.car.kitchensink",
                      UserPackageStats::IoStats{{0, int64Multiplier(3'400)},
                                                {0, int64Multiplier(200)}}}},
            .topNIoWrites =
                    {{1009, "mount",
                      UserPackageStats::IoStats{{0, int64Multiplier(16'000)},
                                                {0, int64Multiplier(100)}}},
                     {1002001, "com.google.android.car.kitchensink",
                      UserPackageStats::IoStats{{0, int64Multiplier(6'700)},
                                                {0, int64Multiplier(200)}}},
                     {1012345, "1012345",
                      UserPackageStats::IoStats{{int64Multiplier(300), int64Multiplier(5'600)},
                                                {int64Multiplier(600), int64Multiplier(300)}}}},
            .topNIoBlocked = {{1002001, "com.google.android.car.kitchensink",
                               UserPackageStats::ProcStats{3, {{"CTS", 2}, {"KitchenSinkApp", 1}}}},
                              {1012345, "1012345",
                               UserPackageStats::ProcStats{2, {{"MapsApp", 2}}}},
                              {1009, "mount", UserPackageStats::ProcStats{1, {{"disk I/O", 1}}}}},
            .topNMajorFaults =
                    {{1012345, "1012345",
                      UserPackageStats::ProcStats{uint64Multiplier(50'900),
                                                  {{"MapsApp", uint64Multiplier(50'900)}}}},
                     {1002001, "com.google.android.car.kitchensink",
                      UserPackageStats::ProcStats{uint64Multiplier(22'445),
                                                  {{"KitchenSinkApp", uint64Multiplier(12'345)},
                                                   {"CTS", uint64Multiplier(10'100)}}}},
                     {1009, "mount",
                      UserPackageStats::ProcStats{uint64Multiplier(11'000),
                                                  {{"disk I/O", uint64Multiplier(11'000)}}}}},
            .totalIoStats = {{int64Multiplier(1'000), int64Multiplier(21'600)},
                             {int64Multiplier(300), int64Multiplier(28'300)},
                             {int64Multiplier(600), int64Multiplier(600)}},
            .taskCountByUid = {{1009, 1}, {1002001, 5}, {1012345, 4}},
            .totalMajorFaults = uint64Multiplier(84'345),
            .majorFaultsPercentChange = 0.0,
    };
    return std::make_tuple(uidStats, userPackageSummaryStats);
}

std::tuple<ProcStatInfo, SystemSummaryStats> sampleProcStat(int multiplier = 1) {
    const auto uint64Multiplier = [&](uint64_t bytes) -> uint64_t {
        return static_cast<uint64_t>(bytes * multiplier);
    };
    const auto uint32Multiplier = [&](uint32_t bytes) -> uint32_t {
        return static_cast<uint32_t>(bytes * multiplier);
    };
    ProcStatInfo procStatInfo{/*cpuStats=*/{uint64Multiplier(2'900), uint64Multiplier(7'900),
                                            uint64Multiplier(4'900), uint64Multiplier(8'900),
                                            /*ioWaitTime=*/uint64Multiplier(5'900),
                                            uint64Multiplier(6'966), uint64Multiplier(7'980), 0, 0,
                                            uint64Multiplier(2'930)},
                              /*runnableProcessCount=*/uint32Multiplier(100),
                              /*ioBlockedProcessCount=*/uint32Multiplier(57)};
    SystemSummaryStats systemSummaryStats{/*cpuIoWaitTime=*/uint64Multiplier(5'900),
                                          /*totalCpuTime=*/uint64Multiplier(48'376),
                                          /*ioBlockedProcessCount=*/uint32Multiplier(57),
                                          /*totalProcessCount=*/uint32Multiplier(157)};
    return std::make_tuple(procStatInfo, systemSummaryStats);
}

}  // namespace

namespace internal {

class IoPerfCollectionPeer : public RefBase {
public:
    explicit IoPerfCollectionPeer(sp<IoPerfCollection> collector) : mCollector(collector) {}

    IoPerfCollectionPeer() = delete;
    ~IoPerfCollectionPeer() {
        mCollector->terminate();
        mCollector.clear();
    }

    Result<void> init() { return mCollector->init(); }

    void setTopNStatsPerCategory(int value) { mCollector->mTopNStatsPerCategory = value; }

    void setTopNStatsPerSubcategory(int value) { mCollector->mTopNStatsPerSubcategory = value; }

    const CollectionInfo& getBoottimeCollectionInfo() {
        Mutex::Autolock lock(mCollector->mMutex);
        return mCollector->mBoottimeCollection;
    }

    const CollectionInfo& getPeriodicCollectionInfo() {
        Mutex::Autolock lock(mCollector->mMutex);
        return mCollector->mPeriodicCollection;
    }

    const CollectionInfo& getCustomCollectionInfo() {
        Mutex::Autolock lock(mCollector->mMutex);
        return mCollector->mCustomCollection;
    }

private:
    sp<IoPerfCollection> mCollector;
};

}  // namespace internal

class IoPerfCollectionTest : public Test {
protected:
    void SetUp() override {
        mMockUidStatsCollector = sp<MockUidStatsCollector>::make();
        mMockProcStat = sp<MockProcStat>::make();
        mCollector = sp<IoPerfCollection>::make();
        mCollectorPeer = sp<internal::IoPerfCollectionPeer>::make(mCollector);
        ASSERT_RESULT_OK(mCollectorPeer->init());
        mCollectorPeer->setTopNStatsPerCategory(5);
        mCollectorPeer->setTopNStatsPerSubcategory(5);
    }

    void TearDown() override {
        mMockUidStatsCollector.clear();
        mMockProcStat.clear();
        mCollector.clear();
        mCollectorPeer.clear();
    }

    void checkDumpContents(int wantedEmptyCollectionInstances) {
        TemporaryFile dump;
        ASSERT_RESULT_OK(mCollector->onDump(dump.fd));

        checkDumpFd(wantedEmptyCollectionInstances, dump.fd);
    }

    void checkCustomDumpContents() {
        TemporaryFile dump;
        ASSERT_RESULT_OK(mCollector->onCustomCollectionDump(dump.fd));

        checkDumpFd(/*wantedEmptyCollectionInstances=*/0, dump.fd);
    }

private:
    void checkDumpFd(int wantedEmptyCollectionInstances, int fd) {
        lseek(fd, 0, SEEK_SET);
        std::string dumpContents;
        ASSERT_TRUE(ReadFdToString(fd, &dumpContents));
        ASSERT_FALSE(dumpContents.empty());

        ASSERT_EQ(countOccurrences(dumpContents, kEmptyCollectionMessage),
                  wantedEmptyCollectionInstances)
                << "Dump contents: " << dumpContents;
    }

protected:
    sp<MockUidStatsCollector> mMockUidStatsCollector;
    sp<MockProcStat> mMockProcStat;
    sp<IoPerfCollection> mCollector;
    sp<internal::IoPerfCollectionPeer> mCollectorPeer;
};

TEST_F(IoPerfCollectionTest, TestOnBoottimeCollection) {
    const auto [uidStats, userPackageSummaryStats] = sampleUidStats();
    const auto [procStatInfo, systemSummaryStats] = sampleProcStat();

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats()).WillOnce(Return(uidStats));
    EXPECT_CALL(*mMockProcStat, deltaStats()).WillOnce(Return(procStatInfo));

    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    ASSERT_RESULT_OK(mCollector->onBoottimeCollection(now, mMockUidStatsCollector, mMockProcStat));

    const auto actual = mCollectorPeer->getBoottimeCollectionInfo();

    const CollectionInfo expected{
            .maxCacheSize = std::numeric_limits<std::size_t>::max(),
            .records = {{
                    .systemSummaryStats = systemSummaryStats,
                    .userPackageSummaryStats = userPackageSummaryStats,
            }},
    };

    EXPECT_THAT(actual, CollectionInfoEq(expected))
            << "Boottime collection info doesn't match.\nExpected:\n"
            << expected.toString() << "\nActual:\n"
            << actual.toString();

    ASSERT_NO_FATAL_FAILURE(checkDumpContents(/*wantedEmptyCollectionInstances=*/1))
            << "Periodic collection shouldn't be reported";
}

TEST_F(IoPerfCollectionTest, TestOnPeriodicCollection) {
    const auto [uidStats, userPackageSummaryStats] = sampleUidStats();
    const auto [procStatInfo, systemSummaryStats] = sampleProcStat();

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats()).WillOnce(Return(uidStats));
    EXPECT_CALL(*mMockProcStat, deltaStats()).WillOnce(Return(procStatInfo));

    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    ASSERT_RESULT_OK(mCollector->onPeriodicCollection(now, SystemState::NORMAL_MODE,
                                                      mMockUidStatsCollector, mMockProcStat));

    const auto actual = mCollectorPeer->getPeriodicCollectionInfo();

    const CollectionInfo expected{
            .maxCacheSize = static_cast<size_t>(sysprop::periodicCollectionBufferSize().value_or(
                    kDefaultPeriodicCollectionBufferSize)),
            .records = {{
                    .systemSummaryStats = systemSummaryStats,
                    .userPackageSummaryStats = userPackageSummaryStats,
            }},
    };

    EXPECT_THAT(actual, CollectionInfoEq(expected))
            << "Periodic collection info doesn't match.\nExpected:\n"
            << expected.toString() << "\nActual:\n"
            << actual.toString();

    ASSERT_NO_FATAL_FAILURE(checkDumpContents(/*wantedEmptyCollectionInstances=*/1))
            << "Boot-time collection shouldn't be reported";
}

TEST_F(IoPerfCollectionTest, TestOnCustomCollectionWithoutPackageFilter) {
    const auto [uidStats, userPackageSummaryStats] = sampleUidStats();
    const auto [procStatInfo, systemSummaryStats] = sampleProcStat();

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats()).WillOnce(Return(uidStats));
    EXPECT_CALL(*mMockProcStat, deltaStats()).WillOnce(Return(procStatInfo));

    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    ASSERT_RESULT_OK(mCollector->onCustomCollection(now, SystemState::NORMAL_MODE, {},
                                                    mMockUidStatsCollector, mMockProcStat));

    const auto actual = mCollectorPeer->getCustomCollectionInfo();

    CollectionInfo expected{
            .maxCacheSize = std::numeric_limits<std::size_t>::max(),
            .records = {{
                    .systemSummaryStats = systemSummaryStats,
                    .userPackageSummaryStats = userPackageSummaryStats,
            }},
    };

    EXPECT_THAT(actual, CollectionInfoEq(expected))
            << "Custom collection info doesn't match.\nExpected:\n"
            << expected.toString() << "\nActual:\n"
            << actual.toString();

    ASSERT_NO_FATAL_FAILURE(checkCustomDumpContents()) << "Custom collection should be reported";

    TemporaryFile customDump;
    ASSERT_RESULT_OK(mCollector->onCustomCollectionDump(customDump.fd));

    // Should clear the cache.
    ASSERT_RESULT_OK(mCollector->onCustomCollectionDump(-1));

    expected.records.clear();
    const CollectionInfo& emptyCollectionInfo = mCollectorPeer->getCustomCollectionInfo();
    EXPECT_THAT(emptyCollectionInfo, CollectionInfoEq(expected))
            << "Custom collection should be cleared.";
}

TEST_F(IoPerfCollectionTest, TestOnCustomCollectionWithPackageFilter) {
    // Filter by package name should ignore this limit with package filter.
    mCollectorPeer->setTopNStatsPerCategory(1);

    const auto [uidStats, _] = sampleUidStats();
    const auto [procStatInfo, systemSummaryStats] = sampleProcStat();

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats()).WillOnce(Return(uidStats));
    EXPECT_CALL(*mMockProcStat, deltaStats()).WillOnce(Return(procStatInfo));

    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    ASSERT_RESULT_OK(mCollector->onCustomCollection(now, SystemState::NORMAL_MODE,
                                                    {"mount", "com.google.android.car.kitchensink"},
                                                    mMockUidStatsCollector, mMockProcStat));

    const auto actual = mCollectorPeer->getCustomCollectionInfo();

    UserPackageSummaryStats userPackageSummaryStats{
            .topNIoReads = {{1009, "mount", UserPackageStats::IoStats{{0, 14'000}, {0, 100}}},
                            {1002001, "com.google.android.car.kitchensink",
                             UserPackageStats::IoStats{{0, 3'400}, {0, 200}}}},
            .topNIoWrites = {{1009, "mount", UserPackageStats::IoStats{{0, 16'000}, {0, 100}}},
                             {1002001, "com.google.android.car.kitchensink",
                              UserPackageStats::IoStats{{0, 6'700}, {0, 200}}}},
            .topNIoBlocked = {{1009, "mount", UserPackageStats::ProcStats{1, {{"disk I/O", 1}}}},
                              {1002001, "com.google.android.car.kitchensink",
                               UserPackageStats::ProcStats{3,
                                                           {{"CTS", 2}, {"KitchenSinkApp", 1}}}}},
            .topNMajorFaults =
                    {{1009, "mount", UserPackageStats::ProcStats{11'000, {{"disk I/O", 11'000}}}},
                     {1002001, "com.google.android.car.kitchensink",
                      UserPackageStats::ProcStats{22'445,
                                                  {{"KitchenSinkApp", 12'345}, {"CTS", 10'100}}}}},
            .totalIoStats = {{1000, 21'600}, {300, 28'300}, {600, 600}},
            .taskCountByUid = {{1009, 1}, {1002001, 5}},
            .totalMajorFaults = 84'345,
            .majorFaultsPercentChange = 0.0,
    };

    CollectionInfo expected{
            .maxCacheSize = std::numeric_limits<std::size_t>::max(),
            .records = {{
                    .systemSummaryStats = systemSummaryStats,
                    .userPackageSummaryStats = userPackageSummaryStats,
            }},
    };

    EXPECT_THAT(actual, CollectionInfoEq(expected))
            << "Custom collection info doesn't match.\nExpected:\n"
            << expected.toString() << "\nActual:\n"
            << actual.toString();

    ASSERT_NO_FATAL_FAILURE(checkCustomDumpContents()) << "Custom collection should be reported";

    TemporaryFile customDump;
    ASSERT_RESULT_OK(mCollector->onCustomCollectionDump(customDump.fd));

    // Should clear the cache.
    ASSERT_RESULT_OK(mCollector->onCustomCollectionDump(-1));

    expected.records.clear();
    const CollectionInfo& emptyCollectionInfo = mCollectorPeer->getCustomCollectionInfo();
    EXPECT_THAT(emptyCollectionInfo, CollectionInfoEq(expected))
            << "Custom collection should be cleared.";
}

TEST_F(IoPerfCollectionTest, TestOnPeriodicCollectionWithTrimmingStatsAfterTopN) {
    mCollectorPeer->setTopNStatsPerCategory(1);
    mCollectorPeer->setTopNStatsPerSubcategory(1);

    const auto [uidStats, _] = sampleUidStats();
    const auto [procStatInfo, systemSummaryStats] = sampleProcStat();

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats()).WillOnce(Return(uidStats));
    EXPECT_CALL(*mMockProcStat, deltaStats()).WillOnce(Return(procStatInfo));

    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    ASSERT_RESULT_OK(mCollector->onPeriodicCollection(now, SystemState::NORMAL_MODE,
                                                      mMockUidStatsCollector, mMockProcStat));

    const auto actual = mCollectorPeer->getPeriodicCollectionInfo();

    UserPackageSummaryStats userPackageSummaryStats{
            .topNIoReads = {{1009, "mount", UserPackageStats::IoStats{{0, 14'000}, {0, 100}}}},
            .topNIoWrites = {{1009, "mount", UserPackageStats::IoStats{{0, 16'000}, {0, 100}}}},
            .topNIoBlocked = {{1002001, "com.google.android.car.kitchensink",
                               UserPackageStats::ProcStats{3, {{"CTS", 2}}}}},
            .topNMajorFaults = {{1012345, "1012345",
                                 UserPackageStats::ProcStats{50'900, {{"MapsApp", 50'900}}}}},
            .totalIoStats = {{1000, 21'600}, {300, 28'300}, {600, 600}},
            .taskCountByUid = {{1009, 1}, {1002001, 5}, {1012345, 4}},
            .totalMajorFaults = 84'345,
            .majorFaultsPercentChange = 0.0,
    };

    const CollectionInfo expected{
            .maxCacheSize = static_cast<size_t>(sysprop::periodicCollectionBufferSize().value_or(
                    kDefaultPeriodicCollectionBufferSize)),
            .records = {{
                    .systemSummaryStats = systemSummaryStats,
                    .userPackageSummaryStats = userPackageSummaryStats,
            }},
    };

    EXPECT_THAT(actual, CollectionInfoEq(expected))
            << "Periodic collection info doesn't match.\nExpected:\n"
            << expected.toString() << "\nActual:\n"
            << actual.toString();

    ASSERT_NO_FATAL_FAILURE(checkDumpContents(/*wantedEmptyCollectionInstances=*/1))
            << "Boot-time collection shouldn't be reported";
}

TEST_F(IoPerfCollectionTest, TestConsecutiveOnPeriodicCollection) {
    const auto [firstUidStats, firstUserPackageSummaryStats] = sampleUidStats();
    const auto [firstProcStatInfo, firstSystemSummaryStats] = sampleProcStat();

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats()).WillOnce(Return(firstUidStats));
    EXPECT_CALL(*mMockProcStat, deltaStats()).WillOnce(Return(firstProcStatInfo));

    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    ASSERT_RESULT_OK(mCollector->onPeriodicCollection(now, SystemState::NORMAL_MODE,
                                                      mMockUidStatsCollector, mMockProcStat));

    auto [secondUidStats, secondUserPackageSummaryStats] = sampleUidStats(/*multiplier=*/2);
    const auto [secondProcStatInfo, secondSystemSummaryStats] = sampleProcStat(/*multiplier=*/2);

    secondUserPackageSummaryStats.majorFaultsPercentChange =
            (static_cast<double>(secondUserPackageSummaryStats.totalMajorFaults -
                                 firstUserPackageSummaryStats.totalMajorFaults) /
             static_cast<double>(firstUserPackageSummaryStats.totalMajorFaults)) *
            100.0;

    EXPECT_CALL(*mMockUidStatsCollector, deltaStats()).WillOnce(Return(secondUidStats));
    EXPECT_CALL(*mMockProcStat, deltaStats()).WillOnce(Return(secondProcStatInfo));

    ASSERT_RESULT_OK(mCollector->onPeriodicCollection(now, SystemState::NORMAL_MODE,
                                                      mMockUidStatsCollector, mMockProcStat));

    const auto actual = mCollectorPeer->getPeriodicCollectionInfo();

    const CollectionInfo expected{
            .maxCacheSize = static_cast<size_t>(sysprop::periodicCollectionBufferSize().value_or(
                    kDefaultPeriodicCollectionBufferSize)),
            .records = {{.systemSummaryStats = firstSystemSummaryStats,
                         .userPackageSummaryStats = firstUserPackageSummaryStats},
                        {.systemSummaryStats = secondSystemSummaryStats,
                         .userPackageSummaryStats = secondUserPackageSummaryStats}},
    };

    EXPECT_THAT(actual, CollectionInfoEq(expected))
            << "Periodic collection info doesn't match.\nExpected:\n"
            << expected.toString() << "\nActual:\n"
            << actual.toString();

    ASSERT_NO_FATAL_FAILURE(checkDumpContents(/*wantedEmptyCollectionInstances=*/1))
            << "Boot-time collection shouldn't be reported";
}

}  // namespace watchdog
}  // namespace automotive
}  // namespace android
