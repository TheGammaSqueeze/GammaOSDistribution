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

package java

import (
	"fmt"
	"strings"

	"android/soong/android"
	"github.com/google/blueprint"
)

// Contains support for processing hiddenAPI in a modular fashion.

// HiddenAPIScope encapsulates all the information that the hidden API processing needs about API
// scopes, i.e. what is called android.SdkKind and apiScope. It does not just use those as they do
// not provide the information needed by hidden API processing.
type HiddenAPIScope struct {
	// The name of the scope, used for debug purposes.
	name string

	// The corresponding android.SdkKind, used for retrieving paths from java_sdk_library* modules.
	sdkKind android.SdkKind

	// The option needed to passed to "hiddenapi list".
	hiddenAPIListOption string

	// The name sof the source stub library modules that contain the API provided by the platform,
	// i.e. by modules that are not in an APEX.
	nonUpdatableSourceModule string

	// The names of the prebuilt stub library modules that contain the API provided by the platform,
	// i.e. by modules that are not in an APEX.
	nonUpdatablePrebuiltModule string
}

// initHiddenAPIScope initializes the scope.
func initHiddenAPIScope(apiScope *HiddenAPIScope) *HiddenAPIScope {
	sdkKind := apiScope.sdkKind
	// The platform does not provide a core platform API.
	if sdkKind != android.SdkCorePlatform {
		kindAsString := sdkKind.String()
		var insert string
		if sdkKind == android.SdkPublic {
			insert = ""
		} else {
			insert = "." + strings.ReplaceAll(kindAsString, "-", "_")
		}

		nonUpdatableModule := "android-non-updatable"

		// Construct the name of the android-non-updatable source module for this scope.
		apiScope.nonUpdatableSourceModule = fmt.Sprintf("%s.stubs%s", nonUpdatableModule, insert)

		prebuiltModuleName := func(name string, kind string) string {
			return fmt.Sprintf("sdk_%s_current_%s", kind, name)
		}

		// Construct the name of the android-non-updatable prebuilt module for this scope.
		apiScope.nonUpdatablePrebuiltModule = prebuiltModuleName(nonUpdatableModule, kindAsString)
	}

	return apiScope
}

// android-non-updatable takes the name of a module and returns a possibly scope specific name of
// the module.
func (l *HiddenAPIScope) scopeSpecificStubModule(ctx android.BaseModuleContext, name string) string {
	// The android-non-updatable is not a java_sdk_library but there are separate stub libraries for
	// each scope.
	// TODO(b/192067200): Remove special handling of android-non-updatable.
	if name == "android-non-updatable" {
		if ctx.Config().AlwaysUsePrebuiltSdks() {
			return l.nonUpdatablePrebuiltModule
		} else {
			return l.nonUpdatableSourceModule
		}
	} else {
		// Assume that the module is either a java_sdk_library (or equivalent) and so will provide
		// separate stub jars for each scope or is a java_library (or equivalent) in which case it will
		// have the same stub jar for each scope.
		return name
	}
}

func (l *HiddenAPIScope) String() string {
	return fmt.Sprintf("HiddenAPIScope{%s}", l.name)
}

var (
	PublicHiddenAPIScope = initHiddenAPIScope(&HiddenAPIScope{
		name:                "public",
		sdkKind:             android.SdkPublic,
		hiddenAPIListOption: "--public-stub-classpath",
	})
	SystemHiddenAPIScope = initHiddenAPIScope(&HiddenAPIScope{
		name:                "system",
		sdkKind:             android.SdkSystem,
		hiddenAPIListOption: "--system-stub-classpath",
	})
	TestHiddenAPIScope = initHiddenAPIScope(&HiddenAPIScope{
		name:                "test",
		sdkKind:             android.SdkTest,
		hiddenAPIListOption: "--test-stub-classpath",
	})
	ModuleLibHiddenAPIScope = initHiddenAPIScope(&HiddenAPIScope{
		name:    "module-lib",
		sdkKind: android.SdkModule,
	})
	CorePlatformHiddenAPIScope = initHiddenAPIScope(&HiddenAPIScope{
		name:                "core-platform",
		sdkKind:             android.SdkCorePlatform,
		hiddenAPIListOption: "--core-platform-stub-classpath",
	})

	// hiddenAPIRelevantSdkKinds lists all the android.SdkKind instances that are needed by the hidden
	// API processing.
	//
	// These are roughly in order from narrowest API surface to widest. Widest means the API stubs
	// with the biggest API surface, e.g. test is wider than system is wider than public.
	//
	// Core platform is considered wider than system/module-lib because those modules that provide
	// core platform APIs either do not have any system/module-lib APIs at all, or if they do it is
	// because the core platform API is being converted to system/module-lib APIs. In either case the
	// system/module-lib APIs are subsets of the core platform API.
	//
	// This is not strictly in order from narrowest to widest as the Test API is wider than system but
	// is neither wider or narrower than the module-lib or core platform APIs. However, this works
	// well enough at the moment.
	// TODO(b/191644675): Correctly reflect the sub/superset relationships between APIs.
	hiddenAPIScopes = []*HiddenAPIScope{
		PublicHiddenAPIScope,
		SystemHiddenAPIScope,
		TestHiddenAPIScope,
		ModuleLibHiddenAPIScope,
		CorePlatformHiddenAPIScope,
	}

	// The HiddenAPIScope instances that are supported by a java_sdk_library.
	//
	// CorePlatformHiddenAPIScope is not used as the java_sdk_library does not have special support
	// for core_platform API, instead it is implemented as a customized form of PublicHiddenAPIScope.
	hiddenAPISdkLibrarySupportedScopes = []*HiddenAPIScope{
		PublicHiddenAPIScope,
		SystemHiddenAPIScope,
		TestHiddenAPIScope,
		ModuleLibHiddenAPIScope,
	}

	// The HiddenAPIScope instances that are supported by the `hiddenapi list`.
	hiddenAPIFlagScopes = []*HiddenAPIScope{
		PublicHiddenAPIScope,
		SystemHiddenAPIScope,
		TestHiddenAPIScope,
		CorePlatformHiddenAPIScope,
	}
)

type hiddenAPIStubsDependencyTag struct {
	blueprint.BaseDependencyTag

	// The api scope for which this dependency was added.
	apiScope *HiddenAPIScope

	// Indicates that the dependency is not for an API provided by the current bootclasspath fragment
	// but is an additional API provided by a module that is not part of the current bootclasspath
	// fragment.
	fromAdditionalDependency bool
}

func (b hiddenAPIStubsDependencyTag) ExcludeFromApexContents() {
}

func (b hiddenAPIStubsDependencyTag) ReplaceSourceWithPrebuilt() bool {
	return false
}

func (b hiddenAPIStubsDependencyTag) SdkMemberType(child android.Module) android.SdkMemberType {
	// Do not add additional dependencies to the sdk.
	if b.fromAdditionalDependency {
		return nil
	}

	// If the module is a java_sdk_library then treat it as if it was specific in the java_sdk_libs
	// property, otherwise treat if it was specified in the java_header_libs property.
	if javaSdkLibrarySdkMemberType.IsInstance(child) {
		return javaSdkLibrarySdkMemberType
	}

	return javaHeaderLibsSdkMemberType
}

func (b hiddenAPIStubsDependencyTag) ExportMember() bool {
	// Export the module added via this dependency tag from the sdk.
	return true
}

// Avoid having to make stubs content explicitly visible to dependent modules.
//
// This is a temporary workaround to make it easier to migrate to bootclasspath_fragment modules
// with proper dependencies.
// TODO(b/177892522): Remove this and add needed visibility.
func (b hiddenAPIStubsDependencyTag) ExcludeFromVisibilityEnforcement() {
}

var _ android.ExcludeFromVisibilityEnforcementTag = hiddenAPIStubsDependencyTag{}
var _ android.ReplaceSourceWithPrebuilt = hiddenAPIStubsDependencyTag{}
var _ android.ExcludeFromApexContentsTag = hiddenAPIStubsDependencyTag{}
var _ android.SdkMemberTypeDependencyTag = hiddenAPIStubsDependencyTag{}

// hiddenAPIComputeMonolithicStubLibModules computes the set of module names that provide stubs
// needed to produce the hidden API monolithic stub flags file.
func hiddenAPIComputeMonolithicStubLibModules(config android.Config) map[*HiddenAPIScope][]string {
	var publicStubModules []string
	var systemStubModules []string
	var testStubModules []string
	var corePlatformStubModules []string

	if config.AlwaysUsePrebuiltSdks() {
		// Build configuration mandates using prebuilt stub modules
		publicStubModules = append(publicStubModules, "sdk_public_current_android")
		systemStubModules = append(systemStubModules, "sdk_system_current_android")
		testStubModules = append(testStubModules, "sdk_test_current_android")
	} else {
		// Use stub modules built from source
		publicStubModules = append(publicStubModules, "android_stubs_current")
		systemStubModules = append(systemStubModules, "android_system_stubs_current")
		testStubModules = append(testStubModules, "android_test_stubs_current")
	}
	// We do not have prebuilts of the core platform api yet
	corePlatformStubModules = append(corePlatformStubModules, "legacy.core.platform.api.stubs")

	// Allow products to define their own stubs for custom product jars that apps can use.
	publicStubModules = append(publicStubModules, config.ProductHiddenAPIStubs()...)
	systemStubModules = append(systemStubModules, config.ProductHiddenAPIStubsSystem()...)
	testStubModules = append(testStubModules, config.ProductHiddenAPIStubsTest()...)
	if config.IsEnvTrue("EMMA_INSTRUMENT") {
		// Add jacoco-stubs to public, system and test. It doesn't make any real difference as public
		// allows everyone access but it is needed to ensure consistent flags between the
		// bootclasspath fragment generated flags and the platform_bootclasspath generated flags.
		publicStubModules = append(publicStubModules, "jacoco-stubs")
		systemStubModules = append(systemStubModules, "jacoco-stubs")
		testStubModules = append(testStubModules, "jacoco-stubs")
	}

	m := map[*HiddenAPIScope][]string{}
	m[PublicHiddenAPIScope] = publicStubModules
	m[SystemHiddenAPIScope] = systemStubModules
	m[TestHiddenAPIScope] = testStubModules
	m[CorePlatformHiddenAPIScope] = corePlatformStubModules
	return m
}

// hiddenAPIAddStubLibDependencies adds dependencies onto the modules specified in
// apiScopeToStubLibModules. It adds them in a well known order and uses a HiddenAPIScope specific
// tag to identify the source of the dependency.
func hiddenAPIAddStubLibDependencies(ctx android.BottomUpMutatorContext, apiScopeToStubLibModules map[*HiddenAPIScope][]string) {
	module := ctx.Module()
	for _, apiScope := range hiddenAPIScopes {
		modules := apiScopeToStubLibModules[apiScope]
		ctx.AddDependency(module, hiddenAPIStubsDependencyTag{apiScope: apiScope}, modules...)
	}
}

// hiddenAPIRetrieveDexJarBuildPath retrieves the DexJarBuildPath from the specified module, if
// available, or reports an error.
func hiddenAPIRetrieveDexJarBuildPath(ctx android.ModuleContext, module android.Module, kind android.SdkKind) android.Path {
	var dexJar android.Path
	if sdkLibrary, ok := module.(SdkLibraryDependency); ok {
		dexJar = sdkLibrary.SdkApiStubDexJar(ctx, kind)
	} else if j, ok := module.(UsesLibraryDependency); ok {
		dexJar = j.DexJarBuildPath()
	} else {
		ctx.ModuleErrorf("dependency %s of module type %s does not support providing a dex jar", module, ctx.OtherModuleType(module))
		return nil
	}

	if dexJar == nil {
		ctx.ModuleErrorf("dependency %s does not provide a dex jar, consider setting compile_dex: true", module)
	}
	return dexJar
}

// buildRuleToGenerateHiddenAPIStubFlagsFile creates a rule to create a hidden API stub flags file.
//
// The rule is initialized but not built so that the caller can modify it and select an appropriate
// name.
func buildRuleToGenerateHiddenAPIStubFlagsFile(ctx android.BuilderContext, name, desc string, outputPath android.WritablePath, bootDexJars android.Paths, input HiddenAPIFlagInput, moduleStubFlagsPaths android.Paths) {
	// Singleton rule which applies hiddenapi on all boot class path dex files.
	rule := android.NewRuleBuilder(pctx, ctx)

	tempPath := tempPathForRestat(ctx, outputPath)

	// Find the widest API stubs provided by the fragments on which this depends, if any.
	dependencyStubDexJars := input.DependencyStubDexJarsByScope.StubDexJarsForWidestAPIScope()

	// Add widest API stubs from the additional dependencies of this, if any.
	dependencyStubDexJars = append(dependencyStubDexJars, input.AdditionalStubDexJarsByScope.StubDexJarsForWidestAPIScope()...)

	command := rule.Command().
		Tool(ctx.Config().HostToolPath(ctx, "hiddenapi")).
		Text("list").
		FlagForEachInput("--dependency-stub-dex=", dependencyStubDexJars).
		FlagForEachInput("--boot-dex=", bootDexJars)

	// If no module stub flags paths are provided then this must be being called for a
	// bootclasspath_fragment and not the whole platform_bootclasspath.
	if moduleStubFlagsPaths == nil {
		// This is being run on a fragment of the bootclasspath.
		command.Flag("--fragment")
	}

	// Iterate over the api scopes in a fixed order.
	for _, apiScope := range hiddenAPIFlagScopes {
		// Merge in the stub dex jar paths for this api scope from the fragments on which it depends.
		// They will be needed to resolve dependencies from this fragment's stubs to classes in the
		// other fragment's APIs.
		var paths android.Paths
		paths = append(paths, input.DependencyStubDexJarsByScope.StubDexJarsForScope(apiScope)...)
		paths = append(paths, input.AdditionalStubDexJarsByScope.StubDexJarsForScope(apiScope)...)
		paths = append(paths, input.StubDexJarsByScope.StubDexJarsForScope(apiScope)...)
		if len(paths) > 0 {
			option := apiScope.hiddenAPIListOption
			command.FlagWithInputList(option+"=", paths, ":")
		}
	}

	// Add the output path.
	command.FlagWithOutput("--out-api-flags=", tempPath)

	// If there are stub flag files that have been generated by fragments on which this depends then
	// use them to validate the stub flag file generated by the rules created by this method.
	if len(moduleStubFlagsPaths) > 0 {
		validFile := buildRuleValidateOverlappingCsvFiles(ctx, name, desc, outputPath, moduleStubFlagsPaths)

		// Add the file that indicates that the file generated by this is valid.
		//
		// This will cause the validation rule above to be run any time that the output of this rule
		// changes but the validation will run in parallel with other rules that depend on this file.
		command.Validation(validFile)
	}

	commitChangeForRestat(rule, tempPath, outputPath)

	rule.Build(name, desc)
}

// HiddenAPIFlagFileProperties contains paths to the flag files that can be used to augment the
// information obtained from annotations within the source code in order to create the complete set
// of flags that should be applied to the dex implementation jars on the bootclasspath.
//
// Each property contains a list of paths. With the exception of the Unsupported_packages the paths
// of each property reference a plain text file that contains a java signature per line. The flags
// for each of those signatures will be updated in a property specific way.
//
// The Unsupported_packages property contains a list of paths, each of which is a plain text file
// with one Java package per line. All members of all classes within that package (but not nested
// packages) will be updated in a property specific way.
type HiddenAPIFlagFileProperties struct {
	// Marks each signature in the referenced files as being unsupported.
	Unsupported []string `android:"path"`

	// Marks each signature in the referenced files as being unsupported because it has been removed.
	// Any conflicts with other flags are ignored.
	Removed []string `android:"path"`

	// Marks each signature in the referenced files as being supported only for targetSdkVersion <= R
	// and low priority.
	Max_target_r_low_priority []string `android:"path"`

	// Marks each signature in the referenced files as being supported only for targetSdkVersion <= Q.
	Max_target_q []string `android:"path"`

	// Marks each signature in the referenced files as being supported only for targetSdkVersion <= P.
	Max_target_p []string `android:"path"`

	// Marks each signature in the referenced files as being supported only for targetSdkVersion <= O
	// and low priority. Any conflicts with other flags are ignored.
	Max_target_o_low_priority []string `android:"path"`

	// Marks each signature in the referenced files as being blocked.
	Blocked []string `android:"path"`

	// Marks each signature in every package in the referenced files as being unsupported.
	Unsupported_packages []string `android:"path"`
}

type hiddenAPIFlagFileCategory struct {
	// PropertyName is the name of the property for this category.
	PropertyName string

	// propertyValueReader retrieves the value of the property for this category from the set of
	// properties.
	propertyValueReader func(properties *HiddenAPIFlagFileProperties) []string

	// commandMutator adds the appropriate command line options for this category to the supplied
	// command
	commandMutator func(command *android.RuleBuilderCommand, path android.Path)
}

// The flag file category for removed members of the API.
//
// This is extracted from HiddenAPIFlagFileCategories as it is needed to add the dex signatures
// list of removed API members that are generated automatically from the removed.txt files provided
// by API stubs.
var hiddenAPIRemovedFlagFileCategory = &hiddenAPIFlagFileCategory{
	// See HiddenAPIFlagFileProperties.Removed
	PropertyName: "removed",
	propertyValueReader: func(properties *HiddenAPIFlagFileProperties) []string {
		return properties.Removed
	},
	commandMutator: func(command *android.RuleBuilderCommand, path android.Path) {
		command.FlagWithInput("--unsupported ", path).Flag("--ignore-conflicts ").FlagWithArg("--tag ", "removed")
	},
}

var HiddenAPIFlagFileCategories = []*hiddenAPIFlagFileCategory{
	// See HiddenAPIFlagFileProperties.Unsupported
	{
		PropertyName: "unsupported",
		propertyValueReader: func(properties *HiddenAPIFlagFileProperties) []string {
			return properties.Unsupported
		},
		commandMutator: func(command *android.RuleBuilderCommand, path android.Path) {
			command.FlagWithInput("--unsupported ", path)
		},
	},
	hiddenAPIRemovedFlagFileCategory,
	// See HiddenAPIFlagFileProperties.Max_target_r_low_priority
	{
		PropertyName: "max_target_r_low_priority",
		propertyValueReader: func(properties *HiddenAPIFlagFileProperties) []string {
			return properties.Max_target_r_low_priority
		},
		commandMutator: func(command *android.RuleBuilderCommand, path android.Path) {
			command.FlagWithInput("--max-target-r ", path).FlagWithArg("--tag ", "lo-prio")
		},
	},
	// See HiddenAPIFlagFileProperties.Max_target_q
	{
		PropertyName: "max_target_q",
		propertyValueReader: func(properties *HiddenAPIFlagFileProperties) []string {
			return properties.Max_target_q
		},
		commandMutator: func(command *android.RuleBuilderCommand, path android.Path) {
			command.FlagWithInput("--max-target-q ", path)
		},
	},
	// See HiddenAPIFlagFileProperties.Max_target_p
	{
		PropertyName: "max_target_p",
		propertyValueReader: func(properties *HiddenAPIFlagFileProperties) []string {
			return properties.Max_target_p
		},
		commandMutator: func(command *android.RuleBuilderCommand, path android.Path) {
			command.FlagWithInput("--max-target-p ", path)
		},
	},
	// See HiddenAPIFlagFileProperties.Max_target_o_low_priority
	{
		PropertyName: "max_target_o_low_priority",
		propertyValueReader: func(properties *HiddenAPIFlagFileProperties) []string {
			return properties.Max_target_o_low_priority
		},
		commandMutator: func(command *android.RuleBuilderCommand, path android.Path) {
			command.FlagWithInput("--max-target-o ", path).Flag("--ignore-conflicts ").FlagWithArg("--tag ", "lo-prio")
		},
	},
	// See HiddenAPIFlagFileProperties.Blocked
	{
		PropertyName: "blocked",
		propertyValueReader: func(properties *HiddenAPIFlagFileProperties) []string {
			return properties.Blocked
		},
		commandMutator: func(command *android.RuleBuilderCommand, path android.Path) {
			command.FlagWithInput("--blocked ", path)
		},
	},
	// See HiddenAPIFlagFileProperties.Unsupported_packages
	{
		PropertyName: "unsupported_packages",
		propertyValueReader: func(properties *HiddenAPIFlagFileProperties) []string {
			return properties.Unsupported_packages
		},
		commandMutator: func(command *android.RuleBuilderCommand, path android.Path) {
			command.FlagWithInput("--unsupported ", path).Flag("--packages ")
		},
	},
}

// FlagFilesByCategory maps a hiddenAPIFlagFileCategory to the paths to the files in that category.
type FlagFilesByCategory map[*hiddenAPIFlagFileCategory]android.Paths

// append appends the supplied flags files to the corresponding category in this map.
func (s FlagFilesByCategory) append(other FlagFilesByCategory) {
	for _, category := range HiddenAPIFlagFileCategories {
		s[category] = append(s[category], other[category]...)
	}
}

// dedup removes duplicates in the flag files, while maintaining the order in which they were
// appended.
func (s FlagFilesByCategory) dedup() {
	for category, paths := range s {
		s[category] = android.FirstUniquePaths(paths)
	}
}

// HiddenAPIInfo contains information provided by the hidden API processing.
//
// That includes paths resolved from HiddenAPIFlagFileProperties and also generated by hidden API
// processing.
type HiddenAPIInfo struct {
	// FlagFilesByCategory maps from the flag file category to the paths containing information for
	// that category.
	FlagFilesByCategory FlagFilesByCategory

	// The paths to the stub dex jars for each of the *HiddenAPIScope in hiddenAPIScopes provided by
	// this fragment and the fragments on which this depends.
	TransitiveStubDexJarsByScope StubDexJarsByModule

	// The output from the hidden API processing needs to be made available to other modules.
	HiddenAPIFlagOutput
}

func newHiddenAPIInfo() *HiddenAPIInfo {
	info := HiddenAPIInfo{
		FlagFilesByCategory:          FlagFilesByCategory{},
		TransitiveStubDexJarsByScope: StubDexJarsByModule{},
	}
	return &info
}

func (i *HiddenAPIInfo) mergeFromFragmentDeps(ctx android.ModuleContext, fragments []android.Module) {
	// Merge all the information from the fragments. The fragments form a DAG so it is possible that
	// this will introduce duplicates so they will be resolved after processing all the fragments.
	for _, fragment := range fragments {
		if ctx.OtherModuleHasProvider(fragment, HiddenAPIInfoProvider) {
			info := ctx.OtherModuleProvider(fragment, HiddenAPIInfoProvider).(HiddenAPIInfo)
			i.TransitiveStubDexJarsByScope.addStubDexJarsByModule(info.TransitiveStubDexJarsByScope)
		}
	}
}

var HiddenAPIInfoProvider = blueprint.NewProvider(HiddenAPIInfo{})

// ModuleStubDexJars contains the stub dex jars provided by a single module.
//
// It maps a *HiddenAPIScope to the path to stub dex jars appropriate for that scope. See
// hiddenAPIScopes for a list of the acceptable *HiddenAPIScope values.
type ModuleStubDexJars map[*HiddenAPIScope]android.Path

// stubDexJarForWidestAPIScope returns the stub dex jars for the widest API scope provided by this
// map.
//
// The relative width of APIs is determined by their order in hiddenAPIScopes.
func (s ModuleStubDexJars) stubDexJarForWidestAPIScope() android.Path {
	for i := len(hiddenAPIScopes) - 1; i >= 0; i-- {
		apiScope := hiddenAPIScopes[i]
		if stubsForAPIScope, ok := s[apiScope]; ok {
			return stubsForAPIScope
		}
	}

	return nil
}

// StubDexJarsByModule contains the stub dex jars provided by a set of modules.
//
// It maps a module name to the path to the stub dex jars provided by that module.
type StubDexJarsByModule map[string]ModuleStubDexJars

// addStubDexJar adds a stub dex jar path provided by the specified module for the specified scope.
func (s StubDexJarsByModule) addStubDexJar(ctx android.ModuleContext, module android.Module, scope *HiddenAPIScope, stubDexJar android.Path) {
	name := android.RemoveOptionalPrebuiltPrefix(module.Name())

	// Each named module provides one dex jar for each scope. However, in some cases different API
	// versions of a single classes are provided by separate modules. e.g. the core platform
	// version of java.lang.Object is provided by the legacy.art.module.platform.api module but the
	// public version is provided by the art.module.public.api module. In those cases it is necessary
	// to treat all those modules as they were the same name, otherwise it will result in multiple
	// definitions of a single class being passed to hidden API processing which will cause an error.
	if name == scope.nonUpdatablePrebuiltModule || name == scope.nonUpdatableSourceModule {
		// Treat all *android-non-updatable* modules as if they were part of an android-non-updatable
		// java_sdk_library.
		// TODO(b/192067200): Remove once android-non-updatable is a java_sdk_library or equivalent.
		name = "android-non-updatable"
	} else if name == "legacy.art.module.platform.api" {
		// Treat legacy.art.module.platform.api as if it was an API scope provided by the
		// art.module.public.api java_sdk_library which will be the case once the former has been
		// migrated to a module_lib API.
		name = "art.module.public.api"
	} else if name == "legacy.i18n.module.platform.api" {
		// Treat legacy.i18n.module.platform.api as if it was an API scope provided by the
		// i18n.module.public.api java_sdk_library which will be the case once the former has been
		// migrated to a module_lib API.
		name = "i18n.module.public.api"
	} else if name == "conscrypt.module.platform.api" {
		// Treat conscrypt.module.platform.api as if it was an API scope provided by the
		// conscrypt.module.public.api java_sdk_library which will be the case once the former has been
		// migrated to a module_lib API.
		name = "conscrypt.module.public.api"
	} else if d, ok := module.(SdkLibraryComponentDependency); ok {
		sdkLibraryName := d.SdkLibraryName()
		if sdkLibraryName != nil {
			// The module is a component of a java_sdk_library so use the name of the java_sdk_library.
			// e.g. if this module is `foo.system.stubs` and is part of the `foo` java_sdk_library then
			// use `foo` as the name.
			name = *sdkLibraryName
		}
	}
	stubDexJarsByScope := s[name]
	if stubDexJarsByScope == nil {
		stubDexJarsByScope = ModuleStubDexJars{}
		s[name] = stubDexJarsByScope
	}
	stubDexJarsByScope[scope] = stubDexJar
}

// addStubDexJarsByModule adds the stub dex jars in the supplied StubDexJarsByModule to this map.
func (s StubDexJarsByModule) addStubDexJarsByModule(other StubDexJarsByModule) {
	for module, stubDexJarsByScope := range other {
		s[module] = stubDexJarsByScope
	}
}

// StubDexJarsForWidestAPIScope returns a list of stub dex jars containing the widest API scope
// provided by each module.
//
// The relative width of APIs is determined by their order in hiddenAPIScopes.
func (s StubDexJarsByModule) StubDexJarsForWidestAPIScope() android.Paths {
	stubDexJars := android.Paths{}
	modules := android.SortedStringKeys(s)
	for _, module := range modules {
		stubDexJarsByScope := s[module]

		stubDexJars = append(stubDexJars, stubDexJarsByScope.stubDexJarForWidestAPIScope())
	}

	return stubDexJars
}

// StubDexJarsForScope returns a list of stub dex jars containing the stub dex jars provided by each
// module for the specified scope.
//
// If a module does not provide a stub dex jar for the supplied scope then it does not contribute to
// the returned list.
func (s StubDexJarsByModule) StubDexJarsForScope(scope *HiddenAPIScope) android.Paths {
	stubDexJars := android.Paths{}
	modules := android.SortedStringKeys(s)
	for _, module := range modules {
		stubDexJarsByScope := s[module]
		// Not every module will have the same set of
		if jars, ok := stubDexJarsByScope[scope]; ok {
			stubDexJars = append(stubDexJars, jars)
		}
	}

	return stubDexJars
}

// HiddenAPIFlagInput encapsulates information obtained from a module and its dependencies that are
// needed for hidden API flag generation.
type HiddenAPIFlagInput struct {
	// FlagFilesByCategory contains the flag files that override the initial flags that are derived
	// from the stub dex files.
	FlagFilesByCategory FlagFilesByCategory

	// StubDexJarsByScope contains the stub dex jars for different *HiddenAPIScope and which determine
	// the initial flags for each dex member.
	StubDexJarsByScope StubDexJarsByModule

	// DependencyStubDexJarsByScope contains the stub dex jars provided by the fragments on which this
	// depends. It is the result of merging HiddenAPIInfo.TransitiveStubDexJarsByScope from each
	// fragment on which this depends.
	DependencyStubDexJarsByScope StubDexJarsByModule

	// AdditionalStubDexJarsByScope contains stub dex jars provided by other modules in addition to
	// the ones that are obtained from fragments on which this depends.
	//
	// These are kept separate from stub dex jars in HiddenAPIFlagInput.DependencyStubDexJarsByScope
	// as there are not propagated transitively to other fragments that depend on this.
	AdditionalStubDexJarsByScope StubDexJarsByModule

	// RemovedTxtFiles is the list of removed.txt files provided by java_sdk_library modules that are
	// specified in the bootclasspath_fragment's stub_libs and contents properties.
	RemovedTxtFiles android.Paths
}

// newHiddenAPIFlagInput creates a new initialize HiddenAPIFlagInput struct.
func newHiddenAPIFlagInput() HiddenAPIFlagInput {
	input := HiddenAPIFlagInput{
		FlagFilesByCategory:          FlagFilesByCategory{},
		StubDexJarsByScope:           StubDexJarsByModule{},
		DependencyStubDexJarsByScope: StubDexJarsByModule{},
		AdditionalStubDexJarsByScope: StubDexJarsByModule{},
	}

	return input
}

// gatherStubLibInfo gathers information from the stub libs needed by hidden API processing from the
// dependencies added in hiddenAPIAddStubLibDependencies.
//
// That includes paths to the stub dex jars as well as paths to the *removed.txt files.
func (i *HiddenAPIFlagInput) gatherStubLibInfo(ctx android.ModuleContext, contents []android.Module) {
	addFromModule := func(ctx android.ModuleContext, module android.Module, apiScope *HiddenAPIScope) {
		sdkKind := apiScope.sdkKind
		dexJar := hiddenAPIRetrieveDexJarBuildPath(ctx, module, sdkKind)
		if dexJar != nil {
			i.StubDexJarsByScope.addStubDexJar(ctx, module, apiScope, dexJar)
		}

		if sdkLibrary, ok := module.(SdkLibraryDependency); ok {
			removedTxtFile := sdkLibrary.SdkRemovedTxtFile(ctx, sdkKind)
			i.RemovedTxtFiles = append(i.RemovedTxtFiles, removedTxtFile.AsPaths()...)
		}
	}

	// If the contents includes any java_sdk_library modules then add them to the stubs.
	for _, module := range contents {
		if _, ok := module.(SdkLibraryDependency); ok {
			// Add information for every possible API scope needed by hidden API.
			for _, apiScope := range hiddenAPISdkLibrarySupportedScopes {
				addFromModule(ctx, module, apiScope)
			}
		}
	}

	ctx.VisitDirectDeps(func(module android.Module) {
		tag := ctx.OtherModuleDependencyTag(module)
		if hiddenAPIStubsTag, ok := tag.(hiddenAPIStubsDependencyTag); ok {
			apiScope := hiddenAPIStubsTag.apiScope
			if hiddenAPIStubsTag.fromAdditionalDependency {
				dexJar := hiddenAPIRetrieveDexJarBuildPath(ctx, module, apiScope.sdkKind)
				if dexJar != nil {
					i.AdditionalStubDexJarsByScope.addStubDexJar(ctx, module, apiScope, dexJar)
				}
			} else {
				addFromModule(ctx, module, apiScope)
			}
		}
	})

	// Normalize the paths, i.e. remove duplicates and sort.
	i.RemovedTxtFiles = android.SortedUniquePaths(i.RemovedTxtFiles)
}

// extractFlagFilesFromProperties extracts the paths to flag files that are specified in the
// supplied properties and stores them in this struct.
func (i *HiddenAPIFlagInput) extractFlagFilesFromProperties(ctx android.ModuleContext, p *HiddenAPIFlagFileProperties) {
	for _, category := range HiddenAPIFlagFileCategories {
		paths := android.PathsForModuleSrc(ctx, category.propertyValueReader(p))
		i.FlagFilesByCategory[category] = paths
	}
}

func (i *HiddenAPIFlagInput) transitiveStubDexJarsByScope() StubDexJarsByModule {
	transitive := i.DependencyStubDexJarsByScope
	transitive.addStubDexJarsByModule(i.StubDexJarsByScope)
	return transitive
}

// HiddenAPIFlagOutput contains paths to output files from the hidden API flag generation for a
// bootclasspath_fragment module.
type HiddenAPIFlagOutput struct {
	// The path to the generated stub-flags.csv file.
	StubFlagsPath android.Path

	// The path to the generated annotation-flags.csv file.
	AnnotationFlagsPath android.Path

	// The path to the generated metadata.csv file.
	MetadataPath android.Path

	// The path to the generated index.csv file.
	IndexPath android.Path

	// The path to the generated all-flags.csv file.
	AllFlagsPath android.Path
}

// bootDexJarByModule is a map from base module name (without prebuilt_ prefix) to the boot dex
// path.
type bootDexJarByModule map[string]android.Path

// addPath adds the path for a module to the map.
func (b bootDexJarByModule) addPath(module android.Module, path android.Path) {
	b[android.RemoveOptionalPrebuiltPrefix(module.Name())] = path
}

// bootDexJars returns the boot dex jar paths sorted by their keys.
func (b bootDexJarByModule) bootDexJars() android.Paths {
	paths := android.Paths{}
	for _, k := range android.SortedStringKeys(b) {
		paths = append(paths, b[k])
	}
	return paths
}

// bootDexJarsWithoutCoverage returns the boot dex jar paths sorted by their keys without coverage
// libraries if present.
func (b bootDexJarByModule) bootDexJarsWithoutCoverage() android.Paths {
	paths := android.Paths{}
	for _, k := range android.SortedStringKeys(b) {
		if k == "jacocoagent" {
			continue
		}
		paths = append(paths, b[k])
	}
	return paths
}

// HiddenAPIOutput encapsulates the output from the hidden API processing.
type HiddenAPIOutput struct {
	HiddenAPIFlagOutput

	// The map from base module name to the path to the encoded boot dex file.
	EncodedBootDexFilesByModule bootDexJarByModule
}

// pathForValidation creates a path of the same type as the supplied type but with a name of
// <path>.valid.
//
// e.g. If path is an OutputPath for out/soong/hiddenapi/hiddenapi-flags.csv then this will return
// an OutputPath for out/soong/hiddenapi/hiddenapi-flags.csv.valid
func pathForValidation(ctx android.PathContext, path android.WritablePath) android.WritablePath {
	extWithoutLeadingDot := strings.TrimPrefix(path.Ext(), ".")
	return path.ReplaceExtension(ctx, extWithoutLeadingDot+".valid")
}

// buildRuleToGenerateHiddenApiFlags creates a rule to create the monolithic hidden API flags from
// the flags from all the modules, the stub flags, augmented with some additional configuration
// files.
//
// baseFlagsPath is the path to the flags file containing all the information from the stubs plus
// an entry for every single member in the dex implementation jars of the individual modules. Every
// signature in any of the other files MUST be included in this file.
//
// annotationFlags is the path to the annotation flags file generated from annotation information
// in each module.
//
// hiddenAPIInfo is a struct containing paths to files that augment the information provided by
// the annotationFlags.
func buildRuleToGenerateHiddenApiFlags(ctx android.BuilderContext, name, desc string,
	outputPath android.WritablePath, baseFlagsPath android.Path, annotationFlagPaths android.Paths,
	flagFilesByCategory FlagFilesByCategory, allFlagsPaths android.Paths, generatedRemovedDexSignatures android.OptionalPath) {

	// Create the rule that will generate the flag files.
	tempPath := tempPathForRestat(ctx, outputPath)
	rule := android.NewRuleBuilder(pctx, ctx)
	command := rule.Command().
		BuiltTool("generate_hiddenapi_lists").
		FlagWithInput("--csv ", baseFlagsPath).
		Inputs(annotationFlagPaths).
		FlagWithOutput("--output ", tempPath)

	// Add the options for the different categories of flag files.
	for _, category := range HiddenAPIFlagFileCategories {
		paths := flagFilesByCategory[category]
		for _, path := range paths {
			category.commandMutator(command, path)
		}
	}

	// If available then pass the automatically generated file containing dex signatures of removed
	// API members to the rule so they can be marked as removed.
	if generatedRemovedDexSignatures.Valid() {
		hiddenAPIRemovedFlagFileCategory.commandMutator(command, generatedRemovedDexSignatures.Path())
	}

	commitChangeForRestat(rule, tempPath, outputPath)

	// If there are flag files that have been generated by fragments on which this depends then use
	// them to validate the flag file generated by the rules created by this method.
	if len(allFlagsPaths) > 0 {
		validFile := buildRuleValidateOverlappingCsvFiles(ctx, name, desc, outputPath, allFlagsPaths)

		// Add the file that indicates that the file generated by this is valid.
		//
		// This will cause the validation rule above to be run any time that the output of this rule
		// changes but the validation will run in parallel with other rules that depend on this file.
		command.Validation(validFile)
	}

	rule.Build(name, desc)
}

// buildRuleValidateOverlappingCsvFiles checks that the modular CSV files, i.e. the files generated
// by the individual bootclasspath_fragment modules are subsets of the monolithic CSV file.
func buildRuleValidateOverlappingCsvFiles(ctx android.BuilderContext, name string, desc string, monolithicFilePath android.WritablePath, modularFilePaths android.Paths) android.WritablePath {
	// The file which is used to record that the flags file is valid.
	validFile := pathForValidation(ctx, monolithicFilePath)

	// Create a rule to validate the output from the following rule.
	rule := android.NewRuleBuilder(pctx, ctx)
	rule.Command().
		BuiltTool("verify_overlaps").
		Input(monolithicFilePath).
		Inputs(modularFilePaths).
		// If validation passes then update the file that records that.
		Text("&& touch").Output(validFile)
	rule.Build(name+"Validation", desc+" validation")

	return validFile
}

// hiddenAPIRulesForBootclasspathFragment will generate all the flags for a fragment of the
// bootclasspath and then encode the flags into the boot dex files.
//
// It takes:
// * Map from android.SdkKind to stub dex jar paths defining the API for that sdk kind.
// * The list of modules that are the contents of the fragment.
// * The additional manually curated flag files to use.
//
// It generates:
// * stub-flags.csv
// * annotation-flags.csv
// * metadata.csv
// * index.csv
// * all-flags.csv
// * encoded boot dex files
func hiddenAPIRulesForBootclasspathFragment(ctx android.ModuleContext, contents []android.Module, input HiddenAPIFlagInput) *HiddenAPIOutput {
	hiddenApiSubDir := "modular-hiddenapi"

	// Gather information about the boot dex files for the boot libraries provided by this fragment.
	bootDexInfoByModule := extractBootDexInfoFromModules(ctx, contents)

	// Generate the stub-flags.csv.
	stubFlagsCSV := android.PathForModuleOut(ctx, hiddenApiSubDir, "stub-flags.csv")
	buildRuleToGenerateHiddenAPIStubFlagsFile(ctx, "modularHiddenAPIStubFlagsFile", "modular hiddenapi stub flags", stubFlagsCSV, bootDexInfoByModule.bootDexJars(), input, nil)

	// Extract the classes jars from the contents.
	classesJars := extractClassesJarsFromModules(contents)

	// Generate the set of flags from the annotations in the source code.
	annotationFlagsCSV := android.PathForModuleOut(ctx, hiddenApiSubDir, "annotation-flags.csv")
	buildRuleToGenerateAnnotationFlags(ctx, "modular hiddenapi annotation flags", classesJars, stubFlagsCSV, annotationFlagsCSV)

	// Generate the metadata from the annotations in the source code.
	metadataCSV := android.PathForModuleOut(ctx, hiddenApiSubDir, "metadata.csv")
	buildRuleToGenerateMetadata(ctx, "modular hiddenapi metadata", classesJars, stubFlagsCSV, metadataCSV)

	// Generate the index file from the CSV files in the classes jars.
	indexCSV := android.PathForModuleOut(ctx, hiddenApiSubDir, "index.csv")
	buildRuleToGenerateIndex(ctx, "modular hiddenapi index", classesJars, indexCSV)

	// Removed APIs need to be marked and in order to do that the hiddenAPIInfo needs to specify files
	// containing dex signatures of all the removed APIs. In the monolithic files that is done by
	// manually combining all the removed.txt files for each API and then converting them to dex
	// signatures, see the combined-removed-dex module. This does that automatically by using the
	// *removed.txt files retrieved from the java_sdk_library modules that are specified in the
	// stub_libs and contents properties of a bootclasspath_fragment.
	removedDexSignatures := buildRuleToGenerateRemovedDexSignatures(ctx, input.RemovedTxtFiles)

	// Generate the all-flags.csv which are the flags that will, in future, be encoded into the dex
	// files.
	allFlagsCSV := android.PathForModuleOut(ctx, hiddenApiSubDir, "all-flags.csv")
	buildRuleToGenerateHiddenApiFlags(ctx, "modularHiddenApiAllFlags", "modular hiddenapi all flags", allFlagsCSV, stubFlagsCSV, android.Paths{annotationFlagsCSV}, input.FlagFilesByCategory, nil, removedDexSignatures)

	// Encode the flags into the boot dex files.
	encodedBootDexJarsByModule := map[string]android.Path{}
	outputDir := android.PathForModuleOut(ctx, "hiddenapi-modular/encoded").OutputPath
	for _, name := range android.SortedStringKeys(bootDexInfoByModule) {
		bootDexInfo := bootDexInfoByModule[name]
		unencodedDex := bootDexInfo.path
		encodedDex := hiddenAPIEncodeDex(ctx, unencodedDex, allFlagsCSV, bootDexInfo.uncompressDex, outputDir)
		encodedBootDexJarsByModule[name] = encodedDex
	}

	// Store the paths in the info for use by other modules and sdk snapshot generation.
	output := HiddenAPIOutput{
		HiddenAPIFlagOutput: HiddenAPIFlagOutput{
			StubFlagsPath:       stubFlagsCSV,
			AnnotationFlagsPath: annotationFlagsCSV,
			MetadataPath:        metadataCSV,
			IndexPath:           indexCSV,
			AllFlagsPath:        allFlagsCSV,
		},
		EncodedBootDexFilesByModule: encodedBootDexJarsByModule,
	}
	return &output
}

func buildRuleToGenerateRemovedDexSignatures(ctx android.ModuleContext, removedTxtFiles android.Paths) android.OptionalPath {
	if len(removedTxtFiles) == 0 {
		return android.OptionalPath{}
	}

	output := android.PathForModuleOut(ctx, "modular-hiddenapi/removed-dex-signatures.txt")

	rule := android.NewRuleBuilder(pctx, ctx)
	rule.Command().
		BuiltTool("metalava").
		Flag("--no-banner").
		Inputs(removedTxtFiles).
		FlagWithOutput("--dex-api ", output)
	rule.Build("modular-hiddenapi-removed-dex-signatures", "modular hiddenapi removed dex signatures")
	return android.OptionalPathForPath(output)
}

// extractBootDexJarsFromModules extracts the boot dex jars from the supplied modules.
func extractBootDexJarsFromModules(ctx android.ModuleContext, contents []android.Module) bootDexJarByModule {
	bootDexJars := bootDexJarByModule{}
	for _, module := range contents {
		hiddenAPIModule := hiddenAPIModuleFromModule(ctx, module)
		if hiddenAPIModule == nil {
			continue
		}
		bootDexJar := retrieveBootDexJarFromHiddenAPIModule(ctx, hiddenAPIModule)
		bootDexJars.addPath(module, bootDexJar)
	}
	return bootDexJars
}

func hiddenAPIModuleFromModule(ctx android.BaseModuleContext, module android.Module) hiddenAPIModule {
	if hiddenAPIModule, ok := module.(hiddenAPIModule); ok {
		return hiddenAPIModule
	} else if _, ok := module.(*DexImport); ok {
		// Ignore this for the purposes of hidden API processing
	} else {
		ctx.ModuleErrorf("module %s does not implement hiddenAPIModule", module)
	}

	return nil
}

// bootDexInfo encapsulates both the path and uncompressDex status retrieved from a hiddenAPIModule.
type bootDexInfo struct {
	// The path to the dex jar that has not had hidden API flags encoded into it.
	path android.Path

	// Indicates whether the dex jar needs uncompressing before encoding.
	uncompressDex bool
}

// bootDexInfoByModule is a map from module name (as returned by module.Name()) to the boot dex
// path (as returned by hiddenAPIModule.bootDexJar()) and the uncompressDex flag.
type bootDexInfoByModule map[string]bootDexInfo

// bootDexJars returns the boot dex jar paths sorted by their keys.
func (b bootDexInfoByModule) bootDexJars() android.Paths {
	paths := android.Paths{}
	for _, m := range android.SortedStringKeys(b) {
		paths = append(paths, b[m].path)
	}
	return paths
}

// extractBootDexInfoFromModules extracts the boot dex jar and uncompress dex state from
// each of the supplied modules which must implement hiddenAPIModule.
func extractBootDexInfoFromModules(ctx android.ModuleContext, contents []android.Module) bootDexInfoByModule {
	bootDexJarsByModule := bootDexInfoByModule{}
	for _, module := range contents {
		hiddenAPIModule := module.(hiddenAPIModule)
		bootDexJar := retrieveBootDexJarFromHiddenAPIModule(ctx, hiddenAPIModule)
		bootDexJarsByModule[module.Name()] = bootDexInfo{
			path:          bootDexJar,
			uncompressDex: *hiddenAPIModule.uncompressDex(),
		}
	}

	return bootDexJarsByModule
}

// retrieveBootDexJarFromHiddenAPIModule retrieves the boot dex jar from the hiddenAPIModule.
//
// If the module does not provide a boot dex jar, i.e. the returned boot dex jar is nil, then  that
// create a fake path and either report an error immediately or defer reporting of the error until
// the path is actually used.
func retrieveBootDexJarFromHiddenAPIModule(ctx android.ModuleContext, module hiddenAPIModule) android.Path {
	bootDexJar := module.bootDexJar()
	if bootDexJar == nil {
		fake := android.PathForModuleOut(ctx, fmt.Sprintf("fake/boot-dex/%s.jar", module.Name()))
		bootDexJar = fake

		handleMissingDexBootFile(ctx, module, fake)
	}
	return bootDexJar
}

// extractClassesJarsFromModules extracts the class jars from the supplied modules.
func extractClassesJarsFromModules(contents []android.Module) android.Paths {
	classesJars := android.Paths{}
	for _, module := range contents {
		classesJars = append(classesJars, retrieveClassesJarsFromModule(module)...)
	}
	return classesJars
}

// retrieveClassesJarsFromModule retrieves the classes jars from the supplied module.
func retrieveClassesJarsFromModule(module android.Module) android.Paths {
	if hiddenAPIModule, ok := module.(hiddenAPIModule); ok {
		return hiddenAPIModule.classesJars()
	}

	return nil
}

// deferReportingMissingBootDexJar returns true if a missing boot dex jar should not be reported by
// Soong but should instead only be reported in ninja if the file is actually built.
func deferReportingMissingBootDexJar(ctx android.ModuleContext, module android.Module) bool {
	// TODO(b/179354495): Remove this workaround when it is unnecessary.
	// Prebuilt modules like framework-wifi do not yet provide dex implementation jars. So,
	// create a fake one that will cause a build error only if it is used.
	if ctx.Config().AlwaysUsePrebuiltSdks() {
		return true
	}

	// Any missing dependency should be allowed.
	if ctx.Config().AllowMissingDependencies() {
		return true
	}

	// A bootclasspath module that is part of a versioned sdk never provides a boot dex jar as there
	// is no equivalently versioned prebuilt APEX file from which it can be obtained. However,
	// versioned bootclasspath modules are processed by Soong so in order to avoid them causing build
	// failures missing boot dex jars need to be deferred.
	if android.IsModuleInVersionedSdk(ctx.Module()) {
		return true
	}

	// This is called for both platform_bootclasspath and bootclasspath_fragment modules.
	//
	// A bootclasspath_fragment module should only use the APEX variant of source or prebuilt modules.
	// Ideally, a bootclasspath_fragment module should never have a platform variant created for it
	// but unfortunately, due to b/187910671 it does.
	//
	// That causes issues when obtaining a boot dex jar for a prebuilt module as a prebuilt module
	// used by a bootclasspath_fragment can only provide a boot dex jar when it is part of APEX, i.e.
	// has an APEX variant not a platform variant.
	//
	// There are some other situations when a prebuilt module used by a bootclasspath_fragment cannot
	// provide a boot dex jar:
	// 1. If the bootclasspath_fragment is not exported by the prebuilt_apex/apex_set module then it
	//    does not have an APEX variant and only has a platform variant and neither do its content
	//    modules.
	// 2. Some build configurations, e.g. setting TARGET_BUILD_USE_PREBUILT_SDKS causes all
	//    java_sdk_library_import modules to be treated as preferred and as many of them are not part
	//    of an apex they cannot provide a boot dex jar.
	//
	// The first case causes problems when the affected prebuilt modules are preferred but that is an
	// invalid configuration and it is ok for it to fail as the work to enable that is not yet
	// complete. The second case is used for building targets that do not use boot dex jars and so
	// deferring error reporting to ninja is fine as the affected ninja targets should never be built.
	// That is handled above.
	//
	// A platform_bootclasspath module can use libraries from both platform and APEX variants. Unlike
	// the bootclasspath_fragment it supports dex_import modules which provides the dex file. So, it
	// can obtain a boot dex jar from a prebuilt that is not part of an APEX. However, it is assumed
	// that if the library can be part of an APEX then it is the APEX variant that is used.
	//
	// This check handles the slightly different requirements of the bootclasspath_fragment and
	// platform_bootclasspath modules by only deferring error reporting for the platform variant of
	// a prebuilt modules that has other variants which are part of an APEX.
	//
	// TODO(b/187910671): Remove this once platform variants are no longer created unnecessarily.
	if android.IsModulePrebuilt(module) {
		// An inactive source module can still contribute to the APEX but an inactive prebuilt module
		// should not contribute to anything. So, rather than have a missing dex jar cause a Soong
		// failure defer the error reporting to Ninja. Unless the prebuilt build target is explicitly
		// built Ninja should never use the dex jar file.
		if !isActiveModule(module) {
			return true
		}

		if am, ok := module.(android.ApexModule); ok && am.InAnyApex() {
			apexInfo := ctx.OtherModuleProvider(module, android.ApexInfoProvider).(android.ApexInfo)
			if apexInfo.IsForPlatform() {
				return true
			}
		}
	}

	return false
}

// handleMissingDexBootFile will either log a warning or create an error rule to create the fake
// file depending on the value returned from deferReportingMissingBootDexJar.
func handleMissingDexBootFile(ctx android.ModuleContext, module android.Module, fake android.WritablePath) {
	if deferReportingMissingBootDexJar(ctx, module) {
		// Create an error rule that pretends to create the output file but will actually fail if it
		// is run.
		ctx.Build(pctx, android.BuildParams{
			Rule:   android.ErrorRule,
			Output: fake,
			Args: map[string]string{
				"error": fmt.Sprintf("missing dependencies: boot dex jar for %s", module),
			},
		})
	} else {
		ctx.ModuleErrorf("module %s does not provide a dex jar", module)
	}
}

// retrieveEncodedBootDexJarFromModule returns a path to the boot dex jar from the supplied module's
// DexJarBuildPath() method.
//
// The returned path will usually be to a dex jar file that has been encoded with hidden API flags.
// However, under certain conditions, e.g. errors, or special build configurations it will return
// a path to a fake file.
func retrieveEncodedBootDexJarFromModule(ctx android.ModuleContext, module android.Module) android.Path {
	bootDexJar := module.(interface{ DexJarBuildPath() android.Path }).DexJarBuildPath()
	if bootDexJar == nil {
		fake := android.PathForModuleOut(ctx, fmt.Sprintf("fake/encoded-dex/%s.jar", module.Name()))
		bootDexJar = fake

		handleMissingDexBootFile(ctx, module, fake)
	}
	return bootDexJar
}

// extractEncodedDexJarsFromModules extracts the encoded dex jars from the supplied modules.
func extractEncodedDexJarsFromModules(ctx android.ModuleContext, contents []android.Module) bootDexJarByModule {
	encodedDexJarsByModuleName := bootDexJarByModule{}
	for _, module := range contents {
		path := retrieveEncodedBootDexJarFromModule(ctx, module)
		encodedDexJarsByModuleName.addPath(module, path)
	}
	return encodedDexJarsByModuleName
}
