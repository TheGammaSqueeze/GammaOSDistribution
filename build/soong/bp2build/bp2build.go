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

package bp2build

import (
	"android/soong/android"
	"fmt"
	"os"
)

// Codegen is the backend of bp2build. The code generator is responsible for
// writing .bzl files that are equivalent to Android.bp files that are capable
// of being built with Bazel.
func Codegen(ctx *CodegenContext) CodegenMetrics {
	// This directory stores BUILD files that could be eventually checked-in.
	bp2buildDir := android.PathForOutput(ctx, "bp2build")
	android.RemoveAllOutputDir(bp2buildDir)

	buildToTargets, metrics := GenerateBazelTargets(ctx, true)
	bp2buildFiles := CreateBazelFiles(nil, buildToTargets, ctx.mode)
	writeFiles(ctx, bp2buildDir, bp2buildFiles)

	soongInjectionDir := android.PathForOutput(ctx, "soong_injection")
	writeFiles(ctx, soongInjectionDir, CreateSoongInjectionFiles())

	return metrics
}

// Get the output directory and create it if it doesn't exist.
func getOrCreateOutputDir(outputDir android.OutputPath, ctx android.PathContext, dir string) android.OutputPath {
	dirPath := outputDir.Join(ctx, dir)
	android.CreateOutputDirIfNonexistent(dirPath, os.ModePerm)
	return dirPath
}

// writeFiles materializes a list of BazelFile rooted at outputDir.
func writeFiles(ctx android.PathContext, outputDir android.OutputPath, files []BazelFile) {
	for _, f := range files {
		p := getOrCreateOutputDir(outputDir, ctx, f.Dir).Join(ctx, f.Basename)
		if err := writeFile(ctx, p, f.Contents); err != nil {
			panic(fmt.Errorf("Failed to write %q (dir %q) due to %q", f.Basename, f.Dir, err))
		}
	}
}

func writeFile(ctx android.PathContext, pathToFile android.OutputPath, content string) error {
	// These files are made editable to allow users to modify and iterate on them
	// in the source tree.
	return android.WriteFileToOutputDir(pathToFile, []byte(content), 0644)
}
