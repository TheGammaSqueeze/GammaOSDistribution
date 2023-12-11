// Copyright 2020 Google Inc. All rights reserved.
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

package bp2build

import (
	"android/soong/android"
	"android/soong/genrule"
	"strings"
	"testing"
)

func TestGenerateSoongModuleTargets(t *testing.T) {
	testCases := []struct {
		bp                  string
		expectedBazelTarget string
	}{
		{
			bp: `custom { name: "foo" }
		`,
			expectedBazelTarget: `soong_module(
    name = "foo",
    soong_module_name = "foo",
    soong_module_type = "custom",
    soong_module_variant = "",
    soong_module_deps = [
    ],
)`,
		},
		{
			bp: `custom {
	name: "foo",
	ramdisk: true,
}
		`,
			expectedBazelTarget: `soong_module(
    name = "foo",
    soong_module_name = "foo",
    soong_module_type = "custom",
    soong_module_variant = "",
    soong_module_deps = [
    ],
    ramdisk = True,
)`,
		},
		{
			bp: `custom {
	name: "foo",
	owner: "a_string_with\"quotes\"_and_\\backslashes\\\\",
}
		`,
			expectedBazelTarget: `soong_module(
    name = "foo",
    soong_module_name = "foo",
    soong_module_type = "custom",
    soong_module_variant = "",
    soong_module_deps = [
    ],
    owner = "a_string_with\"quotes\"_and_\\backslashes\\\\",
)`,
		},
		{
			bp: `custom {
	name: "foo",
	required: ["bar"],
}
		`,
			expectedBazelTarget: `soong_module(
    name = "foo",
    soong_module_name = "foo",
    soong_module_type = "custom",
    soong_module_variant = "",
    soong_module_deps = [
    ],
    required = ["bar"],
)`,
		},
		{
			bp: `custom {
	name: "foo",
	target_required: ["qux", "bazqux"],
}
		`,
			expectedBazelTarget: `soong_module(
    name = "foo",
    soong_module_name = "foo",
    soong_module_type = "custom",
    soong_module_variant = "",
    soong_module_deps = [
    ],
    target_required = [
        "qux",
        "bazqux",
    ],
)`,
		},
		{
			bp: `custom {
	name: "foo",
	dist: {
		targets: ["goal_foo"],
		tag: ".foo",
	},
	dists: [{
		targets: ["goal_bar"],
		tag: ".bar",
	}],
}
		`,
			expectedBazelTarget: `soong_module(
    name = "foo",
    soong_module_name = "foo",
    soong_module_type = "custom",
    soong_module_variant = "",
    soong_module_deps = [
    ],
    dist = {
        "tag": ".foo",
        "targets": ["goal_foo"],
    },
    dists = [{
        "tag": ".bar",
        "targets": ["goal_bar"],
    }],
)`,
		},
		{
			bp: `custom {
	name: "foo",
	required: ["bar"],
	target_required: ["qux", "bazqux"],
	ramdisk: true,
	owner: "custom_owner",
	dists: [
		{
			tag: ".tag",
			targets: ["my_goal"],
		},
	],
}
		`,
			expectedBazelTarget: `soong_module(
    name = "foo",
    soong_module_name = "foo",
    soong_module_type = "custom",
    soong_module_variant = "",
    soong_module_deps = [
    ],
    dists = [{
        "tag": ".tag",
        "targets": ["my_goal"],
    }],
    owner = "custom_owner",
    ramdisk = True,
    required = ["bar"],
    target_required = [
        "qux",
        "bazqux",
    ],
)`,
		},
	}

	dir := "."
	for _, testCase := range testCases {
		config := android.TestConfig(buildDir, nil, testCase.bp, nil)
		ctx := android.NewTestContext(config)

		ctx.RegisterModuleType("custom", customModuleFactory)
		ctx.Register()

		_, errs := ctx.ParseFileList(dir, []string{"Android.bp"})
		android.FailIfErrored(t, errs)
		_, errs = ctx.PrepareBuildActions(config)
		android.FailIfErrored(t, errs)

		codegenCtx := NewCodegenContext(config, *ctx.Context, QueryView)
		bazelTargets := generateBazelTargetsForDir(codegenCtx, dir)
		if actualCount, expectedCount := len(bazelTargets), 1; actualCount != expectedCount {
			t.Fatalf("Expected %d bazel target, got %d", expectedCount, actualCount)
		}

		actualBazelTarget := bazelTargets[0]
		if actualBazelTarget.content != testCase.expectedBazelTarget {
			t.Errorf(
				"Expected generated Bazel target to be '%s', got '%s'",
				testCase.expectedBazelTarget,
				actualBazelTarget.content,
			)
		}
	}
}

func TestGenerateBazelTargetModules(t *testing.T) {
	testCases := []struct {
		name                 string
		bp                   string
		expectedBazelTargets []string
	}{
		{
			bp: `custom {
	name: "foo",
    string_list_prop: ["a", "b"],
    string_prop: "a",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`custom(
    name = "foo",
    string_list_prop = [
        "a",
        "b",
    ],
    string_prop = "a",
)`,
			},
		},
		{
			bp: `custom {
	name: "control_characters",
    string_list_prop: ["\t", "\n"],
    string_prop: "a\t\n\r",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`custom(
    name = "control_characters",
    string_list_prop = [
        "\t",
        "\n",
    ],
    string_prop = "a\t\n\r",
)`,
			},
		},
		{
			bp: `custom {
  name: "has_dep",
  arch_paths: [":dep"],
  bazel_module: { bp2build_available: true },
}

custom {
  name: "dep",
  arch_paths: ["abc"],
  bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`custom(
    name = "dep",
    arch_paths = ["abc"],
)`,
				`custom(
    name = "has_dep",
    arch_paths = [":dep"],
)`,
			},
		},
		{
			bp: `custom {
    name: "arch_paths",
    arch: {
      x86: {
        arch_paths: ["abc"],
      },
    },
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`custom(
    name = "arch_paths",
    arch_paths = select({
        "//build/bazel/platforms/arch:x86": ["abc"],
        "//conditions:default": [],
    }),
)`,
			},
		},
		{
			bp: `custom {
  name: "has_dep",
  arch: {
    x86: {
      arch_paths: [":dep"],
    },
  },
  bazel_module: { bp2build_available: true },
}

custom {
    name: "dep",
    arch_paths: ["abc"],
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`custom(
    name = "dep",
    arch_paths = ["abc"],
)`,
				`custom(
    name = "has_dep",
    arch_paths = select({
        "//build/bazel/platforms/arch:x86": [":dep"],
        "//conditions:default": [],
    }),
)`,
			},
		},
	}

	dir := "."
	for _, testCase := range testCases {
		config := android.TestConfig(buildDir, nil, testCase.bp, nil)
		ctx := android.NewTestContext(config)

		ctx.RegisterModuleType("custom", customModuleFactory)
		ctx.RegisterBp2BuildMutator("custom", customBp2BuildMutator)
		ctx.RegisterForBazelConversion()

		_, errs := ctx.ParseFileList(dir, []string{"Android.bp"})
		if Errored(t, "", errs) {
			continue
		}
		_, errs = ctx.ResolveDependencies(config)
		if Errored(t, "", errs) {
			continue
		}

		codegenCtx := NewCodegenContext(config, *ctx.Context, Bp2Build)
		bazelTargets := generateBazelTargetsForDir(codegenCtx, dir)

		if actualCount, expectedCount := len(bazelTargets), len(testCase.expectedBazelTargets); actualCount != expectedCount {
			t.Errorf("Expected %d bazel target, got %d", expectedCount, actualCount)
		} else {
			for i, expectedBazelTarget := range testCase.expectedBazelTargets {
				actualBazelTarget := bazelTargets[i]
				if actualBazelTarget.content != expectedBazelTarget {
					t.Errorf(
						"Expected generated Bazel target to be '%s', got '%s'",
						expectedBazelTarget,
						actualBazelTarget.content,
					)
				}
			}
		}
	}
}

func TestLoadStatements(t *testing.T) {
	testCases := []struct {
		bazelTargets           BazelTargets
		expectedLoadStatements string
	}{
		{
			bazelTargets: BazelTargets{
				BazelTarget{
					name:            "foo",
					ruleClass:       "cc_library",
					bzlLoadLocation: "//build/bazel/rules:cc.bzl",
				},
			},
			expectedLoadStatements: `load("//build/bazel/rules:cc.bzl", "cc_library")`,
		},
		{
			bazelTargets: BazelTargets{
				BazelTarget{
					name:            "foo",
					ruleClass:       "cc_library",
					bzlLoadLocation: "//build/bazel/rules:cc.bzl",
				},
				BazelTarget{
					name:            "bar",
					ruleClass:       "cc_library",
					bzlLoadLocation: "//build/bazel/rules:cc.bzl",
				},
			},
			expectedLoadStatements: `load("//build/bazel/rules:cc.bzl", "cc_library")`,
		},
		{
			bazelTargets: BazelTargets{
				BazelTarget{
					name:            "foo",
					ruleClass:       "cc_library",
					bzlLoadLocation: "//build/bazel/rules:cc.bzl",
				},
				BazelTarget{
					name:            "bar",
					ruleClass:       "cc_binary",
					bzlLoadLocation: "//build/bazel/rules:cc.bzl",
				},
			},
			expectedLoadStatements: `load("//build/bazel/rules:cc.bzl", "cc_binary", "cc_library")`,
		},
		{
			bazelTargets: BazelTargets{
				BazelTarget{
					name:            "foo",
					ruleClass:       "cc_library",
					bzlLoadLocation: "//build/bazel/rules:cc.bzl",
				},
				BazelTarget{
					name:            "bar",
					ruleClass:       "cc_binary",
					bzlLoadLocation: "//build/bazel/rules:cc.bzl",
				},
				BazelTarget{
					name:            "baz",
					ruleClass:       "java_binary",
					bzlLoadLocation: "//build/bazel/rules:java.bzl",
				},
			},
			expectedLoadStatements: `load("//build/bazel/rules:cc.bzl", "cc_binary", "cc_library")
load("//build/bazel/rules:java.bzl", "java_binary")`,
		},
		{
			bazelTargets: BazelTargets{
				BazelTarget{
					name:            "foo",
					ruleClass:       "cc_binary",
					bzlLoadLocation: "//build/bazel/rules:cc.bzl",
				},
				BazelTarget{
					name:            "bar",
					ruleClass:       "java_binary",
					bzlLoadLocation: "//build/bazel/rules:java.bzl",
				},
				BazelTarget{
					name:      "baz",
					ruleClass: "genrule",
					// Note: no bzlLoadLocation for native rules
				},
			},
			expectedLoadStatements: `load("//build/bazel/rules:cc.bzl", "cc_binary")
load("//build/bazel/rules:java.bzl", "java_binary")`,
		},
	}

	for _, testCase := range testCases {
		actual := testCase.bazelTargets.LoadStatements()
		expected := testCase.expectedLoadStatements
		if actual != expected {
			t.Fatalf("Expected load statements to be %s, got %s", expected, actual)
		}
	}

}

func TestGenerateBazelTargetModules_OneToMany_LoadedFromStarlark(t *testing.T) {
	testCases := []struct {
		bp                       string
		expectedBazelTarget      string
		expectedBazelTargetCount int
		expectedLoadStatements   string
	}{
		{
			bp: `custom {
    name: "bar",
    bazel_module: { bp2build_available: true  },
}`,
			expectedBazelTarget: `my_library(
    name = "bar",
)

my_proto_library(
    name = "bar_my_proto_library_deps",
)

proto_library(
    name = "bar_proto_library_deps",
)`,
			expectedBazelTargetCount: 3,
			expectedLoadStatements: `load("//build/bazel/rules:proto.bzl", "my_proto_library", "proto_library")
load("//build/bazel/rules:rules.bzl", "my_library")`,
		},
	}

	dir := "."
	for _, testCase := range testCases {
		config := android.TestConfig(buildDir, nil, testCase.bp, nil)
		ctx := android.NewTestContext(config)
		ctx.RegisterModuleType("custom", customModuleFactory)
		ctx.RegisterBp2BuildMutator("custom", customBp2BuildMutatorFromStarlark)
		ctx.RegisterForBazelConversion()

		_, errs := ctx.ParseFileList(dir, []string{"Android.bp"})
		android.FailIfErrored(t, errs)
		_, errs = ctx.ResolveDependencies(config)
		android.FailIfErrored(t, errs)

		codegenCtx := NewCodegenContext(config, *ctx.Context, Bp2Build)
		bazelTargets := generateBazelTargetsForDir(codegenCtx, dir)
		if actualCount := len(bazelTargets); actualCount != testCase.expectedBazelTargetCount {
			t.Fatalf("Expected %d bazel target, got %d", testCase.expectedBazelTargetCount, actualCount)
		}

		actualBazelTargets := bazelTargets.String()
		if actualBazelTargets != testCase.expectedBazelTarget {
			t.Errorf(
				"Expected generated Bazel target to be '%s', got '%s'",
				testCase.expectedBazelTarget,
				actualBazelTargets,
			)
		}

		actualLoadStatements := bazelTargets.LoadStatements()
		if actualLoadStatements != testCase.expectedLoadStatements {
			t.Errorf(
				"Expected generated load statements to be '%s', got '%s'",
				testCase.expectedLoadStatements,
				actualLoadStatements,
			)
		}
	}
}

func TestModuleTypeBp2Build(t *testing.T) {
	otherGenruleBp := map[string]string{
		"other/Android.bp": `genrule {
    name: "foo.tool",
    out: ["foo_tool.out"],
    srcs: ["foo_tool.in"],
    cmd: "cp $(in) $(out)",
}
genrule {
    name: "other.tool",
    out: ["other_tool.out"],
    srcs: ["other_tool.in"],
    cmd: "cp $(in) $(out)",
}`,
	}

	testCases := []struct {
		description                        string
		moduleTypeUnderTest                string
		moduleTypeUnderTestFactory         android.ModuleFactory
		moduleTypeUnderTestBp2BuildMutator func(android.TopDownMutatorContext)
		preArchMutators                    []android.RegisterMutatorFunc
		depsMutators                       []android.RegisterMutatorFunc
		bp                                 string
		expectedBazelTargets               []string
		fs                                 map[string]string
		dir                                string
	}{
		{
			description:                        "filegroup with does not specify srcs",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{
				`filegroup(
    name = "fg_foo",
)`,
			},
		},
		{
			description:                        "filegroup with no srcs",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    srcs: [],
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{
				`filegroup(
    name = "fg_foo",
)`,
			},
		},
		{
			description:                        "filegroup with srcs",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    srcs: ["a", "b"],
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`filegroup(
    name = "fg_foo",
    srcs = [
        "a",
        "b",
    ],
)`,
			},
		},
		{
			description:                        "filegroup with excludes srcs",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    srcs: ["a", "b"],
    exclude_srcs: ["a"],
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`filegroup(
    name = "fg_foo",
    srcs = ["b"],
)`,
			},
		},
		{
			description:                        "filegroup with glob",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "foo",
    srcs: ["**/*.txt"],
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`filegroup(
    name = "foo",
    srcs = [
        "other/a.txt",
        "other/b.txt",
        "other/subdir/a.txt",
    ],
)`,
			},
			fs: map[string]string{
				"other/a.txt":        "",
				"other/b.txt":        "",
				"other/subdir/a.txt": "",
				"other/file":         "",
			},
		},
		{
			description:                        "filegroup with glob in subdir",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "foo",
    srcs: ["a.txt"],
    bazel_module: { bp2build_available: true },
}`,
			dir: "other",
			expectedBazelTargets: []string{`filegroup(
    name = "fg_foo",
    srcs = [
        "a.txt",
        "b.txt",
        "subdir/a.txt",
    ],
)`,
			},
			fs: map[string]string{
				"other/Android.bp": `filegroup {
    name: "fg_foo",
    srcs: ["**/*.txt"],
    bazel_module: { bp2build_available: true },
}`,
				"other/a.txt":        "",
				"other/b.txt":        "",
				"other/subdir/a.txt": "",
				"other/file":         "",
			},
		},
		{
			description:                        "depends_on_other_dir_module",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "foobar",
    srcs: [
        ":foo",
        "c",
    ],
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`filegroup(
    name = "foobar",
    srcs = [
        "//other:foo",
        "c",
    ],
)`,
			},
			fs: map[string]string{
				"other/Android.bp": `filegroup {
    name: "foo",
    srcs: ["a", "b"],
}`,
			},
		},
		{
			description:                        "genrule with command line variable replacements",
			moduleTypeUnderTest:                "genrule",
			moduleTypeUnderTestFactory:         genrule.GenRuleFactory,
			moduleTypeUnderTestBp2BuildMutator: genrule.GenruleBp2Build,
			depsMutators:                       []android.RegisterMutatorFunc{genrule.RegisterGenruleBp2BuildDeps},
			bp: `genrule {
    name: "foo.tool",
    out: ["foo_tool.out"],
    srcs: ["foo_tool.in"],
    cmd: "cp $(in) $(out)",
    bazel_module: { bp2build_available: true },
}

genrule {
    name: "foo",
    out: ["foo.out"],
    srcs: ["foo.in"],
    tools: [":foo.tool"],
    cmd: "$(location :foo.tool) --genDir=$(genDir) arg $(in) $(out)",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{
				`genrule(
    name = "foo",
    cmd = "$(location :foo.tool) --genDir=$(GENDIR) arg $(SRCS) $(OUTS)",
    outs = ["foo.out"],
    srcs = ["foo.in"],
    tools = [":foo.tool"],
)`,
				`genrule(
    name = "foo.tool",
    cmd = "cp $(SRCS) $(OUTS)",
    outs = ["foo_tool.out"],
    srcs = ["foo_tool.in"],
)`,
			},
		},
		{
			description:                        "genrule using $(locations :label)",
			moduleTypeUnderTest:                "genrule",
			moduleTypeUnderTestFactory:         genrule.GenRuleFactory,
			moduleTypeUnderTestBp2BuildMutator: genrule.GenruleBp2Build,
			depsMutators:                       []android.RegisterMutatorFunc{genrule.RegisterGenruleBp2BuildDeps},
			bp: `genrule {
    name: "foo.tools",
    out: ["foo_tool.out", "foo_tool2.out"],
    srcs: ["foo_tool.in"],
    cmd: "cp $(in) $(out)",
    bazel_module: { bp2build_available: true },
}

genrule {
    name: "foo",
    out: ["foo.out"],
    srcs: ["foo.in"],
    tools: [":foo.tools"],
    cmd: "$(locations :foo.tools) -s $(out) $(in)",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`genrule(
    name = "foo",
    cmd = "$(locations :foo.tools) -s $(OUTS) $(SRCS)",
    outs = ["foo.out"],
    srcs = ["foo.in"],
    tools = [":foo.tools"],
)`,
				`genrule(
    name = "foo.tools",
    cmd = "cp $(SRCS) $(OUTS)",
    outs = [
        "foo_tool.out",
        "foo_tool2.out",
    ],
    srcs = ["foo_tool.in"],
)`,
			},
		},
		{
			description:                        "genrule using $(locations //absolute:label)",
			moduleTypeUnderTest:                "genrule",
			moduleTypeUnderTestFactory:         genrule.GenRuleFactory,
			moduleTypeUnderTestBp2BuildMutator: genrule.GenruleBp2Build,
			depsMutators:                       []android.RegisterMutatorFunc{genrule.RegisterGenruleBp2BuildDeps},
			bp: `genrule {
    name: "foo",
    out: ["foo.out"],
    srcs: ["foo.in"],
    tool_files: [":foo.tool"],
    cmd: "$(locations :foo.tool) -s $(out) $(in)",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`genrule(
    name = "foo",
    cmd = "$(locations //other:foo.tool) -s $(OUTS) $(SRCS)",
    outs = ["foo.out"],
    srcs = ["foo.in"],
    tools = ["//other:foo.tool"],
)`,
			},
			fs: otherGenruleBp,
		},
		{
			description:                        "genrule srcs using $(locations //absolute:label)",
			moduleTypeUnderTest:                "genrule",
			moduleTypeUnderTestFactory:         genrule.GenRuleFactory,
			moduleTypeUnderTestBp2BuildMutator: genrule.GenruleBp2Build,
			depsMutators:                       []android.RegisterMutatorFunc{genrule.RegisterGenruleBp2BuildDeps},
			bp: `genrule {
    name: "foo",
    out: ["foo.out"],
    srcs: [":other.tool"],
    tool_files: [":foo.tool"],
    cmd: "$(locations :foo.tool) -s $(out) $(location :other.tool)",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`genrule(
    name = "foo",
    cmd = "$(locations //other:foo.tool) -s $(OUTS) $(location //other:other.tool)",
    outs = ["foo.out"],
    srcs = ["//other:other.tool"],
    tools = ["//other:foo.tool"],
)`,
			},
			fs: otherGenruleBp,
		},
		{
			description:                        "genrule using $(location) label should substitute first tool label automatically",
			moduleTypeUnderTest:                "genrule",
			moduleTypeUnderTestFactory:         genrule.GenRuleFactory,
			moduleTypeUnderTestBp2BuildMutator: genrule.GenruleBp2Build,
			depsMutators:                       []android.RegisterMutatorFunc{genrule.RegisterGenruleBp2BuildDeps},
			bp: `genrule {
    name: "foo",
    out: ["foo.out"],
    srcs: ["foo.in"],
    tool_files: [":foo.tool", ":other.tool"],
    cmd: "$(location) -s $(out) $(in)",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`genrule(
    name = "foo",
    cmd = "$(location //other:foo.tool) -s $(OUTS) $(SRCS)",
    outs = ["foo.out"],
    srcs = ["foo.in"],
    tools = [
        "//other:foo.tool",
        "//other:other.tool",
    ],
)`,
			},
			fs: otherGenruleBp,
		},
		{
			description:                        "genrule using $(locations) label should substitute first tool label automatically",
			moduleTypeUnderTest:                "genrule",
			moduleTypeUnderTestFactory:         genrule.GenRuleFactory,
			moduleTypeUnderTestBp2BuildMutator: genrule.GenruleBp2Build,
			depsMutators:                       []android.RegisterMutatorFunc{genrule.RegisterGenruleBp2BuildDeps},
			bp: `genrule {
    name: "foo",
    out: ["foo.out"],
    srcs: ["foo.in"],
    tools: [":foo.tool", ":other.tool"],
    cmd: "$(locations) -s $(out) $(in)",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`genrule(
    name = "foo",
    cmd = "$(locations //other:foo.tool) -s $(OUTS) $(SRCS)",
    outs = ["foo.out"],
    srcs = ["foo.in"],
    tools = [
        "//other:foo.tool",
        "//other:other.tool",
    ],
)`,
			},
			fs: otherGenruleBp,
		},
		{
			description:                        "genrule without tools or tool_files can convert successfully",
			moduleTypeUnderTest:                "genrule",
			moduleTypeUnderTestFactory:         genrule.GenRuleFactory,
			moduleTypeUnderTestBp2BuildMutator: genrule.GenruleBp2Build,
			depsMutators:                       []android.RegisterMutatorFunc{genrule.RegisterGenruleBp2BuildDeps},
			bp: `genrule {
    name: "foo",
    out: ["foo.out"],
    srcs: ["foo.in"],
    cmd: "cp $(in) $(out)",
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`genrule(
    name = "foo",
    cmd = "cp $(SRCS) $(OUTS)",
    outs = ["foo.out"],
    srcs = ["foo.in"],
)`,
			},
		},
	}

	dir := "."
	for _, testCase := range testCases {
		fs := make(map[string][]byte)
		toParse := []string{
			"Android.bp",
		}
		for f, content := range testCase.fs {
			if strings.HasSuffix(f, "Android.bp") {
				toParse = append(toParse, f)
			}
			fs[f] = []byte(content)
		}
		config := android.TestConfig(buildDir, nil, testCase.bp, fs)
		ctx := android.NewTestContext(config)
		ctx.RegisterModuleType(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestFactory)
		for _, m := range testCase.depsMutators {
			ctx.DepsBp2BuildMutators(m)
		}
		ctx.RegisterBp2BuildMutator(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestBp2BuildMutator)
		ctx.RegisterForBazelConversion()

		_, errs := ctx.ParseFileList(dir, toParse)
		if Errored(t, testCase.description, errs) {
			continue
		}
		_, errs = ctx.ResolveDependencies(config)
		if Errored(t, testCase.description, errs) {
			continue
		}

		checkDir := dir
		if testCase.dir != "" {
			checkDir = testCase.dir
		}

		codegenCtx := NewCodegenContext(config, *ctx.Context, Bp2Build)
		bazelTargets := generateBazelTargetsForDir(codegenCtx, checkDir)
		if actualCount, expectedCount := len(bazelTargets), len(testCase.expectedBazelTargets); actualCount != expectedCount {
			t.Errorf("%s: Expected %d bazel target, got %d", testCase.description, expectedCount, actualCount)
		} else {
			for i, target := range bazelTargets {
				if w, g := testCase.expectedBazelTargets[i], target.content; w != g {
					t.Errorf(
						"%s: Expected generated Bazel target to be '%s', got '%s'",
						testCase.description,
						w,
						g,
					)
				}
			}
		}
	}
}

func Errored(t *testing.T, desc string, errs []error) bool {
	t.Helper()
	if len(errs) > 0 {
		for _, err := range errs {
			t.Errorf("%s: %s", desc, err)
		}
		return true
	}
	return false
}

type bp2buildMutator = func(android.TopDownMutatorContext)

func TestBp2BuildInlinesDefaults(t *testing.T) {
	testCases := []struct {
		moduleTypesUnderTest      map[string]android.ModuleFactory
		bp2buildMutatorsUnderTest map[string]bp2buildMutator
		bp                        string
		expectedBazelTarget       string
		description               string
	}{
		{
			moduleTypesUnderTest: map[string]android.ModuleFactory{
				"genrule":          genrule.GenRuleFactory,
				"genrule_defaults": func() android.Module { return genrule.DefaultsFactory() },
			},
			bp2buildMutatorsUnderTest: map[string]bp2buildMutator{
				"genrule": genrule.GenruleBp2Build,
			},
			bp: `genrule_defaults {
    name: "gen_defaults",
    cmd: "do-something $(in) $(out)",
}
genrule {
    name: "gen",
    out: ["out"],
    srcs: ["in1"],
    defaults: ["gen_defaults"],
    bazel_module: { bp2build_available: true },
}
`,
			expectedBazelTarget: `genrule(
    name = "gen",
    cmd = "do-something $(SRCS) $(OUTS)",
    outs = ["out"],
    srcs = ["in1"],
)`,
			description: "genrule applies properties from a genrule_defaults dependency if not specified",
		},
		{
			moduleTypesUnderTest: map[string]android.ModuleFactory{
				"genrule":          genrule.GenRuleFactory,
				"genrule_defaults": func() android.Module { return genrule.DefaultsFactory() },
			},
			bp2buildMutatorsUnderTest: map[string]bp2buildMutator{
				"genrule": genrule.GenruleBp2Build,
			},
			bp: `genrule_defaults {
    name: "gen_defaults",
    out: ["out-from-defaults"],
    srcs: ["in-from-defaults"],
    cmd: "cmd-from-defaults",
}
genrule {
    name: "gen",
    out: ["out"],
    srcs: ["in1"],
    defaults: ["gen_defaults"],
    cmd: "do-something $(in) $(out)",
    bazel_module: { bp2build_available: true },
}
`,
			expectedBazelTarget: `genrule(
    name = "gen",
    cmd = "do-something $(SRCS) $(OUTS)",
    outs = [
        "out-from-defaults",
        "out",
    ],
    srcs = [
        "in-from-defaults",
        "in1",
    ],
)`,
			description: "genrule does merges properties from a genrule_defaults dependency, latest-first",
		},
		{
			moduleTypesUnderTest: map[string]android.ModuleFactory{
				"genrule":          genrule.GenRuleFactory,
				"genrule_defaults": func() android.Module { return genrule.DefaultsFactory() },
			},
			bp2buildMutatorsUnderTest: map[string]bp2buildMutator{
				"genrule": genrule.GenruleBp2Build,
			},
			bp: `genrule_defaults {
    name: "gen_defaults1",
    cmd: "cp $(in) $(out)",
}

genrule_defaults {
    name: "gen_defaults2",
    srcs: ["in1"],
}

genrule {
    name: "gen",
    out: ["out"],
    defaults: ["gen_defaults1", "gen_defaults2"],
    bazel_module: { bp2build_available: true },
}
`,
			expectedBazelTarget: `genrule(
    name = "gen",
    cmd = "cp $(SRCS) $(OUTS)",
    outs = ["out"],
    srcs = ["in1"],
)`,
			description: "genrule applies properties from list of genrule_defaults",
		},
		{
			moduleTypesUnderTest: map[string]android.ModuleFactory{
				"genrule":          genrule.GenRuleFactory,
				"genrule_defaults": func() android.Module { return genrule.DefaultsFactory() },
			},
			bp2buildMutatorsUnderTest: map[string]bp2buildMutator{
				"genrule": genrule.GenruleBp2Build,
			},
			bp: `genrule_defaults {
    name: "gen_defaults1",
    defaults: ["gen_defaults2"],
    cmd: "cmd1 $(in) $(out)", // overrides gen_defaults2's cmd property value.
}

genrule_defaults {
    name: "gen_defaults2",
    defaults: ["gen_defaults3"],
    cmd: "cmd2 $(in) $(out)",
    out: ["out-from-2"],
    srcs: ["in1"],
}

genrule_defaults {
    name: "gen_defaults3",
    out: ["out-from-3"],
    srcs: ["srcs-from-3"],
}

genrule {
    name: "gen",
    out: ["out"],
    defaults: ["gen_defaults1"],
    bazel_module: { bp2build_available: true },
}
`,
			expectedBazelTarget: `genrule(
    name = "gen",
    cmd = "cmd1 $(SRCS) $(OUTS)",
    outs = [
        "out-from-3",
        "out-from-2",
        "out",
    ],
    srcs = [
        "in1",
        "srcs-from-3",
    ],
)`,
			description: "genrule applies properties from genrule_defaults transitively",
		},
	}

	dir := "."
	for _, testCase := range testCases {
		config := android.TestConfig(buildDir, nil, testCase.bp, nil)
		ctx := android.NewTestContext(config)
		for m, factory := range testCase.moduleTypesUnderTest {
			ctx.RegisterModuleType(m, factory)
		}
		for mutator, f := range testCase.bp2buildMutatorsUnderTest {
			ctx.RegisterBp2BuildMutator(mutator, f)
		}
		ctx.RegisterForBazelConversion()

		_, errs := ctx.ParseFileList(dir, []string{"Android.bp"})
		android.FailIfErrored(t, errs)
		_, errs = ctx.ResolveDependencies(config)
		android.FailIfErrored(t, errs)

		codegenCtx := NewCodegenContext(config, *ctx.Context, Bp2Build)
		bazelTargets := generateBazelTargetsForDir(codegenCtx, dir)
		if actualCount := len(bazelTargets); actualCount != 1 {
			t.Fatalf("%s: Expected 1 bazel target, got %d", testCase.description, actualCount)
		}

		actualBazelTarget := bazelTargets[0]
		if actualBazelTarget.content != testCase.expectedBazelTarget {
			t.Errorf(
				"%s: Expected generated Bazel target to be '%s', got '%s'",
				testCase.description,
				testCase.expectedBazelTarget,
				actualBazelTarget.content,
			)
		}
	}
}

func TestAllowlistingBp2buildTargetsExplicitly(t *testing.T) {
	testCases := []struct {
		moduleTypeUnderTest                string
		moduleTypeUnderTestFactory         android.ModuleFactory
		moduleTypeUnderTestBp2BuildMutator bp2buildMutator
		bp                                 string
		expectedCount                      int
		description                        string
	}{
		{
			description:                        "explicitly unavailable",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "foo",
    srcs: ["a", "b"],
    bazel_module: { bp2build_available: false },
}`,
			expectedCount: 0,
		},
		{
			description:                        "implicitly unavailable",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "foo",
    srcs: ["a", "b"],
}`,
			expectedCount: 0,
		},
		{
			description:                        "explicitly available",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "foo",
    srcs: ["a", "b"],
    bazel_module: { bp2build_available: true },
}`,
			expectedCount: 1,
		},
		{
			description:                        "generates more than 1 target if needed",
			moduleTypeUnderTest:                "custom",
			moduleTypeUnderTestFactory:         customModuleFactory,
			moduleTypeUnderTestBp2BuildMutator: customBp2BuildMutatorFromStarlark,
			bp: `custom {
    name: "foo",
    bazel_module: { bp2build_available: true },
}`,
			expectedCount: 3,
		},
	}

	dir := "."
	for _, testCase := range testCases {
		config := android.TestConfig(buildDir, nil, testCase.bp, nil)
		ctx := android.NewTestContext(config)
		ctx.RegisterModuleType(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestFactory)
		ctx.RegisterBp2BuildMutator(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestBp2BuildMutator)
		ctx.RegisterForBazelConversion()

		_, errs := ctx.ParseFileList(dir, []string{"Android.bp"})
		android.FailIfErrored(t, errs)
		_, errs = ctx.ResolveDependencies(config)
		android.FailIfErrored(t, errs)

		codegenCtx := NewCodegenContext(config, *ctx.Context, Bp2Build)
		bazelTargets := generateBazelTargetsForDir(codegenCtx, dir)
		if actualCount := len(bazelTargets); actualCount != testCase.expectedCount {
			t.Fatalf("%s: Expected %d bazel target, got %d", testCase.description, testCase.expectedCount, actualCount)
		}
	}
}

func TestAllowlistingBp2buildTargetsWithConfig(t *testing.T) {
	testCases := []struct {
		moduleTypeUnderTest                string
		moduleTypeUnderTestFactory         android.ModuleFactory
		moduleTypeUnderTestBp2BuildMutator bp2buildMutator
		expectedCount                      map[string]int
		description                        string
		bp2buildConfig                     android.Bp2BuildConfig
		checkDir                           string
		fs                                 map[string]string
	}{
		{
			description:                        "test bp2build config package and subpackages config",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			expectedCount: map[string]int{
				"migrated":                           1,
				"migrated/but_not_really":            0,
				"migrated/but_not_really/but_really": 1,
				"not_migrated":                       0,
				"also_not_migrated":                  0,
			},
			bp2buildConfig: android.Bp2BuildConfig{
				"migrated":                android.Bp2BuildDefaultTrueRecursively,
				"migrated/but_not_really": android.Bp2BuildDefaultFalse,
				"not_migrated":            android.Bp2BuildDefaultFalse,
			},
			fs: map[string]string{
				"migrated/Android.bp":                           `filegroup { name: "a" }`,
				"migrated/but_not_really/Android.bp":            `filegroup { name: "b" }`,
				"migrated/but_not_really/but_really/Android.bp": `filegroup { name: "c" }`,
				"not_migrated/Android.bp":                       `filegroup { name: "d" }`,
				"also_not_migrated/Android.bp":                  `filegroup { name: "e" }`,
			},
		},
		{
			description:                        "test bp2build config opt-in and opt-out",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			expectedCount: map[string]int{
				"package-opt-in":             2,
				"package-opt-in/subpackage":  0,
				"package-opt-out":            1,
				"package-opt-out/subpackage": 0,
			},
			bp2buildConfig: android.Bp2BuildConfig{
				"package-opt-in":  android.Bp2BuildDefaultFalse,
				"package-opt-out": android.Bp2BuildDefaultTrueRecursively,
			},
			fs: map[string]string{
				"package-opt-in/Android.bp": `
filegroup { name: "opt-in-a" }
filegroup { name: "opt-in-b", bazel_module: { bp2build_available: true } }
filegroup { name: "opt-in-c", bazel_module: { bp2build_available: true } }
`,

				"package-opt-in/subpackage/Android.bp": `
filegroup { name: "opt-in-d" } // parent package not configured to DefaultTrueRecursively
`,

				"package-opt-out/Android.bp": `
filegroup { name: "opt-out-a" }
filegroup { name: "opt-out-b", bazel_module: { bp2build_available: false } }
filegroup { name: "opt-out-c", bazel_module: { bp2build_available: false } }
`,

				"package-opt-out/subpackage/Android.bp": `
filegroup { name: "opt-out-g", bazel_module: { bp2build_available: false } }
filegroup { name: "opt-out-h", bazel_module: { bp2build_available: false } }
`,
			},
		},
	}

	dir := "."
	for _, testCase := range testCases {
		fs := make(map[string][]byte)
		toParse := []string{
			"Android.bp",
		}
		for f, content := range testCase.fs {
			if strings.HasSuffix(f, "Android.bp") {
				toParse = append(toParse, f)
			}
			fs[f] = []byte(content)
		}
		config := android.TestConfig(buildDir, nil, "", fs)
		ctx := android.NewTestContext(config)
		ctx.RegisterModuleType(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestFactory)
		ctx.RegisterBp2BuildMutator(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestBp2BuildMutator)
		ctx.RegisterBp2BuildConfig(testCase.bp2buildConfig)
		ctx.RegisterForBazelConversion()

		_, errs := ctx.ParseFileList(dir, toParse)
		android.FailIfErrored(t, errs)
		_, errs = ctx.ResolveDependencies(config)
		android.FailIfErrored(t, errs)

		codegenCtx := NewCodegenContext(config, *ctx.Context, Bp2Build)

		// For each directory, test that the expected number of generated targets is correct.
		for dir, expectedCount := range testCase.expectedCount {
			bazelTargets := generateBazelTargetsForDir(codegenCtx, dir)
			if actualCount := len(bazelTargets); actualCount != expectedCount {
				t.Fatalf(
					"%s: Expected %d bazel target for %s package, got %d",
					testCase.description,
					expectedCount,
					dir,
					actualCount)
			}

		}
	}
}

func TestCombineBuildFilesBp2buildTargets(t *testing.T) {
	testCases := []struct {
		description                        string
		moduleTypeUnderTest                string
		moduleTypeUnderTestFactory         android.ModuleFactory
		moduleTypeUnderTestBp2BuildMutator func(android.TopDownMutatorContext)
		preArchMutators                    []android.RegisterMutatorFunc
		depsMutators                       []android.RegisterMutatorFunc
		bp                                 string
		expectedBazelTargets               []string
		fs                                 map[string]string
		dir                                string
	}{
		{
			description:                        "filegroup bazel_module.label",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    bazel_module: { label: "//other:fg_foo" },
}`,
			expectedBazelTargets: []string{
				`// BUILD file`,
			},
			fs: map[string]string{
				"other/BUILD.bazel": `// BUILD file`,
			},
		},
		{
			description:                        "multiple bazel_module.label same BUILD",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    bazel_module: { label: "//other:fg_foo" },
}

filegroup {
    name: "foo",
    bazel_module: { label: "//other:foo" },
}`,
			expectedBazelTargets: []string{
				`// BUILD file`,
			},
			fs: map[string]string{
				"other/BUILD.bazel": `// BUILD file`,
			},
		},
		{
			description:                        "filegroup bazel_module.label and bp2build",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    bazel_module: {
      label: "//other:fg_foo",
      bp2build_available: true,
    },
}`,
			expectedBazelTargets: []string{
				`filegroup(
    name = "fg_foo",
)`,
				`// BUILD file`,
			},
			fs: map[string]string{
				"other/BUILD.bazel": `// BUILD file`,
			},
		},
		{
			description:                        "filegroup bazel_module.label and filegroup bp2build",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    bazel_module: {
      label: "//other:fg_foo",
    },
}

filegroup {
    name: "fg_bar",
    bazel_module: {
      bp2build_available: true,
    },
}`,
			expectedBazelTargets: []string{
				`filegroup(
    name = "fg_bar",
)`,
				`// BUILD file`,
			},
			fs: map[string]string{
				"other/BUILD.bazel": `// BUILD file`,
			},
		},
	}

	dir := "."
	for _, testCase := range testCases {
		fs := make(map[string][]byte)
		toParse := []string{
			"Android.bp",
		}
		for f, content := range testCase.fs {
			if strings.HasSuffix(f, "Android.bp") {
				toParse = append(toParse, f)
			}
			fs[f] = []byte(content)
		}
		config := android.TestConfig(buildDir, nil, testCase.bp, fs)
		ctx := android.NewTestContext(config)
		ctx.RegisterModuleType(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestFactory)
		for _, m := range testCase.depsMutators {
			ctx.DepsBp2BuildMutators(m)
		}
		ctx.RegisterBp2BuildMutator(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestBp2BuildMutator)
		ctx.RegisterForBazelConversion()

		_, errs := ctx.ParseFileList(dir, toParse)
		if Errored(t, testCase.description, errs) {
			continue
		}
		_, errs = ctx.ResolveDependencies(config)
		if Errored(t, testCase.description, errs) {
			continue
		}

		checkDir := dir
		if testCase.dir != "" {
			checkDir = testCase.dir
		}
		bazelTargets := generateBazelTargetsForDir(NewCodegenContext(config, *ctx.Context, Bp2Build), checkDir)
		if actualCount, expectedCount := len(bazelTargets), len(testCase.expectedBazelTargets); actualCount != expectedCount {
			t.Errorf("%s: Expected %d bazel target, got %d\n%s", testCase.description, expectedCount, actualCount, bazelTargets)
		} else {
			for i, target := range bazelTargets {
				if w, g := testCase.expectedBazelTargets[i], target.content; w != g {
					t.Errorf(
						"%s: Expected generated Bazel target to be '%s', got '%s'",
						testCase.description,
						w,
						g,
					)
				}
			}
		}
	}
}

func TestGlobExcludeSrcs(t *testing.T) {
	testCases := []struct {
		description                        string
		moduleTypeUnderTest                string
		moduleTypeUnderTestFactory         android.ModuleFactory
		moduleTypeUnderTestBp2BuildMutator func(android.TopDownMutatorContext)
		bp                                 string
		expectedBazelTargets               []string
		fs                                 map[string]string
		dir                                string
	}{
		{
			description:                        "filegroup top level exclude_srcs",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp: `filegroup {
    name: "fg_foo",
    srcs: ["**/*.txt"],
    exclude_srcs: ["c.txt"],
    bazel_module: { bp2build_available: true },
}`,
			expectedBazelTargets: []string{`filegroup(
    name = "fg_foo",
    srcs = [
        "//dir:e.txt",
        "//dir:f.txt",
        "a.txt",
        "b.txt",
    ],
)`,
			},
			fs: map[string]string{
				"a.txt":          "",
				"b.txt":          "",
				"c.txt":          "",
				"dir/Android.bp": "",
				"dir/e.txt":      "",
				"dir/f.txt":      "",
			},
		},
		{
			description:                        "filegroup in subdir exclude_srcs",
			moduleTypeUnderTest:                "filegroup",
			moduleTypeUnderTestFactory:         android.FileGroupFactory,
			moduleTypeUnderTestBp2BuildMutator: android.FilegroupBp2Build,
			bp:                                 "",
			dir:                                "dir",
			fs: map[string]string{
				"dir/Android.bp": `filegroup {
    name: "fg_foo",
    srcs: ["**/*.txt"],
    exclude_srcs: ["b.txt"],
    bazel_module: { bp2build_available: true },
}
`,
				"dir/a.txt":             "",
				"dir/b.txt":             "",
				"dir/subdir/Android.bp": "",
				"dir/subdir/e.txt":      "",
				"dir/subdir/f.txt":      "",
			},
			expectedBazelTargets: []string{`filegroup(
    name = "fg_foo",
    srcs = [
        "//dir/subdir:e.txt",
        "//dir/subdir:f.txt",
        "a.txt",
    ],
)`,
			},
		},
	}

	dir := "."
	for _, testCase := range testCases {
		fs := make(map[string][]byte)
		toParse := []string{
			"Android.bp",
		}
		for f, content := range testCase.fs {
			if strings.HasSuffix(f, "Android.bp") {
				toParse = append(toParse, f)
			}
			fs[f] = []byte(content)
		}
		config := android.TestConfig(buildDir, nil, testCase.bp, fs)
		ctx := android.NewTestContext(config)
		ctx.RegisterModuleType(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestFactory)
		ctx.RegisterBp2BuildMutator(testCase.moduleTypeUnderTest, testCase.moduleTypeUnderTestBp2BuildMutator)
		ctx.RegisterForBazelConversion()

		_, errs := ctx.ParseFileList(dir, toParse)
		if Errored(t, testCase.description, errs) {
			continue
		}
		_, errs = ctx.ResolveDependencies(config)
		if Errored(t, testCase.description, errs) {
			continue
		}

		checkDir := dir
		if testCase.dir != "" {
			checkDir = testCase.dir
		}
		bazelTargets := generateBazelTargetsForDir(NewCodegenContext(config, *ctx.Context, Bp2Build), checkDir)
		if actualCount, expectedCount := len(bazelTargets), len(testCase.expectedBazelTargets); actualCount != expectedCount {
			t.Errorf("%s: Expected %d bazel target, got %d\n%s", testCase.description, expectedCount, actualCount, bazelTargets)
		} else {
			for i, target := range bazelTargets {
				if w, g := testCase.expectedBazelTargets[i], target.content; w != g {
					t.Errorf(
						"%s: Expected generated Bazel target to be '%s', got '%s'",
						testCase.description,
						w,
						g,
					)
				}
			}
		}
	}
}
