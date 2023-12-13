
package main

import (
	"io"

	"regexp"
	"testing"

	pkg "android/soong/rust"
)

var t = []testing.InternalTest{

	{"TestAutoDeps", pkg.TestAutoDeps},

	{"TestBinaryFlags", pkg.TestBinaryFlags},

	{"TestBinaryLinkage", pkg.TestBinaryLinkage},

	{"TestBinaryPreferRlib", pkg.TestBinaryPreferRlib},

	{"TestBindgenDisallowedFlags", pkg.TestBindgenDisallowedFlags},

	{"TestCfgsToFlags", pkg.TestCfgsToFlags},

	{"TestClippy", pkg.TestClippy},

	{"TestCoverageDeps", pkg.TestCoverageDeps},

	{"TestCoverageFlags", pkg.TestCoverageFlags},

	{"TestDepsTracking", pkg.TestDepsTracking},

	{"TestDylibPreferDynamic", pkg.TestDylibPreferDynamic},

	{"TestEnforceSingleSourceFile", pkg.TestEnforceSingleSourceFile},

	{"TestFeaturesToFlags", pkg.TestFeaturesToFlags},

	{"TestForbiddenVendorLinkage", pkg.TestForbiddenVendorLinkage},

	{"TestHostToolPath", pkg.TestHostToolPath},

	{"TestImageVndkCfgFlag", pkg.TestImageVndkCfgFlag},

	{"TestInstallDir", pkg.TestInstallDir},

	{"TestLibrarySizes", pkg.TestLibrarySizes},

	{"TestLibraryVariants", pkg.TestLibraryVariants},

	{"TestLibstdLinkage", pkg.TestLibstdLinkage},

	{"TestLinkObjects", pkg.TestLinkObjects},

	{"TestLinkPathFromFilePath", pkg.TestLinkPathFromFilePath},

	{"TestLints", pkg.TestLints},

	{"TestMultilib", pkg.TestMultilib},

	{"TestNoStdlibs", pkg.TestNoStdlibs},

	{"TestProcMacroDeviceDeps", pkg.TestProcMacroDeviceDeps},

	{"TestProjectJsonBinary", pkg.TestProjectJsonBinary},

	{"TestProjectJsonBindGen", pkg.TestProjectJsonBindGen},

	{"TestProjectJsonDep", pkg.TestProjectJsonDep},

	{"TestProjectJsonFeature", pkg.TestProjectJsonFeature},

	{"TestProjectJsonMultiVersion", pkg.TestProjectJsonMultiVersion},

	{"TestRustBenchmark", pkg.TestRustBenchmark},

	{"TestRustBenchmarkLinkage", pkg.TestRustBenchmarkLinkage},

	{"TestRustBindgen", pkg.TestRustBindgen},

	{"TestRustBindgenCustomBindgen", pkg.TestRustBindgenCustomBindgen},

	{"TestRustBindgenStdVersions", pkg.TestRustBindgenStdVersions},

	{"TestRustFuzz", pkg.TestRustFuzz},

	{"TestRustGrpc", pkg.TestRustGrpc},

	{"TestRustProtoErrors", pkg.TestRustProtoErrors},

	{"TestRustProtobuf", pkg.TestRustProtobuf},

	{"TestRustTest", pkg.TestRustTest},

	{"TestRustTestLinkage", pkg.TestRustTestLinkage},

	{"TestSharedLibrary", pkg.TestSharedLibrary},

	{"TestSourceProviderCollision", pkg.TestSourceProviderCollision},

	{"TestSourceProviderDeps", pkg.TestSourceProviderDeps},

	{"TestSourceProviderRequiredFields", pkg.TestSourceProviderRequiredFields},

	{"TestSourceProviderTargetMismatch", pkg.TestSourceProviderTargetMismatch},

	{"TestStaticBinaryFlags", pkg.TestStaticBinaryFlags},

	{"TestStaticLibraryLinkage", pkg.TestStaticLibraryLinkage},

	{"TestStdDeviceLinkage", pkg.TestStdDeviceLinkage},

	{"TestStrippedBinary", pkg.TestStrippedBinary},

	{"TestStrippedLibrary", pkg.TestStrippedLibrary},

	{"TestValidateLibraryStem", pkg.TestValidateLibraryStem},

	{"TestVendorLinkage", pkg.TestVendorLinkage},

	{"TestVendorRamdiskLinkage", pkg.TestVendorRamdiskLinkage},

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
	return "android/soong/rust"
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
