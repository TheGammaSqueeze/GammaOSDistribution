#ifndef __RK_AUTHORIZE_H_
#define __RK_AUTHORIZE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    RKAUTH_OK = 0,
    RKAUTH_FAIL = -1,
    RKAUTH_LICENSE_INVALID = -2,
    RKAUTH_ACTIVATE_CODE_INVALID = -3,
    RKAUTH_DEVICE_ACTIVATED = -4,
    RKAUTH_LICENSE_OUTDATE = -5,
    RKAUTH_ACCESS_FILE_ERROR = -6,
    RKAUTH_GET_DEVICE_INFO_ERROR = -7,
    RKAUTH_NETWORK_ERROR = -8,
    RKAUTH_ACTIVATE_CODE_EXPIRED = -9,
    RKAUTH_LICENSE_PARSE_ERROR = -10
} rkauth_error_code;

/**
 * @brief 获取芯片型号
 * 
 * @return int 芯片型号如3399
 */
int rkauth_getsoc();

/**
 * @brief 获取芯片的efuse id
 * 
 * @param id_buf efuse id
 * @param buf_size buf大小
 * @return int 
 */
int rkauth_getsocid(char *id_buf, int buf_size);

/**
 * @brief 在线验证激活码
 * 
 * @param activate_code [in] 激活码
 * @param license_path [out] 生成的licence文件路径
 * @param is_temp_activate_code [out] 是否是临时激活码
 * @return int rkauth_error_code
 */
int rkauth_activate(const char* activate_code, const char *license_path, int *is_temp_activate_code);

/**
 * @brief 在线验证激活码,支持传入模块
 * 
 * @param module [in] 模块名称
 * @param activate_code [in] 激活码
 * @param license_path [in] 生成的licence文件路径
 * @param is_temp_activate_code [out] 是否是临时激活码
 * @return int rkauth_error_code
 */
int rkauth_activate2(const char * module, const char* activate_code, const char *license_path, int *is_temp_activate_code);

/**
 * @brief 在线验证激活码,支持传入模块和设备信息
 * 
 * @param module [in] 模块名称
 * @param activate_code [in] 激活码
 * @param fingerprint [in] 设备信息
 * @param license_path [in] 生成的licence文件路径
 * @param is_temp_activate_code [out] 是否是临时激活码
 * @return int rkauth_error_code
 */
int rkauth_activate3(const char *module, const char* activate_code, const char *fingerprint, const char *license_path, int *is_temp_activate_code);

/**
 * @brief 校验License文件（如果是正式激活码生成的licence文件可以离线校验）
 * 
 * @param tag [in] TAG，为了兼容旧的方式，激活码方式可以随意穿个字符串
 * @param key_path [in] Licence文件路径
 * @param is_temp_activate_code [out] 是否是临时激活码
 * @return int 
 */
int rkauth_verify_license(const char* tag, const char* key_path, int *is_temp_activate_code);

/**
 * @brief 校验License key字符串（如果是正式激活码生成的licence key可以离线校验）
 * 
 * @param tag [in] TAG，为了兼容旧的方式，激活码方式可以随意穿个字符串
 * @param key_content [in] Licence key字符串内容
 * @param is_temp_activate_code [out] 是否是临时激活码
 * @return int 
 */
int rkauth_verify_license_key(const char* tag, const char* key_content, int *is_temp_activate_code);

/**
 * @brief 获取硬件指纹（当前只有efuse id）
 * 
 * @return char* 硬件指纹
 */
char* rkauth_get_hw_fingerprint(void);

/**
 * @brief 获取授权库版本
 * 
 * @param version 版本号字符串
 * @param size 字符串大小
 * @return int 0：成功；-1：失败
 */
int rkauth_get_version(char *version, int size);

#ifdef __cplusplus
} //extern "C"
#endif

#endif /* __AUTHORIZE_H_ */
