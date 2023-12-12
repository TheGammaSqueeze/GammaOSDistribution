// Copyright (C) 2019 The Android Open Source Project
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
	"sort"
	"strings"

	"github.com/google/blueprint"
	"github.com/google/blueprint/proptools"
)

// Extracted from SdkAware to make it easier to define custom subsets of the
// SdkAware interface and improve code navigation within the IDE.
//
// In addition to its use in SdkAware this interface must also be implemented by
// APEX to specify the SDKs required by that module and its contents. e.g. APEX
// is expected to implement RequiredSdks() by reading its own properties like
// `uses_sdks`.
type RequiredSdks interface {
	// The set of SDKs required by an APEX and its contents.
	RequiredSdks() SdkRefs
}

// Provided to improve code navigation with the IDE.
type sdkAwareWithoutModule interface {
	RequiredSdks

	// SdkMemberComponentName will return the name to use for a component of this module based on the
	// base name of this module.
	//
	// The baseName is the name returned by ModuleBase.BaseModuleName(), i.e. the name specified in
	// the name property in the .bp file so will not include the prebuilt_ prefix.
	//
	// The componentNameCreator is a func for creating the name of a component from the base name of
	// the module, e.g. it could just append ".component" to the name passed in.
	//
	// This is intended to be called by prebuilt modules that create component models. It is because
	// prebuilt module base names come in a variety of different forms:
	// * unversioned - this is the same as the source module.
	// * internal to an sdk - this is the unversioned name prefixed by the base name of the sdk
	//   module.
	// * versioned - this is the same as the internal with the addition of an "@<version>" suffix.
	//
	// While this can be called from a source module in that case it will behave the same way as the
	// unversioned name and return the result of calling the componentNameCreator func on the supplied
	// base name.
	//
	// e.g. Assuming the componentNameCreator func simply appends ".component" to the name passed in
	// then this will work as follows:
	// * An unversioned name of "foo" will return "foo.component".
	// * An internal to the sdk name of "sdk_foo" will return "sdk_foo.component".
	// * A versioned name of "sdk_foo@current" will return "sdk_foo.component@current".
	//
	// Note that in the latter case the ".component" suffix is added before the version. Adding it
	// after would change the version.
	SdkMemberComponentName(baseName string, componentNameCreator func(string) string) string

	sdkBase() *SdkBase
	MakeMemberOf(sdk SdkRef)
	IsInAnySdk() bool

	// IsVersioned determines whether the module is versioned, i.e. has a name of the form
	// <name>@<version>
	IsVersioned() bool

	ContainingSdk() SdkRef
	MemberName() string
	BuildWithSdks(sdks SdkRefs)
}

// SdkAware is the interface that must be supported by any module to become a member of SDK or to be
// built with SDK
type SdkAware interface {
	Module
	sdkAwareWithoutModule
}

// SdkRef refers to a version of an SDK
type SdkRef struct {
	Name    string
	Version string
}

// Unversioned determines if the SdkRef is referencing to the unversioned SDK module
func (s SdkRef) Unversioned() bool {
	return s.Version == ""
}

// String returns string representation of this SdkRef for debugging purpose
func (s SdkRef) String() string {
	if s.Name == "" {
		return "(No Sdk)"
	}
	if s.Unversioned() {
		return s.Name
	}
	return s.Name + string(SdkVersionSeparator) + s.Version
}

// SdkVersionSeparator is a character used to separate an sdk name and its version
const SdkVersionSeparator = '@'

// ParseSdkRef parses a `name@version` style string into a corresponding SdkRef struct
func ParseSdkRef(ctx BaseModuleContext, str string, property string) SdkRef {
	tokens := strings.Split(str, string(SdkVersionSeparator))
	if len(tokens) < 1 || len(tokens) > 2 {
		ctx.PropertyErrorf(property, "%q does not follow name@version syntax", str)
		return SdkRef{Name: "invalid sdk name", Version: "invalid sdk version"}
	}

	name := tokens[0]

	var version string
	if len(tokens) == 2 {
		version = tokens[1]
	}

	return SdkRef{Name: name, Version: version}
}

type SdkRefs []SdkRef

// Contains tells if the given SdkRef is in this list of SdkRef's
func (refs SdkRefs) Contains(s SdkRef) bool {
	for _, r := range refs {
		if r == s {
			return true
		}
	}
	return false
}

type sdkProperties struct {
	// The SDK that this module is a member of. nil if it is not a member of any SDK
	ContainingSdk *SdkRef `blueprint:"mutated"`

	// The list of SDK names and versions that are used to build this module
	RequiredSdks SdkRefs `blueprint:"mutated"`

	// Name of the module that this sdk member is representing
	Sdk_member_name *string
}

// SdkBase is a struct that is expected to be included in module types to implement the SdkAware
// interface. InitSdkAwareModule should be called to initialize this struct.
type SdkBase struct {
	properties sdkProperties
	module     SdkAware
}

func (s *SdkBase) sdkBase() *SdkBase {
	return s
}

func (s *SdkBase) SdkMemberComponentName(baseName string, componentNameCreator func(string) string) string {
	if s.MemberName() == "" {
		return componentNameCreator(baseName)
	} else {
		index := strings.LastIndex(baseName, "@")
		unversionedName := baseName[:index]
		unversionedComponentName := componentNameCreator(unversionedName)
		versionSuffix := baseName[index:]
		return unversionedComponentName + versionSuffix
	}
}

// MakeMemberOf sets this module to be a member of a specific SDK
func (s *SdkBase) MakeMemberOf(sdk SdkRef) {
	s.properties.ContainingSdk = &sdk
}

// IsInAnySdk returns true if this module is a member of any SDK
func (s *SdkBase) IsInAnySdk() bool {
	return s.properties.ContainingSdk != nil
}

// IsVersioned returns true if this module is versioned.
func (s *SdkBase) IsVersioned() bool {
	return strings.Contains(s.module.Name(), "@")
}

// ContainingSdk returns the SDK that this module is a member of
func (s *SdkBase) ContainingSdk() SdkRef {
	if s.properties.ContainingSdk != nil {
		return *s.properties.ContainingSdk
	}
	return SdkRef{Name: "", Version: ""}
}

// MemberName returns the name of the module that this SDK member is overriding
func (s *SdkBase) MemberName() string {
	return proptools.String(s.properties.Sdk_member_name)
}

// BuildWithSdks is used to mark that this module has to be built with the given SDK(s).
func (s *SdkBase) BuildWithSdks(sdks SdkRefs) {
	s.properties.RequiredSdks = sdks
}

// RequiredSdks returns the SDK(s) that this module has to be built with
func (s *SdkBase) RequiredSdks() SdkRefs {
	return s.properties.RequiredSdks
}

// InitSdkAwareModule initializes the SdkBase struct. This must be called by all modules including
// SdkBase.
func InitSdkAwareModule(m SdkAware) {
	base := m.sdkBase()
	base.module = m
	m.AddProperties(&base.properties)
}

// IsModuleInVersionedSdk returns true if the module is an versioned sdk.
func IsModuleInVersionedSdk(module Module) bool {
	if s, ok := module.(SdkAware); ok {
		if !s.ContainingSdk().Unversioned() {
			return true
		}
	}
	return false
}

// Provide support for generating the build rules which will build the snapshot.
type SnapshotBuilder interface {
	// Copy src to the dest (which is a snapshot relative path) and add the dest
	// to the zip
	CopyToSnapshot(src Path, dest string)

	// Unzip the supplied zip into the snapshot relative directory destDir.
	UnzipToSnapshot(zipPath Path, destDir string)

	// Add a new prebuilt module to the snapshot. The returned module
	// must be populated with the module type specific properties. The following
	// properties will be automatically populated.
	//
	// * name
	// * sdk_member_name
	// * prefer
	//
	// This will result in two Soong modules being generated in the Android. One
	// that is versioned, coupled to the snapshot version and marked as
	// prefer=true. And one that is not versioned, not marked as prefer=true and
	// will only be used if the equivalently named non-prebuilt module is not
	// present.
	AddPrebuiltModule(member SdkMember, moduleType string) BpModule

	// The property tag to use when adding a property to a BpModule that contains
	// references to other sdk members. Using this will ensure that the reference
	// is correctly output for both versioned and unversioned prebuilts in the
	// snapshot.
	//
	// "required: true" means that the property must only contain references
	// to other members of the sdk. Passing a reference to a module that is not a
	// member of the sdk will result in a build error.
	//
	// "required: false" means that the property can contain references to modules
	// that are either members or not members of the sdk. If a reference is to a
	// module that is a non member then the reference is left unchanged, i.e. it
	// is not transformed as references to members are.
	//
	// The handling of the member names is dependent on whether it is an internal or
	// exported member. An exported member is one whose name is specified in one of
	// the member type specific properties. An internal member is one that is added
	// due to being a part of an exported (or other internal) member and is not itself
	// an exported member.
	//
	// Member names are handled as follows:
	// * When creating the unversioned form of the module the name is left unchecked
	//   unless the member is internal in which case it is transformed into an sdk
	//   specific name, i.e. by prefixing with the sdk name.
	//
	// * When creating the versioned form of the module the name is transformed into
	//   a versioned sdk specific name, i.e. by prefixing with the sdk name and
	//   suffixing with the version.
	//
	// e.g.
	// bpPropertySet.AddPropertyWithTag("libs", []string{"member1", "member2"}, builder.SdkMemberReferencePropertyTag(true))
	SdkMemberReferencePropertyTag(required bool) BpPropertyTag
}

type BpPropertyTag interface{}

// A set of properties for use in a .bp file.
type BpPropertySet interface {
	// Add a property, the value can be one of the following types:
	// * string
	// * array of the above
	// * bool
	// For these types it is an error if multiple properties with the same name
	// are added.
	//
	// * pointer to a struct
	// * BpPropertySet
	//
	// A pointer to a Blueprint-style property struct is first converted into a
	// BpPropertySet by traversing the fields and adding their values as
	// properties in a BpPropertySet. A field with a struct value is itself
	// converted into a BpPropertySet before adding.
	//
	// Adding a BpPropertySet is done as follows:
	// * If no property with the name exists then the BpPropertySet is added
	//   directly to this property. Care must be taken to ensure that it does not
	//   introduce a cycle.
	// * If a property exists with the name and the current value is a
	//   BpPropertySet then every property of the new BpPropertySet is added to
	//   the existing BpPropertySet.
	// * Otherwise, if a property exists with the name then it is an error.
	AddProperty(name string, value interface{})

	// Add a property with an associated tag
	AddPropertyWithTag(name string, value interface{}, tag BpPropertyTag)

	// Add a property set with the specified name and return so that additional
	// properties can be added.
	AddPropertySet(name string) BpPropertySet

	// Add comment for property (or property set).
	AddCommentForProperty(name, text string)
}

// A .bp module definition.
type BpModule interface {
	BpPropertySet

	// ModuleType returns the module type of the module
	ModuleType() string

	// Name returns the name of the module or "" if no name has been specified.
	Name() string
}

// An individual member of the SDK, includes all of the variants that the SDK
// requires.
type SdkMember interface {
	// The name of the member.
	Name() string

	// All the variants required by the SDK.
	Variants() []SdkAware
}

// SdkMemberTypeDependencyTag is the interface that a tag must implement in order to allow the
// dependent module to be automatically added to the sdk.
type SdkMemberTypeDependencyTag interface {
	blueprint.DependencyTag

	// SdkMemberType returns the SdkMemberType that will be used to automatically add the child module
	// to the sdk.
	//
	// Returning nil will prevent the module being added to the sdk.
	SdkMemberType(child Module) SdkMemberType

	// ExportMember determines whether a module added to the sdk through this tag will be exported
	// from the sdk or not.
	//
	// An exported member is added to the sdk using its own name, e.g. if "foo" was exported from sdk
	// "bar" then its prebuilt would be simply called "foo". A member can be added to the sdk via
	// multiple tags and if any of those tags returns true from this method then the membe will be
	// exported. Every module added directly to the sdk via one of the member type specific
	// properties, e.g. java_libs, will automatically be exported.
	//
	// If a member is not exported then it is treated as an internal implementation detail of the
	// sdk and so will be added with an sdk specific name. e.g. if "foo" was an internal member of sdk
	// "bar" then its prebuilt would be called "bar_foo". Additionally its visibility will be set to
	// "//visibility:private" so it will not be accessible from outside its Android.bp file.
	ExportMember() bool
}

var _ SdkMemberTypeDependencyTag = (*sdkMemberDependencyTag)(nil)
var _ ReplaceSourceWithPrebuilt = (*sdkMemberDependencyTag)(nil)

type sdkMemberDependencyTag struct {
	blueprint.BaseDependencyTag
	memberType SdkMemberType
	export     bool
}

func (t *sdkMemberDependencyTag) SdkMemberType(_ Module) SdkMemberType {
	return t.memberType
}

func (t *sdkMemberDependencyTag) ExportMember() bool {
	return t.export
}

// Prevent dependencies from the sdk/module_exports onto their members from being
// replaced with a preferred prebuilt.
func (t *sdkMemberDependencyTag) ReplaceSourceWithPrebuilt() bool {
	return false
}

// DependencyTagForSdkMemberType creates an SdkMemberTypeDependencyTag that will cause any
// dependencies added by the tag to be added to the sdk as the specified SdkMemberType and exported
// (or not) as specified by the export parameter.
func DependencyTagForSdkMemberType(memberType SdkMemberType, export bool) SdkMemberTypeDependencyTag {
	return &sdkMemberDependencyTag{memberType: memberType, export: export}
}

// Interface that must be implemented for every type that can be a member of an
// sdk.
//
// The basic implementation should look something like this, where ModuleType is
// the name of the module type being supported.
//
//    type moduleTypeSdkMemberType struct {
//        android.SdkMemberTypeBase
//    }
//
//    func init() {
//        android.RegisterSdkMemberType(&moduleTypeSdkMemberType{
//            SdkMemberTypeBase: android.SdkMemberTypeBase{
//                PropertyName: "module_types",
//            },
//        }
//    }
//
//    ...methods...
//
type SdkMemberType interface {
	// The name of the member type property on an sdk module.
	SdkPropertyName() string

	// RequiresBpProperty returns true if this member type requires its property to be usable within
	// an Android.bp file.
	RequiresBpProperty() bool

	// True if the member type supports the sdk/sdk_snapshot, false otherwise.
	UsableWithSdkAndSdkSnapshot() bool

	// Return true if prebuilt host artifacts may be specific to the host OS. Only
	// applicable to modules where HostSupported() is true. If this is true,
	// snapshots will list each host OS variant explicitly and disable all other
	// host OS'es.
	IsHostOsDependent() bool

	// Add dependencies from the SDK module to all the module variants the member
	// type contributes to the SDK. `names` is the list of module names given in
	// the member type property (as returned by SdkPropertyName()) in the SDK
	// module. The exact set of variants required is determined by the SDK and its
	// properties. The dependencies must be added with the supplied tag.
	//
	// The BottomUpMutatorContext provided is for the SDK module.
	AddDependencies(mctx BottomUpMutatorContext, dependencyTag blueprint.DependencyTag, names []string)

	// Return true if the supplied module is an instance of this member type.
	//
	// This is used to check the type of each variant before added to the
	// SdkMember. Returning false will cause an error to be logged expaining that
	// the module is not allowed in whichever sdk property it was added.
	IsInstance(module Module) bool

	// UsesSourceModuleTypeInSnapshot returns true when the AddPrebuiltModule() method returns a
	// source module type.
	UsesSourceModuleTypeInSnapshot() bool

	// Add a prebuilt module that the sdk will populate.
	//
	// The sdk module code generates the snapshot as follows:
	//
	// * A properties struct of type SdkMemberProperties is created for each variant and
	//   populated with information from the variant by calling PopulateFromVariant(SdkAware)
	//   on the struct.
	//
	// * An additional properties struct is created into which the common properties will be
	//   added.
	//
	// * The variant property structs are analysed to find exported (capitalized) fields which
	//   have common values. Those fields are cleared and the common value added to the common
	//   properties.
	//
	//   A field annotated with a tag of `sdk:"keep"` will be treated as if it
	//   was not capitalized, i.e. not optimized for common values.
	//
	//   A field annotated with a tag of `android:"arch_variant"` will be allowed to have
	//   values that differ by arch, fields not tagged as such must have common values across
	//   all variants.
	//
	// * Additional field tags can be specified on a field that will ignore certain values
	//   for the purpose of common value optimization. A value that is ignored must have the
	//   default value for the property type. This is to ensure that significant value are not
	//   ignored by accident. The purpose of this is to allow the snapshot generation to reflect
	//   the behavior of the runtime. e.g. if a property is ignored on the host then a property
	//   that is common for android can be treated as if it was common for android and host as
	//   the setting for host is ignored anyway.
	//   * `sdk:"ignored-on-host" - this indicates the property is ignored on the host variant.
	//
	// * The sdk module type populates the BpModule structure, creating the arch specific
	//   structure and calls AddToPropertySet(...) on the properties struct to add the member
	//   specific properties in the correct place in the structure.
	//
	AddPrebuiltModule(ctx SdkMemberContext, member SdkMember) BpModule

	// Create a structure into which variant specific properties can be added.
	CreateVariantPropertiesStruct() SdkMemberProperties
}

// Base type for SdkMemberType implementations.
type SdkMemberTypeBase struct {
	PropertyName string

	// When set to true BpPropertyNotRequired indicates that the member type does not require the
	// property to be specifiable in an Android.bp file.
	BpPropertyNotRequired bool

	SupportsSdk     bool
	HostOsDependent bool

	// When set to true UseSourceModuleTypeInSnapshot indicates that the member type creates a source
	// module type in its SdkMemberType.AddPrebuiltModule() method. That prevents the sdk snapshot
	// code from automatically adding a prefer: true flag.
	UseSourceModuleTypeInSnapshot bool
}

func (b *SdkMemberTypeBase) SdkPropertyName() string {
	return b.PropertyName
}

func (b *SdkMemberTypeBase) RequiresBpProperty() bool {
	return !b.BpPropertyNotRequired
}

func (b *SdkMemberTypeBase) UsableWithSdkAndSdkSnapshot() bool {
	return b.SupportsSdk
}

func (b *SdkMemberTypeBase) IsHostOsDependent() bool {
	return b.HostOsDependent
}

func (b *SdkMemberTypeBase) UsesSourceModuleTypeInSnapshot() bool {
	return b.UseSourceModuleTypeInSnapshot
}

// Encapsulates the information about registered SdkMemberTypes.
type SdkMemberTypesRegistry struct {
	// The list of types sorted by property name.
	list []SdkMemberType

	// The key that uniquely identifies this registry instance.
	key OnceKey
}

func (r *SdkMemberTypesRegistry) copyAndAppend(memberType SdkMemberType) *SdkMemberTypesRegistry {
	oldList := r.list

	// Copy the slice just in case this is being read while being modified, e.g. when testing.
	list := make([]SdkMemberType, 0, len(oldList)+1)
	list = append(list, oldList...)
	list = append(list, memberType)

	// Sort the member types by their property name to ensure that registry order has no effect
	// on behavior.
	sort.Slice(list, func(i1, i2 int) bool {
		t1 := list[i1]
		t2 := list[i2]

		return t1.SdkPropertyName() < t2.SdkPropertyName()
	})

	// Generate a key that identifies the slice of SdkMemberTypes by joining the property names
	// from all the SdkMemberType .
	var properties []string
	for _, t := range list {
		properties = append(properties, t.SdkPropertyName())
	}
	key := NewOnceKey(strings.Join(properties, "|"))

	// Create a new registry so the pointer uniquely identifies the set of registered types.
	return &SdkMemberTypesRegistry{
		list: list,
		key:  key,
	}
}

func (r *SdkMemberTypesRegistry) RegisteredTypes() []SdkMemberType {
	return r.list
}

func (r *SdkMemberTypesRegistry) UniqueOnceKey() OnceKey {
	// Use the pointer to the registry as the unique key.
	return NewCustomOnceKey(r)
}

// The set of registered SdkMemberTypes, one for sdk module and one for module_exports.
var ModuleExportsMemberTypes = &SdkMemberTypesRegistry{}
var SdkMemberTypes = &SdkMemberTypesRegistry{}

// Register an SdkMemberType object to allow them to be used in the sdk and sdk_snapshot module
// types.
func RegisterSdkMemberType(memberType SdkMemberType) {
	// All member types are usable with module_exports.
	ModuleExportsMemberTypes = ModuleExportsMemberTypes.copyAndAppend(memberType)

	// Only those that explicitly indicate it are usable with sdk.
	if memberType.UsableWithSdkAndSdkSnapshot() {
		SdkMemberTypes = SdkMemberTypes.copyAndAppend(memberType)
	}
}

// Base structure for all implementations of SdkMemberProperties.
//
// Contains common properties that apply across many different member types.
type SdkMemberPropertiesBase struct {
	// The number of unique os types supported by the member variants.
	//
	// If a member has a variant with more than one os type then it will need to differentiate
	// the locations of any of their prebuilt files in the snapshot by os type to prevent them
	// from colliding. See OsPrefix().
	//
	// This property is the same for all variants of a member and so would be optimized away
	// if it was not explicitly kept.
	Os_count int `sdk:"keep"`

	// The os type for which these properties refer.
	//
	// Provided to allow a member to differentiate between os types in the locations of their
	// prebuilt files when it supports more than one os type.
	//
	// This property is the same for all os type specific variants of a member and so would be
	// optimized away if it was not explicitly kept.
	Os OsType `sdk:"keep"`

	// The setting to use for the compile_multilib property.
	Compile_multilib string `android:"arch_variant"`
}

// The os prefix to use for any file paths in the sdk.
//
// Is an empty string if the member only provides variants for a single os type, otherwise
// is the OsType.Name.
func (b *SdkMemberPropertiesBase) OsPrefix() string {
	if b.Os_count == 1 {
		return ""
	} else {
		return b.Os.Name
	}
}

func (b *SdkMemberPropertiesBase) Base() *SdkMemberPropertiesBase {
	return b
}

// Interface to be implemented on top of a structure that contains variant specific
// information.
//
// Struct fields that are capitalized are examined for common values to extract. Fields
// that are not capitalized are assumed to be arch specific.
type SdkMemberProperties interface {
	// Access the base structure.
	Base() *SdkMemberPropertiesBase

	// Populate this structure with information from the variant.
	PopulateFromVariant(ctx SdkMemberContext, variant Module)

	// Add the information from this structure to the property set.
	AddToPropertySet(ctx SdkMemberContext, propertySet BpPropertySet)
}

// Provides access to information common to a specific member.
type SdkMemberContext interface {

	// The module context of the sdk common os variant which is creating the snapshot.
	SdkModuleContext() ModuleContext

	// The builder of the snapshot.
	SnapshotBuilder() SnapshotBuilder

	// The type of the member.
	MemberType() SdkMemberType

	// The name of the member.
	//
	// Provided for use by sdk members to create a member specific location within the snapshot
	// into which to copy the prebuilt files.
	Name() string
}

// ExportedComponentsInfo contains information about the components that this module exports to an
// sdk snapshot.
//
// A component of a module is a child module that the module creates and which forms an integral
// part of the functionality that the creating module provides. A component module is essentially
// owned by its creator and is tightly coupled to the creator and other components.
//
// e.g. the child modules created by prebuilt_apis are not components because they are not tightly
// coupled to the prebuilt_apis module. Once they are created the prebuilt_apis ignores them. The
// child impl and stub library created by java_sdk_library (and corresponding import) are components
// because the creating module depends upon them in order to provide some of its own functionality.
//
// A component is exported if it is part of an sdk snapshot. e.g. The xml and impl child modules are
// components but they are not exported as they are not part of an sdk snapshot.
//
// This information is used by the sdk snapshot generation code to ensure that it does not create
// an sdk snapshot that contains a declaration of the component module and the module that creates
// it as that would result in duplicate modules when attempting to use the snapshot. e.g. a snapshot
// that included the java_sdk_library_import "foo" and also a java_import "foo.stubs" would fail
// as there would be two modules called "foo.stubs".
type ExportedComponentsInfo struct {
	// The names of the exported components.
	Components []string
}

var ExportedComponentsInfoProvider = blueprint.NewProvider(ExportedComponentsInfo{})
