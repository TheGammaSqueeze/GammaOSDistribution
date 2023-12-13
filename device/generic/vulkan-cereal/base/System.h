#include "base/CpuTime.h"

#include <string>

namespace android {
namespace base {

std::string getEnvironmentVariable(const std::string& key);
void setEnvironmentVariable(const std::string& key, const std::string& value);
bool isVerboseLogging();

uint64_t getUnixTimeUs();
uint64_t getHighResTimeUs();

uint64_t getUptimeMs();

std::string getProgramDirectory();
std::string getLauncherDirectory();

bool getFileSize(int fd, uint64_t* size);

void sleepMs(uint64_t ms);
void sleepUs(uint64_t us);

CpuTime cpuTime();

bool queryFileVersionInfo(const char* filename, int* major, int* minor, int* build1, int* build2);

int getCpuCoreCount();

} // namespace base
} // namespace android
