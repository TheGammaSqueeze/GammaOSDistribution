#define LOG_TAG "com.android.apex"
#include "com_android_apex.h"

namespace com {
    namespace android {
        namespace apex {
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

            std::optional<ApexInfoList> readApexInfoList(const char* configFile) {
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

                if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("apex-info-list"))) {
                    ApexInfoList value = ApexInfoList::read(child);
                    return value;
                }
                return std::nullopt;
            }

            std::optional<ApexInfo> readApexInfo(const char* configFile) {
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

                if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("apex-info"))) {
                    ApexInfo value = ApexInfo::read(child);
                    return value;
                }
                return std::nullopt;
            }

            void write(std::ostream& out, ApexInfoList& apexInfoList) {
                out << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
                apexInfoList.write(out, "apex-info-list");
            }

            void write(std::ostream& out, ApexInfo& apexInfo) {
                out << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
                apexInfo.write(out, "apex-info");
            }

            static int indentIndex = 0;
            std::string printIndent() {
                std::string s = "";
                for (int index = 0; index < indentIndex; ++index) {
                    s += "    ";
                }
                return s;
            }


            ApexInfoList::ApexInfoList(std::vector<ApexInfo> apexInfo) : apexInfo_(std::move(apexInfo)) {
            }

            const std::vector<ApexInfo>& ApexInfoList::getApexInfo() const {
                return apexInfo_;
            }

            bool ApexInfoList::hasApexInfo() const {
                return !(apexInfo_.empty());
            }

            const ApexInfo* ApexInfoList::getFirstApexInfo() const {
                if (apexInfo_.empty()) {
                    return nullptr;
                }
                return &apexInfo_[0];
            }

            ApexInfoList ApexInfoList::read(xmlNode *root) {
                std::string raw;
                std::vector<ApexInfo> apexInfo;
                for (xmlNode *child = root->xmlChildrenNode; child != nullptr; child = child->next) {
                    if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>("apex-info"))) {
                        ApexInfo value = ApexInfo::read(child);
                        apexInfo.push_back(std::move(value));
                    }
                }
                ApexInfoList instance(apexInfo);
                return instance;
            }

            void ApexInfoList::write(std::ostream& out, const std::string& name) const {
                out << printIndent() << "<" << name;
                out << ">" << std::endl;
                ++indentIndex;
                for (auto& value : getApexInfo()) {
                    value.write(out, "apex-info");
                }
                --indentIndex;
                out << printIndent() << "</" << name << ">" << std::endl;
            }

            ApexInfo::ApexInfo(std::string moduleName, std::string modulePath, std::optional<std::string> preinstalledModulePath, int64_t versionCode, std::string versionName, bool isFactory, bool isActive, std::optional<int64_t> lastUpdateMillis) : moduleName_(std::move(moduleName)), modulePath_(std::move(modulePath)), preinstalledModulePath_(std::move(preinstalledModulePath)), versionCode_(versionCode), versionName_(std::move(versionName)), isFactory_(isFactory), isActive_(isActive), lastUpdateMillis_(lastUpdateMillis) {
            }

            const std::string& ApexInfo::getModuleName() const {
                return moduleName_;
            }

            bool ApexInfo::hasModuleName() const {
                return true;
            }

            const std::string& ApexInfo::getModulePath() const {
                return modulePath_;
            }

            bool ApexInfo::hasModulePath() const {
                return true;
            }

            const std::string& ApexInfo::getPreinstalledModulePath() const {
                return preinstalledModulePath_.value();
            }

            bool ApexInfo::hasPreinstalledModulePath() const {
                return preinstalledModulePath_.has_value();
            }

            const int64_t& ApexInfo::getVersionCode() const {
                return versionCode_;
            }

            bool ApexInfo::hasVersionCode() const {
                return true;
            }

            const std::string& ApexInfo::getVersionName() const {
                return versionName_;
            }

            bool ApexInfo::hasVersionName() const {
                return true;
            }

            const bool& ApexInfo::getIsFactory() const {
                return isFactory_;
            }

            bool ApexInfo::hasIsFactory() const {
                return true;
            }

            const bool& ApexInfo::getIsActive() const {
                return isActive_;
            }

            bool ApexInfo::hasIsActive() const {
                return true;
            }

            const int64_t& ApexInfo::getLastUpdateMillis() const {
                return lastUpdateMillis_.value();
            }

            bool ApexInfo::hasLastUpdateMillis() const {
                return lastUpdateMillis_.has_value();
            }

            ApexInfo ApexInfo::read(xmlNode *root) {
                std::string raw;
                raw = getXmlAttribute(root, "moduleName");
                std::string moduleName{};
                if (raw != "") {
                    std::string &value = raw;
                    moduleName = value;
                }
                raw = getXmlAttribute(root, "modulePath");
                std::string modulePath{};
                if (raw != "") {
                    std::string &value = raw;
                    modulePath = value;
                }
                raw = getXmlAttribute(root, "preinstalledModulePath");
                std::optional<std::string> preinstalledModulePath = std::nullopt;
                if (raw != "") {
                    std::string &value = raw;
                    preinstalledModulePath = value;
                }
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
                raw = getXmlAttribute(root, "isFactory");
                bool isFactory{};
                if (raw != "") {
                    bool value = raw == "true";
                    isFactory = value;
                }
                raw = getXmlAttribute(root, "isActive");
                bool isActive{};
                if (raw != "") {
                    bool value = raw == "true";
                    isActive = value;
                }
                raw = getXmlAttribute(root, "lastUpdateMillis");
                std::optional<int64_t> lastUpdateMillis = std::nullopt;
                if (raw != "") {
                    int64_t value = std::stoll(raw);
                    lastUpdateMillis = value;
                }
                ApexInfo instance(moduleName, modulePath, preinstalledModulePath, versionCode, versionName, isFactory, isActive, lastUpdateMillis);
                return instance;
            }

            void ApexInfo::write(std::ostream& out, const std::string& name) const {
                out << printIndent() << "<" << name;
                if (hasModuleName()) {
                    out << " moduleName=\"";
                    out << getModuleName();
                    out << "\"";
                }
                if (hasModulePath()) {
                    out << " modulePath=\"";
                    out << getModulePath();
                    out << "\"";
                }
                if (hasPreinstalledModulePath()) {
                    out << " preinstalledModulePath=\"";
                    out << getPreinstalledModulePath();
                    out << "\"";
                }
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
                if (hasIsFactory()) {
                    out << " isFactory=\"";
                    out << (getIsFactory() ? "true" : "false");
                    out << "\"";
                }
                if (hasIsActive()) {
                    out << " isActive=\"";
                    out << (getIsActive() ? "true" : "false");
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
        } // apex
    } // android
} // com
