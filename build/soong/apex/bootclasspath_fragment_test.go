// Copyright (C) 2021 The Android Open Source Project
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
	"sort"
	"strings"
	"testing"

	"android/soong/android"
	"android/soong/java"
	"github.com/google/blueprint/proptools"
)

// Contains tests for bootclasspath_fragment logic from java/bootclasspath_fragment.go as the ART
// bootclasspath_fragment requires modules from the ART apex.

var prepareForTestWithBootclasspathFragment = android.GroupFixturePreparers(
	java.PrepareForTestWithDexpreopt,
	PrepareForTestWithApexBuildComponents,
)

// Some additional files needed for the art apex.
var prepareForTestWithArtApex = android.FixtureMergeMockFs(android.MockFS{
	"com.android.art.avbpubkey":                          nil,
	"com.android.art.pem":                                nil,
	"system/sepolicy/apex/com.android.art-file_contexts": nil,
})

func TestBootclasspathFragments(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForTestWithBootclasspathFragment,
		// Configure some libraries in the art bootclasspath_fragment and platform_bootclasspath.
		java.FixtureConfigureBootJars("com.android.art:baz", "com.android.art:quuz", "platform:foo", "platform:bar"),
		prepareForTestWithArtApex,

		java.PrepareForTestWithJavaSdkLibraryFiles,
		java.FixtureWithLastReleaseApis("foo"),
	).RunTestWithBp(t, `
		java_sdk_library {
			name: "foo",
			srcs: ["b.java"],
		}

		java_library {
			name: "bar",
			srcs: ["b.java"],
			installable: true,
		}

		apex {
			name: "com.android.art",
			key: "com.android.art.key",
			bootclasspath_fragments: ["art-bootclasspath-fragment"],
 			java_libs: [
				"baz",
				"quuz",
			],
			updatable: false,
		}

		apex_key {
			name: "com.android.art.key",
			public_key: "com.android.art.avbpubkey",
			private_key: "com.android.art.pem",
		}

		java_library {
			name: "baz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
		}

		java_library {
			name: "quuz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
		}

		bootclasspath_fragment {
			name: "art-bootclasspath-fragment",
			image_name: "art",
			// Must match the "com.android.art:" entries passed to FixtureConfigureBootJars above.
			contents: ["baz", "quuz"],
			apex_available: [
				"com.android.art",
			],
		}
`,
	)

	// Make sure that the art-bootclasspath-fragment is using the correct configuration.
	checkBootclasspathFragment(t, result, "art-bootclasspath-fragment", "android_common_apex10000",
		"com.android.art:baz,com.android.art:quuz", `
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm/boot.art
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm/boot.oat
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm/boot.vdex
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm/boot-quuz.art
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm/boot-quuz.oat
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm/boot-quuz.vdex
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm64/boot.art
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm64/boot.oat
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm64/boot.vdex
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm64/boot-quuz.art
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm64/boot-quuz.oat
test_device/dex_artjars/android/apex/art_boot_images/javalib/arm64/boot-quuz.vdex
`)
}

func TestBootclasspathFragments_FragmentDependency(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForTestWithBootclasspathFragment,
		// Configure some libraries in the art bootclasspath_fragment and platform_bootclasspath.
		java.FixtureConfigureBootJars("com.android.art:baz", "com.android.art:quuz", "platform:foo", "platform:bar"),
		prepareForTestWithArtApex,

		java.PrepareForTestWithJavaSdkLibraryFiles,
		java.FixtureWithLastReleaseApis("foo", "baz"),
	).RunTestWithBp(t, `
		java_sdk_library {
			name: "foo",
			srcs: ["b.java"],
			shared_library: false,
			public: {
				enabled: true,
			},
			system: {
				enabled: true,
			},
		}

		java_library {
			name: "bar",
			srcs: ["b.java"],
			installable: true,
		}

		apex {
			name: "com.android.art",
			key: "com.android.art.key",
			bootclasspath_fragments: ["art-bootclasspath-fragment"],
			updatable: false,
		}

		apex_key {
			name: "com.android.art.key",
			public_key: "com.android.art.avbpubkey",
			private_key: "com.android.art.pem",
		}

		java_sdk_library {
			name: "baz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			shared_library: false,
			public: {
				enabled: true,
			},
			system: {
				enabled: true,
			},
			test: {
				enabled: true,
			},
		}

		java_library {
			name: "quuz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
		}

		bootclasspath_fragment {
			name: "art-bootclasspath-fragment",
			image_name: "art",
			// Must match the "com.android.art:" entries passed to FixtureConfigureBootJars above.
			contents: ["baz", "quuz"],
			apex_available: [
				"com.android.art",
			],
		}

		bootclasspath_fragment {
			name: "other-bootclasspath-fragment",
			contents: ["foo", "bar"],
			fragments: [
					{
							apex: "com.android.art",
							module: "art-bootclasspath-fragment",
					},
			],
		}
`,
	)

	checkAPIScopeStubs := func(message string, info java.HiddenAPIInfo, apiScope *java.HiddenAPIScope, expectedPaths ...string) {
		t.Helper()
		paths := info.TransitiveStubDexJarsByScope.StubDexJarsForScope(apiScope)
		android.AssertPathsRelativeToTopEquals(t, fmt.Sprintf("%s %s", message, apiScope), expectedPaths, paths)
	}

	// Check stub dex paths exported by art.
	artFragment := result.Module("art-bootclasspath-fragment", "android_common")
	artInfo := result.ModuleProvider(artFragment, java.HiddenAPIInfoProvider).(java.HiddenAPIInfo)

	bazPublicStubs := "out/soong/.intermediates/baz.stubs/android_common/dex/baz.stubs.jar"
	bazSystemStubs := "out/soong/.intermediates/baz.stubs.system/android_common/dex/baz.stubs.system.jar"
	bazTestStubs := "out/soong/.intermediates/baz.stubs.test/android_common/dex/baz.stubs.test.jar"

	checkAPIScopeStubs("art", artInfo, java.PublicHiddenAPIScope, bazPublicStubs)
	checkAPIScopeStubs("art", artInfo, java.SystemHiddenAPIScope, bazSystemStubs)
	checkAPIScopeStubs("art", artInfo, java.TestHiddenAPIScope, bazTestStubs)
	checkAPIScopeStubs("art", artInfo, java.CorePlatformHiddenAPIScope)

	// Check stub dex paths exported by other.
	otherFragment := result.Module("other-bootclasspath-fragment", "android_common")
	otherInfo := result.ModuleProvider(otherFragment, java.HiddenAPIInfoProvider).(java.HiddenAPIInfo)

	fooPublicStubs := "out/soong/.intermediates/foo.stubs/android_common/dex/foo.stubs.jar"
	fooSystemStubs := "out/soong/.intermediates/foo.stubs.system/android_common/dex/foo.stubs.system.jar"

	checkAPIScopeStubs("other", otherInfo, java.PublicHiddenAPIScope, bazPublicStubs, fooPublicStubs)
	checkAPIScopeStubs("other", otherInfo, java.SystemHiddenAPIScope, bazSystemStubs, fooSystemStubs)
	checkAPIScopeStubs("other", otherInfo, java.TestHiddenAPIScope, bazTestStubs, fooSystemStubs)
	checkAPIScopeStubs("other", otherInfo, java.CorePlatformHiddenAPIScope)
}

func checkBootclasspathFragment(t *testing.T, result *android.TestResult, moduleName, variantName string, expectedConfiguredModules string, expectedBootclasspathFragmentFiles string) {
	t.Helper()

	bootclasspathFragment := result.ModuleForTests(moduleName, variantName).Module().(*java.BootclasspathFragmentModule)

	bootclasspathFragmentInfo := result.ModuleProvider(bootclasspathFragment, java.BootclasspathFragmentApexContentInfoProvider).(java.BootclasspathFragmentApexContentInfo)
	modules := bootclasspathFragmentInfo.Modules()
	android.AssertStringEquals(t, "invalid modules for "+moduleName, expectedConfiguredModules, modules.String())

	// Get a list of all the paths in the boot image sorted by arch type.
	allPaths := []string{}
	bootImageFilesByArchType := bootclasspathFragmentInfo.AndroidBootImageFilesByArchType()
	for _, archType := range android.ArchTypeList() {
		if paths, ok := bootImageFilesByArchType[archType]; ok {
			for _, path := range paths {
				allPaths = append(allPaths, android.NormalizePathForTesting(path))
			}
		}
	}

	android.AssertTrimmedStringEquals(t, "invalid paths for "+moduleName, expectedBootclasspathFragmentFiles, strings.Join(allPaths, "\n"))
}

func TestBootclasspathFragmentInArtApex(t *testing.T) {
	commonPreparer := android.GroupFixturePreparers(
		prepareForTestWithBootclasspathFragment,
		prepareForTestWithArtApex,

		android.FixtureWithRootAndroidBp(`
		apex {
			name: "com.android.art",
			key: "com.android.art.key",
			bootclasspath_fragments: [
				"mybootclasspathfragment",
			],
			// bar (like foo) should be transitively included in this apex because it is part of the
			// mybootclasspathfragment bootclasspath_fragment. However, it is kept here to ensure that the
			// apex dedups the files correctly.
			java_libs: [
				"bar",
			],
			updatable: false,
		}

		apex_key {
			name: "com.android.art.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_library {
			name: "foo",
			srcs: ["b.java"],
			installable: true,
			apex_available: [
				"com.android.art",
			],
		}

		java_library {
			name: "bar",
			srcs: ["b.java"],
			installable: true,
			apex_available: [
				"com.android.art",
			],
		}

		java_import {
			name: "foo",
			jars: ["foo.jar"],
			apex_available: [
				"com.android.art",
			],
			compile_dex: true,
		}

		java_import {
			name: "bar",
			jars: ["bar.jar"],
			apex_available: [
				"com.android.art",
			],
			compile_dex: true,
		}
	`),
	)

	contentsInsert := func(contents []string) string {
		insert := ""
		if contents != nil {
			insert = fmt.Sprintf(`contents: ["%s"],`, strings.Join(contents, `", "`))
		}
		return insert
	}

	addSource := func(contents ...string) android.FixturePreparer {
		text := fmt.Sprintf(`
			bootclasspath_fragment {
				name: "mybootclasspathfragment",
				image_name: "art",
				%s
				apex_available: [
					"com.android.art",
				],
			}
		`, contentsInsert(contents))

		return android.FixtureAddTextFile("art/build/boot/Android.bp", text)
	}

	addPrebuilt := func(prefer bool, contents ...string) android.FixturePreparer {
		text := fmt.Sprintf(`
			prebuilt_apex {
				name: "com.android.art",
				arch: {
					arm64: {
						src: "com.android.art-arm64.apex",
					},
					arm: {
						src: "com.android.art-arm.apex",
					},
				},
				exported_bootclasspath_fragments: ["mybootclasspathfragment"],
			}

			prebuilt_bootclasspath_fragment {
				name: "mybootclasspathfragment",
				image_name: "art",
				%s
				prefer: %t,
				apex_available: [
					"com.android.art",
				],
			}
		`, contentsInsert(contents), prefer)
		return android.FixtureAddTextFile("prebuilts/module_sdk/art/Android.bp", text)
	}

	t.Run("boot image files from source", func(t *testing.T) {
		result := android.GroupFixturePreparers(
			commonPreparer,

			// Configure some libraries in the art bootclasspath_fragment that match the source
			// bootclasspath_fragment's contents property.
			java.FixtureConfigureBootJars("com.android.art:foo", "com.android.art:bar"),
			addSource("foo", "bar"),
		).RunTest(t)

		ensureExactContents(t, result.TestContext, "com.android.art", "android_common_com.android.art_image", []string{
			"etc/classpaths/bootclasspath.pb",
			"javalib/arm/boot.art",
			"javalib/arm/boot.oat",
			"javalib/arm/boot.vdex",
			"javalib/arm/boot-bar.art",
			"javalib/arm/boot-bar.oat",
			"javalib/arm/boot-bar.vdex",
			"javalib/arm64/boot.art",
			"javalib/arm64/boot.oat",
			"javalib/arm64/boot.vdex",
			"javalib/arm64/boot-bar.art",
			"javalib/arm64/boot-bar.oat",
			"javalib/arm64/boot-bar.vdex",
			"javalib/bar.jar",
			"javalib/foo.jar",
		})

		java.CheckModuleDependencies(t, result.TestContext, "com.android.art", "android_common_com.android.art_image", []string{
			`bar`,
			`com.android.art.key`,
			`mybootclasspathfragment`,
		})

		// Make sure that the source bootclasspath_fragment copies its dex files to the predefined
		// locations for the art image.
		module := result.ModuleForTests("mybootclasspathfragment", "android_common_apex10000")
		checkCopiesToPredefinedLocationForArt(t, result.Config, module, "bar", "foo")
	})

	t.Run("boot image files with preferred prebuilt", func(t *testing.T) {
		result := android.GroupFixturePreparers(
			commonPreparer,

			// Configure some libraries in the art bootclasspath_fragment that match the source
			// bootclasspath_fragment's contents property.
			java.FixtureConfigureBootJars("com.android.art:foo", "com.android.art:bar"),
			addSource("foo", "bar"),

			// Make sure that a preferred prebuilt with consistent contents doesn't affect the apex.
			addPrebuilt(true, "foo", "bar"),
		).RunTest(t)

		ensureExactContents(t, result.TestContext, "com.android.art", "android_common_com.android.art_image", []string{
			"etc/classpaths/bootclasspath.pb",
			"javalib/arm/boot.art",
			"javalib/arm/boot.oat",
			"javalib/arm/boot.vdex",
			"javalib/arm/boot-bar.art",
			"javalib/arm/boot-bar.oat",
			"javalib/arm/boot-bar.vdex",
			"javalib/arm64/boot.art",
			"javalib/arm64/boot.oat",
			"javalib/arm64/boot.vdex",
			"javalib/arm64/boot-bar.art",
			"javalib/arm64/boot-bar.oat",
			"javalib/arm64/boot-bar.vdex",
			"javalib/bar.jar",
			"javalib/foo.jar",
		})

		java.CheckModuleDependencies(t, result.TestContext, "com.android.art", "android_common_com.android.art_image", []string{
			`bar`,
			`com.android.art.key`,
			`mybootclasspathfragment`,
			`prebuilt_com.android.art`,
		})

		// Make sure that the prebuilt bootclasspath_fragment copies its dex files to the predefined
		// locations for the art image.
		module := result.ModuleForTests("prebuilt_mybootclasspathfragment", "android_common_com.android.art")
		checkCopiesToPredefinedLocationForArt(t, result.Config, module, "bar", "foo")
	})

	t.Run("source with inconsistency between config and contents", func(t *testing.T) {
		android.GroupFixturePreparers(
			commonPreparer,

			// Create an inconsistency between the ArtApexJars configuration and the art source
			// bootclasspath_fragment module's contents property.
			java.FixtureConfigureBootJars("com.android.art:foo"),
			addSource("foo", "bar"),
		).
			ExtendWithErrorHandler(android.FixtureExpectsAtLeastOneErrorMatchingPattern(`\QArtApexJars configuration specifies []string{"foo"}, contents property specifies []string{"foo", "bar"}\E`)).
			RunTest(t)
	})

	t.Run("prebuilt with inconsistency between config and contents", func(t *testing.T) {
		android.GroupFixturePreparers(
			commonPreparer,

			// Create an inconsistency between the ArtApexJars configuration and the art
			// prebuilt_bootclasspath_fragment module's contents property.
			java.FixtureConfigureBootJars("com.android.art:foo"),
			addPrebuilt(false, "foo", "bar"),
		).
			ExtendWithErrorHandler(android.FixtureExpectsAtLeastOneErrorMatchingPattern(`\QArtApexJars configuration specifies []string{"foo"}, contents property specifies []string{"foo", "bar"}\E`)).
			RunTest(t)
	})

	t.Run("preferred prebuilt with inconsistency between config and contents", func(t *testing.T) {
		android.GroupFixturePreparers(
			commonPreparer,

			// Create an inconsistency between the ArtApexJars configuration and the art
			// prebuilt_bootclasspath_fragment module's contents property.
			java.FixtureConfigureBootJars("com.android.art:foo"),
			addPrebuilt(true, "foo", "bar"),

			// Source contents property is consistent with the config.
			addSource("foo"),
		).
			ExtendWithErrorHandler(android.FixtureExpectsAtLeastOneErrorMatchingPattern(`\QArtApexJars configuration specifies []string{"foo"}, contents property specifies []string{"foo", "bar"}\E`)).
			RunTest(t)
	})

	t.Run("source preferred and prebuilt with inconsistency between config and contents", func(t *testing.T) {
		android.GroupFixturePreparers(
			commonPreparer,

			// Create an inconsistency between the ArtApexJars configuration and the art
			// prebuilt_bootclasspath_fragment module's contents property.
			java.FixtureConfigureBootJars("com.android.art:foo"),
			addPrebuilt(false, "foo", "bar"),

			// Source contents property is consistent with the config.
			addSource("foo"),

			// This should pass because while the prebuilt is inconsistent with the configuration it is
			// not actually used.
		).RunTest(t)
	})
}

func TestBootclasspathFragmentInPrebuiltArtApex(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForTestWithBootclasspathFragment,
		prepareForTestWithArtApex,

		android.FixtureMergeMockFs(android.MockFS{
			"com.android.art-arm64.apex": nil,
			"com.android.art-arm.apex":   nil,
		}),

		// Configure some libraries in the art bootclasspath_fragment.
		java.FixtureConfigureBootJars("com.android.art:foo", "com.android.art:bar"),
	).RunTestWithBp(t, `
		prebuilt_apex {
			name: "com.android.art",
			arch: {
				arm64: {
					src: "com.android.art-arm64.apex",
				},
				arm: {
					src: "com.android.art-arm.apex",
				},
			},
			exported_bootclasspath_fragments: ["mybootclasspathfragment"],
		}

		java_import {
			name: "foo",
			jars: ["foo.jar"],
			apex_available: [
				"com.android.art",
			],
		}

		java_import {
			name: "bar",
			jars: ["bar.jar"],
			apex_available: [
				"com.android.art",
			],
		}

		prebuilt_bootclasspath_fragment {
			name: "mybootclasspathfragment",
			image_name: "art",
			// Must match the "com.android.art:" entries passed to FixtureConfigureBootJars above.
			contents: ["foo", "bar"],
			apex_available: [
				"com.android.art",
			],
		}
	`)

	java.CheckModuleDependencies(t, result.TestContext, "com.android.art", "android_common_com.android.art", []string{
		`com.android.art.apex.selector`,
		`prebuilt_mybootclasspathfragment`,
	})

	java.CheckModuleDependencies(t, result.TestContext, "mybootclasspathfragment", "android_common_com.android.art", []string{
		`com.android.art.deapexer`,
		`dex2oatd`,
		`prebuilt_bar`,
		`prebuilt_foo`,
	})

	module := result.ModuleForTests("mybootclasspathfragment", "android_common_com.android.art")
	checkCopiesToPredefinedLocationForArt(t, result.Config, module, "bar", "foo")
}

// checkCopiesToPredefinedLocationForArt checks that the supplied modules are copied to the
// predefined locations of boot dex jars used as inputs for the ART boot image.
func checkCopiesToPredefinedLocationForArt(t *testing.T, config android.Config, module android.TestingModule, modules ...string) {
	t.Helper()
	bootJarLocations := []string{}
	for _, output := range module.AllOutputs() {
		output = android.StringRelativeToTop(config, output)
		if strings.HasPrefix(output, "out/soong/test_device/dex_artjars_input/") {
			bootJarLocations = append(bootJarLocations, output)
		}
	}

	sort.Strings(bootJarLocations)
	expected := []string{}
	for _, m := range modules {
		expected = append(expected, fmt.Sprintf("out/soong/test_device/dex_artjars_input/%s.jar", m))
	}
	sort.Strings(expected)

	android.AssertArrayString(t, "copies to predefined locations for art", expected, bootJarLocations)
}

func TestBootclasspathFragmentContentsNoName(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForTestWithBootclasspathFragment,
		prepareForTestWithMyapex,
		// Configure bootclasspath jars to ensure that hidden API encoding is performed on them.
		java.FixtureConfigureBootJars("myapex:foo", "myapex:bar"),
		// Make sure that the frameworks/base/Android.bp file exists as otherwise hidden API encoding
		// is disabled.
		android.FixtureAddTextFile("frameworks/base/Android.bp", ""),

		java.PrepareForTestWithJavaSdkLibraryFiles,
		java.FixtureWithLastReleaseApis("foo"),
	).RunTestWithBp(t, `
		apex {
			name: "myapex",
			key: "myapex.key",
			bootclasspath_fragments: [
				"mybootclasspathfragment",
			],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_sdk_library {
			name: "foo",
			srcs: ["b.java"],
			shared_library: false,
			public: {enabled: true},
			apex_available: [
				"myapex",
			],
		}

		java_library {
			name: "bar",
			srcs: ["b.java"],
			installable: true,
			apex_available: [
				"myapex",
			],
		}

		bootclasspath_fragment {
			name: "mybootclasspathfragment",
			contents: [
				"foo",
				"bar",
			],
			apex_available: [
				"myapex",
			],
		}
	`)

	ensureExactContents(t, result.TestContext, "myapex", "android_common_myapex_image", []string{
		// This does not include art, oat or vdex files as they are only included for the art boot
		// image.
		"etc/classpaths/bootclasspath.pb",
		"javalib/bar.jar",
		"javalib/foo.jar",
	})

	java.CheckModuleDependencies(t, result.TestContext, "myapex", "android_common_myapex_image", []string{
		`myapex.key`,
		`mybootclasspathfragment`,
	})

	apex := result.ModuleForTests("myapex", "android_common_myapex_image")
	apexRule := apex.Rule("apexRule")
	copyCommands := apexRule.Args["copy_commands"]

	// Make sure that the fragment provides the hidden API encoded dex jars to the APEX.
	fragment := result.Module("mybootclasspathfragment", "android_common_apex10000")

	info := result.ModuleProvider(fragment, java.BootclasspathFragmentApexContentInfoProvider).(java.BootclasspathFragmentApexContentInfo)

	checkFragmentExportedDexJar := func(name string, expectedDexJar string) {
		module := result.Module(name, "android_common_apex10000")
		dexJar, err := info.DexBootJarPathForContentModule(module)
		if err != nil {
			t.Error(err)
		}
		android.AssertPathRelativeToTopEquals(t, name+" dex", expectedDexJar, dexJar)

		expectedCopyCommand := fmt.Sprintf("&& cp -f %s out/soong/.intermediates/myapex/android_common_myapex_image/image.apex/javalib/%s.jar", expectedDexJar, name)
		android.AssertStringDoesContain(t, name+" apex copy command", copyCommands, expectedCopyCommand)
	}

	checkFragmentExportedDexJar("foo", "out/soong/.intermediates/mybootclasspathfragment/android_common_apex10000/hiddenapi-modular/encoded/foo.jar")
	checkFragmentExportedDexJar("bar", "out/soong/.intermediates/mybootclasspathfragment/android_common_apex10000/hiddenapi-modular/encoded/bar.jar")
}

func getDexJarPath(result *android.TestResult, name string) string {
	module := result.Module(name, "android_common")
	return module.(java.UsesLibraryDependency).DexJarBuildPath().RelativeToTop().String()
}

// TestBootclasspathFragment_HiddenAPIList checks to make sure that the correct parameters are
// passed to the hiddenapi list tool.
func TestBootclasspathFragment_HiddenAPIList(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForTestWithBootclasspathFragment,
		prepareForTestWithArtApex,
		prepareForTestWithMyapex,
		// Configure bootclasspath jars to ensure that hidden API encoding is performed on them.
		java.FixtureConfigureBootJars("com.android.art:baz", "com.android.art:quuz"),
		java.FixtureConfigureUpdatableBootJars("myapex:foo", "myapex:bar"),
		// Make sure that the frameworks/base/Android.bp file exists as otherwise hidden API encoding
		// is disabled.
		android.FixtureAddTextFile("frameworks/base/Android.bp", ""),

		java.PrepareForTestWithJavaSdkLibraryFiles,
		java.FixtureWithLastReleaseApis("foo", "quuz"),
	).RunTestWithBp(t, `
		apex {
			name: "com.android.art",
			key: "com.android.art.key",
			bootclasspath_fragments: ["art-bootclasspath-fragment"],
			updatable: false,
		}

		apex_key {
			name: "com.android.art.key",
			public_key: "com.android.art.avbpubkey",
			private_key: "com.android.art.pem",
		}

		java_library {
			name: "baz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
		}

		java_sdk_library {
			name: "quuz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
			public: {enabled: true},
			system: {enabled: true},
			test: {enabled: true},
			module_lib: {enabled: true},
		}

		bootclasspath_fragment {
			name: "art-bootclasspath-fragment",
			image_name: "art",
			// Must match the "com.android.art:" entries passed to FixtureConfigureBootJars above.
			contents: ["baz", "quuz"],
			apex_available: [
				"com.android.art",
			],
		}

		apex {
			name: "myapex",
			key: "myapex.key",
			bootclasspath_fragments: [
				"mybootclasspathfragment",
			],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_sdk_library {
			name: "foo",
			srcs: ["b.java"],
			shared_library: false,
			public: {enabled: true},
			apex_available: [
				"myapex",
			],
		}

		java_library {
			name: "bar",
			srcs: ["b.java"],
			installable: true,
			apex_available: [
				"myapex",
			],
		}

		bootclasspath_fragment {
			name: "mybootclasspathfragment",
			contents: [
				"foo",
				"bar",
			],
			apex_available: [
				"myapex",
			],
			fragments: [
				{
					apex: "com.android.art",
					module: "art-bootclasspath-fragment",
				},
			],
		}
	`)

	java.CheckModuleDependencies(t, result.TestContext, "mybootclasspathfragment", "android_common_apex10000", []string{
		"art-bootclasspath-fragment",
		"bar",
		"dex2oatd",
		"foo",
	})

	fooStubs := getDexJarPath(result, "foo.stubs")
	quuzPublicStubs := getDexJarPath(result, "quuz.stubs")
	quuzSystemStubs := getDexJarPath(result, "quuz.stubs.system")
	quuzTestStubs := getDexJarPath(result, "quuz.stubs.test")
	quuzModuleLibStubs := getDexJarPath(result, "quuz.stubs.module_lib")

	// Make sure that the fragment uses the quuz stub dex jars when generating the hidden API flags.
	fragment := result.ModuleForTests("mybootclasspathfragment", "android_common_apex10000")

	rule := fragment.Rule("modularHiddenAPIStubFlagsFile")
	command := rule.RuleParams.Command
	android.AssertStringDoesContain(t, "check correct rule", command, "hiddenapi list")

	// Make sure that the quuz stubs are available for resolving references from the implementation
	// boot dex jars provided by this module.
	android.AssertStringDoesContain(t, "quuz widest", command, "--dependency-stub-dex="+quuzModuleLibStubs)

	// Make sure that the quuz stubs are available for resolving references from the different API
	// stubs provided by this module.
	android.AssertStringDoesContain(t, "public", command, "--public-stub-classpath="+quuzPublicStubs+":"+fooStubs)
	android.AssertStringDoesContain(t, "system", command, "--system-stub-classpath="+quuzSystemStubs+":"+fooStubs)
	android.AssertStringDoesContain(t, "test", command, "--test-stub-classpath="+quuzTestStubs+":"+fooStubs)
}

// TestBootclasspathFragment_AndroidNonUpdatable checks to make sure that setting
// additional_stubs: ["android-non-updatable"] causes the source android-non-updatable modules to be
// added to the hiddenapi list tool.
func TestBootclasspathFragment_AndroidNonUpdatable(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForTestWithBootclasspathFragment,
		prepareForTestWithArtApex,
		prepareForTestWithMyapex,
		// Configure bootclasspath jars to ensure that hidden API encoding is performed on them.
		java.FixtureConfigureBootJars("com.android.art:baz", "com.android.art:quuz", "myapex:foo", "myapex:bar"),
		// Make sure that the frameworks/base/Android.bp file exists as otherwise hidden API encoding
		// is disabled.
		android.FixtureAddTextFile("frameworks/base/Android.bp", ""),

		java.PrepareForTestWithJavaSdkLibraryFiles,
		java.FixtureWithLastReleaseApis("foo", "android-non-updatable"),
	).RunTestWithBp(t, `
		java_sdk_library {
			name: "android-non-updatable",
			srcs: ["b.java"],
			compile_dex: true,
			public: {
				enabled: true,
			},
			system: {
				enabled: true,
			},
			test: {
				enabled: true,
			},
			module_lib: {
				enabled: true,
			},
		}

		apex {
			name: "com.android.art",
			key: "com.android.art.key",
			bootclasspath_fragments: ["art-bootclasspath-fragment"],
 			java_libs: [
				"baz",
				"quuz",
			],
			updatable: false,
		}

		apex_key {
			name: "com.android.art.key",
			public_key: "com.android.art.avbpubkey",
			private_key: "com.android.art.pem",
		}

		java_library {
			name: "baz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
		}

		java_library {
			name: "quuz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
		}

		bootclasspath_fragment {
			name: "art-bootclasspath-fragment",
			image_name: "art",
			// Must match the "com.android.art:" entries passed to FixtureConfigureBootJars above.
			contents: ["baz", "quuz"],
			apex_available: [
				"com.android.art",
			],
		}

		apex {
			name: "myapex",
			key: "myapex.key",
			bootclasspath_fragments: [
				"mybootclasspathfragment",
			],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_sdk_library {
			name: "foo",
			srcs: ["b.java"],
			shared_library: false,
			public: {enabled: true},
			apex_available: [
				"myapex",
			],
		}

		java_library {
			name: "bar",
			srcs: ["b.java"],
			installable: true,
			apex_available: [
				"myapex",
			],
		}

		bootclasspath_fragment {
			name: "mybootclasspathfragment",
			contents: [
				"foo",
				"bar",
			],
			apex_available: [
				"myapex",
			],
			additional_stubs: ["android-non-updatable"],
			fragments: [
				{
					apex: "com.android.art",
					module: "art-bootclasspath-fragment",
				},
			],
		}
	`)

	java.CheckModuleDependencies(t, result.TestContext, "mybootclasspathfragment", "android_common_apex10000", []string{
		"android-non-updatable.stubs",
		"android-non-updatable.stubs.module_lib",
		"android-non-updatable.stubs.system",
		"android-non-updatable.stubs.test",
		"art-bootclasspath-fragment",
		"bar",
		"dex2oatd",
		"foo",
	})

	nonUpdatablePublicStubs := getDexJarPath(result, "android-non-updatable.stubs")
	nonUpdatableSystemStubs := getDexJarPath(result, "android-non-updatable.stubs.system")
	nonUpdatableTestStubs := getDexJarPath(result, "android-non-updatable.stubs.test")
	nonUpdatableModuleLibStubs := getDexJarPath(result, "android-non-updatable.stubs.module_lib")

	// Make sure that the fragment uses the android-non-updatable modules when generating the hidden
	// API flags.
	fragment := result.ModuleForTests("mybootclasspathfragment", "android_common_apex10000")

	rule := fragment.Rule("modularHiddenAPIStubFlagsFile")
	command := rule.RuleParams.Command
	android.AssertStringDoesContain(t, "check correct rule", command, "hiddenapi list")

	// Make sure that the module_lib non-updatable stubs are available for resolving references from
	// the implementation boot dex jars provided by this module.
	android.AssertStringDoesContain(t, "android-non-updatable widest", command, "--dependency-stub-dex="+nonUpdatableModuleLibStubs)

	// Make sure that the appropriate non-updatable stubs are available for resolving references from
	// the different API stubs provided by this module.
	android.AssertStringDoesContain(t, "public", command, "--public-stub-classpath="+nonUpdatablePublicStubs)
	android.AssertStringDoesContain(t, "system", command, "--system-stub-classpath="+nonUpdatableSystemStubs)
	android.AssertStringDoesContain(t, "test", command, "--test-stub-classpath="+nonUpdatableTestStubs)
}

// TestBootclasspathFragment_AndroidNonUpdatable_AlwaysUsePrebuiltSdks checks to make sure that
// setting additional_stubs: ["android-non-updatable"] causes the prebuilt android-non-updatable
// modules to be added to the hiddenapi list tool.
func TestBootclasspathFragment_AndroidNonUpdatable_AlwaysUsePrebuiltSdks(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForTestWithBootclasspathFragment,
		java.PrepareForTestWithJavaDefaultModules,
		prepareForTestWithArtApex,
		prepareForTestWithMyapex,
		// Configure bootclasspath jars to ensure that hidden API encoding is performed on them.
		java.FixtureConfigureBootJars("com.android.art:baz", "com.android.art:quuz", "myapex:foo", "myapex:bar"),
		// Make sure that the frameworks/base/Android.bp file exists as otherwise hidden API encoding
		// is disabled.
		android.FixtureAddTextFile("frameworks/base/Android.bp", ""),

		android.FixtureModifyProductVariables(func(variables android.FixtureProductVariables) {
			variables.Always_use_prebuilt_sdks = proptools.BoolPtr(true)
		}),

		java.PrepareForTestWithJavaSdkLibraryFiles,
		java.FixtureWithPrebuiltApis(map[string][]string{
			"current": {"android-non-updatable"},
			"30":      {"foo"},
		}),
	).RunTestWithBp(t, `
		apex {
			name: "com.android.art",
			key: "com.android.art.key",
			bootclasspath_fragments: ["art-bootclasspath-fragment"],
 			java_libs: [
				"baz",
				"quuz",
			],
			updatable: false,
		}

		apex_key {
			name: "com.android.art.key",
			public_key: "com.android.art.avbpubkey",
			private_key: "com.android.art.pem",
		}

		java_library {
			name: "baz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
		}

		java_library {
			name: "quuz",
			apex_available: [
				"com.android.art",
			],
			srcs: ["b.java"],
			compile_dex: true,
		}

		bootclasspath_fragment {
			name: "art-bootclasspath-fragment",
			image_name: "art",
			// Must match the "com.android.art:" entries passed to FixtureConfigureBootJars above.
			contents: ["baz", "quuz"],
			apex_available: [
				"com.android.art",
			],
		}

		apex {
			name: "myapex",
			key: "myapex.key",
			bootclasspath_fragments: [
				"mybootclasspathfragment",
			],
			updatable: false,
		}

		apex_key {
			name: "myapex.key",
			public_key: "testkey.avbpubkey",
			private_key: "testkey.pem",
		}

		java_sdk_library {
			name: "foo",
			srcs: ["b.java"],
			shared_library: false,
			public: {enabled: true},
			apex_available: [
				"myapex",
			],
		}

		java_library {
			name: "bar",
			srcs: ["b.java"],
			installable: true,
			apex_available: [
				"myapex",
			],
		}

		bootclasspath_fragment {
			name: "mybootclasspathfragment",
			contents: [
				"foo",
				"bar",
			],
			apex_available: [
				"myapex",
			],
			additional_stubs: ["android-non-updatable"],
			fragments: [
				{
					apex: "com.android.art",
					module: "art-bootclasspath-fragment",
				},
			],
		}
	`)

	java.CheckModuleDependencies(t, result.TestContext, "mybootclasspathfragment", "android_common_apex10000", []string{
		"art-bootclasspath-fragment",
		"bar",
		"dex2oatd",
		"foo",
		"prebuilt_sdk_module-lib_current_android-non-updatable",
		"prebuilt_sdk_public_current_android-non-updatable",
		"prebuilt_sdk_system_current_android-non-updatable",
		"prebuilt_sdk_test_current_android-non-updatable",
	})

	nonUpdatablePublicStubs := getDexJarPath(result, "sdk_public_current_android-non-updatable")
	nonUpdatableSystemStubs := getDexJarPath(result, "sdk_system_current_android-non-updatable")
	nonUpdatableTestStubs := getDexJarPath(result, "sdk_test_current_android-non-updatable")
	nonUpdatableModuleLibStubs := getDexJarPath(result, "sdk_module-lib_current_android-non-updatable")

	// Make sure that the fragment uses the android-non-updatable modules when generating the hidden
	// API flags.
	fragment := result.ModuleForTests("mybootclasspathfragment", "android_common_apex10000")

	rule := fragment.Rule("modularHiddenAPIStubFlagsFile")
	command := rule.RuleParams.Command
	android.AssertStringDoesContain(t, "check correct rule", command, "hiddenapi list")

	// Make sure that the module_lib non-updatable stubs are available for resolving references from
	// the implementation boot dex jars provided by this module.
	android.AssertStringDoesContain(t, "android-non-updatable widest", command, "--dependency-stub-dex="+nonUpdatableModuleLibStubs)

	// Make sure that the appropriate non-updatable stubs are available for resolving references from
	// the different API stubs provided by this module.
	android.AssertStringDoesContain(t, "public", command, "--public-stub-classpath="+nonUpdatablePublicStubs)
	android.AssertStringDoesContain(t, "system", command, "--system-stub-classpath="+nonUpdatableSystemStubs)
	android.AssertStringDoesContain(t, "test", command, "--test-stub-classpath="+nonUpdatableTestStubs)
}

// TODO(b/177892522) - add test for host apex.
