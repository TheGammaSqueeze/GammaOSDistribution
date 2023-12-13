ifneq (,$(filter arm aarch64 arm64, $(TARGET_ARCH)))

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

ifeq ($(PRODUCT_VENDOR_MOVE_ENABLED),true)
LOCAL_VENDOR_MODULE := true
endif

LOCAL_MODULE := wcnss_service
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/common/inc/
LOCAL_SRC_FILES := wcnss_service.c
LOCAL_SHARED_LIBRARIES := libc libcutils libutils liblog

ifeq ($(strip $(TARGET_USES_QCOM_WCNSS_QMI)),true)

ifeq ($(TARGET_PROVIDES_WCNSS_QMI),true)
LOCAL_CFLAGS += -DWCNSS_QMI_OSS
LOCAL_SHARED_LIBRARIES += libdl
else
ifeq ($(TARGET_USES_WCNSS_MAC_ADDR_REV),true)
LOCAL_CFLAGS += -DWCNSS_QMI_MAC_ADDR_REV
endif
ifneq ($(QCPATH),)
LOCAL_CFLAGS += -DWCNSS_QMI -DMDM_DETECT
LOCAL_SHARED_LIBRARIES += libwcnss_qmi
else
LOCAL_CFLAGS += -DWCNSS_QMI_OSS
LOCAL_SHARED_LIBRARIES += libdl
endif #QCPATH
endif #TARGET_PROVIDES_WCNSS_QMI

endif #TARGET_USES_QCOM_WCNSS_QMI

LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS += -Wall

include $(BUILD_EXECUTABLE)

ifneq ($(TARGET_PROVIDES_WCNSS_QMI),true)
ifeq ($(strip $(TARGET_USES_QCOM_WCNSS_QMI)),true)
ifneq ($(QCPATH),)
include $(CLEAR_VARS)

ifeq ($(PRODUCT_VENDOR_MOVE_ENABLED),true)
LOCAL_VENDOR_MODULE := true
endif

LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qmi-framework/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qmi/services
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qmi/platform
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qmi/inc
LOCAL_SHARED_LIBRARIES := libc libcutils libutils liblog
LOCAL_SHARED_LIBRARIES += libqmiservices libqmi_cci
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/libmdmdetect/inc
LOCAL_SHARED_LIBRARIES += libmdmdetect
LOCAL_HEADER_LIBRARIES += libril-qc-qmi-services-headers
LOCAL_CFLAGS += -DWCNSS_QMI
LOCAL_SRC_FILES += wcnss_qmi_client.c

LOCAL_MODULE := libwcnss_qmi
LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS += -Wall

include $(BUILD_SHARED_LIBRARY)

endif #QCPATH
endif #TARGET_USES_QCOM_WCNSS_QMI
endif #TARGET_PROVIDES_WCNSS_QMI

endif #TARGET_ARCH == arm
