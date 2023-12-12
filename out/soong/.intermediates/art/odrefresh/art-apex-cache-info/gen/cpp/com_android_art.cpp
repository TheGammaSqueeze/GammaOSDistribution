#define LOG_TAG "com.android.art"
#include "com_android_art.h"

namespace com {
    namespace android {
        namespace art {
            template <class T>
            constexpr void (*xmlDeleter)(T* t);
            template <>
            constexpr auto xmlDeleter<xmlDoc> = xmlFreeDoc;
            template <>
            auto xmlDeleter<xmlChar> = [](xmlChar *s) { xmlFree(s); };

            template <class T>
            constexpr auto make_xmlUnique(T *t) {
                auto deleter = [](T *t) { xmlDeleter<T>(t); };
                return std::unique_ptr<T, decltype(deleter)>{t, deleter};
            }

            static std::string getXmlAttribute(const xmlNode *cur, const char *attribute) {
                auto xmlValue = make_xmlUnique(xmlGetProp(cur, reinterpret_cast<const xmlChar*>(attribute)));
                if (xmlValue == nullptr) {
                    return "";
                }
                std::string value(reinterpret_cast<const char*>(xmlValue.get()));
                return value;
            }

            std::optional<CacheInfo> read(const char* configFile) {
                auto doc = make_xmlUnique(xmlParseFile(configFile));
                if (doc == nullptr) {
                    return std::nullopt;
                }
                xmlNodePtr child = xmlDocGetRootElement(doc.get());
                if (child == nullptr) {
                    return std::nullopt;
                }
                if (xmlXIncludeProcess(doc.get()) < 0) {
                    return std::nullopt;
                }

                if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("cacheInfo"))) {
                    CacheInfo value = CacheInfo::read(child);
                    return value;
                }
                return std::nullopt;
            }

            void write(std::ostream& out, CacheInfo& cacheInfo) {
                out << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
                cacheInfo.write(out, "cacheInfo");
            }

            static int indentIndex = 0;
            std::string printIndent() {
                std::string s = "";
                for (int index = 0; index < indentIndex; ++index) {
                    s += "    ";
                }
                return s;
            }


            ArtModuleInfo::ArtModuleInfo(int64_t versionCode, std::string versionName, int64_t lastUpdateMillis) : versionCode_(versionCode), versionName_(std::move(versionName)), lastUpdateMillis_(lastUpdateMillis) {
            }

            const int64_t& ArtModuleInfo::getVersionCode() const {
                return versionCode_;
            }

            bool ArtModuleInfo::hasVersionCode() const {
                return true;
            }

            const std::string& ArtModuleInfo::getVersionName() const {
                return versionName_;
            }

            bool ArtModuleInfo::hasVersionName() const {
                return true;
            }

            const int64_t& ArtModuleInfo::getLastUpdateMillis() const {
                return lastUpdateMillis_;
            }

            bool ArtModuleInfo::hasLastUpdateMillis() const {
                return true;
            }

            ArtModuleInfo ArtModuleInfo::read(xmlNode *root) {
                std::string raw;
                raw = getXmlAttribute(root, "versionCode");
                int64_t versionCode{};
                if (raw != "") {
                    int64_t value = std::stoll(raw);
                    versionCode = value;
                }
                raw = getXmlAttribute(root, "versionName");
                std::string versionName{};
                if (raw != "") {
                    std::string &value = raw;
                    versionName = value;
                }
                raw = getXmlAttribute(root, "lastUpdateMillis");
                int64_t lastUpdateMillis{};
                if (raw != "") {
                    int64_t value = std::stoll(raw);
                    lastUpdateMillis = value;
                }
                ArtModuleInfo instance(versionCode, versionName, lastUpdateMillis);
                return instance;
            }

            void ArtModuleInfo::write(std::ostream& out, const std::string& name) const {
                out << printIndent() << "<" << name;
                if (hasVersionCode()) {
                    out << " versionCode=\"";
                    out << getVersionCode();
                    out << "\"";
                }
                if (hasVersionName()) {
                    out << " versionName=\"";
                    out << getVersionName();
                    out << "\"";
                }
                if (hasLastUpdateMillis()) {
                    out << " lastUpdateMillis=\"";
                    out << getLastUpdateMillis();
                    out << "\"";
                }
                out << ">" << std::endl;
                ++indentIndex;
                --indentIndex;
                out << printIndent() << "</" << name << ">" << std::endl;
            }

            Dex2oatBootClasspath::Dex2oatBootClasspath(std::vector<Component> component) : component_(std::move(component)) {
            }

            const std::vector<Component>& Dex2oatBootClasspath::getComponent() const {
                return component_;
            }

            bool Dex2oatBootClasspath::hasComponent() const {
                return !(component_.empty());
            }

            const Component* Dex2oatBootClasspath::getFirstComponent() const {
                if (component_.empty()) {
                    return nullptr;
                }
                return &component_[0];
            }

            Dex2oatBootClasspath Dex2oatBootClasspath::read(xmlNode *root) {
                std::string raw;
                std::vector<Component> component;
                for (xmlNode *child = root->xmlChildrenNode; child != nullptr; child = child->next) {
                    if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("component"))) {
                        Component value = Component::read(child);
                        component.push_back(std::move(value));
                    }
                }
                Dex2oatBootClasspath instance(component);
                return instance;
            }

            void Dex2oatBootClasspath::write(std::ostream& out, const std::string& name) const {
                out << printIndent() << "<" << name;
                out << ">" << std::endl;
                ++indentIndex;
                for (auto& value : getComponent()) {
                    value.write(out, "component");
                }
                --indentIndex;
                out << printIndent() << "</" << name << ">" << std::endl;
            }

            SystemServerClasspath::SystemServerClasspath(std::vector<Component> component) : component_(std::move(component)) {
            }

            const std::vector<Component>& SystemServerClasspath::getComponent() const {
                return component_;
            }

            bool SystemServerClasspath::hasComponent() const {
                return !(component_.empty());
            }

            const Component* SystemServerClasspath::getFirstComponent() const {
                if (component_.empty()) {
                    return nullptr;
                }
                return &component_[0];
            }

            SystemServerClasspath SystemServerClasspath::read(xmlNode *root) {
                std::string raw;
                std::vector<Component> component;
                for (xmlNode *child = root->xmlChildrenNode; child != nullptr; child = child->next) {
                    if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("component"))) {
                        Component value = Component::read(child);
                        component.push_back(std::move(value));
                    }
                }
                SystemServerClasspath instance(component);
                return instance;
            }

            void SystemServerClasspath::write(std::ostream& out, const std::string& name) const {
                out << printIndent() << "<" << name;
                out << ">" << std::endl;
                ++indentIndex;
                for (auto& value : getComponent()) {
                    value.write(out, "component");
                }
                --indentIndex;
                out << printIndent() << "</" << name << ">" << std::endl;
            }

            Component::Component(std::string file, uint64_t size, std::string checksums) : file_(std::move(file)), size_(size), checksums_(std::move(checksums)) {
            }

            const std::string& Component::getFile() const {
                return file_;
            }

            bool Component::hasFile() const {
                return true;
            }

            const uint64_t& Component::getSize() const {
                return size_;
            }

            bool Component::hasSize() const {
                return true;
            }

            const std::string& Component::getChecksums() const {
                return checksums_;
            }

            bool Component::hasChecksums() const {
                return true;
            }

            Component Component::read(xmlNode *root) {
                std::string raw;
                raw = getXmlAttribute(root, "file");
                std::string file{};
                if (raw != "") {
                    std::string &value = raw;
                    file = value;
                }
                raw = getXmlAttribute(root, "size");
                uint64_t size{};
                if (raw != "") {
                    uint64_t value = std::stoull(raw);
                    size = value;
                }
                raw = getXmlAttribute(root, "checksums");
                std::string checksums{};
                if (raw != "") {
                    std::string &value = raw;
                    checksums = value;
                }
                Component instance(file, size, checksums);
                return instance;
            }

            void Component::write(std::ostream& out, const std::string& name) const {
                out << printIndent() << "<" << name;
                if (hasFile()) {
                    out << " file=\"";
                    out << getFile();
                    out << "\"";
                }
                if (hasSize()) {
                    out << " size=\"";
                    out << getSize();
                    out << "\"";
                }
                if (hasChecksums()) {
                    out << " checksums=\"";
                    out << getChecksums();
                    out << "\"";
                }
                out << ">" << std::endl;
                ++indentIndex;
                --indentIndex;
                out << printIndent() << "</" << name << ">" << std::endl;
            }

            CacheInfo::CacheInfo(std::vector<ArtModuleInfo> artModuleInfo, std::vector<Dex2oatBootClasspath> dex2oatBootClasspath, std::vector<SystemServerClasspath> systemServerClasspath) : artModuleInfo_(std::move(artModuleInfo)), dex2oatBootClasspath_(std::move(dex2oatBootClasspath)), systemServerClasspath_(std::move(systemServerClasspath)) {
            }

            const std::vector<ArtModuleInfo>& CacheInfo::getArtModuleInfo() const {
                return artModuleInfo_;
            }

            bool CacheInfo::hasArtModuleInfo() const {
                return !(artModuleInfo_.empty());
            }

            const ArtModuleInfo* CacheInfo::getFirstArtModuleInfo() const {
                if (artModuleInfo_.empty()) {
                    return nullptr;
                }
                return &artModuleInfo_[0];
            }

            const std::vector<Dex2oatBootClasspath>& CacheInfo::getDex2oatBootClasspath() const {
                return dex2oatBootClasspath_;
            }

            bool CacheInfo::hasDex2oatBootClasspath() const {
                return !(dex2oatBootClasspath_.empty());
            }

            const Dex2oatBootClasspath* CacheInfo::getFirstDex2oatBootClasspath() const {
                if (dex2oatBootClasspath_.empty()) {
                    return nullptr;
                }
                return &dex2oatBootClasspath_[0];
            }

            const std::vector<SystemServerClasspath>& CacheInfo::getSystemServerClasspath() const {
                return systemServerClasspath_;
            }

            bool CacheInfo::hasSystemServerClasspath() const {
                return !(systemServerClasspath_.empty());
            }

            const SystemServerClasspath* CacheInfo::getFirstSystemServerClasspath() const {
                if (systemServerClasspath_.empty()) {
                    return nullptr;
                }
                return &systemServerClasspath_[0];
            }

            CacheInfo CacheInfo::read(xmlNode *root) {
                std::string raw;
                std::vector<ArtModuleInfo> artModuleInfo;
                std::vector<Dex2oatBootClasspath> dex2oatBootClasspath;
                std::vector<SystemServerClasspath> systemServerClasspath;
                for (xmlNode *child = root->xmlChildrenNode; child != nullptr; child = child->next) {
                    if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("artModuleInfo"))) {
                        ArtModuleInfo value = ArtModuleInfo::read(child);
                        artModuleInfo.push_back(std::move(value));
                    } else if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("dex2oatBootClasspath"))) {
                        Dex2oatBootClasspath value = Dex2oatBootClasspath::read(child);
                        dex2oatBootClasspath.push_back(std::move(value));
                    } else if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("systemServerClasspath"))) {
                        SystemServerClasspath value = SystemServerClasspath::read(child);
                        systemServerClasspath.push_back(std::move(value));
                    }
                }
                CacheInfo instance(artModuleInfo, dex2oatBootClasspath, systemServerClasspath);
                return instance;
            }

            void CacheInfo::write(std::ostream& out, const std::string& name) const {
                out << printIndent() << "<" << name;
                out << ">" << std::endl;
                ++indentIndex;
                for (auto& value : getArtModuleInfo()) {
                    value.write(out, "artModuleInfo");
                }
                for (auto& value : getDex2oatBootClasspath()) {
                    value.write(out, "dex2oatBootClasspath");
                }
                for (auto& value : getSystemServerClasspath()) {
                    value.write(out, "systemServerClasspath");
                }
                --indentIndex;
                out << printIndent() << "</" << name << ">" << std::endl;
            }
        } // art
    } // android
} // com
