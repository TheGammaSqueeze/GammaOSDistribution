
package main

import (
	"io"

	"os"

	"regexp"
	"testing"

	pkg "android/soong/bazel"
)

var t = []testing.InternalTest{

	{"TestAqueryMultiArchGenrule", pkg.TestAqueryMultiArchGenrule},

	{"TestDepfiles", pkg.TestDepfiles},

	{"TestInvalidInputArtifactId", pkg.TestInvalidInputArtifactId},

	{"TestInvalidInputDepsetId", pkg.TestInvalidInputDepsetId},

	{"TestInvalidOutputId", pkg.TestInvalidOutputId},

	{"TestInvalidPathFragmentId", pkg.TestInvalidPathFragmentId},

	{"TestMultipleDepfiles", pkg.TestMultipleDepfiles},

	{"TestSubtractBazelLabelList", pkg.TestSubtractBazelLabelList},

	{"TestSubtractStrings", pkg.TestSubtractStrings},

	{"TestTransitiveInputDepsets", pkg.TestTransitiveInputDepsets},

	{"TestUniqueBazelLabelList", pkg.TestUniqueBazelLabelList},

	{"TestUniqueBazelLabels", pkg.TestUniqueBazelLabels},

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
	return "android/soong/bazel"
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
