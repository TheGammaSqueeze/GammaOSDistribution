/*
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
#define DEBUG false  // STOPSHIP if true.

#include "UidProcStatsCollector.h"

#include <android-base/file.h>
#include <android-base/parseint.h>
#include <android-base/stringprintf.h>
#include <android-base/strings.h>
#include <log/log.h>

#include <dirent.h>

#include <string>
#include <unordered_map>
#include <vector>

namespace android {
namespace automotive {
namespace watchdog {

using ::android::base::EndsWith;
using ::android::base::Error;
using ::android::base::ParseInt;
using ::android::base::ParseUint;
using ::android::base::ReadFileToString;
using ::android::base::Result;
using ::android::base::Split;
using ::android::base::StringAppendF;
using ::android::base::Trim;

namespace {

enum ReadError {
    ERR_INVALID_FILE = 0,
    ERR_FILE_OPEN_READ = 1,
    NUM_ERRORS = 2,
};

// Per-pid/tid stats.
struct PidStat {
    std::string comm = "";
    std::string state = "";
    uint64_t startTime = 0;
    uint64_t majorFaults = 0;
};

/**
 * /proc/PID/stat or /proc/PID/task/TID/stat format:
 * <pid> <comm> <state> <ppid> <pgrp ID> <session ID> <tty_nr> <tpgid> <flags> <minor faults>
 * <children minor faults> <major faults> <children major faults> <user mode time>
 * <system mode time> <children user mode time> <children kernel mode time> <priority> <nice value>
 * <num threads> <start time since boot> <virtual memory size> <resident set size> <rss soft limit>
 * <start code addr> <end code addr> <start stack addr> <ESP value> <EIP> <bitmap of pending sigs>
 * <bitmap of blocked sigs> <bitmap of ignored sigs> <waiting channel> <num pages swapped>
 * <cumulative pages swapped> <exit signal> <processor #> <real-time prio> <agg block I/O delays>
 * <guest time> <children guest time> <start data addr> <end data addr> <start break addr>
 * <cmd line args start addr> <amd line args end addr> <env start addr> <env end addr> <exit code>
 * Example line: 1 (init) S 0 0 0 0 0 0 0 0 220 0 0 0 0 0 0 0 2 0 0 ...etc...
 */
bool parsePidStatLine(const std::string& line, PidStat* pidStat) {
    std::vector<std::string> fields = Split(line, " ");

    /* Note: Regex parsing for the below logic increased the time taken to run the
     * UidProcStatsCollectorTest#TestProcPidStatContentsFromDevice from 151.7ms to 1.3 seconds.
     *
     * Comm string is enclosed with ( ) brackets and may contain space(s). Thus calculate the
     * commEndOffset based on the field that contains the closing bracket.
     */
    size_t commEndOffset = 0;
    for (size_t i = 1; i < fields.size(); ++i) {
        pidStat->comm += fields[i];
        if (EndsWith(fields[i], ")")) {
            commEndOffset = i - 1;
            break;
        }
        pidStat->comm += " ";
    }

    if (pidStat->comm.front() != '(' || pidStat->comm.back() != ')') {
        ALOGD("Comm string `%s` not enclosed in brackets", pidStat->comm.c_str());
        return false;
    }
    pidStat->comm.erase(pidStat->comm.begin());
    pidStat->comm.erase(pidStat->comm.end() - 1);

    if (fields.size() < 22 + commEndOffset ||
        !ParseUint(fields[11 + commEndOffset], &pidStat->majorFaults) ||
        !ParseUint(fields[21 + commEndOffset], &pidStat->startTime)) {
        ALOGD("Invalid proc pid stat contents: \"%s\"", line.c_str());
        return false;
    }
    pidStat->state = fields[2 + commEndOffset];
    return true;
}

Result<void> readPidStatFile(const std::string& path, PidStat* pidStat) {
    std::string buffer;
    if (!ReadFileToString(path, &buffer)) {
        return Error(ERR_FILE_OPEN_READ) << "ReadFileToString failed for " << path;
    }
    std::vector<std::string> lines = Split(std::move(buffer), "\n");
    if (lines.size() != 1 && (lines.size() != 2 || !lines[1].empty())) {
        return Error(ERR_INVALID_FILE) << path << " contains " << lines.size() << " lines != 1";
    }
    if (!parsePidStatLine(std::move(lines[0]), pidStat)) {
        return Error(ERR_INVALID_FILE) << "Failed to parse the contents of " << path;
    }
    return {};
}

Result<std::unordered_map<std::string, std::string>> readKeyValueFile(
        const std::string& path, const std::string& delimiter) {
    std::string buffer;
    if (!ReadFileToString(path, &buffer)) {
        return Error(ERR_FILE_OPEN_READ) << "ReadFileToString failed for " << path;
    }
    std::unordered_map<std::string, std::string> contents;
    std::vector<std::string> lines = Split(std::move(buffer), "\n");
    for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].empty()) {
            continue;
        }
        std::vector<std::string> elements = Split(lines[i], delimiter);
        if (elements.size() < 2) {
            return Error(ERR_INVALID_FILE)
                    << "Line \"" << lines[i] << "\" doesn't contain the delimiter \"" << delimiter
                    << "\" in file " << path;
        }
        std::string key = elements[0];
        std::string value = Trim(lines[i].substr(key.length() + delimiter.length()));
        if (contents.find(key) != contents.end()) {
            return Error(ERR_INVALID_FILE)
                    << "Duplicate " << key << " line: \"" << lines[i] << "\" in file " << path;
        }
        contents[key] = value;
    }
    return contents;
}

/**
 * /proc/PID/status file format:
 * Tgid:    <Thread group ID of the process>
 * Uid:     <Read UID>   <Effective UID>   <Saved set UID>   <Filesystem UID>
 *
 * Note: Included only the fields that are parsed from the file.
 */
Result<std::tuple<uid_t, pid_t>> readPidStatusFile(const std::string& path) {
    auto result = readKeyValueFile(path, ":\t");
    if (!result.ok()) {
        return Error(result.error().code()) << result.error();
    }
    auto contents = result.value();
    if (contents.empty()) {
        return Error(ERR_INVALID_FILE) << "Empty file " << path;
    }
    int64_t uid = 0;
    int64_t tgid = 0;
    if (contents.find("Uid") == contents.end() ||
        !ParseInt(Split(contents["Uid"], "\t")[0], &uid)) {
        return Error(ERR_INVALID_FILE) << "Failed to read 'UID' from file " << path;
    }
    if (contents.find("Tgid") == contents.end() || !ParseInt(contents["Tgid"], &tgid)) {
        return Error(ERR_INVALID_FILE) << "Failed to read 'Tgid' from file " << path;
    }
    return std::make_tuple(uid, tgid);
}

}  // namespace

std::string ProcessStats::toString() const {
    return StringPrintf("{comm: %s, startTime: %" PRIu64 ", totalMajorFaults: %" PRIu64
                        ", totalTasksCount: %d, ioBlockedTasksCount: %d}",
                        comm.c_str(), startTime, totalMajorFaults, totalTasksCount,
                        ioBlockedTasksCount);
}

std::string UidProcStats::toString() const {
    std::string buffer;
    StringAppendF(&buffer,
                  "UidProcStats{totalMajorFaults: %" PRIu64 ", totalTasksCount: %d,"
                  "ioBlockedTasksCount: %d, processStatsByPid: {",
                  totalMajorFaults, totalTasksCount, ioBlockedTasksCount);
    for (const auto& [pid, processStats] : processStatsByPid) {
        StringAppendF(&buffer, "{pid: %" PRIi32 ", processStats: %s},", pid,
                      processStats.toString().c_str());
    }
    StringAppendF(&buffer, "}");
    return buffer;
}

void UidProcStatsCollector::init() {
    // Note: Verify proc file access outside the constructor. Otherwise, the unittests of
    // dependent classes would call the constructor before mocking and get killed due to
    // sepolicy violation.
    std::string pidStatPath = StringPrintf((mPath + kStatFileFormat).c_str(), PID_FOR_INIT);
    std::string tidStatPath = StringPrintf((mPath + kTaskDirFormat + kStatFileFormat).c_str(),
                                           PID_FOR_INIT, PID_FOR_INIT);
    std::string pidStatusPath = StringPrintf((mPath + kStatusFileFormat).c_str(), PID_FOR_INIT);

    Mutex::Autolock lock(mMutex);
    mEnabled = access(pidStatPath.c_str(), R_OK) == 0 && access(tidStatPath.c_str(), R_OK) == 0 &&
            access(pidStatusPath.c_str(), R_OK) == 0;
}

Result<void> UidProcStatsCollector::collect() {
    if (!mEnabled) {
        return Error() << "Can not access PID stat files under " << kProcDirPath;
    }

    Mutex::Autolock lock(mMutex);
    auto uidProcStatsByUid = readUidProcStatsLocked();
    if (!uidProcStatsByUid.ok()) {
        return Error() << uidProcStatsByUid.error();
    }

    mDeltaStats.clear();
    for (const auto& [uid, currStats] : *uidProcStatsByUid) {
        if (const auto& it = mLatestStats.find(uid); it == mLatestStats.end()) {
            mDeltaStats[uid] = currStats;
            continue;
        }
        const auto& prevStats = mLatestStats[uid];
        UidProcStats deltaStats = {
                .totalTasksCount = currStats.totalTasksCount,
                .ioBlockedTasksCount = currStats.ioBlockedTasksCount,
        };
        for (const auto& [pid, processStats] : currStats.processStatsByPid) {
            ProcessStats deltaProcessStats = processStats;
            if (const auto& it = prevStats.processStatsByPid.find(pid);
                it != prevStats.processStatsByPid.end() &&
                it->second.startTime == processStats.startTime &&
                it->second.totalMajorFaults <= deltaProcessStats.totalMajorFaults) {
                deltaProcessStats.totalMajorFaults =
                        deltaProcessStats.totalMajorFaults - it->second.totalMajorFaults;
            }
            deltaStats.totalMajorFaults += deltaProcessStats.totalMajorFaults;
            deltaStats.processStatsByPid[pid] = deltaProcessStats;
        }
        mDeltaStats[uid] = std::move(deltaStats);
    }
    mLatestStats = std::move(*uidProcStatsByUid);
    return {};
}

Result<std::unordered_map<uid_t, UidProcStats>> UidProcStatsCollector::readUidProcStatsLocked()
        const {
    std::unordered_map<uid_t, UidProcStats> uidProcStatsByUid;
    auto procDirp = std::unique_ptr<DIR, int (*)(DIR*)>(opendir(mPath.c_str()), closedir);
    if (!procDirp) {
        return Error() << "Failed to open " << mPath << " directory";
    }
    for (dirent* pidDir = nullptr; (pidDir = readdir(procDirp.get())) != nullptr;) {
        pid_t pid = 0;
        if (pidDir->d_type != DT_DIR || !ParseInt(pidDir->d_name, &pid)) {
            continue;
        }
        auto result = readProcessStatsLocked(pid);
        if (!result.ok()) {
            if (result.error().code() != ERR_FILE_OPEN_READ) {
                return Error() << result.error();
            }
            /* |ERR_FILE_OPEN_READ| is a soft-error because PID may disappear between scanning and
             * reading directory/files.
             */
            if (DEBUG) {
                ALOGD("%s", result.error().message().c_str());
            }
            continue;
        }
        uid_t uid = std::get<0>(*result);
        ProcessStats processStats = std::get<ProcessStats>(*result);
        if (uidProcStatsByUid.find(uid) == uidProcStatsByUid.end()) {
            uidProcStatsByUid[uid] = {};
        }
        UidProcStats* uidProcStats = &uidProcStatsByUid[uid];
        uidProcStats->totalMajorFaults += processStats.totalMajorFaults;
        uidProcStats->totalTasksCount += processStats.totalTasksCount;
        uidProcStats->ioBlockedTasksCount += processStats.ioBlockedTasksCount;
        uidProcStats->processStatsByPid[pid] = std::move(processStats);
    }
    return uidProcStatsByUid;
}

Result<std::tuple<uid_t, ProcessStats>> UidProcStatsCollector::readProcessStatsLocked(
        pid_t pid) const {
    // 1. Read top-level pid stats.
    PidStat pidStat = {};
    std::string path = StringPrintf((mPath + kStatFileFormat).c_str(), pid);
    if (auto result = readPidStatFile(path, &pidStat); !result.ok()) {
        return Error(result.error().code())
                << "Failed to read top-level per-process stat file '%s': %s"
                << result.error().message().c_str();
    }

    // 2. Read aggregated process status.
    pid_t tgid = -1;
    uid_t uid = -1;
    path = StringPrintf((mPath + kStatusFileFormat).c_str(), pid);
    if (auto result = readPidStatusFile(path); !result.ok()) {
        if (result.error().code() != ERR_FILE_OPEN_READ) {
            return Error() << "Failed to read pid status for pid " << pid << ": "
                           << result.error().message().c_str();
        }
        for (const auto& [curUid, uidProcStats] : mLatestStats) {
            if (const auto it = uidProcStats.processStatsByPid.find(pid);
                it != uidProcStats.processStatsByPid.end() &&
                it->second.startTime == pidStat.startTime) {
                tgid = pid;
                uid = curUid;
                break;
            }
        }
    } else {
        uid = std::get<0>(*result);
        tgid = std::get<1>(*result);
    }

    if (uid == -1 || tgid != pid) {
        return Error(ERR_FILE_OPEN_READ)
                << "Skipping PID '" << pid << "' because either Tgid != PID or invalid UID";
    }

    ProcessStats processStats = {
            .comm = std::move(pidStat.comm),
            .startTime = pidStat.startTime,
            .totalTasksCount = 1,
            /* Top-level process stats has the aggregated major page faults count and this should be
             * persistent across thread creation/termination. Thus use the value from this field.
             */
            .totalMajorFaults = pidStat.majorFaults,
            .ioBlockedTasksCount = pidStat.state == "D" ? 1 : 0,
    };

    // 3. Read per-thread stats.
    std::string taskDir = StringPrintf((mPath + kTaskDirFormat).c_str(), pid);
    bool didReadMainThread = false;
    auto taskDirp = std::unique_ptr<DIR, int (*)(DIR*)>(opendir(taskDir.c_str()), closedir);
    for (dirent* tidDir = nullptr;
         taskDirp != nullptr && (tidDir = readdir(taskDirp.get())) != nullptr;) {
        pid_t tid = 0;
        if (tidDir->d_type != DT_DIR || !ParseInt(tidDir->d_name, &tid) || tid == pid) {
            continue;
        }

        PidStat tidStat = {};
        path = StringPrintf((taskDir + kStatFileFormat).c_str(), tid);
        if (const auto& result = readPidStatFile(path, &tidStat); !result.ok()) {
            if (result.error().code() != ERR_FILE_OPEN_READ) {
                return Error() << "Failed to read per-thread stat file: "
                               << result.error().message().c_str();
            }
            /* Maybe the thread terminated before reading the file so skip this thread and
             * continue with scanning the next thread's stat.
             */
            continue;
        }
        processStats.ioBlockedTasksCount += tidStat.state == "D" ? 1 : 0;
        processStats.totalTasksCount += 1;
    }
    return std::make_tuple(uid, processStats);
}

}  // namespace watchdog
}  // namespace automotive
}  // namespace android
