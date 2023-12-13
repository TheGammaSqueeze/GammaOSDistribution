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

package android

func init() {
	RegisterSingletonType("testsuites", testSuiteFilesFactory)
}

func testSuiteFilesFactory() Singleton {
	return &testSuiteFiles{}
}

type testSuiteFiles struct {
	robolectric WritablePath
}

type TestSuiteModule interface {
	Module
	TestSuites() []string
}

func (t *testSuiteFiles) GenerateBuildActions(ctx SingletonContext) {
	files := make(map[string]map[string]InstallPaths)

	ctx.VisitAllModules(func(m Module) {
		if tsm, ok := m.(TestSuiteModule); ok {
			for _, testSuite := range tsm.TestSuites() {
				if files[testSuite] == nil {
					files[testSuite] = make(map[string]InstallPaths)
				}
				name := ctx.ModuleName(m)
				files[testSuite][name] = append(files[testSuite][name], tsm.FilesToInstall()...)
			}
		}
	})

	t.robolectric = robolectricTestSuite(ctx, files["robolectric-tests"])

	ctx.Phony("robolectric-tests", t.robolectric)
}

func (t *testSuiteFiles) MakeVars(ctx MakeVarsContext) {
	ctx.DistForGoal("robolectric-tests", t.robolectric)
}

func robolectricTestSuite(ctx SingletonContext, files map[string]InstallPaths) WritablePath {
	var installedPaths InstallPaths
	for _, module := range SortedStringKeys(files) {
		installedPaths = append(installedPaths, files[module]...)
	}
	testCasesDir := pathForInstall(ctx, BuildOs, X86, "testcases", false).ToMakePath()

	outputFile := PathForOutput(ctx, "packaging", "robolectric-tests.zip")
	rule := NewRuleBuilder(pctx, ctx)
	rule.Command().BuiltTool("soong_zip").
		FlagWithOutput("-o ", outputFile).
		FlagWithArg("-P ", "host/testcases").
		FlagWithArg("-C ", testCasesDir.String()).
		FlagWithRspFileInputList("-r ", outputFile.ReplaceExtension(ctx, "rsp"), installedPaths.Paths())
	rule.Build("robolectric_tests_zip", "robolectric-tests.zip")

	return outputFile
}
