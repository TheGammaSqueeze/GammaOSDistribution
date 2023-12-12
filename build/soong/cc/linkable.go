package cc

import (
	"android/soong/android"
	"android/soong/bazel/cquery"

	"github.com/google/blueprint"
)

// PlatformSanitizeable is an interface for sanitizing platform modules.
type PlatformSanitizeable interface {
	LinkableInterface

	// SanitizePropDefined returns whether the Sanitizer properties struct for this module is defined.
	SanitizePropDefined() bool

	// IsDependencyRoot returns whether a module is of a type which cannot be a linkage dependency
	// of another module. For example, cc_binary and rust_binary represent dependency roots as other
	// modules cannot have linkage dependencies against these types.
	IsDependencyRoot() bool

	// IsSanitizerEnabled returns whether a sanitizer is enabled.
	IsSanitizerEnabled(t SanitizerType) bool

	// IsSanitizerExplicitlyDisabled returns whether a sanitizer has been explicitly disabled (set to false) rather
	// than left undefined.
	IsSanitizerExplicitlyDisabled(t SanitizerType) bool

	// SanitizeDep returns the value of the SanitizeDep flag, which is set if a module is a dependency of a
	// sanitized module.
	SanitizeDep() bool

	// SetSanitizer enables or disables the specified sanitizer type if it's supported, otherwise this should panic.
	SetSanitizer(t SanitizerType, b bool)

	// SetSanitizerDep returns true if the module is statically linked.
	SetSanitizeDep(b bool)

	// StaticallyLinked returns true if the module is statically linked.
	StaticallyLinked() bool

	// SetInSanitizerDir sets the module installation to the sanitizer directory.
	SetInSanitizerDir()

	// SanitizeNever returns true if this module should never be sanitized.
	SanitizeNever() bool

	// SanitizerSupported returns true if a sanitizer type is supported by this modules compiler.
	SanitizerSupported(t SanitizerType) bool

	// MinimalRuntimeDep returns true if this module needs to link the minimal UBSan runtime,
	// either because it requires it or because a dependent module which requires it to be linked in this module.
	MinimalRuntimeDep() bool

	// UbsanRuntimeDep returns true if this module needs to link the full UBSan runtime,
	// either because it requires it or because a dependent module which requires it to be linked in this module.
	UbsanRuntimeDep() bool

	// UbsanRuntimeNeeded returns true if the full UBSan runtime is required by this module.
	UbsanRuntimeNeeded() bool

	// MinimalRuntimeNeeded returns true if the minimal UBSan runtime is required by this module
	MinimalRuntimeNeeded() bool

	// SanitizableDepTagChecker returns a SantizableDependencyTagChecker function type.
	SanitizableDepTagChecker() SantizableDependencyTagChecker
}

// SantizableDependencyTagChecker functions check whether or not a dependency
// tag can be sanitized. These functions should return true if the tag can be
// sanitized, otherwise they should return false. These functions should also
// handle all possible dependency tags in the dependency tree. For example,
// Rust modules can depend on both Rust and CC libraries, so the Rust module
// implementation should handle tags from both.
type SantizableDependencyTagChecker func(tag blueprint.DependencyTag) bool

// Snapshottable defines those functions necessary for handling module snapshots.
type Snapshottable interface {
	// SnapshotHeaders returns a list of header paths provided by this module.
	SnapshotHeaders() android.Paths

	// ExcludeFromVendorSnapshot returns true if this module should be otherwise excluded from the vendor snapshot.
	ExcludeFromVendorSnapshot() bool

	// ExcludeFromRecoverySnapshot returns true if this module should be otherwise excluded from the recovery snapshot.
	ExcludeFromRecoverySnapshot() bool

	// SnapshotLibrary returns true if this module is a snapshot library.
	IsSnapshotLibrary() bool

	// SnapshotRuntimeLibs returns a list of libraries needed by this module at runtime but which aren't build dependencies.
	SnapshotRuntimeLibs() []string

	// SnapshotSharedLibs returns the list of shared library dependencies for this module.
	SnapshotSharedLibs() []string

	// IsSnapshotPrebuilt returns true if this module is a snapshot prebuilt.
	IsSnapshotPrebuilt() bool
}

// LinkableInterface is an interface for a type of module that is linkable in a C++ library.
type LinkableInterface interface {
	android.Module
	Snapshottable

	Module() android.Module
	CcLibrary() bool
	CcLibraryInterface() bool

	// BaseModuleName returns the android.ModuleBase.BaseModuleName() value for this module.
	BaseModuleName() string

	OutputFile() android.OptionalPath
	CoverageFiles() android.Paths

	NonCcVariants() bool

	SelectedStl() string

	BuildStaticVariant() bool
	BuildSharedVariant() bool
	SetStatic()
	SetShared()
	IsPrebuilt() bool
	Toc() android.OptionalPath

	Host() bool

	InRamdisk() bool
	OnlyInRamdisk() bool

	InVendorRamdisk() bool
	OnlyInVendorRamdisk() bool

	InRecovery() bool
	OnlyInRecovery() bool

	InVendor() bool

	UseSdk() bool

	// IsLlndk returns true for both LLNDK (public) and LLNDK-private libs.
	IsLlndk() bool

	// IsLlndkPublic returns true only for LLNDK (public) libs.
	IsLlndkPublic() bool

	// HasLlndkStubs returns true if this library has a variant that will build LLNDK stubs.
	HasLlndkStubs() bool

	// NeedsLlndkVariants returns true if this module has LLNDK stubs or provides LLNDK headers.
	NeedsLlndkVariants() bool

	// NeedsVendorPublicLibraryVariants returns true if this module has vendor public library stubs.
	NeedsVendorPublicLibraryVariants() bool

	//StubsVersion returns the stubs version for this module.
	StubsVersion() string

	// UseVndk returns true if the module is using VNDK libraries instead of the libraries in /system/lib or /system/lib64.
	// "product" and "vendor" variant modules return true for this function.
	// When BOARD_VNDK_VERSION is set, vendor variants of "vendor_available: true", "vendor: true",
	// "soc_specific: true" and more vendor installed modules are included here.
	// When PRODUCT_PRODUCT_VNDK_VERSION is set, product variants of "vendor_available: true" or
	// "product_specific: true" modules are included here.
	UseVndk() bool

	// IsVndkSp returns true if this is a VNDK-SP module.
	IsVndkSp() bool

	MustUseVendorVariant() bool
	IsVndk() bool
	IsVndkExt() bool
	IsVndkPrivate() bool
	HasVendorVariant() bool
	HasProductVariant() bool
	HasNonSystemVariants() bool
	InProduct() bool

	// SubName returns the modules SubName, used for image and NDK/SDK variations.
	SubName() string

	SdkVersion() string
	MinSdkVersion() string
	AlwaysSdk() bool
	IsSdkVariant() bool

	SplitPerApiLevel() bool

	// SetPreventInstall sets the PreventInstall property to 'true' for this module.
	SetPreventInstall()
	// SetHideFromMake sets the HideFromMake property to 'true' for this module.
	SetHideFromMake()

	// KernelHeadersDecorator returns true if this is a kernel headers decorator module.
	// This is specific to cc and should always return false for all other packages.
	KernelHeadersDecorator() bool

	// HiddenFromMake returns true if this module is hidden from Make.
	HiddenFromMake() bool

	// RelativeInstallPath returns the relative install path for this module.
	RelativeInstallPath() string

	// Binary returns true if this is a binary module.
	Binary() bool

	// Object returns true if this is an object module.
	Object() bool

	// Rlib returns true if this is an rlib module.
	Rlib() bool

	// Dylib returns true if this is an dylib module.
	Dylib() bool

	// Static returns true if this is a static library module.
	Static() bool

	// Shared returns true if this is a shared library module.
	Shared() bool

	// Header returns true if this is a library headers module.
	Header() bool

	// EverInstallable returns true if the module is ever installable
	EverInstallable() bool

	// PreventInstall returns true if this module is prevented from installation.
	PreventInstall() bool

	// InstallInData returns true if this module is installed in data.
	InstallInData() bool

	// Installable returns a bool pointer to the module installable property.
	Installable() *bool

	// Symlinks returns a list of symlinks that should be created for this module.
	Symlinks() []string

	// VndkVersion returns the VNDK version string for this module.
	VndkVersion() string
}

var (
	// Dependency tag for crtbegin, an object file responsible for initialization.
	CrtBeginDepTag = dependencyTag{name: "crtbegin"}
	// Dependency tag for crtend, an object file responsible for program termination.
	CrtEndDepTag = dependencyTag{name: "crtend"}
	// Dependency tag for coverage library.
	CoverageDepTag = dependencyTag{name: "coverage"}
)

// GetImageVariantType returns the ImageVariantType string value for the given module
// (these are defined in cc/image.go).
func GetImageVariantType(c LinkableInterface) ImageVariantType {
	if c.Host() {
		return hostImageVariant
	} else if c.InVendor() {
		return vendorImageVariant
	} else if c.InProduct() {
		return productImageVariant
	} else if c.InRamdisk() {
		return ramdiskImageVariant
	} else if c.InVendorRamdisk() {
		return vendorRamdiskImageVariant
	} else if c.InRecovery() {
		return recoveryImageVariant
	} else {
		return coreImageVariant
	}
}

// DepTagMakeSuffix returns the makeSuffix value of a particular library dependency tag.
// Returns an empty string if not a library dependency tag.
func DepTagMakeSuffix(depTag blueprint.DependencyTag) string {
	if libDepTag, ok := depTag.(libraryDependencyTag); ok {
		return libDepTag.makeSuffix
	}
	return ""
}

// SharedDepTag returns the dependency tag for any C++ shared libraries.
func SharedDepTag() blueprint.DependencyTag {
	return libraryDependencyTag{Kind: sharedLibraryDependency}
}

// StaticDepTag returns the dependency tag for any C++ static libraries.
func StaticDepTag(wholeStatic bool) blueprint.DependencyTag {
	return libraryDependencyTag{Kind: staticLibraryDependency, wholeStatic: wholeStatic}
}

// IsWholeStaticLib whether a dependency tag is a whole static library dependency.
func IsWholeStaticLib(depTag blueprint.DependencyTag) bool {
	if tag, ok := depTag.(libraryDependencyTag); ok {
		return tag.wholeStatic
	}
	return false
}

// HeaderDepTag returns the dependency tag for any C++ "header-only" libraries.
func HeaderDepTag() blueprint.DependencyTag {
	return libraryDependencyTag{Kind: headerLibraryDependency}
}

// SharedLibraryInfo is a provider to propagate information about a shared C++ library.
type SharedLibraryInfo struct {
	SharedLibrary           android.Path
	UnstrippedSharedLibrary android.Path
	Target                  android.Target

	TableOfContents       android.OptionalPath
	CoverageSharedLibrary android.OptionalPath

	StaticAnalogue *StaticLibraryInfo
}

var SharedLibraryInfoProvider = blueprint.NewProvider(SharedLibraryInfo{})

// SharedStubLibrary is a struct containing information about a stub shared library.
// Stub libraries are used for cross-APEX dependencies; when a library is to depend on a shared
// library in another APEX, it must depend on the stub version of that library.
type SharedStubLibrary struct {
	// The version of the stub (corresponding to the stable version of the shared library being
	// stubbed).
	Version           string
	SharedLibraryInfo SharedLibraryInfo
	FlagExporterInfo  FlagExporterInfo
}

// SharedLibraryStubsInfo is a provider to propagate information about all shared library stubs
// which are dependencies of a library.
// Stub libraries are used for cross-APEX dependencies; when a library is to depend on a shared
// library in another APEX, it must depend on the stub version of that library.
type SharedLibraryStubsInfo struct {
	SharedStubLibraries []SharedStubLibrary

	IsLLNDK bool
}

var SharedLibraryStubsProvider = blueprint.NewProvider(SharedLibraryStubsInfo{})

// StaticLibraryInfo is a provider to propagate information about a static C++ library.
type StaticLibraryInfo struct {
	StaticLibrary android.Path
	Objects       Objects
	ReuseObjects  Objects

	// This isn't the actual transitive DepSet, shared library dependencies have been
	// converted into static library analogues.  It is only used to order the static
	// library dependencies that were specified for the current module.
	TransitiveStaticLibrariesForOrdering *android.DepSet
}

var StaticLibraryInfoProvider = blueprint.NewProvider(StaticLibraryInfo{})

// HeaderLibraryInfo is a marker provider that identifies a module as a header library.
type HeaderLibraryInfo struct {
}

// HeaderLibraryInfoProvider is a marker provider that identifies a module as a header library.
var HeaderLibraryInfoProvider = blueprint.NewProvider(HeaderLibraryInfo{})

// FlagExporterInfo is a provider to propagate transitive library information
// pertaining to exported include paths and flags.
type FlagExporterInfo struct {
	IncludeDirs       android.Paths // Include directories to be included with -I
	SystemIncludeDirs android.Paths // System include directories to be included with -isystem
	Flags             []string      // Exported raw flags.
	Deps              android.Paths
	GeneratedHeaders  android.Paths
}

var FlagExporterInfoProvider = blueprint.NewProvider(FlagExporterInfo{})

// flagExporterInfoFromCcInfo populates FlagExporterInfo provider with information from Bazel.
func flagExporterInfoFromCcInfo(ctx android.ModuleContext, ccInfo cquery.CcInfo) FlagExporterInfo {

	includes := android.PathsForBazelOut(ctx, ccInfo.Includes)
	systemIncludes := android.PathsForBazelOut(ctx, ccInfo.SystemIncludes)

	return FlagExporterInfo{
		IncludeDirs:       android.FirstUniquePaths(includes),
		SystemIncludeDirs: android.FirstUniquePaths(systemIncludes),
	}
}
