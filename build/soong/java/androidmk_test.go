// Copyright 2019 Google Inc. All rights reserved.
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

package java

import (
	"reflect"
	"testing"

	"android/soong/android"
)

func TestRequired(t *testing.T) {
	ctx, _ := testJava(t, `
		java_library {
			name: "foo",
			srcs: ["a.java"],
			required: ["libfoo"],
		}
	`)

	mod := ctx.ModuleForTests("foo", "android_common").Module()
	entries := android.AndroidMkEntriesForTest(t, ctx, mod)[0]

	expected := []string{"libfoo"}
	actual := entries.EntryMap["LOCAL_REQUIRED_MODULES"]
	if !reflect.DeepEqual(expected, actual) {
		t.Errorf("Unexpected required modules - expected: %q, actual: %q", expected, actual)
	}
}

func TestHostdex(t *testing.T) {
	ctx, _ := testJava(t, `
		java_library {
			name: "foo",
			srcs: ["a.java"],
			hostdex: true,
		}
	`)

	mod := ctx.ModuleForTests("foo", "android_common").Module()
	entriesList := android.AndroidMkEntriesForTest(t, ctx, mod)
	if len(entriesList) != 2 {
		t.Errorf("two entries are expected, but got %d", len(entriesList))
	}

	mainEntries := &entriesList[0]
	expected := []string{"foo"}
	actual := mainEntries.EntryMap["LOCAL_MODULE"]
	if !reflect.DeepEqual(expected, actual) {
		t.Errorf("Unexpected module name - expected: %q, actual: %q", expected, actual)
	}

	subEntries := &entriesList[1]
	expected = []string{"foo-hostdex"}
	actual = subEntries.EntryMap["LOCAL_MODULE"]
	if !reflect.DeepEqual(expected, actual) {
		t.Errorf("Unexpected module name - expected: %q, actual: %q", expected, actual)
	}
}

func TestHostdexRequired(t *testing.T) {
	ctx, _ := testJava(t, `
		java_library {
			name: "foo",
			srcs: ["a.java"],
			hostdex: true,
			required: ["libfoo"],
		}
	`)

	mod := ctx.ModuleForTests("foo", "android_common").Module()
	entriesList := android.AndroidMkEntriesForTest(t, ctx, mod)
	if len(entriesList) != 2 {
		t.Errorf("two entries are expected, but got %d", len(entriesList))
	}

	mainEntries := &entriesList[0]
	expected := []string{"libfoo"}
	actual := mainEntries.EntryMap["LOCAL_REQUIRED_MODULES"]
	if !reflect.DeepEqual(expected, actual) {
		t.Errorf("Unexpected required modules - expected: %q, actual: %q", expected, actual)
	}

	subEntries := &entriesList[1]
	expected = []string{"libfoo"}
	actual = subEntries.EntryMap["LOCAL_REQUIRED_MODULES"]
	if !reflect.DeepEqual(expected, actual) {
		t.Errorf("Unexpected required modules - expected: %q, actual: %q", expected, actual)
	}
}

func TestHostdexSpecificRequired(t *testing.T) {
	ctx, _ := testJava(t, `
		java_library {
			name: "foo",
			srcs: ["a.java"],
			hostdex: true,
			target: {
				hostdex: {
					required: ["libfoo"],
				},
			},
		}
	`)

	mod := ctx.ModuleForTests("foo", "android_common").Module()
	entriesList := android.AndroidMkEntriesForTest(t, ctx, mod)
	if len(entriesList) != 2 {
		t.Errorf("two entries are expected, but got %d", len(entriesList))
	}

	mainEntries := &entriesList[0]
	if r, ok := mainEntries.EntryMap["LOCAL_REQUIRED_MODULES"]; ok {
		t.Errorf("Unexpected required modules: %q", r)
	}

	subEntries := &entriesList[1]
	expected := []string{"libfoo"}
	actual := subEntries.EntryMap["LOCAL_REQUIRED_MODULES"]
	if !reflect.DeepEqual(expected, actual) {
		t.Errorf("Unexpected required modules - expected: %q, actual: %q", expected, actual)
	}
}

func TestJavaSdkLibrary_RequireXmlPermissionFile(t *testing.T) {
	result := android.GroupFixturePreparers(
		prepareForJavaTest,
		PrepareForTestWithJavaSdkLibraryFiles,
		FixtureWithLastReleaseApis("foo-shared_library", "foo-no_shared_library"),
	).RunTestWithBp(t, `
		java_sdk_library {
			name: "foo-shared_library",
			srcs: ["a.java"],
		}
		java_sdk_library {
			name: "foo-no_shared_library",
			srcs: ["a.java"],
			shared_library: false,
		}
		`)

	// Verify the existence of internal modules
	result.ModuleForTests("foo-shared_library.xml", "android_common")

	testCases := []struct {
		moduleName string
		expected   []string
	}{
		{"foo-shared_library", []string{"foo-shared_library.xml"}},
		{"foo-no_shared_library", nil},
	}
	for _, tc := range testCases {
		mod := result.ModuleForTests(tc.moduleName, "android_common").Module()
		entries := android.AndroidMkEntriesForTest(t, result.TestContext, mod)[0]
		actual := entries.EntryMap["LOCAL_REQUIRED_MODULES"]
		if !reflect.DeepEqual(tc.expected, actual) {
			t.Errorf("Unexpected required modules - expected: %q, actual: %q", tc.expected, actual)
		}
	}
}

func TestImportSoongDexJar(t *testing.T) {
	result := PrepareForTestWithJavaDefaultModules.RunTestWithBp(t, `
		java_import {
			name: "my-java-import",
			jars: ["a.jar"],
			prefer: true,
			compile_dex: true,
		}
	`)

	mod := result.Module("my-java-import", "android_common")
	entries := android.AndroidMkEntriesForTest(t, result.TestContext, mod)[0]
	expectedSoongDexJar := "out/soong/.intermediates/my-java-import/android_common/dex/my-java-import.jar"
	actualSoongDexJar := entries.EntryMap["LOCAL_SOONG_DEX_JAR"]

	android.AssertStringPathsRelativeToTopEquals(t, "LOCAL_SOONG_DEX_JAR", result.Config, []string{expectedSoongDexJar}, actualSoongDexJar)
}

func TestAndroidTestHelperApp_LocalDisableTestConfig(t *testing.T) {
	ctx, _ := testJava(t, `
		android_test_helper_app {
			name: "foo",
			srcs: ["a.java"],
		}
	`)

	mod := ctx.ModuleForTests("foo", "android_common").Module()
	entries := android.AndroidMkEntriesForTest(t, ctx, mod)[0]

	expected := []string{"true"}
	actual := entries.EntryMap["LOCAL_DISABLE_TEST_CONFIG"]
	if !reflect.DeepEqual(expected, actual) {
		t.Errorf("Unexpected flag value - expected: %q, actual: %q", expected, actual)
	}
}
