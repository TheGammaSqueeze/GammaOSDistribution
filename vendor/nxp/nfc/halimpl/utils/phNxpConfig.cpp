/******************************************************************************
 *
 *  Copyright (C) 2011-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

/******************************************************************************
 *
 *  The original Work has been changed by NXP Semiconductors.
 *
 *  Copyright 2015-2020 NXP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#include <phNxpConfig.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <sys/stat.h>

#include <phNxpLog.h>
#include <android-base/properties.h>
#include "sparse_crc32.h"
#include <cutils/properties.h>

#if GENERIC_TARGET
const char alternative_config_path[] = "/data/vendor/nfc/";
#else
const char alternative_config_path[] = "";
#endif

#if 1
const char* transport_config_paths[] = {"/odm/etc/", "/vendor/etc/"};
const char transit_config_path[] = "/data/vendor/nfc/libnfc-nxpTransit.conf";
#else
const char* transport_config_paths[] = {"res/"};
#endif
const int transport_config_path_size =
    (sizeof(transport_config_paths) / sizeof(transport_config_paths[0]));
#define config_name "libnfc-nxp.conf"
#if (NXP_EXTNS == TRUE)
#define extra_config_base "libnfc-"
#else
#define extra_config_base "libnfc-nxp-"
#endif
#define extra_config_ext ".conf"
#define IsStringValue 0x80000000

const char rf_config_timestamp_path[] =
        "/data/vendor/nfc/libnfc-nxpRFConfigState.bin";
const char tr_config_timestamp_path[] =
    "/data/vendor/nfc/libnfc-nxpTransitConfigState.bin";
const char config_timestamp_path[] =
        "/data/vendor/nfc/libnfc-nxpConfigState.bin";
const char default_nxp_config_path[] =
        "/vendor/etc/libnfc-nxp.conf";
const char nxp_rf_config_path[] =
        "/vendor/etc/libnfc-nxp_RF.conf";

namespace {

size_t readConfigFile(const char* fileName, uint8_t** p_data) {
  FILE* fd = fopen(fileName, "rb");
  if (fd == nullptr) return 0;
  fseek(fd, 0L, SEEK_END);
  const size_t file_size = ftell(fd);
  rewind(fd);
  if((long)file_size < 0){
    ALOGE("%s Invalid file size file_size = %zu\n",__func__,file_size);
    fclose(fd);
    return 0;
  }
  uint8_t* buffer = new uint8_t[file_size];
  if (!buffer) {
    ALOGE("%s  memory allocation failed \n",__func__);
    return 0;
  }
  size_t read = fread(buffer, file_size, 1, fd);
  fclose(fd);
  if (read == 1) {
    *p_data = buffer;
    return file_size;
  }
  delete[] buffer;
  return 0;
}

}  // namespace

using namespace ::std;

namespace nxp {


class CNfcParam : public string {
 public:
  CNfcParam();
  CNfcParam(const char* name, const string& value);
  CNfcParam(const char* name, unsigned long value);
  virtual ~CNfcParam();
  unsigned long numValue() const { return m_numValue; }
  const char* str_value() const { return m_str_value.c_str(); }
  size_t str_len() const { return m_str_value.length(); }

 private:
  string m_str_value;
  unsigned long m_numValue;
};

class CNfcConfig : public vector<const CNfcParam*> {
 public:
  virtual ~CNfcConfig();
  static CNfcConfig& GetInstance();
  bool isModified();
  bool isModified(const char* pName);
  void resetModified();

  bool getValue(const char* name, char* pValue, size_t len) const;
  bool getValue(const char* name, unsigned long& rValue) const;
  bool getValue(const char* name, unsigned short& rValue) const;
  bool getValue(const char* name, char* pValue, long len, long* readlen) const;
  const CNfcParam* find(const char* p_name) const;
  void readNxpTransitConfig(const char* fileName) const;
  void readNxpRFConfig(const char* fileName) const;
  void clean();

 private:
  CNfcConfig();
  bool readConfig(const char* name, bool bResetContent);
  void moveFromList();
  void moveToList();
  void add(const CNfcParam* pParam);
  void dump();
  bool isAllowed(const char* name);
  list<const CNfcParam*> m_list;
  bool mValidFile;
  uint32_t config_crc32_;
  uint32_t config_crc32_rf_;
  uint32_t config_crc32_tr_;

  string mCurrentFile;

  unsigned long state;

  inline bool Is(unsigned long f) { return (state & f) == f; }
  inline void Set(unsigned long f) { state |= f; }
  inline void Reset(unsigned long f) { state &= ~f; }
};

/*******************************************************************************
**
** Function:    isPrintable()
**
** Description: determine if 'c' is printable
**
** Returns:     1, if printable, otherwise 0
**
*******************************************************************************/
inline bool isPrintable(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
         (c >= '0' && c <= '9') || c == '/' || c == '_' || c == '-' || c == '.';
}

/*******************************************************************************
**
** Function:    isDigit()
**
** Description: determine if 'c' is numeral digit
**
** Returns:     true, if numerical digit
**
*******************************************************************************/
inline bool isDigit(char c, int base) {
  if ('0' <= c && c <= '9') return true;
  if (base == 16) {
    if (('A' <= c && c <= 'F') || ('a' <= c && c <= 'f')) return true;
  }
  return false;
}

/*******************************************************************************
**
** Function:    getDigitValue()
**
** Description: return numerical value of a decimal or hex char
**
** Returns:     numerical value if decimal or hex char, otherwise 0
**
*******************************************************************************/
inline int getDigitValue(char c, int base) {
  if ('0' <= c && c <= '9') return c - '0';
  if (base == 16) {
    if ('A' <= c && c <= 'F')
      return c - 'A' + 10;
    else if ('a' <= c && c <= 'f')
      return c - 'a' + 10;
  }
  return 0;
}

/*******************************************************************************
**
** Function:    findConfigFilePathFromTransportConfigPaths()
**
** Description: find a config file path with a given config name from transport
**              config paths
**
** Returns:     none
**
*******************************************************************************/
bool findConfigFilePathFromTransportConfigPaths(const string& configName,
                                                string& filePath) {
  for (int i = 0; i < transport_config_path_size; i++) {
    if (configName.empty()) break;
    filePath.assign(transport_config_paths[i]);
    filePath += configName;
    struct stat file_stat;
    if (stat(filePath.c_str(), &file_stat) == 0 && S_ISREG(file_stat.st_mode)) {
      return true;
    }
  }
  // Config file didnt exist in any of the transport config_paths.
  filePath = "";
  return false;
}

/*******************************************************************************
**
** Function:    CNfcConfig::readConfig()
**
** Description: read Config settings and parse them into a linked list
**              move the element from linked list to a array at the end
**
** Returns:     1, if there are any config data, 0 otherwise
**
*******************************************************************************/
bool CNfcConfig::readConfig(const char* name, bool bResetContent) {
  enum {
    BEGIN_LINE = 1,
    TOKEN,
    STR_VALUE,
    NUM_VALUE,
    BEGIN_HEX,
    BEGIN_QUOTE,
    END_LINE
  };

  uint8_t* p_config = nullptr;
  size_t config_size = readConfigFile(name, &p_config);
  if (p_config == nullptr) {
    ALOGE("%s Cannot open config file %s\n", __func__, name);
    if (bResetContent) {
      ALOGE("%s Using default value for all settings\n", __func__);
      mValidFile = false;
    }
    return false;
  }

  string token;
  string strValue;
  unsigned long numValue = 0;
  CNfcParam* pParam = NULL;
  int i = 0;
  int base = 0;
  char c;
  int bflag = 0;
  state = BEGIN_LINE;
  mCurrentFile = name;

  if (strcmp(default_nxp_config_path, name) == 0) {
    config_crc32_ = sparse_crc32(0, p_config, config_size);
  }
  else if (strcmp(nxp_rf_config_path, name) == 0) {
    config_crc32_rf_ = sparse_crc32(0, p_config, config_size);
  }
  else if (strcmp(transit_config_path, name) == 0) {
    config_crc32_tr_ = sparse_crc32(0, p_config, config_size);
  }
  mValidFile = true;
  if (size() > 0) {
    if (bResetContent)
      clean();
    else
      moveToList();
  }

  for (size_t offset = 0; offset != config_size; ++offset) {
    c = p_config[offset];
    switch (state & 0xff) {
      case BEGIN_LINE:
        if (c == '#')
          state = END_LINE;
        else if (isPrintable(c)) {
          i = 0;
          token.erase();
          strValue.erase();
          state = TOKEN;
          token.push_back(c);
        }
        break;
      case TOKEN:
        if (c == '=') {
          token.push_back('\0');
          state = BEGIN_QUOTE;
        } else if (isPrintable(c))
          token.push_back(c);
        else
          state = END_LINE;
        break;
      case BEGIN_QUOTE:
        if (c == '"') {
          state = STR_VALUE;
          base = 0;
        } else if (c == '0')
          state = BEGIN_HEX;
        else if (isDigit(c, 10)) {
          state = NUM_VALUE;
          base = 10;
          numValue = getDigitValue(c, base);
          i = 0;
        } else if (c == '{') {
          state = NUM_VALUE;
          bflag = 1;
          base = 16;
          i = 0;
          Set(IsStringValue);
        } else
          state = END_LINE;
        break;
      case BEGIN_HEX:
        if (c == 'x' || c == 'X') {
          state = NUM_VALUE;
          base = 16;
          numValue = 0;
          i = 0;
          break;
        } else if (isDigit(c, 10)) {
          state = NUM_VALUE;
          base = 10;
          numValue = getDigitValue(c, base);
          break;
        } else if (c != '\n' && c != '\r') {
          state = END_LINE;
          break;
        }
      // fall through to numValue to handle numValue
        [[fallthrough]];
      case NUM_VALUE:
        if (isDigit(c, base)) {
          numValue *= base;
          numValue += getDigitValue(c, base);
          ++i;
        } else if (bflag == 1 &&
                   (c == ' ' || c == '\r' || c == '\n' || c == '\t')) {
          break;
        } else if (base == 16 &&
                   (c == ',' || c == ':' || c == '-' || c == ' ' || c == '}')) {
          if (c == '}') {
            bflag = 0;
          }
          if (i > 0) {
            int n = (i + 1) / 2;
            while (n-- > 0) {
              numValue = numValue >> (n * 8);
              unsigned char c = (numValue)&0xFF;
              strValue.push_back(c);
            }
          }

          Set(IsStringValue);
          numValue = 0;
          i = 0;
        } else {
          if (c == '\n' || c == '\r') {
            if (bflag == 0) {
              state = BEGIN_LINE;
            }
          } else {
            if (bflag == 0) {
              state = END_LINE;
            }
          }
          if (Is(IsStringValue) && base == 16 && i > 0) {
            int n = (i + 1) / 2;
            while (n-- > 0) strValue.push_back(((numValue >> (n * 8)) & 0xFF));
          }
          if (strValue.length() > 0)
            pParam = new CNfcParam(token.c_str(), strValue);
          else
            pParam = new CNfcParam(token.c_str(), numValue);
          add(pParam);
          strValue.erase();
          numValue = 0;
        }
        break;
      case STR_VALUE:
        if (c == '"') {
          strValue.push_back('\0');
          state = END_LINE;
          pParam = new CNfcParam(token.c_str(), strValue);
          add(pParam);
        } else if (isPrintable(c))
          strValue.push_back(c);
        break;
      case END_LINE:
        if (c == '\n' || c == '\r') state = BEGIN_LINE;
        break;
      default:
        break;
    }
  }

  delete[] p_config;

  moveFromList();
  return size() > 0;
}

/*******************************************************************************
**
** Function:    CNfcConfig::CNfcConfig()
**
** Description: class constructor
**
** Returns:     none
**
*******************************************************************************/
CNfcConfig::CNfcConfig()
    : mValidFile(true), config_crc32_(0), config_crc32_rf_(0),
      config_crc32_tr_(0), state(0) {}

/*******************************************************************************
**
** Function:    CNfcConfig::~CNfcConfig()
**
** Description: class destructor
**
** Returns:     none
**
*******************************************************************************/
CNfcConfig::~CNfcConfig() {}

/*******************************************************************************
**
** Function:    CNfcConfig::GetInstance()
**
** Description: get class singleton object
**
** Returns:     none
**
*******************************************************************************/
CNfcConfig& CNfcConfig::GetInstance() {
  static CNfcConfig theInstance;
  string config_file_name = "libnfc-nxp";
  if (theInstance.size() == 0 && theInstance.mValidFile) {
    string strPath;
    if (alternative_config_path[0] != '\0') {
      strPath.assign(alternative_config_path);
      strPath += config_name;
      theInstance.readConfig(strPath.c_str(), true);
      if (!theInstance.empty()) {
        return theInstance;
      }
    }

    if (findConfigFilePathFromTransportConfigPaths(
        android::base::GetProperty("persist.vendor.nfc.config_file_name", ""),
        strPath)) {
      NXPLOG_EXTNS_D("%s load %s\n", __func__,  strPath.c_str());
    } else if (findConfigFilePathFromTransportConfigPaths(
        extra_config_base +
        android::base::GetProperty("ro.boot.product.hardware.sku", "") +
        + extra_config_ext, strPath)) {
      NXPLOG_EXTNS_D("%s load %s\n", __func__,  strPath.c_str());
    } else {
      findConfigFilePathFromTransportConfigPaths(config_name, strPath);
    }

    ALOGD("nxp config file : %s", strPath.c_str());
    theInstance.readConfig(strPath.c_str(), true);
#if (NXP_EXTNS == TRUE)
    theInstance.readNxpTransitConfig(transit_config_path);
    theInstance.readNxpRFConfig(nxp_rf_config_path);
#endif
  }
  return theInstance;
}

/*******************************************************************************
**
** Function:    CNfcConfig::getValue()
**
** Description: get a string value of a setting
**
** Returns:     true if setting exists
**              false if setting does not exist
**
*******************************************************************************/
bool CNfcConfig::getValue(const char* name, char* pValue, size_t len) const {
  const CNfcParam* pParam = find(name);
  if (pParam == NULL) return false;

  if (pParam->str_len() > 0) {
    memset(pValue, 0, len);
    memcpy(pValue, pParam->str_value(), pParam->str_len());
    return true;
  }
  return false;
}

bool CNfcConfig::getValue(const char* name, char* pValue, long len,
                          long* readlen) const {
  const CNfcParam* pParam = find(name);
  if (pParam == NULL) return false;

  if (pParam->str_len() > 0) {
    if (pParam->str_len() <= (unsigned long)len) {
      memset(pValue, 0, len);
      memcpy(pValue, pParam->str_value(), pParam->str_len());
      *readlen = pParam->str_len();
    } else {
      *readlen = -1;
    }

    return true;
  }
  return false;
}

/*******************************************************************************
**
** Function:    CNfcConfig::getValue()
**
** Description: get a long numerical value of a setting
**
** Returns:     true if setting exists
**              false if setting does not exist
**
*******************************************************************************/
bool CNfcConfig::getValue(const char* name, unsigned long& rValue) const {
  const CNfcParam* pParam = find(name);
  if (pParam == NULL) return false;

  if (pParam->str_len() == 0) {
    rValue = static_cast<unsigned long>(pParam->numValue());
    return true;
  }
  return false;
}

/*******************************************************************************
**
** Function:    CNfcConfig::getValue()
**
** Description: get a short numerical value of a setting
**
** Returns:     true if setting exists
**              false if setting does not exist
**
*******************************************************************************/
bool CNfcConfig::getValue(const char* name, unsigned short& rValue) const {
  const CNfcParam* pParam = find(name);
  if (pParam == NULL) return false;

  if (pParam->str_len() == 0) {
    rValue = static_cast<unsigned short>(pParam->numValue());
    return true;
  }
  return false;
}

/*******************************************************************************
**
** Function:    CNfcConfig::find()
**
** Description: search if a setting exist in the setting array
**
** Returns:     pointer to the setting object
**
*******************************************************************************/
const CNfcParam* CNfcConfig::find(const char* p_name) const {
  if (size() == 0) return NULL;

  for (const_iterator it = begin(), itEnd = end(); it != itEnd; ++it) {
    if (**it < p_name) {
      continue;
    } else if (**it == p_name) {
      if ((*it)->str_len() > 0) {
        NXPLOG_EXTNS_D("%s found %s=%s\n", __func__, p_name,
                       (*it)->str_value());
      } else {
        NXPLOG_EXTNS_D("%s found %s=(0x%lx)\n", __func__, p_name,
                       (*it)->numValue());
      }
      return *it;
    } else
      break;
  }
  return NULL;
}

/*******************************************************************************
**
** Function:    CNfcConfig::readNxpTransitConfig()
**
** Description: read Config settings from transit conf file
**
** Returns:     none
**
*******************************************************************************/
void CNfcConfig::readNxpTransitConfig(const char* fileName) const {
  ALOGD("readNxpTransitConfig-Enter..Reading %s", fileName);
  CNfcConfig::GetInstance().readConfig(fileName, false);
}

/*******************************************************************************
**
** Function:    CNfcConfig::readNxpRFConfig()
**
** Description: read Config settings from RF conf file
**
** Returns:     none
**
*******************************************************************************/
void CNfcConfig::readNxpRFConfig(const char* fileName) const {
  ALOGD("readNxpRFConfig-Enter..Reading %s", fileName);
  CNfcConfig::GetInstance().readConfig(fileName, false);
}

/*******************************************************************************
**
** Function:    CNfcConfig::clean()
**
** Description: reset the setting array
**
** Returns:     none
**
*******************************************************************************/
void CNfcConfig::clean() {
  if (size() == 0) return;

  for (iterator it = begin(), itEnd = end(); it != itEnd; ++it) delete *it;
  clear();
}

/*******************************************************************************
**
** Function:    CNfcConfig::Add()
**
** Description: add a setting object to the list
**
** Returns:     none
**
*******************************************************************************/
void CNfcConfig::add(const CNfcParam* pParam) {
  if (m_list.size() == 0) {
    m_list.push_back(pParam);
    return;
  }
  if ((mCurrentFile.find("nxpTransit") != std::string::npos) &&
      !isAllowed(pParam->c_str())) {
    ALOGD("%s Token restricted. Returning", __func__);
    return;
  }
  for (list<const CNfcParam*>::iterator it = m_list.begin(),
                                        itEnd = m_list.end();
       it != itEnd; ++it) {
    if (**it < pParam->c_str()) continue;
    if (**it == pParam->c_str())
      m_list.insert(m_list.erase(it), pParam);
    else
      m_list.insert(it, pParam);

    return;
  }
  m_list.push_back(pParam);
}
/*******************************************************************************
**
** Function:    CNfcConfig::dump()
**
** Description: prints all elements in the list
**
** Returns:     none
**
*******************************************************************************/
void CNfcConfig::dump() {
  ALOGD("%s Enter", __func__);

  for (list<const CNfcParam*>::iterator it = m_list.begin(),
                                        itEnd = m_list.end();
       it != itEnd; ++it) {
    if ((*it)->str_len() > 0)
      ALOGD("%s %s \t= %s", __func__, (*it)->c_str(), (*it)->str_value());
    else
      ALOGD("%s %s \t= (0x%0lX)\n", __func__, (*it)->c_str(),
            (*it)->numValue());
  }
}
/*******************************************************************************
**
** Function:    CNfcConfig::isAllowed()
**
** Description: checks if token update is allowed
**
** Returns:     true if allowed else false
**
*******************************************************************************/
bool CNfcConfig::isAllowed(const char* name) {
  string token(name);
  bool stat = false;
  if ((token.find("P2P_LISTEN_TECH_MASK") != std::string::npos) ||
      (token.find("HOST_LISTEN_TECH_MASK") != std::string::npos) ||
      (token.find("UICC_LISTEN_TECH_MASK") != std::string::npos) ||
      (token.find("NXP_ESE_LISTEN_TECH_MASK") != std::string::npos) ||
      (token.find("POLLING_TECH_MASK") != std::string::npos) ||
      (token.find("NXP_RF_CONF_BLK") != std::string::npos) ||
      (token.find("NXP_CN_TRANSIT_BLK_NUM_CHECK_ENABLE") !=
       std::string::npos) ||
      (token.find("NXP_FWD_FUNCTIONALITY_ENABLE") != std::string::npos))

  {
    stat = true;
  }
  return stat;
}
/*******************************************************************************
**
** Function:    CNfcConfig::moveFromList()
**
** Description: move the setting object from list to array
**
** Returns:     none
**
*******************************************************************************/
void CNfcConfig::moveFromList() {
  if (m_list.size() == 0) return;

  for (list<const CNfcParam*>::iterator it = m_list.begin(),
                                        itEnd = m_list.end();
       it != itEnd; ++it)
    push_back(*it);
  m_list.clear();
}

/*******************************************************************************
**
** Function:    CNfcConfig::moveToList()
**
** Description: move the setting object from array to list
**
** Returns:     none
**
*******************************************************************************/
void CNfcConfig::moveToList() {
  if (m_list.size() != 0) m_list.clear();

  for (iterator it = begin(), itEnd = end(); it != itEnd; ++it)
    m_list.push_back(*it);
  clear();
}

bool CNfcConfig::isModified() {
  FILE* fd = fopen(config_timestamp_path, "r+");
  if (fd == nullptr) {
    ALOGE("%s Unable to open file '%s' - assuming modified", __func__,
          config_timestamp_path);
    return true;
  }

  uint32_t stored_crc32 = 0;
  if (fread(&stored_crc32, sizeof(uint32_t), 1, fd) != 1)
    ALOGE("%s Failed to Read file", __func__);

  fclose(fd);

  return stored_crc32 != config_crc32_;
}

bool CNfcConfig::isModified(const char* pName) {
  FILE* fd = nullptr;
  bool isRfFile = false;
  if (strcmp(nxp_rf_config_path, pName) == 0) {
    isRfFile = true;
    fd = fopen(rf_config_timestamp_path, "r+");
  }
  else if (strcmp(transit_config_path, pName) == 0) {
    fd = fopen(tr_config_timestamp_path, "r+");
  }
  if (fd == nullptr) {
    return true;
  }

  uint32_t stored_crc32 = 0;
  if (fread(&stored_crc32, sizeof(uint32_t), 1, fd) != 1)
    ALOGE("%s Failed to Read file", __func__);

  fclose(fd);

  if(isRfFile)
    return stored_crc32 != config_crc32_rf_;
  else
    return stored_crc32 != config_crc32_tr_;
}

void CNfcConfig::resetModified() {
  FILE* fd = nullptr;

  fd = fopen(config_timestamp_path, "w+");
  if (fd == nullptr) {
    ALOGE("%s Unable to open file '%s' for writing", __func__,
          config_timestamp_path);
  }
  else
  {
    fwrite(&config_crc32_, sizeof(uint32_t), 1, fd);
    fclose(fd);
  }
  fd = fopen(rf_config_timestamp_path, "w+");
  if (fd == nullptr) {
    ALOGE("%s Unable to open file '%s' for writing", __func__,
        rf_config_timestamp_path);
  }
  else
  {
    fwrite(&config_crc32_rf_, sizeof(uint32_t), 1, fd);
    fclose(fd);
  }

  fd = fopen(tr_config_timestamp_path, "w+");
  if (fd == nullptr) {
    ALOGE("%s Unable to open file '%s' for writing", __func__,
        tr_config_timestamp_path);
  }
  else
  {
    fwrite(&config_crc32_tr_, sizeof(uint32_t), 1, fd);
    fclose(fd);
  }
}

/*******************************************************************************
**
** Function:    CNfcParam::CNfcParam()
**
** Description: class constructor
**
** Returns:     none
**
*******************************************************************************/
CNfcParam::CNfcParam() : m_numValue(0) {}

/*******************************************************************************
**
** Function:    CNfcParam::~CNfcParam()
**
** Description: class destructor
**
** Returns:     none
**
*******************************************************************************/
CNfcParam::~CNfcParam() {}

/*******************************************************************************
**
** Function:    CNfcParam::CNfcParam()
**
** Description: class copy constructor
**
** Returns:     none
**
*******************************************************************************/
CNfcParam::CNfcParam(const char* name, const string& value)
    : string(name), m_str_value(value), m_numValue(0) {}

/*******************************************************************************
**
** Function:    CNfcParam::CNfcParam()
**
** Description: class copy constructor
**
** Returns:     none
**
*******************************************************************************/
CNfcParam::CNfcParam(const char* name, unsigned long value)
    : string(name), m_numValue(value) {}


}  // namespace nxp
/*******************************************************************************
**
** Function:    GetStrValue
**
** Description: API function for getting a string value of a setting
**
** Returns:     True if found, otherwise False.
**
*******************************************************************************/
extern int GetNxpStrValue(const char* name, char* pValue, unsigned long len) {
  nxp::CNfcConfig& rConfig = nxp::CNfcConfig::GetInstance();

  return rConfig.getValue(name, pValue, len);
}

/*******************************************************************************
**
** Function:    GetNxpValueAsString
**
** Description: This API will return string format of value if value is either
**              given as string or long in config file.
**
** Returns:     True if found, otherwise False.
**
*******************************************************************************/
extern bool GetNxpValueAsString(const char* name, char* pValue,
                                unsigned long len) {
  const nxp::CNfcParam* pParam = nxp::CNfcConfig::GetInstance().find(name);
  if (pParam == NULL) return false;
  memset(pValue, 0, len);
  if (pParam->str_len() > 0)
    memcpy(pValue, pParam->str_value(), pParam->str_len());
  else
    memcpy(pValue, to_string(pParam->numValue()).c_str(),
           sizeof(pParam->numValue()));
  return true;
}
/*******************************************************************************
**
** Function:    GetByteArrayValue()
**
** Description: Read byte array value from the config file.
**
** Parameters:
**              name - name of the config param to read.
**              pValue  - pointer to input buffer.
**              bufflen - input buffer length.
**              len - out parameter to return the number of bytes read from
**                    config file, return -1 in case bufflen is not enough.
**
** Returns:     true[1] if config param name is found in the config file, else
**              false[0]
**
*******************************************************************************/
extern int GetNxpByteArrayValue(const char* name, char* pValue, long bufflen,
                                long* len) {
  nxp::CNfcConfig& rConfig = nxp::CNfcConfig::GetInstance();

  return rConfig.getValue(name, pValue, bufflen, len);
}

/*******************************************************************************
**
** Function:    GetNumValue
**
** Description: API function for getting a numerical value of a setting
**
** Returns:     true, if successful
**
*******************************************************************************/
extern int GetNxpNumValue(const char* name, void* pValue,
                              unsigned long len) {
  if (!pValue) return false;

  nxp::CNfcConfig& rConfig = nxp::CNfcConfig::GetInstance();
  const nxp::CNfcParam* pParam = rConfig.find(name);

  if (pParam == NULL) return false;
  unsigned long v = pParam->numValue();
  if (v == 0 && pParam->str_len() > 0 && pParam->str_len() < 4) {
    const unsigned char* p = (const unsigned char*)pParam->str_value();
    for (unsigned int i = 0; i < pParam->str_len(); ++i) {
      v *= 256;
      v += *p++;
    }
  }
  switch (len) {
    case sizeof(unsigned long):
      *(static_cast<unsigned long*>(pValue)) = (unsigned long)v;
      break;
    case sizeof(unsigned short):
      *(static_cast<unsigned short*>(pValue)) = (unsigned short)v;
      break;
    case sizeof(unsigned char):
      *(static_cast<unsigned char*>(pValue)) = (unsigned char)v;
      break;
    default:
      return false;
  }
  return true;
}

/*******************************************************************************
**
** Function:    resetConfig
**
** Description: reset settings array
**
** Returns:     none
**
*******************************************************************************/
extern void resetNxpConfig()

{
  nxp::CNfcConfig& rConfig = nxp::CNfcConfig::GetInstance();

  rConfig.clean();
}

/*******************************************************************************
**
** Function:    isNxpConfigModified()
**
** Description: check if config file has modified
**
** Returns:     0 if not modified, 1 otherwise.
**
*******************************************************************************/
extern int isNxpConfigModified() {
  nxp::CNfcConfig& rConfig = nxp::CNfcConfig::GetInstance();
  return rConfig.isModified();
}
/*******************************************************************************
**
** Function:    isNxpRFConfigModified()
**
** Description: check if config file has modified
**
** Returns:     0 if not modified, 1 otherwise.
**
*******************************************************************************/
extern int isNxpRFConfigModified() {
  int retRF = 0, rettransit = 0, ret = 0;
  nxp::CNfcConfig& rConfig = nxp::CNfcConfig::GetInstance();
  retRF = rConfig.isModified(nxp_rf_config_path);
  rettransit = rConfig.isModified(transit_config_path);
  ret = retRF | rettransit;
  ALOGD("ret RF or Transit value %d", ret);
  return ret;
}

/*******************************************************************************
**
** Function:    updateNxpConfigTimestamp()
**
** Description: update if config file has modified
**
** Returns:     0 if not modified, 1 otherwise.
**
*******************************************************************************/
extern int updateNxpConfigTimestamp() {
  nxp::CNfcConfig& rConfig = nxp::CNfcConfig::GetInstance();
  rConfig.resetModified();
  return 0;
}
