// Copyright 2014 Google Inc. All rights reserved.
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

package bootstrap

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"path/filepath"
	"runtime"
	"runtime/debug"
	"runtime/pprof"
	"runtime/trace"

	"github.com/google/blueprint"
	"github.com/google/blueprint/deptools"
)

type Args struct {
	OutFile                  string
	GlobFile                 string
	DepFile                  string
	DocFile                  string
	Cpuprofile               string
	Memprofile               string
	DelveListen              string
	DelvePath                string
	TraceFile                string
	RunGoTests               bool
	UseValidations           bool
	NoGC                     bool
	EmptyNinjaFile           bool
	BuildDir                 string
	ModuleListFile           string
	NinjaBuildDir            string
	TopFile                  string
	GeneratingPrimaryBuilder bool

	PrimaryBuilderInvocations []PrimaryBuilderInvocation
}

var (
	CmdlineArgs Args
	absSrcDir   string
)

func init() {
	flag.StringVar(&CmdlineArgs.OutFile, "o", "build.ninja", "the Ninja file to output")
	flag.StringVar(&CmdlineArgs.GlobFile, "globFile", "build-globs.ninja", "the Ninja file of globs to output")
	flag.StringVar(&CmdlineArgs.BuildDir, "b", ".", "the build output directory")
	flag.StringVar(&CmdlineArgs.NinjaBuildDir, "n", "", "the ninja builddir directory")
	flag.StringVar(&CmdlineArgs.DepFile, "d", "", "the dependency file to output")
	flag.StringVar(&CmdlineArgs.DocFile, "docs", "", "build documentation file to output")
	flag.StringVar(&CmdlineArgs.Cpuprofile, "cpuprofile", "", "write cpu profile to file")
	flag.StringVar(&CmdlineArgs.TraceFile, "trace", "", "write trace to file")
	flag.StringVar(&CmdlineArgs.Memprofile, "memprofile", "", "write memory profile to file")
	flag.BoolVar(&CmdlineArgs.NoGC, "nogc", false, "turn off GC for debugging")
	flag.BoolVar(&CmdlineArgs.RunGoTests, "t", false, "build and run go tests during bootstrap")
	flag.BoolVar(&CmdlineArgs.UseValidations, "use-validations", false, "use validations to depend on go tests")
	flag.StringVar(&CmdlineArgs.ModuleListFile, "l", "", "file that lists filepaths to parse")
	flag.BoolVar(&CmdlineArgs.EmptyNinjaFile, "empty-ninja-file", false, "write out a 0-byte ninja file")
}

func Main(ctx *blueprint.Context, config interface{}, generatingPrimaryBuilder bool) {
	if !flag.Parsed() {
		flag.Parse()
	}

	if flag.NArg() != 1 {
		fatalf("no Blueprints file specified")
	}

	CmdlineArgs.TopFile = flag.Arg(0)
	CmdlineArgs.GeneratingPrimaryBuilder = generatingPrimaryBuilder
	ninjaDeps := RunBlueprint(CmdlineArgs, ctx, config)
	err := deptools.WriteDepFile(CmdlineArgs.DepFile, CmdlineArgs.OutFile, ninjaDeps)
	if err != nil {
		fatalf("Cannot write depfile '%s': %s", CmdlineArgs.DepFile, err)
	}
}

func PrimaryBuilderExtraFlags(args Args, globFile, mainNinjaFile string) []string {
	result := make([]string, 0)

	if args.RunGoTests {
		result = append(result, "-t")
	}

	result = append(result, "-l", args.ModuleListFile)
	result = append(result, "-globFile", globFile)
	result = append(result, "-o", mainNinjaFile)

	if args.EmptyNinjaFile {
		result = append(result, "--empty-ninja-file")
	}

	if args.DelveListen != "" {
		result = append(result, "--delve_listen", args.DelveListen)
	}

	if args.DelvePath != "" {
		result = append(result, "--delve_path", args.DelvePath)
	}

	return result
}

func writeEmptyGlobFile(path string) {
	err := os.MkdirAll(filepath.Dir(path), 0777)
	if err != nil {
		fatalf("Failed to create parent directories of empty ninja glob file '%s': %s", path, err)
	}

	if _, err := os.Stat(path); os.IsNotExist(err) {
		err = ioutil.WriteFile(path, nil, 0666)
		if err != nil {
			fatalf("Failed to create empty ninja glob file '%s': %s", path, err)
		}
	}
}

// Returns the list of dependencies the emitted Ninja files has. These can be
// written to the .d file for the output so that it is correctly rebuilt when
// needed in case Blueprint is itself invoked from Ninja
func RunBlueprint(args Args, ctx *blueprint.Context, config interface{}) []string {
	runtime.GOMAXPROCS(runtime.NumCPU())

	if args.NoGC {
		debug.SetGCPercent(-1)
	}

	absSrcDir = ctx.SrcDir()

	if args.Cpuprofile != "" {
		f, err := os.Create(absolutePath(args.Cpuprofile))
		if err != nil {
			fatalf("error opening cpuprofile: %s", err)
		}
		pprof.StartCPUProfile(f)
		defer f.Close()
		defer pprof.StopCPUProfile()
	}

	if args.TraceFile != "" {
		f, err := os.Create(absolutePath(args.TraceFile))
		if err != nil {
			fatalf("error opening trace: %s", err)
		}
		trace.Start(f)
		defer f.Close()
		defer trace.Stop()
	}

	srcDir := filepath.Dir(args.TopFile)

	ninjaDeps := make([]string, 0)

	if args.ModuleListFile != "" {
		ctx.SetModuleListFile(args.ModuleListFile)
		ninjaDeps = append(ninjaDeps, args.ModuleListFile)
	} else {
		fatalf("-l <moduleListFile> is required and must be nonempty")
	}
	filesToParse, err := ctx.ListModulePaths(srcDir)
	if err != nil {
		fatalf("could not enumerate files: %v\n", err.Error())
	}

	buildDir := config.(BootstrapConfig).BuildDir()

	stage := StageMain
	if args.GeneratingPrimaryBuilder {
		stage = StagePrimary
	}

	primaryBuilderNinjaGlobFile := absolutePath(filepath.Join(args.BuildDir, bootstrapSubDir, "build-globs.ninja"))
	mainNinjaFile := filepath.Join("$buildDir", "build.ninja")

	writeEmptyGlobFile(primaryBuilderNinjaGlobFile)

	var invocations []PrimaryBuilderInvocation

	if args.PrimaryBuilderInvocations != nil {
		invocations = args.PrimaryBuilderInvocations
	} else {
		primaryBuilderArgs := PrimaryBuilderExtraFlags(args, primaryBuilderNinjaGlobFile, mainNinjaFile)
		primaryBuilderArgs = append(primaryBuilderArgs, args.TopFile)

		invocations = []PrimaryBuilderInvocation{{
			Inputs:  []string{args.TopFile},
			Outputs: []string{mainNinjaFile},
			Args:    primaryBuilderArgs,
		}}
	}

	bootstrapConfig := &Config{
		stage: stage,

		topLevelBlueprintsFile:    args.TopFile,
		globFile:                  primaryBuilderNinjaGlobFile,
		runGoTests:                args.RunGoTests,
		useValidations:            args.UseValidations,
		primaryBuilderInvocations: invocations,
	}

	ctx.RegisterBottomUpMutator("bootstrap_plugin_deps", pluginDeps)
	ctx.RegisterModuleType("bootstrap_go_package", newGoPackageModuleFactory(bootstrapConfig))
	ctx.RegisterModuleType("bootstrap_go_binary", newGoBinaryModuleFactory(bootstrapConfig, false))
	ctx.RegisterModuleType("blueprint_go_binary", newGoBinaryModuleFactory(bootstrapConfig, true))
	ctx.RegisterSingletonType("bootstrap", newSingletonFactory(bootstrapConfig))

	ctx.RegisterSingletonType("glob", globSingletonFactory(bootstrapConfig, ctx))

	blueprintFiles, errs := ctx.ParseFileList(filepath.Dir(args.TopFile), filesToParse, config)
	if len(errs) > 0 {
		fatalErrors(errs)
	}

	// Add extra ninja file dependencies
	ninjaDeps = append(ninjaDeps, blueprintFiles...)

	extraDeps, errs := ctx.ResolveDependencies(config)
	if len(errs) > 0 {
		fatalErrors(errs)
	}
	ninjaDeps = append(ninjaDeps, extraDeps...)

	if args.DocFile != "" {
		err := writeDocs(ctx, config, absolutePath(args.DocFile))
		if err != nil {
			fatalErrors([]error{err})
		}
		return nil
	}

	if c, ok := config.(ConfigStopBefore); ok {
		if c.StopBefore() == StopBeforePrepareBuildActions {
			return ninjaDeps
		}
	}

	extraDeps, errs = ctx.PrepareBuildActions(config)
	if len(errs) > 0 {
		fatalErrors(errs)
	}
	ninjaDeps = append(ninjaDeps, extraDeps...)

	if c, ok := config.(ConfigStopBefore); ok {
		if c.StopBefore() == StopBeforeWriteNinja {
			return ninjaDeps
		}
	}

	const outFilePermissions = 0666
	var out io.StringWriter
	var f *os.File
	var buf *bufio.Writer

	if args.EmptyNinjaFile {
		if err := ioutil.WriteFile(absolutePath(args.OutFile), []byte(nil), outFilePermissions); err != nil {
			fatalf("error writing empty Ninja file: %s", err)
		}
	}

	if stage != StageMain || !args.EmptyNinjaFile {
		f, err = os.OpenFile(absolutePath(args.OutFile), os.O_WRONLY|os.O_CREATE|os.O_TRUNC, outFilePermissions)
		if err != nil {
			fatalf("error opening Ninja file: %s", err)
		}
		buf = bufio.NewWriterSize(f, 16*1024*1024)
		out = buf
	} else {
		out = ioutil.Discard.(io.StringWriter)
	}

	if args.GlobFile != "" {
		buffer, errs := generateGlobNinjaFile(bootstrapConfig, config, ctx.Globs)
		if len(errs) > 0 {
			fatalErrors(errs)
		}

		err = ioutil.WriteFile(absolutePath(args.GlobFile), buffer, outFilePermissions)
		if err != nil {
			fatalf("error writing %s: %s", args.GlobFile, err)
		}
	}

	err = ctx.WriteBuildFile(out)
	if err != nil {
		fatalf("error writing Ninja file contents: %s", err)
	}

	if buf != nil {
		err = buf.Flush()
		if err != nil {
			fatalf("error flushing Ninja file contents: %s", err)
		}
	}

	if f != nil {
		err = f.Close()
		if err != nil {
			fatalf("error closing Ninja file: %s", err)
		}
	}

	if c, ok := config.(ConfigRemoveAbandonedFilesUnder); ok {
		under, except := c.RemoveAbandonedFilesUnder(buildDir)
		err := removeAbandonedFilesUnder(ctx, srcDir, buildDir, under, except)
		if err != nil {
			fatalf("error removing abandoned files: %s", err)
		}
	}

	if args.Memprofile != "" {
		f, err := os.Create(absolutePath(args.Memprofile))
		if err != nil {
			fatalf("error opening memprofile: %s", err)
		}
		defer f.Close()
		pprof.WriteHeapProfile(f)
	}

	return ninjaDeps
}

func fatalf(format string, args ...interface{}) {
	fmt.Printf(format, args...)
	fmt.Print("\n")
	os.Exit(1)
}

func fatalErrors(errs []error) {
	red := "\x1b[31m"
	unred := "\x1b[0m"

	for _, err := range errs {
		switch err := err.(type) {
		case *blueprint.BlueprintError,
			*blueprint.ModuleError,
			*blueprint.PropertyError:
			fmt.Printf("%serror:%s %s\n", red, unred, err.Error())
		default:
			fmt.Printf("%sinternal error:%s %s\n", red, unred, err)
		}
	}
	os.Exit(1)
}

func absolutePath(path string) string {
	if filepath.IsAbs(path) {
		return path
	}
	return filepath.Join(absSrcDir, path)
}
