
package main

import (
	"io"

	"regexp"
	"testing"

	pkg "android/soong/cc"
)

var t = []testing.InternalTest{

	{"TestAidl", pkg.TestAidl},

	{"TestAidlFlagsPassedToTheAidlCompiler", pkg.TestAidlFlagsPassedToTheAidlCompiler},

	{"TestArchGenruleCmd", pkg.TestArchGenruleCmd},

	{"TestAsan", pkg.TestAsan},

	{"TestCcObjectWithBazel", pkg.TestCcObjectWithBazel},

	{"TestCheckVndkMembershipBeforeDoubleLoadable", pkg.TestCheckVndkMembershipBeforeDoubleLoadable},

	{"TestCompilerFlags", pkg.TestCompilerFlags},

	{"TestDataLibs", pkg.TestDataLibs},

	{"TestDataLibsPrebuiltSharedTestLibrary", pkg.TestDataLibsPrebuiltSharedTestLibrary},

	{"TestDataLibsRelativeInstallPath", pkg.TestDataLibsRelativeInstallPath},

	{"TestDataTests", pkg.TestDataTests},

	{"TestDefaults", pkg.TestDefaults},

	{"TestDoubleLoadableDepError", pkg.TestDoubleLoadableDepError},

	{"TestDoubleLoadbleDep", pkg.TestDoubleLoadbleDep},

	{"TestEmptyWholeStaticLibsAllowMissingDependencies", pkg.TestEmptyWholeStaticLibsAllowMissingDependencies},

	{"TestEnforceProductVndkVersion", pkg.TestEnforceProductVndkVersion},

	{"TestEnforceProductVndkVersionErrors", pkg.TestEnforceProductVndkVersionErrors},

	{"TestErrorsIfAModuleDependsOnDisabled", pkg.TestErrorsIfAModuleDependsOnDisabled},

	{"TestExcludeRuntimeLibs", pkg.TestExcludeRuntimeLibs},

	{"TestFuchsiaDeps", pkg.TestFuchsiaDeps},

	{"TestFuchsiaTargetDecl", pkg.TestFuchsiaTargetDecl},

	{"TestFuzzTarget", pkg.TestFuzzTarget},

	{"TestGen", pkg.TestGen},

	{"TestIncludeDirsExporting", pkg.TestIncludeDirsExporting},

	{"TestInstallPartition", pkg.TestInstallPartition},

	{"TestInstallSharedLibs", pkg.TestInstallSharedLibs},

	{"TestIsThirdParty", pkg.TestIsThirdParty},

	{"TestLibraryGenruleCmd", pkg.TestLibraryGenruleCmd},

	{"TestLibraryHeaders", pkg.TestLibraryHeaders},

	{"TestLibraryReuse", pkg.TestLibraryReuse},

	{"TestLinkerScript", pkg.TestLinkerScript},

	{"TestLlndkHeaders", pkg.TestLlndkHeaders},

	{"TestLlndkLibrary", pkg.TestLlndkLibrary},

	{"TestMakeLinkType", pkg.TestMakeLinkType},

	{"TestMinSdkVersionInClangTriple", pkg.TestMinSdkVersionInClangTriple},

	{"TestMinSdkVersionsOfCrtObjects", pkg.TestMinSdkVersionsOfCrtObjects},

	{"TestPrebuilt", pkg.TestPrebuilt},

	{"TestPrebuiltLibrary", pkg.TestPrebuiltLibrary},

	{"TestPrebuiltLibraryHeaders", pkg.TestPrebuiltLibraryHeaders},

	{"TestPrebuiltLibrarySanitized", pkg.TestPrebuiltLibrarySanitized},

	{"TestPrebuiltLibraryShared", pkg.TestPrebuiltLibraryShared},

	{"TestPrebuiltLibrarySharedStem", pkg.TestPrebuiltLibrarySharedStem},

	{"TestPrebuiltLibraryStatic", pkg.TestPrebuiltLibraryStatic},

	{"TestPrebuiltLibraryStem", pkg.TestPrebuiltLibraryStem},

	{"TestPrebuiltSymlinkedHostBinary", pkg.TestPrebuiltSymlinkedHostBinary},

	{"TestPrepareForTestWithCcDefaultModules", pkg.TestPrepareForTestWithCcDefaultModules},

	{"TestProductVariableDefaults", pkg.TestProductVariableDefaults},

	{"TestProductVndkExtDependency", pkg.TestProductVndkExtDependency},

	{"TestProto", pkg.TestProto},

	{"TestRecovery", pkg.TestRecovery},

	{"TestRecoverySnapshotCapture", pkg.TestRecoverySnapshotCapture},

	{"TestRecoverySnapshotDirected", pkg.TestRecoverySnapshotDirected},

	{"TestRecoverySnapshotExclude", pkg.TestRecoverySnapshotExclude},

	{"TestRuntimeLibs", pkg.TestRuntimeLibs},

	{"TestRuntimeLibsNoVndk", pkg.TestRuntimeLibsNoVndk},

	{"TestSanitizeMemtagHeap", pkg.TestSanitizeMemtagHeap},

	{"TestSanitizeMemtagHeapWithSanitizeDevice", pkg.TestSanitizeMemtagHeapWithSanitizeDevice},

	{"TestSanitizeMemtagHeapWithSanitizeDeviceDiag", pkg.TestSanitizeMemtagHeapWithSanitizeDeviceDiag},

	{"TestStaticDepsOrderWithStubs", pkg.TestStaticDepsOrderWithStubs},

	{"TestStaticExecutable", pkg.TestStaticExecutable},

	{"TestStaticLibDepExport", pkg.TestStaticLibDepExport},

	{"TestStaticLibDepReordering", pkg.TestStaticLibDepReordering},

	{"TestStaticLibDepReorderingWithShared", pkg.TestStaticLibDepReorderingWithShared},

	{"TestStubsLibReexportsHeaders", pkg.TestStubsLibReexportsHeaders},

	{"TestStubsVersions", pkg.TestStubsVersions},

	{"TestStubsVersions_NotSorted", pkg.TestStubsVersions_NotSorted},

	{"TestStubsVersions_ParseError", pkg.TestStubsVersions_ParseError},

	{"TestUseCrtObjectOfCorrectVersion", pkg.TestUseCrtObjectOfCorrectVersion},

	{"TestVendorModuleUseVndkExt", pkg.TestVendorModuleUseVndkExt},

	{"TestVendorPublicLibraries", pkg.TestVendorPublicLibraries},

	{"TestVendorSnapshotCapture", pkg.TestVendorSnapshotCapture},

	{"TestVendorSnapshotDirected", pkg.TestVendorSnapshotDirected},

	{"TestVendorSnapshotExclude", pkg.TestVendorSnapshotExclude},

	{"TestVendorSnapshotExcludeInVendorProprietaryPathErrors", pkg.TestVendorSnapshotExcludeInVendorProprietaryPathErrors},

	{"TestVendorSnapshotSanitizer", pkg.TestVendorSnapshotSanitizer},

	{"TestVendorSnapshotUse", pkg.TestVendorSnapshotUse},

	{"TestVendorSrc", pkg.TestVendorSrc},

	{"TestVersionedStubs", pkg.TestVersionedStubs},

	{"TestVersioningMacro", pkg.TestVersioningMacro},

	{"TestVndk", pkg.TestVndk},

	{"TestVndkDepError", pkg.TestVndkDepError},

	{"TestVndkExt", pkg.TestVndkExt},

	{"TestVndkExtError", pkg.TestVndkExtError},

	{"TestVndkExtInconsistentSupportSystemProcessError", pkg.TestVndkExtInconsistentSupportSystemProcessError},

	{"TestVndkExtUseVendorLib", pkg.TestVndkExtUseVendorLib},

	{"TestVndkExtVendorAvailableFalseError", pkg.TestVndkExtVendorAvailableFalseError},

	{"TestVndkExtWithoutBoardVndkVersion", pkg.TestVndkExtWithoutBoardVndkVersion},

	{"TestVndkExtWithoutProductVndkVersion", pkg.TestVndkExtWithoutProductVndkVersion},

	{"TestVndkLibrariesTxtAndroidMk", pkg.TestVndkLibrariesTxtAndroidMk},

	{"TestVndkModuleError", pkg.TestVndkModuleError},

	{"TestVndkSpExtUseVndkError", pkg.TestVndkSpExtUseVndkError},

	{"TestVndkUseVndkExtError", pkg.TestVndkUseVndkExtError},

	{"TestVndkUsingCoreVariant", pkg.TestVndkUsingCoreVariant},

	{"TestVndkWhenVndkVersionIsNotSet", pkg.TestVndkWhenVndkVersionIsNotSet},

	{"TestVndkWithHostSupported", pkg.TestVndkWithHostSupported},

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
	return "android/soong/cc"
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
