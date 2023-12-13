
package main

import (
	"io"

	"regexp"
	"testing"

	pkg "android/soong/bp2build"
)

var t = []testing.InternalTest{

	{"TestAllowlistingBp2buildTargetsExplicitly", pkg.TestAllowlistingBp2buildTargetsExplicitly},

	{"TestAllowlistingBp2buildTargetsWithConfig", pkg.TestAllowlistingBp2buildTargetsWithConfig},

	{"TestBp2BuildInlinesDefaults", pkg.TestBp2BuildInlinesDefaults},

	{"TestCcLibraryBp2Build", pkg.TestCcLibraryBp2Build},

	{"TestCcLibraryHeadersBp2Build", pkg.TestCcLibraryHeadersBp2Build},

	{"TestCcLibraryHeadersLoadStatement", pkg.TestCcLibraryHeadersLoadStatement},

	{"TestCcLibraryStaticBp2Build", pkg.TestCcLibraryStaticBp2Build},

	{"TestCcLibraryStaticLoadStatement", pkg.TestCcLibraryStaticLoadStatement},

	{"TestCcObjectBp2Build", pkg.TestCcObjectBp2Build},

	{"TestCcObjectConfigurableAttributesBp2Build", pkg.TestCcObjectConfigurableAttributesBp2Build},

	{"TestCombineBuildFilesBp2buildTargets", pkg.TestCombineBuildFilesBp2buildTargets},

	{"TestCreateBazelFiles_Bp2Build_CreatesDefaultFiles", pkg.TestCreateBazelFiles_Bp2Build_CreatesDefaultFiles},

	{"TestCreateBazelFiles_QueryView_AddsTopLevelFiles", pkg.TestCreateBazelFiles_QueryView_AddsTopLevelFiles},

	{"TestGenerateBazelTargetModules", pkg.TestGenerateBazelTargetModules},

	{"TestGenerateBazelTargetModules_OneToMany_LoadedFromStarlark", pkg.TestGenerateBazelTargetModules_OneToMany_LoadedFromStarlark},

	{"TestGenerateModuleRuleShims", pkg.TestGenerateModuleRuleShims},

	{"TestGenerateSoongModuleBzl", pkg.TestGenerateSoongModuleBzl},

	{"TestGenerateSoongModuleTargets", pkg.TestGenerateSoongModuleTargets},

	{"TestGlobExcludeSrcs", pkg.TestGlobExcludeSrcs},

	{"TestLoadStatements", pkg.TestLoadStatements},

	{"TestModuleTypeBp2Build", pkg.TestModuleTypeBp2Build},

	{"TestPythonBinaryHost", pkg.TestPythonBinaryHost},

	{"TestShBinaryBp2Build", pkg.TestShBinaryBp2Build},

	{"TestShBinaryLoadStatement", pkg.TestShBinaryLoadStatement},

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
	return "android/soong/bp2build"
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
