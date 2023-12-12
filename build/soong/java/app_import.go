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

package java

// This file contains the module implementations for android_app_import and android_test_import.

import (
	"reflect"

	"github.com/google/blueprint/proptools"

	"android/soong/android"
)

func init() {
	RegisterAppImportBuildComponents(android.InitRegistrationContext)

	initAndroidAppImportVariantGroupTypes()
}

func RegisterAppImportBuildComponents(ctx android.RegistrationContext) {
	ctx.RegisterModuleType("android_app_import", AndroidAppImportFactory)
	ctx.RegisterModuleType("android_test_import", AndroidTestImportFactory)
}

type AndroidAppImport struct {
	android.ModuleBase
	android.DefaultableModuleBase
	android.ApexModuleBase
	prebuilt android.Prebuilt

	properties   AndroidAppImportProperties
	dpiVariants  interface{}
	archVariants interface{}

	outputFile  android.Path
	certificate Certificate

	dexpreopter

	usesLibrary usesLibrary

	preprocessed bool

	installPath android.InstallPath

	hideApexVariantFromMake bool
}

type AndroidAppImportProperties struct {
	// A prebuilt apk to import
	Apk *string

	// The name of a certificate in the default certificate directory or an android_app_certificate
	// module name in the form ":module". Should be empty if presigned or default_dev_cert is set.
	Certificate *string

	// Names of extra android_app_certificate modules to sign the apk with in the form ":module".
	Additional_certificates []string

	// Set this flag to true if the prebuilt apk is already signed. The certificate property must not
	// be set for presigned modules.
	Presigned *bool

	// Name of the signing certificate lineage file or filegroup module.
	Lineage *string `android:"path"`

	// Sign with the default system dev certificate. Must be used judiciously. Most imported apps
	// need to either specify a specific certificate or be presigned.
	Default_dev_cert *bool

	// Specifies that this app should be installed to the priv-app directory,
	// where the system will grant it additional privileges not available to
	// normal apps.
	Privileged *bool

	// Names of modules to be overridden. Listed modules can only be other binaries
	// (in Make or Soong).
	// This does not completely prevent installation of the overridden binaries, but if both
	// binaries would be installed by default (in PRODUCT_PACKAGES) the other binary will be removed
	// from PRODUCT_PACKAGES.
	Overrides []string

	// Optional name for the installed app. If unspecified, it is derived from the module name.
	Filename *string

	// If set, create package-export.apk, which other packages can
	// use to get PRODUCT-agnostic resource data like IDs and type definitions.
	Export_package_resources *bool
}

func (a *AndroidAppImport) IsInstallable() bool {
	return true
}

// Updates properties with variant-specific values.
func (a *AndroidAppImport) processVariants(ctx android.LoadHookContext) {
	config := ctx.Config()

	dpiProps := reflect.ValueOf(a.dpiVariants).Elem().FieldByName("Dpi_variants")
	// Try DPI variant matches in the reverse-priority order so that the highest priority match
	// overwrites everything else.
	// TODO(jungjw): Can we optimize this by making it priority order?
	for i := len(config.ProductAAPTPrebuiltDPI()) - 1; i >= 0; i-- {
		MergePropertiesFromVariant(ctx, &a.properties, dpiProps, config.ProductAAPTPrebuiltDPI()[i])
	}
	if config.ProductAAPTPreferredConfig() != "" {
		MergePropertiesFromVariant(ctx, &a.properties, dpiProps, config.ProductAAPTPreferredConfig())
	}

	archProps := reflect.ValueOf(a.archVariants).Elem().FieldByName("Arch")
	archType := ctx.Config().AndroidFirstDeviceTarget.Arch.ArchType
	MergePropertiesFromVariant(ctx, &a.properties, archProps, archType.Name)

	if String(a.properties.Apk) == "" {
		// Disable this module since the apk property is still empty after processing all matching
		// variants. This likely means there is no matching variant, and the default variant doesn't
		// have an apk property value either.
		a.Disable()
	}
}

func MergePropertiesFromVariant(ctx android.EarlyModuleContext,
	dst interface{}, variantGroup reflect.Value, variant string) {
	src := variantGroup.FieldByName(proptools.FieldNameForProperty(variant))
	if !src.IsValid() {
		return
	}

	err := proptools.ExtendMatchingProperties([]interface{}{dst}, src.Interface(), nil, proptools.OrderAppend)
	if err != nil {
		if propertyErr, ok := err.(*proptools.ExtendPropertyError); ok {
			ctx.PropertyErrorf(propertyErr.Property, "%s", propertyErr.Err.Error())
		} else {
			panic(err)
		}
	}
}

func (a *AndroidAppImport) isPrebuiltFrameworkRes() bool {
	return a.Name() == "prebuilt_framework-res"
}

func (a *AndroidAppImport) DepsMutator(ctx android.BottomUpMutatorContext) {
	cert := android.SrcIsModule(String(a.properties.Certificate))
	if cert != "" {
		ctx.AddDependency(ctx.Module(), certificateTag, cert)
	}

	for _, cert := range a.properties.Additional_certificates {
		cert = android.SrcIsModule(cert)
		if cert != "" {
			ctx.AddDependency(ctx.Module(), certificateTag, cert)
		} else {
			ctx.PropertyErrorf("additional_certificates",
				`must be names of android_app_certificate modules in the form ":module"`)
		}
	}

	a.usesLibrary.deps(ctx, !a.isPrebuiltFrameworkRes())
}

func (a *AndroidAppImport) uncompressEmbeddedJniLibs(
	ctx android.ModuleContext, inputPath android.Path, outputPath android.OutputPath) {
	// Test apps don't need their JNI libraries stored uncompressed. As a matter of fact, messing
	// with them may invalidate pre-existing signature data.
	if ctx.InstallInTestcases() && (Bool(a.properties.Presigned) || a.preprocessed) {
		ctx.Build(pctx, android.BuildParams{
			Rule:   android.Cp,
			Output: outputPath,
			Input:  inputPath,
		})
		return
	}
	rule := android.NewRuleBuilder(pctx, ctx)
	rule.Command().
		Textf(`if (zipinfo %s 'lib/*.so' 2>/dev/null | grep -v ' stor ' >/dev/null) ; then`, inputPath).
		BuiltTool("zip2zip").
		FlagWithInput("-i ", inputPath).
		FlagWithOutput("-o ", outputPath).
		FlagWithArg("-0 ", "'lib/**/*.so'").
		Textf(`; else cp -f %s %s; fi`, inputPath, outputPath)
	rule.Build("uncompress-embedded-jni-libs", "Uncompress embedded JIN libs")
}

// Returns whether this module should have the dex file stored uncompressed in the APK.
func (a *AndroidAppImport) shouldUncompressDex(ctx android.ModuleContext) bool {
	if ctx.Config().UnbundledBuild() || a.preprocessed {
		return false
	}

	// Uncompress dex in APKs of privileged apps
	if ctx.Config().UncompressPrivAppDex() && a.Privileged() {
		return true
	}

	return shouldUncompressDex(ctx, &a.dexpreopter)
}

func (a *AndroidAppImport) uncompressDex(
	ctx android.ModuleContext, inputPath android.Path, outputPath android.OutputPath) {
	rule := android.NewRuleBuilder(pctx, ctx)
	rule.Command().
		Textf(`if (zipinfo %s '*.dex' 2>/dev/null | grep -v ' stor ' >/dev/null) ; then`, inputPath).
		BuiltTool("zip2zip").
		FlagWithInput("-i ", inputPath).
		FlagWithOutput("-o ", outputPath).
		FlagWithArg("-0 ", "'classes*.dex'").
		Textf(`; else cp -f %s %s; fi`, inputPath, outputPath)
	rule.Build("uncompress-dex", "Uncompress dex files")
}

func (a *AndroidAppImport) GenerateAndroidBuildActions(ctx android.ModuleContext) {
	a.generateAndroidBuildActions(ctx)
}

func (a *AndroidAppImport) InstallApkName() string {
	return a.BaseModuleName()
}

func (a *AndroidAppImport) generateAndroidBuildActions(ctx android.ModuleContext) {
	apexInfo := ctx.Provider(android.ApexInfoProvider).(android.ApexInfo)
	if !apexInfo.IsForPlatform() {
		a.hideApexVariantFromMake = true
	}

	numCertPropsSet := 0
	if String(a.properties.Certificate) != "" {
		numCertPropsSet++
	}
	if Bool(a.properties.Presigned) {
		numCertPropsSet++
	}
	if Bool(a.properties.Default_dev_cert) {
		numCertPropsSet++
	}
	if numCertPropsSet != 1 {
		ctx.ModuleErrorf("One and only one of certficate, presigned, and default_dev_cert properties must be set")
	}

	_, certificates := collectAppDeps(ctx, a, false, false)

	// TODO: LOCAL_EXTRACT_APK/LOCAL_EXTRACT_DPI_APK
	// TODO: LOCAL_PACKAGE_SPLITS

	srcApk := a.prebuilt.SingleSourcePath(ctx)

	// TODO: Install or embed JNI libraries

	// Uncompress JNI libraries in the apk
	jnisUncompressed := android.PathForModuleOut(ctx, "jnis-uncompressed", ctx.ModuleName()+".apk")
	a.uncompressEmbeddedJniLibs(ctx, srcApk, jnisUncompressed.OutputPath)

	var installDir android.InstallPath

	if a.isPrebuiltFrameworkRes() {
		// framework-res.apk is installed as system/framework/framework-res.apk
		installDir = android.PathForModuleInstall(ctx, "framework")
		a.preprocessed = true
	} else if Bool(a.properties.Privileged) {
		installDir = android.PathForModuleInstall(ctx, "priv-app", a.BaseModuleName())
	} else if ctx.InstallInTestcases() {
		installDir = android.PathForModuleInstall(ctx, a.BaseModuleName(), ctx.DeviceConfig().DeviceArch())
	} else {
		installDir = android.PathForModuleInstall(ctx, "app", a.BaseModuleName())
	}

	a.dexpreopter.isApp = true
	a.dexpreopter.installPath = installDir.Join(ctx, a.BaseModuleName()+".apk")
	a.dexpreopter.isPresignedPrebuilt = Bool(a.properties.Presigned)
	a.dexpreopter.uncompressedDex = a.shouldUncompressDex(ctx)

	a.dexpreopter.enforceUsesLibs = a.usesLibrary.enforceUsesLibraries()
	a.dexpreopter.classLoaderContexts = a.usesLibrary.classLoaderContextForUsesLibDeps(ctx)

	if a.usesLibrary.enforceUsesLibraries() {
		srcApk = a.usesLibrary.verifyUsesLibrariesAPK(ctx, srcApk)
	}

	a.dexpreopter.dexpreopt(ctx, jnisUncompressed)
	if a.dexpreopter.uncompressedDex {
		dexUncompressed := android.PathForModuleOut(ctx, "dex-uncompressed", ctx.ModuleName()+".apk")
		a.uncompressDex(ctx, jnisUncompressed, dexUncompressed.OutputPath)
		jnisUncompressed = dexUncompressed
	}

	apkFilename := proptools.StringDefault(a.properties.Filename, a.BaseModuleName()+".apk")

	// TODO: Handle EXTERNAL

	// Sign or align the package if package has not been preprocessed

	if a.isPrebuiltFrameworkRes() {
		a.outputFile = srcApk
		certificates = processMainCert(a.ModuleBase, String(a.properties.Certificate), certificates, ctx)
		if len(certificates) != 1 {
			ctx.ModuleErrorf("Unexpected number of certificates were extracted: %q", certificates)
		}
		a.certificate = certificates[0]
	} else if a.preprocessed {
		a.outputFile = srcApk
		a.certificate = PresignedCertificate
	} else if !Bool(a.properties.Presigned) {
		// If the certificate property is empty at this point, default_dev_cert must be set to true.
		// Which makes processMainCert's behavior for the empty cert string WAI.
		certificates = processMainCert(a.ModuleBase, String(a.properties.Certificate), certificates, ctx)
		a.certificate = certificates[0]
		signed := android.PathForModuleOut(ctx, "signed", apkFilename)
		var lineageFile android.Path
		if lineage := String(a.properties.Lineage); lineage != "" {
			lineageFile = android.PathForModuleSrc(ctx, lineage)
		}
		SignAppPackage(ctx, signed, jnisUncompressed, certificates, nil, lineageFile)
		a.outputFile = signed
	} else {
		alignedApk := android.PathForModuleOut(ctx, "zip-aligned", apkFilename)
		TransformZipAlign(ctx, alignedApk, jnisUncompressed)
		a.outputFile = alignedApk
		a.certificate = PresignedCertificate
	}

	// TODO: Optionally compress the output apk.

	if apexInfo.IsForPlatform() {
		a.installPath = ctx.InstallFile(installDir, apkFilename, a.outputFile)
	}

	// TODO: androidmk converter jni libs
}

func (a *AndroidAppImport) Prebuilt() *android.Prebuilt {
	return &a.prebuilt
}

func (a *AndroidAppImport) Name() string {
	return a.prebuilt.Name(a.ModuleBase.Name())
}

func (a *AndroidAppImport) OutputFile() android.Path {
	return a.outputFile
}

func (a *AndroidAppImport) JacocoReportClassesFile() android.Path {
	return nil
}

func (a *AndroidAppImport) Certificate() Certificate {
	return a.certificate
}

var dpiVariantGroupType reflect.Type
var archVariantGroupType reflect.Type
var supportedDpis = []string{"ldpi", "mdpi", "hdpi", "xhdpi", "xxhdpi", "xxxhdpi"}

func initAndroidAppImportVariantGroupTypes() {
	dpiVariantGroupType = createVariantGroupType(supportedDpis, "Dpi_variants")

	archNames := make([]string, len(android.ArchTypeList()))
	for i, archType := range android.ArchTypeList() {
		archNames[i] = archType.Name
	}
	archVariantGroupType = createVariantGroupType(archNames, "Arch")
}

// Populates all variant struct properties at creation time.
func (a *AndroidAppImport) populateAllVariantStructs() {
	a.dpiVariants = reflect.New(dpiVariantGroupType).Interface()
	a.AddProperties(a.dpiVariants)

	a.archVariants = reflect.New(archVariantGroupType).Interface()
	a.AddProperties(a.archVariants)
}

func (a *AndroidAppImport) Privileged() bool {
	return Bool(a.properties.Privileged)
}

func (a *AndroidAppImport) DepIsInSameApex(_ android.BaseModuleContext, _ android.Module) bool {
	// android_app_import might have extra dependencies via uses_libs property.
	// Don't track the dependency as we don't automatically add those libraries
	// to the classpath. It should be explicitly added to java_libs property of APEX
	return false
}

func (a *AndroidAppImport) SdkVersion(ctx android.EarlyModuleContext) android.SdkSpec {
	return android.SdkSpecPrivate
}

func (a *AndroidAppImport) MinSdkVersion(ctx android.EarlyModuleContext) android.SdkSpec {
	return android.SdkSpecPrivate
}

func (a *AndroidAppImport) LintDepSets() LintDepSets {
	return LintDepSets{}
}

var _ android.ApexModule = (*AndroidAppImport)(nil)

// Implements android.ApexModule
func (j *AndroidAppImport) ShouldSupportSdkVersion(ctx android.BaseModuleContext,
	sdkVersion android.ApiLevel) error {
	// Do not check for prebuilts against the min_sdk_version of enclosing APEX
	return nil
}

func createVariantGroupType(variants []string, variantGroupName string) reflect.Type {
	props := reflect.TypeOf((*AndroidAppImportProperties)(nil))

	variantFields := make([]reflect.StructField, len(variants))
	for i, variant := range variants {
		variantFields[i] = reflect.StructField{
			Name: proptools.FieldNameForProperty(variant),
			Type: props,
		}
	}

	variantGroupStruct := reflect.StructOf(variantFields)
	return reflect.StructOf([]reflect.StructField{
		{
			Name: variantGroupName,
			Type: variantGroupStruct,
		},
	})
}

// android_app_import imports a prebuilt apk with additional processing specified in the module.
// DPI-specific apk source files can be specified using dpi_variants. Example:
//
//     android_app_import {
//         name: "example_import",
//         apk: "prebuilts/example.apk",
//         dpi_variants: {
//             mdpi: {
//                 apk: "prebuilts/example_mdpi.apk",
//             },
//             xhdpi: {
//                 apk: "prebuilts/example_xhdpi.apk",
//             },
//         },
//         certificate: "PRESIGNED",
//     }
func AndroidAppImportFactory() android.Module {
	module := &AndroidAppImport{}
	module.AddProperties(&module.properties)
	module.AddProperties(&module.dexpreoptProperties)
	module.AddProperties(&module.usesLibrary.usesLibraryProperties)
	module.populateAllVariantStructs()
	android.AddLoadHook(module, func(ctx android.LoadHookContext) {
		module.processVariants(ctx)
	})

	android.InitApexModule(module)
	android.InitAndroidMultiTargetsArchModule(module, android.DeviceSupported, android.MultilibCommon)
	android.InitDefaultableModule(module)
	android.InitSingleSourcePrebuiltModule(module, &module.properties, "Apk")

	module.usesLibrary.enforce = true

	return module
}

type androidTestImportProperties struct {
	// Whether the prebuilt apk can be installed without additional processing. Default is false.
	Preprocessed *bool
}

type AndroidTestImport struct {
	AndroidAppImport

	testProperties testProperties

	testImportProperties androidTestImportProperties

	data android.Paths
}

func (a *AndroidTestImport) GenerateAndroidBuildActions(ctx android.ModuleContext) {
	a.preprocessed = Bool(a.testImportProperties.Preprocessed)

	a.generateAndroidBuildActions(ctx)

	a.data = android.PathsForModuleSrc(ctx, a.testProperties.Data)
}

func (a *AndroidTestImport) InstallInTestcases() bool {
	return true
}

// android_test_import imports a prebuilt test apk with additional processing specified in the
// module. DPI or arch variant configurations can be made as with android_app_import.
func AndroidTestImportFactory() android.Module {
	module := &AndroidTestImport{}
	module.AddProperties(&module.properties)
	module.AddProperties(&module.dexpreoptProperties)
	module.AddProperties(&module.testProperties)
	module.AddProperties(&module.testImportProperties)
	module.populateAllVariantStructs()
	android.AddLoadHook(module, func(ctx android.LoadHookContext) {
		module.processVariants(ctx)
	})

	module.dexpreopter.isTest = true

	android.InitApexModule(module)
	android.InitAndroidMultiTargetsArchModule(module, android.DeviceSupported, android.MultilibCommon)
	android.InitDefaultableModule(module)
	android.InitSingleSourcePrebuiltModule(module, &module.properties, "Apk")

	return module
}
