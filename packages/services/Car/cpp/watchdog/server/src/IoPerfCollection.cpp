/**
 * Copyright (c) 2020, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "carwatchdogd"

#include "IoPerfCollection.h"

#include <WatchdogProperties.sysprop.h>
#include <android-base/file.h>
#include <android-base/stringprintf.h>
#include <log/log.h>

#include <inttypes.h>

#include <iomanip>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace android {
namespace automotive {
namespace watchdog {

using ::android::wp;
using ::android::base::Error;
using ::android::base::Result;
using ::android::base::StringAppendF;
using ::android::base::StringPrintf;
using ::android::base::WriteStringToFd;

namespace {

constexpr int32_t kDefaultTopNStatsPerCategory = 10;
constexpr int32_t kDefaultTopNStatsPerSubcategory = 5;
constexpr const char kBootTimeCollectionTitle[] = "%s\nBoot-time I/O performance report:\n%s\n";
constexpr const char kPeriodicCollectionTitle[] =
        "%s\nLast N minutes I/O performance report:\n%s\n";
constexpr const char kCustomCollectionTitle[] = "%s\nCustom I/O performance data report:\n%s\n";
constexpr const char kCollectionTitle[] =
        "Collection duration: %.f seconds\nNumber of collections: %zu\n";
constexpr const char kRecordTitle[] = "\nCollection %zu: <%s>\n%s\n%s";
constexpr const char kIoReadsTitle[] = "\nTop N Reads:\n%s\n";
constexpr const char kIoWritesTitle[] = "\nTop N Writes:\n%s\n";
constexpr const char kIoStatsHeader[] =
        "Android User ID, Package Name, Foreground Bytes, Foreground Bytes %%, Foreground Fsync, "
        "Foreground Fsync %%, Background Bytes, Background Bytes %%, Background Fsync, "
        "Background Fsync %%\n";
constexpr const char kIoBlockedTitle[] = "\nTop N I/O waiting UIDs:\n%s\n";
constexpr const char kIoBlockedHeader[] =
        "Android User ID, Package Name, Number of owned tasks waiting for I/O, Percentage of owned "
        "tasks waiting for I/O\n\tCommand, Number of I/O waiting tasks, Percentage of UID's tasks "
        "waiting for I/O\n";
constexpr const char kMajorPageFaultsTitle[] = "\nTop N major page faults:\n%s\n";
constexpr const char kMajorFaultsHeader[] =
        "Android User ID, Package Name, Number of major page faults, Percentage of total major "
        "page faults\n\tCommand, Number of major page faults, Percentage of UID's major page "
        "faults\n";
constexpr const char kMajorFaultsSummary[] =
        "Number of major page faults since last collection: %" PRIu64 "\n"
        "Percentage of change in major page faults since last collection: %.2f%%\n";

double percentage(uint64_t numer, uint64_t denom) {
    return denom == 0 ? 0.0 : (static_cast<double>(numer) / static_cast<double>(denom)) * 100.0;
}

void addUidIoStats(const int64_t entry[][UID_STATES], int64_t total[][UID_STATES]) {
    const auto sum = [](int64_t lhs, int64_t rhs) -> int64_t {
        return std::numeric_limits<int64_t>::max() - lhs > rhs
                ? lhs + rhs
                : std::numeric_limits<int64_t>::max();
    };
    total[READ_BYTES][FOREGROUND] =
            sum(total[READ_BYTES][FOREGROUND], entry[READ_BYTES][FOREGROUND]);
    total[READ_BYTES][BACKGROUND] =
            sum(total[READ_BYTES][BACKGROUND], entry[READ_BYTES][BACKGROUND]);
    total[WRITE_BYTES][FOREGROUND] =
            sum(total[WRITE_BYTES][FOREGROUND], entry[WRITE_BYTES][FOREGROUND]);
    total[WRITE_BYTES][BACKGROUND] =
            sum(total[WRITE_BYTES][BACKGROUND], entry[WRITE_BYTES][BACKGROUND]);
    total[FSYNC_COUNT][FOREGROUND] =
            sum(total[FSYNC_COUNT][FOREGROUND], entry[FSYNC_COUNT][FOREGROUND]);
    total[FSYNC_COUNT][BACKGROUND] =
            sum(total[FSYNC_COUNT][BACKGROUND], entry[FSYNC_COUNT][BACKGROUND]);
    return;
}

UserPackageStats toUserPackageStats(MetricType metricType, const UidStats& uidStats) {
    const UidIoStats& ioStats = uidStats.ioStats;
    return UserPackageStats{
            .uid = uidStats.uid(),
            .genericPackageName = uidStats.genericPackageName(),
            .stats = UserPackageStats::
                    IoStats{.bytes = {ioStats.metrics[metricType][UidState::FOREGROUND],
                                      ioStats.metrics[metricType][UidState::BACKGROUND]},
                            .fsync =
                                    {ioStats.metrics[MetricType::FSYNC_COUNT][UidState::FOREGROUND],
                                     ioStats.metrics[MetricType::FSYNC_COUNT]
                                                    [UidState::BACKGROUND]}},
    };
}

void cacheTopNIoStats(MetricType metricType, const UidStats& uidStats,
                      std::vector<UserPackageStats>* topNIoStats) {
    if (metricType != MetricType::READ_BYTES && metricType != MetricType::WRITE_BYTES) {
        return;
    }
    int64_t totalBytes = metricType == MetricType::READ_BYTES ? uidStats.ioStats.sumReadBytes()
                                                              : uidStats.ioStats.sumWriteBytes();
    if (totalBytes == 0) {
        return;
    }
    for (auto it = topNIoStats->begin(); it != topNIoStats->end(); ++it) {
        if (const auto* ioStats = std::get_if<UserPackageStats::IoStats>(&it->stats);
            ioStats == nullptr || totalBytes > ioStats->totalBytes()) {
            topNIoStats->emplace(it, toUserPackageStats(metricType, uidStats));
            topNIoStats->pop_back();
            break;
        }
    }
    return;
}

enum ProcStatType {
    IO_BLOCKED_TASKS_COUNT = 0,
    MAJOR_FAULTS,
    PROC_STAT_TYPES,
};

bool cacheTopNProcessStats(ProcStatType procStatType, const ProcessStats& processStats,
                           std::vector<UserPackageStats::ProcStats::ProcessCount>* topNProcesses) {
    uint64_t count = procStatType == IO_BLOCKED_TASKS_COUNT ? processStats.ioBlockedTasksCount
                                                            : processStats.totalMajorFaults;
    if (count == 0) {
        return false;
    }
    for (auto it = topNProcesses->begin(); it != topNProcesses->end(); ++it) {
        if (count > it->count) {
            topNProcesses->emplace(it,
                                   UserPackageStats::ProcStats::ProcessCount{
                                           .comm = processStats.comm,
                                           .count = count,
                                   });
            topNProcesses->pop_back();
            return true;
        }
    }
    return false;
}

UserPackageStats toUserPackageStats(ProcStatType procStatType, const UidStats& uidStats,
                                    int topNProcessCount) {
    uint64_t count = procStatType == IO_BLOCKED_TASKS_COUNT ? uidStats.procStats.ioBlockedTasksCount
                                                            : uidStats.procStats.totalMajorFaults;
    UserPackageStats userPackageStats = {
            .uid = uidStats.uid(),
            .genericPackageName = uidStats.genericPackageName(),
            .stats = UserPackageStats::ProcStats{.count = count},
    };
    auto& procStats = std::get<UserPackageStats::ProcStats>(userPackageStats.stats);
    procStats.topNProcesses.resize(topNProcessCount);
    int cachedProcessCount = 0;
    for (const auto& [_, processStats] : uidStats.procStats.processStatsByPid) {
        if (cacheTopNProcessStats(procStatType, processStats, &procStats.topNProcesses)) {
            ++cachedProcessCount;
        }
    }
    if (cachedProcessCount < topNProcessCount) {
        procStats.topNProcesses.erase(procStats.topNProcesses.begin() + cachedProcessCount,
                                      procStats.topNProcesses.end());
    }
    return userPackageStats;
}

bool cacheTopNProcStats(ProcStatType procStatType, const UidStats& uidStats, int topNProcessCount,
                        std::vector<UserPackageStats>* topNProcStats) {
    uint64_t count = procStatType == IO_BLOCKED_TASKS_COUNT ? uidStats.procStats.ioBlockedTasksCount
                                                            : uidStats.procStats.totalMajorFaults;
    if (count == 0) {
        return false;
    }
    for (auto it = topNProcStats->begin(); it != topNProcStats->end(); ++it) {
        if (const auto* procStats = std::get_if<UserPackageStats::ProcStats>(&it->stats);
            procStats == nullptr || count > procStats->count) {
            topNProcStats->emplace(it,
                                   toUserPackageStats(procStatType, uidStats, topNProcessCount));
            topNProcStats->pop_back();
            return true;
        }
    }
    return false;
}

Result<void> checkDataCollectors(const sp<UidStatsCollectorInterface>& uidStatsCollector,
                                 const sp<ProcStat>& procStat) {
    if (uidStatsCollector != nullptr && procStat != nullptr) {
        return {};
    }
    std::string error;
    if (uidStatsCollector == nullptr) {
        error = "Per-UID stats collector must not be null";
    }
    if (procStat == nullptr) {
        StringAppendF(&error, "%s%s", error.empty() ? "" : ", ",
                      "Proc stats collector must not be null");
    }
    return Error() << "Invalid data collectors: " << error;
}

}  // namespace

std::string UserPackageStats::toString(MetricType metricsType,
                                       const int64_t totalIoStats[][UID_STATES]) const {
    std::string buffer;
    StringAppendF(&buffer, "%" PRIu32 ", %s", multiuser_get_user_id(uid),
                  genericPackageName.c_str());
    const auto& ioStats = std::get<UserPackageStats::IoStats>(stats);
    for (int i = 0; i < UID_STATES; ++i) {
        StringAppendF(&buffer, ", %" PRIi64 ", %.2f%%, %" PRIi64 ", %.2f%%", ioStats.bytes[i],
                      percentage(ioStats.bytes[i], totalIoStats[metricsType][i]), ioStats.fsync[i],
                      percentage(ioStats.fsync[i], totalIoStats[FSYNC_COUNT][i]));
    }
    StringAppendF(&buffer, "\n");
    return buffer;
}

std::string UserPackageStats::toString(int64_t totalCount) const {
    std::string buffer;
    const auto& procStats = std::get<UserPackageStats::ProcStats>(stats);
    StringAppendF(&buffer, "%" PRIu32 ", %s, %" PRIu64 ", %.2f%%\n", multiuser_get_user_id(uid),
                  genericPackageName.c_str(), procStats.count,
                  percentage(procStats.count, totalCount));
    for (const auto& processCount : procStats.topNProcesses) {
        StringAppendF(&buffer, "\t%s, %" PRIu64 ", %.2f%%\n", processCount.comm.c_str(),
                      processCount.count, percentage(processCount.count, procStats.count));
    }
    return buffer;
}

std::string UserPackageSummaryStats::toString() const {
    std::string buffer;
    if (!topNIoReads.empty()) {
        StringAppendF(&buffer, kIoReadsTitle, std::string(12, '-').c_str());
        StringAppendF(&buffer, kIoStatsHeader);
        for (const auto& stats : topNIoReads) {
            StringAppendF(&buffer, "%s",
                          stats.toString(MetricType::READ_BYTES, totalIoStats).c_str());
        }
    }
    if (!topNIoWrites.empty()) {
        StringAppendF(&buffer, kIoWritesTitle, std::string(13, '-').c_str());
        StringAppendF(&buffer, kIoStatsHeader);
        for (const auto& stats : topNIoWrites) {
            StringAppendF(&buffer, "%s",
                          stats.toString(MetricType::WRITE_BYTES, totalIoStats).c_str());
        }
    }
    if (!topNIoBlocked.empty()) {
        StringAppendF(&buffer, kIoBlockedTitle, std::string(23, '-').c_str());
        StringAppendF(&buffer, kIoBlockedHeader);
        for (const auto& stats : topNIoBlocked) {
            const auto it = taskCountByUid.find(stats.uid);
            if (it == taskCountByUid.end()) {
                continue;
            }
            StringAppendF(&buffer, "%s", stats.toString(it->second).c_str());
        }
    }
    if (!topNMajorFaults.empty()) {
        StringAppendF(&buffer, kMajorPageFaultsTitle, std::string(24, '-').c_str());
        StringAppendF(&buffer, kMajorFaultsHeader);
        for (const auto& stats : topNMajorFaults) {
            StringAppendF(&buffer, "%s", stats.toString(totalMajorFaults).c_str());
        }
        StringAppendF(&buffer, kMajorFaultsSummary, totalMajorFaults, majorFaultsPercentChange);
    }
    return buffer;
}

std::string SystemSummaryStats::toString() const {
    std::string buffer;
    StringAppendF(&buffer, "CPU I/O wait time/percent: %" PRIu64 " / %.2f%%\n", cpuIoWaitTime,
                  percentage(cpuIoWaitTime, totalCpuTime));
    StringAppendF(&buffer, "Number of I/O blocked processes/percent: %" PRIu32 " / %.2f%%\n",
                  ioBlockedProcessCount, percentage(ioBlockedProcessCount, totalProcessCount));
    return buffer;
}

std::string PerfStatsRecord::toString() const {
    std::string buffer;
    StringAppendF(&buffer, "%s%s", systemSummaryStats.toString().c_str(),
                  userPackageSummaryStats.toString().c_str());
    return buffer;
}

std::string CollectionInfo::toString() const {
    if (records.empty()) {
        return kEmptyCollectionMessage;
    }
    std::string buffer;
    double duration = difftime(records.back().time, records.front().time);
    StringAppendF(&buffer, kCollectionTitle, duration, records.size());
    for (size_t i = 0; i < records.size(); ++i) {
        const auto& record = records[i];
        std::stringstream timestamp;
        timestamp << std::put_time(std::localtime(&record.time), "%c %Z");
        StringAppendF(&buffer, kRecordTitle, i, timestamp.str().c_str(),
                      std::string(45, '=').c_str(), record.toString().c_str());
    }
    return buffer;
}

Result<void> IoPerfCollection::init() {
    Mutex::Autolock lock(mMutex);
    if (mTopNStatsPerCategory != 0 || mTopNStatsPerSubcategory != 0) {
        return Error() << "Cannot initialize " << name() << " more than once";
    }
    mTopNStatsPerCategory = static_cast<int>(
            sysprop::topNStatsPerCategory().value_or(kDefaultTopNStatsPerCategory));
    mTopNStatsPerSubcategory = static_cast<int>(
            sysprop::topNStatsPerSubcategory().value_or(kDefaultTopNStatsPerSubcategory));
    size_t periodicCollectionBufferSize = static_cast<size_t>(
            sysprop::periodicCollectionBufferSize().value_or(kDefaultPeriodicCollectionBufferSize));
    mBoottimeCollection = {
            .maxCacheSize = std::numeric_limits<std::size_t>::max(),
            .records = {},
    };
    mPeriodicCollection = {
            .maxCacheSize = periodicCollectionBufferSize,
            .records = {},
    };
    mCustomCollection = {
            .maxCacheSize = std::numeric_limits<std::size_t>::max(),
            .records = {},
    };
    return {};
}

void IoPerfCollection::terminate() {
    Mutex::Autolock lock(mMutex);

    ALOGW("Terminating %s", name().c_str());

    mBoottimeCollection.records.clear();
    mBoottimeCollection = {};

    mPeriodicCollection.records.clear();
    mPeriodicCollection = {};

    mCustomCollection.records.clear();
    mCustomCollection = {};
}

Result<void> IoPerfCollection::onDump(int fd) const {
    Mutex::Autolock lock(mMutex);
    if (!WriteStringToFd(StringPrintf(kBootTimeCollectionTitle, std::string(75, '-').c_str(),
                                      std::string(33, '=').c_str()),
                         fd) ||
        !WriteStringToFd(mBoottimeCollection.toString(), fd) ||
        !WriteStringToFd(StringPrintf(kPeriodicCollectionTitle, std::string(75, '-').c_str(),
                                      std::string(38, '=').c_str()),
                         fd) ||
        !WriteStringToFd(mPeriodicCollection.toString(), fd)) {
        return Error(FAILED_TRANSACTION)
                << "Failed to dump the boot-time and periodic collection reports.";
    }
    return {};
}

Result<void> IoPerfCollection::onCustomCollectionDump(int fd) {
    if (fd == -1) {
        // Custom collection ends so clear the cache.
        mCustomCollection.records.clear();
        mCustomCollection = {
                .maxCacheSize = std::numeric_limits<std::size_t>::max(),
                .records = {},
        };
        return {};
    }

    if (!WriteStringToFd(StringPrintf(kCustomCollectionTitle, std::string(75, '-').c_str(),
                                      std::string(75, '-').c_str()),
                         fd) ||
        !WriteStringToFd(mCustomCollection.toString(), fd)) {
        return Error(FAILED_TRANSACTION) << "Failed to write custom I/O collection report.";
    }

    return {};
}

Result<void> IoPerfCollection::onBoottimeCollection(
        time_t time, const wp<UidStatsCollectorInterface>& uidStatsCollector,
        const wp<ProcStat>& procStat) {
    const sp<UidStatsCollectorInterface> uidStatsCollectorSp = uidStatsCollector.promote();
    const sp<ProcStat> procStatSp = procStat.promote();
    auto result = checkDataCollectors(uidStatsCollectorSp, procStatSp);
    if (!result.ok()) {
        return result;
    }
    Mutex::Autolock lock(mMutex);
    return processLocked(time, std::unordered_set<std::string>(), uidStatsCollectorSp, procStatSp,
                         &mBoottimeCollection);
}

Result<void> IoPerfCollection::onPeriodicCollection(
        time_t time, [[maybe_unused]] SystemState systemState,
        const wp<UidStatsCollectorInterface>& uidStatsCollector, const wp<ProcStat>& procStat) {
    const sp<UidStatsCollectorInterface> uidStatsCollectorSp = uidStatsCollector.promote();
    const sp<ProcStat> procStatSp = procStat.promote();
    auto result = checkDataCollectors(uidStatsCollectorSp, procStatSp);
    if (!result.ok()) {
        return result;
    }
    Mutex::Autolock lock(mMutex);
    return processLocked(time, std::unordered_set<std::string>(), uidStatsCollectorSp, procStatSp,
                         &mPeriodicCollection);
}

Result<void> IoPerfCollection::onCustomCollection(
        time_t time, [[maybe_unused]] SystemState systemState,
        const std::unordered_set<std::string>& filterPackages,
        const wp<UidStatsCollectorInterface>& uidStatsCollector, const wp<ProcStat>& procStat) {
    const sp<UidStatsCollectorInterface> uidStatsCollectorSp = uidStatsCollector.promote();
    const sp<ProcStat> procStatSp = procStat.promote();
    auto result = checkDataCollectors(uidStatsCollectorSp, procStatSp);
    if (!result.ok()) {
        return result;
    }
    Mutex::Autolock lock(mMutex);
    return processLocked(time, filterPackages, uidStatsCollectorSp, procStatSp, &mCustomCollection);
}

Result<void> IoPerfCollection::processLocked(
        time_t time, const std::unordered_set<std::string>& filterPackages,
        const sp<UidStatsCollectorInterface>& uidStatsCollector, const sp<ProcStat>& procStat,
        CollectionInfo* collectionInfo) {
    if (collectionInfo->maxCacheSize == 0) {
        return Error() << "Maximum cache size cannot be 0";
    }
    PerfStatsRecord record{
            .time = time,
    };
    processUidStatsLocked(filterPackages, uidStatsCollector, &record.userPackageSummaryStats);
    processProcStatLocked(procStat, &record.systemSummaryStats);
    if (collectionInfo->records.size() > collectionInfo->maxCacheSize) {
        collectionInfo->records.erase(collectionInfo->records.begin());  // Erase the oldest record.
    }
    collectionInfo->records.emplace_back(record);
    return {};
}

void IoPerfCollection::processUidStatsLocked(
        const std::unordered_set<std::string>& filterPackages,
        const sp<UidStatsCollectorInterface>& uidStatsCollector,
        UserPackageSummaryStats* userPackageSummaryStats) {
    const std::vector<UidStats>& uidStats = uidStatsCollector->deltaStats();
    if (uidStats.empty()) {
        return;
    }
    if (filterPackages.empty()) {
        userPackageSummaryStats->topNIoReads.resize(mTopNStatsPerCategory);
        userPackageSummaryStats->topNIoWrites.resize(mTopNStatsPerCategory);
        userPackageSummaryStats->topNIoBlocked.resize(mTopNStatsPerCategory);
        userPackageSummaryStats->topNMajorFaults.resize(mTopNStatsPerCategory);
    }
    for (const auto& curUidStats : uidStats) {
        uid_t uid = curUidStats.uid();
        addUidIoStats(curUidStats.ioStats.metrics, userPackageSummaryStats->totalIoStats);
        userPackageSummaryStats->totalMajorFaults += curUidStats.procStats.totalMajorFaults;
        if (filterPackages.empty()) {
            cacheTopNIoStats(MetricType::READ_BYTES, curUidStats,
                             &userPackageSummaryStats->topNIoReads);
            cacheTopNIoStats(MetricType::WRITE_BYTES, curUidStats,
                             &userPackageSummaryStats->topNIoWrites);
            if (cacheTopNProcStats(IO_BLOCKED_TASKS_COUNT, curUidStats, mTopNStatsPerSubcategory,
                                   &userPackageSummaryStats->topNIoBlocked)) {
                userPackageSummaryStats->taskCountByUid[uid] =
                        curUidStats.procStats.totalTasksCount;
            }
            cacheTopNProcStats(MAJOR_FAULTS, curUidStats, mTopNStatsPerSubcategory,
                               &userPackageSummaryStats->topNMajorFaults);
            continue;
        }
        if (filterPackages.count(curUidStats.genericPackageName()) != 0) {
            userPackageSummaryStats->topNIoReads.emplace_back(
                    toUserPackageStats(MetricType::READ_BYTES, curUidStats));
            userPackageSummaryStats->topNIoWrites.emplace_back(
                    toUserPackageStats(MetricType::WRITE_BYTES, curUidStats));
            userPackageSummaryStats->topNIoBlocked.emplace_back(
                    toUserPackageStats(IO_BLOCKED_TASKS_COUNT, curUidStats,
                                       mTopNStatsPerSubcategory));
            userPackageSummaryStats->topNMajorFaults.emplace_back(
                    toUserPackageStats(MAJOR_FAULTS, curUidStats, mTopNStatsPerSubcategory));
            userPackageSummaryStats->taskCountByUid[uid] = curUidStats.procStats.totalTasksCount;
        }
    }
    if (mLastMajorFaults != 0) {
        int64_t increase = userPackageSummaryStats->totalMajorFaults - mLastMajorFaults;
        userPackageSummaryStats->majorFaultsPercentChange =
                (static_cast<double>(increase) / static_cast<double>(mLastMajorFaults)) * 100.0;
    }
    mLastMajorFaults = userPackageSummaryStats->totalMajorFaults;

    const auto removeEmptyStats = [](std::vector<UserPackageStats>& userPackageStats) {
        for (auto it = userPackageStats.begin(); it != userPackageStats.end(); ++it) {
            /* std::monostate is the first alternative in the variant. When the variant is
             * uninitialized, the index points to this alternative.
             */
            if (it->stats.index() == 0) {
                userPackageStats.erase(it, userPackageStats.end());
                break;
            }
        }
    };
    removeEmptyStats(userPackageSummaryStats->topNIoReads);
    removeEmptyStats(userPackageSummaryStats->topNIoWrites);
    removeEmptyStats(userPackageSummaryStats->topNIoBlocked);
    removeEmptyStats(userPackageSummaryStats->topNMajorFaults);
}

void IoPerfCollection::processProcStatLocked(const sp<ProcStat>& procStat,
                                             SystemSummaryStats* systemSummaryStats) const {
    const ProcStatInfo& procStatInfo = procStat->deltaStats();
    systemSummaryStats->cpuIoWaitTime = procStatInfo.cpuStats.ioWaitTime;
    systemSummaryStats->totalCpuTime = procStatInfo.totalCpuTime();
    systemSummaryStats->ioBlockedProcessCount = procStatInfo.ioBlockedProcessCount;
    systemSummaryStats->totalProcessCount = procStatInfo.totalProcessCount();
}

}  // namespace watchdog
}  // namespace automotive
}  // namespace android
