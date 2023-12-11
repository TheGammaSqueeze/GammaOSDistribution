/******************************************************************************
 *  Copyright (c) 2016, The Linux Foundation. All rights reserved.
 *  Not a Contribution.
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
 *  Copyright (C) 2015-2019 NXP Semiconductors
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

 /**
  * @file phNxpConfig.cpp
  * @date 24 Aug 2016
  * @brief File containing code for dynamic selection of config files based on target.
  *
  * The target device has to be configured with some primary setting while booting.So a
  * config file will be picked while the target is booted. Here based on the target device
  * a configuration file will be selected dynamically and the device will be configured.
  */

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
        "/system/vendor/libnfc-nxp_RF.conf";

/**
 *  @brief target platform ID values.
 */

typedef enum
{
  CONFIG_GENERIC                         = 0x00,
  MTP_TYPE_DEFAULT                       = 0x01, /**< default MTP config. DC DC ON */
  QRD_TYPE_DEFAULT                       = 0x02, /**< default QRD config DC DC OFF */
  MTP_TYPE_1                             = 0x03, /**< mtp config type1 : newer chip */
  MTP_TYPE_2                             = 0x04, /**< mtp config type2 TBD */
  QRD_TYPE_1                             = 0x05, /**< qrd config type1 DC DC ON*/
  QRD_TYPE_2                             = 0x06, /**< qrd config type2  Newer chip */
  MTP_TYPE_NQ3XX                         = 0x07, /**< mtp config : for NQ3XX chip */
  QRD_TYPE_NQ3XX                         = 0x08, /**< qrd config : for NQ3XX chip */
  MTP_TYPE_NQ4XX                         = 0x09, /**< mtp config : for NQ4XX chip */
  QRD_TYPE_NQ4XX                         = 0x10, /**< qrd config : for NQ4XX chip */
  DEFAULT_CONFIG                         = QRD_TYPE_DEFAULT, /**< default is qrd default config */
  CONFIG_INVALID                         = 0xFF
} CONFIGIDVALUE;

/**
 *  @brief Defines the soc_id values for different targets.
 */

typedef enum
{
  TARGET_GENERIC                       = 0x00,/**< new targets */
  TARGET_MSM8952                       = 264, /**< 8952 target */
  TARGET_MSM8976                       = 278, /**< 8976 target */
  TARGET_MSM8937                       = 294, /**< 8937 target */
  TARGET_MSM8953                       = 293, /**< 8953 target */
  TARGET_MSM8996                       = 246, /**< 8996 target*/
  TARGET_MSM8909                       = 245, /**< 8909w target */
  TARGET_MSM8998                       = 292, /**< 8998 target */
  TARGET_MSM8997                       = 306, /**< 8997 target */
  TARGET_MSM8917                       = 303, /**< 8917 target */
  TARGET_MSM8940                       = 313, /**< 8940 target */
  TARGET_SDM660                        = 317, /**< SDM660 target */
  TARGET_SDM670                        = 336, /**< SDM670 target */
  TARGET_SDM710                        = 360, /**< SDM710 target */
  TARGET_SDM712                        = 393, /**< SDM712 target */
  TARGET_QCS605                        = 347, /**< QCS605 target */
  TARGET_SDM630                        = 318, /**< SDM630 target */
  TARGET_SDM632                        = 349, /**< SDM632 target */
  TARGET_SDM439                        = 353, /**< SDM439 target */
  TARGET_SDM429                        = 354, /**< SDM429 target */
  TARGET_SDM450                        = 338, /**< SDM450 target */
  TARGET_SDM455                        = 385, /**< SDM455 target */
  TARGET_SDM845                        = 321, /**< SDM845 target */
  TARGET_DEFAULT                       = TARGET_GENERIC, /**< new targets */
  TARGET_INVALID                       = 0xFF
} TARGETTYPE;

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

bool findConfigFilePathFromTransportConfigPaths(const string& configName, string& filePath);

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
  int     file_exist (const char* filename);
  int     getconfiguration_id (char * config_file);
  void moveFromList();
  void moveToList();
  void add(const CNfcParam* pParam);
  void dump();
  bool isAllowed(const char* name);
  list<const CNfcParam*> m_list;
  bool mValidFile;
  bool    mDynamConfig;
  uint32_t config_crc32_;
  uint32_t config_crc32_rf_;
  uint32_t config_crc32_tr_;

  string mCurrentFile;

  unsigned long state;

  inline bool Is(unsigned long f) { return (state & f) == f; }
  inline void Set(unsigned long f) { state |= f; }
  inline void Reset(unsigned long f) { state &= ~f; }
};

/**
 * @brief This function reads the hardware information from the given path.
 *
 * This function receives the path and then reads the hardware information
 * from the file present in the given path. It reads the details like whether
 * it is QRD or MTP. It reads the data from that file and stores in buffer.
 * It also receives a count which tells the number of characters to be read
 * Finally the length of the buffer is returned.
 *
 * @param path The path where the file containing hardware details to be read.
 * @param buff The hardware details that is read from that path will be stored here.
 * @param count It represents the number of characters to be read from that file.
 * @return It returns the length of the buffer.
 */

static int read_line_from_file(const char *path, char *buf, size_t count)
{
    char *fgets_ret = NULL;
    FILE *fd = NULL;
    int rv = 0;

    // opens the file to read the HW_PLATFORM detail of the target
    fd = fopen(path, "r");
    if (fd == NULL)
        return -1;

    // stores the data that is read from the given path into buf
    fgets_ret = fgets(buf, (int)count, fd);
    if (NULL != fgets_ret)
        rv = (int)strlen(buf);
    else
        rv = ferror(fd);

    fclose(fd);

    return rv;
}

/**
 * @brief This function gets the source information from the file.
 *
 * This function receives a buffer variable to store the read information
 * and also receives two different path. The hardware information may be
 * present in any one of the received path. So this function checks in
 * both the paths. This function internally uses read_line_from_file
 * function to read the check and read the hardware details in each path.
 *
 * @param buf hardware details that is read will be stored.
 * @param soc_node_path1 The first path where the file may be present.
 * @param soc_node_path2 The second path where the file may be present.
 * @return Returns the length of buffer.
 */

static int get_soc_info(char *buf, const char *soc_node_path1,
            const char *soc_node_path2)
{
    int ret = 0;

    // checks whether the hw platform detail is present in this path
    ret = read_line_from_file(soc_node_path1, buf, MAX_SOC_INFO_NAME_LEN);
    if (ret < 0) {
        // if the hw platform detail is not present in the former path it checks here
        ret = read_line_from_file(soc_node_path2, buf, MAX_SOC_INFO_NAME_LEN);
        if (ret < 0) {
            ALOGE("getting socinfo(%s, %d) failed.\n", soc_node_path1, ret);
            return ret;
        }
    }
    if (ret && buf[ret - 1] == '\n')
        buf[ret - 1] = '\0';

    return ret;
}

/**
 * @brief finds the cofiguration id value for the particular target.
 *
 * This function reads the target board platform detail and hardware
 * platform detail from the target device and generate a generic
 * config file name.If that config file is present then it will be
 * used for configuring that target. If not then based on the target
 * information a config file will be assigned.
 *
 * @param config_file The generic config file name will be stored.
 * @return it returns the config id for the target.
 */

int CNfcConfig::getconfiguration_id (char * config_file)
{
    int config_id = QRD_TYPE_DEFAULT;
    char target_type[MAX_SOC_INFO_NAME_LEN] = {'\0'};
    char soc_info[MAX_SOC_INFO_NAME_LEN] = {'\0'};
    char nq_chipid[PROPERTY_VALUE_MAX] = {0};
    char nq_fw_ver[PROPERTY_VALUE_MAX] = {0};
    string strPath;
    int rc = 0;
    int idx = 0;

    rc = get_soc_info(soc_info, SYSFS_SOCID_PATH1, SYSFS_SOCID_PATH2);
    if (rc < 0) {
        ALOGE("get_soc_info(SOC_ID) fail!\n");
        return DEFAULT_CONFIG;
    }
    idx = atoi(soc_info);

    rc = get_soc_info(target_type, SYSFS_HW_PLATFORM_PATH1, SYSFS_HW_PLATFORM_PATH2);
    if (rc < 0) {
        ALOGE("get_soc_info(HW_PLATFORM) fail!\n");
        return DEFAULT_CONFIG;
    }

    rc = __system_property_get("vendor.qti.nfc.chipid", nq_chipid);
    if (rc <= 0)
        ALOGE("get vendor.qti.nfc.chipid fail, rc = %d\n", rc);
    else
        ALOGD("vendor.qti.nfc.chipid = %s\n", nq_chipid);

    rc = __system_property_get("vendor.qti.nfc.fwver", nq_fw_ver);
    if (rc <= 0)
        ALOGE("get vendor.qti.nfc.fwver fail, rc = %d\n", rc);
    else
        ALOGD("vendor.qti.nfc.fwver = %s\n", nq_fw_ver);

    // Converting the HW_PLATFORM detail that is read from target to lowercase
    for (int i=0;target_type[i];i++)
        target_type[i] = tolower(target_type[i]);

    // generating a generic config file name based on the target details
    snprintf(config_file, MAX_DATA_CONFIG_PATH_LEN, "libnfc-%s_%s.conf",
            soc_info, target_type);

    findConfigFilePathFromTransportConfigPaths(config_file, strPath);
    if (file_exist(strPath.c_str()))
        idx = 0;

    if (DEBUG)
        ALOGI("id:%d, config_file_name:%s\n", idx, config_file);

    // if target is QRD platform then config id is assigned here
    if (0 == strncmp(target_type, QRD_HW_PLATFORM, MAX_SOC_INFO_NAME_LEN)) {
        switch (idx)
        {
        case TARGET_GENERIC:
            config_id = CONFIG_GENERIC;
            break;
        case TARGET_MSM8952:
        case TARGET_MSM8909:
            config_id = QRD_TYPE_DEFAULT;
            strlcpy(config_file, config_name_qrd, MAX_DATA_CONFIG_PATH_LEN);
            break;
        case TARGET_MSM8953:
        case TARGET_MSM8937:
        case TARGET_MSM8917:
        case TARGET_MSM8940:
        case TARGET_SDM632:
        case TARGET_SDM439:
        case TARGET_SDM429:
        case TARGET_SDM450:
            if ((!strncmp(nq_chipid, NQ220, PROPERTY_VALUE_MAX)) || (!strncmp(nq_chipid, NQ210, PROPERTY_VALUE_MAX))) {
                // NQ210 or NQ220
                config_id = QRD_TYPE_DEFAULT;
                strlcpy(config_file, config_name_qrd, MAX_DATA_CONFIG_PATH_LEN);
            } else if (!strncmp(nq_fw_ver, FW_MAJOR_NUM_NQ4xx, FW_MAJOR_NUM_LENGTH)) {
                config_id = QRD_TYPE_NQ4XX;
                strlcpy(config_file, config_name_qrd_NQ4XX, MAX_DATA_CONFIG_PATH_LEN);
            } else {
                config_id = QRD_TYPE_NQ3XX;
                strlcpy(config_file, config_name_qrd_NQ3XX, MAX_DATA_CONFIG_PATH_LEN);
            }
            break;
        case TARGET_MSM8976:
        case TARGET_MSM8996:
            strlcpy(config_file, config_name_qrd1, MAX_DATA_CONFIG_PATH_LEN);
            config_id = QRD_TYPE_1;
            break;
        case TARGET_SDM845:
        case TARGET_SDM670:
        case TARGET_SDM710:
        case TARGET_SDM712:
        case TARGET_QCS605:
            if (!strncmp(nq_fw_ver, FW_MAJOR_NUM_NQ4xx, FW_MAJOR_NUM_LENGTH)) {
                config_id = QRD_TYPE_NQ4XX;
                strlcpy(config_file, config_name_qrd_NQ4XX, MAX_DATA_CONFIG_PATH_LEN);
            }
            else {
                config_id = QRD_TYPE_NQ3XX;
                strlcpy(config_file, config_name_qrd_NQ3XX, MAX_DATA_CONFIG_PATH_LEN);
            }
            break;
        case TARGET_SDM660:
        case TARGET_SDM630:
        case TARGET_SDM455:
        case TARGET_MSM8998:
        case TARGET_MSM8997:
            if ((!strncmp(nq_chipid, NQ220, PROPERTY_VALUE_MAX)) || (!strncmp(nq_chipid, NQ210, PROPERTY_VALUE_MAX))) {
                // NQ210 or NQ220
                config_id = QRD_TYPE_2;
                strlcpy(config_file, config_name_qrd2, MAX_DATA_CONFIG_PATH_LEN);
            } else {
                config_id = QRD_TYPE_NQ3XX;
                strlcpy(config_file, config_name_qrd_NQ3XX, MAX_DATA_CONFIG_PATH_LEN);
            }
            break;
        default:
            config_id = QRD_TYPE_DEFAULT;
            strlcpy(config_file, config_name_qrd, MAX_DATA_CONFIG_PATH_LEN);
            break;
        }
    }
    // if target is not QRD platform then default config id is assigned here
    else {
        switch (idx)
        {
        case TARGET_GENERIC:
            config_id = CONFIG_GENERIC;
            break;
        case TARGET_MSM8953:
        case TARGET_MSM8937:
        case TARGET_MSM8917:
        case TARGET_MSM8940:
        case TARGET_SDM632:
        case TARGET_SDM439:
        case TARGET_SDM429:
        case TARGET_SDM450:
            if ((!strncmp(nq_chipid, NQ220, PROPERTY_VALUE_MAX)) || (!strncmp(nq_chipid, NQ210, PROPERTY_VALUE_MAX))) {
                // NQ210 or NQ220
                config_id = MTP_TYPE_DEFAULT;
                strlcpy(config_file, config_name_mtp, MAX_DATA_CONFIG_PATH_LEN);
            } else if (!strncmp(nq_fw_ver, FW_MAJOR_NUM_NQ4xx, FW_MAJOR_NUM_LENGTH)) {
                config_id = MTP_TYPE_NQ4XX;
                strlcpy(config_file, config_name_mtp_NQ4XX, MAX_DATA_CONFIG_PATH_LEN);
            } else {
                config_id = MTP_TYPE_NQ3XX;
                strlcpy(config_file, config_name_mtp_NQ3XX, MAX_DATA_CONFIG_PATH_LEN);
            }
            break;
        case TARGET_SDM845:
        case TARGET_SDM670:
        case TARGET_SDM710:
        case TARGET_SDM712:
        case TARGET_QCS605:
            if (!strncmp(nq_fw_ver, FW_MAJOR_NUM_NQ4xx, FW_MAJOR_NUM_LENGTH)) {
                config_id = MTP_TYPE_NQ4XX;
                strlcpy(config_file, config_name_mtp_NQ4XX, MAX_DATA_CONFIG_PATH_LEN);
            }
            else {
                config_id = MTP_TYPE_NQ3XX;
                strlcpy(config_file, config_name_mtp_NQ3XX, MAX_DATA_CONFIG_PATH_LEN);
            }
            break;
        case TARGET_SDM660:
        case TARGET_SDM630:
        case TARGET_SDM455:
        case TARGET_MSM8998:
        case TARGET_MSM8997:
            if ((!strncmp(nq_chipid, NQ220, PROPERTY_VALUE_MAX)) || (!strncmp(nq_chipid, NQ210, PROPERTY_VALUE_MAX))) {
                // NQ210 or NQ220
                config_id = MTP_TYPE_1;
                strlcpy(config_file, config_name_mtp1, MAX_DATA_CONFIG_PATH_LEN);
            } else {
                config_id = MTP_TYPE_NQ3XX;
                strlcpy(config_file, config_name_mtp_NQ3XX, MAX_DATA_CONFIG_PATH_LEN);
            }
            break;
        default:
            config_id = MTP_TYPE_DEFAULT;
            strlcpy(config_file, config_name_mtp, MAX_DATA_CONFIG_PATH_LEN);
            break;
        }
    }
    if (DEBUG)
        ALOGI("platform config id:%d, config_file_name:%s\n", config_id, config_file);

    return config_id;
}

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
CNfcConfig::CNfcConfig() : mValidFile(true), mDynamConfig(true), config_crc32_(0),
      config_crc32_rf_(0), config_crc32_tr_(0), state(0) {}

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

/**
 * @brief checks whether the given file exist.
 *
 * This function gets the file name and checks whether the given file
 * exist in the particular path.Internaly it uses stat system call to
 * find the existance.
 *
 * @param filename The name of the file whose existance has to be checked.
 * @return it returns true if the given file name exist.
 */
int CNfcConfig::file_exist (const char* filename)
{
    struct stat   buffer;
    return (stat (filename, &buffer) == 0);
}

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
  int gconfigpathid=0;
  char config_name_generic[MAX_DATA_CONFIG_PATH_LEN] = {'\0'};

    if (theInstance.size() == 0 && theInstance.mValidFile)
    {
        string strPath;
        if (alternative_config_path[0] != '\0')
        {
            strPath.assign(alternative_config_path);
            strPath += config_name;
            theInstance.readConfig(strPath.c_str(), true);
            if (!theInstance.empty())
            {
                return theInstance;
            }
        }
        findConfigFilePathFromTransportConfigPaths(config_name, strPath);
        //checks whether the default config file is present in th target
        if (theInstance.file_exist(strPath.c_str())) {
            ALOGI("default config file exists = %s, disables dynamic selection", strPath.c_str());
            theInstance.mDynamConfig = false;
            theInstance.readConfig(strPath.c_str(), true);
            /*
             * if libnfc-nxp.conf exists then dynamic selection will
             * be turned off by default we will not have this file.
             */
            return theInstance;
        }

        gconfigpathid = theInstance.getconfiguration_id(config_name_generic);
        findConfigFilePathFromTransportConfigPaths(config_name_generic, strPath);
        if (!(theInstance.file_exist(strPath.c_str()))) {
            ALOGI("no matching file found, using default file for stability\n");
            findConfigFilePathFromTransportConfigPaths(config_name_default, strPath);
        }
        ALOGI("config file used = %s\n",strPath.c_str());
        theInstance.readConfig(strPath.c_str(), true);
#if(NXP_EXTNS == TRUE)


        theInstance.readNxpTransitConfig("nxpTransit");
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
