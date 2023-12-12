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

// The dexpreopt package converts a global dexpreopt config and a module dexpreopt config into rules to perform
// dexpreopting.
//
// It is used in two places; in the dexpeopt_gen binary for modules defined in Make, and directly linked into Soong.
//
// For Make modules it is built into the dexpreopt_gen binary, which is executed as a Make rule using global config and
// module config specified in JSON files.  The binary writes out two shell scripts, only updating them if they have
// changed.  One script takes an APK or JAR as an input and produces a zip file containing any outputs of preopting,
// in the location they should be on the device.  The Make build rules will unzip the zip file into $(PRODUCT_OUT) when
// installing the APK, which will install the preopt outputs into $(PRODUCT_OUT)/system or $(PRODUCT_OUT)/system_other
// as necessary.  The zip file may be empty if preopting was disabled for any reason.
//
// The intermediate shell scripts allow changes to this package or to the global config to regenerate the shell scripts
// but only require re-executing preopting if the script has changed.
//
// For Soong modules this package is linked directly into Soong and run from the java package.  It generates the same
// commands as for make, using athe same global config JSON file used by make, but using a module config structure
// provided by Soong.  The generated commands are then converted into Soong rule and written directly to the ninja file,
// with no extra shell scripts involved.
package dexpreopt

import (
	"fmt"
	"path/filepath"
	"runtime"
	"strings"

	"android/soong/android"

	"github.com/google/blueprint/pathtools"
)

const SystemPartition = "/system/"
const SystemOtherPartition = "/system_other/"

var DexpreoptRunningInSoong = false

// GenerateDexpreoptRule generates a set of commands that will preopt a module based on a GlobalConfig and a
// ModuleConfig.  The produced files and their install locations will be available through rule.Installs().
func GenerateDexpreoptRule(ctx android.BuilderContext, globalSoong *GlobalSoongConfig,
	global *GlobalConfig, module *ModuleConfig) (rule *android.RuleBuilder, err error) {

	defer func() {
		if r := recover(); r != nil {
			if _, ok := r.(runtime.Error); ok {
				panic(r)
			} else if e, ok := r.(error); ok {
				err = e
				rule = nil
			} else {
				panic(r)
			}
		}
	}()

	rule = android.NewRuleBuilder(pctx, ctx)

	generateProfile := module.ProfileClassListing.Valid() && !global.DisableGenerateProfile
	generateBootProfile := module.ProfileBootListing.Valid() && !global.DisableGenerateProfile

	var profile android.WritablePath
	if generateProfile {
		profile = profileCommand(ctx, globalSoong, global, module, rule)
	}
	if generateBootProfile {
		bootProfileCommand(ctx, globalSoong, global, module, rule)
	}

	if !dexpreoptDisabled(ctx, global, module) {
		if valid, err := validateClassLoaderContext(module.ClassLoaderContexts); err != nil {
			android.ReportPathErrorf(ctx, err.Error())
		} else if valid {
			fixClassLoaderContext(module.ClassLoaderContexts)

			appImage := (generateProfile || module.ForceCreateAppImage || global.DefaultAppImages) &&
				!module.NoCreateAppImage

			generateDM := shouldGenerateDM(module, global)

			for archIdx, _ := range module.Archs {
				dexpreoptCommand(ctx, globalSoong, global, module, rule, archIdx, profile, appImage, generateDM)
			}
		}
	}

	return rule, nil
}

func dexpreoptDisabled(ctx android.PathContext, global *GlobalConfig, module *ModuleConfig) bool {
	if contains(global.DisablePreoptModules, module.Name) {
		return true
	}

	// Don't preopt individual boot jars, they will be preopted together.
	if global.BootJars.ContainsJar(module.Name) {
		return true
	}

	// Don't preopt system server jars that are updatable.
	if global.UpdatableSystemServerJars.ContainsJar(module.Name) {
		return true
	}

	// If OnlyPreoptBootImageAndSystemServer=true and module is not in boot class path skip
	// Also preopt system server jars since selinux prevents system server from loading anything from
	// /data. If we don't do this they will need to be extracted which is not favorable for RAM usage
	// or performance. If PreoptExtractedApk is true, we ignore the only preopt boot image options.
	if global.OnlyPreoptBootImageAndSystemServer && !global.BootJars.ContainsJar(module.Name) &&
		!global.SystemServerJars.ContainsJar(module.Name) && !module.PreoptExtractedApk {
		return true
	}

	return false
}

func profileCommand(ctx android.PathContext, globalSoong *GlobalSoongConfig, global *GlobalConfig,
	module *ModuleConfig, rule *android.RuleBuilder) android.WritablePath {

	profilePath := module.BuildPath.InSameDir(ctx, "profile.prof")
	profileInstalledPath := module.DexLocation + ".prof"

	if !module.ProfileIsTextListing {
		rule.Command().Text("rm -f").Output(profilePath)
		rule.Command().Text("touch").Output(profilePath)
	}

	cmd := rule.Command().
		Text(`ANDROID_LOG_TAGS="*:e"`).
		Tool(globalSoong.Profman)

	if module.ProfileIsTextListing {
		// The profile is a test listing of classes (used for framework jars).
		// We need to generate the actual binary profile before being able to compile.
		cmd.FlagWithInput("--create-profile-from=", module.ProfileClassListing.Path())
	} else {
		// The profile is binary profile (used for apps). Run it through profman to
		// ensure the profile keys match the apk.
		cmd.
			Flag("--copy-and-update-profile-key").
			FlagWithInput("--profile-file=", module.ProfileClassListing.Path())
	}

	cmd.
		Flag("--output-profile-type=app").
		FlagWithInput("--apk=", module.DexPath).
		Flag("--dex-location="+module.DexLocation).
		FlagWithOutput("--reference-profile-file=", profilePath)

	if !module.ProfileIsTextListing {
		cmd.Text(fmt.Sprintf(`|| echo "Profile out of date for %s"`, module.DexPath))
	}
	rule.Install(profilePath, profileInstalledPath)

	return profilePath
}

func bootProfileCommand(ctx android.PathContext, globalSoong *GlobalSoongConfig, global *GlobalConfig,
	module *ModuleConfig, rule *android.RuleBuilder) android.WritablePath {

	profilePath := module.BuildPath.InSameDir(ctx, "profile.bprof")
	profileInstalledPath := module.DexLocation + ".bprof"

	if !module.ProfileIsTextListing {
		rule.Command().Text("rm -f").Output(profilePath)
		rule.Command().Text("touch").Output(profilePath)
	}

	cmd := rule.Command().
		Text(`ANDROID_LOG_TAGS="*:e"`).
		Tool(globalSoong.Profman)

	// The profile is a test listing of methods.
	// We need to generate the actual binary profile.
	cmd.FlagWithInput("--create-profile-from=", module.ProfileBootListing.Path())

	cmd.
		Flag("--output-profile-type=bprof").
		FlagWithInput("--apk=", module.DexPath).
		Flag("--dex-location="+module.DexLocation).
		FlagWithOutput("--reference-profile-file=", profilePath)

	if !module.ProfileIsTextListing {
		cmd.Text(fmt.Sprintf(`|| echo "Profile out of date for %s"`, module.DexPath))
	}
	rule.Install(profilePath, profileInstalledPath)

	return profilePath
}

func dexpreoptCommand(ctx android.PathContext, globalSoong *GlobalSoongConfig, global *GlobalConfig,
	module *ModuleConfig, rule *android.RuleBuilder, archIdx int, profile android.WritablePath,
	appImage bool, generateDM bool) {

	arch := module.Archs[archIdx]

	// HACK: make soname in Soong-generated .odex files match Make.
	base := filepath.Base(module.DexLocation)
	if filepath.Ext(base) == ".jar" {
		base = "javalib.jar"
	} else if filepath.Ext(base) == ".apk" {
		base = "package.apk"
	}

	toOdexPath := func(path string) string {
		return filepath.Join(
			filepath.Dir(path),
			"oat",
			arch.String(),
			pathtools.ReplaceExtension(filepath.Base(path), "odex"))
	}

	odexPath := module.BuildPath.InSameDir(ctx, "oat", arch.String(), pathtools.ReplaceExtension(base, "odex"))
	odexInstallPath := toOdexPath(module.DexLocation)
	if odexOnSystemOther(module, global) {
		odexInstallPath = filepath.Join(SystemOtherPartition, odexInstallPath)
	}

	vdexPath := odexPath.ReplaceExtension(ctx, "vdex")
	vdexInstallPath := pathtools.ReplaceExtension(odexInstallPath, "vdex")

	invocationPath := odexPath.ReplaceExtension(ctx, "invocation")

	systemServerJars := NonUpdatableSystemServerJars(ctx, global)

	rule.Command().FlagWithArg("mkdir -p ", filepath.Dir(odexPath.String()))
	rule.Command().FlagWithOutput("rm -f ", odexPath)

	if jarIndex := android.IndexList(module.Name, systemServerJars); jarIndex >= 0 {
		// System server jars should be dexpreopted together: class loader context of each jar
		// should include all preceding jars on the system server classpath.

		var clcHost android.Paths
		var clcTarget []string
		for _, lib := range systemServerJars[:jarIndex] {
			clcHost = append(clcHost, SystemServerDexJarHostPath(ctx, lib))
			clcTarget = append(clcTarget, filepath.Join("/system/framework", lib+".jar"))
		}

		// Copy the system server jar to a predefined location where dex2oat will find it.
		dexPathHost := SystemServerDexJarHostPath(ctx, module.Name)
		rule.Command().Text("mkdir -p").Flag(filepath.Dir(dexPathHost.String()))
		rule.Command().Text("cp -f").Input(module.DexPath).Output(dexPathHost)

		checkSystemServerOrder(ctx, jarIndex)

		rule.Command().
			Text("class_loader_context_arg=--class-loader-context=PCL[" + strings.Join(clcHost.Strings(), ":") + "]").
			Implicits(clcHost).
			Text("stored_class_loader_context_arg=--stored-class-loader-context=PCL[" + strings.Join(clcTarget, ":") + "]")

	} else {
		// There are three categories of Java modules handled here:
		//
		// - Modules that have passed verify_uses_libraries check. They are AOT-compiled and
		//   expected to be loaded on device without CLC mismatch errors.
		//
		// - Modules that have failed the check in relaxed mode, so it didn't cause a build error.
		//   They are dexpreopted with "verify" filter and not AOT-compiled.
		//   TODO(b/132357300): ensure that CLC mismatch errors are ignored with "verify" filter.
		//
		// - Modules that didn't run the check. They are AOT-compiled, but it's unknown if they
		//   will have CLC mismatch errors on device (the check is disabled by default).
		//
		// TODO(b/132357300): enable the check by default and eliminate the last category, so that
		// no time/space is wasted on AOT-compiling modules that will fail CLC check on device.

		var manifestOrApk android.Path
		if module.ManifestPath.Valid() {
			// Ok, there is an XML manifest.
			manifestOrApk = module.ManifestPath.Path()
		} else if filepath.Ext(base) == ".apk" {
			// Ok, there is is an APK with the manifest inside.
			manifestOrApk = module.DexPath
		}

		// Generate command that saves target SDK version in a shell variable.
		if manifestOrApk == nil {
			// There is neither an XML manifest nor APK => nowhere to extract targetSdkVersion from.
			// Set the latest ("any") version: then construct_context will not add any compatibility
			// libraries (if this is incorrect, there will be a CLC mismatch and dexopt on device).
			rule.Command().Textf(`target_sdk_version=%d`, AnySdkVersion)
		} else {
			rule.Command().Text(`target_sdk_version="$(`).
				Tool(globalSoong.ManifestCheck).
				Flag("--extract-target-sdk-version").
				Input(manifestOrApk).
				FlagWithInput("--aapt ", globalSoong.Aapt).
				Text(`)"`)
		}

		// Generate command that saves host and target class loader context in shell variables.
		clc, paths := ComputeClassLoaderContext(module.ClassLoaderContexts)
		rule.Command().
			Text(`eval "$(`).Tool(globalSoong.ConstructContext).
			Text(` --target-sdk-version ${target_sdk_version}`).
			Text(clc).Implicits(paths).
			Text(`)"`)
	}

	// Devices that do not have a product partition use a symlink from /product to /system/product.
	// Because on-device dexopt will see dex locations starting with /product, we change the paths
	// to mimic this behavior.
	dexLocationArg := module.DexLocation
	if strings.HasPrefix(dexLocationArg, "/system/product/") {
		dexLocationArg = strings.TrimPrefix(dexLocationArg, "/system")
	}

	cmd := rule.Command().
		Text(`ANDROID_LOG_TAGS="*:e"`).
		Tool(globalSoong.Dex2oat).
		Flag("--avoid-storing-invocation").
		FlagWithOutput("--write-invocation-to=", invocationPath).ImplicitOutput(invocationPath).
		Flag("--runtime-arg").FlagWithArg("-Xms", global.Dex2oatXms).
		Flag("--runtime-arg").FlagWithArg("-Xmx", global.Dex2oatXmx).
		Flag("--runtime-arg").FlagWithInputList("-Xbootclasspath:", module.PreoptBootClassPathDexFiles, ":").
		Flag("--runtime-arg").FlagWithList("-Xbootclasspath-locations:", module.PreoptBootClassPathDexLocations, ":").
		Flag("${class_loader_context_arg}").
		Flag("${stored_class_loader_context_arg}").
		FlagWithArg("--boot-image=", strings.Join(module.DexPreoptImageLocationsOnHost, ":")).Implicits(module.DexPreoptImagesDeps[archIdx].Paths()).
		FlagWithInput("--dex-file=", module.DexPath).
		FlagWithArg("--dex-location=", dexLocationArg).
		FlagWithOutput("--oat-file=", odexPath).ImplicitOutput(vdexPath).
		// Pass an empty directory, dex2oat shouldn't be reading arbitrary files
		FlagWithArg("--android-root=", global.EmptyDirectory).
		FlagWithArg("--instruction-set=", arch.String()).
		FlagWithArg("--instruction-set-variant=", global.CpuVariant[arch]).
		FlagWithArg("--instruction-set-features=", global.InstructionSetFeatures[arch]).
		Flag("--no-generate-debug-info").
		Flag("--generate-build-id").
		Flag("--abort-on-hard-verifier-error").
		Flag("--force-determinism").
		FlagWithArg("--no-inline-from=", "core-oj.jar")

	var preoptFlags []string
	if len(module.PreoptFlags) > 0 {
		preoptFlags = module.PreoptFlags
	} else if len(global.PreoptFlags) > 0 {
		preoptFlags = global.PreoptFlags
	}

	if len(preoptFlags) > 0 {
		cmd.Text(strings.Join(preoptFlags, " "))
	}

	if module.UncompressedDex {
		cmd.FlagWithArg("--copy-dex-files=", "false")
	}

	if !android.PrefixInList(preoptFlags, "--compiler-filter=") {
		var compilerFilter string
		if global.SystemServerJars.ContainsJar(module.Name) {
			// Jars of system server, use the product option if it is set, speed otherwise.
			if global.SystemServerCompilerFilter != "" {
				compilerFilter = global.SystemServerCompilerFilter
			} else {
				compilerFilter = "speed"
			}
		} else if contains(global.SpeedApps, module.Name) || contains(global.SystemServerApps, module.Name) {
			// Apps loaded into system server, and apps the product default to being compiled with the
			// 'speed' compiler filter.
			compilerFilter = "speed"
		} else if profile != nil {
			// For non system server jars, use speed-profile when we have a profile.
			compilerFilter = "speed-profile"
		} else if global.DefaultCompilerFilter != "" {
			compilerFilter = global.DefaultCompilerFilter
		} else {
			compilerFilter = "quicken"
		}
		if module.EnforceUsesLibraries {
			// If the verify_uses_libraries check failed (in this case status file contains a
			// non-empty error message), then use "verify" compiler filter to avoid compiling any
			// code (it would be rejected on device because of a class loader context mismatch).
			cmd.Text("--compiler-filter=$(if test -s ").
				Input(module.EnforceUsesLibrariesStatusFile).
				Text(" ; then echo verify ; else echo " + compilerFilter + " ; fi)")
		} else {
			cmd.FlagWithArg("--compiler-filter=", compilerFilter)
		}
	}

	if generateDM {
		cmd.FlagWithArg("--copy-dex-files=", "false")
		dmPath := module.BuildPath.InSameDir(ctx, "generated.dm")
		dmInstalledPath := pathtools.ReplaceExtension(module.DexLocation, "dm")
		tmpPath := module.BuildPath.InSameDir(ctx, "primary.vdex")
		rule.Command().Text("cp -f").Input(vdexPath).Output(tmpPath)
		rule.Command().Tool(globalSoong.SoongZip).
			FlagWithArg("-L", "9").
			FlagWithOutput("-o", dmPath).
			Flag("-j").
			Input(tmpPath)
		rule.Install(dmPath, dmInstalledPath)
	}

	// By default, emit debug info.
	debugInfo := true
	if global.NoDebugInfo {
		// If the global setting suppresses mini-debug-info, disable it.
		debugInfo = false
	}

	// PRODUCT_SYSTEM_SERVER_DEBUG_INFO overrides WITH_DEXPREOPT_DEBUG_INFO.
	// PRODUCT_OTHER_JAVA_DEBUG_INFO overrides WITH_DEXPREOPT_DEBUG_INFO.
	if global.SystemServerJars.ContainsJar(module.Name) {
		if global.AlwaysSystemServerDebugInfo {
			debugInfo = true
		} else if global.NeverSystemServerDebugInfo {
			debugInfo = false
		}
	} else {
		if global.AlwaysOtherDebugInfo {
			debugInfo = true
		} else if global.NeverOtherDebugInfo {
			debugInfo = false
		}
	}

	// Never enable on eng.
	if global.IsEng {
		debugInfo = false
	}

	if debugInfo {
		cmd.Flag("--generate-mini-debug-info")
	} else {
		cmd.Flag("--no-generate-mini-debug-info")
	}

	// Set the compiler reason to 'prebuilt' to identify the oat files produced
	// during the build, as opposed to compiled on the device.
	cmd.FlagWithArg("--compilation-reason=", "prebuilt")

	if appImage {
		appImagePath := odexPath.ReplaceExtension(ctx, "art")
		appImageInstallPath := pathtools.ReplaceExtension(odexInstallPath, "art")
		cmd.FlagWithOutput("--app-image-file=", appImagePath).
			FlagWithArg("--image-format=", "lz4")
		if !global.DontResolveStartupStrings {
			cmd.FlagWithArg("--resolve-startup-const-strings=", "true")
		}
		rule.Install(appImagePath, appImageInstallPath)
	}

	if profile != nil {
		cmd.FlagWithInput("--profile-file=", profile)
	}

	rule.Install(odexPath, odexInstallPath)
	rule.Install(vdexPath, vdexInstallPath)
}

func shouldGenerateDM(module *ModuleConfig, global *GlobalConfig) bool {
	// Generating DM files only makes sense for verify, avoid doing for non verify compiler filter APKs.
	// No reason to use a dm file if the dex is already uncompressed.
	return global.GenerateDMFiles && !module.UncompressedDex &&
		contains(module.PreoptFlags, "--compiler-filter=verify")
}

func OdexOnSystemOtherByName(name string, dexLocation string, global *GlobalConfig) bool {
	if !global.HasSystemOther {
		return false
	}

	if global.SanitizeLite {
		return false
	}

	if contains(global.SpeedApps, name) || contains(global.SystemServerApps, name) {
		return false
	}

	for _, f := range global.PatternsOnSystemOther {
		if makefileMatch(filepath.Join(SystemPartition, f), dexLocation) {
			return true
		}
	}

	return false
}

func odexOnSystemOther(module *ModuleConfig, global *GlobalConfig) bool {
	return OdexOnSystemOtherByName(module.Name, module.DexLocation, global)
}

// PathToLocation converts .../system/framework/arm64/boot.art to .../system/framework/boot.art
func PathToLocation(path android.Path, arch android.ArchType) string {
	return PathStringToLocation(path.String(), arch)
}

// PathStringToLocation converts .../system/framework/arm64/boot.art to .../system/framework/boot.art
func PathStringToLocation(path string, arch android.ArchType) string {
	pathArch := filepath.Base(filepath.Dir(path))
	if pathArch != arch.String() {
		panic(fmt.Errorf("last directory in %q must be %q", path, arch.String()))
	}
	return filepath.Join(filepath.Dir(filepath.Dir(path)), filepath.Base(path))
}

func makefileMatch(pattern, s string) bool {
	percent := strings.IndexByte(pattern, '%')
	switch percent {
	case -1:
		return pattern == s
	case len(pattern) - 1:
		return strings.HasPrefix(s, pattern[:len(pattern)-1])
	default:
		panic(fmt.Errorf("unsupported makefile pattern %q", pattern))
	}
}

var nonUpdatableSystemServerJarsKey = android.NewOnceKey("nonUpdatableSystemServerJars")

// TODO: eliminate the superficial global config parameter by moving global config definition
// from java subpackage to dexpreopt.
func NonUpdatableSystemServerJars(ctx android.PathContext, global *GlobalConfig) []string {
	return ctx.Config().Once(nonUpdatableSystemServerJarsKey, func() interface{} {
		return android.RemoveListFromList(global.SystemServerJars.CopyOfJars(), global.UpdatableSystemServerJars.CopyOfJars())
	}).([]string)
}

// A predefined location for the system server dex jars. This is needed in order to generate
// class loader context for dex2oat, as the path to the jar in the Soong module may be unknown
// at that time (Soong processes the jars in dependency order, which may be different from the
// the system server classpath order).
func SystemServerDexJarHostPath(ctx android.PathContext, jar string) android.OutputPath {
	if DexpreoptRunningInSoong {
		// Soong module, just use the default output directory $OUT/soong.
		return android.PathForOutput(ctx, "system_server_dexjars", jar+".jar")
	} else {
		// Make module, default output directory is $OUT (passed via the "null config" created
		// by dexpreopt_gen). Append Soong subdirectory to match Soong module paths.
		return android.PathForOutput(ctx, "soong", "system_server_dexjars", jar+".jar")
	}
}

// Check the order of jars on the system server classpath and give a warning/error if a jar precedes
// one of its dependencies. This is not an error, but a missed optimization, as dexpreopt won't
// have the dependency jar in the class loader context, and it won't be able to resolve any
// references to its classes and methods.
func checkSystemServerOrder(ctx android.PathContext, jarIndex int) {
	mctx, isModule := ctx.(android.ModuleContext)
	if isModule {
		config := GetGlobalConfig(ctx)
		jars := NonUpdatableSystemServerJars(ctx, config)
		mctx.WalkDeps(func(dep android.Module, parent android.Module) bool {
			depIndex := android.IndexList(dep.Name(), jars)
			if jarIndex < depIndex && !config.BrokenSuboptimalOrderOfSystemServerJars {
				jar := jars[jarIndex]
				dep := jars[depIndex]
				mctx.ModuleErrorf("non-optimal order of jars on the system server classpath:"+
					" '%s' precedes its dependency '%s', so dexpreopt is unable to resolve any"+
					" references from '%s' to '%s'.\n", jar, dep, jar, dep)
			}
			return true
		})
	}
}

// Returns path to a file containing the reult of verify_uses_libraries check (empty if the check
// has succeeded, or an error message if it failed).
func UsesLibrariesStatusFile(ctx android.ModuleContext) android.WritablePath {
	return android.PathForModuleOut(ctx, "enforce_uses_libraries.status")
}

func contains(l []string, s string) bool {
	for _, e := range l {
		if e == s {
			return true
		}
	}
	return false
}

var copyOf = android.CopyOf
