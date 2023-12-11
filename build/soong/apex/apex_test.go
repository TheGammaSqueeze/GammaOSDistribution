// Copyright 2018 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package apex

import (
	"fmt"
	"os"
	"path"
	"path/filepath"
	"reflect"
	"regexp"
	"sort"
	"strconv"
	"strings"
	"testing"

	"github.com/google/blueprint/proptools"

	"android/soong/android"
	"android/soong/bpf"
	"android/soong/cc"
	"android/soong/dexpreopt"
	prebuilt_etc "android/soong/etc"
	"android/soong/java"
	"android/soong/rust"
	"android/soong/sh"
)

// names returns name list from white space separated string
func names(s string) (ns []string) {
	for _, n := range strings.Split(s, " ") {
		if len(n) > 0 {
			ns = append(ns, n)
		}
	}
	return
}

func testApexError(t *testing.T, pattern, bp string, preparers ...android.FixturePreparer) {
	t.Helper()
	android.GroupFixturePreparers(
		prepareForApexTest,
		android.GroupFixturePreparers(preparers...),
	).
		ExtendWithErrorHandler(android.FixtureExpectsAtLeastOneErrorMatchingPattern(pattern)).
		RunTestWithBp(t, bp)
}

func testApex(t *testing.T, bp string, preparers ...android.FixturePreparer) *android.TestContext {
	t.Helper()

	optionalBpPreparer := android.NullFixturePreparer
	if bp != "" {
		optionalBpPreparer = android.FixtureWithRootAndroidBp(bp)
	}

	result := android.GroupFixturePreparers(
		prepareForApexTest,
		android.GroupFixturePreparers(preparers...),
		optionalBpPreparer,
	).RunTest(t)

	return result.TestContext
}

func withFiles(files android.MockFS) android.FixturePreparer {
	return files.AddToFixture()
}

func withTargets(targets map[android.OsType][]android.Target) android.FixturePreparer {
	return android.FixtureModifyConfig(func(config android.Config) {
		for k, v := range targets {
			config.Targets[k] = v
		}
	})
}

// withNativeBridgeTargets sets configuration with targets including:
// - X86_64 (primary)
// - X86 (secondary)
// - Arm64 on X86_64 (native bridge)
// - Arm on X86 (native bridge)
var withNativeBridgeEnabled = android.FixtureModifyConfig(
	func(config android.Config) {
		config.Targets[android.Android] = []android.Target{
			{Os: android.Android, Arch: android.Arch{ArchType: android.X86_64, ArchVariant: "silvermont", Abi: []string{"arm64-v8a"}},
				NativeBridge: android.NativeBridgeDisabled, NativeBridgeHostArchName: "", NativeBridgeRelativePath: ""},
			{Os: android.Android, Arch: android.Arch{ArchType: android.X86, ArchVariant: "silvermont", Abi: []string{"armeabi-v7a"}},
				NativeBridge: android.NativeBridgeDisabled, NativeBridgeHostArchName: "", NativeBridgeRelativePath: ""},
			{Os: android.Android, Arch: android.Arch{ArchType: android.Arm64, ArchVariant: "armv8-a", Abi: []string{"arm64-v8a"}},
				NativeBridge: android.NativeBridgeEnabled, NativeBridgeHostArchName: "x86_64", NativeBridgeRelativePath: "arm64"},
			{Os: android.Android, Arch: android.Arch{ArchType: android.Arm, ArchVariant: "armv7-a-neon", Abi: []string{"armeabi-v7a"}},
				NativeBridge: android.NativeBridgeEnabled, NativeBridgeHostArchName: "x86", NativeBridgeRelativePath: "arm"},
		}
	},
)

func withManifestPackageNameOverrides(specs []string) android.FixturePreparer {
	return android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
		variables.ManifestPackageNameOverrides = specs
	})
}

var withBinder32bit = android.FixtureModifyProductVariables(
	func(variables android.FixtureProductVariables) {
		variables.Binder32bit = proptools.BoolPtr(true)
	},
)

var withUnbundledBuild = android.FixtureModifyProductVariables(
	func(variables android.FixtureProductVariables) {
		variables.Unbundled_build = proptools.BoolPtr(true)
	},
)

// Legacy preparer used for running tests within the apex package.
//
// This includes everything that was needed to run any test in the apex package prior to the
// introduction of the test fixtures. Tests that are being converted to use fixtures directly
// rather than through the testApex...() methods should avoid using this and instead use the
// various preparers directly, using android.GroupFixturePreparers(...) to group them when
// necessary.
//
// deprecated
var prepareForApexTest = android.GroupFixturePreparers(
	// General preparers in alphabetical order as test infrastructure will enforce correct
	// registration order.
	android.PrepareForTestWithAndroidBuildComponents,
	bpf.PrepareForTestWithBpf,
	cc.PrepareForTestWithCcBuildComponents,
	java.PrepareForTestWithJavaDefaultModules,
	prebuilt_etc.PrepareForTestWithPrebuiltEtc,
	rust.PrepareForTestWithRustDefaultModules,
	sh.PrepareForTestWithShBuildComponents,

	PrepareForTestWithApexBuildComponents,

	// Additional apex test specific preparers.
	android.FixtureAddTextFile("system/sepolicy/Android.bp", `
		filegroup {
			name: "myapex-file_contexts",
			srcs: [
				"apex/myapex-file_contexts",
			],
		}
	`),
	prepareForTestWithMyapex,
	android.FixtureMergeMockFs(android.MockFS{
		"a.java":                 nil,
		"PrebuiltAppFoo.apk":     nil,
		"PrebuiltAppFooPriv.apk": nil,
		"apex_manifest.json":     nil,
		"AndroidManifest.xml":    nil,
		"system/sepolicy/apex/myapex.updatable-file_contexts":         nil,
		"system/sepolicy/apex/myapex2-file_contexts":                  nil,
		"system/sepolicy/apex/otherapex-file_contexts":                nil,
		"system/sepolicy/apex/com.android.vndk-file_contexts":         nil,
		"system/sepolicy/apex/com.android.vndk.current-file_contexts": nil,
		"mylib.cpp":                                  nil,
		"mytest.cpp":                                 nil,
		"mytest1.cpp":                                nil,
		"mytest2.cpp":                                nil,
		"mytest3.cpp":                                nil,
		"myprebuilt":                                 nil,
		"my_include":                                 nil,
		"foo/bar/MyClass.java":                       nil,
		"prebuilt.jar":                               nil,
		"prebuilt.so":                                nil,
		"vendor/foo/devkeys/test.x509.pem":           nil,
		"vendor/foo/devkeys/test.pk8":                nil,
		"testkey.x509.pem":                           nil,
		"testkey.pk8":                                nil,
		"testkey.override.x509.pem":                  nil,
		"testkey.override.pk8":                       nil,
		"vendor/foo/devkeys/testkey.avbpubkey":       nil,
		"vendor/foo/devkeys/testkey.pem":             nil,
		"NOTICE":                                     nil,
		"custom_notice":                              nil,
		"custom_notice_for_static_lib":               nil,
		"testkey2.avbpubkey":                         nil,
		"testkey2.pem":                               nil,
		"myapex-arm64.apex":                          nil,
		"myapex-arm.apex":                            nil,
		"myapex.apks":                                nil,
		"frameworks/base/api/current.txt":            nil,
		"framework/aidl/a.aidl":                      nil,
		"build/make/core/proguard.flags":             nil,
		"build/make/core/proguard_basic_keeps.flags": nil,
		"dummy.txt":                                  nil,
		"baz":                                        nil,
		"bar/baz":                                    nil,
		"testdata/baz":                               nil,
		"AppSet.apks":                                nil,
		"foo.rs":                                     nil,
		"libfoo.jar":                                 nil,
		"libbar.jar":                                 nil,
	},
	),

	android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
		variables.DeviceVndkVersion = proptools.StringPtr("current")
		variables.DefaultAppCertificate = proptools.StringPtr("vendor/foo/devkeys/test")
		variables.CertificateOverrides = []string{"myapex_keytest:myapex.certificate.override"}
		variables.Platform_sdk_codename = proptools.StringPtr("Q")
		variables.Platform_sdk_final = proptools.BoolPtr(false)
		variables.Platform_version_active_codenames = []string{"Q"}
		variables.Platform_vndk_version = proptools.StringPtr("29")
	}),
)

var prepareForTestWithMyapex = android.FixtureMergeMockFs(android.MockFS{
	"system/sepolicy/apex/myapex-file_contexts": nil,
})

// ensure that 'result' equals 'expected'
func ensureEquals(t *testing.T, result string, expected string) {
	t.Helper()
	if result != expected {
		t.Errorf("%q != %q", expected, result)
	}
}

// ensure that 'result' contains 'expected'
func ensureContains(t *testing.T, result string, expected string) {
	t.Helper()
	if !strings.Contains(result, expected) {
		t.Errorf("%q is not found in %q", expected, result)
	}
}

// ensure that 'result' contains 'expected' exactly one time
func ensureContainsOnce(t *testing.T, result string, expected string) {
	t.Helper()
	count := strings.Count(result, expected)
	if count != 1 {
		t.Errorf("%q is found %d times (expected 1 time) in %q", expected, count, result)
	}
}

// ensures that 'result' does not contain 'notExpected'
func ensureNotContains(t *testing.T, result string, notExpected string) {
	t.Helper()
	if strings.Contains(result, notExpected) {
		t.Errorf("%q is found in %q", notExpected, result)
	}
}

func ensureMatches(t *testing.T, result string, expectedRex string) {
	ok, err := regexp.MatchString(expectedRex, result)
	if err != nil {
		t.Fatalf("regexp failure trying to match %s against `%s` expression: %s", result, expectedRex, err)
		return
	}
	if !ok {
		t.Errorf("%s does not match regular expession %s", result, expectedRex)
	}
}

func ensureListContains(t *testing.T, result []string, expected string) {
	t.Helper()
	if !android.InList(expected, result) {
		t.Errorf("%q is not found in %v", expected, result)
	}
}

func ensureListNotContains(t *testing.T, result []string, notExpected string) {
	t.Helper()
	if android.InList(notExpected, result) {
		t.Errorf("%q is found in %v", notExpected, result)
	}
}

func ensureListEmpty(t *testing.T, result []string) {
	t.Helper()
	if len(result) > 0 {
		t.Errorf("%q is expected to be empty", result)
	}
}

func ensureListNotEmpty(t *testing.T, result []string) {
	t.Helper()
	if len(result) == 0 {
		t.Errorf("%q is expected to be not empty", result)
	}
}

// Minimal test
func TestBasicApex(t *testing.T) {
	ctx := testApex(t, `
		apex_defaults {
			name: "myapex-defaults",
			manifest: ":myapex.manifest",
			androidManifest: ":myapex.androidmanifest",
			key: "myapex.key",
			binaries: ["foo.rust"],
			native_shared_libs: [
				"mylib",
				"libfoo.ffi",
			],
			rust_dyn_libs: ["libfoo.dylib.rust"],
			multilib: {
				both: {
					binaries: ["foo"],
				}
			},
			java_libs: [
				"myjar",
				"myjar_dex",
			],
			updatable: false,
		}

		apex {
			name: "myapex",
			defaults: ["myapex-defaults"],
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		filegroup {
			name: "myapex.manifest",
			srcs: ["apex_manifest.json"],
		}

		filegroup {
			name: "myapex.androidmanifest",
			srcs: ["AndroidManifest.xml"],
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: [
				"mylib2",
				"libbar.ffi",
			],
			system_shared_libs: [],
			stl: "none",
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		cc_binary {
			name: "foo",
			srcs: ["mylib.cpp"],
			compile_multilib: "both",
			multilib: {
					lib32: {
							suffix: "32",
					},
					lib64: {
							suffix: "64",
					},
			},
			symlinks: ["foo_link_"],
			symlink_preferred_arch: true,
			system_shared_libs: [],
			static_executable: true,
			stl: "none",
			apex_available: [ "myapex", "com.android.gki.*" ],
		}

		rust_binary {
			name: "foo.rust",
			srcs: ["foo.rs"],
			rlibs: ["libfoo.rlib.rust"],
			dylibs: ["libfoo.dylib.rust"],
			apex_available: ["myapex"],
		}

		rust_library_rlib {
			name: "libfoo.rlib.rust",
			srcs: ["foo.rs"],
			crate_name: "foo",
			apex_available: ["myapex"],
			shared_libs: ["libfoo.shared_from_rust"],
		}

		cc_library_shared {
			name: "libfoo.shared_from_rust",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: ["myapex"],
		}

		rust_library_dylib {
			name: "libfoo.dylib.rust",
			srcs: ["foo.rs"],
			crate_name: "foo",
			apex_available: ["myapex"],
		}

		rust_ffi_shared {
			name: "libfoo.ffi",
			srcs: ["foo.rs"],
			crate_name: "foo",
			apex_available: ["myapex"],
		}

		rust_ffi_shared {
			name: "libbar.ffi",
			srcs: ["foo.rs"],
			crate_name: "bar",
			apex_available: ["myapex"],
		}

		apex {
			name: "com.android.gki.fake",
			binaries: ["foo"],
			key: "myapex.key",
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}

		cc_library_shared {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			notice: "custom_notice",
			static_libs: ["libstatic"],
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		cc_prebuilt_library_shared {
			name: "mylib2",
			srcs: ["prebuilt.so"],
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
    }

		cc_library_static {
			name: "libstatic",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			notice: "custom_notice_for_static_lib",
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		java_library {
			name: "myjar",
			srcs: ["foo/bar/MyClass.java"],
			stem: "myjar_stem",
			sdk_version: "none",
			system_modules: "none",
			static_libs: ["myotherjar"],
			libs: ["mysharedjar"],
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		dex_import {
			name: "myjar_dex",
			jars: ["prebuilt.jar"],
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		java_library {
			name: "myotherjar",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		java_library {
			name: "mysharedjar",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
		}
	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")

	// Make sure that Android.mk is created
	ab := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, ab)
	var builder strings.Builder
	data.Custom(&builder, ab.BaseModuleName(), "TARGET_", "", data)

	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_MODULE := mylib.myapex\n")
	ensureNotContains(t, androidMk, "LOCAL_MODULE := mylib.com.android.myapex\n")

	optFlags := apexRule.Args["opt_flags"]
	ensureContains(t, optFlags, "--pubkey vendor/foo/devkeys/testkey.avbpubkey")
	// Ensure that the NOTICE output is being packaged as an asset.
	ensureContains(t, optFlags, "--assets_dir out/soong/.intermediates/myapex/android_common_myapex_image/NOTICE")

	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that main rule creates an output
	ensureContains(t, apexRule.Output.String(), "myapex.apex.unsigned")

	// Ensure that apex variant is created for the direct dep
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib"), "android_arm64_armv8-a_shared_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("myjar"), "android_common_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("myjar_dex"), "android_common_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("foo.rust"), "android_arm64_armv8-a_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("libfoo.ffi"), "android_arm64_armv8-a_shared_apex10000")

	// Ensure that apex variant is created for the indirect dep
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib2"), "android_arm64_armv8-a_shared_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("myotherjar"), "android_common_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("libfoo.rlib.rust"), "android_arm64_armv8-a_rlib_dylib-std_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("libfoo.dylib.rust"), "android_arm64_armv8-a_dylib_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("libbar.ffi"), "android_arm64_armv8-a_shared_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("libfoo.shared_from_rust"), "android_arm64_armv8-a_shared_apex10000")

	// Ensure that both direct and indirect deps are copied into apex
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.so")
	ensureContains(t, copyCmds, "image.apex/lib64/mylib2.so")
	ensureContains(t, copyCmds, "image.apex/javalib/myjar_stem.jar")
	ensureContains(t, copyCmds, "image.apex/javalib/myjar_dex.jar")
	ensureContains(t, copyCmds, "image.apex/lib64/libfoo.dylib.rust.dylib.so")
	ensureContains(t, copyCmds, "image.apex/lib64/libfoo.ffi.so")
	ensureContains(t, copyCmds, "image.apex/lib64/libbar.ffi.so")
	ensureContains(t, copyCmds, "image.apex/lib64/libfoo.shared_from_rust.so")
	// .. but not for java libs
	ensureNotContains(t, copyCmds, "image.apex/javalib/myotherjar.jar")
	ensureNotContains(t, copyCmds, "image.apex/javalib/msharedjar.jar")

	// Ensure that the platform variant ends with _shared or _common
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib"), "android_arm64_armv8-a_shared")
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib2"), "android_arm64_armv8-a_shared")
	ensureListContains(t, ctx.ModuleVariantsForTests("myjar"), "android_common")
	ensureListContains(t, ctx.ModuleVariantsForTests("myotherjar"), "android_common")
	ensureListContains(t, ctx.ModuleVariantsForTests("mysharedjar"), "android_common")

	// Ensure that dynamic dependency to java libs are not included
	ensureListNotContains(t, ctx.ModuleVariantsForTests("mysharedjar"), "android_common_myapex")

	// Ensure that all symlinks are present.
	found_foo_link_64 := false
	found_foo := false
	for _, cmd := range strings.Split(copyCmds, " && ") {
		if strings.HasPrefix(cmd, "ln -sfn foo64") {
			if strings.HasSuffix(cmd, "bin/foo") {
				found_foo = true
			} else if strings.HasSuffix(cmd, "bin/foo_link_64") {
				found_foo_link_64 = true
			}
		}
	}
	good := found_foo && found_foo_link_64
	if !good {
		t.Errorf("Could not find all expected symlinks! foo: %t, foo_link_64: %t. Command was %s", found_foo, found_foo_link_64, copyCmds)
	}

	mergeNoticesRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("mergeNoticesRule")
	noticeInputs := mergeNoticesRule.Inputs.Strings()
	if len(noticeInputs) != 3 {
		t.Errorf("number of input notice files: expected = 3, actual = %q", len(noticeInputs))
	}
	ensureListContains(t, noticeInputs, "NOTICE")
	ensureListContains(t, noticeInputs, "custom_notice")
	ensureListContains(t, noticeInputs, "custom_notice_for_static_lib")

	fullDepsInfo := strings.Split(ctx.ModuleForTests("myapex", "android_common_myapex_image").Output("depsinfo/fulllist.txt").Args["content"], "\\n")
	ensureListContains(t, fullDepsInfo, "  myjar(minSdkVersion:(no version)) <- myapex")
	ensureListContains(t, fullDepsInfo, "  mylib2(minSdkVersion:(no version)) <- mylib")
	ensureListContains(t, fullDepsInfo, "  myotherjar(minSdkVersion:(no version)) <- myjar")
	ensureListContains(t, fullDepsInfo, "  mysharedjar(minSdkVersion:(no version)) (external) <- myjar")

	flatDepsInfo := strings.Split(ctx.ModuleForTests("myapex", "android_common_myapex_image").Output("depsinfo/flatlist.txt").Args["content"], "\\n")
	ensureListContains(t, flatDepsInfo, "myjar(minSdkVersion:(no version))")
	ensureListContains(t, flatDepsInfo, "mylib2(minSdkVersion:(no version))")
	ensureListContains(t, flatDepsInfo, "myotherjar(minSdkVersion:(no version))")
	ensureListContains(t, flatDepsInfo, "mysharedjar(minSdkVersion:(no version)) (external)")
}

func TestDefaults(t *testing.T) {
	ctx := testApex(t, `
		apex_defaults {
			name: "myapex-defaults",
			key: "myapex.key",
			prebuilts: ["myetc"],
			native_shared_libs: ["mylib"],
			java_libs: ["myjar"],
			apps: ["AppFoo"],
			rros: ["rro"],
			bpfs: ["bpf"],
			updatable: false,
		}

		prebuilt_etc {
			name: "myetc",
			src: "myprebuilt",
		}

		apex {
			name: "myapex",
			defaults: ["myapex-defaults"],
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		java_library {
			name: "myjar",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			apex_available: [ "myapex" ],
		}

		android_app {
			name: "AppFoo",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			apex_available: [ "myapex" ],
		}

		runtime_resource_overlay {
			name: "rro",
			theme: "blue",
		}

		bpf {
			name: "bpf",
			srcs: ["bpf.c", "bpf2.c"],
		}

	`)
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"etc/myetc",
		"javalib/myjar.jar",
		"lib64/mylib.so",
		"app/AppFoo/AppFoo.apk",
		"overlay/blue/rro.apk",
		"etc/bpf/bpf.o",
		"etc/bpf/bpf2.o",
	})
}

func TestApexManifest(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`)

	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	args := module.Rule("apexRule").Args
	if manifest := args["manifest"]; manifest != module.Output("apex_manifest.pb").Output.String() {
		t.Error("manifest should be apex_manifest.pb, but " + manifest)
	}
}

func TestBasicZipApex(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			payload_type: "zip",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["mylib2"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}
	`)

	zipApexRule := ctx.ModuleForTests("myapex", "android_common_myapex_zip").Rule("zipApexRule")
	copyCmds := zipApexRule.Args["copy_commands"]

	// Ensure that main rule creates an output
	ensureContains(t, zipApexRule.Output.String(), "myapex.zipapex.unsigned")

	// Ensure that APEX variant is created for the direct dep
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib"), "android_arm64_armv8-a_shared_apex10000")

	// Ensure that APEX variant is created for the indirect dep
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib2"), "android_arm64_armv8-a_shared_apex10000")

	// Ensure that both direct and indirect deps are copied into apex
	ensureContains(t, copyCmds, "image.zipapex/lib64/mylib.so")
	ensureContains(t, copyCmds, "image.zipapex/lib64/mylib2.so")
}

func TestApexWithStubs(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib", "mylib3"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["mylib2", "mylib3"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			cflags: ["-include mylib.h"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["1", "2", "3"],
			},
		}

		cc_library {
			name: "mylib3",
			srcs: ["mylib.cpp"],
			shared_libs: ["mylib4"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["10", "11", "12"],
			},
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "mylib4",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}
	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that direct non-stubs dep is always included
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.so")

	// Ensure that indirect stubs dep is not included
	ensureNotContains(t, copyCmds, "image.apex/lib64/mylib2.so")

	// Ensure that direct stubs dep is included
	ensureContains(t, copyCmds, "image.apex/lib64/mylib3.so")

	mylibLdFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_shared_apex10000").Rule("ld").Args["libFlags"]

	// Ensure that mylib is linking with the latest version of stubs for mylib2
	ensureContains(t, mylibLdFlags, "mylib2/android_arm64_armv8-a_shared_current/mylib2.so")
	// ... and not linking to the non-stub (impl) variant of mylib2
	ensureNotContains(t, mylibLdFlags, "mylib2/android_arm64_armv8-a_shared/mylib2.so")

	// Ensure that mylib is linking with the non-stub (impl) of mylib3 (because mylib3 is in the same apex)
	ensureContains(t, mylibLdFlags, "mylib3/android_arm64_armv8-a_shared_apex10000/mylib3.so")
	// .. and not linking to the stubs variant of mylib3
	ensureNotContains(t, mylibLdFlags, "mylib3/android_arm64_armv8-a_shared_12/mylib3.so")

	// Ensure that stubs libs are built without -include flags
	mylib2Cflags := ctx.ModuleForTests("mylib2", "android_arm64_armv8-a_static").Rule("cc").Args["cFlags"]
	ensureNotContains(t, mylib2Cflags, "-include ")

	// Ensure that genstub is invoked with --apex
	ensureContains(t, "--apex", ctx.ModuleForTests("mylib2", "android_arm64_armv8-a_shared_3").Rule("genStubSrc").Args["flags"])

	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"lib64/mylib.so",
		"lib64/mylib3.so",
		"lib64/mylib4.so",
	})
}

func TestApexWithStubsWithMinSdkVersion(t *testing.T) {
	t.Parallel()
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib", "mylib3"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["mylib2", "mylib3"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
			min_sdk_version: "28",
		}

		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			cflags: ["-include mylib.h"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["28", "29", "30", "current"],
			},
			min_sdk_version: "28",
		}

		cc_library {
			name: "mylib3",
			srcs: ["mylib.cpp"],
			shared_libs: ["mylib4"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["28", "29", "30", "current"],
			},
			apex_available: [ "myapex" ],
			min_sdk_version: "28",
		}

		cc_library {
			name: "mylib4",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
			min_sdk_version: "28",
		}
	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that direct non-stubs dep is always included
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.so")

	// Ensure that indirect stubs dep is not included
	ensureNotContains(t, copyCmds, "image.apex/lib64/mylib2.so")

	// Ensure that direct stubs dep is included
	ensureContains(t, copyCmds, "image.apex/lib64/mylib3.so")

	mylibLdFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_shared_apex29").Rule("ld").Args["libFlags"]

	// Ensure that mylib is linking with the latest version of stub for mylib2
	ensureContains(t, mylibLdFlags, "mylib2/android_arm64_armv8-a_shared_current/mylib2.so")
	// ... and not linking to the non-stub (impl) variant of mylib2
	ensureNotContains(t, mylibLdFlags, "mylib2/android_arm64_armv8-a_shared/mylib2.so")

	// Ensure that mylib is linking with the non-stub (impl) of mylib3 (because mylib3 is in the same apex)
	ensureContains(t, mylibLdFlags, "mylib3/android_arm64_armv8-a_shared_apex29/mylib3.so")
	// .. and not linking to the stubs variant of mylib3
	ensureNotContains(t, mylibLdFlags, "mylib3/android_arm64_armv8-a_shared_29/mylib3.so")

	// Ensure that stubs libs are built without -include flags
	mylib2Cflags := ctx.ModuleForTests("mylib2", "android_arm64_armv8-a_shared_29").Rule("cc").Args["cFlags"]
	ensureNotContains(t, mylib2Cflags, "-include ")

	// Ensure that genstub is invoked with --apex
	ensureContains(t, "--apex", ctx.ModuleForTests("mylib2", "android_arm64_armv8-a_shared_29").Rule("genStubSrc").Args["flags"])

	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"lib64/mylib.so",
		"lib64/mylib3.so",
		"lib64/mylib4.so",
	})
}

func TestApex_PlatformUsesLatestStubFromApex(t *testing.T) {
	t.Parallel()
	//   myapex (Z)
	//      mylib -----------------.
	//                             |
	//   otherapex (29)            |
	//      libstub's versions: 29 Z current
	//                                  |
	//   <platform>                     |
	//      libplatform ----------------'
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			min_sdk_version: "Z", // non-final
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["libstub"],
			apex_available: ["myapex"],
			min_sdk_version: "Z",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		apex {
			name: "otherapex",
			key: "myapex.key",
			native_shared_libs: ["libstub"],
			min_sdk_version: "29",
		}

		cc_library {
			name: "libstub",
			srcs: ["mylib.cpp"],
			stubs: {
				versions: ["29", "Z", "current"],
			},
			apex_available: ["otherapex"],
			min_sdk_version: "29",
		}

		// platform module depending on libstub from otherapex should use the latest stub("current")
		cc_library {
			name: "libplatform",
			srcs: ["mylib.cpp"],
			shared_libs: ["libstub"],
		}
	`,
		android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
			variables.Platform_sdk_codename = proptools.StringPtr("Z")
			variables.Platform_sdk_final = proptools.BoolPtr(false)
			variables.Platform_version_active_codenames = []string{"Z"}
		}),
	)

	// Ensure that mylib from myapex is built against the latest stub (current)
	mylibCflags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_static_apex10000").Rule("cc").Args["cFlags"]
	ensureContains(t, mylibCflags, "-D__LIBSTUB_API__=10000 ")
	mylibLdflags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_shared_apex10000").Rule("ld").Args["libFlags"]
	ensureContains(t, mylibLdflags, "libstub/android_arm64_armv8-a_shared_current/libstub.so ")

	// Ensure that libplatform is built against latest stub ("current") of mylib3 from the apex
	libplatformCflags := ctx.ModuleForTests("libplatform", "android_arm64_armv8-a_static").Rule("cc").Args["cFlags"]
	ensureContains(t, libplatformCflags, "-D__LIBSTUB_API__=10000 ") // "current" maps to 10000
	libplatformLdflags := ctx.ModuleForTests("libplatform", "android_arm64_armv8-a_shared").Rule("ld").Args["libFlags"]
	ensureContains(t, libplatformLdflags, "libstub/android_arm64_armv8-a_shared_current/libstub.so ")
}

func TestApexWithExplicitStubsDependency(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex2",
			key: "myapex2.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex2.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["libfoo#10"],
			static_libs: ["libbaz"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex2" ],
		}

		cc_library {
			name: "libfoo",
			srcs: ["mylib.cpp"],
			shared_libs: ["libbar"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["10", "20", "30"],
			},
		}

		cc_library {
			name: "libbar",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
		}

		cc_library_static {
			name: "libbaz",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex2" ],
		}

	`)

	apexRule := ctx.ModuleForTests("myapex2", "android_common_myapex2_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that direct non-stubs dep is always included
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.so")

	// Ensure that indirect stubs dep is not included
	ensureNotContains(t, copyCmds, "image.apex/lib64/libfoo.so")

	// Ensure that dependency of stubs is not included
	ensureNotContains(t, copyCmds, "image.apex/lib64/libbar.so")

	mylibLdFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_shared_apex10000").Rule("ld").Args["libFlags"]

	// Ensure that mylib is linking with version 10 of libfoo
	ensureContains(t, mylibLdFlags, "libfoo/android_arm64_armv8-a_shared_10/libfoo.so")
	// ... and not linking to the non-stub (impl) variant of libfoo
	ensureNotContains(t, mylibLdFlags, "libfoo/android_arm64_armv8-a_shared/libfoo.so")

	libFooStubsLdFlags := ctx.ModuleForTests("libfoo", "android_arm64_armv8-a_shared_10").Rule("ld").Args["libFlags"]

	// Ensure that libfoo stubs is not linking to libbar (since it is a stubs)
	ensureNotContains(t, libFooStubsLdFlags, "libbar.so")

	fullDepsInfo := strings.Split(ctx.ModuleForTests("myapex2", "android_common_myapex2_image").Output("depsinfo/fulllist.txt").Args["content"], "\\n")
	ensureListContains(t, fullDepsInfo, "  libfoo(minSdkVersion:(no version)) (external) <- mylib")

	flatDepsInfo := strings.Split(ctx.ModuleForTests("myapex2", "android_common_myapex2_image").Output("depsinfo/flatlist.txt").Args["content"], "\\n")
	ensureListContains(t, flatDepsInfo, "libfoo(minSdkVersion:(no version)) (external)")
}

func TestApexWithRuntimeLibsDependency(t *testing.T) {
	/*
		myapex
		  |
		  v   (runtime_libs)
		mylib ------+------> libfoo [provides stub]
			    |
			    `------> libbar
	*/
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			runtime_libs: ["libfoo", "libbar"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "libfoo",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["10", "20", "30"],
			},
		}

		cc_library {
			name: "libbar",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that direct non-stubs dep is always included
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.so")

	// Ensure that indirect stubs dep is not included
	ensureNotContains(t, copyCmds, "image.apex/lib64/libfoo.so")

	// Ensure that runtime_libs dep in included
	ensureContains(t, copyCmds, "image.apex/lib64/libbar.so")

	apexManifestRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexManifestRule")
	ensureListEmpty(t, names(apexManifestRule.Args["provideNativeLibs"]))
	ensureListContains(t, names(apexManifestRule.Args["requireNativeLibs"]), "libfoo.so")

}

var prepareForTestOfRuntimeApexWithHwasan = android.GroupFixturePreparers(
	cc.PrepareForTestWithCcBuildComponents,
	PrepareForTestWithApexBuildComponents,
	android.FixtureAddTextFile("bionic/apex/Android.bp", `
		apex {
			name: "com.android.runtime",
			key: "com.android.runtime.key",
			native_shared_libs: ["libc"],
			updatable: false,
		}

		apex_key {
			name: "com.android.runtime.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`),
	android.FixtureAddFile("system/sepolicy/apex/com.android.runtime-file_contexts", nil),
)

func TestRuntimeApexShouldInstallHwasanIfLibcDependsOnIt(t *testing.T) {
	result := android.GroupFixturePreparers(prepareForTestOfRuntimeApexWithHwasan).RunTestWithBp(t, `
		cc_library {
			name: "libc",
			no_libcrt: true,
			nocrt: true,
			stl: "none",
			system_shared_libs: [],
			stubs: { versions: ["1"] },
			apex_available: ["com.android.runtime"],

			sanitize: {
				hwaddress: true,
			}
		}

		cc_prebuilt_library_shared {
			name: "libclang_rt.hwasan-aarch64-android",
			no_libcrt: true,
			nocrt: true,
			stl: "none",
			system_shared_libs: [],
			srcs: [""],
			stubs: { versions: ["1"] },

			sanitize: {
				never: true,
			},
		}	`)
	ctx := result.TestContext

	ensureExactContents(t, ctx, "com.android.runtime", "android_common_hwasan_com.android.runtime_image", []string{
		"lib64/bionic/libc.so",
		"lib64/bionic/libclang_rt.hwasan-aarch64-android.so",
	})

	hwasan := ctx.ModuleForTests("libclang_rt.hwasan-aarch64-android", "android_arm64_armv8-a_shared")

	installed := hwasan.Description("install libclang_rt.hwasan")
	ensureContains(t, installed.Output.String(), "/system/lib64/bootstrap/libclang_rt.hwasan-aarch64-android.so")

	symlink := hwasan.Description("install symlink libclang_rt.hwasan")
	ensureEquals(t, symlink.Args["fromPath"], "/apex/com.android.runtime/lib64/bionic/libclang_rt.hwasan-aarch64-android.so")
	ensureContains(t, symlink.Output.String(), "/system/lib64/libclang_rt.hwasan-aarch64-android.so")
}

func TestRuntimeApexShouldInstallHwasanIfHwaddressSanitized(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForTestOfRuntimeApexWithHwasan,
		android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
			variables.SanitizeDevice = []string{"hwaddress"}
		}),
	).RunTestWithBp(t, `
		cc_library {
			name: "libc",
			no_libcrt: true,
			nocrt: true,
			stl: "none",
			system_shared_libs: [],
			stubs: { versions: ["1"] },
			apex_available: ["com.android.runtime"],
		}

		cc_prebuilt_library_shared {
			name: "libclang_rt.hwasan-aarch64-android",
			no_libcrt: true,
			nocrt: true,
			stl: "none",
			system_shared_libs: [],
			srcs: [""],
			stubs: { versions: ["1"] },

			sanitize: {
				never: true,
			},
		}
		`)
	ctx := result.TestContext

	ensureExactContents(t, ctx, "com.android.runtime", "android_common_hwasan_com.android.runtime_image", []string{
		"lib64/bionic/libc.so",
		"lib64/bionic/libclang_rt.hwasan-aarch64-android.so",
	})

	hwasan := ctx.ModuleForTests("libclang_rt.hwasan-aarch64-android", "android_arm64_armv8-a_shared")

	installed := hwasan.Description("install libclang_rt.hwasan")
	ensureContains(t, installed.Output.String(), "/system/lib64/bootstrap/libclang_rt.hwasan-aarch64-android.so")

	symlink := hwasan.Description("install symlink libclang_rt.hwasan")
	ensureEquals(t, symlink.Args["fromPath"], "/apex/com.android.runtime/lib64/bionic/libclang_rt.hwasan-aarch64-android.so")
	ensureContains(t, symlink.Output.String(), "/system/lib64/libclang_rt.hwasan-aarch64-android.so")
}

func TestApexDependsOnLLNDKTransitively(t *testing.T) {
	testcases := []struct {
		name          string
		minSdkVersion string
		apexVariant   string
		shouldLink    string
		shouldNotLink []string
	}{
		{
			name:          "unspecified version links to the latest",
			minSdkVersion: "",
			apexVariant:   "apex10000",
			shouldLink:    "current",
			shouldNotLink: []string{"29", "30"},
		},
		{
			name:          "always use the latest",
			minSdkVersion: "min_sdk_version: \"29\",",
			apexVariant:   "apex29",
			shouldLink:    "current",
			shouldNotLink: []string{"29", "30"},
		},
	}
	for _, tc := range testcases {
		t.Run(tc.name, func(t *testing.T) {
			ctx := testApex(t, `
			apex {
				name: "myapex",
				key: "myapex.key",
				native_shared_libs: ["mylib"],
				updatable: false,
				`+tc.minSdkVersion+`
			}

			apex_key {
				name: "myapex.key",
				public_key: "testkey.avbpubkey",
				private_key: "testkey.pem",
			}

			cc_library {
				name: "mylib",
				srcs: ["mylib.cpp"],
				vendor_available: true,
				shared_libs: ["libbar"],
				system_shared_libs: [],
				stl: "none",
				apex_available: [ "myapex" ],
				min_sdk_version: "29",
			}

			cc_library {
				name: "libbar",
				srcs: ["mylib.cpp"],
				system_shared_libs: [],
				stl: "none",
				stubs: { versions: ["29","30"] },
				llndk: {
					symbol_file: "libbar.map.txt",
				}
			}
			`,
				withUnbundledBuild,
			)

			// Ensure that LLNDK dep is not included
			ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
				"lib64/mylib.so",
			})

			// Ensure that LLNDK dep is required
			apexManifestRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexManifestRule")
			ensureListEmpty(t, names(apexManifestRule.Args["provideNativeLibs"]))
			ensureListContains(t, names(apexManifestRule.Args["requireNativeLibs"]), "libbar.so")

			mylibLdFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_shared_"+tc.apexVariant).Rule("ld").Args["libFlags"]
			ensureContains(t, mylibLdFlags, "libbar/android_arm64_armv8-a_shared_"+tc.shouldLink+"/libbar.so")
			for _, ver := range tc.shouldNotLink {
				ensureNotContains(t, mylibLdFlags, "libbar/android_arm64_armv8-a_shared_"+ver+"/libbar.so")
			}

			mylibCFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_static_"+tc.apexVariant).Rule("cc").Args["cFlags"]
			ver := tc.shouldLink
			if tc.shouldLink == "current" {
				ver = strconv.Itoa(android.FutureApiLevelInt)
			}
			ensureContains(t, mylibCFlags, "__LIBBAR_API__="+ver)
		})
	}
}

func TestApexWithSystemLibsStubs(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib", "mylib_shared", "libdl", "libm"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: ["libc", "libm"],
			shared_libs: ["libdl#27"],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library_shared {
			name: "mylib_shared",
			srcs: ["mylib.cpp"],
			shared_libs: ["libdl#27"],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "libBootstrap",
			srcs: ["mylib.cpp"],
			stl: "none",
			bootstrap: true,
		}
	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that mylib, libm, libdl are included.
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.so")
	ensureContains(t, copyCmds, "image.apex/lib64/bionic/libm.so")
	ensureContains(t, copyCmds, "image.apex/lib64/bionic/libdl.so")

	// Ensure that libc is not included (since it has stubs and not listed in native_shared_libs)
	ensureNotContains(t, copyCmds, "image.apex/lib64/bionic/libc.so")

	mylibLdFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_shared_apex10000").Rule("ld").Args["libFlags"]
	mylibCFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_static_apex10000").Rule("cc").Args["cFlags"]
	mylibSharedCFlags := ctx.ModuleForTests("mylib_shared", "android_arm64_armv8-a_shared_apex10000").Rule("cc").Args["cFlags"]

	// For dependency to libc
	// Ensure that mylib is linking with the latest version of stubs
	ensureContains(t, mylibLdFlags, "libc/android_arm64_armv8-a_shared_current/libc.so")
	// ... and not linking to the non-stub (impl) variant
	ensureNotContains(t, mylibLdFlags, "libc/android_arm64_armv8-a_shared/libc.so")
	// ... Cflags from stub is correctly exported to mylib
	ensureContains(t, mylibCFlags, "__LIBC_API__=10000")
	ensureContains(t, mylibSharedCFlags, "__LIBC_API__=10000")

	// For dependency to libm
	// Ensure that mylib is linking with the non-stub (impl) variant
	ensureContains(t, mylibLdFlags, "libm/android_arm64_armv8-a_shared_apex10000/libm.so")
	// ... and not linking to the stub variant
	ensureNotContains(t, mylibLdFlags, "libm/android_arm64_armv8-a_shared_29/libm.so")
	// ... and is not compiling with the stub
	ensureNotContains(t, mylibCFlags, "__LIBM_API__=29")
	ensureNotContains(t, mylibSharedCFlags, "__LIBM_API__=29")

	// For dependency to libdl
	// Ensure that mylib is linking with the specified version of stubs
	ensureContains(t, mylibLdFlags, "libdl/android_arm64_armv8-a_shared_27/libdl.so")
	// ... and not linking to the other versions of stubs
	ensureNotContains(t, mylibLdFlags, "libdl/android_arm64_armv8-a_shared_28/libdl.so")
	ensureNotContains(t, mylibLdFlags, "libdl/android_arm64_armv8-a_shared_29/libdl.so")
	// ... and not linking to the non-stub (impl) variant
	ensureNotContains(t, mylibLdFlags, "libdl/android_arm64_armv8-a_shared_apex10000/libdl.so")
	// ... Cflags from stub is correctly exported to mylib
	ensureContains(t, mylibCFlags, "__LIBDL_API__=27")
	ensureContains(t, mylibSharedCFlags, "__LIBDL_API__=27")

	// Ensure that libBootstrap is depending on the platform variant of bionic libs
	libFlags := ctx.ModuleForTests("libBootstrap", "android_arm64_armv8-a_shared").Rule("ld").Args["libFlags"]
	ensureContains(t, libFlags, "libc/android_arm64_armv8-a_shared/libc.so")
	ensureContains(t, libFlags, "libm/android_arm64_armv8-a_shared/libm.so")
	ensureContains(t, libFlags, "libdl/android_arm64_armv8-a_shared/libdl.so")
}

func TestApexMinSdkVersion_NativeModulesShouldBeBuiltAgainstStubs(t *testing.T) {
	// there are three links between liba --> libz.
	// 1) myapex -> libx -> liba -> libz    : this should be #30 link
	// 2) otherapex -> liby -> liba -> libz : this should be #30 link
	// 3) (platform) -> liba -> libz        : this should be non-stub link
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libx"],
			min_sdk_version: "29",
		}

		apex {
			name: "otherapex",
			key: "myapex.key",
			native_shared_libs: ["liby"],
			min_sdk_version: "30",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libx",
			shared_libs: ["liba"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
			min_sdk_version: "29",
		}

		cc_library {
			name: "liby",
			shared_libs: ["liba"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "otherapex" ],
			min_sdk_version: "29",
		}

		cc_library {
			name: "liba",
			shared_libs: ["libz"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"//apex_available:anyapex",
				"//apex_available:platform",
			],
			min_sdk_version: "29",
		}

		cc_library {
			name: "libz",
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["28", "30"],
			},
		}
	`)

	expectLink := func(from, from_variant, to, to_variant string) {
		ldArgs := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld").Args["libFlags"]
		ensureContains(t, ldArgs, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectNoLink := func(from, from_variant, to, to_variant string) {
		ldArgs := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld").Args["libFlags"]
		ensureNotContains(t, ldArgs, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	// platform liba is linked to non-stub version
	expectLink("liba", "shared", "libz", "shared")
	// liba in myapex is linked to current
	expectLink("liba", "shared_apex29", "libz", "shared_current")
	expectNoLink("liba", "shared_apex29", "libz", "shared_30")
	expectNoLink("liba", "shared_apex29", "libz", "shared_28")
	expectNoLink("liba", "shared_apex29", "libz", "shared")
	// liba in otherapex is linked to current
	expectLink("liba", "shared_apex30", "libz", "shared_current")
	expectNoLink("liba", "shared_apex30", "libz", "shared_30")
	expectNoLink("liba", "shared_apex30", "libz", "shared_28")
	expectNoLink("liba", "shared_apex30", "libz", "shared")
}

func TestApexMinSdkVersion_SupportsCodeNames(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libx"],
			min_sdk_version: "R",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libx",
			shared_libs: ["libz"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
			min_sdk_version: "R",
		}

		cc_library {
			name: "libz",
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["29", "R"],
			},
		}
	`,
		android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
			variables.Platform_version_active_codenames = []string{"R"}
		}),
	)

	expectLink := func(from, from_variant, to, to_variant string) {
		ldArgs := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld").Args["libFlags"]
		ensureContains(t, ldArgs, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectNoLink := func(from, from_variant, to, to_variant string) {
		ldArgs := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld").Args["libFlags"]
		ensureNotContains(t, ldArgs, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectLink("libx", "shared_apex10000", "libz", "shared_current")
	expectNoLink("libx", "shared_apex10000", "libz", "shared_R")
	expectNoLink("libx", "shared_apex10000", "libz", "shared_29")
	expectNoLink("libx", "shared_apex10000", "libz", "shared")
}

func TestApexMinSdkVersion_DefaultsToLatest(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libx"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libx",
			shared_libs: ["libz"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "libz",
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["1", "2"],
			},
		}
	`)

	expectLink := func(from, from_variant, to, to_variant string) {
		ldArgs := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld").Args["libFlags"]
		ensureContains(t, ldArgs, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectNoLink := func(from, from_variant, to, to_variant string) {
		ldArgs := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld").Args["libFlags"]
		ensureNotContains(t, ldArgs, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectLink("libx", "shared_apex10000", "libz", "shared_current")
	expectNoLink("libx", "shared_apex10000", "libz", "shared_1")
	expectNoLink("libx", "shared_apex10000", "libz", "shared_2")
	expectNoLink("libx", "shared_apex10000", "libz", "shared")
}

func TestPlatformUsesLatestStubsFromApexes(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libx"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libx",
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
			stubs: {
				versions: ["1", "2"],
			},
		}

		cc_library {
			name: "libz",
			shared_libs: ["libx"],
			system_shared_libs: [],
			stl: "none",
		}
	`)

	expectLink := func(from, from_variant, to, to_variant string) {
		t.Helper()
		ldArgs := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld").Args["libFlags"]
		ensureContains(t, ldArgs, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectNoLink := func(from, from_variant, to, to_variant string) {
		t.Helper()
		ldArgs := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld").Args["libFlags"]
		ensureNotContains(t, ldArgs, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectLink("libz", "shared", "libx", "shared_current")
	expectNoLink("libz", "shared", "libx", "shared_2")
	expectNoLink("libz", "shared", "libz", "shared_1")
	expectNoLink("libz", "shared", "libz", "shared")
}

var prepareForTestWithSantitizeHwaddress = android.FixtureModifyProductVariables(
	func(variables android.FixtureProductVariables) {
		variables.SanitizeDevice = []string{"hwaddress"}
	},
)

func TestQApexesUseLatestStubsInBundledBuildsAndHWASAN(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libx"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libx",
			shared_libs: ["libbar"],
			apex_available: [ "myapex" ],
			min_sdk_version: "29",
		}

		cc_library {
			name: "libbar",
			stubs: {
				versions: ["29", "30"],
			},
		}
	`,
		prepareForTestWithSantitizeHwaddress,
	)
	expectLink := func(from, from_variant, to, to_variant string) {
		ld := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld")
		libFlags := ld.Args["libFlags"]
		ensureContains(t, libFlags, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectLink("libx", "shared_hwasan_apex29", "libbar", "shared_current")
}

func TestQTargetApexUsesStaticUnwinder(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libx"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libx",
			apex_available: [ "myapex" ],
			min_sdk_version: "29",
		}
	`)

	// ensure apex variant of c++ is linked with static unwinder
	cm := ctx.ModuleForTests("libc++", "android_arm64_armv8-a_shared_apex29").Module().(*cc.Module)
	ensureListContains(t, cm.Properties.AndroidMkStaticLibs, "libunwind")
	// note that platform variant is not.
	cm = ctx.ModuleForTests("libc++", "android_arm64_armv8-a_shared").Module().(*cc.Module)
	ensureListNotContains(t, cm.Properties.AndroidMkStaticLibs, "libunwind")
}

func TestApexMinSdkVersion_ErrorIfIncompatibleVersion(t *testing.T) {
	testApexError(t, `module "mylib".*: should support min_sdk_version\(29\)`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
			],
			min_sdk_version: "30",
		}
	`)

	testApexError(t, `module "libfoo.ffi".*: should support min_sdk_version\(29\)`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libfoo.ffi"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		rust_ffi_shared {
			name: "libfoo.ffi",
			srcs: ["foo.rs"],
			crate_name: "foo",
			apex_available: [
				"myapex",
			],
			min_sdk_version: "30",
		}
	`)

	testApexError(t, `module "libfoo".*: should support min_sdk_version\(29\)`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["libfoo"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_import {
			name: "libfoo",
			jars: ["libfoo.jar"],
			apex_available: [
				"myapex",
			],
			min_sdk_version: "30",
		}
	`)
}

func TestApexMinSdkVersion_Okay(t *testing.T) {
	testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libfoo"],
			java_libs: ["libbar"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libfoo",
			srcs: ["mylib.cpp"],
			shared_libs: ["libfoo_dep"],
			apex_available: ["myapex"],
			min_sdk_version: "29",
		}

		cc_library {
			name: "libfoo_dep",
			srcs: ["mylib.cpp"],
			apex_available: ["myapex"],
			min_sdk_version: "29",
		}

		java_library {
			name: "libbar",
			sdk_version: "current",
			srcs: ["a.java"],
			static_libs: [
				"libbar_dep",
				"libbar_import_dep",
			],
			apex_available: ["myapex"],
			min_sdk_version: "29",
		}

		java_library {
			name: "libbar_dep",
			sdk_version: "current",
			srcs: ["a.java"],
			apex_available: ["myapex"],
			min_sdk_version: "29",
		}

		java_import {
			name: "libbar_import_dep",
			jars: ["libbar.jar"],
			apex_available: ["myapex"],
			min_sdk_version: "29",
		}
	`)
}

func TestJavaStableSdkVersion(t *testing.T) {
	testCases := []struct {
		name          string
		expectedError string
		bp            string
	}{
		{
			name: "Non-updatable apex with non-stable dep",
			bp: `
				apex {
					name: "myapex",
					java_libs: ["myjar"],
					key: "myapex.key",
					updatable: false,
				}
				apex_key {
					name: "myapex.key",
					public_key: "testkey.avbpubkey",
					private_key: "testkey.pem",
				}
				java_library {
					name: "myjar",
					srcs: ["foo/bar/MyClass.java"],
					sdk_version: "test_current",
					apex_available: ["myapex"],
				}
			`,
		},
		{
			name: "Updatable apex with stable dep",
			bp: `
				apex {
					name: "myapex",
					java_libs: ["myjar"],
					key: "myapex.key",
					updatable: true,
					min_sdk_version: "29",
				}
				apex_key {
					name: "myapex.key",
					public_key: "testkey.avbpubkey",
					private_key: "testkey.pem",
				}
				java_library {
					name: "myjar",
					srcs: ["foo/bar/MyClass.java"],
					sdk_version: "current",
					apex_available: ["myapex"],
					min_sdk_version: "29",
				}
			`,
		},
		{
			name:          "Updatable apex with non-stable dep",
			expectedError: "cannot depend on \"myjar\"",
			bp: `
				apex {
					name: "myapex",
					java_libs: ["myjar"],
					key: "myapex.key",
					updatable: true,
				}
				apex_key {
					name: "myapex.key",
					public_key: "testkey.avbpubkey",
					private_key: "testkey.pem",
				}
				java_library {
					name: "myjar",
					srcs: ["foo/bar/MyClass.java"],
					sdk_version: "test_current",
					apex_available: ["myapex"],
				}
			`,
		},
		{
			name: "Updatable apex with non-stable transitive dep",
			// This is not actually detecting that the transitive dependency is unstable, rather it is
			// detecting that the transitive dependency is building against a wider API surface than the
			// module that depends on it is using.
			expectedError: "compiles against Android API, but dependency \"transitive-jar\" is compiling against private API.",
			bp: `
				apex {
					name: "myapex",
					java_libs: ["myjar"],
					key: "myapex.key",
					updatable: true,
				}
				apex_key {
					name: "myapex.key",
					public_key: "testkey.avbpubkey",
					private_key: "testkey.pem",
				}
				java_library {
					name: "myjar",
					srcs: ["foo/bar/MyClass.java"],
					sdk_version: "current",
					apex_available: ["myapex"],
					static_libs: ["transitive-jar"],
				}
				java_library {
					name: "transitive-jar",
					srcs: ["foo/bar/MyClass.java"],
					sdk_version: "core_platform",
					apex_available: ["myapex"],
				}
			`,
		},
	}

	for _, test := range testCases {
		t.Run(test.name, func(t *testing.T) {
			if test.expectedError == "" {
				testApex(t, test.bp)
			} else {
				testApexError(t, test.expectedError, test.bp)
			}
		})
	}
}

func TestApexMinSdkVersion_ErrorIfDepIsNewer(t *testing.T) {
	testApexError(t, `module "mylib2".*: should support min_sdk_version\(29\) for "myapex"`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["mylib2"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
			],
			min_sdk_version: "29",
		}

		// indirect part of the apex
		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
			],
			min_sdk_version: "30",
		}
	`)
}

func TestApexMinSdkVersion_ErrorIfDepIsNewer_Java(t *testing.T) {
	testApexError(t, `module "bar".*: should support min_sdk_version\(29\) for "myapex"`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: ["AppFoo"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_app {
			name: "AppFoo",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "current",
			min_sdk_version: "29",
			system_modules: "none",
			stl: "none",
			static_libs: ["bar"],
			apex_available: [ "myapex" ],
		}

		java_library {
			name: "bar",
			sdk_version: "current",
			srcs: ["a.java"],
			apex_available: [ "myapex" ],
		}
	`)
}

func TestApexMinSdkVersion_OkayEvenWhenDepIsNewer_IfItSatisfiesApexMinSdkVersion(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		// mylib in myapex will link to mylib2#current
		// mylib in otherapex will link to mylib2(non-stub) in otherapex as well
		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["mylib2"],
			system_shared_libs: [],
			stl: "none",
			apex_available: ["myapex", "otherapex"],
			min_sdk_version: "29",
		}

		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: ["otherapex"],
			stubs: { versions: ["29", "30"] },
			min_sdk_version: "30",
		}

		apex {
			name: "otherapex",
			key: "myapex.key",
			native_shared_libs: ["mylib", "mylib2"],
			min_sdk_version: "30",
		}
	`)
	expectLink := func(from, from_variant, to, to_variant string) {
		ld := ctx.ModuleForTests(from, "android_arm64_armv8-a_"+from_variant).Rule("ld")
		libFlags := ld.Args["libFlags"]
		ensureContains(t, libFlags, "android_arm64_armv8-a_"+to_variant+"/"+to+".so")
	}
	expectLink("mylib", "shared_apex29", "mylib2", "shared_current")
	expectLink("mylib", "shared_apex30", "mylib2", "shared_apex30")
}

func TestApexMinSdkVersion_WorksWithSdkCodename(t *testing.T) {
	withSAsActiveCodeNames := android.FixtureModifyProductVariables(
		func(variables android.FixtureProductVariables) {
			variables.Platform_sdk_codename = proptools.StringPtr("S")
			variables.Platform_version_active_codenames = []string{"S"}
		},
	)
	testApexError(t, `libbar.*: should support min_sdk_version\(S\)`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libfoo"],
			min_sdk_version: "S",
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
		cc_library {
			name: "libfoo",
			shared_libs: ["libbar"],
			apex_available: ["myapex"],
			min_sdk_version: "29",
		}
		cc_library {
			name: "libbar",
			apex_available: ["myapex"],
		}
	`, withSAsActiveCodeNames)
}

func TestApexMinSdkVersion_WorksWithActiveCodenames(t *testing.T) {
	withSAsActiveCodeNames := android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
		variables.Platform_sdk_codename = proptools.StringPtr("S")
		variables.Platform_version_active_codenames = []string{"S", "T"}
	})
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libfoo"],
			min_sdk_version: "S",
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
		cc_library {
			name: "libfoo",
			shared_libs: ["libbar"],
			apex_available: ["myapex"],
			min_sdk_version: "S",
		}
		cc_library {
			name: "libbar",
			stubs: {
				symbol_file: "libbar.map.txt",
				versions: ["30", "S", "T"],
			},
		}
	`, withSAsActiveCodeNames)

	// ensure libfoo is linked with current version of libbar stub
	libfoo := ctx.ModuleForTests("libfoo", "android_arm64_armv8-a_shared_apex10000")
	libFlags := libfoo.Rule("ld").Args["libFlags"]
	ensureContains(t, libFlags, "android_arm64_armv8-a_shared_current/libbar.so")
}

func TestFilesInSubDir(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			binaries: ["mybin"],
			prebuilts: ["myetc"],
			compile_multilib: "both",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		prebuilt_etc {
			name: "myetc",
			src: "myprebuilt",
			sub_dir: "foo/bar",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			relative_install_path: "foo/bar",
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_binary {
			name: "mybin",
			srcs: ["mylib.cpp"],
			relative_install_path: "foo/bar",
			system_shared_libs: [],
			static_executable: true,
			stl: "none",
			apex_available: [ "myapex" ],
		}
	`)

	generateFsRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("generateFsConfig")
	dirs := strings.Split(generateFsRule.Args["exec_paths"], " ")

	// Ensure that the subdirectories are all listed
	ensureListContains(t, dirs, "etc")
	ensureListContains(t, dirs, "etc/foo")
	ensureListContains(t, dirs, "etc/foo/bar")
	ensureListContains(t, dirs, "lib64")
	ensureListContains(t, dirs, "lib64/foo")
	ensureListContains(t, dirs, "lib64/foo/bar")
	ensureListContains(t, dirs, "lib")
	ensureListContains(t, dirs, "lib/foo")
	ensureListContains(t, dirs, "lib/foo/bar")

	ensureListContains(t, dirs, "bin")
	ensureListContains(t, dirs, "bin/foo")
	ensureListContains(t, dirs, "bin/foo/bar")
}

func TestFilesInSubDirWhenNativeBridgeEnabled(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			multilib: {
				both: {
					native_shared_libs: ["mylib"],
					binaries: ["mybin"],
				},
			},
			compile_multilib: "both",
			native_bridge_supported: true,
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			relative_install_path: "foo/bar",
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
			native_bridge_supported: true,
		}

		cc_binary {
			name: "mybin",
			relative_install_path: "foo/bar",
			system_shared_libs: [],
			static_executable: true,
			stl: "none",
			apex_available: [ "myapex" ],
			native_bridge_supported: true,
			compile_multilib: "both", // default is "first" for binary
			multilib: {
				lib64: {
					suffix: "64",
				},
			},
		}
	`, withNativeBridgeEnabled)
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"bin/foo/bar/mybin",
		"bin/foo/bar/mybin64",
		"bin/arm/foo/bar/mybin",
		"bin/arm64/foo/bar/mybin64",
		"lib/foo/bar/mylib.so",
		"lib/arm/foo/bar/mylib.so",
		"lib64/foo/bar/mylib.so",
		"lib64/arm64/foo/bar/mylib.so",
	})
}

func TestVendorApex(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			binaries: ["mybin"],
			vendor: true,
			updatable: false,
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
		cc_binary {
			name: "mybin",
			vendor: true,
			shared_libs: ["libfoo"],
		}
		cc_library {
			name: "libfoo",
			proprietary: true,
		}
	`)

	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"bin/mybin",
		"lib64/libfoo.so",
		// TODO(b/159195575): Add an option to use VNDK libs from VNDK APEX
		"lib64/libc++.so",
	})

	apexBundle := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, apexBundle)
	name := apexBundle.BaseModuleName()
	prefix := "TARGET_"
	var builder strings.Builder
	data.Custom(&builder, name, prefix, "", data)
	androidMk := android.StringRelativeToTop(ctx.Config(), builder.String())
	installPath := "out/target/product/test_device/vendor/apex"
	ensureContains(t, androidMk, "LOCAL_MODULE_PATH := "+installPath)

	apexManifestRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexManifestRule")
	requireNativeLibs := names(apexManifestRule.Args["requireNativeLibs"])
	ensureListNotContains(t, requireNativeLibs, ":vndk")
}

func TestVendorApex_use_vndk_as_stable(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			binaries: ["mybin"],
			vendor: true,
			use_vndk_as_stable: true,
			updatable: false,
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
		cc_binary {
			name: "mybin",
			vendor: true,
			shared_libs: ["libvndk", "libvendor"],
		}
		cc_library {
			name: "libvndk",
			vndk: {
				enabled: true,
			},
			vendor_available: true,
			product_available: true,
		}
		cc_library {
			name: "libvendor",
			vendor: true,
		}
	`)

	vendorVariant := "android_vendor.29_arm64_armv8-a"

	ldRule := ctx.ModuleForTests("mybin", vendorVariant+"_apex10000").Rule("ld")
	libs := names(ldRule.Args["libFlags"])
	// VNDK libs(libvndk/libc++) as they are
	ensureListContains(t, libs, "out/soong/.intermediates/libvndk/"+vendorVariant+"_shared/libvndk.so")
	ensureListContains(t, libs, "out/soong/.intermediates/"+cc.DefaultCcCommonTestModulesDir+"libc++/"+vendorVariant+"_shared/libc++.so")
	// non-stable Vendor libs as APEX variants
	ensureListContains(t, libs, "out/soong/.intermediates/libvendor/"+vendorVariant+"_shared_apex10000/libvendor.so")

	// VNDK libs are not included when use_vndk_as_stable: true
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"bin/mybin",
		"lib64/libvendor.so",
	})

	apexManifestRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexManifestRule")
	requireNativeLibs := names(apexManifestRule.Args["requireNativeLibs"])
	ensureListContains(t, requireNativeLibs, ":vndk")
}

func TestProductVariant(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
			product_specific: true,
			binaries: ["foo"],
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_binary {
			name: "foo",
			product_available: true,
			apex_available: ["myapex"],
			srcs: ["foo.cpp"],
		}
	`, android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
		variables.ProductVndkVersion = proptools.StringPtr("current")
	}),
	)

	cflags := strings.Fields(
		ctx.ModuleForTests("foo", "android_product.29_arm64_armv8-a_apex10000").Rule("cc").Args["cFlags"])
	ensureListContains(t, cflags, "-D__ANDROID_VNDK__")
	ensureListContains(t, cflags, "-D__ANDROID_APEX__")
	ensureListContains(t, cflags, "-D__ANDROID_PRODUCT__")
	ensureListNotContains(t, cflags, "-D__ANDROID_VENDOR__")
}

func TestApex_withPrebuiltFirmware(t *testing.T) {
	testCases := []struct {
		name           string
		additionalProp string
	}{
		{"system apex with prebuilt_firmware", ""},
		{"vendor apex with prebuilt_firmware", "vendor: true,"},
	}
	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {
			ctx := testApex(t, `
				apex {
					name: "myapex",
					key: "myapex.key",
					prebuilts: ["myfirmware"],
					updatable: false,
					`+tc.additionalProp+`
				}
				apex_key {
					name: "myapex.key",
					public_key: "testkey.avbpubkey",
					private_key: "testkey.pem",
				}
				prebuilt_firmware {
					name: "myfirmware",
					src: "myfirmware.bin",
					filename_from_src: true,
					`+tc.additionalProp+`
				}
			`)
			ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
				"etc/firmware/myfirmware.bin",
			})
		})
	}
}

func TestAndroidMk_VendorApexRequired(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			vendor: true,
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			vendor_available: true,
		}
	`)

	apexBundle := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, apexBundle)
	name := apexBundle.BaseModuleName()
	prefix := "TARGET_"
	var builder strings.Builder
	data.Custom(&builder, name, prefix, "", data)
	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_REQUIRED_MODULES += libc.vendor libm.vendor libdl.vendor\n")
}

func TestAndroidMkWritesCommonProperties(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			vintf_fragments: ["fragment.xml"],
			init_rc: ["init.rc"],
			updatable: false,
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
		cc_binary {
			name: "mybin",
		}
	`)

	apexBundle := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, apexBundle)
	name := apexBundle.BaseModuleName()
	prefix := "TARGET_"
	var builder strings.Builder
	data.Custom(&builder, name, prefix, "", data)
	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_FULL_VINTF_FRAGMENTS := fragment.xml\n")
	ensureContains(t, androidMk, "LOCAL_FULL_INIT_RC := init.rc\n")
}

func TestStaticLinking(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["1", "2", "3"],
			},
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		cc_binary {
			name: "not_in_apex",
			srcs: ["mylib.cpp"],
			static_libs: ["mylib"],
			static_executable: true,
			system_shared_libs: [],
			stl: "none",
		}
	`)

	ldFlags := ctx.ModuleForTests("not_in_apex", "android_arm64_armv8-a").Rule("ld").Args["libFlags"]

	// Ensure that not_in_apex is linking with the static variant of mylib
	ensureContains(t, ldFlags, "mylib/android_arm64_armv8-a_static/mylib.a")
}

func TestKeys(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex_keytest",
			key: "myapex.key",
			certificate: ":myapex.certificate",
			native_shared_libs: ["mylib"],
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex_keytest" ],
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_app_certificate {
			name: "myapex.certificate",
			certificate: "testkey",
		}

		android_app_certificate {
			name: "myapex.certificate.override",
			certificate: "testkey.override",
		}

	`)

	// check the APEX keys
	keys := ctx.ModuleForTests("myapex.key", "android_common").Module().(*apexKey)

	if keys.publicKeyFile.String() != "vendor/foo/devkeys/testkey.avbpubkey" {
		t.Errorf("public key %q is not %q", keys.publicKeyFile.String(),
			"vendor/foo/devkeys/testkey.avbpubkey")
	}
	if keys.privateKeyFile.String() != "vendor/foo/devkeys/testkey.pem" {
		t.Errorf("private key %q is not %q", keys.privateKeyFile.String(),
			"vendor/foo/devkeys/testkey.pem")
	}

	// check the APK certs. It should be overridden to myapex.certificate.override
	certs := ctx.ModuleForTests("myapex_keytest", "android_common_myapex_keytest_image").Rule("signapk").Args["certificates"]
	if certs != "testkey.override.x509.pem testkey.override.pk8" {
		t.Errorf("cert and private key %q are not %q", certs,
			"testkey.override.509.pem testkey.override.pk8")
	}
}

func TestCertificate(t *testing.T) {
	t.Run("if unspecified, it defaults to DefaultAppCertificate", func(t *testing.T) {
		ctx := testApex(t, `
			apex {
				name: "myapex",
				key: "myapex.key",
				updatable: false,
			}
			apex_key {
				name: "myapex.key",
				public_key: "testkey.avbpubkey",
				private_key: "testkey.pem",
			}`)
		rule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("signapk")
		expected := "vendor/foo/devkeys/test.x509.pem vendor/foo/devkeys/test.pk8"
		if actual := rule.Args["certificates"]; actual != expected {
			t.Errorf("certificates should be %q, not %q", expected, actual)
		}
	})
	t.Run("override when unspecified", func(t *testing.T) {
		ctx := testApex(t, `
			apex {
				name: "myapex_keytest",
				key: "myapex.key",
				file_contexts: ":myapex-file_contexts",
				updatable: false,
			}
			apex_key {
				name: "myapex.key",
				public_key: "testkey.avbpubkey",
				private_key: "testkey.pem",
			}
			android_app_certificate {
				name: "myapex.certificate.override",
				certificate: "testkey.override",
			}`)
		rule := ctx.ModuleForTests("myapex_keytest", "android_common_myapex_keytest_image").Rule("signapk")
		expected := "testkey.override.x509.pem testkey.override.pk8"
		if actual := rule.Args["certificates"]; actual != expected {
			t.Errorf("certificates should be %q, not %q", expected, actual)
		}
	})
	t.Run("if specified as :module, it respects the prop", func(t *testing.T) {
		ctx := testApex(t, `
			apex {
				name: "myapex",
				key: "myapex.key",
				certificate: ":myapex.certificate",
				updatable: false,
			}
			apex_key {
				name: "myapex.key",
				public_key: "testkey.avbpubkey",
				private_key: "testkey.pem",
			}
			android_app_certificate {
				name: "myapex.certificate",
				certificate: "testkey",
			}`)
		rule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("signapk")
		expected := "testkey.x509.pem testkey.pk8"
		if actual := rule.Args["certificates"]; actual != expected {
			t.Errorf("certificates should be %q, not %q", expected, actual)
		}
	})
	t.Run("override when specifiec as <:module>", func(t *testing.T) {
		ctx := testApex(t, `
			apex {
				name: "myapex_keytest",
				key: "myapex.key",
				file_contexts: ":myapex-file_contexts",
				certificate: ":myapex.certificate",
				updatable: false,
			}
			apex_key {
				name: "myapex.key",
				public_key: "testkey.avbpubkey",
				private_key: "testkey.pem",
			}
			android_app_certificate {
				name: "myapex.certificate.override",
				certificate: "testkey.override",
			}`)
		rule := ctx.ModuleForTests("myapex_keytest", "android_common_myapex_keytest_image").Rule("signapk")
		expected := "testkey.override.x509.pem testkey.override.pk8"
		if actual := rule.Args["certificates"]; actual != expected {
			t.Errorf("certificates should be %q, not %q", expected, actual)
		}
	})
	t.Run("if specified as name, finds it from DefaultDevKeyDir", func(t *testing.T) {
		ctx := testApex(t, `
			apex {
				name: "myapex",
				key: "myapex.key",
				certificate: "testkey",
				updatable: false,
			}
			apex_key {
				name: "myapex.key",
				public_key: "testkey.avbpubkey",
				private_key: "testkey.pem",
			}`)
		rule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("signapk")
		expected := "vendor/foo/devkeys/testkey.x509.pem vendor/foo/devkeys/testkey.pk8"
		if actual := rule.Args["certificates"]; actual != expected {
			t.Errorf("certificates should be %q, not %q", expected, actual)
		}
	})
	t.Run("override when specified as <name>", func(t *testing.T) {
		ctx := testApex(t, `
			apex {
				name: "myapex_keytest",
				key: "myapex.key",
				file_contexts: ":myapex-file_contexts",
				certificate: "testkey",
				updatable: false,
			}
			apex_key {
				name: "myapex.key",
				public_key: "testkey.avbpubkey",
				private_key: "testkey.pem",
			}
			android_app_certificate {
				name: "myapex.certificate.override",
				certificate: "testkey.override",
			}`)
		rule := ctx.ModuleForTests("myapex_keytest", "android_common_myapex_keytest_image").Rule("signapk")
		expected := "testkey.override.x509.pem testkey.override.pk8"
		if actual := rule.Args["certificates"]; actual != expected {
			t.Errorf("certificates should be %q, not %q", expected, actual)
		}
	})
}

func TestMacro(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib", "mylib2"],
			updatable: false,
		}

		apex {
			name: "otherapex",
			key: "myapex.key",
			native_shared_libs: ["mylib", "mylib2"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
				"otherapex",
			],
			recovery_available: true,
			min_sdk_version: "29",
		}
		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
				"otherapex",
			],
			static_libs: ["mylib3"],
			recovery_available: true,
			min_sdk_version: "29",
		}
		cc_library {
			name: "mylib3",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
				"otherapex",
			],
			use_apex_name_macro: true,
			recovery_available: true,
			min_sdk_version: "29",
		}
	`)

	// non-APEX variant does not have __ANDROID_APEX__ defined
	mylibCFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_static").Rule("cc").Args["cFlags"]
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_MIN_SDK_VERSION__")

	// APEX variant has __ANDROID_APEX__ and __ANDROID_APEX_SDK__ defined
	mylibCFlags = ctx.ModuleForTests("mylib", "android_arm64_armv8-a_static_apex10000").Rule("cc").Args["cFlags"]
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX_MIN_SDK_VERSION__=10000")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_MYAPEX__")

	// APEX variant has __ANDROID_APEX__ and __ANDROID_APEX_SDK__ defined
	mylibCFlags = ctx.ModuleForTests("mylib", "android_arm64_armv8-a_static_apex29").Rule("cc").Args["cFlags"]
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX_MIN_SDK_VERSION__=29")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_OTHERAPEX__")

	// When a cc_library sets use_apex_name_macro: true each apex gets a unique variant and
	// each variant defines additional macros to distinguish which apex variant it is built for

	// non-APEX variant does not have __ANDROID_APEX__ defined
	mylibCFlags = ctx.ModuleForTests("mylib3", "android_arm64_armv8-a_static").Rule("cc").Args["cFlags"]
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX__")

	// APEX variant has __ANDROID_APEX__ defined
	mylibCFlags = ctx.ModuleForTests("mylib3", "android_arm64_armv8-a_static_myapex").Rule("cc").Args["cFlags"]
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX_MYAPEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_OTHERAPEX__")

	// APEX variant has __ANDROID_APEX__ defined
	mylibCFlags = ctx.ModuleForTests("mylib3", "android_arm64_armv8-a_static_otherapex").Rule("cc").Args["cFlags"]
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_MYAPEX__")
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX_OTHERAPEX__")

	// recovery variant does not set __ANDROID_APEX_MIN_SDK_VERSION__
	mylibCFlags = ctx.ModuleForTests("mylib3", "android_recovery_arm64_armv8-a_static").Rule("cc").Args["cFlags"]
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_MIN_SDK_VERSION__")

	// When a dependency of a cc_library sets use_apex_name_macro: true each apex gets a unique
	// variant.

	// non-APEX variant does not have __ANDROID_APEX__ defined
	mylibCFlags = ctx.ModuleForTests("mylib2", "android_arm64_armv8-a_static").Rule("cc").Args["cFlags"]
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX__")

	// APEX variant has __ANDROID_APEX__ defined
	mylibCFlags = ctx.ModuleForTests("mylib2", "android_arm64_armv8-a_static_myapex").Rule("cc").Args["cFlags"]
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_MYAPEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_OTHERAPEX__")

	// APEX variant has __ANDROID_APEX__ defined
	mylibCFlags = ctx.ModuleForTests("mylib2", "android_arm64_armv8-a_static_otherapex").Rule("cc").Args["cFlags"]
	ensureContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_MYAPEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_OTHERAPEX__")

	// recovery variant does not set __ANDROID_APEX_MIN_SDK_VERSION__
	mylibCFlags = ctx.ModuleForTests("mylib2", "android_recovery_arm64_armv8-a_static").Rule("cc").Args["cFlags"]
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX__")
	ensureNotContains(t, mylibCFlags, "-D__ANDROID_APEX_MIN_SDK_VERSION__")
}

func TestHeaderLibsDependency(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library_headers {
			name: "mylib_headers",
			export_include_dirs: ["my_include"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			header_libs: ["mylib_headers"],
			export_header_lib_headers: ["mylib_headers"],
			stubs: {
				versions: ["1", "2", "3"],
			},
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "otherlib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			shared_libs: ["mylib"],
		}
	`)

	cFlags := ctx.ModuleForTests("otherlib", "android_arm64_armv8-a_static").Rule("cc").Args["cFlags"]

	// Ensure that the include path of the header lib is exported to 'otherlib'
	ensureContains(t, cFlags, "-Imy_include")
}

type fileInApex struct {
	path   string // path in apex
	src    string // src path
	isLink bool
}

func getFiles(t *testing.T, ctx *android.TestContext, moduleName, variant string) []fileInApex {
	t.Helper()
	apexRule := ctx.ModuleForTests(moduleName, variant).Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]
	imageApexDir := "/image.apex/"
	var ret []fileInApex
	for _, cmd := range strings.Split(copyCmds, "&&") {
		cmd = strings.TrimSpace(cmd)
		if cmd == "" {
			continue
		}
		terms := strings.Split(cmd, " ")
		var dst, src string
		var isLink bool
		switch terms[0] {
		case "mkdir":
		case "cp":
			if len(terms) != 3 && len(terms) != 4 {
				t.Fatal("copyCmds contains invalid cp command", cmd)
			}
			dst = terms[len(terms)-1]
			src = terms[len(terms)-2]
			isLink = false
		case "ln":
			if len(terms) != 3 && len(terms) != 4 {
				// ln LINK TARGET or ln -s LINK TARGET
				t.Fatal("copyCmds contains invalid ln command", cmd)
			}
			dst = terms[len(terms)-1]
			src = terms[len(terms)-2]
			isLink = true
		default:
			t.Fatalf("copyCmds should contain mkdir/cp commands only: %q", cmd)
		}
		if dst != "" {
			index := strings.Index(dst, imageApexDir)
			if index == -1 {
				t.Fatal("copyCmds should copy a file to image.apex/", cmd)
			}
			dstFile := dst[index+len(imageApexDir):]
			ret = append(ret, fileInApex{path: dstFile, src: src, isLink: isLink})
		}
	}
	return ret
}

func ensureExactContents(t *testing.T, ctx *android.TestContext, moduleName, variant string, files []string) {
	t.Helper()
	var failed bool
	var surplus []string
	filesMatched := make(map[string]bool)
	for _, file := range getFiles(t, ctx, moduleName, variant) {
		mactchFound := false
		for _, expected := range files {
			if matched, _ := path.Match(expected, file.path); matched {
				filesMatched[expected] = true
				mactchFound = true
				break
			}
		}
		if !mactchFound {
			surplus = append(surplus, file.path)
		}
	}

	if len(surplus) > 0 {
		sort.Strings(surplus)
		t.Log("surplus files", surplus)
		failed = true
	}

	if len(files) > len(filesMatched) {
		var missing []string
		for _, expected := range files {
			if !filesMatched[expected] {
				missing = append(missing, expected)
			}
		}
		sort.Strings(missing)
		t.Log("missing files", missing)
		failed = true
	}
	if failed {
		t.Fail()
	}
}

func TestVndkApexCurrent(t *testing.T) {
	ctx := testApex(t, `
		apex_vndk {
			name: "com.android.vndk.current",
			key: "com.android.vndk.current.key",
			updatable: false,
		}

		apex_key {
			name: "com.android.vndk.current.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libvndk",
			srcs: ["mylib.cpp"],
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
			},
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "com.android.vndk.current" ],
		}

		cc_library {
			name: "libvndksp",
			srcs: ["mylib.cpp"],
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
				support_system_process: true,
			},
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "com.android.vndk.current" ],
		}
	`+vndkLibrariesTxtFiles("current"))

	ensureExactContents(t, ctx, "com.android.vndk.current", "android_common_image", []string{
		"lib/libvndk.so",
		"lib/libvndksp.so",
		"lib/libc++.so",
		"lib64/libvndk.so",
		"lib64/libvndksp.so",
		"lib64/libc++.so",
		"etc/llndk.libraries.29.txt",
		"etc/vndkcore.libraries.29.txt",
		"etc/vndksp.libraries.29.txt",
		"etc/vndkprivate.libraries.29.txt",
		"etc/vndkproduct.libraries.29.txt",
	})
}

func TestVndkApexWithPrebuilt(t *testing.T) {
	ctx := testApex(t, `
		apex_vndk {
			name: "com.android.vndk.current",
			key: "com.android.vndk.current.key",
			updatable: false,
		}

		apex_key {
			name: "com.android.vndk.current.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_prebuilt_library_shared {
			name: "libvndk",
			srcs: ["libvndk.so"],
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
			},
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "com.android.vndk.current" ],
		}

		cc_prebuilt_library_shared {
			name: "libvndk.arm",
			srcs: ["libvndk.arm.so"],
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
			},
			enabled: false,
			arch: {
				arm: {
					enabled: true,
				},
			},
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "com.android.vndk.current" ],
		}
		`+vndkLibrariesTxtFiles("current"),
		withFiles(map[string][]byte{
			"libvndk.so":     nil,
			"libvndk.arm.so": nil,
		}))
	ensureExactContents(t, ctx, "com.android.vndk.current", "android_common_image", []string{
		"lib/libvndk.so",
		"lib/libvndk.arm.so",
		"lib64/libvndk.so",
		"lib/libc++.so",
		"lib64/libc++.so",
		"etc/*",
	})
}

func vndkLibrariesTxtFiles(vers ...string) (result string) {
	for _, v := range vers {
		if v == "current" {
			for _, txt := range []string{"llndk", "vndkcore", "vndksp", "vndkprivate", "vndkproduct"} {
				result += `
					` + txt + `_libraries_txt {
						name: "` + txt + `.libraries.txt",
					}
				`
			}
		} else {
			for _, txt := range []string{"llndk", "vndkcore", "vndksp", "vndkprivate", "vndkproduct"} {
				result += `
					prebuilt_etc {
						name: "` + txt + `.libraries.` + v + `.txt",
						src: "dummy.txt",
					}
				`
			}
		}
	}
	return
}

func TestVndkApexVersion(t *testing.T) {
	ctx := testApex(t, `
		apex_vndk {
			name: "com.android.vndk.v27",
			key: "myapex.key",
			file_contexts: ":myapex-file_contexts",
			vndk_version: "27",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		vndk_prebuilt_shared {
			name: "libvndk27",
			version: "27",
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
			},
			target_arch: "arm64",
			arch: {
				arm: {
					srcs: ["libvndk27_arm.so"],
				},
				arm64: {
					srcs: ["libvndk27_arm64.so"],
				},
			},
			apex_available: [ "com.android.vndk.v27" ],
		}

		vndk_prebuilt_shared {
			name: "libvndk27",
			version: "27",
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
			},
			target_arch: "x86_64",
			arch: {
				x86: {
					srcs: ["libvndk27_x86.so"],
				},
				x86_64: {
					srcs: ["libvndk27_x86_64.so"],
				},
			},
		}
		`+vndkLibrariesTxtFiles("27"),
		withFiles(map[string][]byte{
			"libvndk27_arm.so":    nil,
			"libvndk27_arm64.so":  nil,
			"libvndk27_x86.so":    nil,
			"libvndk27_x86_64.so": nil,
		}))

	ensureExactContents(t, ctx, "com.android.vndk.v27", "android_common_image", []string{
		"lib/libvndk27_arm.so",
		"lib64/libvndk27_arm64.so",
		"etc/*",
	})
}

func TestVndkApexNameRule(t *testing.T) {
	ctx := testApex(t, `
		apex_vndk {
			name: "com.android.vndk.current",
			key: "myapex.key",
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}
		apex_vndk {
			name: "com.android.vndk.v28",
			key: "myapex.key",
			file_contexts: ":myapex-file_contexts",
			vndk_version: "28",
			updatable: false,
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}`+vndkLibrariesTxtFiles("28", "current"))

	assertApexName := func(expected, moduleName string) {
		bundle := ctx.ModuleForTests(moduleName, "android_common_image").Module().(*apexBundle)
		actual := proptools.String(bundle.properties.Apex_name)
		if !reflect.DeepEqual(actual, expected) {
			t.Errorf("Got '%v', expected '%v'", actual, expected)
		}
	}

	assertApexName("com.android.vndk.v29", "com.android.vndk.current")
	assertApexName("com.android.vndk.v28", "com.android.vndk.v28")
}

func TestVndkApexSkipsNativeBridgeSupportedModules(t *testing.T) {
	ctx := testApex(t, `
		apex_vndk {
			name: "com.android.vndk.current",
			key: "com.android.vndk.current.key",
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}

		apex_key {
			name: "com.android.vndk.current.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libvndk",
			srcs: ["mylib.cpp"],
			vendor_available: true,
			product_available: true,
			native_bridge_supported: true,
			host_supported: true,
			vndk: {
				enabled: true,
			},
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "com.android.vndk.current" ],
		}
		`+vndkLibrariesTxtFiles("current"),
		withNativeBridgeEnabled)

	ensureExactContents(t, ctx, "com.android.vndk.current", "android_common_image", []string{
		"lib/libvndk.so",
		"lib64/libvndk.so",
		"lib/libc++.so",
		"lib64/libc++.so",
		"etc/*",
	})
}

func TestVndkApexDoesntSupportNativeBridgeSupported(t *testing.T) {
	testApexError(t, `module "com.android.vndk.current" .*: native_bridge_supported: .* doesn't support native bridge binary`, `
		apex_vndk {
			name: "com.android.vndk.current",
			key: "com.android.vndk.current.key",
			file_contexts: ":myapex-file_contexts",
			native_bridge_supported: true,
		}

		apex_key {
			name: "com.android.vndk.current.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libvndk",
			srcs: ["mylib.cpp"],
			vendor_available: true,
			product_available: true,
			native_bridge_supported: true,
			host_supported: true,
			vndk: {
				enabled: true,
			},
			system_shared_libs: [],
			stl: "none",
		}
	`)
}

func TestVndkApexWithBinder32(t *testing.T) {
	ctx := testApex(t, `
		apex_vndk {
			name: "com.android.vndk.v27",
			key: "myapex.key",
			file_contexts: ":myapex-file_contexts",
			vndk_version: "27",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		vndk_prebuilt_shared {
			name: "libvndk27",
			version: "27",
			target_arch: "arm",
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
			},
			arch: {
				arm: {
					srcs: ["libvndk27.so"],
				}
			},
		}

		vndk_prebuilt_shared {
			name: "libvndk27",
			version: "27",
			target_arch: "arm",
			binder32bit: true,
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
			},
			arch: {
				arm: {
					srcs: ["libvndk27binder32.so"],
				}
			},
			apex_available: [ "com.android.vndk.v27" ],
		}
		`+vndkLibrariesTxtFiles("27"),
		withFiles(map[string][]byte{
			"libvndk27.so":         nil,
			"libvndk27binder32.so": nil,
		}),
		withBinder32bit,
		withTargets(map[android.OsType][]android.Target{
			android.Android: []android.Target{
				{Os: android.Android, Arch: android.Arch{ArchType: android.Arm, ArchVariant: "armv7-a-neon", Abi: []string{"armeabi-v7a"}},
					NativeBridge: android.NativeBridgeDisabled, NativeBridgeHostArchName: "", NativeBridgeRelativePath: ""},
			},
		}),
	)

	ensureExactContents(t, ctx, "com.android.vndk.v27", "android_common_image", []string{
		"lib/libvndk27binder32.so",
		"etc/*",
	})
}

func TestVndkApexShouldNotProvideNativeLibs(t *testing.T) {
	ctx := testApex(t, `
		apex_vndk {
			name: "com.android.vndk.current",
			key: "com.android.vndk.current.key",
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}

		apex_key {
			name: "com.android.vndk.current.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libz",
			vendor_available: true,
			product_available: true,
			vndk: {
				enabled: true,
			},
			stubs: {
				symbol_file: "libz.map.txt",
				versions: ["30"],
			}
		}
	`+vndkLibrariesTxtFiles("current"), withFiles(map[string][]byte{
		"libz.map.txt": nil,
	}))

	apexManifestRule := ctx.ModuleForTests("com.android.vndk.current", "android_common_image").Rule("apexManifestRule")
	provideNativeLibs := names(apexManifestRule.Args["provideNativeLibs"])
	ensureListEmpty(t, provideNativeLibs)
}

func TestDependenciesInApexManifest(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex_nodep",
			key: "myapex.key",
			native_shared_libs: ["lib_nodep"],
			compile_multilib: "both",
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}

		apex {
			name: "myapex_dep",
			key: "myapex.key",
			native_shared_libs: ["lib_dep"],
			compile_multilib: "both",
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}

		apex {
			name: "myapex_provider",
			key: "myapex.key",
			native_shared_libs: ["libfoo"],
			compile_multilib: "both",
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}

		apex {
			name: "myapex_selfcontained",
			key: "myapex.key",
			native_shared_libs: ["lib_dep", "libfoo"],
			compile_multilib: "both",
			file_contexts: ":myapex-file_contexts",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "lib_nodep",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex_nodep" ],
		}

		cc_library {
			name: "lib_dep",
			srcs: ["mylib.cpp"],
			shared_libs: ["libfoo"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex_dep",
				"myapex_provider",
				"myapex_selfcontained",
			],
		}

		cc_library {
			name: "libfoo",
			srcs: ["mytest.cpp"],
			stubs: {
				versions: ["1"],
			},
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex_provider",
				"myapex_selfcontained",
			],
		}
	`)

	var apexManifestRule android.TestingBuildParams
	var provideNativeLibs, requireNativeLibs []string

	apexManifestRule = ctx.ModuleForTests("myapex_nodep", "android_common_myapex_nodep_image").Rule("apexManifestRule")
	provideNativeLibs = names(apexManifestRule.Args["provideNativeLibs"])
	requireNativeLibs = names(apexManifestRule.Args["requireNativeLibs"])
	ensureListEmpty(t, provideNativeLibs)
	ensureListEmpty(t, requireNativeLibs)

	apexManifestRule = ctx.ModuleForTests("myapex_dep", "android_common_myapex_dep_image").Rule("apexManifestRule")
	provideNativeLibs = names(apexManifestRule.Args["provideNativeLibs"])
	requireNativeLibs = names(apexManifestRule.Args["requireNativeLibs"])
	ensureListEmpty(t, provideNativeLibs)
	ensureListContains(t, requireNativeLibs, "libfoo.so")

	apexManifestRule = ctx.ModuleForTests("myapex_provider", "android_common_myapex_provider_image").Rule("apexManifestRule")
	provideNativeLibs = names(apexManifestRule.Args["provideNativeLibs"])
	requireNativeLibs = names(apexManifestRule.Args["requireNativeLibs"])
	ensureListContains(t, provideNativeLibs, "libfoo.so")
	ensureListEmpty(t, requireNativeLibs)

	apexManifestRule = ctx.ModuleForTests("myapex_selfcontained", "android_common_myapex_selfcontained_image").Rule("apexManifestRule")
	provideNativeLibs = names(apexManifestRule.Args["provideNativeLibs"])
	requireNativeLibs = names(apexManifestRule.Args["requireNativeLibs"])
	ensureListContains(t, provideNativeLibs, "libfoo.so")
	ensureListEmpty(t, requireNativeLibs)
}

func TestApexName(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apex_name: "com.android.myapex",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}
	`)

	module := ctx.ModuleForTests("myapex", "android_common_com.android.myapex_image")
	apexManifestRule := module.Rule("apexManifestRule")
	ensureContains(t, apexManifestRule.Args["opt"], "-v name com.android.myapex")
	apexRule := module.Rule("apexRule")
	ensureContains(t, apexRule.Args["opt_flags"], "--do_not_check_keyname")

	apexBundle := module.Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, apexBundle)
	name := apexBundle.BaseModuleName()
	prefix := "TARGET_"
	var builder strings.Builder
	data.Custom(&builder, name, prefix, "", data)
	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_MODULE := mylib.myapex\n")
	ensureNotContains(t, androidMk, "LOCAL_MODULE := mylib.com.android.myapex\n")
}

func TestNonTestApex(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib_common"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib_common",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
					"//apex_available:platform",
				  "myapex",
		  ],
		}
	`)

	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	apexRule := module.Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	if apex, ok := module.Module().(*apexBundle); !ok || apex.testApex {
		t.Log("Apex was a test apex!")
		t.Fail()
	}
	// Ensure that main rule creates an output
	ensureContains(t, apexRule.Output.String(), "myapex.apex.unsigned")

	// Ensure that apex variant is created for the direct dep
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib_common"), "android_arm64_armv8-a_shared_apex10000")

	// Ensure that both direct and indirect deps are copied into apex
	ensureContains(t, copyCmds, "image.apex/lib64/mylib_common.so")

	// Ensure that the platform variant ends with _shared
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib_common"), "android_arm64_armv8-a_shared")

	if !ctx.ModuleForTests("mylib_common", "android_arm64_armv8-a_shared_apex10000").Module().(*cc.Module).InAnyApex() {
		t.Log("Found mylib_common not in any apex!")
		t.Fail()
	}
}

func TestTestApex(t *testing.T) {
	ctx := testApex(t, `
		apex_test {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib_common_test"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib_common_test",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}
	`)

	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	apexRule := module.Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	if apex, ok := module.Module().(*apexBundle); !ok || !apex.testApex {
		t.Log("Apex was not a test apex!")
		t.Fail()
	}
	// Ensure that main rule creates an output
	ensureContains(t, apexRule.Output.String(), "myapex.apex.unsigned")

	// Ensure that apex variant is created for the direct dep
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib_common_test"), "android_arm64_armv8-a_shared_apex10000")

	// Ensure that both direct and indirect deps are copied into apex
	ensureContains(t, copyCmds, "image.apex/lib64/mylib_common_test.so")

	// Ensure that the platform variant ends with _shared
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib_common_test"), "android_arm64_armv8-a_shared")
}

func TestApexWithTarget(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
			multilib: {
				first: {
					native_shared_libs: ["mylib_common"],
				}
			},
			target: {
				android: {
					multilib: {
						first: {
							native_shared_libs: ["mylib"],
						}
					}
				},
				host: {
					multilib: {
						first: {
							native_shared_libs: ["mylib2"],
						}
					}
				}
			}
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		cc_library {
			name: "mylib_common",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			compile_multilib: "first",
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			compile_multilib: "first",
		}
	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that main rule creates an output
	ensureContains(t, apexRule.Output.String(), "myapex.apex.unsigned")

	// Ensure that apex variant is created for the direct dep
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib"), "android_arm64_armv8-a_shared_apex10000")
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib_common"), "android_arm64_armv8-a_shared_apex10000")
	ensureListNotContains(t, ctx.ModuleVariantsForTests("mylib2"), "android_arm64_armv8-a_shared_apex10000")

	// Ensure that both direct and indirect deps are copied into apex
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.so")
	ensureContains(t, copyCmds, "image.apex/lib64/mylib_common.so")
	ensureNotContains(t, copyCmds, "image.apex/lib64/mylib2.so")

	// Ensure that the platform variant ends with _shared
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib"), "android_arm64_armv8-a_shared")
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib_common"), "android_arm64_armv8-a_shared")
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib2"), "android_arm64_armv8-a_shared")
}

func TestApexWithArch(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
			arch: {
				arm64: {
					native_shared_libs: ["mylib.arm64"],
				},
				x86_64: {
					native_shared_libs: ["mylib.x64"],
				},
			}
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib.arm64",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}

		cc_library {
			name: "mylib.x64",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			// TODO: remove //apex_available:platform
			apex_available: [
				"//apex_available:platform",
				"myapex",
			],
		}
	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that apex variant is created for the direct dep
	ensureListContains(t, ctx.ModuleVariantsForTests("mylib.arm64"), "android_arm64_armv8-a_shared_apex10000")
	ensureListNotContains(t, ctx.ModuleVariantsForTests("mylib.x64"), "android_arm64_armv8-a_shared_apex10000")

	// Ensure that both direct and indirect deps are copied into apex
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.arm64.so")
	ensureNotContains(t, copyCmds, "image.apex/lib64/mylib.x64.so")
}

func TestApexWithShBinary(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			binaries: ["myscript"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		sh_binary {
			name: "myscript",
			src: "mylib.cpp",
			filename: "myscript.sh",
			sub_dir: "script",
		}
	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	ensureContains(t, copyCmds, "image.apex/bin/script/myscript.sh")
}

func TestApexInVariousPartition(t *testing.T) {
	testcases := []struct {
		propName, parition, flattenedPartition string
	}{
		{"", "system", "system_ext"},
		{"product_specific: true", "product", "product"},
		{"soc_specific: true", "vendor", "vendor"},
		{"proprietary: true", "vendor", "vendor"},
		{"vendor: true", "vendor", "vendor"},
		{"system_ext_specific: true", "system_ext", "system_ext"},
	}
	for _, tc := range testcases {
		t.Run(tc.propName+":"+tc.parition, func(t *testing.T) {
			ctx := testApex(t, `
				apex {
					name: "myapex",
					key: "myapex.key",
					updatable: false,
					`+tc.propName+`
				}

				apex_key {
					name: "myapex.key",
					public_key: "testkey.avbpubkey",
					private_key: "testkey.pem",
				}
			`)

			apex := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
			expected := "out/soong/target/product/test_device/" + tc.parition + "/apex"
			actual := apex.installDir.RelativeToTop().String()
			if actual != expected {
				t.Errorf("wrong install path. expected %q. actual %q", expected, actual)
			}

			flattened := ctx.ModuleForTests("myapex", "android_common_myapex_flattened").Module().(*apexBundle)
			expected = "out/soong/target/product/test_device/" + tc.flattenedPartition + "/apex"
			actual = flattened.installDir.RelativeToTop().String()
			if actual != expected {
				t.Errorf("wrong install path. expected %q. actual %q", expected, actual)
			}
		})
	}
}

func TestFileContexts_FindInDefaultLocationIfNotSet(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`)
	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	rule := module.Output("file_contexts")
	ensureContains(t, rule.RuleParams.Command, "cat system/sepolicy/apex/myapex-file_contexts")
}

func TestFileContexts_ShouldBeUnderSystemSepolicyForSystemApexes(t *testing.T) {
	testApexError(t, `"myapex" .*: file_contexts: should be under system/sepolicy`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			file_contexts: "my_own_file_contexts",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`, withFiles(map[string][]byte{
		"my_own_file_contexts": nil,
	}))
}

func TestFileContexts_ProductSpecificApexes(t *testing.T) {
	testApexError(t, `"myapex" .*: file_contexts: cannot find`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			product_specific: true,
			file_contexts: "product_specific_file_contexts",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`)

	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			product_specific: true,
			file_contexts: "product_specific_file_contexts",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`, withFiles(map[string][]byte{
		"product_specific_file_contexts": nil,
	}))
	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	rule := module.Output("file_contexts")
	ensureContains(t, rule.RuleParams.Command, "cat product_specific_file_contexts")
}

func TestFileContexts_SetViaFileGroup(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			product_specific: true,
			file_contexts: ":my-file-contexts",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		filegroup {
			name: "my-file-contexts",
			srcs: ["product_specific_file_contexts"],
		}
	`, withFiles(map[string][]byte{
		"product_specific_file_contexts": nil,
	}))
	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	rule := module.Output("file_contexts")
	ensureContains(t, rule.RuleParams.Command, "cat product_specific_file_contexts")
}

func TestApexKeyFromOtherModule(t *testing.T) {
	ctx := testApex(t, `
		apex_key {
			name: "myapex.key",
			public_key: ":my.avbpubkey",
			private_key: ":my.pem",
			product_specific: true,
		}

		filegroup {
			name: "my.avbpubkey",
			srcs: ["testkey2.avbpubkey"],
		}

		filegroup {
			name: "my.pem",
			srcs: ["testkey2.pem"],
		}
	`)

	apex_key := ctx.ModuleForTests("myapex.key", "android_common").Module().(*apexKey)
	expected_pubkey := "testkey2.avbpubkey"
	actual_pubkey := apex_key.publicKeyFile.String()
	if actual_pubkey != expected_pubkey {
		t.Errorf("wrong public key path. expected %q. actual %q", expected_pubkey, actual_pubkey)
	}
	expected_privkey := "testkey2.pem"
	actual_privkey := apex_key.privateKeyFile.String()
	if actual_privkey != expected_privkey {
		t.Errorf("wrong private key path. expected %q. actual %q", expected_privkey, actual_privkey)
	}
}

func TestPrebuilt(t *testing.T) {
	ctx := testApex(t, `
		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
		}
	`)

	prebuilt := ctx.ModuleForTests("myapex", "android_common_myapex").Module().(*Prebuilt)

	expectedInput := "myapex-arm64.apex"
	if prebuilt.inputApex.String() != expectedInput {
		t.Errorf("inputApex invalid. expected: %q, actual: %q", expectedInput, prebuilt.inputApex.String())
	}
}

func TestPrebuiltMissingSrc(t *testing.T) {
	testApexError(t, `module "myapex" variant "android_common_myapex".*: prebuilt_apex does not support "arm64_armv8-a"`, `
		prebuilt_apex {
			name: "myapex",
		}
	`)
}

func TestPrebuiltFilenameOverride(t *testing.T) {
	ctx := testApex(t, `
		prebuilt_apex {
			name: "myapex",
			src: "myapex-arm.apex",
			filename: "notmyapex.apex",
		}
	`)

	p := ctx.ModuleForTests("myapex", "android_common_myapex").Module().(*Prebuilt)

	expected := "notmyapex.apex"
	if p.installFilename != expected {
		t.Errorf("installFilename invalid. expected: %q, actual: %q", expected, p.installFilename)
	}
}

func TestPrebuiltOverrides(t *testing.T) {
	ctx := testApex(t, `
		prebuilt_apex {
			name: "myapex.prebuilt",
			src: "myapex-arm.apex",
			overrides: [
				"myapex",
			],
		}
	`)

	p := ctx.ModuleForTests("myapex.prebuilt", "android_common_myapex.prebuilt").Module().(*Prebuilt)

	expected := []string{"myapex"}
	actual := android.AndroidMkEntriesForTest(t, ctx, p)[0].EntryMap["LOCAL_OVERRIDES_MODULES"]
	if !reflect.DeepEqual(actual, expected) {
		t.Errorf("Incorrect LOCAL_OVERRIDES_MODULES value '%s', expected '%s'", actual, expected)
	}
}

func TestPrebuiltApexName(t *testing.T) {
	testApex(t, `
		prebuilt_apex {
			name: "com.company.android.myapex",
			apex_name: "com.android.myapex",
			src: "company-myapex-arm.apex",
		}
	`).ModuleForTests("com.company.android.myapex", "android_common_com.android.myapex")

	testApex(t, `
		apex_set {
			name: "com.company.android.myapex",
			apex_name: "com.android.myapex",
			set: "company-myapex.apks",
		}
	`).ModuleForTests("com.company.android.myapex", "android_common_com.android.myapex")
}

func TestPrebuiltApexNameWithPlatformBootclasspath(t *testing.T) {
	_ = android.GroupFixturePreparers(
		java.PrepareForTestWithJavaDefaultModules,
		PrepareForTestWithApexBuildComponents,
		android.FixtureWithRootAndroidBp(`
			platform_bootclasspath {
				name: "platform-bootclasspath",
				fragments: [
					{
						apex: "com.android.art",
						module: "art-bootclasspath-fragment",
					},
				],
			}

			prebuilt_apex {
				name: "com.company.android.art",
				apex_name: "com.android.art",
				src: "com.company.android.art-arm.apex",
				exported_bootclasspath_fragments: ["art-bootclasspath-fragment"],
			}

			prebuilt_bootclasspath_fragment {
				name: "art-bootclasspath-fragment",
				contents: ["core-oj"],
			}

			java_import {
				name: "core-oj",
				jars: ["prebuilt.jar"],
			}
		`),
	).RunTest(t)
}

// These tests verify that the prebuilt_apex/deapexer to java_import wiring allows for the
// propagation of paths to dex implementation jars from the former to the latter.
func TestPrebuiltExportDexImplementationJars(t *testing.T) {
	transform := android.NullFixturePreparer

	checkDexJarBuildPath := func(t *testing.T, ctx *android.TestContext, name string) {
		// Make sure the import has been given the correct path to the dex jar.
		p := ctx.ModuleForTests(name, "android_common_myapex").Module().(java.UsesLibraryDependency)
		dexJarBuildPath := p.DexJarBuildPath()
		stem := android.RemoveOptionalPrebuiltPrefix(name)
		if expected, actual := ".intermediates/myapex.deapexer/android_common/deapexer/javalib/"+stem+".jar", android.NormalizePathForTesting(dexJarBuildPath); actual != expected {
			t.Errorf("Incorrect DexJarBuildPath value '%s', expected '%s'", actual, expected)
		}
	}

	ensureNoSourceVariant := func(t *testing.T, ctx *android.TestContext, name string) {
		// Make sure that an apex variant is not created for the source module.
		if expected, actual := []string{"android_common"}, ctx.ModuleVariantsForTests(name); !reflect.DeepEqual(expected, actual) {
			t.Errorf("invalid set of variants for %q: expected %q, found %q", "libfoo", expected, actual)
		}
	}

	t.Run("prebuilt only", func(t *testing.T) {
		bp := `
		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
			exported_java_libs: ["libfoo", "libbar"],
		}

		java_import {
			name: "libfoo",
			jars: ["libfoo.jar"],
		}

		java_sdk_library_import {
			name: "libbar",
			public: {
				jars: ["libbar.jar"],
			},
		}
	`

		// Make sure that dexpreopt can access dex implementation files from the prebuilt.
		ctx := testDexpreoptWithApexes(t, bp, "", transform)

		// Make sure that the deapexer has the correct input APEX.
		deapexer := ctx.ModuleForTests("myapex.deapexer", "android_common")
		rule := deapexer.Rule("deapexer")
		if expected, actual := []string{"myapex-arm64.apex"}, android.NormalizePathsForTesting(rule.Implicits); !reflect.DeepEqual(expected, actual) {
			t.Errorf("expected: %q, found: %q", expected, actual)
		}

		// Make sure that the prebuilt_apex has the correct input APEX.
		prebuiltApex := ctx.ModuleForTests("myapex", "android_common_myapex")
		rule = prebuiltApex.Rule("android/soong/android.Cp")
		if expected, actual := "myapex-arm64.apex", android.NormalizePathForTesting(rule.Input); !reflect.DeepEqual(expected, actual) {
			t.Errorf("expected: %q, found: %q", expected, actual)
		}

		checkDexJarBuildPath(t, ctx, "libfoo")

		checkDexJarBuildPath(t, ctx, "libbar")
	})

	t.Run("prebuilt with source preferred", func(t *testing.T) {

		bp := `
		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
			exported_java_libs: ["libfoo", "libbar"],
		}

		java_import {
			name: "libfoo",
			jars: ["libfoo.jar"],
		}

		java_library {
			name: "libfoo",
		}

		java_sdk_library_import {
			name: "libbar",
			public: {
				jars: ["libbar.jar"],
			},
		}

		java_sdk_library {
			name: "libbar",
			srcs: ["foo/bar/MyClass.java"],
			unsafe_ignore_missing_latest_api: true,
		}
	`

		// Make sure that dexpreopt can access dex implementation files from the prebuilt.
		ctx := testDexpreoptWithApexes(t, bp, "", transform)

		checkDexJarBuildPath(t, ctx, "prebuilt_libfoo")
		ensureNoSourceVariant(t, ctx, "libfoo")

		checkDexJarBuildPath(t, ctx, "prebuilt_libbar")
		ensureNoSourceVariant(t, ctx, "libbar")
	})

	t.Run("prebuilt preferred with source", func(t *testing.T) {
		bp := `
		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
			exported_java_libs: ["libfoo", "libbar"],
		}

		java_import {
			name: "libfoo",
			prefer: true,
			jars: ["libfoo.jar"],
		}

		java_library {
			name: "libfoo",
		}

		java_sdk_library_import {
			name: "libbar",
			prefer: true,
			public: {
				jars: ["libbar.jar"],
			},
		}

		java_sdk_library {
			name: "libbar",
			srcs: ["foo/bar/MyClass.java"],
			unsafe_ignore_missing_latest_api: true,
		}
	`

		// Make sure that dexpreopt can access dex implementation files from the prebuilt.
		ctx := testDexpreoptWithApexes(t, bp, "", transform)

		checkDexJarBuildPath(t, ctx, "prebuilt_libfoo")
		ensureNoSourceVariant(t, ctx, "libfoo")

		checkDexJarBuildPath(t, ctx, "prebuilt_libbar")
		ensureNoSourceVariant(t, ctx, "libbar")
	})
}

func TestBootDexJarsFromSourcesAndPrebuilts(t *testing.T) {
	preparer := android.GroupFixturePreparers(
		java.FixtureConfigureBootJars("myapex:libfoo", "myapex:libbar"),
		// Make sure that the frameworks/base/Android.bp file exists as otherwise hidden API encoding
		// is disabled.
		android.FixtureAddTextFile("frameworks/base/Android.bp", ""),
	)

	checkBootDexJarPath := func(t *testing.T, ctx *android.TestContext, stem string, bootDexJarPath string) {
		t.Helper()
		s := ctx.ModuleForTests("platform-bootclasspath", "android_common")
		foundLibfooJar := false
		base := stem + ".jar"
		for _, output := range s.AllOutputs() {
			if filepath.Base(output) == base {
				foundLibfooJar = true
				buildRule := s.Output(output)
				android.AssertStringEquals(t, "boot dex jar path", bootDexJarPath, buildRule.Input.String())
			}
		}
		if !foundLibfooJar {
			t.Errorf("Rule for libfoo.jar missing in dex_bootjars singleton outputs %q", android.StringPathsRelativeToTop(ctx.Config().BuildDir(), s.AllOutputs()))
		}
	}

	checkHiddenAPIIndexInputs := func(t *testing.T, ctx *android.TestContext, expectedIntermediateInputs string) {
		t.Helper()
		platformBootclasspath := ctx.ModuleForTests("platform-bootclasspath", "android_common")
		var rule android.TestingBuildParams

		rule = platformBootclasspath.Output("hiddenapi-monolithic/index-from-classes.csv")
		java.CheckHiddenAPIRuleInputs(t, "intermediate index", expectedIntermediateInputs, rule)
	}

	fragment := java.ApexVariantReference{
		Apex:   proptools.StringPtr("myapex"),
		Module: proptools.StringPtr("my-bootclasspath-fragment"),
	}

	t.Run("prebuilt only", func(t *testing.T) {
		bp := `
		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
			exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
		}

		prebuilt_bootclasspath_fragment {
			name: "my-bootclasspath-fragment",
			contents: ["libfoo", "libbar"],
			apex_available: ["myapex"],
		}

		java_import {
			name: "libfoo",
			jars: ["libfoo.jar"],
			apex_available: ["myapex"],
		}

		java_sdk_library_import {
			name: "libbar",
			public: {
				jars: ["libbar.jar"],
			},
			apex_available: ["myapex"],
			shared_library: false,
		}
	`

		ctx := testDexpreoptWithApexes(t, bp, "", preparer, fragment)
		checkBootDexJarPath(t, ctx, "libfoo", "out/soong/.intermediates/myapex.deapexer/android_common/deapexer/javalib/libfoo.jar")
		checkBootDexJarPath(t, ctx, "libbar", "out/soong/.intermediates/myapex.deapexer/android_common/deapexer/javalib/libbar.jar")

		// Verify the correct module jars contribute to the hiddenapi index file.
		checkHiddenAPIIndexInputs(t, ctx, `
			out/soong/.intermediates/libbar.stubs/android_common/combined/libbar.stubs.jar
			out/soong/.intermediates/libfoo/android_common_myapex/combined/libfoo.jar
		`)
	})

	t.Run("apex_set only", func(t *testing.T) {
		bp := `
		apex_set {
			name: "myapex",
			set: "myapex.apks",
			exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
		}

		prebuilt_bootclasspath_fragment {
			name: "my-bootclasspath-fragment",
			contents: ["libfoo", "libbar"],
			apex_available: ["myapex"],
		}

		java_import {
			name: "libfoo",
			jars: ["libfoo.jar"],
			apex_available: ["myapex"],
		}

		java_sdk_library_import {
			name: "libbar",
			public: {
				jars: ["libbar.jar"],
			},
			apex_available: ["myapex"],
			shared_library: false,
		}
	`

		ctx := testDexpreoptWithApexes(t, bp, "", preparer, fragment)
		checkBootDexJarPath(t, ctx, "libfoo", "out/soong/.intermediates/myapex.deapexer/android_common/deapexer/javalib/libfoo.jar")
		checkBootDexJarPath(t, ctx, "libbar", "out/soong/.intermediates/myapex.deapexer/android_common/deapexer/javalib/libbar.jar")

		// Verify the correct module jars contribute to the hiddenapi index file.
		checkHiddenAPIIndexInputs(t, ctx, `
			out/soong/.intermediates/libbar.stubs/android_common/combined/libbar.stubs.jar
			out/soong/.intermediates/libfoo/android_common_myapex/combined/libfoo.jar
		`)
	})

	t.Run("prebuilt with source library preferred", func(t *testing.T) {
		bp := `
		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
			exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
		}

		prebuilt_bootclasspath_fragment {
			name: "my-bootclasspath-fragment",
			contents: ["libfoo", "libbar"],
			apex_available: ["myapex"],
		}

		java_import {
			name: "libfoo",
			jars: ["libfoo.jar"],
			apex_available: ["myapex"],
		}

		java_library {
			name: "libfoo",
			srcs: ["foo/bar/MyClass.java"],
			apex_available: ["myapex"],
		}

		java_sdk_library_import {
			name: "libbar",
			public: {
				jars: ["libbar.jar"],
			},
			apex_available: ["myapex"],
			shared_library: false,
		}

		java_sdk_library {
			name: "libbar",
			srcs: ["foo/bar/MyClass.java"],
			unsafe_ignore_missing_latest_api: true,
			apex_available: ["myapex"],
		}
	`

		// In this test the source (java_library) libfoo is active since the
		// prebuilt (java_import) defaults to prefer:false. However the
		// prebuilt_apex module always depends on the prebuilt, and so it doesn't
		// find the dex boot jar in it. We either need to disable the source libfoo
		// or make the prebuilt libfoo preferred.
		testDexpreoptWithApexes(t, bp, "module libfoo does not provide a dex boot jar", preparer, fragment)
	})

	t.Run("prebuilt library preferred with source", func(t *testing.T) {
		bp := `
		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
			exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
		}

		prebuilt_bootclasspath_fragment {
			name: "my-bootclasspath-fragment",
			contents: ["libfoo", "libbar"],
			apex_available: ["myapex"],
		}

		java_import {
			name: "libfoo",
			prefer: true,
			jars: ["libfoo.jar"],
			apex_available: ["myapex"],
		}

		java_library {
			name: "libfoo",
			srcs: ["foo/bar/MyClass.java"],
			apex_available: ["myapex"],
		}

		java_sdk_library_import {
			name: "libbar",
			prefer: true,
			public: {
				jars: ["libbar.jar"],
			},
			apex_available: ["myapex"],
			shared_library: false,
		}

		java_sdk_library {
			name: "libbar",
			srcs: ["foo/bar/MyClass.java"],
			unsafe_ignore_missing_latest_api: true,
			apex_available: ["myapex"],
		}
	`

		ctx := testDexpreoptWithApexes(t, bp, "", preparer, fragment)
		checkBootDexJarPath(t, ctx, "libfoo", "out/soong/.intermediates/myapex.deapexer/android_common/deapexer/javalib/libfoo.jar")
		checkBootDexJarPath(t, ctx, "libbar", "out/soong/.intermediates/myapex.deapexer/android_common/deapexer/javalib/libbar.jar")

		// Verify the correct module jars contribute to the hiddenapi index file.
		checkHiddenAPIIndexInputs(t, ctx, `
			out/soong/.intermediates/prebuilt_libbar.stubs/android_common/combined/libbar.stubs.jar
			out/soong/.intermediates/prebuilt_libfoo/android_common_myapex/combined/libfoo.jar
		`)
	})

	t.Run("prebuilt with source apex preferred", func(t *testing.T) {
		bp := `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["libfoo", "libbar"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
			exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
		}

		prebuilt_bootclasspath_fragment {
			name: "my-bootclasspath-fragment",
			contents: ["libfoo", "libbar"],
			apex_available: ["myapex"],
		}

		java_import {
			name: "libfoo",
			jars: ["libfoo.jar"],
			apex_available: ["myapex"],
		}

		java_library {
			name: "libfoo",
			srcs: ["foo/bar/MyClass.java"],
			apex_available: ["myapex"],
		}

		java_sdk_library_import {
			name: "libbar",
			public: {
				jars: ["libbar.jar"],
			},
			apex_available: ["myapex"],
			shared_library: false,
		}

		java_sdk_library {
			name: "libbar",
			srcs: ["foo/bar/MyClass.java"],
			unsafe_ignore_missing_latest_api: true,
			apex_available: ["myapex"],
		}
	`

		ctx := testDexpreoptWithApexes(t, bp, "", preparer, fragment)
		checkBootDexJarPath(t, ctx, "libfoo", "out/soong/.intermediates/libfoo/android_common_apex10000/hiddenapi/libfoo.jar")
		checkBootDexJarPath(t, ctx, "libbar", "out/soong/.intermediates/libbar/android_common_myapex/hiddenapi/libbar.jar")

		// Verify the correct module jars contribute to the hiddenapi index file.
		checkHiddenAPIIndexInputs(t, ctx, `
			out/soong/.intermediates/libbar/android_common_myapex/javac/libbar.jar
			out/soong/.intermediates/libfoo/android_common_apex10000/javac/libfoo.jar
		`)
	})

	t.Run("prebuilt preferred with source apex disabled", func(t *testing.T) {
		bp := `
		apex {
			name: "myapex",
			enabled: false,
			key: "myapex.key",
			java_libs: ["libfoo", "libbar"],
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		prebuilt_apex {
			name: "myapex",
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
			exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
		}

		prebuilt_bootclasspath_fragment {
			name: "my-bootclasspath-fragment",
			contents: ["libfoo", "libbar"],
			apex_available: ["myapex"],
		}

		java_import {
			name: "libfoo",
			prefer: true,
			jars: ["libfoo.jar"],
			apex_available: ["myapex"],
		}

		java_library {
			name: "libfoo",
			srcs: ["foo/bar/MyClass.java"],
			apex_available: ["myapex"],
		}

		java_sdk_library_import {
			name: "libbar",
			prefer: true,
			public: {
				jars: ["libbar.jar"],
			},
			apex_available: ["myapex"],
			shared_library: false,
		}

		java_sdk_library {
			name: "libbar",
			srcs: ["foo/bar/MyClass.java"],
			unsafe_ignore_missing_latest_api: true,
			apex_available: ["myapex"],
		}
	`

		ctx := testDexpreoptWithApexes(t, bp, "", preparer, fragment)
		checkBootDexJarPath(t, ctx, "libfoo", "out/soong/.intermediates/myapex.deapexer/android_common/deapexer/javalib/libfoo.jar")
		checkBootDexJarPath(t, ctx, "libbar", "out/soong/.intermediates/myapex.deapexer/android_common/deapexer/javalib/libbar.jar")

		// Verify the correct module jars contribute to the hiddenapi index file.
		checkHiddenAPIIndexInputs(t, ctx, `
			out/soong/.intermediates/prebuilt_libbar.stubs/android_common/combined/libbar.stubs.jar
			out/soong/.intermediates/prebuilt_libfoo/android_common_myapex/combined/libfoo.jar
		`)
	})
}

func TestApexWithTests(t *testing.T) {
	ctx := testApex(t, `
		apex_test {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
			tests: [
				"mytest",
				"mytests",
			],
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		filegroup {
			name: "fg",
			srcs: [
				"baz",
				"bar/baz"
			],
		}

		cc_test {
			name: "mytest",
			gtest: false,
			srcs: ["mytest.cpp"],
			relative_install_path: "test",
			shared_libs: ["mylib"],
			system_shared_libs: [],
			static_executable: true,
			stl: "none",
			data: [":fg"],
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
		}

		filegroup {
			name: "fg2",
			srcs: [
				"testdata/baz"
			],
		}

		cc_test {
			name: "mytests",
			gtest: false,
			srcs: [
				"mytest1.cpp",
				"mytest2.cpp",
				"mytest3.cpp",
			],
			test_per_src: true,
			relative_install_path: "test",
			system_shared_libs: [],
			static_executable: true,
			stl: "none",
			data: [
				":fg",
				":fg2",
			],
		}
	`)

	apexRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	// Ensure that test dep (and their transitive dependencies) are copied into apex.
	ensureContains(t, copyCmds, "image.apex/bin/test/mytest")
	ensureContains(t, copyCmds, "image.apex/lib64/mylib.so")

	//Ensure that test data are copied into apex.
	ensureContains(t, copyCmds, "image.apex/bin/test/baz")
	ensureContains(t, copyCmds, "image.apex/bin/test/bar/baz")

	// Ensure that test deps built with `test_per_src` are copied into apex.
	ensureContains(t, copyCmds, "image.apex/bin/test/mytest1")
	ensureContains(t, copyCmds, "image.apex/bin/test/mytest2")
	ensureContains(t, copyCmds, "image.apex/bin/test/mytest3")

	// Ensure the module is correctly translated.
	bundle := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, bundle)
	name := bundle.BaseModuleName()
	prefix := "TARGET_"
	var builder strings.Builder
	data.Custom(&builder, name, prefix, "", data)
	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_MODULE := mytest.myapex\n")
	ensureContains(t, androidMk, "LOCAL_MODULE := mytest1.myapex\n")
	ensureContains(t, androidMk, "LOCAL_MODULE := mytest2.myapex\n")
	ensureContains(t, androidMk, "LOCAL_MODULE := mytest3.myapex\n")
	ensureContains(t, androidMk, "LOCAL_MODULE := apex_manifest.pb.myapex\n")
	ensureContains(t, androidMk, "LOCAL_MODULE := apex_pubkey.myapex\n")
	ensureContains(t, androidMk, "LOCAL_MODULE := myapex\n")

	flatBundle := ctx.ModuleForTests("myapex", "android_common_myapex_flattened").Module().(*apexBundle)
	data = android.AndroidMkDataForTest(t, ctx, flatBundle)
	data.Custom(&builder, name, prefix, "", data)
	flatAndroidMk := builder.String()
	ensureContainsOnce(t, flatAndroidMk, "LOCAL_TEST_DATA := :baz :bar/baz\n")
	ensureContainsOnce(t, flatAndroidMk, "LOCAL_TEST_DATA := :testdata/baz\n")
}

func TestInstallExtraFlattenedApexes(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`,
		android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
			variables.InstallExtraFlattenedApexes = proptools.BoolPtr(true)
		}),
	)
	ab := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	ensureListContains(t, ab.requiredDeps, "myapex.flattened")
	mk := android.AndroidMkDataForTest(t, ctx, ab)
	var builder strings.Builder
	mk.Custom(&builder, ab.Name(), "TARGET_", "", mk)
	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_REQUIRED_MODULES += myapex.flattened")
}

func TestErrorsIfDepsAreNotEnabled(t *testing.T) {
	testApexError(t, `module "myapex" .* depends on disabled module "libfoo"`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["libfoo"],
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "libfoo",
			stl: "none",
			system_shared_libs: [],
			enabled: false,
			apex_available: ["myapex"],
		}
	`)
	testApexError(t, `module "myapex" .* depends on disabled module "myjar"`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["myjar"],
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_library {
			name: "myjar",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			enabled: false,
			apex_available: ["myapex"],
		}
	`)
}

func TestApexWithJavaImport(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["myjavaimport"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_import {
			name: "myjavaimport",
			apex_available: ["myapex"],
			jars: ["my.jar"],
			compile_dex: true,
		}
	`)

	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	apexRule := module.Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]
	ensureContains(t, copyCmds, "image.apex/javalib/myjavaimport.jar")
}

func TestApexWithApps(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: [
				"AppFoo",
				"AppFooPriv",
			],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_app {
			name: "AppFoo",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "current",
			system_modules: "none",
			jni_libs: ["libjni"],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		android_app {
			name: "AppFooPriv",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "current",
			system_modules: "none",
			privileged: true,
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library_shared {
			name: "libjni",
			srcs: ["mylib.cpp"],
			shared_libs: ["libfoo"],
			stl: "none",
			system_shared_libs: [],
			apex_available: [ "myapex" ],
			sdk_version: "current",
		}

		cc_library_shared {
			name: "libfoo",
			stl: "none",
			system_shared_libs: [],
			apex_available: [ "myapex" ],
			sdk_version: "current",
		}
	`)

	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	apexRule := module.Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	ensureContains(t, copyCmds, "image.apex/app/AppFoo/AppFoo.apk")
	ensureContains(t, copyCmds, "image.apex/priv-app/AppFooPriv/AppFooPriv.apk")

	appZipRule := ctx.ModuleForTests("AppFoo", "android_common_apex10000").Description("zip jni libs")
	// JNI libraries are uncompressed
	if args := appZipRule.Args["jarArgs"]; !strings.Contains(args, "-L 0") {
		t.Errorf("jni libs are not uncompressed for AppFoo")
	}
	// JNI libraries including transitive deps are
	for _, jni := range []string{"libjni", "libfoo"} {
		jniOutput := ctx.ModuleForTests(jni, "android_arm64_armv8-a_sdk_shared_apex10000").Module().(*cc.Module).OutputFile().RelativeToTop()
		// ... embedded inside APK (jnilibs.zip)
		ensureListContains(t, appZipRule.Implicits.Strings(), jniOutput.String())
		// ... and not directly inside the APEX
		ensureNotContains(t, copyCmds, "image.apex/lib64/"+jni+".so")
	}
}

func TestApexWithAppImports(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: [
				"AppFooPrebuilt",
				"AppFooPrivPrebuilt",
			],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_app_import {
			name: "AppFooPrebuilt",
			apk: "PrebuiltAppFoo.apk",
			presigned: true,
			dex_preopt: {
				enabled: false,
			},
			apex_available: ["myapex"],
		}

		android_app_import {
			name: "AppFooPrivPrebuilt",
			apk: "PrebuiltAppFooPriv.apk",
			privileged: true,
			presigned: true,
			dex_preopt: {
				enabled: false,
			},
			filename: "AwesomePrebuiltAppFooPriv.apk",
			apex_available: ["myapex"],
		}
	`)

	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	apexRule := module.Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	ensureContains(t, copyCmds, "image.apex/app/AppFooPrebuilt/AppFooPrebuilt.apk")
	ensureContains(t, copyCmds, "image.apex/priv-app/AppFooPrivPrebuilt/AwesomePrebuiltAppFooPriv.apk")
}

func TestApexWithAppImportsPrefer(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: [
				"AppFoo",
			],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_app {
			name: "AppFoo",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			apex_available: [ "myapex" ],
		}

		android_app_import {
			name: "AppFoo",
			apk: "AppFooPrebuilt.apk",
			filename: "AppFooPrebuilt.apk",
			presigned: true,
			prefer: true,
			apex_available: ["myapex"],
		}
	`, withFiles(map[string][]byte{
		"AppFooPrebuilt.apk": nil,
	}))

	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"app/AppFoo/AppFooPrebuilt.apk",
	})
}

func TestApexWithTestHelperApp(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: [
				"TesterHelpAppFoo",
			],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_test_helper_app {
			name: "TesterHelpAppFoo",
			srcs: ["foo/bar/MyClass.java"],
			apex_available: [ "myapex" ],
		}

	`)

	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	apexRule := module.Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	ensureContains(t, copyCmds, "image.apex/app/TesterHelpAppFoo/TesterHelpAppFoo.apk")
}

func TestApexPropertiesShouldBeDefaultable(t *testing.T) {
	// libfoo's apex_available comes from cc_defaults
	testApexError(t, `requires "libfoo" that doesn't list the APEX under 'apex_available'.`, `
	apex {
		name: "myapex",
		key: "myapex.key",
		native_shared_libs: ["libfoo"],
		updatable: false,
	}

	apex_key {
		name: "myapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}

	apex {
		name: "otherapex",
		key: "myapex.key",
		native_shared_libs: ["libfoo"],
		updatable: false,
	}

	cc_defaults {
		name: "libfoo-defaults",
		apex_available: ["otherapex"],
	}

	cc_library {
		name: "libfoo",
		defaults: ["libfoo-defaults"],
		stl: "none",
		system_shared_libs: [],
	}`)
}

func TestApexAvailable_DirectDep(t *testing.T) {
	// libfoo is not available to myapex, but only to otherapex
	testApexError(t, "requires \"libfoo\" that doesn't list the APEX under 'apex_available'.", `
	apex {
		name: "myapex",
		key: "myapex.key",
		native_shared_libs: ["libfoo"],
		updatable: false,
	}

	apex_key {
		name: "myapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}

	apex {
		name: "otherapex",
		key: "otherapex.key",
		native_shared_libs: ["libfoo"],
		updatable: false,
	}

	apex_key {
		name: "otherapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}

	cc_library {
		name: "libfoo",
		stl: "none",
		system_shared_libs: [],
		apex_available: ["otherapex"],
	}`)
}

func TestApexAvailable_IndirectDep(t *testing.T) {
	// libbbaz is an indirect dep
	testApexError(t, `requires "libbaz" that doesn't list the APEX under 'apex_available'.\n\nDependency path:
.*via tag apex\.dependencyTag.*name:sharedLib.*
.*-> libfoo.*link:shared.*
.*via tag cc\.libraryDependencyTag.*Kind:sharedLibraryDependency.*
.*-> libbar.*link:shared.*
.*via tag cc\.libraryDependencyTag.*Kind:sharedLibraryDependency.*
.*-> libbaz.*link:shared.*`, `
	apex {
		name: "myapex",
		key: "myapex.key",
		native_shared_libs: ["libfoo"],
		updatable: false,
	}

	apex_key {
		name: "myapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}

	cc_library {
		name: "libfoo",
		stl: "none",
		shared_libs: ["libbar"],
		system_shared_libs: [],
		apex_available: ["myapex"],
	}

	cc_library {
		name: "libbar",
		stl: "none",
		shared_libs: ["libbaz"],
		system_shared_libs: [],
		apex_available: ["myapex"],
	}

	cc_library {
		name: "libbaz",
		stl: "none",
		system_shared_libs: [],
	}`)
}

func TestApexAvailable_InvalidApexName(t *testing.T) {
	testApexError(t, "\"otherapex\" is not a valid module name", `
	apex {
		name: "myapex",
		key: "myapex.key",
		native_shared_libs: ["libfoo"],
		updatable: false,
	}

	apex_key {
		name: "myapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}

	cc_library {
		name: "libfoo",
		stl: "none",
		system_shared_libs: [],
		apex_available: ["otherapex"],
	}`)

	testApex(t, `
	apex {
		name: "myapex",
		key: "myapex.key",
		native_shared_libs: ["libfoo", "libbar"],
		updatable: false,
	}

	apex_key {
		name: "myapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}

	cc_library {
		name: "libfoo",
		stl: "none",
		system_shared_libs: [],
		runtime_libs: ["libbaz"],
		apex_available: ["myapex"],
	}

	cc_library {
		name: "libbar",
		stl: "none",
		system_shared_libs: [],
		apex_available: ["//apex_available:anyapex"],
	}

	cc_library {
		name: "libbaz",
		stl: "none",
		system_shared_libs: [],
		stubs: {
			versions: ["10", "20", "30"],
		},
	}`)
}

func TestApexAvailable_CheckForPlatform(t *testing.T) {
	ctx := testApex(t, `
	apex {
		name: "myapex",
		key: "myapex.key",
		native_shared_libs: ["libbar", "libbaz"],
		updatable: false,
	}

	apex_key {
		name: "myapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}

	cc_library {
		name: "libfoo",
		stl: "none",
		system_shared_libs: [],
		shared_libs: ["libbar"],
		apex_available: ["//apex_available:platform"],
	}

	cc_library {
		name: "libfoo2",
		stl: "none",
		system_shared_libs: [],
		shared_libs: ["libbaz"],
		apex_available: ["//apex_available:platform"],
	}

	cc_library {
		name: "libbar",
		stl: "none",
		system_shared_libs: [],
		apex_available: ["myapex"],
	}

	cc_library {
		name: "libbaz",
		stl: "none",
		system_shared_libs: [],
		apex_available: ["myapex"],
		stubs: {
			versions: ["1"],
		},
	}`)

	// libfoo shouldn't be available to platform even though it has "//apex_available:platform",
	// because it depends on libbar which isn't available to platform
	libfoo := ctx.ModuleForTests("libfoo", "android_arm64_armv8-a_shared").Module().(*cc.Module)
	if libfoo.NotAvailableForPlatform() != true {
		t.Errorf("%q shouldn't be available to platform", libfoo.String())
	}

	// libfoo2 however can be available to platform because it depends on libbaz which provides
	// stubs
	libfoo2 := ctx.ModuleForTests("libfoo2", "android_arm64_armv8-a_shared").Module().(*cc.Module)
	if libfoo2.NotAvailableForPlatform() == true {
		t.Errorf("%q should be available to platform", libfoo2.String())
	}
}

func TestApexAvailable_CreatedForApex(t *testing.T) {
	ctx := testApex(t, `
	apex {
		name: "myapex",
		key: "myapex.key",
		native_shared_libs: ["libfoo"],
		updatable: false,
	}

	apex_key {
		name: "myapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}

	cc_library {
		name: "libfoo",
		stl: "none",
		system_shared_libs: [],
		apex_available: ["myapex"],
		static: {
			apex_available: ["//apex_available:platform"],
		},
	}`)

	libfooShared := ctx.ModuleForTests("libfoo", "android_arm64_armv8-a_shared").Module().(*cc.Module)
	if libfooShared.NotAvailableForPlatform() != true {
		t.Errorf("%q shouldn't be available to platform", libfooShared.String())
	}
	libfooStatic := ctx.ModuleForTests("libfoo", "android_arm64_armv8-a_static").Module().(*cc.Module)
	if libfooStatic.NotAvailableForPlatform() != false {
		t.Errorf("%q should be available to platform", libfooStatic.String())
	}
}

func TestOverrideApex(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: ["app"],
			overrides: ["oldapex"],
			updatable: false,
		}

		override_apex {
			name: "override_myapex",
			base: "myapex",
			apps: ["override_app"],
			overrides: ["unknownapex"],
			logging_parent: "com.foo.bar",
			package_name: "test.overridden.package",
			key: "mynewapex.key",
			certificate: ":myapex.certificate",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		apex_key {
			name: "mynewapex.key",
			public_key: "testkey2.avbpubkey",
			private_key: "testkey2.pem",
		}

		android_app_certificate {
			name: "myapex.certificate",
			certificate: "testkey",
		}

		android_app {
			name: "app",
			srcs: ["foo/bar/MyClass.java"],
			package_name: "foo",
			sdk_version: "none",
			system_modules: "none",
			apex_available: [ "myapex" ],
		}

		override_android_app {
			name: "override_app",
			base: "app",
			package_name: "bar",
		}
	`, withManifestPackageNameOverrides([]string{"myapex:com.android.myapex"}))

	originalVariant := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(android.OverridableModule)
	overriddenVariant := ctx.ModuleForTests("myapex", "android_common_override_myapex_myapex_image").Module().(android.OverridableModule)
	if originalVariant.GetOverriddenBy() != "" {
		t.Errorf("GetOverriddenBy should be empty, but was %q", originalVariant.GetOverriddenBy())
	}
	if overriddenVariant.GetOverriddenBy() != "override_myapex" {
		t.Errorf("GetOverriddenBy should be \"override_myapex\", but was %q", overriddenVariant.GetOverriddenBy())
	}

	module := ctx.ModuleForTests("myapex", "android_common_override_myapex_myapex_image")
	apexRule := module.Rule("apexRule")
	copyCmds := apexRule.Args["copy_commands"]

	ensureNotContains(t, copyCmds, "image.apex/app/app/app.apk")
	ensureContains(t, copyCmds, "image.apex/app/override_app/override_app.apk")

	apexBundle := module.Module().(*apexBundle)
	name := apexBundle.Name()
	if name != "override_myapex" {
		t.Errorf("name should be \"override_myapex\", but was %q", name)
	}

	if apexBundle.overridableProperties.Logging_parent != "com.foo.bar" {
		t.Errorf("override_myapex should have logging parent (com.foo.bar), but was %q.", apexBundle.overridableProperties.Logging_parent)
	}

	optFlags := apexRule.Args["opt_flags"]
	ensureContains(t, optFlags, "--override_apk_package_name test.overridden.package")
	ensureContains(t, optFlags, "--pubkey testkey2.avbpubkey")

	signApkRule := module.Rule("signapk")
	ensureEquals(t, signApkRule.Args["certificates"], "testkey.x509.pem testkey.pk8")

	data := android.AndroidMkDataForTest(t, ctx, apexBundle)
	var builder strings.Builder
	data.Custom(&builder, name, "TARGET_", "", data)
	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_MODULE := override_app.override_myapex")
	ensureContains(t, androidMk, "LOCAL_MODULE := apex_manifest.pb.override_myapex")
	ensureContains(t, androidMk, "LOCAL_MODULE_STEM := override_myapex.apex")
	ensureContains(t, androidMk, "LOCAL_OVERRIDES_MODULES := unknownapex myapex")
	ensureNotContains(t, androidMk, "LOCAL_MODULE := app.myapex")
	ensureNotContains(t, androidMk, "LOCAL_MODULE := override_app.myapex")
	ensureNotContains(t, androidMk, "LOCAL_MODULE := apex_manifest.pb.myapex")
	ensureNotContains(t, androidMk, "LOCAL_MODULE_STEM := myapex.apex")
}

func TestLegacyAndroid10Support(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			min_sdk_version: "29",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			stl: "libc++",
			system_shared_libs: [],
			apex_available: [ "myapex" ],
			min_sdk_version: "29",
		}
	`, withUnbundledBuild)

	module := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	args := module.Rule("apexRule").Args
	ensureContains(t, args["opt_flags"], "--manifest_json "+module.Output("apex_manifest.json").Output.String())
	ensureNotContains(t, args["opt_flags"], "--no_hashtree")

	// The copies of the libraries in the apex should have one more dependency than
	// the ones outside the apex, namely the unwinder. Ideally we should check
	// the dependency names directly here but for some reason the names are blank in
	// this test.
	for _, lib := range []string{"libc++", "mylib"} {
		apexImplicits := ctx.ModuleForTests(lib, "android_arm64_armv8-a_shared_apex29").Rule("ld").Implicits
		nonApexImplicits := ctx.ModuleForTests(lib, "android_arm64_armv8-a_shared").Rule("ld").Implicits
		if len(apexImplicits) != len(nonApexImplicits)+1 {
			t.Errorf("%q missing unwinder dep", lib)
		}
	}
}

var filesForSdkLibrary = android.MockFS{
	"api/current.txt":        nil,
	"api/removed.txt":        nil,
	"api/system-current.txt": nil,
	"api/system-removed.txt": nil,
	"api/test-current.txt":   nil,
	"api/test-removed.txt":   nil,

	"100/public/api/foo.txt":         nil,
	"100/public/api/foo-removed.txt": nil,
	"100/system/api/foo.txt":         nil,
	"100/system/api/foo-removed.txt": nil,

	// For java_sdk_library_import
	"a.jar": nil,
}

func TestJavaSDKLibrary(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["foo"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_sdk_library {
			name: "foo",
			srcs: ["a.java"],
			api_packages: ["foo"],
			apex_available: [ "myapex" ],
		}

		prebuilt_apis {
			name: "sdk",
			api_dirs: ["100"],
		}
	`, withFiles(filesForSdkLibrary))

	// java_sdk_library installs both impl jar and permission XML
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"javalib/foo.jar",
		"etc/permissions/foo.xml",
	})
	// Permission XML should point to the activated path of impl jar of java_sdk_library
	sdkLibrary := ctx.ModuleForTests("foo.xml", "android_common_myapex").Rule("java_sdk_xml")
	ensureContains(t, sdkLibrary.RuleParams.Command, `<library name=\"foo\" file=\"/apex/myapex/javalib/foo.jar\"`)
}

func TestJavaSDKLibrary_WithinApex(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["foo", "bar"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_sdk_library {
			name: "foo",
			srcs: ["a.java"],
			api_packages: ["foo"],
			apex_available: ["myapex"],
			sdk_version: "none",
			system_modules: "none",
		}

		java_library {
			name: "bar",
			srcs: ["a.java"],
			libs: ["foo"],
			apex_available: ["myapex"],
			sdk_version: "none",
			system_modules: "none",
		}

		prebuilt_apis {
			name: "sdk",
			api_dirs: ["100"],
		}
	`, withFiles(filesForSdkLibrary))

	// java_sdk_library installs both impl jar and permission XML
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"javalib/bar.jar",
		"javalib/foo.jar",
		"etc/permissions/foo.xml",
	})

	// The bar library should depend on the implementation jar.
	barLibrary := ctx.ModuleForTests("bar", "android_common_myapex").Rule("javac")
	if expected, actual := `^-classpath [^:]*/turbine-combined/foo\.jar$`, barLibrary.Args["classpath"]; !regexp.MustCompile(expected).MatchString(actual) {
		t.Errorf("expected %q, found %#q", expected, actual)
	}
}

func TestJavaSDKLibrary_CrossBoundary(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["foo"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_sdk_library {
			name: "foo",
			srcs: ["a.java"],
			api_packages: ["foo"],
			apex_available: ["myapex"],
			sdk_version: "none",
			system_modules: "none",
		}

		java_library {
			name: "bar",
			srcs: ["a.java"],
			libs: ["foo"],
			sdk_version: "none",
			system_modules: "none",
		}

		prebuilt_apis {
			name: "sdk",
			api_dirs: ["100"],
		}
	`, withFiles(filesForSdkLibrary))

	// java_sdk_library installs both impl jar and permission XML
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"javalib/foo.jar",
		"etc/permissions/foo.xml",
	})

	// The bar library should depend on the stubs jar.
	barLibrary := ctx.ModuleForTests("bar", "android_common").Rule("javac")
	if expected, actual := `^-classpath [^:]*/turbine-combined/foo\.stubs\.jar$`, barLibrary.Args["classpath"]; !regexp.MustCompile(expected).MatchString(actual) {
		t.Errorf("expected %q, found %#q", expected, actual)
	}
}

func TestJavaSDKLibrary_ImportPreferred(t *testing.T) {
	ctx := testApex(t, `
		prebuilt_apis {
			name: "sdk",
			api_dirs: ["100"],
		}`,
		withFiles(map[string][]byte{
			"apex/a.java":             nil,
			"apex/apex_manifest.json": nil,
			"apex/Android.bp": []byte(`
		package {
			default_visibility: ["//visibility:private"],
		}

		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["foo", "bar"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_library {
			name: "bar",
			srcs: ["a.java"],
			libs: ["foo"],
			apex_available: ["myapex"],
			sdk_version: "none",
			system_modules: "none",
		}
`),
			"source/a.java":          nil,
			"source/api/current.txt": nil,
			"source/api/removed.txt": nil,
			"source/Android.bp": []byte(`
		package {
			default_visibility: ["//visibility:private"],
		}

		java_sdk_library {
			name: "foo",
			visibility: ["//apex"],
			srcs: ["a.java"],
			api_packages: ["foo"],
			apex_available: ["myapex"],
			sdk_version: "none",
			system_modules: "none",
			public: {
				enabled: true,
			},
		}
`),
			"prebuilt/a.jar": nil,
			"prebuilt/Android.bp": []byte(`
		package {
			default_visibility: ["//visibility:private"],
		}

		java_sdk_library_import {
			name: "foo",
			visibility: ["//apex", "//source"],
			apex_available: ["myapex"],
			prefer: true,
			public: {
				jars: ["a.jar"],
			},
		}
`),
		}), withFiles(filesForSdkLibrary),
	)

	// java_sdk_library installs both impl jar and permission XML
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"javalib/bar.jar",
		"javalib/foo.jar",
		"etc/permissions/foo.xml",
	})

	// The bar library should depend on the implementation jar.
	barLibrary := ctx.ModuleForTests("bar", "android_common_myapex").Rule("javac")
	if expected, actual := `^-classpath [^:]*/turbine-combined/foo\.impl\.jar$`, barLibrary.Args["classpath"]; !regexp.MustCompile(expected).MatchString(actual) {
		t.Errorf("expected %q, found %#q", expected, actual)
	}
}

func TestJavaSDKLibrary_ImportOnly(t *testing.T) {
	testApexError(t, `java_libs: "foo" is not configured to be compiled into dex`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["foo"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_sdk_library_import {
			name: "foo",
			apex_available: ["myapex"],
			prefer: true,
			public: {
				jars: ["a.jar"],
			},
		}

	`, withFiles(filesForSdkLibrary))
}

func TestCompatConfig(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForApexTest,
		java.PrepareForTestWithPlatformCompatConfig,
	).RunTestWithBp(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			compat_configs: ["myjar-platform-compat-config"],
			java_libs: ["myjar"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		platform_compat_config {
		    name: "myjar-platform-compat-config",
		    src: ":myjar",
		}

		java_library {
			name: "myjar",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			apex_available: [ "myapex" ],
		}

		// Make sure that a preferred prebuilt does not affect the apex contents.
		prebuilt_platform_compat_config {
			name: "myjar-platform-compat-config",
			metadata: "compat-config/metadata.xml",
			prefer: true,
		}
	`)
	ctx := result.TestContext
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"etc/compatconfig/myjar-platform-compat-config.xml",
		"javalib/myjar.jar",
	})
}

func TestRejectNonInstallableJavaLibrary(t *testing.T) {
	testApexError(t, `"myjar" is not configured to be compiled into dex`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["myjar"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_library {
			name: "myjar",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			compile_dex: false,
			apex_available: ["myapex"],
		}
	`)
}

func TestCarryRequiredModuleNames(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			required: ["a", "b"],
			host_required: ["c", "d"],
			target_required: ["e", "f"],
			apex_available: [ "myapex" ],
		}
	`)

	apexBundle := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, apexBundle)
	name := apexBundle.BaseModuleName()
	prefix := "TARGET_"
	var builder strings.Builder
	data.Custom(&builder, name, prefix, "", data)
	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_REQUIRED_MODULES += a b\n")
	ensureContains(t, androidMk, "LOCAL_HOST_REQUIRED_MODULES += c d\n")
	ensureContains(t, androidMk, "LOCAL_TARGET_REQUIRED_MODULES += e f\n")
}

func TestSymlinksFromApexToSystem(t *testing.T) {
	bp := `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			java_libs: ["myjar"],
			updatable: false,
		}

		apex {
			name: "myapex.updatable",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			java_libs: ["myjar"],
			updatable: true,
			min_sdk_version: "current",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["myotherlib"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
				"myapex.updatable",
				"//apex_available:platform",
			],
			min_sdk_version: "current",
		}

		cc_library {
			name: "myotherlib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
				"myapex.updatable",
				"//apex_available:platform",
			],
			min_sdk_version: "current",
		}

		java_library {
			name: "myjar",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			libs: ["myotherjar"],
			apex_available: [
				"myapex",
				"myapex.updatable",
				"//apex_available:platform",
			],
			min_sdk_version: "current",
		}

		java_library {
			name: "myotherjar",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			apex_available: [
				"myapex",
				"myapex.updatable",
				"//apex_available:platform",
			],
			min_sdk_version: "current",
		}
	`

	ensureRealfileExists := func(t *testing.T, files []fileInApex, file string) {
		for _, f := range files {
			if f.path == file {
				if f.isLink {
					t.Errorf("%q is not a real file", file)
				}
				return
			}
		}
		t.Errorf("%q is not found", file)
	}

	ensureSymlinkExists := func(t *testing.T, files []fileInApex, file string) {
		for _, f := range files {
			if f.path == file {
				if !f.isLink {
					t.Errorf("%q is not a symlink", file)
				}
				return
			}
		}
		t.Errorf("%q is not found", file)
	}

	// For unbundled build, symlink shouldn't exist regardless of whether an APEX
	// is updatable or not
	ctx := testApex(t, bp, withUnbundledBuild)
	files := getFiles(t, ctx, "myapex", "android_common_myapex_image")
	ensureRealfileExists(t, files, "javalib/myjar.jar")
	ensureRealfileExists(t, files, "lib64/mylib.so")
	ensureRealfileExists(t, files, "lib64/myotherlib.so")

	files = getFiles(t, ctx, "myapex.updatable", "android_common_myapex.updatable_image")
	ensureRealfileExists(t, files, "javalib/myjar.jar")
	ensureRealfileExists(t, files, "lib64/mylib.so")
	ensureRealfileExists(t, files, "lib64/myotherlib.so")

	// For bundled build, symlink to the system for the non-updatable APEXes only
	ctx = testApex(t, bp)
	files = getFiles(t, ctx, "myapex", "android_common_myapex_image")
	ensureRealfileExists(t, files, "javalib/myjar.jar")
	ensureRealfileExists(t, files, "lib64/mylib.so")
	ensureSymlinkExists(t, files, "lib64/myotherlib.so") // this is symlink

	files = getFiles(t, ctx, "myapex.updatable", "android_common_myapex.updatable_image")
	ensureRealfileExists(t, files, "javalib/myjar.jar")
	ensureRealfileExists(t, files, "lib64/mylib.so")
	ensureRealfileExists(t, files, "lib64/myotherlib.so") // this is a real file
}

func TestSymlinksFromApexToSystemRequiredModuleNames(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library_shared {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["myotherlib"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
				"//apex_available:platform",
			],
		}

		cc_prebuilt_library_shared {
			name: "myotherlib",
			srcs: ["prebuilt.so"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [
				"myapex",
				"//apex_available:platform",
			],
		}
	`)

	apexBundle := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, apexBundle)
	var builder strings.Builder
	data.Custom(&builder, apexBundle.BaseModuleName(), "TARGET_", "", data)
	androidMk := builder.String()
	// `myotherlib` is added to `myapex` as symlink
	ensureContains(t, androidMk, "LOCAL_MODULE := mylib.myapex\n")
	ensureNotContains(t, androidMk, "LOCAL_MODULE := prebuilt_myotherlib.myapex\n")
	ensureNotContains(t, androidMk, "LOCAL_MODULE := myotherlib.myapex\n")
	// `myapex` should have `myotherlib` in its required line, not `prebuilt_myotherlib`
	ensureContains(t, androidMk, "LOCAL_REQUIRED_MODULES += mylib.myapex:64 myotherlib:64 apex_manifest.pb.myapex apex_pubkey.myapex\n")
}

func TestApexWithJniLibs(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			jni_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			shared_libs: ["mylib2"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}
	`)

	rule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexManifestRule")
	// Notice mylib2.so (transitive dep) is not added as a jni_lib
	ensureEquals(t, rule.Args["opt"], "-a jniLibs mylib.so")
	ensureExactContents(t, ctx, "myapex", "android_common_myapex_image", []string{
		"lib64/mylib.so",
		"lib64/mylib2.so",
	})
}

func TestApexMutatorsDontRunIfDisabled(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`,
		android.FixtureModifyConfig(func(config android.Config) {
			delete(config.Targets, android.Android)
			config.AndroidCommonTarget = android.Target{}
		}),
	)

	if expected, got := []string{""}, ctx.ModuleVariantsForTests("myapex"); !reflect.DeepEqual(expected, got) {
		t.Errorf("Expected variants: %v, but got: %v", expected, got)
	}
}

func TestAppBundle(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: ["AppFoo"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_app {
			name: "AppFoo",
			srcs: ["foo/bar/MyClass.java"],
			sdk_version: "none",
			system_modules: "none",
			apex_available: [ "myapex" ],
		}
		`, withManifestPackageNameOverrides([]string{"AppFoo:com.android.foo"}))

	bundleConfigRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Output("bundle_config.json")
	content := bundleConfigRule.Args["content"]

	ensureContains(t, content, `"compression":{"uncompressed_glob":["apex_payload.img","apex_manifest.*"]}`)
	ensureContains(t, content, `"apex_config":{"apex_embedded_apk_config":[{"package_name":"com.android.foo","path":"app/AppFoo/AppFoo.apk"}]}`)
}

func TestAppSetBundle(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: ["AppSet"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_app_set {
			name: "AppSet",
			set: "AppSet.apks",
		}`)
	mod := ctx.ModuleForTests("myapex", "android_common_myapex_image")
	bundleConfigRule := mod.Output("bundle_config.json")
	content := bundleConfigRule.Args["content"]
	ensureContains(t, content, `"compression":{"uncompressed_glob":["apex_payload.img","apex_manifest.*"]}`)
	s := mod.Rule("apexRule").Args["copy_commands"]
	copyCmds := regexp.MustCompile(" *&& *").Split(s, -1)
	if len(copyCmds) != 3 {
		t.Fatalf("Expected 3 commands, got %d in:\n%s", len(copyCmds), s)
	}
	ensureMatches(t, copyCmds[0], "^rm -rf .*/app/AppSet$")
	ensureMatches(t, copyCmds[1], "^mkdir -p .*/app/AppSet$")
	ensureMatches(t, copyCmds[2], "^unzip .*-d .*/app/AppSet .*/AppSet.zip$")
}

func TestAppSetBundlePrebuilt(t *testing.T) {
	bp := `
		apex_set {
			name: "myapex",
			filename: "foo_v2.apex",
			sanitized: {
				none: { set: "myapex.apks", },
				hwaddress: { set: "myapex.hwasan.apks", },
			},
		}
	`
	ctx := testApex(t, bp, prepareForTestWithSantitizeHwaddress)

	// Check that the extractor produces the correct output file from the correct input file.
	extractorOutput := "out/soong/.intermediates/myapex.apex.extractor/android_common/extracted/myapex.hwasan.apks"

	m := ctx.ModuleForTests("myapex.apex.extractor", "android_common")
	extractedApex := m.Output(extractorOutput)

	android.AssertArrayString(t, "extractor input", []string{"myapex.hwasan.apks"}, extractedApex.Inputs.Strings())

	// Ditto for the apex.
	m = ctx.ModuleForTests("myapex", "android_common_myapex")
	copiedApex := m.Output("out/soong/.intermediates/myapex/android_common_myapex/foo_v2.apex")

	android.AssertStringEquals(t, "myapex input", extractorOutput, copiedApex.Input.String())
}

func testNoUpdatableJarsInBootImage(t *testing.T, errmsg string, preparer android.FixturePreparer, fragments ...java.ApexVariantReference) {
	t.Helper()

	bp := `
		java_library {
			name: "some-updatable-apex-lib",
			srcs: ["a.java"],
			sdk_version: "current",
			apex_available: [
				"some-updatable-apex",
			],
		}

		java_library {
			name: "some-non-updatable-apex-lib",
			srcs: ["a.java"],
			apex_available: [
				"some-non-updatable-apex",
			],
			compile_dex: true,
		}

		bootclasspath_fragment {
			name: "some-non-updatable-fragment",
			contents: ["some-non-updatable-apex-lib"],
			apex_available: [
				"some-non-updatable-apex",
			],
		}

		java_library {
			name: "some-platform-lib",
			srcs: ["a.java"],
			sdk_version: "current",
			installable: true,
		}

		java_library {
			name: "some-art-lib",
			srcs: ["a.java"],
			sdk_version: "current",
			apex_available: [
				"com.android.art.debug",
			],
			hostdex: true,
			compile_dex: true,
		}

		apex {
			name: "some-updatable-apex",
			key: "some-updatable-apex.key",
			java_libs: ["some-updatable-apex-lib"],
			updatable: true,
			min_sdk_version: "current",
		}

		apex {
			name: "some-non-updatable-apex",
			key: "some-non-updatable-apex.key",
			bootclasspath_fragments: ["some-non-updatable-fragment"],
			updatable: false,
		}

		apex_key {
			name: "some-updatable-apex.key",
		}

		apex_key {
			name: "some-non-updatable-apex.key",
		}

		apex {
			name: "com.android.art.debug",
			key: "com.android.art.debug.key",
			bootclasspath_fragments: ["art-bootclasspath-fragment"],
			updatable: true,
			min_sdk_version: "current",
		}

		bootclasspath_fragment {
			name: "art-bootclasspath-fragment",
			image_name: "art",
			contents: ["some-art-lib"],
			apex_available: [
				"com.android.art.debug",
			],
		}

		apex_key {
			name: "com.android.art.debug.key",
		}

		filegroup {
			name: "some-updatable-apex-file_contexts",
			srcs: [
				"system/sepolicy/apex/some-updatable-apex-file_contexts",
			],
		}

		filegroup {
			name: "some-non-updatable-apex-file_contexts",
			srcs: [
				"system/sepolicy/apex/some-non-updatable-apex-file_contexts",
			],
		}
	`

	testDexpreoptWithApexes(t, bp, errmsg, preparer, fragments...)
}

func testDexpreoptWithApexes(t *testing.T, bp, errmsg string, preparer android.FixturePreparer, fragments ...java.ApexVariantReference) *android.TestContext {
	t.Helper()

	fs := android.MockFS{
		"a.java":              nil,
		"a.jar":               nil,
		"apex_manifest.json":  nil,
		"AndroidManifest.xml": nil,
		"system/sepolicy/apex/myapex-file_contexts":                  nil,
		"system/sepolicy/apex/some-updatable-apex-file_contexts":     nil,
		"system/sepolicy/apex/some-non-updatable-apex-file_contexts": nil,
		"system/sepolicy/apex/com.android.art.debug-file_contexts":   nil,
		"framework/aidl/a.aidl":                                      nil,
	}

	errorHandler := android.FixtureExpectsNoErrors
	if errmsg != "" {
		errorHandler = android.FixtureExpectsAtLeastOneErrorMatchingPattern(errmsg)
	}

	result := android.GroupFixturePreparers(
		cc.PrepareForTestWithCcDefaultModules,
		java.PrepareForTestWithHiddenApiBuildComponents,
		java.PrepareForTestWithJavaDefaultModules,
		java.PrepareForTestWithJavaSdkLibraryFiles,
		PrepareForTestWithApexBuildComponents,
		preparer,
		fs.AddToFixture(),
		android.FixtureModifyMockFS(func(fs android.MockFS) {
			if _, ok := fs["frameworks/base/boot/Android.bp"]; !ok {
				insert := ""
				for _, fragment := range fragments {
					insert += fmt.Sprintf("{apex: %q, module: %q},\n", *fragment.Apex, *fragment.Module)
				}
				fs["frameworks/base/boot/Android.bp"] = []byte(fmt.Sprintf(`
					platform_bootclasspath {
						name: "platform-bootclasspath",
						fragments: [
  						%s
						],
					}
				`, insert))
			}
		}),
	).
		ExtendWithErrorHandler(errorHandler).
		RunTestWithBp(t, bp)

	return result.TestContext
}

func TestDuplicateDeapexeresFromPrebuiltApexes(t *testing.T) {
	preparers := android.GroupFixturePreparers(
		java.PrepareForTestWithJavaDefaultModules,
		PrepareForTestWithApexBuildComponents,
	).
		ExtendWithErrorHandler(android.FixtureExpectsAtLeastOneErrorMatchingPattern(
			`Ambiguous duplicate deapexer module dependencies "com.android.myapex.deapexer" and "com.mycompany.android.myapex.deapexer"`))

	bpBase := `
		apex_set {
			name: "com.android.myapex",
			exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
			set: "myapex.apks",
		}

		apex_set {
			name: "com.mycompany.android.myapex",
			apex_name: "com.android.myapex",
			exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
			set: "company-myapex.apks",
		}

		prebuilt_bootclasspath_fragment {
			name: "my-bootclasspath-fragment",
			apex_available: ["com.android.myapex"],
			%s
		}
	`

	t.Run("java_import", func(t *testing.T) {
		_ = preparers.RunTestWithBp(t, fmt.Sprintf(bpBase, `contents: ["libfoo"]`)+`
			java_import {
				name: "libfoo",
				jars: ["libfoo.jar"],
				apex_available: ["com.android.myapex"],
			}
		`)
	})

	t.Run("java_sdk_library_import", func(t *testing.T) {
		_ = preparers.RunTestWithBp(t, fmt.Sprintf(bpBase, `contents: ["libfoo"]`)+`
			java_sdk_library_import {
				name: "libfoo",
				public: {
					jars: ["libbar.jar"],
				},
				apex_available: ["com.android.myapex"],
			}
		`)
	})

	t.Run("prebuilt_bootclasspath_fragment", func(t *testing.T) {
		_ = preparers.RunTestWithBp(t, fmt.Sprintf(bpBase, `
			image_name: "art",
			contents: ["libfoo"],
		`)+`
			java_sdk_library_import {
				name: "libfoo",
				public: {
					jars: ["libbar.jar"],
				},
				apex_available: ["com.android.myapex"],
			}
		`)
	})
}

func TestUpdatable_should_set_min_sdk_version(t *testing.T) {
	testApexError(t, `"myapex" .*: updatable: updatable APEXes should set min_sdk_version`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: true,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`)
}

func TestUpdatableDefault_should_set_min_sdk_version(t *testing.T) {
	testApexError(t, `"myapex" .*: updatable: updatable APEXes should set min_sdk_version`, `
		apex {
			name: "myapex",
			key: "myapex.key",
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`)
}

func TestNoUpdatableJarsInBootImage(t *testing.T) {
	// Set the BootJars in dexpreopt.GlobalConfig and productVariables to the same value. This can
	// result in an invalid configuration as it does not set the ArtApexJars and allows art apex
	// modules to be included in the BootJars.
	prepareSetBootJars := func(bootJars ...string) android.FixturePreparer {
		return android.GroupFixturePreparers(
			dexpreopt.FixtureSetBootJars(bootJars...),
			android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
				variables.BootJars = android.CreateTestConfiguredJarList(bootJars)
			}),
		)
	}

	// Set the ArtApexJars and BootJars in dexpreopt.GlobalConfig and productVariables all to the
	// same value. This can result in an invalid configuration as it allows non art apex jars to be
	// specified in the ArtApexJars configuration.
	prepareSetArtJars := func(bootJars ...string) android.FixturePreparer {
		return android.GroupFixturePreparers(
			dexpreopt.FixtureSetArtBootJars(bootJars...),
			dexpreopt.FixtureSetBootJars(bootJars...),
			android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
				variables.BootJars = android.CreateTestConfiguredJarList(bootJars)
			}),
		)
	}

	t.Run("updatable jar from ART apex in the ART boot image => ok", func(t *testing.T) {
		preparer := java.FixtureConfigureBootJars("com.android.art.debug:some-art-lib")
		fragment := java.ApexVariantReference{
			Apex:   proptools.StringPtr("com.android.art.debug"),
			Module: proptools.StringPtr("art-bootclasspath-fragment"),
		}
		testNoUpdatableJarsInBootImage(t, "", preparer, fragment)
	})

	t.Run("updatable jar from ART apex in the framework boot image => error", func(t *testing.T) {
		err := `module "some-art-lib" from updatable apexes \["com.android.art.debug"\] is not allowed in the framework boot image`
		// Update the dexpreopt BootJars directly.
		preparer := prepareSetBootJars("com.android.art.debug:some-art-lib")
		testNoUpdatableJarsInBootImage(t, err, preparer)
	})

	t.Run("updatable jar from some other apex in the ART boot image => error", func(t *testing.T) {
		err := `ArtApexJars expects this to be in apex "some-updatable-apex" but this is only in apexes.*"com.android.art.debug"`
		// Update the dexpreopt ArtApexJars directly.
		preparer := prepareSetArtJars("some-updatable-apex:some-updatable-apex-lib")
		testNoUpdatableJarsInBootImage(t, err, preparer)
	})

	t.Run("non-updatable jar from some other apex in the ART boot image => error", func(t *testing.T) {
		err := `ArtApexJars expects this to be in apex "some-non-updatable-apex" but this is only in apexes.*"com.android.art.debug"`
		// Update the dexpreopt ArtApexJars directly.
		preparer := prepareSetArtJars("some-non-updatable-apex:some-non-updatable-apex-lib")
		testNoUpdatableJarsInBootImage(t, err, preparer)
	})

	t.Run("updatable jar from some other apex in the framework boot image => error", func(t *testing.T) {
		err := `module "some-updatable-apex-lib" from updatable apexes \["some-updatable-apex"\] is not allowed in the framework boot image`
		preparer := java.FixtureConfigureBootJars("some-updatable-apex:some-updatable-apex-lib")
		testNoUpdatableJarsInBootImage(t, err, preparer)
	})

	t.Run("non-updatable jar from some other apex in the framework boot image => ok", func(t *testing.T) {
		preparer := java.FixtureConfigureBootJars("some-non-updatable-apex:some-non-updatable-apex-lib")
		fragment := java.ApexVariantReference{
			Apex:   proptools.StringPtr("some-non-updatable-apex"),
			Module: proptools.StringPtr("some-non-updatable-fragment"),
		}
		testNoUpdatableJarsInBootImage(t, "", preparer, fragment)
	})

	t.Run("nonexistent jar in the ART boot image => error", func(t *testing.T) {
		err := `"platform-bootclasspath" depends on undefined module "nonexistent"`
		preparer := java.FixtureConfigureBootJars("platform:nonexistent")
		testNoUpdatableJarsInBootImage(t, err, preparer)
	})

	t.Run("nonexistent jar in the framework boot image => error", func(t *testing.T) {
		err := `"platform-bootclasspath" depends on undefined module "nonexistent"`
		preparer := java.FixtureConfigureBootJars("platform:nonexistent")
		testNoUpdatableJarsInBootImage(t, err, preparer)
	})

	t.Run("platform jar in the ART boot image => error", func(t *testing.T) {
		err := `ArtApexJars is invalid as it requests a platform variant of "some-platform-lib"`
		// Update the dexpreopt ArtApexJars directly.
		preparer := prepareSetArtJars("platform:some-platform-lib")
		testNoUpdatableJarsInBootImage(t, err, preparer)
	})

	t.Run("platform jar in the framework boot image => ok", func(t *testing.T) {
		preparer := java.FixtureConfigureBootJars("platform:some-platform-lib")
		testNoUpdatableJarsInBootImage(t, "", preparer)
	})
}

func TestDexpreoptAccessDexFilesFromPrebuiltApex(t *testing.T) {
	preparer := java.FixtureConfigureBootJars("myapex:libfoo")
	t.Run("prebuilt no source", func(t *testing.T) {
		fragment := java.ApexVariantReference{
			Apex:   proptools.StringPtr("myapex"),
			Module: proptools.StringPtr("my-bootclasspath-fragment"),
		}

		testDexpreoptWithApexes(t, `
			prebuilt_apex {
				name: "myapex" ,
				arch: {
					arm64: {
						src: "myapex-arm64.apex",
					},
					arm: {
						src: "myapex-arm.apex",
					},
				},
				exported_bootclasspath_fragments: ["my-bootclasspath-fragment"],
			}

			prebuilt_bootclasspath_fragment {
				name: "my-bootclasspath-fragment",
				contents: ["libfoo"],
				apex_available: ["myapex"],
			}

			java_import {
				name: "libfoo",
				jars: ["libfoo.jar"],
				apex_available: ["myapex"],
			}
		`, "", preparer, fragment)
	})
}

func testApexPermittedPackagesRules(t *testing.T, errmsg, bp string, apexBootJars []string, rules []android.Rule) {
	t.Helper()
	bp += `
	apex_key {
		name: "myapex.key",
		public_key: "testkey.avbpubkey",
		private_key: "testkey.pem",
	}`
	fs := android.MockFS{
		"lib1/src/A.java": nil,
		"lib2/src/B.java": nil,
		"system/sepolicy/apex/myapex-file_contexts": nil,
	}

	errorHandler := android.FixtureExpectsNoErrors
	if errmsg != "" {
		errorHandler = android.FixtureExpectsAtLeastOneErrorMatchingPattern(errmsg)
	}

	android.GroupFixturePreparers(
		android.PrepareForTestWithAndroidBuildComponents,
		java.PrepareForTestWithJavaBuildComponents,
		PrepareForTestWithApexBuildComponents,
		android.PrepareForTestWithNeverallowRules(rules),
		android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
			updatableBootJars := make([]string, 0, len(apexBootJars))
			for _, apexBootJar := range apexBootJars {
				updatableBootJars = append(updatableBootJars, "myapex:"+apexBootJar)
			}
			variables.UpdatableBootJars = android.CreateTestConfiguredJarList(updatableBootJars)
		}),
		fs.AddToFixture(),
	).
		ExtendWithErrorHandler(errorHandler).
		RunTestWithBp(t, bp)
}

func TestApexPermittedPackagesRules(t *testing.T) {
	testcases := []struct {
		name            string
		expectedError   string
		bp              string
		bootJars        []string
		modulesPackages map[string][]string
	}{

		{
			name:          "Non-Bootclasspath apex jar not satisfying allowed module packages.",
			expectedError: "",
			bp: `
				java_library {
					name: "bcp_lib1",
					srcs: ["lib1/src/*.java"],
					permitted_packages: ["foo.bar"],
					apex_available: ["myapex"],
					sdk_version: "none",
					system_modules: "none",
				}
				java_library {
					name: "nonbcp_lib2",
					srcs: ["lib2/src/*.java"],
					apex_available: ["myapex"],
					permitted_packages: ["a.b"],
					sdk_version: "none",
					system_modules: "none",
				}
				apex {
					name: "myapex",
					key: "myapex.key",
					java_libs: ["bcp_lib1", "nonbcp_lib2"],
					updatable: false,
				}`,
			bootJars: []string{"bcp_lib1"},
			modulesPackages: map[string][]string{
				"myapex": []string{
					"foo.bar",
				},
			},
		},
		{
			name:          "Bootclasspath apex jar not satisfying allowed module packages.",
			expectedError: `module "bcp_lib2" .* which is restricted because jars that are part of the myapex module may only allow these packages: foo.bar. Please jarjar or move code around.`,
			bp: `
				java_library {
					name: "bcp_lib1",
					srcs: ["lib1/src/*.java"],
					apex_available: ["myapex"],
					permitted_packages: ["foo.bar"],
					sdk_version: "none",
					system_modules: "none",
				}
				java_library {
					name: "bcp_lib2",
					srcs: ["lib2/src/*.java"],
					apex_available: ["myapex"],
					permitted_packages: ["foo.bar", "bar.baz"],
					sdk_version: "none",
					system_modules: "none",
				}
				apex {
					name: "myapex",
					key: "myapex.key",
					java_libs: ["bcp_lib1", "bcp_lib2"],
					updatable: false,
				}
			`,
			bootJars: []string{"bcp_lib1", "bcp_lib2"},
			modulesPackages: map[string][]string{
				"myapex": []string{
					"foo.bar",
				},
			},
		},
	}
	for _, tc := range testcases {
		t.Run(tc.name, func(t *testing.T) {
			rules := createApexPermittedPackagesRules(tc.modulesPackages)
			testApexPermittedPackagesRules(t, tc.expectedError, tc.bp, tc.bootJars, rules)
		})
	}
}

func TestTestFor(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib", "myprivlib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["1"],
			},
			apex_available: ["myapex"],
		}

		cc_library {
			name: "myprivlib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: ["myapex"],
		}


		cc_test {
			name: "mytest",
			gtest: false,
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			shared_libs: ["mylib", "myprivlib", "mytestlib"],
			test_for: ["myapex"]
		}

		cc_library {
			name: "mytestlib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			shared_libs: ["mylib", "myprivlib"],
			stl: "none",
			test_for: ["myapex"],
		}

		cc_benchmark {
			name: "mybench",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			shared_libs: ["mylib", "myprivlib"],
			stl: "none",
			test_for: ["myapex"],
		}
	`)

	ensureLinkedLibIs := func(mod, variant, linkedLib, expectedVariant string) {
		ldFlags := strings.Split(ctx.ModuleForTests(mod, variant).Rule("ld").Args["libFlags"], " ")
		mylibLdFlags := android.FilterListPred(ldFlags, func(s string) bool { return strings.HasPrefix(s, linkedLib) })
		android.AssertArrayString(t, "unexpected "+linkedLib+" link library for "+mod, []string{linkedLib + expectedVariant}, mylibLdFlags)
	}

	// These modules are tests for the apex, therefore are linked to the
	// actual implementation of mylib instead of its stub.
	ensureLinkedLibIs("mytest", "android_arm64_armv8-a", "out/soong/.intermediates/mylib/", "android_arm64_armv8-a_shared/mylib.so")
	ensureLinkedLibIs("mytestlib", "android_arm64_armv8-a_shared", "out/soong/.intermediates/mylib/", "android_arm64_armv8-a_shared/mylib.so")
	ensureLinkedLibIs("mybench", "android_arm64_armv8-a", "out/soong/.intermediates/mylib/", "android_arm64_armv8-a_shared/mylib.so")
}

func TestIndirectTestFor(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib", "myprivlib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["1"],
			},
			apex_available: ["myapex"],
		}

		cc_library {
			name: "myprivlib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			shared_libs: ["mylib"],
			apex_available: ["myapex"],
		}

		cc_library {
			name: "mytestlib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			shared_libs: ["myprivlib"],
			stl: "none",
			test_for: ["myapex"],
		}
	`)

	ensureLinkedLibIs := func(mod, variant, linkedLib, expectedVariant string) {
		ldFlags := strings.Split(ctx.ModuleForTests(mod, variant).Rule("ld").Args["libFlags"], " ")
		mylibLdFlags := android.FilterListPred(ldFlags, func(s string) bool { return strings.HasPrefix(s, linkedLib) })
		android.AssertArrayString(t, "unexpected "+linkedLib+" link library for "+mod, []string{linkedLib + expectedVariant}, mylibLdFlags)
	}

	// The platform variant of mytestlib links to the platform variant of the
	// internal myprivlib.
	ensureLinkedLibIs("mytestlib", "android_arm64_armv8-a_shared", "out/soong/.intermediates/myprivlib/", "android_arm64_armv8-a_shared/myprivlib.so")

	// The platform variant of myprivlib links to the platform variant of mylib
	// and bypasses its stubs.
	ensureLinkedLibIs("myprivlib", "android_arm64_armv8-a_shared", "out/soong/.intermediates/mylib/", "android_arm64_armv8-a_shared/mylib.so")
}

func TestTestForForLibInOtherApex(t *testing.T) {
	// This case is only allowed for known overlapping APEXes, i.e. the ART APEXes.
	_ = testApex(t, `
		apex {
			name: "com.android.art",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex {
			name: "com.android.art.debug",
			key: "myapex.key",
			native_shared_libs: ["mylib", "mytestlib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["1"],
			},
			apex_available: ["com.android.art", "com.android.art.debug"],
		}

		cc_library {
			name: "mytestlib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			shared_libs: ["mylib"],
			stl: "none",
			apex_available: ["com.android.art.debug"],
			test_for: ["com.android.art"],
		}
	`,
		android.MockFS{
			"system/sepolicy/apex/com.android.art-file_contexts":       nil,
			"system/sepolicy/apex/com.android.art.debug-file_contexts": nil,
		}.AddToFixture())
}

// TODO(jungjw): Move this to proptools
func intPtr(i int) *int {
	return &i
}

func TestApexSet(t *testing.T) {
	ctx := testApex(t, `
		apex_set {
			name: "myapex",
			set: "myapex.apks",
			filename: "foo_v2.apex",
			overrides: ["foo"],
		}
	`,
		android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
			variables.Platform_sdk_version = intPtr(30)
		}),
		android.FixtureModifyConfig(func(config android.Config) {
			config.Targets[android.Android] = []android.Target{
				{Os: android.Android, Arch: android.Arch{ArchType: android.Arm, ArchVariant: "armv7-a-neon", Abi: []string{"armeabi-v7a"}}},
				{Os: android.Android, Arch: android.Arch{ArchType: android.Arm64, ArchVariant: "armv8-a", Abi: []string{"arm64-v8a"}}},
			}
		}),
	)

	m := ctx.ModuleForTests("myapex.apex.extractor", "android_common")

	// Check extract_apks tool parameters.
	extractedApex := m.Output("extracted/myapex.apks")
	actual := extractedApex.Args["abis"]
	expected := "ARMEABI_V7A,ARM64_V8A"
	if actual != expected {
		t.Errorf("Unexpected abis parameter - expected %q vs actual %q", expected, actual)
	}
	actual = extractedApex.Args["sdk-version"]
	expected = "30"
	if actual != expected {
		t.Errorf("Unexpected abis parameter - expected %q vs actual %q", expected, actual)
	}

	m = ctx.ModuleForTests("myapex", "android_common_myapex")
	a := m.Module().(*ApexSet)
	expectedOverrides := []string{"foo"}
	actualOverrides := android.AndroidMkEntriesForTest(t, ctx, a)[0].EntryMap["LOCAL_OVERRIDES_MODULES"]
	if !reflect.DeepEqual(actualOverrides, expectedOverrides) {
		t.Errorf("Incorrect LOCAL_OVERRIDES_MODULES - expected %q vs actual %q", expectedOverrides, actualOverrides)
	}
}

func TestNoStaticLinkingToStubsLib(t *testing.T) {
	testApexError(t, `.*required by "mylib" is a native library providing stub.*`, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			static_libs: ["otherlib"],
			system_shared_libs: [],
			stl: "none",
			apex_available: [ "myapex" ],
		}

		cc_library {
			name: "otherlib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["1", "2", "3"],
			},
			apex_available: [ "myapex" ],
		}
	`)
}

func TestApexKeysTxt(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		prebuilt_apex {
			name: "myapex",
			prefer: true,
			arch: {
				arm64: {
					src: "myapex-arm64.apex",
				},
				arm: {
					src: "myapex-arm.apex",
				},
			},
		}

		apex_set {
			name: "myapex_set",
			set: "myapex.apks",
			filename: "myapex_set.apex",
			overrides: ["myapex"],
		}
	`)

	apexKeysText := ctx.SingletonForTests("apex_keys_text")
	content := apexKeysText.MaybeDescription("apexkeys.txt").BuildParams.Args["content"]
	ensureContains(t, content, `name="myapex_set.apex" public_key="PRESIGNED" private_key="PRESIGNED" container_certificate="PRESIGNED" container_private_key="PRESIGNED" partition="system"`)
	ensureContains(t, content, `name="myapex.apex" public_key="PRESIGNED" private_key="PRESIGNED" container_certificate="PRESIGNED" container_private_key="PRESIGNED" partition="system"`)
}

func TestAllowedFiles(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			apps: ["app"],
			allowed_files: "allowed.txt",
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		android_app {
			name: "app",
			srcs: ["foo/bar/MyClass.java"],
			package_name: "foo",
			sdk_version: "none",
			system_modules: "none",
			apex_available: [ "myapex" ],
		}
	`, withFiles(map[string][]byte{
		"sub/Android.bp": []byte(`
			override_apex {
				name: "override_myapex",
				base: "myapex",
				apps: ["override_app"],
				allowed_files: ":allowed",
			}
			// Overridable "path" property should be referenced indirectly
			filegroup {
				name: "allowed",
				srcs: ["allowed.txt"],
			}
			override_android_app {
				name: "override_app",
				base: "app",
				package_name: "bar",
			}
			`),
	}))

	rule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("diffApexContentRule")
	if expected, actual := "allowed.txt", rule.Args["allowed_files_file"]; expected != actual {
		t.Errorf("allowed_files_file: expected %q but got %q", expected, actual)
	}

	rule2 := ctx.ModuleForTests("myapex", "android_common_override_myapex_myapex_image").Rule("diffApexContentRule")
	if expected, actual := "sub/allowed.txt", rule2.Args["allowed_files_file"]; expected != actual {
		t.Errorf("allowed_files_file: expected %q but got %q", expected, actual)
	}
}

func TestNonPreferredPrebuiltDependency(t *testing.T) {
	testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			stubs: {
				versions: ["current"],
			},
			apex_available: ["myapex"],
		}

		cc_prebuilt_library_shared {
			name: "mylib",
			prefer: false,
			srcs: ["prebuilt.so"],
			stubs: {
				versions: ["current"],
			},
			apex_available: ["myapex"],
		}
	`)
}

func TestCompressedApex(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			compressible: true,
			updatable: false,
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
	`,
		android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
			variables.CompressedApex = proptools.BoolPtr(true)
		}),
	)

	compressRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("compressRule")
	ensureContains(t, compressRule.Output.String(), "myapex.capex.unsigned")

	signApkRule := ctx.ModuleForTests("myapex", "android_common_myapex_image").Description("sign compressedApex")
	ensureEquals(t, signApkRule.Input.String(), compressRule.Output.String())

	// Make sure output of bundle is .capex
	ab := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	ensureContains(t, ab.outputFile.String(), "myapex.capex")

	// Verify android.mk rules
	data := android.AndroidMkDataForTest(t, ctx, ab)
	var builder strings.Builder
	data.Custom(&builder, ab.BaseModuleName(), "TARGET_", "", data)
	androidMk := builder.String()
	ensureContains(t, androidMk, "LOCAL_MODULE_STEM := myapex.capex\n")
}

func TestPreferredPrebuiltSharedLibDep(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			apex_available: ["myapex"],
			shared_libs: ["otherlib"],
			system_shared_libs: [],
		}

		cc_library {
			name: "otherlib",
			srcs: ["mylib.cpp"],
			stubs: {
				versions: ["current"],
			},
		}

		cc_prebuilt_library_shared {
			name: "otherlib",
			prefer: true,
			srcs: ["prebuilt.so"],
			stubs: {
				versions: ["current"],
			},
		}
	`)

	ab := ctx.ModuleForTests("myapex", "android_common_myapex_image").Module().(*apexBundle)
	data := android.AndroidMkDataForTest(t, ctx, ab)
	var builder strings.Builder
	data.Custom(&builder, ab.BaseModuleName(), "TARGET_", "", data)
	androidMk := builder.String()

	// The make level dependency needs to be on otherlib - prebuilt_otherlib isn't
	// a thing there.
	ensureContains(t, androidMk, "LOCAL_REQUIRED_MODULES += otherlib\n")
}

func TestExcludeDependency(t *testing.T) {
	ctx := testApex(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
			apex_available: ["myapex"],
			shared_libs: ["mylib2"],
			target: {
				apex: {
					exclude_shared_libs: ["mylib2"],
				},
			},
		}

		cc_library {
			name: "mylib2",
			srcs: ["mylib.cpp"],
			system_shared_libs: [],
			stl: "none",
		}
	`)

	// Check if mylib is linked to mylib2 for the non-apex target
	ldFlags := ctx.ModuleForTests("mylib", "android_arm64_armv8-a_shared").Rule("ld").Args["libFlags"]
	ensureContains(t, ldFlags, "mylib2/android_arm64_armv8-a_shared/mylib2.so")

	// Make sure that the link doesn't occur for the apex target
	ldFlags = ctx.ModuleForTests("mylib", "android_arm64_armv8-a_shared_apex10000").Rule("ld").Args["libFlags"]
	ensureNotContains(t, ldFlags, "mylib2/android_arm64_armv8-a_shared_apex10000/mylib2.so")

	// It shouldn't appear in the copy cmd as well.
	copyCmds := ctx.ModuleForTests("myapex", "android_common_myapex_image").Rule("apexRule").Args["copy_commands"]
	ensureNotContains(t, copyCmds, "image.apex/lib64/mylib2.so")
}

func TestPrebuiltStubLibDep(t *testing.T) {
	bpBase := `
		apex {
			name: "myapex",
			key: "myapex.key",
			native_shared_libs: ["mylib"],
			updatable: false,
		}
		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}
		cc_library {
			name: "mylib",
			srcs: ["mylib.cpp"],
			apex_available: ["myapex"],
			shared_libs: ["stublib"],
			system_shared_libs: [],
		}
		apex {
			name: "otherapex",
			enabled: %s,
			key: "myapex.key",
			native_shared_libs: ["stublib"],
			updatable: false,
		}
	`

	stublibSourceBp := `
		cc_library {
			name: "stublib",
			srcs: ["mylib.cpp"],
			apex_available: ["otherapex"],
			system_shared_libs: [],
			stl: "none",
			stubs: {
				versions: ["1"],
			},
		}
	`

	stublibPrebuiltBp := `
		cc_prebuilt_library_shared {
			name: "stublib",
			srcs: ["prebuilt.so"],
			apex_available: ["otherapex"],
			stubs: {
				versions: ["1"],
			},
			%s
		}
	`

	tests := []struct {
		name             string
		stublibBp        string
		usePrebuilt      bool
		modNames         []string // Modules to collect AndroidMkEntries for
		otherApexEnabled []string
	}{
		{
			name:             "only_source",
			stublibBp:        stublibSourceBp,
			usePrebuilt:      false,
			modNames:         []string{"stublib"},
			otherApexEnabled: []string{"true", "false"},
		},
		{
			name:             "source_preferred",
			stublibBp:        stublibSourceBp + fmt.Sprintf(stublibPrebuiltBp, ""),
			usePrebuilt:      false,
			modNames:         []string{"stublib", "prebuilt_stublib"},
			otherApexEnabled: []string{"true", "false"},
		},
		{
			name:             "prebuilt_preferred",
			stublibBp:        stublibSourceBp + fmt.Sprintf(stublibPrebuiltBp, "prefer: true,"),
			usePrebuilt:      true,
			modNames:         []string{"stublib", "prebuilt_stublib"},
			otherApexEnabled: []string{"false"}, // No "true" since APEX cannot depend on prebuilt.
		},
		{
			name:             "only_prebuilt",
			stublibBp:        fmt.Sprintf(stublibPrebuiltBp, ""),
			usePrebuilt:      true,
			modNames:         []string{"stublib"},
			otherApexEnabled: []string{"false"}, // No "true" since APEX cannot depend on prebuilt.
		},
	}

	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			for _, otherApexEnabled := range test.otherApexEnabled {
				t.Run("otherapex_enabled_"+otherApexEnabled, func(t *testing.T) {
					ctx := testApex(t, fmt.Sprintf(bpBase, otherApexEnabled)+test.stublibBp)

					type modAndMkEntries struct {
						mod       *cc.Module
						mkEntries android.AndroidMkEntries
					}
					entries := []*modAndMkEntries{}

					// Gather shared lib modules that are installable
					for _, modName := range test.modNames {
						for _, variant := range ctx.ModuleVariantsForTests(modName) {
							if !strings.HasPrefix(variant, "android_arm64_armv8-a_shared") {
								continue
							}
							mod := ctx.ModuleForTests(modName, variant).Module().(*cc.Module)
							if !mod.Enabled() || mod.IsHideFromMake() {
								continue
							}
							for _, ent := range android.AndroidMkEntriesForTest(t, ctx, mod) {
								if ent.Disabled {
									continue
								}
								entries = append(entries, &modAndMkEntries{
									mod:       mod,
									mkEntries: ent,
								})
							}
						}
					}

					var entry *modAndMkEntries = nil
					for _, ent := range entries {
						if strings.Join(ent.mkEntries.EntryMap["LOCAL_MODULE"], ",") == "stublib" {
							if entry != nil {
								t.Errorf("More than one AndroidMk entry for \"stublib\": %s and %s", entry.mod, ent.mod)
							} else {
								entry = ent
							}
						}
					}

					if entry == nil {
						t.Errorf("AndroidMk entry for \"stublib\" missing")
					} else {
						isPrebuilt := entry.mod.Prebuilt() != nil
						if isPrebuilt != test.usePrebuilt {
							t.Errorf("Wrong module for \"stublib\" AndroidMk entry: got prebuilt %t, want prebuilt %t", isPrebuilt, test.usePrebuilt)
						}
						if !entry.mod.IsStubs() {
							t.Errorf("Module for \"stublib\" AndroidMk entry isn't a stub: %s", entry.mod)
						}
						if entry.mkEntries.EntryMap["LOCAL_NOT_AVAILABLE_FOR_PLATFORM"] != nil {
							t.Errorf("AndroidMk entry for \"stublib\" has LOCAL_NOT_AVAILABLE_FOR_PLATFORM set: %+v", entry.mkEntries)
						}
						cflags := entry.mkEntries.EntryMap["LOCAL_EXPORT_CFLAGS"]
						expected := "-D__STUBLIB_API__=10000"
						if !android.InList(expected, cflags) {
							t.Errorf("LOCAL_EXPORT_CFLAGS expected to have %q, but got %q", expected, cflags)
						}
					}
				})
			}
		})
	}
}

func TestApexJavaCoverage(t *testing.T) {
	bp := `
		apex {
			name: "myapex",
			key: "myapex.key",
			java_libs: ["mylib"],
			bootclasspath_fragments: ["mybootclasspathfragment"],
			systemserverclasspath_fragments: ["mysystemserverclasspathfragment"],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_library {
			name: "mylib",
			srcs: ["mylib.java"],
			apex_available: ["myapex"],
			compile_dex: true,
		}

		bootclasspath_fragment {
			name: "mybootclasspathfragment",
			contents: ["mybootclasspathlib"],
			apex_available: ["myapex"],
		}

		java_library {
			name: "mybootclasspathlib",
			srcs: ["mybootclasspathlib.java"],
			apex_available: ["myapex"],
			compile_dex: true,
		}

		systemserverclasspath_fragment {
			name: "mysystemserverclasspathfragment",
			contents: ["mysystemserverclasspathlib"],
			apex_available: ["myapex"],
		}

		java_library {
			name: "mysystemserverclasspathlib",
			srcs: ["mysystemserverclasspathlib.java"],
			apex_available: ["myapex"],
			compile_dex: true,
		}
	`

	result := android.GroupFixturePreparers(
		PrepareForTestWithApexBuildComponents,
		prepareForTestWithMyapex,
		java.PrepareForTestWithJavaDefaultModules,
		android.PrepareForTestWithAndroidBuildComponents,
		android.FixtureWithRootAndroidBp(bp),
		android.FixtureMergeEnv(map[string]string{
			"EMMA_INSTRUMENT": "true",
		}),
	).RunTest(t)

	// Make sure jacoco ran on both mylib and mybootclasspathlib
	if result.ModuleForTests("mylib", "android_common_apex10000").MaybeRule("jacoco").Rule == nil {
		t.Errorf("Failed to find jacoco rule for mylib")
	}
	if result.ModuleForTests("mybootclasspathlib", "android_common_apex10000").MaybeRule("jacoco").Rule == nil {
		t.Errorf("Failed to find jacoco rule for mybootclasspathlib")
	}
	if result.ModuleForTests("mysystemserverclasspathlib", "android_common_apex10000").MaybeRule("jacoco").Rule == nil {
		t.Errorf("Failed to find jacoco rule for mysystemserverclasspathlib")
	}
}

func TestMain(m *testing.M) {
	os.Exit(m.Run())
}
