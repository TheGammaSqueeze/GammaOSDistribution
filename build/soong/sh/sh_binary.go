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

package sh

import (
	"fmt"
	"path/filepath"
	"sort"
	"strings"

	"github.com/google/blueprint"
	"github.com/google/blueprint/proptools"

	"android/soong/android"
	"android/soong/bazel"
	"android/soong/cc"
	"android/soong/tradefed"
)

// sh_binary is for shell scripts (and batch files) that are installed as
// executable files into .../bin/
//
// Do not use them for prebuilt C/C++/etc files.  Use cc_prebuilt_binary
// instead.

var pctx = android.NewPackageContext("android/soong/sh")

func init() {
	pctx.Import("android/soong/android")

	registerShBuildComponents(android.InitRegistrationContext)

	android.RegisterBp2BuildMutator("sh_binary", ShBinaryBp2Build)
}

func registerShBuildComponents(ctx android.RegistrationContext) {
	ctx.RegisterModuleType("sh_binary", ShBinaryFactory)
	ctx.RegisterModuleType("sh_binary_host", ShBinaryHostFactory)
	ctx.RegisterModuleType("sh_test", ShTestFactory)
	ctx.RegisterModuleType("sh_test_host", ShTestHostFactory)
}

// Test fixture preparer that will register most sh build components.
//
// Singletons and mutators should only be added here if they are needed for a majority of sh
// module types, otherwise they should be added under a separate preparer to allow them to be
// selected only when needed to reduce test execution time.
//
// Module types do not have much of an overhead unless they are used so this should include as many
// module types as possible. The exceptions are those module types that require mutators and/or
// singletons in order to function in which case they should be kept together in a separate
// preparer.
var PrepareForTestWithShBuildComponents = android.GroupFixturePreparers(
	android.FixtureRegisterWithContext(registerShBuildComponents),
)

type shBinaryProperties struct {
	// Source file of this prebuilt.
	Src *string `android:"path,arch_variant"`

	// optional subdirectory under which this file is installed into
	Sub_dir *string `android:"arch_variant"`

	// optional name for the installed file. If unspecified, name of the module is used as the file name
	Filename *string `android:"arch_variant"`

	// when set to true, and filename property is not set, the name for the installed file
	// is the same as the file name of the source file.
	Filename_from_src *bool `android:"arch_variant"`

	// Whether this module is directly installable to one of the partitions. Default: true.
	Installable *bool

	// install symlinks to the binary
	Symlinks []string `android:"arch_variant"`

	// Make this module available when building for ramdisk.
	// On device without a dedicated recovery partition, the module is only
	// available after switching root into
	// /first_stage_ramdisk. To expose the module before switching root, install
	// the recovery variant instead.
	Ramdisk_available *bool

	// Make this module available when building for vendor ramdisk.
	// On device without a dedicated recovery partition, the module is only
	// available after switching root into
	// /first_stage_ramdisk. To expose the module before switching root, install
	// the recovery variant instead.
	Vendor_ramdisk_available *bool

	// Make this module available when building for recovery.
	Recovery_available *bool
}

type TestProperties struct {
	// list of compatibility suites (for example "cts", "vts") that the module should be
	// installed into.
	Test_suites []string `android:"arch_variant"`

	// the name of the test configuration (for example "AndroidTest.xml") that should be
	// installed with the module.
	Test_config *string `android:"path,arch_variant"`

	// list of files or filegroup modules that provide data that should be installed alongside
	// the test.
	Data []string `android:"path,arch_variant"`

	// Add RootTargetPreparer to auto generated test config. This guarantees the test to run
	// with root permission.
	Require_root *bool

	// the name of the test configuration template (for example "AndroidTestTemplate.xml") that
	// should be installed with the module.
	Test_config_template *string `android:"path,arch_variant"`

	// Flag to indicate whether or not to create test config automatically. If AndroidTest.xml
	// doesn't exist next to the Android.bp, this attribute doesn't need to be set to true
	// explicitly.
	Auto_gen_config *bool

	// list of binary modules that should be installed alongside the test
	Data_bins []string `android:"path,arch_variant"`

	// list of library modules that should be installed alongside the test
	Data_libs []string `android:"path,arch_variant"`

	// list of device binary modules that should be installed alongside the test.
	// Only available for host sh_test modules.
	Data_device_bins []string `android:"path,arch_variant"`

	// list of device library modules that should be installed alongside the test.
	// Only available for host sh_test modules.
	Data_device_libs []string `android:"path,arch_variant"`
}

type ShBinary struct {
	android.ModuleBase
	android.BazelModuleBase

	properties shBinaryProperties

	sourceFilePath android.Path
	outputFilePath android.OutputPath
	installedFile  android.InstallPath
}

var _ android.HostToolProvider = (*ShBinary)(nil)

type ShTest struct {
	ShBinary

	testProperties TestProperties

	installDir android.InstallPath

	data       android.Paths
	testConfig android.Path

	dataModules map[string]android.Path
}

func (s *ShBinary) HostToolPath() android.OptionalPath {
	return android.OptionalPathForPath(s.installedFile)
}

func (s *ShBinary) DepsMutator(ctx android.BottomUpMutatorContext) {
}

func (s *ShBinary) OutputFile() android.OutputPath {
	return s.outputFilePath
}

func (s *ShBinary) SubDir() string {
	return proptools.String(s.properties.Sub_dir)
}

func (s *ShBinary) Installable() bool {
	return s.properties.Installable == nil || proptools.Bool(s.properties.Installable)
}

func (s *ShBinary) Symlinks() []string {
	return s.properties.Symlinks
}

var _ android.ImageInterface = (*ShBinary)(nil)

func (s *ShBinary) ImageMutatorBegin(ctx android.BaseModuleContext) {}

func (s *ShBinary) CoreVariantNeeded(ctx android.BaseModuleContext) bool {
	return !s.ModuleBase.InstallInRecovery() && !s.ModuleBase.InstallInRamdisk()
}

func (s *ShBinary) RamdiskVariantNeeded(ctx android.BaseModuleContext) bool {
	return proptools.Bool(s.properties.Ramdisk_available) || s.ModuleBase.InstallInRamdisk()
}

func (s *ShBinary) VendorRamdiskVariantNeeded(ctx android.BaseModuleContext) bool {
	return proptools.Bool(s.properties.Vendor_ramdisk_available) || s.ModuleBase.InstallInVendorRamdisk()
}

func (s *ShBinary) DebugRamdiskVariantNeeded(ctx android.BaseModuleContext) bool {
	return false
}

func (s *ShBinary) RecoveryVariantNeeded(ctx android.BaseModuleContext) bool {
	return proptools.Bool(s.properties.Recovery_available) || s.ModuleBase.InstallInRecovery()
}

func (s *ShBinary) ExtraImageVariations(ctx android.BaseModuleContext) []string {
	return nil
}

func (s *ShBinary) SetImageVariation(ctx android.BaseModuleContext, variation string, module android.Module) {
}

func (s *ShBinary) generateAndroidBuildActions(ctx android.ModuleContext) {
	if s.properties.Src == nil {
		ctx.PropertyErrorf("src", "missing prebuilt source file")
	}

	s.sourceFilePath = android.PathForModuleSrc(ctx, proptools.String(s.properties.Src))
	filename := proptools.String(s.properties.Filename)
	filenameFromSrc := proptools.Bool(s.properties.Filename_from_src)
	if filename == "" {
		if filenameFromSrc {
			filename = s.sourceFilePath.Base()
		} else {
			filename = ctx.ModuleName()
		}
	} else if filenameFromSrc {
		ctx.PropertyErrorf("filename_from_src", "filename is set. filename_from_src can't be true")
		return
	}
	s.outputFilePath = android.PathForModuleOut(ctx, filename).OutputPath

	// This ensures that outputFilePath has the correct name for others to
	// use, as the source file may have a different name.
	ctx.Build(pctx, android.BuildParams{
		Rule:   android.CpExecutable,
		Output: s.outputFilePath,
		Input:  s.sourceFilePath,
	})
}

func (s *ShBinary) GenerateAndroidBuildActions(ctx android.ModuleContext) {
	s.generateAndroidBuildActions(ctx)
	installDir := android.PathForModuleInstall(ctx, "bin", proptools.String(s.properties.Sub_dir))
	s.installedFile = ctx.InstallExecutable(installDir, s.outputFilePath.Base(), s.outputFilePath)
}

func (s *ShBinary) AndroidMkEntries() []android.AndroidMkEntries {
	return []android.AndroidMkEntries{android.AndroidMkEntries{
		Class:      "EXECUTABLES",
		OutputFile: android.OptionalPathForPath(s.outputFilePath),
		Include:    "$(BUILD_SYSTEM)/soong_cc_prebuilt.mk",
		ExtraEntries: []android.AndroidMkExtraEntriesFunc{
			func(ctx android.AndroidMkExtraEntriesContext, entries *android.AndroidMkEntries) {
				s.customAndroidMkEntries(entries)
				entries.SetString("LOCAL_MODULE_RELATIVE_PATH", proptools.String(s.properties.Sub_dir))
			},
		},
	}}
}

func (s *ShBinary) customAndroidMkEntries(entries *android.AndroidMkEntries) {
	entries.SetString("LOCAL_MODULE_SUFFIX", "")
	entries.SetString("LOCAL_MODULE_STEM", s.outputFilePath.Rel())
	if len(s.properties.Symlinks) > 0 {
		entries.SetString("LOCAL_MODULE_SYMLINKS", strings.Join(s.properties.Symlinks, " "))
	}
}

type dependencyTag struct {
	blueprint.BaseDependencyTag
	name string
}

var (
	shTestDataBinsTag       = dependencyTag{name: "dataBins"}
	shTestDataLibsTag       = dependencyTag{name: "dataLibs"}
	shTestDataDeviceBinsTag = dependencyTag{name: "dataDeviceBins"}
	shTestDataDeviceLibsTag = dependencyTag{name: "dataDeviceLibs"}
)

var sharedLibVariations = []blueprint.Variation{{Mutator: "link", Variation: "shared"}}

func (s *ShTest) DepsMutator(ctx android.BottomUpMutatorContext) {
	s.ShBinary.DepsMutator(ctx)

	ctx.AddFarVariationDependencies(ctx.Target().Variations(), shTestDataBinsTag, s.testProperties.Data_bins...)
	ctx.AddFarVariationDependencies(append(ctx.Target().Variations(), sharedLibVariations...),
		shTestDataLibsTag, s.testProperties.Data_libs...)
	if (ctx.Target().Os.Class == android.Host || ctx.BazelConversionMode()) && len(ctx.Config().Targets[android.Android]) > 0 {
		deviceVariations := ctx.Config().AndroidFirstDeviceTarget.Variations()
		ctx.AddFarVariationDependencies(deviceVariations, shTestDataDeviceBinsTag, s.testProperties.Data_device_bins...)
		ctx.AddFarVariationDependencies(append(deviceVariations, sharedLibVariations...),
			shTestDataDeviceLibsTag, s.testProperties.Data_device_libs...)
	} else if ctx.Target().Os.Class != android.Host {
		if len(s.testProperties.Data_device_bins) > 0 {
			ctx.PropertyErrorf("data_device_bins", "only available for host modules")
		}
		if len(s.testProperties.Data_device_libs) > 0 {
			ctx.PropertyErrorf("data_device_libs", "only available for host modules")
		}
	}
}

func (s *ShTest) addToDataModules(ctx android.ModuleContext, relPath string, path android.Path) {
	if _, exists := s.dataModules[relPath]; exists {
		ctx.ModuleErrorf("data modules have a conflicting installation path, %v - %s, %s",
			relPath, s.dataModules[relPath].String(), path.String())
		return
	}
	s.dataModules[relPath] = path
}

func (s *ShTest) GenerateAndroidBuildActions(ctx android.ModuleContext) {
	s.ShBinary.generateAndroidBuildActions(ctx)
	testDir := "nativetest"
	if ctx.Target().Arch.ArchType.Multilib == "lib64" {
		testDir = "nativetest64"
	}
	if ctx.Target().NativeBridge == android.NativeBridgeEnabled {
		testDir = filepath.Join(testDir, ctx.Target().NativeBridgeRelativePath)
	} else if !ctx.Host() && ctx.Config().HasMultilibConflict(ctx.Arch().ArchType) {
		testDir = filepath.Join(testDir, ctx.Arch().ArchType.String())
	}
	if s.SubDir() != "" {
		// Don't add the module name to the installation path if sub_dir is specified for backward
		// compatibility.
		s.installDir = android.PathForModuleInstall(ctx, testDir, s.SubDir())
	} else {
		s.installDir = android.PathForModuleInstall(ctx, testDir, s.Name())
	}
	s.installedFile = ctx.InstallExecutable(s.installDir, s.outputFilePath.Base(), s.outputFilePath)

	s.data = android.PathsForModuleSrc(ctx, s.testProperties.Data)

	var configs []tradefed.Config
	if Bool(s.testProperties.Require_root) {
		configs = append(configs, tradefed.Object{"target_preparer", "com.android.tradefed.targetprep.RootTargetPreparer", nil})
	} else {
		options := []tradefed.Option{{Name: "force-root", Value: "false"}}
		configs = append(configs, tradefed.Object{"target_preparer", "com.android.tradefed.targetprep.RootTargetPreparer", options})
	}
	if len(s.testProperties.Data_device_bins) > 0 {
		moduleName := s.Name()
		remoteDir := "/data/local/tests/unrestricted/" + moduleName + "/"
		options := []tradefed.Option{{Name: "cleanup", Value: "true"}}
		for _, bin := range s.testProperties.Data_device_bins {
			options = append(options, tradefed.Option{Name: "push-file", Key: bin, Value: remoteDir + bin})
		}
		configs = append(configs, tradefed.Object{"target_preparer", "com.android.tradefed.targetprep.PushFilePreparer", options})
	}
	s.testConfig = tradefed.AutoGenShellTestConfig(ctx, s.testProperties.Test_config,
		s.testProperties.Test_config_template, s.testProperties.Test_suites, configs, s.testProperties.Auto_gen_config, s.outputFilePath.Base())

	s.dataModules = make(map[string]android.Path)
	ctx.VisitDirectDeps(func(dep android.Module) {
		depTag := ctx.OtherModuleDependencyTag(dep)
		switch depTag {
		case shTestDataBinsTag, shTestDataDeviceBinsTag:
			path := android.OutputFileForModule(ctx, dep, "")
			s.addToDataModules(ctx, path.Base(), path)
		case shTestDataLibsTag, shTestDataDeviceLibsTag:
			if cc, isCc := dep.(*cc.Module); isCc {
				// Copy to an intermediate output directory to append "lib[64]" to the path,
				// so that it's compatible with the default rpath values.
				var relPath string
				if cc.Arch().ArchType.Multilib == "lib64" {
					relPath = filepath.Join("lib64", cc.OutputFile().Path().Base())
				} else {
					relPath = filepath.Join("lib", cc.OutputFile().Path().Base())
				}
				if _, exist := s.dataModules[relPath]; exist {
					return
				}
				relocatedLib := android.PathForModuleOut(ctx, "relocated", relPath)
				ctx.Build(pctx, android.BuildParams{
					Rule:   android.Cp,
					Input:  cc.OutputFile().Path(),
					Output: relocatedLib,
				})
				s.addToDataModules(ctx, relPath, relocatedLib)
				return
			}
			property := "data_libs"
			if depTag == shTestDataDeviceBinsTag {
				property = "data_device_libs"
			}
			ctx.PropertyErrorf(property, "%q of type %q is not supported", dep.Name(), ctx.OtherModuleType(dep))
		}
	})
}

func (s *ShTest) InstallInData() bool {
	return true
}

func (s *ShTest) AndroidMkEntries() []android.AndroidMkEntries {
	return []android.AndroidMkEntries{android.AndroidMkEntries{
		Class:      "NATIVE_TESTS",
		OutputFile: android.OptionalPathForPath(s.outputFilePath),
		Include:    "$(BUILD_SYSTEM)/soong_cc_prebuilt.mk",
		ExtraEntries: []android.AndroidMkExtraEntriesFunc{
			func(ctx android.AndroidMkExtraEntriesContext, entries *android.AndroidMkEntries) {
				s.customAndroidMkEntries(entries)
				entries.SetPath("LOCAL_MODULE_PATH", s.installDir.ToMakePath())
				entries.AddCompatibilityTestSuites(s.testProperties.Test_suites...)
				if s.testConfig != nil {
					entries.SetPath("LOCAL_FULL_TEST_CONFIG", s.testConfig)
				}
				for _, d := range s.data {
					rel := d.Rel()
					path := d.String()
					if !strings.HasSuffix(path, rel) {
						panic(fmt.Errorf("path %q does not end with %q", path, rel))
					}
					path = strings.TrimSuffix(path, rel)
					entries.AddStrings("LOCAL_TEST_DATA", path+":"+rel)
				}
				relPaths := make([]string, 0)
				for relPath, _ := range s.dataModules {
					relPaths = append(relPaths, relPath)
				}
				sort.Strings(relPaths)
				for _, relPath := range relPaths {
					dir := strings.TrimSuffix(s.dataModules[relPath].String(), relPath)
					entries.AddStrings("LOCAL_TEST_DATA", dir+":"+relPath)
				}
			},
		},
	}}
}

func InitShBinaryModule(s *ShBinary) {
	s.AddProperties(&s.properties)
	android.InitBazelModule(s)
}

// sh_binary is for a shell script or batch file to be installed as an
// executable binary to <partition>/bin.
func ShBinaryFactory() android.Module {
	module := &ShBinary{}
	InitShBinaryModule(module)
	android.InitAndroidArchModule(module, android.HostAndDeviceSupported, android.MultilibFirst)
	return module
}

// sh_binary_host is for a shell script to be installed as an executable binary
// to $(HOST_OUT)/bin.
func ShBinaryHostFactory() android.Module {
	module := &ShBinary{}
	InitShBinaryModule(module)
	android.InitAndroidArchModule(module, android.HostSupported, android.MultilibFirst)
	return module
}

// sh_test defines a shell script based test module.
func ShTestFactory() android.Module {
	module := &ShTest{}
	InitShBinaryModule(&module.ShBinary)
	module.AddProperties(&module.testProperties)

	android.InitAndroidArchModule(module, android.HostAndDeviceSupported, android.MultilibFirst)
	return module
}

// sh_test_host defines a shell script based test module that runs on a host.
func ShTestHostFactory() android.Module {
	module := &ShTest{}
	InitShBinaryModule(&module.ShBinary)
	module.AddProperties(&module.testProperties)

	android.InitAndroidArchModule(module, android.HostSupported, android.MultilibFirst)
	return module
}

type bazelShBinaryAttributes struct {
	Srcs bazel.LabelListAttribute
	// Bazel also supports the attributes below, but (so far) these are not required for Bionic
	// deps
	// data
	// args
	// compatible_with
	// deprecation
	// distribs
	// env
	// exec_compatible_with
	// exec_properties
	// features
	// licenses
	// output_licenses
	// restricted_to
	// tags
	// target_compatible_with
	// testonly
	// toolchains
	// visibility
}

type bazelShBinary struct {
	android.BazelTargetModuleBase
	bazelShBinaryAttributes
}

func BazelShBinaryFactory() android.Module {
	module := &bazelShBinary{}
	module.AddProperties(&module.bazelShBinaryAttributes)
	android.InitBazelTargetModule(module)
	return module
}

func ShBinaryBp2Build(ctx android.TopDownMutatorContext) {
	m, ok := ctx.Module().(*ShBinary)
	if !ok || !m.ConvertWithBp2build(ctx) {
		return
	}

	srcs := bazel.MakeLabelListAttribute(
		android.BazelLabelForModuleSrc(ctx, []string{*m.properties.Src}))

	attrs := &bazelShBinaryAttributes{
		Srcs: srcs,
	}

	props := bazel.BazelTargetModuleProperties{
		Rule_class: "sh_binary",
	}

	ctx.CreateBazelTargetModule(BazelShBinaryFactory, m.Name(), props, attrs)
}

func (m *bazelShBinary) Name() string {
	return m.BaseModuleName()
}

func (m *bazelShBinary) GenerateAndroidBuildActions(ctx android.ModuleContext) {}

var Bool = proptools.Bool
