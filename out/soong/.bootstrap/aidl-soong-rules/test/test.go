
package main

import (
	"io"

	"regexp"
	"testing"

	pkg "android/soong/aidl"
)

var t = []testing.InternalTest{

	{"TestAidlFlags", pkg.TestAidlFlags},

	{"TestAidlImportFlagsForIncludeDirs", pkg.TestAidlImportFlagsForIncludeDirs},

	{"TestAidlModuleNameContainsVersion", pkg.TestAidlModuleNameContainsVersion},

	{"TestCcModuleWithApexNameMacro", pkg.TestCcModuleWithApexNameMacro},

	{"TestCreatesModulesWithFrozenVersions", pkg.TestCreatesModulesWithFrozenVersions},

	{"TestCreatesModulesWithNoVersions", pkg.TestCreatesModulesWithNoVersions},

	{"TestDuplicatedVersions", pkg.TestDuplicatedVersions},

	{"TestErrorsWithDuplicateVersions", pkg.TestErrorsWithDuplicateVersions},

	{"TestErrorsWithNonIntegerVersions", pkg.TestErrorsWithNonIntegerVersions},

	{"TestErrorsWithNonPositiveVersions", pkg.TestErrorsWithNonPositiveVersions},

	{"TestErrorsWithUnsortedVersions", pkg.TestErrorsWithUnsortedVersions},

	{"TestExplicitAidlModuleImport", pkg.TestExplicitAidlModuleImport},

	{"TestImportInRelease", pkg.TestImportInRelease},

	{"TestImports", pkg.TestImports},

	{"TestNativeOutputIsAlwaysVersioned", pkg.TestNativeOutputIsAlwaysVersioned},

	{"TestNonVersionedModuleUsageInRelease", pkg.TestNonVersionedModuleUsageInRelease},

	{"TestRustDuplicateNames", pkg.TestRustDuplicateNames},

	{"TestSrcsAvailable", pkg.TestSrcsAvailable},

	{"TestSupportsGenruleAndFilegroup", pkg.TestSupportsGenruleAndFilegroup},

	{"TestUnstableModules", pkg.TestUnstableModules},

	{"TestUnstableVersionUsageInRelease", pkg.TestUnstableVersionUsageInRelease},

	{"TestUnstableVersionedModuleUsageInRelease", pkg.TestUnstableVersionedModuleUsageInRelease},

	{"TestUnstableVndkModule", pkg.TestUnstableVndkModule},

	{"TestVintfWithoutVersionInRelease", pkg.TestVintfWithoutVersionInRelease},

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
	return "android/soong/aidl"
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
