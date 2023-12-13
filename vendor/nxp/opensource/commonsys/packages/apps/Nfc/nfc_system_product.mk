ifeq ($(TARGET_FWK_SUPPORTS_FULL_VALUEADDS), true)
TARGET_USES_QSSI_NQ_NFC := true

NQ_SYSTEM_NFC := NQNfcNci
NQ_SYSTEM_NFC += libnqnfc-nci
NQ_SYSTEM_NFC += libnqnfc_nci_jni
NQ_SYSTEM_NFC += libsn100nfc_nci_jni
NQ_SYSTEM_NFC += libsn100nfc-nci
NQ_SYSTEM_NFC += com.nxp.nfc.nq
NQ_SYSTEM_NFC += com.nxp.nfc.nq.xml
NQ_SYSTEM_NFC += Tag
NQ_SYSTEM_NFC += com.android.nfc_extras

ifeq ($(strip $(TARGET_USES_QSSI_NQ_NFC)),true)
PRODUCT_PACKAGES += $(NQ_SYSTEM_NFC)
endif
endif
