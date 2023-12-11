// Copyright 2015 Google Inc. All rights reserved.
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

// This file offers AndroidMkEntriesProvider, which individual modules implement to output
// Android.mk entries that contain information about the modules built through Soong. Kati reads
// and combines them with the legacy Make-based module definitions to produce the complete view of
// the source tree, which makes this a critical point of Make-Soong interoperability.
//
// Naturally, Soong-only builds do not rely on this mechanism.

package android

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"path/filepath"
	"reflect"
	"sort"
	"strings"

	"github.com/google/blueprint"
	"github.com/google/blueprint/bootstrap"
)

func init() {
	RegisterAndroidMkBuildComponents(InitRegistrationContext)
}

func RegisterAndroidMkBuildComponents(ctx RegistrationContext) {
	ctx.RegisterSingletonType("androidmk", AndroidMkSingleton)
}

// Enable androidmk support.
// * Register the singleton
// * Configure that we are inside make
var PrepareForTestWithAndroidMk = GroupFixturePreparers(
	FixtureRegisterWithContext(RegisterAndroidMkBuildComponents),
	FixtureModifyConfig(SetKatiEnabledForTests),
)

// Deprecated: Use AndroidMkEntriesProvider instead, especially if you're not going to use the
// Custom function. It's easier to use and test.
type AndroidMkDataProvider interface {
	AndroidMk() AndroidMkData
	BaseModuleName() string
}

type AndroidMkData struct {
	Class           string
	SubName         string
	DistFiles       TaggedDistFiles
	OutputFile      OptionalPath
	Disabled        bool
	Include         string
	Required        []string
	Host_required   []string
	Target_required []string

	Custom func(w io.Writer, name, prefix, moduleDir string, data AndroidMkData)

	Extra []AndroidMkExtraFunc

	Entries AndroidMkEntries
}

type AndroidMkExtraFunc func(w io.Writer, outputFile Path)

// Interface for modules to declare their Android.mk outputs. Note that every module needs to
// implement this in order to be included in the final Android-<product_name>.mk output, even if
// they only need to output the common set of entries without any customizations.
type AndroidMkEntriesProvider interface {
	// Returns AndroidMkEntries objects that contain all basic info plus extra customization data
	// if needed. This is the core func to implement.
	// Note that one can return multiple objects. For example, java_library may return an additional
	// AndroidMkEntries object for its hostdex sub-module.
	AndroidMkEntries() []AndroidMkEntries
	// Modules don't need to implement this as it's already implemented by ModuleBase.
	// AndroidMkEntries uses BaseModuleName() instead of ModuleName() because certain modules
	// e.g. Prebuilts, override the Name() func and return modified names.
	// If a different name is preferred, use SubName or OverrideName in AndroidMkEntries.
	BaseModuleName() string
}

// The core data struct that modules use to provide their Android.mk data.
type AndroidMkEntries struct {
	// Android.mk class string, e.g EXECUTABLES, JAVA_LIBRARIES, ETC
	Class string
	// Optional suffix to append to the module name. Useful when a module wants to return multiple
	// AndroidMkEntries objects. For example, when a java_library returns an additional entry for
	// its hostdex sub-module, this SubName field is set to "-hostdex" so that it can have a
	// different name than the parent's.
	SubName string
	// If set, this value overrides the base module name. SubName is still appended.
	OverrideName string
	// Dist files to output
	DistFiles TaggedDistFiles
	// The output file for Kati to process and/or install. If absent, the module is skipped.
	OutputFile OptionalPath
	// If true, the module is skipped and does not appear on the final Android-<product name>.mk
	// file. Useful when a module needs to be skipped conditionally.
	Disabled bool
	// The postprocessing mk file to include, e.g. $(BUILD_SYSTEM)/soong_cc_prebuilt.mk
	// If not set, $(BUILD_SYSTEM)/prebuilt.mk is used.
	Include string
	// Required modules that need to be built and included in the final build output when building
	// this module.
	Required []string
	// Required host modules that need to be built and included in the final build output when
	// building this module.
	Host_required []string
	// Required device modules that need to be built and included in the final build output when
	// building this module.
	Target_required []string

	header bytes.Buffer
	footer bytes.Buffer

	// Funcs to append additional Android.mk entries or modify the common ones. Multiple funcs are
	// accepted so that common logic can be factored out as a shared func.
	ExtraEntries []AndroidMkExtraEntriesFunc
	// Funcs to add extra lines to the module's Android.mk output. Unlike AndroidMkExtraEntriesFunc,
	// which simply sets Make variable values, this can be used for anything since it can write any
	// Make statements directly to the final Android-*.mk file.
	// Primarily used to call macros or declare/update Make targets.
	ExtraFooters []AndroidMkExtraFootersFunc

	// A map that holds the up-to-date Make variable values. Can be accessed from tests.
	EntryMap map[string][]string
	// A list of EntryMap keys in insertion order. This serves a few purposes:
	// 1. Prevents churns. Golang map doesn't provide consistent iteration order, so without this,
	// the outputted Android-*.mk file may change even though there have been no content changes.
	// 2. Allows modules to refer to other variables, like LOCAL_BAR_VAR := $(LOCAL_FOO_VAR),
	// without worrying about the variables being mixed up in the actual mk file.
	// 3. Makes troubleshooting and spotting errors easier.
	entryOrder []string
}

type AndroidMkExtraEntriesContext interface {
	Provider(provider blueprint.ProviderKey) interface{}
}

type androidMkExtraEntriesContext struct {
	ctx fillInEntriesContext
	mod blueprint.Module
}

func (a *androidMkExtraEntriesContext) Provider(provider blueprint.ProviderKey) interface{} {
	return a.ctx.ModuleProvider(a.mod, provider)
}

type AndroidMkExtraEntriesFunc func(ctx AndroidMkExtraEntriesContext, entries *AndroidMkEntries)
type AndroidMkExtraFootersFunc func(w io.Writer, name, prefix, moduleDir string)

// Utility funcs to manipulate Android.mk variable entries.

// SetString sets a Make variable with the given name to the given value.
func (a *AndroidMkEntries) SetString(name, value string) {
	if _, ok := a.EntryMap[name]; !ok {
		a.entryOrder = append(a.entryOrder, name)
	}
	a.EntryMap[name] = []string{value}
}

// SetPath sets a Make variable with the given name to the given path string.
func (a *AndroidMkEntries) SetPath(name string, path Path) {
	if _, ok := a.EntryMap[name]; !ok {
		a.entryOrder = append(a.entryOrder, name)
	}
	a.EntryMap[name] = []string{path.String()}
}

// SetOptionalPath sets a Make variable with the given name to the given path string if it is valid.
// It is a no-op if the given path is invalid.
func (a *AndroidMkEntries) SetOptionalPath(name string, path OptionalPath) {
	if path.Valid() {
		a.SetPath(name, path.Path())
	}
}

// AddPath appends the given path string to a Make variable with the given name.
func (a *AndroidMkEntries) AddPath(name string, path Path) {
	if _, ok := a.EntryMap[name]; !ok {
		a.entryOrder = append(a.entryOrder, name)
	}
	a.EntryMap[name] = append(a.EntryMap[name], path.String())
}

// AddOptionalPath appends the given path string to a Make variable with the given name if it is
// valid. It is a no-op if the given path is invalid.
func (a *AndroidMkEntries) AddOptionalPath(name string, path OptionalPath) {
	if path.Valid() {
		a.AddPath(name, path.Path())
	}
}

// SetPaths sets a Make variable with the given name to a slice of the given path strings.
func (a *AndroidMkEntries) SetPaths(name string, paths Paths) {
	if _, ok := a.EntryMap[name]; !ok {
		a.entryOrder = append(a.entryOrder, name)
	}
	a.EntryMap[name] = paths.Strings()
}

// SetOptionalPaths sets a Make variable with the given name to a slice of the given path strings
// only if there are a non-zero amount of paths.
func (a *AndroidMkEntries) SetOptionalPaths(name string, paths Paths) {
	if len(paths) > 0 {
		a.SetPaths(name, paths)
	}
}

// AddPaths appends the given path strings to a Make variable with the given name.
func (a *AndroidMkEntries) AddPaths(name string, paths Paths) {
	if _, ok := a.EntryMap[name]; !ok {
		a.entryOrder = append(a.entryOrder, name)
	}
	a.EntryMap[name] = append(a.EntryMap[name], paths.Strings()...)
}

// SetBoolIfTrue sets a Make variable with the given name to true if the given flag is true.
// It is a no-op if the given flag is false.
func (a *AndroidMkEntries) SetBoolIfTrue(name string, flag bool) {
	if flag {
		if _, ok := a.EntryMap[name]; !ok {
			a.entryOrder = append(a.entryOrder, name)
		}
		a.EntryMap[name] = []string{"true"}
	}
}

// SetBool sets a Make variable with the given name to if the given bool flag value.
func (a *AndroidMkEntries) SetBool(name string, flag bool) {
	if _, ok := a.EntryMap[name]; !ok {
		a.entryOrder = append(a.entryOrder, name)
	}
	if flag {
		a.EntryMap[name] = []string{"true"}
	} else {
		a.EntryMap[name] = []string{"false"}
	}
}

// AddStrings appends the given strings to a Make variable with the given name.
func (a *AndroidMkEntries) AddStrings(name string, value ...string) {
	if len(value) == 0 {
		return
	}
	if _, ok := a.EntryMap[name]; !ok {
		a.entryOrder = append(a.entryOrder, name)
	}
	a.EntryMap[name] = append(a.EntryMap[name], value...)
}

// AddCompatibilityTestSuites adds the supplied test suites to the EntryMap, with special handling
// for partial MTS test suites.
func (a *AndroidMkEntries) AddCompatibilityTestSuites(suites ...string) {
	// MTS supports a full test suite and partial per-module MTS test suites, with naming mts-${MODULE}.
	// To reduce repetition, if we find a partial MTS test suite without an full MTS test suite,
	// we add the full test suite to our list.
	if PrefixInList(suites, "mts-") && !InList("mts", suites) {
		suites = append(suites, "mts")
	}
	a.AddStrings("LOCAL_COMPATIBILITY_SUITE", suites...)
}

// The contributions to the dist.
type distContributions struct {
	// List of goals and the dist copy instructions.
	copiesForGoals []*copiesForGoals
}

// getCopiesForGoals returns a copiesForGoals into which copy instructions that
// must be processed when building one or more of those goals can be added.
func (d *distContributions) getCopiesForGoals(goals string) *copiesForGoals {
	copiesForGoals := &copiesForGoals{goals: goals}
	d.copiesForGoals = append(d.copiesForGoals, copiesForGoals)
	return copiesForGoals
}

// Associates a list of dist copy instructions with a set of goals for which they
// should be run.
type copiesForGoals struct {
	// goals are a space separated list of build targets that will trigger the
	// copy instructions.
	goals string

	// A list of instructions to copy a module's output files to somewhere in the
	// dist directory.
	copies []distCopy
}

// Adds a copy instruction.
func (d *copiesForGoals) addCopyInstruction(from Path, dest string) {
	d.copies = append(d.copies, distCopy{from, dest})
}

// Instruction on a path that must be copied into the dist.
type distCopy struct {
	// The path to copy from.
	from Path

	// The destination within the dist directory to copy to.
	dest string
}

// Compute the contributions that the module makes to the dist.
func (a *AndroidMkEntries) getDistContributions(mod blueprint.Module) *distContributions {
	amod := mod.(Module).base()
	name := amod.BaseModuleName()

	// Collate the set of associated tag/paths available for copying to the dist.
	// Start with an empty (nil) set.
	var availableTaggedDists TaggedDistFiles

	// Then merge in any that are provided explicitly by the module.
	if a.DistFiles != nil {
		// Merge the DistFiles into the set.
		availableTaggedDists = availableTaggedDists.merge(a.DistFiles)
	}

	// If no paths have been provided for the DefaultDistTag and the output file is
	// valid then add that as the default dist path.
	if _, ok := availableTaggedDists[DefaultDistTag]; !ok && a.OutputFile.Valid() {
		availableTaggedDists = availableTaggedDists.addPathsForTag(DefaultDistTag, a.OutputFile.Path())
	}

	// If the distFiles created by GenerateTaggedDistFiles contains paths for the
	// DefaultDistTag then that takes priority so delete any existing paths.
	if _, ok := amod.distFiles[DefaultDistTag]; ok {
		delete(availableTaggedDists, DefaultDistTag)
	}

	// Finally, merge the distFiles created by GenerateTaggedDistFiles.
	availableTaggedDists = availableTaggedDists.merge(amod.distFiles)

	if len(availableTaggedDists) == 0 {
		// Nothing dist-able for this module.
		return nil
	}

	// Collate the contributions this module makes to the dist.
	distContributions := &distContributions{}

	// Iterate over this module's dist structs, merged from the dist and dists properties.
	for _, dist := range amod.Dists() {
		// Get the list of goals this dist should be enabled for. e.g. sdk, droidcore
		goals := strings.Join(dist.Targets, " ")

		// Get the tag representing the output files to be dist'd. e.g. ".jar", ".proguard_map"
		var tag string
		if dist.Tag == nil {
			// If the dist struct does not specify a tag, use the default output files tag.
			tag = DefaultDistTag
		} else {
			tag = *dist.Tag
		}

		// Get the paths of the output files to be dist'd, represented by the tag.
		// Can be an empty list.
		tagPaths := availableTaggedDists[tag]
		if len(tagPaths) == 0 {
			// Nothing to dist for this tag, continue to the next dist.
			continue
		}

		if len(tagPaths) > 1 && (dist.Dest != nil || dist.Suffix != nil) {
			errorMessage := "%s: Cannot apply dest/suffix for more than one dist " +
				"file for %q goals tag %q in module %s. The list of dist files, " +
				"which should have a single element, is:\n%s"
			panic(fmt.Errorf(errorMessage, mod, goals, tag, name, tagPaths))
		}

		copiesForGoals := distContributions.getCopiesForGoals(goals)

		// Iterate over each path adding a copy instruction to copiesForGoals
		for _, path := range tagPaths {
			// It's possible that the Path is nil from errant modules. Be defensive here.
			if path == nil {
				tagName := "default" // for error message readability
				if dist.Tag != nil {
					tagName = *dist.Tag
				}
				panic(fmt.Errorf("Dist file should not be nil for the %s tag in %s", tagName, name))
			}

			dest := filepath.Base(path.String())

			if dist.Dest != nil {
				var err error
				if dest, err = validateSafePath(*dist.Dest); err != nil {
					// This was checked in ModuleBase.GenerateBuildActions
					panic(err)
				}
			}

			if dist.Suffix != nil {
				ext := filepath.Ext(dest)
				suffix := *dist.Suffix
				dest = strings.TrimSuffix(dest, ext) + suffix + ext
			}

			if dist.Dir != nil {
				var err error
				if dest, err = validateSafePath(*dist.Dir, dest); err != nil {
					// This was checked in ModuleBase.GenerateBuildActions
					panic(err)
				}
			}

			copiesForGoals.addCopyInstruction(path, dest)
		}
	}

	return distContributions
}

// generateDistContributionsForMake generates make rules that will generate the
// dist according to the instructions in the supplied distContribution.
func generateDistContributionsForMake(distContributions *distContributions) []string {
	var ret []string
	for _, d := range distContributions.copiesForGoals {
		ret = append(ret, fmt.Sprintf(".PHONY: %s\n", d.goals))
		// Create dist-for-goals calls for each of the copy instructions.
		for _, c := range d.copies {
			ret = append(
				ret,
				fmt.Sprintf("$(call dist-for-goals,%s,%s:%s)\n", d.goals, c.from.String(), c.dest))
		}
	}

	return ret
}

// Compute the list of Make strings to declare phony goals and dist-for-goals
// calls from the module's dist and dists properties.
func (a *AndroidMkEntries) GetDistForGoals(mod blueprint.Module) []string {
	distContributions := a.getDistContributions(mod)
	if distContributions == nil {
		return nil
	}

	return generateDistContributionsForMake(distContributions)
}

// Write the license variables to Make for AndroidMkData.Custom(..) methods that do not call WriteAndroidMkData(..)
// It's required to propagate the license metadata even for module types that have non-standard interfaces to Make.
func (a *AndroidMkEntries) WriteLicenseVariables(w io.Writer) {
	fmt.Fprintln(w, "LOCAL_LICENSE_KINDS :=", strings.Join(a.EntryMap["LOCAL_LICENSE_KINDS"], " "))
	fmt.Fprintln(w, "LOCAL_LICENSE_CONDITIONS :=", strings.Join(a.EntryMap["LOCAL_LICENSE_CONDITIONS"], " "))
	fmt.Fprintln(w, "LOCAL_NOTICE_FILE :=", strings.Join(a.EntryMap["LOCAL_NOTICE_FILE"], " "))
	if pn, ok := a.EntryMap["LOCAL_LICENSE_PACKAGE_NAME"]; ok {
		fmt.Fprintln(w, "LOCAL_LICENSE_PACKAGE_NAME :=", strings.Join(pn, " "))
	}
}

// fillInEntries goes through the common variable processing and calls the extra data funcs to
// generate and fill in AndroidMkEntries's in-struct data, ready to be flushed to a file.
type fillInEntriesContext interface {
	ModuleDir(module blueprint.Module) string
	Config() Config
	ModuleProvider(module blueprint.Module, provider blueprint.ProviderKey) interface{}
}

func (a *AndroidMkEntries) fillInEntries(ctx fillInEntriesContext, mod blueprint.Module) {
	a.EntryMap = make(map[string][]string)
	amod := mod.(Module).base()
	name := amod.BaseModuleName()
	if a.OverrideName != "" {
		name = a.OverrideName
	}

	if a.Include == "" {
		a.Include = "$(BUILD_PREBUILT)"
	}
	a.Required = append(a.Required, amod.commonProperties.Required...)
	a.Host_required = append(a.Host_required, amod.commonProperties.Host_required...)
	a.Target_required = append(a.Target_required, amod.commonProperties.Target_required...)

	for _, distString := range a.GetDistForGoals(mod) {
		fmt.Fprintf(&a.header, distString)
	}

	fmt.Fprintln(&a.header, "\ninclude $(CLEAR_VARS)")

	// Collect make variable assignment entries.
	a.SetString("LOCAL_PATH", ctx.ModuleDir(mod))
	a.SetString("LOCAL_MODULE", name+a.SubName)
	a.AddStrings("LOCAL_LICENSE_KINDS", amod.commonProperties.Effective_license_kinds...)
	a.AddStrings("LOCAL_LICENSE_CONDITIONS", amod.commonProperties.Effective_license_conditions...)
	a.AddStrings("LOCAL_NOTICE_FILE", amod.commonProperties.Effective_license_text.Strings()...)
	// TODO(b/151177513): Does this code need to set LOCAL_MODULE_IS_CONTAINER ?
	if amod.commonProperties.Effective_package_name != nil {
		a.SetString("LOCAL_LICENSE_PACKAGE_NAME", *amod.commonProperties.Effective_package_name)
	} else if len(amod.commonProperties.Effective_licenses) > 0 {
		a.SetString("LOCAL_LICENSE_PACKAGE_NAME", strings.Join(amod.commonProperties.Effective_licenses, " "))
	}
	a.SetString("LOCAL_MODULE_CLASS", a.Class)
	a.SetString("LOCAL_PREBUILT_MODULE_FILE", a.OutputFile.String())
	a.AddStrings("LOCAL_REQUIRED_MODULES", a.Required...)
	a.AddStrings("LOCAL_HOST_REQUIRED_MODULES", a.Host_required...)
	a.AddStrings("LOCAL_TARGET_REQUIRED_MODULES", a.Target_required...)

	if am, ok := mod.(ApexModule); ok {
		a.SetBoolIfTrue("LOCAL_NOT_AVAILABLE_FOR_PLATFORM", am.NotAvailableForPlatform())
	}

	archStr := amod.Arch().ArchType.String()
	host := false
	switch amod.Os().Class {
	case Host:
		if amod.Target().HostCross {
			// Make cannot identify LOCAL_MODULE_HOST_CROSS_ARCH:= common.
			if amod.Arch().ArchType != Common {
				a.SetString("LOCAL_MODULE_HOST_CROSS_ARCH", archStr)
			}
		} else {
			// Make cannot identify LOCAL_MODULE_HOST_ARCH:= common.
			if amod.Arch().ArchType != Common {
				a.SetString("LOCAL_MODULE_HOST_ARCH", archStr)
			}
		}
		host = true
	case Device:
		// Make cannot identify LOCAL_MODULE_TARGET_ARCH:= common.
		if amod.Arch().ArchType != Common {
			if amod.Target().NativeBridge {
				hostArchStr := amod.Target().NativeBridgeHostArchName
				if hostArchStr != "" {
					a.SetString("LOCAL_MODULE_TARGET_ARCH", hostArchStr)
				}
			} else {
				a.SetString("LOCAL_MODULE_TARGET_ARCH", archStr)
			}
		}

		if !amod.InRamdisk() && !amod.InVendorRamdisk() {
			a.AddPaths("LOCAL_FULL_INIT_RC", amod.initRcPaths)
		}
		if len(amod.vintfFragmentsPaths) > 0 {
			a.AddPaths("LOCAL_FULL_VINTF_FRAGMENTS", amod.vintfFragmentsPaths)
		}
		a.SetBoolIfTrue("LOCAL_PROPRIETARY_MODULE", Bool(amod.commonProperties.Proprietary))
		if Bool(amod.commonProperties.Vendor) || Bool(amod.commonProperties.Soc_specific) {
			a.SetString("LOCAL_VENDOR_MODULE", "true")
		}
		a.SetBoolIfTrue("LOCAL_ODM_MODULE", Bool(amod.commonProperties.Device_specific))
		a.SetBoolIfTrue("LOCAL_PRODUCT_MODULE", Bool(amod.commonProperties.Product_specific))
		a.SetBoolIfTrue("LOCAL_SYSTEM_EXT_MODULE", Bool(amod.commonProperties.System_ext_specific))
		if amod.commonProperties.Owner != nil {
			a.SetString("LOCAL_MODULE_OWNER", *amod.commonProperties.Owner)
		}
	}

	if len(amod.noticeFiles) > 0 {
		a.SetString("LOCAL_NOTICE_FILE", strings.Join(amod.noticeFiles.Strings(), " "))
	}

	if host {
		makeOs := amod.Os().String()
		if amod.Os() == Linux || amod.Os() == LinuxBionic {
			makeOs = "linux"
		}
		a.SetString("LOCAL_MODULE_HOST_OS", makeOs)
		a.SetString("LOCAL_IS_HOST_MODULE", "true")
	}

	prefix := ""
	if amod.ArchSpecific() {
		switch amod.Os().Class {
		case Host:
			if amod.Target().HostCross {
				prefix = "HOST_CROSS_"
			} else {
				prefix = "HOST_"
			}
		case Device:
			prefix = "TARGET_"

		}

		if amod.Arch().ArchType != ctx.Config().Targets[amod.Os()][0].Arch.ArchType {
			prefix = "2ND_" + prefix
		}
	}

	extraCtx := &androidMkExtraEntriesContext{
		ctx: ctx,
		mod: mod,
	}

	for _, extra := range a.ExtraEntries {
		extra(extraCtx, a)
	}

	// Write to footer.
	fmt.Fprintln(&a.footer, "include "+a.Include)
	blueprintDir := ctx.ModuleDir(mod)
	for _, footerFunc := range a.ExtraFooters {
		footerFunc(&a.footer, name, prefix, blueprintDir)
	}
}

// write  flushes the AndroidMkEntries's in-struct data populated by AndroidMkEntries into the
// given Writer object.
func (a *AndroidMkEntries) write(w io.Writer) {
	if a.Disabled {
		return
	}

	if !a.OutputFile.Valid() {
		return
	}

	w.Write(a.header.Bytes())
	for _, name := range a.entryOrder {
		fmt.Fprintln(w, name+" := "+strings.Join(a.EntryMap[name], " "))
	}
	w.Write(a.footer.Bytes())
}

func (a *AndroidMkEntries) FooterLinesForTests() []string {
	return strings.Split(string(a.footer.Bytes()), "\n")
}

// AndroidMkSingleton is a singleton to collect Android.mk data from all modules and dump them into
// the final Android-<product_name>.mk file output.
func AndroidMkSingleton() Singleton {
	return &androidMkSingleton{}
}

type androidMkSingleton struct{}

func (c *androidMkSingleton) GenerateBuildActions(ctx SingletonContext) {
	// Skip if Soong wasn't invoked from Make.
	if !ctx.Config().KatiEnabled() {
		return
	}

	var androidMkModulesList []blueprint.Module

	ctx.VisitAllModulesBlueprint(func(module blueprint.Module) {
		androidMkModulesList = append(androidMkModulesList, module)
	})

	// Sort the module list by the module names to eliminate random churns, which may erroneously
	// invoke additional build processes.
	sort.SliceStable(androidMkModulesList, func(i, j int) bool {
		return ctx.ModuleName(androidMkModulesList[i]) < ctx.ModuleName(androidMkModulesList[j])
	})

	transMk := PathForOutput(ctx, "Android"+String(ctx.Config().productVariables.Make_suffix)+".mk")
	if ctx.Failed() {
		return
	}

	err := translateAndroidMk(ctx, absolutePath(transMk.String()), androidMkModulesList)
	if err != nil {
		ctx.Errorf(err.Error())
	}

	ctx.Build(pctx, BuildParams{
		Rule:   blueprint.Phony,
		Output: transMk,
	})
}

func translateAndroidMk(ctx SingletonContext, mkFile string, mods []blueprint.Module) error {
	buf := &bytes.Buffer{}

	fmt.Fprintln(buf, "LOCAL_MODULE_MAKEFILE := $(lastword $(MAKEFILE_LIST))")

	typeStats := make(map[string]int)
	for _, mod := range mods {
		err := translateAndroidMkModule(ctx, buf, mod)
		if err != nil {
			os.Remove(mkFile)
			return err
		}

		if amod, ok := mod.(Module); ok && ctx.PrimaryModule(amod) == amod {
			typeStats[ctx.ModuleType(amod)] += 1
		}
	}

	keys := []string{}
	fmt.Fprintln(buf, "\nSTATS.SOONG_MODULE_TYPE :=")
	for k := range typeStats {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	for _, mod_type := range keys {
		fmt.Fprintln(buf, "STATS.SOONG_MODULE_TYPE +=", mod_type)
		fmt.Fprintf(buf, "STATS.SOONG_MODULE_TYPE.%s := %d\n", mod_type, typeStats[mod_type])
	}

	// Don't write to the file if it hasn't changed
	if _, err := os.Stat(absolutePath(mkFile)); !os.IsNotExist(err) {
		if data, err := ioutil.ReadFile(absolutePath(mkFile)); err == nil {
			matches := buf.Len() == len(data)

			if matches {
				for i, value := range buf.Bytes() {
					if value != data[i] {
						matches = false
						break
					}
				}
			}

			if matches {
				return nil
			}
		}
	}

	return ioutil.WriteFile(absolutePath(mkFile), buf.Bytes(), 0666)
}

func translateAndroidMkModule(ctx SingletonContext, w io.Writer, mod blueprint.Module) error {
	defer func() {
		if r := recover(); r != nil {
			panic(fmt.Errorf("%s in translateAndroidMkModule for module %s variant %s",
				r, ctx.ModuleName(mod), ctx.ModuleSubDir(mod)))
		}
	}()

	// Additional cases here require review for correct license propagation to make.
	switch x := mod.(type) {
	case AndroidMkDataProvider:
		return translateAndroidModule(ctx, w, mod, x)
	case bootstrap.GoBinaryTool:
		return translateGoBinaryModule(ctx, w, mod, x)
	case AndroidMkEntriesProvider:
		return translateAndroidMkEntriesModule(ctx, w, mod, x)
	default:
		// Not exported to make so no make variables to set.
		return nil
	}
}

// A simple, special Android.mk entry output func to make it possible to build blueprint tools using
// m by making them phony targets.
func translateGoBinaryModule(ctx SingletonContext, w io.Writer, mod blueprint.Module,
	goBinary bootstrap.GoBinaryTool) error {

	name := ctx.ModuleName(mod)
	fmt.Fprintln(w, ".PHONY:", name)
	fmt.Fprintln(w, name+":", goBinary.InstallPath())
	fmt.Fprintln(w, "")
	// Assuming no rules in make include go binaries in distributables.
	// If the assumption is wrong, make will fail to build without the necessary .meta_lic and .meta_module files.
	// In that case, add the targets and rules here to build a .meta_lic file for `name` and a .meta_module for
	// `goBinary.InstallPath()` pointing to the `name`.meta_lic file.

	return nil
}

func (data *AndroidMkData) fillInData(ctx fillInEntriesContext, mod blueprint.Module) {
	// Get the preamble content through AndroidMkEntries logic.
	data.Entries = AndroidMkEntries{
		Class:           data.Class,
		SubName:         data.SubName,
		DistFiles:       data.DistFiles,
		OutputFile:      data.OutputFile,
		Disabled:        data.Disabled,
		Include:         data.Include,
		Required:        data.Required,
		Host_required:   data.Host_required,
		Target_required: data.Target_required,
	}
	data.Entries.fillInEntries(ctx, mod)

	// copy entries back to data since it is used in Custom
	data.Required = data.Entries.Required
	data.Host_required = data.Entries.Host_required
	data.Target_required = data.Entries.Target_required
}

// A support func for the deprecated AndroidMkDataProvider interface. Use AndroidMkEntryProvider
// instead.
func translateAndroidModule(ctx SingletonContext, w io.Writer, mod blueprint.Module,
	provider AndroidMkDataProvider) error {

	amod := mod.(Module).base()
	if shouldSkipAndroidMkProcessing(amod) {
		return nil
	}

	data := provider.AndroidMk()
	if data.Include == "" {
		data.Include = "$(BUILD_PREBUILT)"
	}

	data.fillInData(ctx, mod)

	prefix := ""
	if amod.ArchSpecific() {
		switch amod.Os().Class {
		case Host:
			if amod.Target().HostCross {
				prefix = "HOST_CROSS_"
			} else {
				prefix = "HOST_"
			}
		case Device:
			prefix = "TARGET_"

		}

		if amod.Arch().ArchType != ctx.Config().Targets[amod.Os()][0].Arch.ArchType {
			prefix = "2ND_" + prefix
		}
	}

	name := provider.BaseModuleName()
	blueprintDir := filepath.Dir(ctx.BlueprintFile(mod))

	if data.Custom != nil {
		// List of module types allowed to use .Custom(...)
		// Additions to the list require careful review for proper license handling.
		switch reflect.TypeOf(mod).String() { // ctx.ModuleType(mod) doesn't work: aidl_interface creates phony without type
		case "*aidl.aidlApi": // writes non-custom before adding .phony
		case "*aidl.aidlMapping": // writes non-custom before adding .phony
		case "*android.customModule": // appears in tests only
		case "*apex.apexBundle": // license properties written
		case "*bpf.bpf": // license properties written (both for module and objs)
		case "*genrule.Module": // writes non-custom before adding .phony
		case "*java.SystemModules": // doesn't go through base_rules
		case "*java.systemModulesImport": // doesn't go through base_rules
		case "*phony.phony": // license properties written
		case "*selinux.selinuxContextsModule": // license properties written
		case "*sysprop.syspropLibrary": // license properties written
		default:
			if ctx.Config().IsEnvTrue("ANDROID_REQUIRE_LICENSES") {
				return fmt.Errorf("custom make rules not allowed for %q (%q) module %q", ctx.ModuleType(mod), reflect.TypeOf(mod), ctx.ModuleName(mod))
			}
		}
		data.Custom(w, name, prefix, blueprintDir, data)
	} else {
		WriteAndroidMkData(w, data)
	}

	return nil
}

// A support func for the deprecated AndroidMkDataProvider interface. Use AndroidMkEntryProvider
// instead.
func WriteAndroidMkData(w io.Writer, data AndroidMkData) {
	if data.Disabled {
		return
	}

	if !data.OutputFile.Valid() {
		return
	}

	// write preamble via Entries
	data.Entries.footer = bytes.Buffer{}
	data.Entries.write(w)

	for _, extra := range data.Extra {
		extra(w, data.OutputFile.Path())
	}

	fmt.Fprintln(w, "include "+data.Include)
}

func translateAndroidMkEntriesModule(ctx SingletonContext, w io.Writer, mod blueprint.Module,
	provider AndroidMkEntriesProvider) error {
	if shouldSkipAndroidMkProcessing(mod.(Module).base()) {
		return nil
	}

	// Any new or special cases here need review to verify correct propagation of license information.
	for _, entries := range provider.AndroidMkEntries() {
		entries.fillInEntries(ctx, mod)
		entries.write(w)
	}

	return nil
}

func shouldSkipAndroidMkProcessing(module *ModuleBase) bool {
	if !module.commonProperties.NamespaceExportedToMake {
		// TODO(jeffrygaston) do we want to validate that there are no modules being
		// exported to Kati that depend on this module?
		return true
	}

	return !module.Enabled() ||
		module.commonProperties.HideFromMake ||
		// Make does not understand LinuxBionic
		module.Os() == LinuxBionic
}

// A utility func to format LOCAL_TEST_DATA outputs. See the comments on DataPath to understand how
// to use this func.
func AndroidMkDataPaths(data []DataPath) []string {
	var testFiles []string
	for _, d := range data {
		rel := d.SrcPath.Rel()
		path := d.SrcPath.String()
		// LOCAL_TEST_DATA requires the rel portion of the path to be removed from the path.
		if !strings.HasSuffix(path, rel) {
			panic(fmt.Errorf("path %q does not end with %q", path, rel))
		}
		path = strings.TrimSuffix(path, rel)
		testFileString := path + ":" + rel
		if len(d.RelativeInstallPath) > 0 {
			testFileString += ":" + d.RelativeInstallPath
		}
		testFiles = append(testFiles, testFileString)
	}
	return testFiles
}
