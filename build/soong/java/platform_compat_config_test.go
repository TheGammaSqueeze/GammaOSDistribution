// Copyright 2021 Google Inc. All rights reserved.
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
	"testing"

	"android/soong/android"
)

func TestPlatformCompatConfig(t *testing.T) {
	result := android.GroupFixturePreparers(
		PrepareForTestWithPlatformCompatConfig,
		android.FixtureWithRootAndroidBp(`
			platform_compat_config {
				name: "myconfig2",
			}
			platform_compat_config {
				name: "myconfig1",
			}
			platform_compat_config {
				name: "myconfig3",
			}
		`),
	).RunTest(t)

	CheckMergedCompatConfigInputs(t, result, "myconfig",
		"out/soong/.intermediates/myconfig1/myconfig1_meta.xml",
		"out/soong/.intermediates/myconfig2/myconfig2_meta.xml",
		"out/soong/.intermediates/myconfig3/myconfig3_meta.xml",
	)
}
