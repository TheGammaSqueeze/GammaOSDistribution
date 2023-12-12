package com.android.settingslib.search;

import java.lang.Override;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

public class SearchIndexableResourcesBase implements SearchIndexableResources {
  private final Set<SearchIndexableData> mProviders = new HashSet();

  public SearchIndexableResourcesBase() {
    addIndex(new SearchIndexableData(com.android.settings.AllInOneTetherSettings.class, com.android.settings.AllInOneTetherSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.LegalSettings.class, com.android.settings.LegalSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.TetherSettings.class, com.android.settings.TetherSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.accounts.AccountDashboardFragment.class, com.android.settings.accounts.AccountDashboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.accounts.ManagedProfileSettings.class, com.android.settings.accounts.ManagedProfileSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.applications.AppDashboardFragment.class, com.android.settings.applications.AppDashboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.applications.assist.ManageAssist.class, com.android.settings.applications.assist.ManageAssist.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.applications.specialaccess.SpecialAccessSettings.class, com.android.settings.applications.specialaccess.SpecialAccessSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.applications.specialaccess.deviceadmin.DeviceAdminSettings.class, com.android.settings.applications.specialaccess.deviceadmin.DeviceAdminSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.applications.specialaccess.interactacrossprofiles.InteractAcrossProfilesSettings.class, com.android.settings.applications.specialaccess.interactacrossprofiles.InteractAcrossProfilesSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.applications.specialaccess.pictureinpicture.PictureInPictureSettings.class, com.android.settings.applications.specialaccess.pictureinpicture.PictureInPictureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.applications.specialaccess.premiumsms.PremiumSmsAccess.class, com.android.settings.applications.specialaccess.premiumsms.PremiumSmsAccess.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.applications.specialaccess.vrlistener.VrListenerSettings.class, com.android.settings.applications.specialaccess.vrlistener.VrListenerSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.backup.BackupSettingsFragment.class, com.android.settings.backup.BackupSettingsFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.backup.PrivacySettings.class, com.android.settings.backup.PrivacySettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.backup.UserBackupSettingsActivity.class, com.android.settings.backup.UserBackupSettingsActivity.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.biometrics.combination.CombinedBiometricSettings.class, com.android.settings.biometrics.combination.CombinedBiometricSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.biometrics.face.FaceSettings.class, com.android.settings.biometrics.face.FaceSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.datausage.BillingCycleSettings.class, com.android.settings.datausage.BillingCycleSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.datausage.DataSaverSummary.class, com.android.settings.datausage.DataSaverSummary.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.datausage.UnrestrictedDataAccess.class, com.android.settings.datausage.UnrestrictedDataAccess.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.datetime.DateTimeSettings.class, com.android.settings.datetime.DateTimeSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.datetime.timezone.TimeZoneSettings.class, com.android.settings.datetime.timezone.TimeZoneSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.deletionhelper.AutomaticStorageManagerSettings.class, com.android.settings.deletionhelper.AutomaticStorageManagerSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.development.WirelessDebuggingFragment.class, com.android.settings.development.WirelessDebuggingFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.development.featureflags.FeatureFlagsDashboard.class, com.android.settings.development.featureflags.FeatureFlagsDashboard.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.development.graphicsdriver.GraphicsDriverDashboard.class, com.android.settings.development.graphicsdriver.GraphicsDriverDashboard.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.development.qstile.DevelopmentTileConfigFragment.class, com.android.settings.development.qstile.DevelopmentTileConfigFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.development.transcode.TranscodeSettingsFragment.class, com.android.settings.development.transcode.TranscodeSettingsFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.deviceinfo.StorageDashboardFragment.class, com.android.settings.deviceinfo.StorageDashboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.deviceinfo.aboutphone.MyDeviceInfoFragment.class, com.android.settings.deviceinfo.aboutphone.MyDeviceInfoFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.deviceinfo.firmwareversion.FirmwareVersionSettings.class, com.android.settings.deviceinfo.firmwareversion.FirmwareVersionSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.deviceinfo.hardwareinfo.HardwareInfoFragment.class, com.android.settings.deviceinfo.hardwareinfo.HardwareInfoFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.display.ColorModePreferenceFragment.class, com.android.settings.display.ColorModePreferenceFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.display.SmartAutoRotatePreferenceFragment.class, com.android.settings.display.SmartAutoRotatePreferenceFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.display.ToggleFontSizePreferenceFragment.class, com.android.settings.display.ToggleFontSizePreferenceFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.dream.DreamSettings.class, com.android.settings.dream.DreamSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.emergency.EmergencyDashboardFragment.class, com.android.settings.emergency.EmergencyDashboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.emergency.EmergencyGestureSettings.class, com.android.settings.emergency.EmergencyGestureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.enterprise.EnterprisePrivacySettings.class, com.android.settings.enterprise.EnterprisePrivacySettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.AssistGestureSettings.class, com.android.settings.gestures.AssistGestureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.DoubleTapPowerSettings.class, com.android.settings.gestures.DoubleTapPowerSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.DoubleTapScreenSettings.class, com.android.settings.gestures.DoubleTapScreenSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.DoubleTwistGestureSettings.class, com.android.settings.gestures.DoubleTwistGestureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.GestureSettings.class, com.android.settings.gestures.GestureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.PickupGestureSettings.class, com.android.settings.gestures.PickupGestureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.PowerMenuSettings.class, com.android.settings.gestures.PowerMenuSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.PreventRingingGestureSettings.class, com.android.settings.gestures.PreventRingingGestureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.ScreenOffUdfpsSettings.class, com.android.settings.gestures.ScreenOffUdfpsSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.SwipeToNotificationSettings.class, com.android.settings.gestures.SwipeToNotificationSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.SystemNavigationGestureSettings.class, com.android.settings.gestures.SystemNavigationGestureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.gestures.TapScreenGestureSettings.class, com.android.settings.gestures.TapScreenGestureSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.inputmethod.AvailableVirtualKeyboardFragment.class, com.android.settings.inputmethod.AvailableVirtualKeyboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.inputmethod.PhysicalKeyboardFragment.class, com.android.settings.inputmethod.PhysicalKeyboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.inputmethod.UserDictionaryList.class, com.android.settings.inputmethod.UserDictionaryList.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.inputmethod.VirtualKeyboardFragment.class, com.android.settings.inputmethod.VirtualKeyboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.language.LanguageAndInputSettings.class, com.android.settings.language.LanguageAndInputSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.localepicker.LocaleListEditor.class, com.android.settings.localepicker.LocaleListEditor.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.location.LocationSettings.class, com.android.settings.location.LocationSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.location.RecentLocationAccessSeeAllFragment.class, com.android.settings.location.RecentLocationAccessSeeAllFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.network.AdaptiveConnectivitySettings.class, com.android.settings.network.AdaptiveConnectivitySettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.network.NetworkDashboardFragment.class, com.android.settings.network.NetworkDashboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.network.NetworkProviderSettings.class, com.android.settings.network.NetworkProviderSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.nfc.PaymentSettings.class, com.android.settings.nfc.PaymentSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.BubbleNotificationSettings.class, com.android.settings.notification.BubbleNotificationSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.ConfigureNotificationSettings.class, com.android.settings.notification.ConfigureNotificationSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.NotificationAccessSettings.class, com.android.settings.notification.NotificationAccessSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.SoundSettings.class, com.android.settings.notification.SoundSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.SoundWorkSettings.class, com.android.settings.notification.SoundWorkSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.app.AppBubbleNotificationSettings.class, com.android.settings.notification.app.AppBubbleNotificationSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenAccessSettings.class, com.android.settings.notification.zen.ZenAccessSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModeAutomationSettings.class, com.android.settings.notification.zen.ZenModeAutomationSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModeBlockedEffectsSettings.class, com.android.settings.notification.zen.ZenModeBlockedEffectsSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModeBypassingAppsSettings.class, com.android.settings.notification.zen.ZenModeBypassingAppsSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModeCallsSettings.class, com.android.settings.notification.zen.ZenModeCallsSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModeConversationsSettings.class, com.android.settings.notification.zen.ZenModeConversationsSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModeMessagesSettings.class, com.android.settings.notification.zen.ZenModeMessagesSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModePeopleSettings.class, com.android.settings.notification.zen.ZenModePeopleSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModeSettings.class, com.android.settings.notification.zen.ZenModeSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.notification.zen.ZenModeSoundVibrationSettings.class, com.android.settings.notification.zen.ZenModeSoundVibrationSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.print.PrintSettingsFragment.class, com.android.settings.print.PrintSettingsFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.privacy.PrivacyDashboardFragment.class, com.android.settings.privacy.PrivacyDashboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.security.CredentialManagementAppFragment.class, com.android.settings.security.CredentialManagementAppFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.security.EncryptionAndCredential.class, com.android.settings.security.EncryptionAndCredential.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.security.InstallCertificateFromStorage.class, com.android.settings.security.InstallCertificateFromStorage.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.security.LockscreenDashboardFragment.class, com.android.settings.security.LockscreenDashboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.security.ScreenPinningSettings.class, com.android.settings.security.ScreenPinningSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.security.SecuritySettings.class, com.android.settings.security.SecuritySettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.security.screenlock.ScreenLockSettings.class, com.android.settings.security.screenlock.ScreenLockSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.security.trustagent.TrustAgentSettings.class, com.android.settings.security.trustagent.TrustAgentSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.sound.MediaControlsSettings.class, com.android.settings.sound.MediaControlsSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.support.SupportDashboardActivity.class, com.android.settings.support.SupportDashboardActivity.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.system.SystemDashboardFragment.class, com.android.settings.system.SystemDashboardFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.tts.TextToSpeechSettings.class, com.android.settings.tts.TextToSpeechSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.tts.TtsEnginePreferenceFragment.class, com.android.settings.tts.TtsEnginePreferenceFragment.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.users.UserSettings.class, com.android.settings.users.UserSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.wallpaper.WallpaperSuggestionActivity.class, com.android.settings.wallpaper.WallpaperSuggestionActivity.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.wifi.ConfigureWifiSettings.class, com.android.settings.wifi.ConfigureWifiSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.wifi.WifiSettings.class, com.android.settings.wifi.WifiSettings.SEARCH_INDEX_DATA_PROVIDER));
    addIndex(new SearchIndexableData(com.android.settings.wifi.tether.WifiTetherSettings.class, com.android.settings.wifi.tether.WifiTetherSettings.SEARCH_INDEX_DATA_PROVIDER));
  }

  public void addIndex(SearchIndexableData indexClass) {
    mProviders.add(indexClass);
  }

  @Override
  public Collection<SearchIndexableData> getProviderValues() {
    return mProviders;
  }
}
