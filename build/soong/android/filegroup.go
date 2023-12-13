// Copyright 2016 Google Inc. All rights reserved.
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

import (
	"android/soong/bazel"
	"strings"
)

func init() {
	RegisterModuleType("filegroup", FileGroupFactory)
	RegisterBp2BuildMutator("filegroup", FilegroupBp2Build)
}

var PrepareForTestWithFilegroup = FixtureRegisterWithContext(func(ctx RegistrationContext) {
	ctx.RegisterModuleType("filegroup", FileGroupFactory)
})

// https://docs.bazel.build/versions/master/be/general.html#filegroup
type bazelFilegroupAttributes struct {
	Srcs bazel.LabelListAttribute
}

type bazelFilegroup struct {
	BazelTargetModuleBase
	bazelFilegroupAttributes
}

func BazelFileGroupFactory() Module {
	module := &bazelFilegroup{}
	module.AddProperties(&module.bazelFilegroupAttributes)
	InitBazelTargetModule(module)
	return module
}

func (bfg *bazelFilegroup) Name() string {
	return bfg.BaseModuleName()
}

func (bfg *bazelFilegroup) GenerateAndroidBuildActions(ctx ModuleContext) {}

func FilegroupBp2Build(ctx TopDownMutatorContext) {
	fg, ok := ctx.Module().(*fileGroup)
	if !ok || !fg.ConvertWithBp2build(ctx) {
		return
	}

	srcs := bazel.MakeLabelListAttribute(
		BazelLabelForModuleSrcExcludes(ctx, fg.properties.Srcs, fg.properties.Exclude_srcs))
	attrs := &bazelFilegroupAttributes{
		Srcs: srcs,
	}

	props := bazel.BazelTargetModuleProperties{Rule_class: "filegroup"}

	ctx.CreateBazelTargetModule(BazelFileGroupFactory, fg.Name(), props, attrs)
}

type fileGroupProperties struct {
	// srcs lists files that will be included in this filegroup
	Srcs []string `android:"path"`

	Exclude_srcs []string `android:"path"`

	// The base path to the files.  May be used by other modules to determine which portion
	// of the path to use.  For example, when a filegroup is used as data in a cc_test rule,
	// the base path is stripped off the path and the remaining path is used as the
	// installation directory.
	Path *string

	// Create a make variable with the specified name that contains the list of files in the
	// filegroup, relative to the root of the source tree.
	Export_to_make_var *string
}

type fileGroup struct {
	ModuleBase
	BazelModuleBase
	properties fileGroupProperties
	srcs       Paths
}

var _ SourceFileProducer = (*fileGroup)(nil)

// filegroup contains a list of files that are referenced by other modules
// properties (such as "srcs") using the syntax ":<name>". filegroup are
// also be used to export files across package boundaries.
func FileGroupFactory() Module {
	module := &fileGroup{}
	module.AddProperties(&module.properties)
	InitAndroidModule(module)
	InitBazelModule(module)
	return module
}

func (fg *fileGroup) generateBazelBuildActions(ctx ModuleContext) bool {
	if !fg.MixedBuildsEnabled(ctx) {
		return false
	}

	bazelCtx := ctx.Config().BazelContext
	filePaths, ok := bazelCtx.GetOutputFiles(fg.GetBazelLabel(ctx, fg), ctx.Arch().ArchType)
	if !ok {
		return false
	}

	bazelOuts := make(Paths, 0, len(filePaths))
	for _, p := range filePaths {
		src := PathForBazelOut(ctx, p)
		bazelOuts = append(bazelOuts, src)
	}

	fg.srcs = bazelOuts

	return true
}

func (fg *fileGroup) GenerateAndroidBuildActions(ctx ModuleContext) {
	if fg.generateBazelBuildActions(ctx) {
		return
	}

	fg.srcs = PathsForModuleSrcExcludes(ctx, fg.properties.Srcs, fg.properties.Exclude_srcs)
	if fg.properties.Path != nil {
		fg.srcs = PathsWithModuleSrcSubDir(ctx, fg.srcs, String(fg.properties.Path))
	}
}

func (fg *fileGroup) Srcs() Paths {
	return append(Paths{}, fg.srcs...)
}

func (fg *fileGroup) MakeVars(ctx MakeVarsModuleContext) {
	if makeVar := String(fg.properties.Export_to_make_var); makeVar != "" {
		ctx.StrictRaw(makeVar, strings.Join(fg.srcs.Strings(), " "))
	}
}
