// Copyright 2019 The Android Open Source Project
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

package rust

import (
	"fmt"
	"strings"

	"github.com/google/blueprint"
	"github.com/google/blueprint/proptools"

	"android/soong/android"
	"android/soong/bloaty"
	"android/soong/cc"
	cc_config "android/soong/cc/config"
	"android/soong/rust/config"
)

var pctx = android.NewPackageContext("android/soong/rust")

func init() {
	// Only allow rust modules to be defined for certain projects

	android.AddNeverAllowRules(
		android.NeverAllow().
			NotIn(config.RustAllowedPaths...).
			ModuleType(config.RustModuleTypes...))

	android.RegisterModuleType("rust_defaults", defaultsFactory)
	android.PreDepsMutators(func(ctx android.RegisterMutatorsContext) {
		ctx.BottomUp("rust_libraries", LibraryMutator).Parallel()
		ctx.BottomUp("rust_stdlinkage", LibstdMutator).Parallel()
		ctx.BottomUp("rust_begin", BeginMutator).Parallel()

	})
	android.PostDepsMutators(func(ctx android.RegisterMutatorsContext) {
		ctx.BottomUp("rust_sanitizers", rustSanitizerRuntimeMutator).Parallel()
	})
	pctx.Import("android/soong/rust/config")
	pctx.ImportAs("cc_config", "android/soong/cc/config")
}

type Flags struct {
	GlobalRustFlags []string // Flags that apply globally to rust
	GlobalLinkFlags []string // Flags that apply globally to linker
	RustFlags       []string // Flags that apply to rust
	LinkFlags       []string // Flags that apply to linker
	ClippyFlags     []string // Flags that apply to clippy-driver, during the linting
	RustdocFlags    []string // Flags that apply to rustdoc
	Toolchain       config.Toolchain
	Coverage        bool
	Clippy          bool
}

type BaseProperties struct {
	AndroidMkRlibs         []string
	AndroidMkDylibs        []string
	AndroidMkProcMacroLibs []string
	AndroidMkSharedLibs    []string
	AndroidMkStaticLibs    []string

	ImageVariationPrefix string `blueprint:"mutated"`
	VndkVersion          string `blueprint:"mutated"`
	SubName              string `blueprint:"mutated"`

	// SubName is used by CC for tracking image variants / SDK versions. RustSubName is used for Rust-specific
	// subnaming which shouldn't be visible to CC modules (such as the rlib stdlinkage subname). This should be
	// appended before SubName.
	RustSubName string `blueprint:"mutated"`

	// Set by imageMutator
	CoreVariantNeeded          bool     `blueprint:"mutated"`
	VendorRamdiskVariantNeeded bool     `blueprint:"mutated"`
	ExtraVariants              []string `blueprint:"mutated"`

	// Make this module available when building for vendor ramdisk.
	// On device without a dedicated recovery partition, the module is only
	// available after switching root into
	// /first_stage_ramdisk. To expose the module before switching root, install
	// the recovery variant instead (TODO(b/165791368) recovery not yet supported)
	Vendor_ramdisk_available *bool

	// Minimum sdk version that the artifact should support when it runs as part of mainline modules(APEX).
	Min_sdk_version *string

	PreventInstall bool
	HideFromMake   bool
	Installable    *bool
}

type Module struct {
	android.ModuleBase
	android.DefaultableModuleBase
	android.ApexModuleBase

	VendorProperties cc.VendorProperties

	Properties BaseProperties

	hod      android.HostOrDeviceSupported
	multilib android.Multilib

	makeLinkType string

	compiler         compiler
	coverage         *coverage
	clippy           *clippy
	sanitize         *sanitize
	cachedToolchain  config.Toolchain
	sourceProvider   SourceProvider
	subAndroidMkOnce map[SubAndroidMkProvider]bool

	// Unstripped output. This is usually used when this module is linked to another module
	// as a library. The stripped output which is used for installation can be found via
	// compiler.strippedOutputFile if it exists.
	unstrippedOutputFile android.OptionalPath
	docTimestampFile     android.OptionalPath

	hideApexVariantFromMake bool
}

func (mod *Module) Header() bool {
	//TODO: If Rust libraries provide header variants, this needs to be updated.
	return false
}

func (mod *Module) SetPreventInstall() {
	mod.Properties.PreventInstall = true
}

func (mod *Module) SetHideFromMake() {
	mod.Properties.HideFromMake = true
}

func (c *Module) HiddenFromMake() bool {
	return c.Properties.HideFromMake
}

func (mod *Module) SanitizePropDefined() bool {
	// Because compiler is not set for some Rust modules where sanitize might be set, check that compiler is also not
	// nil since we need compiler to actually sanitize.
	return mod.sanitize != nil && mod.compiler != nil
}

func (mod *Module) IsDependencyRoot() bool {
	if mod.compiler != nil {
		return mod.compiler.isDependencyRoot()
	}
	panic("IsDependencyRoot called on a non-compiler Rust module")
}

func (mod *Module) IsPrebuilt() bool {
	if _, ok := mod.compiler.(*prebuiltLibraryDecorator); ok {
		return true
	}
	return false
}

func (mod *Module) OutputFiles(tag string) (android.Paths, error) {
	switch tag {
	case "":
		if mod.sourceProvider != nil && (mod.compiler == nil || mod.compiler.Disabled()) {
			return mod.sourceProvider.Srcs(), nil
		} else {
			if mod.OutputFile().Valid() {
				return android.Paths{mod.OutputFile().Path()}, nil
			}
			return android.Paths{}, nil
		}
	default:
		return nil, fmt.Errorf("unsupported module reference tag %q", tag)
	}
}

func (mod *Module) SelectedStl() string {
	return ""
}

func (mod *Module) NonCcVariants() bool {
	if mod.compiler != nil {
		if _, ok := mod.compiler.(libraryInterface); ok {
			return false
		}
	}
	panic(fmt.Errorf("NonCcVariants called on non-library module: %q", mod.BaseModuleName()))
}

func (mod *Module) Static() bool {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(libraryInterface); ok {
			return library.static()
		}
	}
	return false
}

func (mod *Module) Shared() bool {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(libraryInterface); ok {
			return library.shared()
		}
	}
	return false
}

func (mod *Module) Dylib() bool {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(libraryInterface); ok {
			return library.dylib()
		}
	}
	return false
}

func (mod *Module) Rlib() bool {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(libraryInterface); ok {
			return library.rlib()
		}
	}
	return false
}

func (mod *Module) Binary() bool {
	if mod.compiler != nil {
		if _, ok := mod.compiler.(*binaryDecorator); ok {
			return true
		}
	}
	return false
}

func (mod *Module) Object() bool {
	// Rust has no modules which produce only object files.
	return false
}

func (mod *Module) Toc() android.OptionalPath {
	if mod.compiler != nil {
		if _, ok := mod.compiler.(libraryInterface); ok {
			return android.OptionalPath{}
		}
	}
	panic(fmt.Errorf("Toc() called on non-library module: %q", mod.BaseModuleName()))
}

func (mod *Module) UseSdk() bool {
	return false
}

func (mod *Module) RelativeInstallPath() string {
	if mod.compiler != nil {
		return mod.compiler.relativeInstallPath()
	}
	return ""
}

func (mod *Module) UseVndk() bool {
	return mod.Properties.VndkVersion != ""
}

func (mod *Module) MustUseVendorVariant() bool {
	return true
}

func (mod *Module) SubName() string {
	return mod.Properties.SubName
}

func (mod *Module) IsVndk() bool {
	// TODO(b/165791368)
	return false
}

func (mod *Module) IsVndkExt() bool {
	return false
}

func (mod *Module) IsVndkSp() bool {
	return false
}

func (c *Module) IsVndkPrivate() bool {
	return false
}

func (c *Module) IsLlndk() bool {
	return false
}

func (c *Module) IsLlndkPublic() bool {
	return false
}

func (mod *Module) KernelHeadersDecorator() bool {
	return false
}

func (m *Module) NeedsLlndkVariants() bool {
	return false
}

func (m *Module) NeedsVendorPublicLibraryVariants() bool {
	return false
}

func (mod *Module) HasLlndkStubs() bool {
	return false
}

func (mod *Module) StubsVersion() string {
	panic(fmt.Errorf("StubsVersion called on non-versioned module: %q", mod.BaseModuleName()))
}

func (mod *Module) SdkVersion() string {
	return ""
}

func (mod *Module) MinSdkVersion() string {
	return ""
}

func (mod *Module) AlwaysSdk() bool {
	return false
}

func (mod *Module) IsSdkVariant() bool {
	return false
}

func (mod *Module) SplitPerApiLevel() bool {
	return false
}

type Deps struct {
	Dylibs          []string
	Rlibs           []string
	Rustlibs        []string
	Stdlibs         []string
	ProcMacros      []string
	SharedLibs      []string
	StaticLibs      []string
	WholeStaticLibs []string
	HeaderLibs      []string

	CrtBegin, CrtEnd string
}

type PathDeps struct {
	DyLibs        RustLibraries
	RLibs         RustLibraries
	SharedLibs    android.Paths
	SharedLibDeps android.Paths
	StaticLibs    android.Paths
	ProcMacros    RustLibraries

	// depFlags and depLinkFlags are rustc and linker (clang) flags.
	depFlags     []string
	depLinkFlags []string

	// linkDirs are link paths passed via -L to rustc. linkObjects are objects passed directly to the linker.
	// Both of these are exported and propagate to dependencies.
	linkDirs    []string
	linkObjects []string

	// Used by bindgen modules which call clang
	depClangFlags         []string
	depIncludePaths       android.Paths
	depGeneratedHeaders   android.Paths
	depSystemIncludePaths android.Paths

	CrtBegin android.OptionalPath
	CrtEnd   android.OptionalPath

	// Paths to generated source files
	SrcDeps          android.Paths
	srcProviderFiles android.Paths
}

type RustLibraries []RustLibrary

type RustLibrary struct {
	Path      android.Path
	CrateName string
}

type compiler interface {
	initialize(ctx ModuleContext)
	compilerFlags(ctx ModuleContext, flags Flags) Flags
	compilerProps() []interface{}
	compile(ctx ModuleContext, flags Flags, deps PathDeps) android.Path
	compilerDeps(ctx DepsContext, deps Deps) Deps
	crateName() string
	rustdoc(ctx ModuleContext, flags Flags, deps PathDeps) android.OptionalPath

	// Output directory in which source-generated code from dependencies is
	// copied. This is equivalent to Cargo's OUT_DIR variable.
	CargoOutDir() android.OptionalPath

	inData() bool
	install(ctx ModuleContext)
	relativeInstallPath() string
	everInstallable() bool

	nativeCoverage() bool

	Disabled() bool
	SetDisabled()

	stdLinkage(ctx *depsContext) RustLinkage
	isDependencyRoot() bool

	strippedOutputFilePath() android.OptionalPath
}

type exportedFlagsProducer interface {
	exportLinkDirs(...string)
	exportLinkObjects(...string)
}

type flagExporter struct {
	linkDirs    []string
	linkObjects []string
}

func (flagExporter *flagExporter) exportLinkDirs(dirs ...string) {
	flagExporter.linkDirs = android.FirstUniqueStrings(append(flagExporter.linkDirs, dirs...))
}

func (flagExporter *flagExporter) exportLinkObjects(flags ...string) {
	flagExporter.linkObjects = android.FirstUniqueStrings(append(flagExporter.linkObjects, flags...))
}

func (flagExporter *flagExporter) setProvider(ctx ModuleContext) {
	ctx.SetProvider(FlagExporterInfoProvider, FlagExporterInfo{
		LinkDirs:    flagExporter.linkDirs,
		LinkObjects: flagExporter.linkObjects,
	})
}

var _ exportedFlagsProducer = (*flagExporter)(nil)

func NewFlagExporter() *flagExporter {
	return &flagExporter{}
}

type FlagExporterInfo struct {
	Flags       []string
	LinkDirs    []string // TODO: this should be android.Paths
	LinkObjects []string // TODO: this should be android.Paths
}

var FlagExporterInfoProvider = blueprint.NewProvider(FlagExporterInfo{})

func (mod *Module) isCoverageVariant() bool {
	return mod.coverage.Properties.IsCoverageVariant
}

var _ cc.Coverage = (*Module)(nil)

func (mod *Module) IsNativeCoverageNeeded(ctx android.BaseModuleContext) bool {
	return mod.coverage != nil && mod.coverage.Properties.NeedCoverageVariant
}

func (mod *Module) VndkVersion() string {
	return mod.Properties.VndkVersion
}

func (mod *Module) PreventInstall() bool {
	return mod.Properties.PreventInstall
}

func (mod *Module) HideFromMake() {
	mod.Properties.HideFromMake = true
}

func (mod *Module) MarkAsCoverageVariant(coverage bool) {
	mod.coverage.Properties.IsCoverageVariant = coverage
}

func (mod *Module) EnableCoverageIfNeeded() {
	mod.coverage.Properties.CoverageEnabled = mod.coverage.Properties.NeedCoverageBuild
}

func defaultsFactory() android.Module {
	return DefaultsFactory()
}

type Defaults struct {
	android.ModuleBase
	android.DefaultsModuleBase
}

func DefaultsFactory(props ...interface{}) android.Module {
	module := &Defaults{}

	module.AddProperties(props...)
	module.AddProperties(
		&BaseProperties{},
		&cc.VendorProperties{},
		&BenchmarkProperties{},
		&BindgenProperties{},
		&BaseCompilerProperties{},
		&BinaryCompilerProperties{},
		&LibraryCompilerProperties{},
		&ProcMacroCompilerProperties{},
		&PrebuiltProperties{},
		&SourceProviderProperties{},
		&TestProperties{},
		&cc.CoverageProperties{},
		&cc.RustBindgenClangProperties{},
		&ClippyProperties{},
		&SanitizeProperties{},
	)

	android.InitDefaultsModule(module)
	return module
}

func (mod *Module) CrateName() string {
	return mod.compiler.crateName()
}

func (mod *Module) CcLibrary() bool {
	if mod.compiler != nil {
		if _, ok := mod.compiler.(*libraryDecorator); ok {
			return true
		}
	}
	return false
}

func (mod *Module) CcLibraryInterface() bool {
	if mod.compiler != nil {
		// use build{Static,Shared}() instead of {static,shared}() here because this might be called before
		// VariantIs{Static,Shared} is set.
		if lib, ok := mod.compiler.(libraryInterface); ok && (lib.buildShared() || lib.buildStatic()) {
			return true
		}
	}
	return false
}

func (mod *Module) IncludeDirs() android.Paths {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(*libraryDecorator); ok {
			return library.includeDirs
		}
	}
	panic(fmt.Errorf("IncludeDirs called on non-library module: %q", mod.BaseModuleName()))
}

func (mod *Module) SetStatic() {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(libraryInterface); ok {
			library.setStatic()
			return
		}
	}
	panic(fmt.Errorf("SetStatic called on non-library module: %q", mod.BaseModuleName()))
}

func (mod *Module) SetShared() {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(libraryInterface); ok {
			library.setShared()
			return
		}
	}
	panic(fmt.Errorf("SetShared called on non-library module: %q", mod.BaseModuleName()))
}

func (mod *Module) BuildStaticVariant() bool {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(libraryInterface); ok {
			return library.buildStatic()
		}
	}
	panic(fmt.Errorf("BuildStaticVariant called on non-library module: %q", mod.BaseModuleName()))
}

func (mod *Module) BuildSharedVariant() bool {
	if mod.compiler != nil {
		if library, ok := mod.compiler.(libraryInterface); ok {
			return library.buildShared()
		}
	}
	panic(fmt.Errorf("BuildSharedVariant called on non-library module: %q", mod.BaseModuleName()))
}

func (mod *Module) Module() android.Module {
	return mod
}

func (mod *Module) OutputFile() android.OptionalPath {
	if mod.compiler != nil && mod.compiler.strippedOutputFilePath().Valid() {
		return mod.compiler.strippedOutputFilePath()
	}
	return mod.unstrippedOutputFile
}

func (mod *Module) CoverageFiles() android.Paths {
	if mod.compiler != nil {
		return android.Paths{}
	}
	panic(fmt.Errorf("CoverageFiles called on non-library module: %q", mod.BaseModuleName()))
}

func (mod *Module) installable(apexInfo android.ApexInfo) bool {
	// The apex variant is not installable because it is included in the APEX and won't appear
	// in the system partition as a standalone file.
	if !apexInfo.IsForPlatform() {
		return false
	}

	return mod.OutputFile().Valid() && !mod.Properties.PreventInstall
}

var _ cc.LinkableInterface = (*Module)(nil)

func (mod *Module) Init() android.Module {
	mod.AddProperties(&mod.Properties)
	mod.AddProperties(&mod.VendorProperties)

	if mod.compiler != nil {
		mod.AddProperties(mod.compiler.compilerProps()...)
	}
	if mod.coverage != nil {
		mod.AddProperties(mod.coverage.props()...)
	}
	if mod.clippy != nil {
		mod.AddProperties(mod.clippy.props()...)
	}
	if mod.sourceProvider != nil {
		mod.AddProperties(mod.sourceProvider.SourceProviderProps()...)
	}
	if mod.sanitize != nil {
		mod.AddProperties(mod.sanitize.props()...)
	}

	android.InitAndroidArchModule(mod, mod.hod, mod.multilib)
	android.InitApexModule(mod)

	android.InitDefaultableModule(mod)
	return mod
}

func newBaseModule(hod android.HostOrDeviceSupported, multilib android.Multilib) *Module {
	return &Module{
		hod:      hod,
		multilib: multilib,
	}
}
func newModule(hod android.HostOrDeviceSupported, multilib android.Multilib) *Module {
	module := newBaseModule(hod, multilib)
	module.coverage = &coverage{}
	module.clippy = &clippy{}
	module.sanitize = &sanitize{}
	return module
}

type ModuleContext interface {
	android.ModuleContext
	ModuleContextIntf
}

type BaseModuleContext interface {
	android.BaseModuleContext
	ModuleContextIntf
}

type DepsContext interface {
	android.BottomUpMutatorContext
	ModuleContextIntf
}

type ModuleContextIntf interface {
	RustModule() *Module
	toolchain() config.Toolchain
}

type depsContext struct {
	android.BottomUpMutatorContext
}

type moduleContext struct {
	android.ModuleContext
}

type baseModuleContext struct {
	android.BaseModuleContext
}

func (ctx *moduleContext) RustModule() *Module {
	return ctx.Module().(*Module)
}

func (ctx *moduleContext) toolchain() config.Toolchain {
	return ctx.RustModule().toolchain(ctx)
}

func (ctx *depsContext) RustModule() *Module {
	return ctx.Module().(*Module)
}

func (ctx *depsContext) toolchain() config.Toolchain {
	return ctx.RustModule().toolchain(ctx)
}

func (ctx *baseModuleContext) RustModule() *Module {
	return ctx.Module().(*Module)
}

func (ctx *baseModuleContext) toolchain() config.Toolchain {
	return ctx.RustModule().toolchain(ctx)
}

func (mod *Module) nativeCoverage() bool {
	return mod.compiler != nil && mod.compiler.nativeCoverage()
}

func (mod *Module) EverInstallable() bool {
	return mod.compiler != nil &&
		// Check to see whether the module is actually ever installable.
		mod.compiler.everInstallable()
}

func (mod *Module) Installable() *bool {
	return mod.Properties.Installable
}

func (mod *Module) toolchain(ctx android.BaseModuleContext) config.Toolchain {
	if mod.cachedToolchain == nil {
		mod.cachedToolchain = config.FindToolchain(ctx.Os(), ctx.Arch())
	}
	return mod.cachedToolchain
}

func (mod *Module) ccToolchain(ctx android.BaseModuleContext) cc_config.Toolchain {
	return cc_config.FindToolchain(ctx.Os(), ctx.Arch())
}

func (d *Defaults) GenerateAndroidBuildActions(ctx android.ModuleContext) {
}

func (mod *Module) GenerateAndroidBuildActions(actx android.ModuleContext) {
	ctx := &moduleContext{
		ModuleContext: actx,
	}

	apexInfo := actx.Provider(android.ApexInfoProvider).(android.ApexInfo)
	if !apexInfo.IsForPlatform() {
		mod.hideApexVariantFromMake = true
	}

	toolchain := mod.toolchain(ctx)
	mod.makeLinkType = cc.GetMakeLinkType(actx, mod)

	// Differentiate static libraries that are vendor available
	if mod.UseVndk() {
		mod.Properties.SubName += cc.VendorSuffix
	} else if mod.InVendorRamdisk() && !mod.OnlyInVendorRamdisk() {
		mod.Properties.SubName += cc.VendorRamdiskSuffix
	}

	if !toolchain.Supported() {
		// This toolchain's unsupported, there's nothing to do for this mod.
		return
	}

	deps := mod.depsToPaths(ctx)
	flags := Flags{
		Toolchain: toolchain,
	}

	if mod.compiler != nil {
		flags = mod.compiler.compilerFlags(ctx, flags)
	}
	if mod.coverage != nil {
		flags, deps = mod.coverage.flags(ctx, flags, deps)
	}
	if mod.clippy != nil {
		flags, deps = mod.clippy.flags(ctx, flags, deps)
	}
	if mod.sanitize != nil {
		flags, deps = mod.sanitize.flags(ctx, flags, deps)
	}

	// SourceProvider needs to call GenerateSource() before compiler calls
	// compile() so it can provide the source. A SourceProvider has
	// multiple variants (e.g. source, rlib, dylib). Only the "source"
	// variant is responsible for effectively generating the source. The
	// remaining variants relies on the "source" variant output.
	if mod.sourceProvider != nil {
		if mod.compiler.(libraryInterface).source() {
			mod.sourceProvider.GenerateSource(ctx, deps)
			mod.sourceProvider.setSubName(ctx.ModuleSubDir())
		} else {
			sourceMod := actx.GetDirectDepWithTag(mod.Name(), sourceDepTag)
			sourceLib := sourceMod.(*Module).compiler.(*libraryDecorator)
			mod.sourceProvider.setOutputFiles(sourceLib.sourceProvider.Srcs())
		}
	}

	if mod.compiler != nil && !mod.compiler.Disabled() {
		mod.compiler.initialize(ctx)
		unstrippedOutputFile := mod.compiler.compile(ctx, flags, deps)
		mod.unstrippedOutputFile = android.OptionalPathForPath(unstrippedOutputFile)
		bloaty.MeasureSizeForPaths(ctx, mod.compiler.strippedOutputFilePath(), mod.unstrippedOutputFile)

		mod.docTimestampFile = mod.compiler.rustdoc(ctx, flags, deps)

		apexInfo := actx.Provider(android.ApexInfoProvider).(android.ApexInfo)
		if mod.installable(apexInfo) {
			mod.compiler.install(ctx)
		}
	}
}

func (mod *Module) deps(ctx DepsContext) Deps {
	deps := Deps{}

	if mod.compiler != nil {
		deps = mod.compiler.compilerDeps(ctx, deps)
	}
	if mod.sourceProvider != nil {
		deps = mod.sourceProvider.SourceProviderDeps(ctx, deps)
	}

	if mod.coverage != nil {
		deps = mod.coverage.deps(ctx, deps)
	}

	if mod.sanitize != nil {
		deps = mod.sanitize.deps(ctx, deps)
	}

	deps.Rlibs = android.LastUniqueStrings(deps.Rlibs)
	deps.Dylibs = android.LastUniqueStrings(deps.Dylibs)
	deps.Rustlibs = android.LastUniqueStrings(deps.Rustlibs)
	deps.ProcMacros = android.LastUniqueStrings(deps.ProcMacros)
	deps.SharedLibs = android.LastUniqueStrings(deps.SharedLibs)
	deps.StaticLibs = android.LastUniqueStrings(deps.StaticLibs)
	deps.WholeStaticLibs = android.LastUniqueStrings(deps.WholeStaticLibs)
	return deps

}

type dependencyTag struct {
	blueprint.BaseDependencyTag
	name      string
	library   bool
	procMacro bool
}

// InstallDepNeeded returns true for rlibs, dylibs, and proc macros so that they or their transitive
// dependencies (especially C/C++ shared libs) are installed as dependencies of a rust binary.
func (d dependencyTag) InstallDepNeeded() bool {
	return d.library || d.procMacro
}

var _ android.InstallNeededDependencyTag = dependencyTag{}

var (
	customBindgenDepTag = dependencyTag{name: "customBindgenTag"}
	rlibDepTag          = dependencyTag{name: "rlibTag", library: true}
	dylibDepTag         = dependencyTag{name: "dylib", library: true}
	procMacroDepTag     = dependencyTag{name: "procMacro", procMacro: true}
	testPerSrcDepTag    = dependencyTag{name: "rust_unit_tests"}
	sourceDepTag        = dependencyTag{name: "source"}
)

func IsDylibDepTag(depTag blueprint.DependencyTag) bool {
	tag, ok := depTag.(dependencyTag)
	return ok && tag == dylibDepTag
}

func IsRlibDepTag(depTag blueprint.DependencyTag) bool {
	tag, ok := depTag.(dependencyTag)
	return ok && tag == rlibDepTag
}

type autoDep struct {
	variation string
	depTag    dependencyTag
}

var (
	rlibVariation  = "rlib"
	dylibVariation = "dylib"
	rlibAutoDep    = autoDep{variation: rlibVariation, depTag: rlibDepTag}
	dylibAutoDep   = autoDep{variation: dylibVariation, depTag: dylibDepTag}
)

type autoDeppable interface {
	autoDep(ctx android.BottomUpMutatorContext) autoDep
}

func (mod *Module) begin(ctx BaseModuleContext) {
	if mod.coverage != nil {
		mod.coverage.begin(ctx)
	}
	if mod.sanitize != nil {
		mod.sanitize.begin(ctx)
	}
}

func (mod *Module) depsToPaths(ctx android.ModuleContext) PathDeps {
	var depPaths PathDeps

	directRlibDeps := []*Module{}
	directDylibDeps := []*Module{}
	directProcMacroDeps := []*Module{}
	directSharedLibDeps := [](cc.LinkableInterface){}
	directStaticLibDeps := [](cc.LinkableInterface){}
	directSrcProvidersDeps := []*Module{}
	directSrcDeps := [](android.SourceFileProducer){}

	ctx.VisitDirectDeps(func(dep android.Module) {
		depName := ctx.OtherModuleName(dep)
		depTag := ctx.OtherModuleDependencyTag(dep)

		if rustDep, ok := dep.(*Module); ok && !rustDep.CcLibraryInterface() {
			//Handle Rust Modules
			makeLibName := cc.MakeLibName(ctx, mod, rustDep, depName+rustDep.Properties.RustSubName)

			switch depTag {
			case dylibDepTag:
				dylib, ok := rustDep.compiler.(libraryInterface)
				if !ok || !dylib.dylib() {
					ctx.ModuleErrorf("mod %q not an dylib library", depName)
					return
				}
				directDylibDeps = append(directDylibDeps, rustDep)
				mod.Properties.AndroidMkDylibs = append(mod.Properties.AndroidMkDylibs, makeLibName)
			case rlibDepTag:

				rlib, ok := rustDep.compiler.(libraryInterface)
				if !ok || !rlib.rlib() {
					ctx.ModuleErrorf("mod %q not an rlib library", makeLibName)
					return
				}
				directRlibDeps = append(directRlibDeps, rustDep)
				mod.Properties.AndroidMkRlibs = append(mod.Properties.AndroidMkRlibs, makeLibName)
			case procMacroDepTag:
				directProcMacroDeps = append(directProcMacroDeps, rustDep)
				mod.Properties.AndroidMkProcMacroLibs = append(mod.Properties.AndroidMkProcMacroLibs, makeLibName)
			case android.SourceDepTag:
				// Since these deps are added in path_properties.go via AddDependencies, we need to ensure the correct
				// OS/Arch variant is used.
				var helper string
				if ctx.Host() {
					helper = "missing 'host_supported'?"
				} else {
					helper = "device module defined?"
				}

				if dep.Target().Os != ctx.Os() {
					ctx.ModuleErrorf("OS mismatch on dependency %q (%s)", dep.Name(), helper)
					return
				} else if dep.Target().Arch.ArchType != ctx.Arch().ArchType {
					ctx.ModuleErrorf("Arch mismatch on dependency %q (%s)", dep.Name(), helper)
					return
				}
				directSrcProvidersDeps = append(directSrcProvidersDeps, rustDep)
			}

			//Append the dependencies exportedDirs, except for proc-macros which target a different arch/OS
			if depTag != procMacroDepTag {
				exportedInfo := ctx.OtherModuleProvider(dep, FlagExporterInfoProvider).(FlagExporterInfo)
				depPaths.linkDirs = append(depPaths.linkDirs, exportedInfo.LinkDirs...)
				depPaths.depFlags = append(depPaths.depFlags, exportedInfo.Flags...)
				depPaths.linkObjects = append(depPaths.linkObjects, exportedInfo.LinkObjects...)
			}

			if depTag == dylibDepTag || depTag == rlibDepTag || depTag == procMacroDepTag {
				linkFile := rustDep.unstrippedOutputFile
				if !linkFile.Valid() {
					ctx.ModuleErrorf("Invalid output file when adding dep %q to %q",
						depName, ctx.ModuleName())
					return
				}
				linkDir := linkPathFromFilePath(linkFile.Path())
				if lib, ok := mod.compiler.(exportedFlagsProducer); ok {
					lib.exportLinkDirs(linkDir)
				}
			}

		} else if ccDep, ok := dep.(cc.LinkableInterface); ok {
			//Handle C dependencies
			makeLibName := cc.MakeLibName(ctx, mod, ccDep, depName)
			if _, ok := ccDep.(*Module); !ok {
				if ccDep.Module().Target().Os != ctx.Os() {
					ctx.ModuleErrorf("OS mismatch between %q and %q", ctx.ModuleName(), depName)
					return
				}
				if ccDep.Module().Target().Arch.ArchType != ctx.Arch().ArchType {
					ctx.ModuleErrorf("Arch mismatch between %q and %q", ctx.ModuleName(), depName)
					return
				}
			}
			linkObject := ccDep.OutputFile()
			linkPath := linkPathFromFilePath(linkObject.Path())

			if !linkObject.Valid() {
				ctx.ModuleErrorf("Invalid output file when adding dep %q to %q", depName, ctx.ModuleName())
			}

			exportDep := false
			switch {
			case cc.IsStaticDepTag(depTag):
				if cc.IsWholeStaticLib(depTag) {
					// rustc will bundle static libraries when they're passed with "-lstatic=<lib>". This will fail
					// if the library is not prefixed by "lib".
					if libName, ok := libNameFromFilePath(linkObject.Path()); ok {
						depPaths.depFlags = append(depPaths.depFlags, "-lstatic="+libName)
					} else {
						ctx.ModuleErrorf("'%q' cannot be listed as a whole_static_library in Rust modules unless the output is prefixed by 'lib'", depName, ctx.ModuleName())
					}
				}

				// Add this to linkObjects to pass the library directly to the linker as well. This propagates
				// to dependencies to avoid having to redeclare static libraries for dependents of the dylib variant.
				depPaths.linkObjects = append(depPaths.linkObjects, linkObject.String())
				depPaths.linkDirs = append(depPaths.linkDirs, linkPath)

				exportedInfo := ctx.OtherModuleProvider(dep, cc.FlagExporterInfoProvider).(cc.FlagExporterInfo)
				depPaths.depIncludePaths = append(depPaths.depIncludePaths, exportedInfo.IncludeDirs...)
				depPaths.depSystemIncludePaths = append(depPaths.depSystemIncludePaths, exportedInfo.SystemIncludeDirs...)
				depPaths.depClangFlags = append(depPaths.depClangFlags, exportedInfo.Flags...)
				depPaths.depGeneratedHeaders = append(depPaths.depGeneratedHeaders, exportedInfo.GeneratedHeaders...)
				directStaticLibDeps = append(directStaticLibDeps, ccDep)
				mod.Properties.AndroidMkStaticLibs = append(mod.Properties.AndroidMkStaticLibs, makeLibName)
			case cc.IsSharedDepTag(depTag):
				depPaths.linkDirs = append(depPaths.linkDirs, linkPath)
				depPaths.linkObjects = append(depPaths.linkObjects, linkObject.String())
				exportedInfo := ctx.OtherModuleProvider(dep, cc.FlagExporterInfoProvider).(cc.FlagExporterInfo)
				depPaths.depIncludePaths = append(depPaths.depIncludePaths, exportedInfo.IncludeDirs...)
				depPaths.depSystemIncludePaths = append(depPaths.depSystemIncludePaths, exportedInfo.SystemIncludeDirs...)
				depPaths.depClangFlags = append(depPaths.depClangFlags, exportedInfo.Flags...)
				depPaths.depGeneratedHeaders = append(depPaths.depGeneratedHeaders, exportedInfo.GeneratedHeaders...)
				directSharedLibDeps = append(directSharedLibDeps, ccDep)
				mod.Properties.AndroidMkSharedLibs = append(mod.Properties.AndroidMkSharedLibs, makeLibName)
				exportDep = true
			case cc.IsHeaderDepTag(depTag):
				exportedInfo := ctx.OtherModuleProvider(dep, cc.FlagExporterInfoProvider).(cc.FlagExporterInfo)
				depPaths.depIncludePaths = append(depPaths.depIncludePaths, exportedInfo.IncludeDirs...)
				depPaths.depSystemIncludePaths = append(depPaths.depSystemIncludePaths, exportedInfo.SystemIncludeDirs...)
				depPaths.depGeneratedHeaders = append(depPaths.depGeneratedHeaders, exportedInfo.GeneratedHeaders...)
			case depTag == cc.CrtBeginDepTag:
				depPaths.CrtBegin = linkObject
			case depTag == cc.CrtEndDepTag:
				depPaths.CrtEnd = linkObject
			}

			// Make sure these dependencies are propagated
			if lib, ok := mod.compiler.(exportedFlagsProducer); ok && exportDep {
				lib.exportLinkDirs(linkPath)
				lib.exportLinkObjects(linkObject.String())
			}
		}

		if srcDep, ok := dep.(android.SourceFileProducer); ok {
			switch depTag {
			case android.SourceDepTag:
				// These are usually genrules which don't have per-target variants.
				directSrcDeps = append(directSrcDeps, srcDep)
			}
		}
	})

	var rlibDepFiles RustLibraries
	for _, dep := range directRlibDeps {
		rlibDepFiles = append(rlibDepFiles, RustLibrary{Path: dep.unstrippedOutputFile.Path(), CrateName: dep.CrateName()})
	}
	var dylibDepFiles RustLibraries
	for _, dep := range directDylibDeps {
		dylibDepFiles = append(dylibDepFiles, RustLibrary{Path: dep.unstrippedOutputFile.Path(), CrateName: dep.CrateName()})
	}
	var procMacroDepFiles RustLibraries
	for _, dep := range directProcMacroDeps {
		procMacroDepFiles = append(procMacroDepFiles, RustLibrary{Path: dep.unstrippedOutputFile.Path(), CrateName: dep.CrateName()})
	}

	var staticLibDepFiles android.Paths
	for _, dep := range directStaticLibDeps {
		staticLibDepFiles = append(staticLibDepFiles, dep.OutputFile().Path())
	}

	var sharedLibFiles android.Paths
	var sharedLibDepFiles android.Paths
	for _, dep := range directSharedLibDeps {
		sharedLibFiles = append(sharedLibFiles, dep.OutputFile().Path())
		if dep.Toc().Valid() {
			sharedLibDepFiles = append(sharedLibDepFiles, dep.Toc().Path())
		} else {
			sharedLibDepFiles = append(sharedLibDepFiles, dep.OutputFile().Path())
		}
	}

	var srcProviderDepFiles android.Paths
	for _, dep := range directSrcProvidersDeps {
		srcs, _ := dep.OutputFiles("")
		srcProviderDepFiles = append(srcProviderDepFiles, srcs...)
	}
	for _, dep := range directSrcDeps {
		srcs := dep.Srcs()
		srcProviderDepFiles = append(srcProviderDepFiles, srcs...)
	}

	depPaths.RLibs = append(depPaths.RLibs, rlibDepFiles...)
	depPaths.DyLibs = append(depPaths.DyLibs, dylibDepFiles...)
	depPaths.SharedLibs = append(depPaths.SharedLibs, sharedLibDepFiles...)
	depPaths.SharedLibDeps = append(depPaths.SharedLibDeps, sharedLibDepFiles...)
	depPaths.StaticLibs = append(depPaths.StaticLibs, staticLibDepFiles...)
	depPaths.ProcMacros = append(depPaths.ProcMacros, procMacroDepFiles...)
	depPaths.SrcDeps = append(depPaths.SrcDeps, srcProviderDepFiles...)

	// Dedup exported flags from dependencies
	depPaths.linkDirs = android.FirstUniqueStrings(depPaths.linkDirs)
	depPaths.linkObjects = android.FirstUniqueStrings(depPaths.linkObjects)
	depPaths.depFlags = android.FirstUniqueStrings(depPaths.depFlags)
	depPaths.depClangFlags = android.FirstUniqueStrings(depPaths.depClangFlags)
	depPaths.depIncludePaths = android.FirstUniquePaths(depPaths.depIncludePaths)
	depPaths.depSystemIncludePaths = android.FirstUniquePaths(depPaths.depSystemIncludePaths)

	return depPaths
}

func (mod *Module) InstallInData() bool {
	if mod.compiler == nil {
		return false
	}
	return mod.compiler.inData()
}

func linkPathFromFilePath(filepath android.Path) string {
	return strings.Split(filepath.String(), filepath.Base())[0]
}

func (mod *Module) DepsMutator(actx android.BottomUpMutatorContext) {
	ctx := &depsContext{
		BottomUpMutatorContext: actx,
	}

	deps := mod.deps(ctx)
	var commonDepVariations []blueprint.Variation

	stdLinkage := "dylib-std"
	if mod.compiler.stdLinkage(ctx) == RlibLinkage {
		stdLinkage = "rlib-std"
	}

	rlibDepVariations := commonDepVariations
	if lib, ok := mod.compiler.(libraryInterface); !ok || !lib.sysroot() {
		rlibDepVariations = append(rlibDepVariations,
			blueprint.Variation{Mutator: "rust_stdlinkage", Variation: stdLinkage})
	}

	actx.AddVariationDependencies(
		append(rlibDepVariations, []blueprint.Variation{
			{Mutator: "rust_libraries", Variation: rlibVariation}}...),
		rlibDepTag, deps.Rlibs...)
	actx.AddVariationDependencies(
		append(commonDepVariations, []blueprint.Variation{
			{Mutator: "rust_libraries", Variation: dylibVariation}}...),
		dylibDepTag, deps.Dylibs...)

	if deps.Rustlibs != nil && !mod.compiler.Disabled() {
		autoDep := mod.compiler.(autoDeppable).autoDep(ctx)
		if autoDep.depTag == rlibDepTag {
			actx.AddVariationDependencies(
				append(rlibDepVariations, blueprint.Variation{Mutator: "rust_libraries", Variation: autoDep.variation}),
				autoDep.depTag, deps.Rustlibs...)
		} else {
			actx.AddVariationDependencies(
				append(commonDepVariations, blueprint.Variation{Mutator: "rust_libraries", Variation: autoDep.variation}),
				autoDep.depTag, deps.Rustlibs...)
		}
	}
	if deps.Stdlibs != nil {
		if mod.compiler.stdLinkage(ctx) == RlibLinkage {
			actx.AddVariationDependencies(
				append(commonDepVariations, blueprint.Variation{Mutator: "rust_libraries", Variation: "rlib"}),
				rlibDepTag, deps.Stdlibs...)
		} else {
			actx.AddVariationDependencies(
				append(commonDepVariations, blueprint.Variation{Mutator: "rust_libraries", Variation: "dylib"}),
				dylibDepTag, deps.Stdlibs...)
		}
	}
	actx.AddVariationDependencies(append(commonDepVariations,
		blueprint.Variation{Mutator: "link", Variation: "shared"}),
		cc.SharedDepTag(), deps.SharedLibs...)
	actx.AddVariationDependencies(append(commonDepVariations,
		blueprint.Variation{Mutator: "link", Variation: "static"}),
		cc.StaticDepTag(false), deps.StaticLibs...)
	actx.AddVariationDependencies(append(commonDepVariations,
		blueprint.Variation{Mutator: "link", Variation: "static"}),
		cc.StaticDepTag(true), deps.WholeStaticLibs...)

	actx.AddVariationDependencies(nil, cc.HeaderDepTag(), deps.HeaderLibs...)

	crtVariations := cc.GetCrtVariations(ctx, mod)
	if deps.CrtBegin != "" {
		actx.AddVariationDependencies(crtVariations, cc.CrtBeginDepTag, deps.CrtBegin)
	}
	if deps.CrtEnd != "" {
		actx.AddVariationDependencies(crtVariations, cc.CrtEndDepTag, deps.CrtEnd)
	}

	if mod.sourceProvider != nil {
		if bindgen, ok := mod.sourceProvider.(*bindgenDecorator); ok &&
			bindgen.Properties.Custom_bindgen != "" {
			actx.AddFarVariationDependencies(ctx.Config().BuildOSTarget.Variations(), customBindgenDepTag,
				bindgen.Properties.Custom_bindgen)
		}
	}
	// proc_macros are compiler plugins, and so we need the host arch variant as a dependendcy.
	actx.AddFarVariationDependencies(ctx.Config().BuildOSTarget.Variations(), procMacroDepTag, deps.ProcMacros...)
}

func BeginMutator(ctx android.BottomUpMutatorContext) {
	if mod, ok := ctx.Module().(*Module); ok && mod.Enabled() {
		mod.beginMutator(ctx)
	}
}

func (mod *Module) beginMutator(actx android.BottomUpMutatorContext) {
	ctx := &baseModuleContext{
		BaseModuleContext: actx,
	}

	mod.begin(ctx)
}

func (mod *Module) Name() string {
	name := mod.ModuleBase.Name()
	if p, ok := mod.compiler.(interface {
		Name(string) string
	}); ok {
		name = p.Name(name)
	}
	return name
}

func (mod *Module) disableClippy() {
	if mod.clippy != nil {
		mod.clippy.Properties.Clippy_lints = proptools.StringPtr("none")
	}
}

var _ android.HostToolProvider = (*Module)(nil)

func (mod *Module) HostToolPath() android.OptionalPath {
	if !mod.Host() {
		return android.OptionalPath{}
	}
	if binary, ok := mod.compiler.(*binaryDecorator); ok {
		return android.OptionalPathForPath(binary.baseCompiler.path)
	}
	return android.OptionalPath{}
}

var _ android.ApexModule = (*Module)(nil)

func (mod *Module) minSdkVersion() string {
	return String(mod.Properties.Min_sdk_version)
}

var _ android.ApexModule = (*Module)(nil)

// Implements android.ApexModule
func (mod *Module) ShouldSupportSdkVersion(ctx android.BaseModuleContext, sdkVersion android.ApiLevel) error {
	minSdkVersion := mod.minSdkVersion()
	if minSdkVersion == "apex_inherit" {
		return nil
	}
	if minSdkVersion == "" {
		return fmt.Errorf("min_sdk_version is not specificed")
	}

	// Not using nativeApiLevelFromUser because the context here is not
	// necessarily a native context.
	ver, err := android.ApiLevelFromUser(ctx, minSdkVersion)
	if err != nil {
		return err
	}

	if ver.GreaterThan(sdkVersion) {
		return fmt.Errorf("newer SDK(%v)", ver)
	}
	return nil
}

// Implements android.ApexModule
func (mod *Module) DepIsInSameApex(ctx android.BaseModuleContext, dep android.Module) bool {
	depTag := ctx.OtherModuleDependencyTag(dep)

	if ccm, ok := dep.(*cc.Module); ok {
		if ccm.HasStubsVariants() {
			if cc.IsSharedDepTag(depTag) {
				// dynamic dep to a stubs lib crosses APEX boundary
				return false
			}
			if cc.IsRuntimeDepTag(depTag) {
				// runtime dep to a stubs lib also crosses APEX boundary
				return false
			}

			if cc.IsHeaderDepTag(depTag) {
				return false
			}
		}
		if mod.Static() && cc.IsSharedDepTag(depTag) {
			// shared_lib dependency from a static lib is considered as crossing
			// the APEX boundary because the dependency doesn't actually is
			// linked; the dependency is used only during the compilation phase.
			return false
		}
	}

	if depTag == procMacroDepTag {
		return false
	}

	return true
}

// Overrides ApexModule.IsInstallabeToApex()
func (mod *Module) IsInstallableToApex() bool {
	if mod.compiler != nil {
		if lib, ok := mod.compiler.(*libraryDecorator); ok && (lib.shared() || lib.dylib()) {
			return true
		}
		if _, ok := mod.compiler.(*binaryDecorator); ok {
			return true
		}
	}
	return false
}

// If a library file has a "lib" prefix, extract the library name without the prefix.
func libNameFromFilePath(filepath android.Path) (string, bool) {
	libName := strings.TrimSuffix(filepath.Base(), filepath.Ext())
	if strings.HasPrefix(libName, "lib") {
		libName = libName[3:]
		return libName, true
	}
	return "", false
}

var Bool = proptools.Bool
var BoolDefault = proptools.BoolDefault
var String = proptools.String
var StringPtr = proptools.StringPtr

var _ android.OutputFileProducer = (*Module)(nil)
