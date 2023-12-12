// Copyright 2020 The Android Open Source Project
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
	"android/soong/android"
	"android/soong/cc"
	"android/soong/rust/config"
	"fmt"
	"github.com/google/blueprint"
)

type SanitizeProperties struct {
	// enable AddressSanitizer, HWAddressSanitizer, and others.
	Sanitize struct {
		Address   *bool `android:"arch_variant"`
		Hwaddress *bool `android:"arch_variant"`
		Fuzzer    *bool `android:"arch_variant"`
		Never     *bool `android:"arch_variant"`
	}
	SanitizerEnabled bool `blueprint:"mutated"`
	SanitizeDep      bool `blueprint:"mutated"`

	// Used when we need to place libraries in their own directory, such as ASAN.
	InSanitizerDir bool `blueprint:"mutated"`
}

var fuzzerFlags = []string{
	"-C passes='sancov'",

	"--cfg fuzzing",
	"-C llvm-args=-sanitizer-coverage-level=3",
	"-C llvm-args=-sanitizer-coverage-trace-compares",
	"-C llvm-args=-sanitizer-coverage-inline-8bit-counters",
	"-C llvm-args=-sanitizer-coverage-trace-geps",
	"-C llvm-args=-sanitizer-coverage-prune-blocks=0",

	// Sancov breaks with lto
	// TODO: Remove when https://bugs.llvm.org/show_bug.cgi?id=41734 is resolved and sancov works with LTO
	"-C lto=no",
}

var asanFlags = []string{
	"-Z sanitizer=address",
}

var hwasanFlags = []string{
	"-Z sanitizer=hwaddress",
	"-C target-feature=+tagged-globals",
}

func boolPtr(v bool) *bool {
	if v {
		return &v
	} else {
		return nil
	}
}

func init() {
}
func (sanitize *sanitize) props() []interface{} {
	return []interface{}{&sanitize.Properties}
}

func (sanitize *sanitize) begin(ctx BaseModuleContext) {
	s := sanitize.Properties.Sanitize

	// TODO:(b/178369775)
	// For now sanitizing is only supported on devices
	if ctx.Os() == android.Android && Bool(s.Fuzzer) {
		sanitize.Properties.SanitizerEnabled = true
	}

	if ctx.Os() == android.Android && Bool(s.Address) {
		sanitize.Properties.SanitizerEnabled = true
	}

	// HWASan requires AArch64 hardware feature (top-byte-ignore).
	if ctx.Arch().ArchType != android.Arm64 {
		s.Hwaddress = nil
	}

	if ctx.Os() == android.Android && Bool(s.Hwaddress) {
		sanitize.Properties.SanitizerEnabled = true
	}
}

type sanitize struct {
	Properties SanitizeProperties
}

func (sanitize *sanitize) flags(ctx ModuleContext, flags Flags, deps PathDeps) (Flags, PathDeps) {
	if !sanitize.Properties.SanitizerEnabled {
		return flags, deps
	}
	if Bool(sanitize.Properties.Sanitize.Fuzzer) {
		flags.RustFlags = append(flags.RustFlags, fuzzerFlags...)
		if ctx.Arch().ArchType == android.Arm64 {
			flags.RustFlags = append(flags.RustFlags, hwasanFlags...)
		} else {
			flags.RustFlags = append(flags.RustFlags, asanFlags...)
		}
	}
	if Bool(sanitize.Properties.Sanitize.Address) {
		flags.RustFlags = append(flags.RustFlags, asanFlags...)
	}
	if Bool(sanitize.Properties.Sanitize.Hwaddress) {
		flags.RustFlags = append(flags.RustFlags, hwasanFlags...)
	}
	return flags, deps
}

func (sanitize *sanitize) deps(ctx BaseModuleContext, deps Deps) Deps {
	return deps
}

func rustSanitizerRuntimeMutator(mctx android.BottomUpMutatorContext) {
	if mod, ok := mctx.Module().(*Module); ok && mod.sanitize != nil {
		if !mod.Enabled() {
			return
		}

		variations := mctx.Target().Variations()
		var depTag blueprint.DependencyTag
		var deps []string

		if mod.IsSanitizerEnabled(cc.Asan) ||
			(mod.IsSanitizerEnabled(cc.Fuzzer) && mctx.Arch().ArchType != android.Arm64) {
			variations = append(variations,
				blueprint.Variation{Mutator: "link", Variation: "shared"})
			depTag = cc.SharedDepTag()
			deps = []string{config.LibclangRuntimeLibrary(mod.toolchain(mctx), "asan")}
		} else if mod.IsSanitizerEnabled(cc.Hwasan) ||
			(mod.IsSanitizerEnabled(cc.Fuzzer) && mctx.Arch().ArchType == android.Arm64) {
			// TODO(b/180495975): HWASan for static Rust binaries isn't supported yet.
			if binary, ok := mod.compiler.(*binaryDecorator); ok {
				if Bool(binary.Properties.Static_executable) {
					mctx.ModuleErrorf("HWASan is not supported for static Rust executables yet.")
				}
			}

			if mod.StaticallyLinked() {
				variations = append(variations,
					blueprint.Variation{Mutator: "link", Variation: "static"})
				depTag = cc.StaticDepTag(false)
				deps = []string{config.LibclangRuntimeLibrary(mod.toolchain(mctx), "hwasan_static")}
			} else {
				variations = append(variations,
					blueprint.Variation{Mutator: "link", Variation: "shared"})
				depTag = cc.SharedDepTag()
				deps = []string{config.LibclangRuntimeLibrary(mod.toolchain(mctx), "hwasan")}
			}
		}

		mctx.AddFarVariationDependencies(variations, depTag, deps...)
	}
}

func (sanitize *sanitize) SetSanitizer(t cc.SanitizerType, b bool) {
	sanitizerSet := false
	switch t {
	case cc.Fuzzer:
		sanitize.Properties.Sanitize.Fuzzer = boolPtr(b)
		sanitizerSet = true
	case cc.Asan:
		sanitize.Properties.Sanitize.Address = boolPtr(b)
		sanitizerSet = true
	case cc.Hwasan:
		sanitize.Properties.Sanitize.Hwaddress = boolPtr(b)
		sanitizerSet = true
	default:
		panic(fmt.Errorf("setting unsupported sanitizerType %d", t))
	}
	if b && sanitizerSet {
		sanitize.Properties.SanitizerEnabled = true
	}
}

func (m *Module) UbsanRuntimeNeeded() bool {
	return false
}

func (m *Module) MinimalRuntimeNeeded() bool {
	return false
}

func (m *Module) UbsanRuntimeDep() bool {
	return false
}

func (m *Module) MinimalRuntimeDep() bool {
	return false
}

// Check if the sanitizer is explicitly disabled (as opposed to nil by
// virtue of not being set).
func (sanitize *sanitize) isSanitizerExplicitlyDisabled(t cc.SanitizerType) bool {
	if sanitize == nil {
		return false
	}
	if Bool(sanitize.Properties.Sanitize.Never) {
		return true
	}
	sanitizerVal := sanitize.getSanitizerBoolPtr(t)
	return sanitizerVal != nil && *sanitizerVal == false
}

// There isn't an analog of the method above (ie:isSanitizerExplicitlyEnabled)
// because enabling a sanitizer either directly (via the blueprint) or
// indirectly (via a mutator) sets the bool ptr to true, and you can't
// distinguish between the cases. It isn't needed though - both cases can be
// treated identically.
func (sanitize *sanitize) isSanitizerEnabled(t cc.SanitizerType) bool {
	if sanitize == nil || !sanitize.Properties.SanitizerEnabled {
		return false
	}

	sanitizerVal := sanitize.getSanitizerBoolPtr(t)
	return sanitizerVal != nil && *sanitizerVal == true
}

func (sanitize *sanitize) getSanitizerBoolPtr(t cc.SanitizerType) *bool {
	switch t {
	case cc.Fuzzer:
		return sanitize.Properties.Sanitize.Fuzzer
	case cc.Asan:
		return sanitize.Properties.Sanitize.Address
	case cc.Hwasan:
		return sanitize.Properties.Sanitize.Hwaddress
	default:
		return nil
	}
}

func (sanitize *sanitize) AndroidMk(ctx AndroidMkContext, entries *android.AndroidMkEntries) {
	// Add a suffix for hwasan rlib libraries to allow surfacing both the sanitized and
	// non-sanitized variants to make without a name conflict.
	if entries.Class == "RLIB_LIBRARIES" || entries.Class == "STATIC_LIBRARIES" {
		if sanitize.isSanitizerEnabled(cc.Hwasan) {
			entries.SubName += ".hwasan"
		}
	}
}

func (mod *Module) SanitizerSupported(t cc.SanitizerType) bool {
	if mod.Host() {
		return false
	}
	switch t {
	case cc.Fuzzer:
		return true
	case cc.Asan:
		return true
	case cc.Hwasan:
		return true
	default:
		return false
	}
}

func (mod *Module) IsSanitizerEnabled(t cc.SanitizerType) bool {
	return mod.sanitize.isSanitizerEnabled(t)
}

func (mod *Module) IsSanitizerExplicitlyDisabled(t cc.SanitizerType) bool {
	if mod.Host() {
		return true
	}

	// TODO(b/178365482): Rust/CC interop doesn't work just yet; don't sanitize rust_ffi modules until
	// linkage issues are resolved.
	if lib, ok := mod.compiler.(libraryInterface); ok {
		if lib.shared() || lib.static() {
			return true
		}
	}

	return mod.sanitize.isSanitizerExplicitlyDisabled(t)
}

func (mod *Module) SanitizeDep() bool {
	return mod.sanitize.Properties.SanitizeDep
}

func (mod *Module) SetSanitizer(t cc.SanitizerType, b bool) {
	if !Bool(mod.sanitize.Properties.Sanitize.Never) {
		mod.sanitize.SetSanitizer(t, b)
	}
}

func (mod *Module) SetSanitizeDep(b bool) {
	mod.sanitize.Properties.SanitizeDep = b
}

func (mod *Module) StaticallyLinked() bool {
	if lib, ok := mod.compiler.(libraryInterface); ok {
		return lib.rlib() || lib.static()
	} else if binary, ok := mod.compiler.(*binaryDecorator); ok {
		return Bool(binary.Properties.Static_executable)
	}
	return false
}

func (mod *Module) SetInSanitizerDir() {
	mod.sanitize.Properties.InSanitizerDir = true
}

func (mod *Module) SanitizeNever() bool {
	return Bool(mod.sanitize.Properties.Sanitize.Never)
}

var _ cc.PlatformSanitizeable = (*Module)(nil)

func IsSanitizableDependencyTag(tag blueprint.DependencyTag) bool {
	switch t := tag.(type) {
	case dependencyTag:
		return t.library
	default:
		return cc.IsSanitizableDependencyTag(tag)
	}
}

func (m *Module) SanitizableDepTagChecker() cc.SantizableDependencyTagChecker {
	return IsSanitizableDependencyTag
}
