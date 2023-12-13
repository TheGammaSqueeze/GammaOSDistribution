// Copyright 2020 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package java

import (
	"android/soong/android"
	"android/soong/java/config"
)

var legacyCorePlatformApiModules = []string{
	"AAECarSystemUI",
	"AAECarSystemUI-tests",
	"ArcSettings",
	"ahat-test-dump",
	"android.car",
	"android.test.mock",
	"android.test.mock.impl",
	"AoapTestDeviceApp",
	"AoapTestHostApp",
	"api-stubs-docs",
	"art_cts_jvmti_test_library",
	"art-gtest-jars-MyClassNatives",
	"BackupEncryption",
	"BackupFrameworksServicesRoboTests",
	"backuplib",
	"BandwidthEnforcementTest",
	"BlockedNumberProvider",
	"BluetoothInstrumentationTests",
	"BluetoothMidiLib",
	"BluetoothMidiService",
	"BTTestApp",
	"CallEnhancement",
	"CapCtrlInterface",
	"CarService",
	"CarServiceTest",
	"car-service-test-lib",
	"car-service-test-static-lib",
	"CertInstaller",
	"com.qti.location.sdk",
	"com.qti.media.secureprocessor",
	"ConnectivityManagerTest",
	"ContactsProvider",
	"CorePerfTests",
	"core-tests-support",
	"cronet_impl_common_java",
	"cronet_impl_native_java",
	"cronet_impl_platform_java",
	"CtsAppExitTestCases",
	"CtsContentTestCases",
	"CtsLibcoreWycheproofBCTestCases",
	"CtsMediaTestCases",
	"CtsNetTestCases",
	"CtsNetTestCasesLatestSdk",
	"CtsSecurityTestCases",
	"CtsSuspendAppsTestCases",
	"CtsUsageStatsTestCases",
	"DeadpoolService",
	"DeadpoolServiceBtServices",
	"DeviceInfo",
	"DiagnosticTools",
	"DisplayCutoutEmulationEmu01Overlay",
	"DocumentsUIGoogleTests",
	"DocumentsUIPerfTests",
	"DocumentsUITests",
	"DocumentsUIUnitTests",
	"DownloadProvider",
	"DownloadProviderTests",
	"DownloadProviderUi",
	"ds-car-docs", // for AAOS API documentation only
	"DynamicSystemInstallationService",
	"EmergencyInfo-lib",
	"ethernet-service",
	"EthernetServiceTests",
	"ExternalStorageProvider",
	"face-V1-0-javalib",
	"FloralClocks",
	"framework-jobscheduler",
	"framework-minus-apex",
	"framework-minus-apex-intdefs",
	"FrameworkOverlayG6QU3",
	"FrameworksCoreTests",
	"FrameworksIkeTests",
	"FrameworksNetCommonTests",
	"FrameworksNetTests",
	"FrameworksServicesRoboTests",
	"FrameworksServicesTests",
	"FrameworksMockingServicesTests",
	"FrameworksUtilTests",
	"GtsIncrementalInstallTestCases",
	"GtsIncrementalInstallTriggerApp",
	"GtsInstallerV2TestCases",
	"HelloOslo",
	"hid",
	"hidl_test_java_java",
	"hwbinder",
	"imssettings",
	"izat.lib.glue",
	"KeyChain",
	"LocalSettingsLib",
	"LocalTransport",
	"lockagent",
	"mediaframeworktest",
	"mediatek-ims-base",
	"MmsService",
	"ModemTestMode",
	"MtkCapCtrl",
	"MtpService",
	"MultiDisplayProvider",
	"my.tests.snapdragonsdktest",
	"NetworkSetting",
	"NetworkStackIntegrationTestsLib",
	"NetworkStackNextIntegrationTests",
	"NetworkStackNextTests",
	"NetworkStackTests",
	"NetworkStackTestsLib",
	"online-gcm-ref-docs",
	"online-gts-docs",
	"PerformanceMode",
	"platform_library-docs",
	"PowerStatsService",
	"PrintSpooler",
	"pxp-monitor",
	"QColor",
	"qcom.fmradio",
	"QDCMMobileApp",
	"Qmmi",
	"QPerformance",
	"remotesimlockmanagerlibrary",
	"RollbackTest",
	"sam",
	"saminterfacelibrary",
	"sammanagerlibrary",
	"service-blobstore",
	"service-connectivity-pre-jarjar",
	"service-jobscheduler",
	"services",
	"services.accessibility",
	"services.backup",
	"services.core.unboosted",
	"services.devicepolicy",
	"services.print",
	"services.usage",
	"services.usb",
	"Settings-core",
	"SettingsGoogle",
	"SettingsGoogleOverlayCoral",
	"SettingsGoogleOverlayFlame",
	"SettingsLib",
	"SettingsOverlayG020A",
	"SettingsOverlayG020B",
	"SettingsOverlayG020C",
	"SettingsOverlayG020D",
	"SettingsOverlayG020E",
	"SettingsOverlayG020E_VN",
	"SettingsOverlayG020F",
	"SettingsOverlayG020F_VN",
	"SettingsOverlayG020G",
	"SettingsOverlayG020G_VN",
	"SettingsOverlayG020H",
	"SettingsOverlayG020H_VN",
	"SettingsOverlayG020I",
	"SettingsOverlayG020I_VN",
	"SettingsOverlayG020J",
	"SettingsOverlayG020M",
	"SettingsOverlayG020N",
	"SettingsOverlayG020P",
	"SettingsOverlayG020Q",
	"SettingsOverlayG025H",
	"SettingsOverlayG025J",
	"SettingsOverlayG025M",
	"SettingsOverlayG025N",
	"SettingsOverlayG5NZ6",
	"SettingsProvider",
	"SettingsProviderTest",
	"SettingsRoboTests",
	"Shell",
	"ShellTests",
	"SimContact",
	"SimContacts",
	"SimSettings",
	"sl4a.Common",
	"StatementService",
	"SystemUI-core",
	"SystemUISharedLib",
	"SystemUI-tests",
	"tcmiface",
	"Telecom",
	"TelecomUnitTests",
	"telephony-common",
	"TelephonyProviderTests",
	"TeleService",
	"testables",
	"TetheringTests",
	"TetheringTestsLib",
	"time_zone_distro_installer",
	"time_zone_distro_installer-tests",
	"time_zone_distro-tests",
	"time_zone_updater",
	"TMobilePlanProvider",
	"TvProvider",
	"uiautomator-stubs-docs",
	"uimgbamanagerlibrary",
	"UsbHostExternalManagementTestApp",
	"UserDictionaryProvider",
	"UxPerformance",
	"WallpaperBackup",
	"WallpaperBackupAgentTests",
	"WfdCommon",
}

var legacyCorePlatformApiLookup = make(map[string]struct{})

func init() {
	for _, module := range legacyCorePlatformApiModules {
		legacyCorePlatformApiLookup[module] = struct{}{}
	}
}

func useLegacyCorePlatformApi(ctx android.EarlyModuleContext) bool {
	return useLegacyCorePlatformApiByName(ctx.ModuleName())
}

func useLegacyCorePlatformApiByName(name string) bool {
	_, found := legacyCorePlatformApiLookup[name]
	return found
}

func corePlatformSystemModules(ctx android.EarlyModuleContext) string {
	if useLegacyCorePlatformApi(ctx) {
		return config.LegacyCorePlatformSystemModules
	} else {
		return config.StableCorePlatformSystemModules
	}
}

func corePlatformBootclasspathLibraries(ctx android.EarlyModuleContext) []string {
	if useLegacyCorePlatformApi(ctx) {
		return config.LegacyCorePlatformBootclasspathLibraries
	} else {
		return config.StableCorePlatformBootclasspathLibraries
	}
}
