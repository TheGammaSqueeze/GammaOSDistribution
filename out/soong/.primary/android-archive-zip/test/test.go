
package main

import (
	"io"

	"os"

	"regexp"
	"testing"

	pkg "android/soong/third_party/zip"
)

var t = []testing.InternalTest{

	{"TestCopyFromZip64", pkg.TestCopyFromZip64},

	{"TestFileHeaderRoundTrip", pkg.TestFileHeaderRoundTrip},

	{"TestFileHeaderRoundTrip64", pkg.TestFileHeaderRoundTrip64},

	{"TestHeaderIgnoredSize", pkg.TestHeaderIgnoredSize},

	{"TestHeaderInvalidTagAndSize", pkg.TestHeaderInvalidTagAndSize},

	{"TestHeaderTooShort", pkg.TestHeaderTooShort},

	{"TestInvalidFiles", pkg.TestInvalidFiles},

	{"TestIssue10956", pkg.TestIssue10956},

	{"TestIssue10957", pkg.TestIssue10957},

	{"TestIssue11146", pkg.TestIssue11146},

	{"TestIssue12449", pkg.TestIssue12449},

	{"TestIssue8186", pkg.TestIssue8186},

	{"TestModTime", pkg.TestModTime},

	{"TestOver65kFiles", pkg.TestOver65kFiles},

	{"TestRLEBuffer", pkg.TestRLEBuffer},

	{"TestReader", pkg.TestReader},

	{"TestStripZip64Extras", pkg.TestStripZip64Extras},

	{"TestWriter", pkg.TestWriter},

	{"TestWriterFlush", pkg.TestWriterFlush},

	{"TestWriterOffset", pkg.TestWriterOffset},

	{"TestZeroLengthHeader", pkg.TestZeroLengthHeader},

	{"TestZip64", pkg.TestZip64},

	{"TestZip64EdgeCase", pkg.TestZip64EdgeCase},

	{"TestZip64P7ZipRecords", pkg.TestZip64P7ZipRecords},

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
	return "android/soong/third_party/zip"
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
