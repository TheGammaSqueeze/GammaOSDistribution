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

package cc

import (
	"android/soong/android"
	"android/soong/genrule"
)

// sdkMutator sets a creates a platform and an SDK variant for modules
// that set sdk_version, and ignores sdk_version for the platform
// variant.  The SDK variant will be used for embedding in APKs
// that may be installed on older platforms.  Apexes use their own
// variants that enforce backwards compatibility.
func sdkMutator(ctx android.BottomUpMutatorContext) {
	if ctx.Os() != android.Android {
		return
	}

	switch m := ctx.Module().(type) {
	case LinkableInterface:
		if m.AlwaysSdk() {
			if !m.UseSdk() && !m.SplitPerApiLevel() {
				ctx.ModuleErrorf("UseSdk() must return true when AlwaysSdk is set, did the factory forget to set Sdk_version?")
			}
			ctx.CreateVariations("sdk")
		} else if m.UseSdk() || m.SplitPerApiLevel() {
			modules := ctx.CreateVariations("", "sdk")

			// Clear the sdk_version property for the platform (non-SDK) variant so later code
			// doesn't get confused by it.
			modules[0].(*Module).Properties.Sdk_version = nil

			// Mark the SDK variant.
			modules[1].(*Module).Properties.IsSdkVariant = true

			if ctx.Config().UnbundledBuildApps() {
				// For an unbundled apps build, hide the platform variant from Make.
				modules[0].(*Module).Properties.HideFromMake = true
				modules[0].(*Module).Properties.PreventInstall = true
			} else {
				// For a platform build, mark the SDK variant so that it gets a ".sdk" suffix when
				// exposed to Make.
				modules[1].(*Module).Properties.SdkAndPlatformVariantVisibleToMake = true
				modules[1].(*Module).Properties.PreventInstall = true
			}
			ctx.AliasVariation("")
		} else {
			if m, ok := ctx.Module().(*Module); ok {
				// Clear the sdk_version property for modules that don't have an SDK variant so
				// later code doesn't get confused by it.
				m.Properties.Sdk_version = nil
			}
			ctx.CreateVariations("")
			ctx.AliasVariation("")
		}
	case *genrule.Module:
		if p, ok := m.Extra.(*GenruleExtraProperties); ok {
			if String(p.Sdk_version) != "" {
				ctx.CreateVariations("", "sdk")
			} else {
				ctx.CreateVariations("")
			}
			ctx.AliasVariation("")
		}
	case *snapshot:
		ctx.CreateVariations("")
	}
}
