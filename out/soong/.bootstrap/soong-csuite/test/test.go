
package main

import (
	"io"

	"regexp"
	"testing"

	pkg "android/soong/csuite"
)

var t = []testing.InternalTest{

	{"TestBpContainsManifestThrowsError", pkg.TestBpContainsManifestThrowsError},

	{"TestBpContainsTestHostPropsThrowsError", pkg.TestBpContainsTestHostPropsThrowsError},

	{"TestBpMissingNameThrowsError", pkg.TestBpMissingNameThrowsError},

	{"TestBpMissingTemplatePathThrowsError", pkg.TestBpMissingTemplatePathThrowsError},

	{"TestGeneratedTestPlanContainsPlanInclude", pkg.TestGeneratedTestPlanContainsPlanInclude},

	{"TestGeneratedTestPlanContainsPlanName", pkg.TestGeneratedTestPlanContainsPlanName},

	{"TestGeneratedTestPlanContainsTemplatePath", pkg.TestGeneratedTestPlanContainsTemplatePath},

	{"TestPlanIncludeFileCopyRuleExists", pkg.TestPlanIncludeFileCopyRuleExists},

	{"TestTemplateFileCopyRuleExists", pkg.TestTemplateFileCopyRuleExists},

	{"TestValidBpMissingPlanIncludeDoesNotThrowError", pkg.TestValidBpMissingPlanIncludeDoesNotThrowError},

	{"TestValidBpMissingPlanIncludeGeneratesPlanXmlWithoutPlaceholders", pkg.TestValidBpMissingPlanIncludeGeneratesPlanXmlWithoutPlaceholders},

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
	return "android/soong/csuite"
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
