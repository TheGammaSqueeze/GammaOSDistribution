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

#ifndef CPP_WATCHDOG_SERVER_SRC_IOPERFCOLLECTION_H_
#define CPP_WATCHDOG_SERVER_SRC_IOPERFCOLLECTION_H_

#include "ProcDiskStats.h"
#include "ProcStat.h"
#include "UidStatsCollector.h"
#include "WatchdogPerfService.h"

#include <android-base/result.h>
#include <cutils/multiuser.h>
#include <gtest/gtest_prod.h>
#include <utils/Errors.h>
#include <utils/Mutex.h>
#include <utils/RefBase.h>

#include <ctime>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>

namespace android {
namespace automotive {
namespace watchdog {

// Number of periodic collection records to cache in memory.
constexpr int32_t kDefaultPeriodicCollectionBufferSize = 180;
constexpr const char kEmptyCollectionMessage[] = "No collection recorded\n";

// Forward declaration for testing use only.
namespace internal {

class IoPerfCollectionPeer;

}  // namespace internal

// Below structs should be used only by the implementation and unit tests.
/**
 * Struct to represent user package performance stats.
 */
struct UserPackageStats {
    struct IoStats {
        int64_t bytes[UID_STATES] = {0};
        int64_t fsync[UID_STATES] = {0};

        int64_t totalBytes() const {
            return std::numeric_limits<int64_t>::max() - bytes[UidState::FOREGROUND] >
                            bytes[UidState::BACKGROUND]
                    ? bytes[UidState::FOREGROUND] + bytes[UidState::BACKGROUND]
                    : std::numeric_limits<int64_t>::max();
        }
    };
    struct ProcStats {
        uint64_t count = 0;
        struct ProcessCount {
            std::string comm = "";
            uint64_t count = 0;
        };
        std::vector<ProcessCount> topNProcesses = {};
    };
    uid_t uid = 0;
    std::string genericPackageName = "";
    std::variant<std::monostate, IoStats, ProcStats> stats;
    std::string toString(MetricType metricsType, const int64_t totalIoStats[][UID_STATES]) const;
    std::string toString(int64_t count) const;
};

/**
 * User package summary performance stats collected from the `/proc/uid_io/stats`,
 * `/proc/[pid]/stat`, `/proc/[pid]/task/[tid]/stat`, and /proc/[pid]/status` files.
 */
struct UserPackageSummaryStats {
    std::vector<UserPackageStats> topNIoReads = {};
    std::vector<UserPackageStats> topNIoWrites = {};
    std::vector<UserPackageStats> topNIoBlocked = {};
    std::vector<UserPackageStats> topNMajorFaults = {};
    int64_t totalIoStats[METRIC_TYPES][UID_STATES] = {{0}};
    std::unordered_map<uid_t, uint64_t> taskCountByUid = {};
    uint64_t totalMajorFaults = 0;
    // Percentage of increase/decrease in the major page faults since last collection.
    double majorFaultsPercentChange = 0.0;
    std::string toString() const;
};

// System performance stats collected from the `/proc/stats` file.
struct SystemSummaryStats {
    uint64_t cpuIoWaitTime = 0;
    uint64_t totalCpuTime = 0;
    uint32_t ioBlockedProcessCount = 0;
    uint32_t totalProcessCount = 0;
    std::string toString() const;
};

// Performance record collected during a sampling/collection period.
struct PerfStatsRecord {
    time_t time;  // Collection time.
    SystemSummaryStats systemSummaryStats;
    UserPackageSummaryStats userPackageSummaryStats;
    std::string toString() const;
};

// Group of performance records collected for a collection event.
struct CollectionInfo {
    size_t maxCacheSize = 0;               // Maximum cache size for the collection.
    std::vector<PerfStatsRecord> records;  // Cache of collected performance records.
    std::string toString() const;
};

// IoPerfCollection implements the I/O performance data collection module.
class IoPerfCollection : public IDataProcessorInterface {
public:
    IoPerfCollection() :
          mTopNStatsPerCategory(0),
          mTopNStatsPerSubcategory(0),
          mBoottimeCollection({}),
          mPeriodicCollection({}),
          mCustomCollection({}),
          mLastMajorFaults(0) {}

    ~IoPerfCollection() { terminate(); }

    std::string name() const override { return "IoPerfCollection"; }

    // Implements IDataProcessorInterface.
    android::base::Result<void> onBoottimeCollection(
            time_t time, const android::wp<UidStatsCollectorInterface>& uidStatsCollector,
            const android::wp<ProcStat>& procStat) override;

    android::base::Result<void> onPeriodicCollection(
            time_t time, SystemState systemState,
            const android::wp<UidStatsCollectorInterface>& uidStatsCollector,
            const android::wp<ProcStat>& procStat) override;

    android::base::Result<void> onCustomCollection(
            time_t time, SystemState systemState,
            const std::unordered_set<std::string>& filterPackages,
            const android::wp<UidStatsCollectorInterface>& uidStatsCollector,
            const android::wp<ProcStat>& procStat) override;

    android::base::Result<void> onPeriodicMonitor(
            [[maybe_unused]] time_t time,
            [[maybe_unused]] const android::wp<IProcDiskStatsInterface>& procDiskStats,
            [[maybe_unused]] const std::function<void()>& alertHandler) override {
        // No monitoring done here as this DataProcessor only collects I/O performance records.
        return {};
    }

    android::base::Result<void> onDump(int fd) const override;

    android::base::Result<void> onCustomCollectionDump(int fd) override;

protected:
    android::base::Result<void> init();

    // Clears in-memory cache.
    void terminate();

private:
    // Processes the collected data.
    android::base::Result<void> processLocked(
            time_t time, const std::unordered_set<std::string>& filterPackages,
            const android::sp<UidStatsCollectorInterface>& uidStatsCollector,
            const android::sp<ProcStat>& procStat, CollectionInfo* collectionInfo);

    // Processes per-UID performance data.
    void processUidStatsLocked(const std::unordered_set<std::string>& filterPackages,
                               const android::sp<UidStatsCollectorInterface>& uidStatsCollector,
                               UserPackageSummaryStats* userPackageSummaryStats);

    // Processes system performance data from the `/proc/stats` file.
    void processProcStatLocked(const android::sp<ProcStat>& procStat,
                               SystemSummaryStats* systemSummaryStats) const;

    // Top N per-UID stats per category.
    int mTopNStatsPerCategory;

    // Top N per-process stats per subcategory.
    int mTopNStatsPerSubcategory;

    // Makes sure only one collection is running at any given time.
    mutable Mutex mMutex;

    // Info for the boot-time collection event. The cache is persisted until system shutdown/reboot.
    CollectionInfo mBoottimeCollection GUARDED_BY(mMutex);

    /**
     * Info for the periodic collection event. The cache size is limited by
     * |ro.carwatchdog.periodic_collection_buffer_size|.
     */
    CollectionInfo mPeriodicCollection GUARDED_BY(mMutex);

    /**
     * Info for the custom collection event. The info is cleared at the end of every custom
     * collection.
     */
    CollectionInfo mCustomCollection GUARDED_BY(mMutex);

    /**
     * Major faults delta from last collection. Useful when calculating the percentage change in
     * major faults since last collection.
     */
    uint64_t mLastMajorFaults GUARDED_BY(mMutex);

    friend class WatchdogPerfService;

    // For unit tests.
    friend class internal::IoPerfCollectionPeer;
};

}  // namespace watchdog
}  // namespace automotive
}  // namespace android

#endif  //  CPP_WATCHDOG_SERVER_SRC_IOPERFCOLLECTION_H_
