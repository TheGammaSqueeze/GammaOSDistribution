
package main

import (
	"io"

	"regexp"
	"testing"

	pkg "android/soong/java"
)

var t = []testing.InternalTest{

	{"TestAidlExportIncludeDirsFromImports", pkg.TestAidlExportIncludeDirsFromImports},

	{"TestAidlFlagsArePassedToTheAidlCompiler", pkg.TestAidlFlagsArePassedToTheAidlCompiler},

	{"TestAndroidAppImport", pkg.TestAndroidAppImport},

	{"TestAndroidAppImport_ArchVariants", pkg.TestAndroidAppImport_ArchVariants},

	{"TestAndroidAppImport_DefaultDevCert", pkg.TestAndroidAppImport_DefaultDevCert},

	{"TestAndroidAppImport_DpiVariants", pkg.TestAndroidAppImport_DpiVariants},

	{"TestAndroidAppImport_Filename", pkg.TestAndroidAppImport_Filename},

	{"TestAndroidAppImport_NoDexPreopt", pkg.TestAndroidAppImport_NoDexPreopt},

	{"TestAndroidAppImport_Presigned", pkg.TestAndroidAppImport_Presigned},

	{"TestAndroidAppImport_SigningLineage", pkg.TestAndroidAppImport_SigningLineage},

	{"TestAndroidAppImport_SigningLineageFilegroup", pkg.TestAndroidAppImport_SigningLineageFilegroup},

	{"TestAndroidAppImport_frameworkRes", pkg.TestAndroidAppImport_frameworkRes},

	{"TestAndroidAppImport_overridesDisabledAndroidApp", pkg.TestAndroidAppImport_overridesDisabledAndroidApp},

	{"TestAndroidAppLinkType", pkg.TestAndroidAppLinkType},

	{"TestAndroidAppSet", pkg.TestAndroidAppSet},

	{"TestAndroidAppSet_Variants", pkg.TestAndroidAppSet_Variants},

	{"TestAndroidResources", pkg.TestAndroidResources},

	{"TestAndroidTestHelperApp_LocalDisableTestConfig", pkg.TestAndroidTestHelperApp_LocalDisableTestConfig},

	{"TestAndroidTestImport", pkg.TestAndroidTestImport},

	{"TestAndroidTestImport_NoJinUncompressForPresigned", pkg.TestAndroidTestImport_NoJinUncompressForPresigned},

	{"TestAndroidTestImport_Preprocessed", pkg.TestAndroidTestImport_Preprocessed},

	{"TestAndroidTest_FixTestConfig", pkg.TestAndroidTest_FixTestConfig},

	{"TestApp", pkg.TestApp},

	{"TestAppJavaResources", pkg.TestAppJavaResources},

	{"TestAppSdkVersion", pkg.TestAppSdkVersion},

	{"TestAppSdkVersionByPartition", pkg.TestAppSdkVersionByPartition},

	{"TestAppSplits", pkg.TestAppSplits},

	{"TestArchSpecific", pkg.TestArchSpecific},

	{"TestBinary", pkg.TestBinary},

	{"TestBootclasspathFragmentInconsistentArtConfiguration_ApexMixture", pkg.TestBootclasspathFragmentInconsistentArtConfiguration_ApexMixture},

	{"TestBootclasspathFragmentInconsistentArtConfiguration_Platform", pkg.TestBootclasspathFragmentInconsistentArtConfiguration_Platform},

	{"TestBootclasspathFragment_Coverage", pkg.TestBootclasspathFragment_Coverage},

	{"TestBootclasspathFragment_StubLibs", pkg.TestBootclasspathFragment_StubLibs},

	{"TestBootclasspathFragment_UnknownImageName", pkg.TestBootclasspathFragment_UnknownImageName},

	{"TestCertificates", pkg.TestCertificates},

	{"TestClasspath", pkg.TestClasspath},

	{"TestCodelessApp", pkg.TestCodelessApp},

	{"TestCollectJavaLibraryPropertiesAddAidlIncludeDirs", pkg.TestCollectJavaLibraryPropertiesAddAidlIncludeDirs},

	{"TestCollectJavaLibraryPropertiesAddJarjarRules", pkg.TestCollectJavaLibraryPropertiesAddJarjarRules},

	{"TestCollectJavaLibraryPropertiesAddLibsDeps", pkg.TestCollectJavaLibraryPropertiesAddLibsDeps},

	{"TestCollectJavaLibraryPropertiesAddScrs", pkg.TestCollectJavaLibraryPropertiesAddScrs},

	{"TestCollectJavaLibraryPropertiesAddStaticLibsDeps", pkg.TestCollectJavaLibraryPropertiesAddStaticLibsDeps},

	{"TestCompilerFlags", pkg.TestCompilerFlags},

	{"TestDataNativeBinaries", pkg.TestDataNativeBinaries},

	{"TestDefaultInstallable", pkg.TestDefaultInstallable},

	{"TestDefaults", pkg.TestDefaults},

	{"TestDeviceForHost", pkg.TestDeviceForHost},

	{"TestDex2oatToolDeps", pkg.TestDex2oatToolDeps},

	{"TestDexpreoptBcp", pkg.TestDexpreoptBcp},

	{"TestDexpreoptBootJars", pkg.TestDexpreoptBootJars},

	{"TestDexpreoptBootZip", pkg.TestDexpreoptBootZip},

	{"TestDexpreoptEnabled", pkg.TestDexpreoptEnabled},

	{"TestDroiddoc", pkg.TestDroiddoc},

	{"TestDroiddocArgsAndFlagsCausesError", pkg.TestDroiddocArgsAndFlagsCausesError},

	{"TestDroidstubs", pkg.TestDroidstubs},

	{"TestDroidstubsSandbox", pkg.TestDroidstubsSandbox},

	{"TestDroidstubsWithSystemModules", pkg.TestDroidstubsWithSystemModules},

	{"TestEmbedNotice", pkg.TestEmbedNotice},

	{"TestEnforceRRO_propagatesToDependencies", pkg.TestEnforceRRO_propagatesToDependencies},

	{"TestExcludeFileGroupInSrcs", pkg.TestExcludeFileGroupInSrcs},

	{"TestExportedPlugins", pkg.TestExportedPlugins},

	{"TestExportedProguardFlagFiles", pkg.TestExportedProguardFlagFiles},

	{"TestGeneratedSources", pkg.TestGeneratedSources},

	{"TestHiddenAPIEncoding_JavaSdkLibrary", pkg.TestHiddenAPIEncoding_JavaSdkLibrary},

	{"TestHiddenAPISingleton", pkg.TestHiddenAPISingleton},

	{"TestHiddenAPISingletonSdks", pkg.TestHiddenAPISingletonSdks},

	{"TestHiddenAPISingletonWithPrebuilt", pkg.TestHiddenAPISingletonWithPrebuilt},

	{"TestHiddenAPISingletonWithPrebuiltCsvFile", pkg.TestHiddenAPISingletonWithPrebuiltCsvFile},

	{"TestHiddenAPISingletonWithPrebuiltOverrideSource", pkg.TestHiddenAPISingletonWithPrebuiltOverrideSource},

	{"TestHiddenAPISingletonWithPrebuiltUseSource", pkg.TestHiddenAPISingletonWithPrebuiltUseSource},

	{"TestHiddenAPISingletonWithSourceAndPrebuiltPreferredButNoDex", pkg.TestHiddenAPISingletonWithSourceAndPrebuiltPreferredButNoDex},

	{"TestHostBinaryNoJavaDebugInfoOverride", pkg.TestHostBinaryNoJavaDebugInfoOverride},

	{"TestHostForDevice", pkg.TestHostForDevice},

	{"TestHostdex", pkg.TestHostdex},

	{"TestHostdexRequired", pkg.TestHostdexRequired},

	{"TestHostdexSpecificRequired", pkg.TestHostdexSpecificRequired},

	{"TestImportSoongDexJar", pkg.TestImportSoongDexJar},

	{"TestIncludeSrcs", pkg.TestIncludeSrcs},

	{"TestInstrumentationTargetOverridden", pkg.TestInstrumentationTargetOverridden},

	{"TestJNIABI", pkg.TestJNIABI},

	{"TestJNIPackaging", pkg.TestJNIPackaging},

	{"TestJNISDK", pkg.TestJNISDK},

	{"TestJacocoFilterToSpecs", pkg.TestJacocoFilterToSpecs},

	{"TestJacocoFiltersToZipCommand", pkg.TestJacocoFiltersToZipCommand},

	{"TestJarGenrules", pkg.TestJarGenrules},

	{"TestJavaImport", pkg.TestJavaImport},

	{"TestJavaLibrary", pkg.TestJavaLibrary},

	{"TestJavaLibraryWithSystemModules", pkg.TestJavaLibraryWithSystemModules},

	{"TestJavaLinkType", pkg.TestJavaLinkType},

	{"TestJavaLint", pkg.TestJavaLint},

	{"TestJavaLintBypassUpdatableChecks", pkg.TestJavaLintBypassUpdatableChecks},

	{"TestJavaLintDatabaseSelectionFull", pkg.TestJavaLintDatabaseSelectionFull},

	{"TestJavaLintDatabaseSelectionPublicFiltered", pkg.TestJavaLintDatabaseSelectionPublicFiltered},

	{"TestJavaLintRequiresCustomLintFileToExist", pkg.TestJavaLintRequiresCustomLintFileToExist},

	{"TestJavaLintStrictUpdatabilityLinting", pkg.TestJavaLintStrictUpdatabilityLinting},

	{"TestJavaLintUsesCorrectBpConfig", pkg.TestJavaLintUsesCorrectBpConfig},

	{"TestJavaLintWithoutBaseline", pkg.TestJavaLintWithoutBaseline},

	{"TestJavaSdkLibrary_RequireXmlPermissionFile", pkg.TestJavaSdkLibrary_RequireXmlPermissionFile},

	{"TestJavaSystemModules", pkg.TestJavaSystemModules},

	{"TestJavaSystemModulesImport", pkg.TestJavaSystemModulesImport},

	{"TestJavaSystemModulesMixSourceAndPrebuilt", pkg.TestJavaSystemModulesMixSourceAndPrebuilt},

	{"TestKapt", pkg.TestKapt},

	{"TestKaptEncodeFlags", pkg.TestKaptEncodeFlags},

	{"TestKotlin", pkg.TestKotlin},

	{"TestLibraryAssets", pkg.TestLibraryAssets},

	{"TestNoPlugin", pkg.TestNoPlugin},

	{"TestOverrideAndroidApp", pkg.TestOverrideAndroidApp},

	{"TestOverrideAndroidAppDependency", pkg.TestOverrideAndroidAppDependency},

	{"TestOverrideAndroidTest", pkg.TestOverrideAndroidTest},

	{"TestOverrideRuntimeResourceOverlay", pkg.TestOverrideRuntimeResourceOverlay},

	{"TestPackageNameOverride", pkg.TestPackageNameOverride},

	{"TestPatchModule", pkg.TestPatchModule},

	{"TestPlatformAPIs", pkg.TestPlatformAPIs},

	{"TestPlatformBootclasspath", pkg.TestPlatformBootclasspath},

	{"TestPlatformBootclasspathModule_AndroidMkEntries", pkg.TestPlatformBootclasspathModule_AndroidMkEntries},

	{"TestPlatformBootclasspathVariant", pkg.TestPlatformBootclasspathVariant},

	{"TestPlatformBootclasspath_ClasspathFragmentPaths", pkg.TestPlatformBootclasspath_ClasspathFragmentPaths},

	{"TestPlatformBootclasspath_Dist", pkg.TestPlatformBootclasspath_Dist},

	{"TestPlatformBootclasspath_HiddenAPIMonolithicFiles", pkg.TestPlatformBootclasspath_HiddenAPIMonolithicFiles},

	{"TestPlatformCompatConfig", pkg.TestPlatformCompatConfig},

	{"TestPlatformSystemServerClasspathModule_AndroidMkEntries", pkg.TestPlatformSystemServerClasspathModule_AndroidMkEntries},

	{"TestPlatformSystemServerClasspathVariant", pkg.TestPlatformSystemServerClasspathVariant},

	{"TestPlatformSystemServerClasspath_ClasspathFragmentPaths", pkg.TestPlatformSystemServerClasspath_ClasspathFragmentPaths},

	{"TestPlugin", pkg.TestPlugin},

	{"TestPluginGeneratesApi", pkg.TestPluginGeneratesApi},

	{"TestPrebuiltBootclasspathFragment_UnknownImageName", pkg.TestPrebuiltBootclasspathFragment_UnknownImageName},

	{"TestPrebuiltStubsSources", pkg.TestPrebuiltStubsSources},

	{"TestPrebuilts", pkg.TestPrebuilts},

	{"TestPrepareForTestWithJavaDefaultModules", pkg.TestPrepareForTestWithJavaDefaultModules},

	{"TestRequestV4SigningFlag", pkg.TestRequestV4SigningFlag},

	{"TestRequired", pkg.TestRequired},

	{"TestResourceDirs", pkg.TestResourceDirs},

	{"TestResources", pkg.TestResources},

	{"TestRuntimeResourceOverlay", pkg.TestRuntimeResourceOverlay},

	{"TestRuntimeResourceOverlay_JavaDefaults", pkg.TestRuntimeResourceOverlay_JavaDefaults},

	{"TestSdkVersionByPartition", pkg.TestSdkVersionByPartition},

	{"TestSharding", pkg.TestSharding},

	{"TestSimple", pkg.TestSimple},

	{"TestStl", pkg.TestStl},

	{"TestSystemServerClasspathFragmentWithoutContents", pkg.TestSystemServerClasspathFragmentWithoutContents},

	{"TestTest", pkg.TestTest},

	{"TestTurbine", pkg.TestTurbine},

	{"TestUncompressDex", pkg.TestUncompressDex},

	{"TestUpdatableApps", pkg.TestUpdatableApps},

	{"TestUpdatableApps_ErrorIfDepSdkVersionIsHigher", pkg.TestUpdatableApps_ErrorIfDepSdkVersionIsHigher},

	{"TestUpdatableApps_ErrorIfJniLibDoesntSupportMinSdkVersion", pkg.TestUpdatableApps_ErrorIfJniLibDoesntSupportMinSdkVersion},

	{"TestUpdatableApps_JniLibShouldBeBuiltAgainstMinSdkVersion", pkg.TestUpdatableApps_JniLibShouldBeBuiltAgainstMinSdkVersion},

	{"TestUpdatableApps_JniLibsShouldShouldSupportMinSdkVersion", pkg.TestUpdatableApps_JniLibsShouldShouldSupportMinSdkVersion},

	{"TestUpdatableApps_TransitiveDepsShouldSetMinSdkVersion", pkg.TestUpdatableApps_TransitiveDepsShouldSetMinSdkVersion},

	{"TestUsesLibraries", pkg.TestUsesLibraries},

	{"TestVendorAppSdkVersion", pkg.TestVendorAppSdkVersion},

}

var e = []testing.InternalExample{

}

var matchPat string
var matchRe *regexp.Regexp

type matchString struct{}

func MatchString(pat, str string) (result bool, err error) {
	if matchRe == nil || matchPat != pat {
		matchPat = pat
		matchRe, err = regexp.Compile(matchPat)
		if err != nil {
			return
		}
	}
	return matchRe.MatchString(str), nil
}

func (matchString) MatchString(pat, str string) (bool, error) {
	return MatchString(pat, str)
}

func (matchString) StartCPUProfile(w io.Writer) error {
	panic("shouldn't get here")
}

func (matchString) StopCPUProfile() {
}

func (matchString) WriteHeapProfile(w io.Writer) error {
    panic("shouldn't get here")
}

func (matchString) WriteProfileTo(string, io.Writer, int) error {
    panic("shouldn't get here")
}

func (matchString) ImportPath() string {
	return "android/soong/java"
}

func (matchString) StartTestLog(io.Writer) {
	panic("shouldn't get here")
}

func (matchString) StopTestLog() error {
	panic("shouldn't get here")
}

func main() {

	m := testing.MainStart(matchString{}, t, nil, e)


	pkg.TestMain(m)

}
