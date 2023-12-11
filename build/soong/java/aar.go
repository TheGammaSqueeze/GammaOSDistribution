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

package java

import (
	"fmt"
	"path/filepath"
	"strconv"
	"strings"

	"android/soong/android"
	"android/soong/dexpreopt"

	"github.com/google/blueprint"
	"github.com/google/blueprint/proptools"
)

type AndroidLibraryDependency interface {
	ExportPackage() android.Path
	ExportedProguardFlagFiles() android.Paths
	ExportedRRODirs() []rroDir
	ExportedStaticPackages() android.Paths
	ExportedManifests() android.Paths
	ExportedAssets() android.OptionalPath
	SetRROEnforcedForDependent(enforce bool)
	IsRROEnforced(ctx android.BaseModuleContext) bool
}

func init() {
	RegisterAARBuildComponents(android.InitRegistrationContext)
}

func RegisterAARBuildComponents(ctx android.RegistrationContext) {
	ctx.RegisterModuleType("android_library_import", AARImportFactory)
	ctx.RegisterModuleType("android_library", AndroidLibraryFactory)
	ctx.PostDepsMutators(func(ctx android.RegisterMutatorsContext) {
		ctx.TopDown("propagate_rro_enforcement", propagateRROEnforcementMutator).Parallel()
	})
}

//
// AAR (android library)
//

type androidLibraryProperties struct {
	BuildAAR bool `blueprint:"mutated"`
}

type aaptProperties struct {
	// flags passed to aapt when creating the apk
	Aaptflags []string

	// include all resource configurations, not just the product-configured
	// ones.
	Aapt_include_all_resources *bool

	// list of directories relative to the Blueprints file containing assets.
	// Defaults to ["assets"] if a directory called assets exists.  Set to []
	// to disable the default.
	Asset_dirs []string

	// list of directories relative to the Blueprints file containing
	// Android resources.  Defaults to ["res"] if a directory called res exists.
	// Set to [] to disable the default.
	Resource_dirs []string

	// list of zip files containing Android resources.
	Resource_zips []string `android:"path"`

	// path to AndroidManifest.xml.  If unset, defaults to "AndroidManifest.xml".
	Manifest *string `android:"path"`

	// paths to additional manifest files to merge with main manifest.
	Additional_manifests []string `android:"path"`

	// do not include AndroidManifest from dependent libraries
	Dont_merge_manifests *bool

	// true if RRO is enforced for any of the dependent modules
	RROEnforcedForDependent bool `blueprint:"mutated"`
}

type aapt struct {
	aaptSrcJar              android.Path
	exportPackage           android.Path
	manifestPath            android.Path
	transitiveManifestPaths android.Paths
	proguardOptionsFile     android.Path
	rroDirs                 []rroDir
	rTxt                    android.Path
	extraAaptPackagesFile   android.Path
	mergedManifestFile      android.Path
	noticeFile              android.OptionalPath
	assetPackage            android.OptionalPath
	isLibrary               bool
	useEmbeddedNativeLibs   bool
	useEmbeddedDex          bool
	usesNonSdkApis          bool
	hasNoCode               bool
	LoggingParent           string
	resourceFiles           android.Paths

	splitNames []string
	splits     []split

	aaptProperties aaptProperties
}

type split struct {
	name   string
	suffix string
	path   android.Path
}

// Propagate RRO enforcement flag to static lib dependencies transitively.
func propagateRROEnforcementMutator(ctx android.TopDownMutatorContext) {
	m := ctx.Module()
	if d, ok := m.(AndroidLibraryDependency); ok && d.IsRROEnforced(ctx) {
		ctx.VisitDirectDepsWithTag(staticLibTag, func(d android.Module) {
			if a, ok := d.(AndroidLibraryDependency); ok {
				a.SetRROEnforcedForDependent(true)
			}
		})
	}
}

func (a *aapt) ExportPackage() android.Path {
	return a.exportPackage
}

func (a *aapt) ExportedRRODirs() []rroDir {
	return a.rroDirs
}

func (a *aapt) ExportedManifests() android.Paths {
	return a.transitiveManifestPaths
}

func (a *aapt) ExportedAssets() android.OptionalPath {
	return a.assetPackage
}

func (a *aapt) SetRROEnforcedForDependent(enforce bool) {
	a.aaptProperties.RROEnforcedForDependent = enforce
}

func (a *aapt) IsRROEnforced(ctx android.BaseModuleContext) bool {
	// True if RRO is enforced for this module or...
	return ctx.Config().EnforceRROForModule(ctx.ModuleName()) ||
		// if RRO is enforced for any of its dependents.
		a.aaptProperties.RROEnforcedForDependent
}

func (a *aapt) aapt2Flags(ctx android.ModuleContext, sdkContext android.SdkContext,
	manifestPath android.Path) (compileFlags, linkFlags []string, linkDeps android.Paths,
	resDirs, overlayDirs []globbedResourceDir, rroDirs []rroDir, resZips android.Paths) {

	hasVersionCode := android.PrefixInList(a.aaptProperties.Aaptflags, "--version-code")
	hasVersionName := android.PrefixInList(a.aaptProperties.Aaptflags, "--version-name")

	// Flags specified in Android.bp
	linkFlags = append(linkFlags, a.aaptProperties.Aaptflags...)

	linkFlags = append(linkFlags, "--no-static-lib-packages")

	// Find implicit or explicit asset and resource dirs
	assetDirs := android.PathsWithOptionalDefaultForModuleSrc(ctx, a.aaptProperties.Asset_dirs, "assets")
	resourceDirs := android.PathsWithOptionalDefaultForModuleSrc(ctx, a.aaptProperties.Resource_dirs, "res")
	resourceZips := android.PathsForModuleSrc(ctx, a.aaptProperties.Resource_zips)

	// Glob directories into lists of paths
	for _, dir := range resourceDirs {
		resDirs = append(resDirs, globbedResourceDir{
			dir:   dir,
			files: androidResourceGlob(ctx, dir),
		})
		resOverlayDirs, resRRODirs := overlayResourceGlob(ctx, a, dir)
		overlayDirs = append(overlayDirs, resOverlayDirs...)
		rroDirs = append(rroDirs, resRRODirs...)
	}

	var assetDeps android.Paths
	for i, dir := range assetDirs {
		// Add a dependency on every file in the asset directory.  This ensures the aapt2
		// rule will be rerun if one of the files in the asset directory is modified.
		assetDeps = append(assetDeps, androidResourceGlob(ctx, dir)...)

		// Add a dependency on a file that contains a list of all the files in the asset directory.
		// This ensures the aapt2 rule will be run if a file is removed from the asset directory,
		// or a file is added whose timestamp is older than the output of aapt2.
		assetFileListFile := android.PathForModuleOut(ctx, "asset_dir_globs", strconv.Itoa(i)+".glob")
		androidResourceGlobList(ctx, dir, assetFileListFile)
		assetDeps = append(assetDeps, assetFileListFile)
	}

	assetDirStrings := assetDirs.Strings()
	if a.noticeFile.Valid() {
		assetDirStrings = append(assetDirStrings, filepath.Dir(a.noticeFile.Path().String()))
		assetDeps = append(assetDeps, a.noticeFile.Path())
	}

	linkFlags = append(linkFlags, "--manifest "+manifestPath.String())
	linkDeps = append(linkDeps, manifestPath)

	linkFlags = append(linkFlags, android.JoinWithPrefix(assetDirStrings, "-A "))
	linkDeps = append(linkDeps, assetDeps...)

	// SDK version flags
	minSdkVersion, err := sdkContext.MinSdkVersion(ctx).EffectiveVersionString(ctx)
	if err != nil {
		ctx.ModuleErrorf("invalid minSdkVersion: %s", err)
	}

	linkFlags = append(linkFlags, "--min-sdk-version "+minSdkVersion)
	linkFlags = append(linkFlags, "--target-sdk-version "+minSdkVersion)

	// Version code
	if !hasVersionCode {
		linkFlags = append(linkFlags, "--version-code", ctx.Config().PlatformSdkVersion().String())
	}

	if !hasVersionName {
		var versionName string
		if ctx.ModuleName() == "framework-res" || ctx.ModuleName() == "org.lineageos.platform-res" {
			// Some builds set AppsDefaultVersionName() to include the build number ("O-123456").  aapt2 copies the
			// version name of framework-res into app manifests as compileSdkVersionCodename, which confuses things
			// if it contains the build number.  Use the PlatformVersionName instead.
			versionName = ctx.Config().PlatformVersionName()
		} else {
			versionName = ctx.Config().AppsDefaultVersionName()
		}
		versionName = proptools.NinjaEscape(versionName)
		linkFlags = append(linkFlags, "--version-name ", versionName)
	}

	linkFlags, compileFlags = android.FilterList(linkFlags, []string{"--legacy"})

	// Always set --pseudo-localize, it will be stripped out later for release
	// builds that don't want it.
	compileFlags = append(compileFlags, "--pseudo-localize")

	return compileFlags, linkFlags, linkDeps, resDirs, overlayDirs, rroDirs, resourceZips
}

func (a *aapt) deps(ctx android.BottomUpMutatorContext, sdkDep sdkDep) {
	if sdkDep.frameworkResModule != "" {
		ctx.AddVariationDependencies(nil, frameworkResTag, sdkDep.frameworkResModule)
	}
	if sdkDep.lineageResModule != "" {
		ctx.AddVariationDependencies(nil, lineageResTag, sdkDep.lineageResModule)
	}
}

var extractAssetsRule = pctx.AndroidStaticRule("extractAssets",
	blueprint.RuleParams{
		Command:     `${config.Zip2ZipCmd} -i ${in} -o ${out} "assets/**/*"`,
		CommandDeps: []string{"${config.Zip2ZipCmd}"},
	})

func (a *aapt) buildActions(ctx android.ModuleContext, sdkContext android.SdkContext,
	classLoaderContexts dexpreopt.ClassLoaderContextMap, extraLinkFlags ...string) {

	transitiveStaticLibs, transitiveStaticLibManifests, staticRRODirs, assetPackages, libDeps, libFlags :=
		aaptLibs(ctx, sdkContext, classLoaderContexts)

	// App manifest file
	manifestFile := proptools.StringDefault(a.aaptProperties.Manifest, "AndroidManifest.xml")
	manifestSrcPath := android.PathForModuleSrc(ctx, manifestFile)

	manifestPath := manifestFixer(ctx, manifestSrcPath, sdkContext, classLoaderContexts,
		a.isLibrary, a.useEmbeddedNativeLibs, a.usesNonSdkApis, a.useEmbeddedDex, a.hasNoCode,
		a.LoggingParent)

	// Add additional manifest files to transitive manifests.
	additionalManifests := android.PathsForModuleSrc(ctx, a.aaptProperties.Additional_manifests)
	a.transitiveManifestPaths = append(android.Paths{manifestPath}, additionalManifests...)
	a.transitiveManifestPaths = append(a.transitiveManifestPaths, transitiveStaticLibManifests...)

	if len(a.transitiveManifestPaths) > 1 && !Bool(a.aaptProperties.Dont_merge_manifests) {
		a.mergedManifestFile = manifestMerger(ctx, a.transitiveManifestPaths[0], a.transitiveManifestPaths[1:], a.isLibrary)
		if !a.isLibrary {
			// Only use the merged manifest for applications.  For libraries, the transitive closure of manifests
			// will be propagated to the final application and merged there.  The merged manifest for libraries is
			// only passed to Make, which can't handle transitive dependencies.
			manifestPath = a.mergedManifestFile
		}
	} else {
		a.mergedManifestFile = manifestPath
	}

	compileFlags, linkFlags, linkDeps, resDirs, overlayDirs, rroDirs, resZips := a.aapt2Flags(ctx, sdkContext, manifestPath)

	rroDirs = append(rroDirs, staticRRODirs...)
	linkFlags = append(linkFlags, libFlags...)
	linkDeps = append(linkDeps, libDeps...)
	linkFlags = append(linkFlags, extraLinkFlags...)
	if a.isLibrary {
		linkFlags = append(linkFlags, "--static-lib")
	}

	packageRes := android.PathForModuleOut(ctx, "package-res.apk")
	// the subdir "android" is required to be filtered by package names
	srcJar := android.PathForModuleGen(ctx, "android", "R.srcjar")
	proguardOptionsFile := android.PathForModuleGen(ctx, "proguard.options")
	rTxt := android.PathForModuleOut(ctx, "R.txt")
	// This file isn't used by Soong, but is generated for exporting
	extraPackages := android.PathForModuleOut(ctx, "extra_packages")

	var compiledResDirs []android.Paths
	for _, dir := range resDirs {
		a.resourceFiles = append(a.resourceFiles, dir.files...)
		compiledResDirs = append(compiledResDirs, aapt2Compile(ctx, dir.dir, dir.files, compileFlags).Paths())
	}

	for i, zip := range resZips {
		flata := android.PathForModuleOut(ctx, fmt.Sprintf("reszip.%d.flata", i))
		aapt2CompileZip(ctx, flata, zip, "", compileFlags)
		compiledResDirs = append(compiledResDirs, android.Paths{flata})
	}

	var compiledRes, compiledOverlay android.Paths

	compiledOverlay = append(compiledOverlay, transitiveStaticLibs...)

	if len(transitiveStaticLibs) > 0 {
		// If we are using static android libraries, every source file becomes an overlay.
		// This is to emulate old AAPT behavior which simulated library support.
		for _, compiledResDir := range compiledResDirs {
			compiledOverlay = append(compiledOverlay, compiledResDir...)
		}
	} else if a.isLibrary {
		// Otherwise, for a static library we treat all the resources equally with no overlay.
		for _, compiledResDir := range compiledResDirs {
			compiledRes = append(compiledRes, compiledResDir...)
		}
	} else if len(compiledResDirs) > 0 {
		// Without static libraries, the first directory is our directory, which can then be
		// overlaid by the rest.
		compiledRes = append(compiledRes, compiledResDirs[0]...)
		for _, compiledResDir := range compiledResDirs[1:] {
			compiledOverlay = append(compiledOverlay, compiledResDir...)
		}
	}

	for _, dir := range overlayDirs {
		compiledOverlay = append(compiledOverlay, aapt2Compile(ctx, dir.dir, dir.files, compileFlags).Paths()...)
	}

	var splitPackages android.WritablePaths
	var splits []split

	for _, s := range a.splitNames {
		suffix := strings.Replace(s, ",", "_", -1)
		path := android.PathForModuleOut(ctx, "package_"+suffix+".apk")
		linkFlags = append(linkFlags, "--split", path.String()+":"+s)
		splitPackages = append(splitPackages, path)
		splits = append(splits, split{
			name:   s,
			suffix: suffix,
			path:   path,
		})
	}

	aapt2Link(ctx, packageRes, srcJar, proguardOptionsFile, rTxt, extraPackages,
		linkFlags, linkDeps, compiledRes, compiledOverlay, assetPackages, splitPackages)

	// Extract assets from the resource package output so that they can be used later in aapt2link
	// for modules that depend on this one.
	if android.PrefixInList(linkFlags, "-A ") || len(assetPackages) > 0 {
		assets := android.PathForModuleOut(ctx, "assets.zip")
		ctx.Build(pctx, android.BuildParams{
			Rule:        extractAssetsRule,
			Input:       packageRes,
			Output:      assets,
			Description: "extract assets from built resource file",
		})
		a.assetPackage = android.OptionalPathForPath(assets)
	}

	a.aaptSrcJar = srcJar
	a.exportPackage = packageRes
	a.manifestPath = manifestPath
	a.proguardOptionsFile = proguardOptionsFile
	a.rroDirs = rroDirs
	a.extraAaptPackagesFile = extraPackages
	a.rTxt = rTxt
	a.splits = splits
}

// aaptLibs collects libraries from dependencies and sdk_version and converts them into paths
func aaptLibs(ctx android.ModuleContext, sdkContext android.SdkContext, classLoaderContexts dexpreopt.ClassLoaderContextMap) (
	transitiveStaticLibs, transitiveStaticLibManifests android.Paths, staticRRODirs []rroDir, assets, deps android.Paths, flags []string) {

	var sharedLibs android.Paths

	if classLoaderContexts == nil {
		// Not all callers need to compute class loader context, those who don't just pass nil.
		// Create a temporary class loader context here (it will be computed, but not used).
		classLoaderContexts = make(dexpreopt.ClassLoaderContextMap)
	}

	sdkDep := decodeSdkDep(ctx, sdkContext)
	if sdkDep.useFiles {
		sharedLibs = append(sharedLibs, sdkDep.jars...)
	}

	ctx.VisitDirectDeps(func(module android.Module) {
		depTag := ctx.OtherModuleDependencyTag(module)

		var exportPackage android.Path
		aarDep, _ := module.(AndroidLibraryDependency)
		if aarDep != nil {
			exportPackage = aarDep.ExportPackage()
		}

		switch depTag {
		case instrumentationForTag:
			// Nothing, instrumentationForTag is treated as libTag for javac but not for aapt2.
		case libTag:
			if exportPackage != nil {
				sharedLibs = append(sharedLibs, exportPackage)
			}
		case frameworkResTag, lineageResTag:
			if exportPackage != nil {
				sharedLibs = append(sharedLibs, exportPackage)
			}
		case staticLibTag:
			if exportPackage != nil {
				transitiveStaticLibs = append(transitiveStaticLibs, aarDep.ExportedStaticPackages()...)
				transitiveStaticLibs = append(transitiveStaticLibs, exportPackage)
				transitiveStaticLibManifests = append(transitiveStaticLibManifests, aarDep.ExportedManifests()...)
				if aarDep.ExportedAssets().Valid() {
					assets = append(assets, aarDep.ExportedAssets().Path())
				}

			outer:
				for _, d := range aarDep.ExportedRRODirs() {
					for _, e := range staticRRODirs {
						if d.path == e.path {
							continue outer
						}
					}
					staticRRODirs = append(staticRRODirs, d)
				}
			}
		}

		addCLCFromDep(ctx, module, classLoaderContexts)
	})

	deps = append(deps, sharedLibs...)
	deps = append(deps, transitiveStaticLibs...)

	if len(transitiveStaticLibs) > 0 {
		flags = append(flags, "--auto-add-overlay")
	}

	for _, sharedLib := range sharedLibs {
		flags = append(flags, "-I "+sharedLib.String())
	}

	transitiveStaticLibs = android.FirstUniquePaths(transitiveStaticLibs)
	transitiveStaticLibManifests = android.FirstUniquePaths(transitiveStaticLibManifests)

	return transitiveStaticLibs, transitiveStaticLibManifests, staticRRODirs, assets, deps, flags
}

type AndroidLibrary struct {
	Library
	aapt

	androidLibraryProperties androidLibraryProperties

	aarFile android.WritablePath

	exportedProguardFlagFiles android.Paths
	exportedStaticPackages    android.Paths
}

var _ android.OutputFileProducer = (*AndroidLibrary)(nil)

// For OutputFileProducer interface
func (a *AndroidLibrary) OutputFiles(tag string) (android.Paths, error) {
	switch tag {
	case ".aar":
		return []android.Path{a.aarFile}, nil
	default:
		return a.Library.OutputFiles(tag)
	}
}

func (a *AndroidLibrary) ExportedProguardFlagFiles() android.Paths {
	return a.exportedProguardFlagFiles
}

func (a *AndroidLibrary) ExportedStaticPackages() android.Paths {
	return a.exportedStaticPackages
}

var _ AndroidLibraryDependency = (*AndroidLibrary)(nil)

func (a *AndroidLibrary) DepsMutator(ctx android.BottomUpMutatorContext) {
	a.Module.deps(ctx)
	sdkDep := decodeSdkDep(ctx, android.SdkContext(a))
	if sdkDep.hasFrameworkLibs() {
		a.aapt.deps(ctx, sdkDep)
	}
}

func (a *AndroidLibrary) GenerateAndroidBuildActions(ctx android.ModuleContext) {
	a.aapt.isLibrary = true
	a.classLoaderContexts = make(dexpreopt.ClassLoaderContextMap)
	a.aapt.buildActions(ctx, android.SdkContext(a), a.classLoaderContexts)

	a.hideApexVariantFromMake = !ctx.Provider(android.ApexInfoProvider).(android.ApexInfo).IsForPlatform()

	ctx.CheckbuildFile(a.proguardOptionsFile)
	ctx.CheckbuildFile(a.exportPackage)
	ctx.CheckbuildFile(a.aaptSrcJar)

	// apps manifests are handled by aapt, don't let Module see them
	a.properties.Manifest = nil

	a.linter.mergedManifest = a.aapt.mergedManifestFile
	a.linter.manifest = a.aapt.manifestPath
	a.linter.resources = a.aapt.resourceFiles

	a.Module.extraProguardFlagFiles = append(a.Module.extraProguardFlagFiles,
		a.proguardOptionsFile)

	a.Module.compile(ctx, a.aaptSrcJar)

	a.aarFile = android.PathForModuleOut(ctx, ctx.ModuleName()+".aar")
	var res android.Paths
	if a.androidLibraryProperties.BuildAAR {
		BuildAAR(ctx, a.aarFile, a.outputFile, a.manifestPath, a.rTxt, res)
		ctx.CheckbuildFile(a.aarFile)
	}

	a.exportedProguardFlagFiles = append(a.exportedProguardFlagFiles,
		android.PathsForModuleSrc(ctx, a.dexProperties.Optimize.Proguard_flags_files)...)
	ctx.VisitDirectDeps(func(m android.Module) {
		if lib, ok := m.(AndroidLibraryDependency); ok && ctx.OtherModuleDependencyTag(m) == staticLibTag {
			a.exportedProguardFlagFiles = append(a.exportedProguardFlagFiles, lib.ExportedProguardFlagFiles()...)
			a.exportedStaticPackages = append(a.exportedStaticPackages, lib.ExportPackage())
			a.exportedStaticPackages = append(a.exportedStaticPackages, lib.ExportedStaticPackages()...)
		}
	})

	a.exportedProguardFlagFiles = android.FirstUniquePaths(a.exportedProguardFlagFiles)
	a.exportedStaticPackages = android.FirstUniquePaths(a.exportedStaticPackages)
}

// android_library builds and links sources into a `.jar` file for the device along with Android resources.
//
// An android_library has a single variant that produces a `.jar` file containing `.class` files that were
// compiled against the device bootclasspath, along with a `package-res.apk` file containing  Android resources compiled
// with aapt2.  This module is not suitable for installing on a device, but can be used as a `static_libs` dependency of
// an android_app module.
func AndroidLibraryFactory() android.Module {
	module := &AndroidLibrary{}

	module.Module.addHostAndDeviceProperties()
	module.AddProperties(
		&module.aaptProperties,
		&module.androidLibraryProperties)

	module.androidLibraryProperties.BuildAAR = true
	module.Module.linter.library = true

	android.InitApexModule(module)
	InitJavaModule(module, android.DeviceSupported)
	return module
}

//
// AAR (android library) prebuilts
//

type AARImportProperties struct {
	Aars []string `android:"path"`

	Sdk_version     *string
	Min_sdk_version *string

	Static_libs []string
	Libs        []string

	// if set to true, run Jetifier against .aar file. Defaults to false.
	Jetifier *bool
}

type AARImport struct {
	android.ModuleBase
	android.DefaultableModuleBase
	android.ApexModuleBase
	prebuilt android.Prebuilt

	// Functionality common to Module and Import.
	embeddableInModuleAndImport

	properties AARImportProperties

	classpathFile         android.WritablePath
	proguardFlags         android.WritablePath
	exportPackage         android.WritablePath
	extraAaptPackagesFile android.WritablePath
	manifest              android.WritablePath

	exportedStaticPackages android.Paths

	hideApexVariantFromMake bool

	aarPath android.Path

	sdkVersion    android.SdkSpec
	minSdkVersion android.SdkSpec
}

var _ android.OutputFileProducer = (*AARImport)(nil)

// For OutputFileProducer interface
func (a *AARImport) OutputFiles(tag string) (android.Paths, error) {
	switch tag {
	case ".aar":
		return []android.Path{a.aarPath}, nil
	case "":
		return []android.Path{a.classpathFile}, nil
	default:
		return nil, fmt.Errorf("unsupported module reference tag %q", tag)
	}
}

func (a *AARImport) SdkVersion(ctx android.EarlyModuleContext) android.SdkSpec {
	return android.SdkSpecFrom(ctx, String(a.properties.Sdk_version))
}

func (a *AARImport) SystemModules() string {
	return ""
}

func (a *AARImport) MinSdkVersion(ctx android.EarlyModuleContext) android.SdkSpec {
	if a.properties.Min_sdk_version != nil {
		return android.SdkSpecFrom(ctx, *a.properties.Min_sdk_version)
	}
	return a.SdkVersion(ctx)
}

func (a *AARImport) TargetSdkVersion(ctx android.EarlyModuleContext) android.SdkSpec {
	return a.SdkVersion(ctx)
}

func (a *AARImport) javaVersion() string {
	return ""
}

var _ AndroidLibraryDependency = (*AARImport)(nil)

func (a *AARImport) ExportPackage() android.Path {
	return a.exportPackage
}

func (a *AARImport) ExportedProguardFlagFiles() android.Paths {
	return android.Paths{a.proguardFlags}
}

func (a *AARImport) ExportedRRODirs() []rroDir {
	return nil
}

func (a *AARImport) ExportedStaticPackages() android.Paths {
	return a.exportedStaticPackages
}

func (a *AARImport) ExportedManifests() android.Paths {
	return android.Paths{a.manifest}
}

// TODO(jungjw): Decide whether we want to implement this.
func (a *AARImport) ExportedAssets() android.OptionalPath {
	return android.OptionalPath{}
}

// RRO enforcement is not available on aar_import since its RRO dirs are not
// exported.
func (a *AARImport) SetRROEnforcedForDependent(enforce bool) {
}

// RRO enforcement is not available on aar_import since its RRO dirs are not
// exported.
func (a *AARImport) IsRROEnforced(ctx android.BaseModuleContext) bool {
	return false
}

func (a *AARImport) Prebuilt() *android.Prebuilt {
	return &a.prebuilt
}

func (a *AARImport) Name() string {
	return a.prebuilt.Name(a.ModuleBase.Name())
}

func (a *AARImport) JacocoReportClassesFile() android.Path {
	return nil
}

func (a *AARImport) DepsMutator(ctx android.BottomUpMutatorContext) {
	if !ctx.Config().AlwaysUsePrebuiltSdks() {
		sdkDep := decodeSdkDep(ctx, android.SdkContext(a))
		if sdkDep.useModule && sdkDep.frameworkResModule != "" {
			ctx.AddVariationDependencies(nil, frameworkResTag, sdkDep.frameworkResModule)
		}
		if sdkDep.useModule && sdkDep.lineageResModule != "" {
			ctx.AddVariationDependencies(nil, lineageResTag, sdkDep.lineageResModule)
		}
	}

	ctx.AddVariationDependencies(nil, libTag, a.properties.Libs...)
	ctx.AddVariationDependencies(nil, staticLibTag, a.properties.Static_libs...)
}

// Unzip an AAR into its constituent files and directories.  Any files in Outputs that don't exist in the AAR will be
// touched to create an empty file. The res directory is not extracted, as it will be extracted in its own rule.
var unzipAAR = pctx.AndroidStaticRule("unzipAAR",
	blueprint.RuleParams{
		Command: `rm -rf $outDir && mkdir -p $outDir && ` +
			`unzip -qoDD -d $outDir $in && rm -rf $outDir/res && touch $out && ` +
			`${config.MergeZipsCmd} $combinedClassesJar $$(ls $outDir/classes.jar 2> /dev/null) $$(ls $outDir/libs/*.jar 2> /dev/null)`,
		CommandDeps: []string{"${config.MergeZipsCmd}"},
	},
	"outDir", "combinedClassesJar")

func (a *AARImport) GenerateAndroidBuildActions(ctx android.ModuleContext) {
	if len(a.properties.Aars) != 1 {
		ctx.PropertyErrorf("aars", "exactly one aar is required")
		return
	}

	a.sdkVersion = a.SdkVersion(ctx)
	a.minSdkVersion = a.MinSdkVersion(ctx)

	a.hideApexVariantFromMake = !ctx.Provider(android.ApexInfoProvider).(android.ApexInfo).IsForPlatform()

	aarName := ctx.ModuleName() + ".aar"
	a.aarPath = android.PathForModuleSrc(ctx, a.properties.Aars[0])

	if Bool(a.properties.Jetifier) {
		inputFile := a.aarPath
		a.aarPath = android.PathForModuleOut(ctx, "jetifier", aarName)
		TransformJetifier(ctx, a.aarPath.(android.WritablePath), inputFile)
	}

	extractedAARDir := android.PathForModuleOut(ctx, "aar")
	a.classpathFile = extractedAARDir.Join(ctx, "classes-combined.jar")
	a.proguardFlags = extractedAARDir.Join(ctx, "proguard.txt")
	a.manifest = extractedAARDir.Join(ctx, "AndroidManifest.xml")

	ctx.Build(pctx, android.BuildParams{
		Rule:        unzipAAR,
		Input:       a.aarPath,
		Outputs:     android.WritablePaths{a.classpathFile, a.proguardFlags, a.manifest},
		Description: "unzip AAR",
		Args: map[string]string{
			"outDir":             extractedAARDir.String(),
			"combinedClassesJar": a.classpathFile.String(),
		},
	})

	// Always set --pseudo-localize, it will be stripped out later for release
	// builds that don't want it.
	compileFlags := []string{"--pseudo-localize"}
	compiledResDir := android.PathForModuleOut(ctx, "flat-res")
	flata := compiledResDir.Join(ctx, "gen_res.flata")
	aapt2CompileZip(ctx, flata, a.aarPath, "res", compileFlags)

	a.exportPackage = android.PathForModuleOut(ctx, "package-res.apk")
	// the subdir "android" is required to be filtered by package names
	srcJar := android.PathForModuleGen(ctx, "android", "R.srcjar")
	proguardOptionsFile := android.PathForModuleGen(ctx, "proguard.options")
	rTxt := android.PathForModuleOut(ctx, "R.txt")
	a.extraAaptPackagesFile = android.PathForModuleOut(ctx, "extra_packages")

	var linkDeps android.Paths

	linkFlags := []string{
		"--static-lib",
		"--no-static-lib-packages",
		"--auto-add-overlay",
	}

	linkFlags = append(linkFlags, "--manifest "+a.manifest.String())
	linkDeps = append(linkDeps, a.manifest)

	transitiveStaticLibs, staticLibManifests, staticRRODirs, transitiveAssets, libDeps, libFlags :=
		aaptLibs(ctx, android.SdkContext(a), nil)

	_ = staticLibManifests
	_ = staticRRODirs

	linkDeps = append(linkDeps, libDeps...)
	linkFlags = append(linkFlags, libFlags...)

	overlayRes := append(android.Paths{flata}, transitiveStaticLibs...)

	aapt2Link(ctx, a.exportPackage, srcJar, proguardOptionsFile, rTxt, a.extraAaptPackagesFile,
		linkFlags, linkDeps, nil, overlayRes, transitiveAssets, nil)

	ctx.SetProvider(JavaInfoProvider, JavaInfo{
		HeaderJars:                     android.PathsIfNonNil(a.classpathFile),
		ImplementationAndResourcesJars: android.PathsIfNonNil(a.classpathFile),
		ImplementationJars:             android.PathsIfNonNil(a.classpathFile),
	})
}

func (a *AARImport) HeaderJars() android.Paths {
	return android.Paths{a.classpathFile}
}

func (a *AARImport) ImplementationAndResourcesJars() android.Paths {
	return android.Paths{a.classpathFile}
}

func (a *AARImport) DexJarBuildPath() android.Path {
	return nil
}

func (a *AARImport) DexJarInstallPath() android.Path {
	return nil
}

func (a *AARImport) ClassLoaderContexts() dexpreopt.ClassLoaderContextMap {
	return nil
}

var _ android.ApexModule = (*AARImport)(nil)

// Implements android.ApexModule
func (a *AARImport) DepIsInSameApex(ctx android.BaseModuleContext, dep android.Module) bool {
	return a.depIsInSameApex(ctx, dep)
}

// Implements android.ApexModule
func (g *AARImport) ShouldSupportSdkVersion(ctx android.BaseModuleContext,
	sdkVersion android.ApiLevel) error {
	return nil
}

var _ android.PrebuiltInterface = (*Import)(nil)

// android_library_import imports an `.aar` file into the build graph as if it was built with android_library.
//
// This module is not suitable for installing on a device, but can be used as a `static_libs` dependency of
// an android_app module.
func AARImportFactory() android.Module {
	module := &AARImport{}

	module.AddProperties(&module.properties)

	android.InitPrebuiltModule(module, &module.properties.Aars)
	android.InitApexModule(module)
	InitJavaModule(module, android.DeviceSupported)
	return module
}
