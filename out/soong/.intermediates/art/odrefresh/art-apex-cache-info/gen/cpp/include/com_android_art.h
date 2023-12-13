#ifndef COM_ANDROID_ART_H
#define COM_ANDROID_ART_H

#include <array>
#include <map>
#include <optional>
#include <string>
#include <vector>
#include <iostream>

#if __has_include(<libxml/parser.h>)
#include <libxml/parser.h>
#include <libxml/xinclude.h>
#else
#error Require libxml2 library. Please add libxml2 to shared_libs or static_libs
#endif

#include "com_android_art_enums.h"

namespace com {
    namespace android {
        namespace art {
            class ArtModuleInfo;
            class Dex2oatBootClasspath;
            class SystemServerClasspath;
            class Component;
            class CacheInfo;
            std::optional<CacheInfo> read(const char* configFile);

            void write(std::ostream& out, CacheInfo& cacheInfo);

            class ArtModuleInfo {
                private:
                const int64_t versionCode_;
                const std::string versionName_;
                const int64_t lastUpdateMillis_;
                public:
                ArtModuleInfo(int64_t versionCode, std::string versionName, int64_t lastUpdateMillis);
                const int64_t& getVersionCode() const;
                bool hasVersionCode() const;
                const std::string& getVersionName() const;
                bool hasVersionName() const;
                const int64_t& getLastUpdateMillis() const;
                bool hasLastUpdateMillis() const;
                static ArtModuleInfo read(xmlNode *root);
                void write(std::ostream& out, const std::string& name) const;
            };

            class Dex2oatBootClasspath {
                private:
                const std::vector<Component> component_;
                public:
                explicit Dex2oatBootClasspath(std::vector<Component> component);
                const std::vector<Component>& getComponent() const;
                bool hasComponent() const;
                const Component* getFirstComponent() const;
                static Dex2oatBootClasspath read(xmlNode *root);
                void write(std::ostream& out, const std::string& name) const;
            };

            class SystemServerClasspath {
                private:
                const std::vector<Component> component_;
                public:
                explicit SystemServerClasspath(std::vector<Component> component);
                const std::vector<Component>& getComponent() const;
                bool hasComponent() const;
                const Component* getFirstComponent() const;
                static SystemServerClasspath read(xmlNode *root);
                void write(std::ostream& out, const std::string& name) const;
            };

            class Component {
                private:
                const std::string file_;
                const uint64_t size_;
                const std::string checksums_;
                public:
                Component(std::string file, uint64_t size, std::string checksums);
                const std::string& getFile() const;
                bool hasFile() const;
                const uint64_t& getSize() const;
                bool hasSize() const;
                const std::string& getChecksums() const;
                bool hasChecksums() const;
                static Component read(xmlNode *root);
                void write(std::ostream& out, const std::string& name) const;
            };

            class CacheInfo {
                private:
                const std::vector<ArtModuleInfo> artModuleInfo_;
                const std::vector<Dex2oatBootClasspath> dex2oatBootClasspath_;
                const std::vector<SystemServerClasspath> systemServerClasspath_;
                public:
                CacheInfo(std::vector<ArtModuleInfo> artModuleInfo, std::vector<Dex2oatBootClasspath> dex2oatBootClasspath, std::vector<SystemServerClasspath> systemServerClasspath);
                const std::vector<ArtModuleInfo>& getArtModuleInfo() const;
                bool hasArtModuleInfo() const;
                const ArtModuleInfo* getFirstArtModuleInfo() const;
                const std::vector<Dex2oatBootClasspath>& getDex2oatBootClasspath() const;
                bool hasDex2oatBootClasspath() const;
                const Dex2oatBootClasspath* getFirstDex2oatBootClasspath() const;
                const std::vector<SystemServerClasspath>& getSystemServerClasspath() const;
                bool hasSystemServerClasspath() const;
                const SystemServerClasspath* getFirstSystemServerClasspath() const;
                static CacheInfo read(xmlNode *root);
                void write(std::ostream& out, const std::string& name) const;
            };

        } // art
    } // android
} // com
#endif // COM_ANDROID_ART_H
