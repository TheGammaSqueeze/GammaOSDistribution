
package main

import (
	"io"

	"regexp"
	"testing"

	pkg "android/soong/etc"
)

var t = []testing.InternalTest{

	{"TestPrebuiltDSPDirPath", pkg.TestPrebuiltDSPDirPath},

	{"TestPrebuiltEtcAndroidMk", pkg.TestPrebuiltEtcAndroidMk},

	{"TestPrebuiltEtcCannotSetRelativeInstallPathAndSubDir", pkg.TestPrebuiltEtcCannotSetRelativeInstallPathAndSubDir},

	{"TestPrebuiltEtcGlob", pkg.TestPrebuiltEtcGlob},

	{"TestPrebuiltEtcHost", pkg.TestPrebuiltEtcHost},

	{"TestPrebuiltEtcOutputPath", pkg.TestPrebuiltEtcOutputPath},

	{"TestPrebuiltEtcRelativeInstallPathInstallDirPath", pkg.TestPrebuiltEtcRelativeInstallPathInstallDirPath},

	{"TestPrebuiltEtcVariants", pkg.TestPrebuiltEtcVariants},

	{"TestPrebuiltFirmwareDirPath", pkg.TestPrebuiltFirmwareDirPath},

	{"TestPrebuiltFontInstallDirPath", pkg.TestPrebuiltFontInstallDirPath},

	{"TestPrebuiltRFSADirPath", pkg.TestPrebuiltRFSADirPath},

	{"TestPrebuiltRootInstallDirPath", pkg.TestPrebuiltRootInstallDirPath},

	{"TestPrebuiltRootInstallDirPathValidate", pkg.TestPrebuiltRootInstallDirPathValidate},

	{"TestPrebuiltUserShareHostInstallDirPath", pkg.TestPrebuiltUserShareHostInstallDirPath},

	{"TestPrebuiltUserShareInstallDirPath", pkg.TestPrebuiltUserShareInstallDirPath},

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
	return "android/soong/etc"
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
