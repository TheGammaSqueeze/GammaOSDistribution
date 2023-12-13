#ANT
ifeq ($(TARGET_FWK_SUPPORTS_FULL_VALUEADDS), true)
ifeq ($(BOARD_ANT_WIRELESS_DEVICE), "vfs-prerelease")
PRODUCT_PACKAGES += AntHalService
PRODUCT_PACKAGES += libantradio
PRODUCT_PACKAGES += antradio_app
else
PRODUCT_PACKAGES += AntHalService-Soong
PRODUCT_PACKAGES += com.dsi.ant@1.0
endif
endif #TARGET_FWK_SUPPORTS_FULL_VALUEADDS

#BT
ifeq ($(BOARD_HAVE_BLUETOOTH_QCOM),true)
PRODUCT_PACKAGES += Bluetooth

ifeq ($(TARGET_FWK_SUPPORTS_FULL_VALUEADDS), true)
ifneq ($(TARGET_BOARD_TYPE),auto)
TARGET_USE_QTI_BT_STACK := true
endif

ifeq ($(TARGET_USE_QTI_BT_STACK),true)
# BT Related Libs
PRODUCT_PACKAGES += libbluetooth_qti
PRODUCT_PACKAGES += libbluetooth_qti_jni
PRODUCT_PACKAGES += bt_logger
PRODUCT_PACKAGES += libbt-logClient
PRODUCT_PACKAGES += libbtconfigstore
PRODUCT_PACKAGES += vendor.qti.hardware.btconfigstore@1.0
PRODUCT_PACKAGES += vendor.qti.hardware.btconfigstore@2.0
PRODUCT_PACKAGES += com.qualcomm.qti.bluetooth_audio@1.0
PRODUCT_PACKAGES += vendor.qti.hardware.bluetooth_audio@2.0

ifeq ($(TARGET_USE_BT_DUN),true)
PRODUCT_PACKAGES += vendor.qti.hardware.bluetooth_dun-V1.0-java
PRODUCT_PACKAGES += BluetoothExt
endif #TARGET_USE_BT_DUN

PRODUCT_SOONG_NAMESPACES += vendor/qcom/opensource/commonsys/packages/apps/Bluetooth
PRODUCT_SOONG_NAMESPACES += vendor/qcom/opensource/commonsys/system/bt/conf
PRODUCT_SOONG_NAMESPACES += vendor/qcom/opensource/commonsys/system/bt/main

PRODUCT_PACKAGE_OVERLAYS += vendor/qcom/opensource/commonsys-intf/bluetooth/overlay/qva
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := vendor/qcom/opensource/commonsys-intf/bluetooth/build/qva/config

# BT Related Test app & Tools
PRODUCT_PACKAGES_ENG += btsnoop
PRODUCT_PACKAGES_ENG += gatt_tool_qti_internal
PRODUCT_PACKAGES_ENG += l2cap_coc_tool
PRODUCT_PACKAGES_ENG += l2test_ertm
PRODUCT_PACKAGES_ENG += rfc

ifneq ($(TARGET_HAS_LOW_RAM), true)
PRODUCT_PACKAGES_ENG += BTTestApp
PRODUCT_PACKAGES_ENG += BATestApp
endif #TARGET_HAS_LOW_RAM

else
PRODUCT_SOONG_NAMESPACES += packages/apps/Bluetooth
PRODUCT_PACKAGE_OVERLAYS += vendor/qcom/opensource/commonsys-intf/bluetooth/overlay/generic
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := vendor/qcom/opensource/commonsys-intf/bluetooth/build/generic/config
endif #TARGET_USE_QTI_BT_STACK

else
PRODUCT_PACKAGE_OVERLAYS += vendor/qcom/opensource/commonsys-intf/bluetooth/overlay/generic
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := vendor/qcom/opensource/commonsys-intf/bluetooth/build/generic/config
endif #TARGET_FWK_SUPPORTS_FULL_VALUEADDS

endif #BOARD_HAVE_BLUETOOTH_QCOM

#FM
ifeq ($(BOARD_HAVE_QCOM_FM), true)
ifeq ($(TARGET_FWK_SUPPORTS_FULL_VALUEADDS), true)
PRODUCT_PACKAGES += libqcomfm_jni
PRODUCT_PACKAGES += libfmjni
PRODUCT_PACKAGES += fm_helium
PRODUCT_PACKAGES += libfm-hci
PRODUCT_PACKAGES += FM2
PRODUCT_PACKAGES += qcom.fmradio
PRODUCT_BOOT_JARS += qcom.fmradio
PRODUCT_PACKAGES += vendor.qti.hardware.fm@1.0
# system prop for fm
PRODUCT_PROPERTY_OVERRIDES += vendor.hw.fm.init=0
endif #TARGET_FWK_SUPPORTS_FULL_VALUEADDS
endif #BOARD_HAVE_QCOM_FM

#WIPOWER
ifeq ($(BOARD_USES_WIPOWER),true)
ifeq ($(TARGET_FWK_SUPPORTS_FULL_VALUEADDS), true)
#WIPOWER, wbc
PRODUCT_PACKAGES += wbc_hal.default
PRODUCT_PACKAGES += com.quicinc.wbc
PRODUCT_PACKAGES += com.quicinc.wbc.xml
PRODUCT_PACKAGES += com.quicinc.wbcservice
PRODUCT_PACKAGES += com.quicinc.wbcservice.xml
PRODUCT_PACKAGES += libwbc_jni
PRODUCT_PACKAGES += com.quicinc.wipoweragent
PRODUCT_PACKAGES += com.quicinc.wbcserviceapp
endif #TARGET_FWK_SUPPORTS_FULL_VALUEADDS
endif #BOARD_USES_WIPOWER
