
package main

import (
	"io"

	"os"

	"regexp"
	"testing"

	pkg "github.com/google/blueprint"
)

var t = []testing.InternalTest{

	{"TestAddVariationDependencies", pkg.TestAddVariationDependencies},

	{"TestAliasVariation", pkg.TestAliasVariation},

	{"TestCheckBlueprintSyntax", pkg.TestCheckBlueprintSyntax},

	{"TestContextParse", pkg.TestContextParse},

	{"TestCreateAliasVariations", pkg.TestCreateAliasVariations},

	{"TestCreateModule", pkg.TestCreateModule},

	{"TestGlobCache", pkg.TestGlobCache},

	{"TestInvalidProvidersUsage", pkg.TestInvalidProvidersUsage},

	{"TestNinjaWriter", pkg.TestNinjaWriter},

	{"TestParseFailsForModuleWithoutName", pkg.TestParseFailsForModuleWithoutName},

	{"TestParseNinjaString", pkg.TestParseNinjaString},

	{"TestParseNinjaStringWithImportedVar", pkg.TestParseNinjaStringWithImportedVar},

	{"TestProviders", pkg.TestProviders},

	{"TestSpliceModules", pkg.TestSpliceModules},

	{"TestVisit", pkg.TestVisit},

	{"TestWalkDeps", pkg.TestWalkDeps},

	{"TestWalkDepsDuplicates", pkg.TestWalkDepsDuplicates},

	{"TestWalkDepsDuplicates_IgnoreFirstPath", pkg.TestWalkDepsDuplicates_IgnoreFirstPath},

	{"TestWalkFileOrder", pkg.TestWalkFileOrder},

	{"TestWalkingWithSyntaxError", pkg.TestWalkingWithSyntaxError},

	{"Test_findVariant", pkg.Test_findVariant},

	{"Test_parallelVisit", pkg.Test_parallelVisit},

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
	return "github.com/google/blueprint"
}

func (matchString) StartTestLog(io.Writer) {
	panic("shouldn't get here")
}

func (matchString) StopTestLog() error {
	panic("shouldn't get here")
}

func main() {

	m := testing.MainStart(matchString{}, t, nil, e)


	os.Exit(m.Run())

}
