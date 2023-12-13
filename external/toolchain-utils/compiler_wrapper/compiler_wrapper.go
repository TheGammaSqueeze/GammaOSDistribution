// Copyright 2019 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package main

import (
	"bytes"
	"fmt"
	"io"
	"path/filepath"
	"strings"
)

func callCompiler(env env, cfg *config, inputCmd *command) int {
	var compilerErr error

	if !filepath.IsAbs(inputCmd.Path) && !strings.HasPrefix(inputCmd.Path, ".") &&
		!strings.ContainsRune(inputCmd.Path, filepath.Separator) {
		if resolvedPath, err := resolveAgainstPathEnv(env, inputCmd.Path); err == nil {
			inputCmd = &command{
				Path:       resolvedPath,
				Args:       inputCmd.Args,
				EnvUpdates: inputCmd.EnvUpdates,
			}
		} else {
			compilerErr = err
		}
	}
	exitCode := 0
	if compilerErr == nil {
		exitCode, compilerErr = callCompilerInternal(env, cfg, inputCmd)
	}
	if compilerErr != nil {
		printCompilerError(env.stderr(), compilerErr)
		exitCode = 1
	}
	return exitCode
}

// Given the main builder path and the absolute path to our wrapper, returns the path to the
// 'real' compiler we should invoke.
func calculateAndroidWrapperPath(mainBuilderPath string, absWrapperPath string) string {
	// FIXME: This combination of using the directory of the symlink but the basename of the
	// link target is strange but is the logic that old android wrapper uses. Change this to use
	// directory and basename either from the absWrapperPath or from the builder.path, but don't
	// mix anymore.

	// We need to be careful here: path.Join Clean()s its result, so `./foo` will get
	// transformed to `foo`, which isn't good since we're passing this path to exec.
	basePart := filepath.Base(absWrapperPath) + ".real"
	if !strings.ContainsRune(mainBuilderPath, filepath.Separator) {
		return basePart
	}

	dirPart := filepath.Dir(mainBuilderPath)
	if cleanResult := filepath.Join(dirPart, basePart); strings.ContainsRune(cleanResult, filepath.Separator) {
		return cleanResult
	}

	return "." + string(filepath.Separator) + basePart
}

func callCompilerInternal(env env, cfg *config, inputCmd *command) (exitCode int, err error) {
	if err := checkUnsupportedFlags(inputCmd); err != nil {
		return 0, err
	}
	mainBuilder, err := newCommandBuilder(env, cfg, inputCmd)
	if err != nil {
		return 0, err
	}
	processPrintConfigFlag(mainBuilder)
	processPrintCmdlineFlag(mainBuilder)
	env = mainBuilder.env
	var compilerCmd *command
	clangSyntax := processClangSyntaxFlag(mainBuilder)
	if cfg.isAndroidWrapper {
		mainBuilder.path = calculateAndroidWrapperPath(mainBuilder.path, mainBuilder.absWrapperPath)
		switch mainBuilder.target.compilerType {
		case clangType:
			mainBuilder.addPreUserArgs(mainBuilder.cfg.clangFlags...)
			mainBuilder.addPreUserArgs(mainBuilder.cfg.commonFlags...)
			mainBuilder.addPostUserArgs(mainBuilder.cfg.clangPostFlags...)
			if _, err := processGomaCccFlags(mainBuilder); err != nil {
				return 0, err
			}
			compilerCmd = mainBuilder.build()
		case clangTidyType:
			compilerCmd = mainBuilder.build()
		default:
			return 0, newErrorwithSourceLocf("unsupported compiler: %s", mainBuilder.target.compiler)
		}
	} else {
		cSrcFile, tidyFlags, tidyMode := processClangTidyFlags(mainBuilder)
		if mainBuilder.target.compilerType == clangType {
			err := prepareClangCommand(mainBuilder)
			if err != nil {
				return 0, err
			}
			allowCCache := true
			if tidyMode != tidyModeNone {
				allowCCache = false
				clangCmdWithoutGomaAndCCache := mainBuilder.build()
				var err error
				switch tidyMode {
				case tidyModeTricium:
					if cfg.triciumNitsDir == "" {
						return 0, newErrorwithSourceLocf("tricium linting was requested, but no nits directory is configured")
					}
					err = runClangTidyForTricium(env, clangCmdWithoutGomaAndCCache, cSrcFile, cfg.triciumNitsDir, tidyFlags, cfg.crashArtifactsDir)
				case tidyModeAll:
					err = runClangTidy(env, clangCmdWithoutGomaAndCCache, cSrcFile, tidyFlags)
				default:
					panic(fmt.Sprintf("Unknown tidy mode: %v", tidyMode))
				}

				if err != nil {
					return 0, err
				}
			}
			if err := processGomaCCacheFlags(allowCCache, mainBuilder); err != nil {
				return 0, err
			}
			compilerCmd = mainBuilder.build()
		} else {
			if clangSyntax {
				allowCCache := false
				clangCmd, err := calcClangCommand(allowCCache, mainBuilder.clone())
				if err != nil {
					return 0, err
				}
				gccCmd, err := calcGccCommand(mainBuilder)
				if err != nil {
					return 0, err
				}
				return checkClangSyntax(env, clangCmd, gccCmd)
			}
			compilerCmd, err = calcGccCommand(mainBuilder)
			if err != nil {
				return 0, err
			}
		}
	}
	rusageLogfileName := getRusageLogFilename(env)
	bisectStage := getBisectStage(env)
	if shouldForceDisableWerror(env, cfg) {
		if rusageLogfileName != "" {
			return 0, newUserErrorf("GETRUSAGE is meaningless with FORCE_DISABLE_WERROR")
		}
		if bisectStage != "" {
			return 0, newUserErrorf("BISECT_STAGE is meaningless with FORCE_DISABLE_WERROR")
		}
		return doubleBuildWithWNoError(env, cfg, compilerCmd)
	}
	if shouldCompileWithFallback(env) {
		if rusageLogfileName != "" {
			return 0, newUserErrorf("GETRUSAGE is meaningless with FORCE_DISABLE_WERROR")
		}
		if bisectStage != "" {
			return 0, newUserErrorf("BISECT_STAGE is meaningless with FORCE_DISABLE_WERROR")
		}
		return compileWithFallback(env, cfg, compilerCmd, mainBuilder.absWrapperPath)
	}
	if rusageLogfileName != "" {
		if bisectStage != "" {
			return 0, newUserErrorf("BISECT_STAGE is meaningless with GETRUSAGE")
		}
		return logRusage(env, rusageLogfileName, compilerCmd)
	}
	if bisectStage != "" {
		compilerCmd, err = calcBisectCommand(env, cfg, bisectStage, compilerCmd)
		if err != nil {
			return 0, err
		}
	}
	// Note: We return an exit code only if the underlying env is not
	// really doing an exec, e.g. commandRecordingEnv.
	return wrapSubprocessErrorWithSourceLoc(compilerCmd, env.exec(compilerCmd))
}

func prepareClangCommand(builder *commandBuilder) (err error) {
	if !builder.cfg.isHostWrapper {
		processSysrootFlag(builder)
	}
	builder.addPreUserArgs(builder.cfg.clangFlags...)
	if builder.cfg.crashArtifactsDir != "" {
		builder.addPreUserArgs("-fcrash-diagnostics-dir=" + builder.cfg.crashArtifactsDir)
	}
	builder.addPostUserArgs(builder.cfg.clangPostFlags...)
	calcCommonPreUserArgs(builder)
	return processClangFlags(builder)
}

func calcClangCommand(allowCCache bool, builder *commandBuilder) (*command, error) {
	err := prepareClangCommand(builder)
	if err != nil {
		return nil, err
	}
	if err := processGomaCCacheFlags(allowCCache, builder); err != nil {
		return nil, err
	}
	return builder.build(), nil
}

func calcGccCommand(builder *commandBuilder) (*command, error) {
	if !builder.cfg.isHostWrapper {
		processSysrootFlag(builder)
	}
	builder.addPreUserArgs(builder.cfg.gccFlags...)
	if !builder.cfg.isHostWrapper {
		calcCommonPreUserArgs(builder)
	}
	processGccFlags(builder)
	if !builder.cfg.isHostWrapper {
		allowCCache := true
		if err := processGomaCCacheFlags(allowCCache, builder); err != nil {
			return nil, err
		}
	}
	return builder.build(), nil
}

func calcCommonPreUserArgs(builder *commandBuilder) {
	builder.addPreUserArgs(builder.cfg.commonFlags...)
	if !builder.cfg.isHostWrapper {
		processPieFlags(builder)
		processThumbCodeFlags(builder)
		processStackProtectorFlags(builder)
		processX86Flags(builder)
	}
	processSanitizerFlags(builder)
}

func processGomaCCacheFlags(allowCCache bool, builder *commandBuilder) (err error) {
	gomaccUsed := false
	if !builder.cfg.isHostWrapper {
		gomaccUsed, err = processGomaCccFlags(builder)
		if err != nil {
			return err
		}
	}
	if !gomaccUsed && allowCCache {
		processCCacheFlag(builder)
	}
	return nil
}

func getAbsWrapperPath(env env, wrapperCmd *command) (string, error) {
	wrapperPath := getAbsCmdPath(env, wrapperCmd)
	evaledCmdPath, err := filepath.EvalSymlinks(wrapperPath)
	if err != nil {
		return "", wrapErrorwithSourceLocf(err, "failed to evaluate symlinks for %s", wrapperPath)
	}
	return evaledCmdPath, nil
}

func printCompilerError(writer io.Writer, compilerErr error) {
	if _, ok := compilerErr.(userError); ok {
		fmt.Fprintf(writer, "%s\n", compilerErr)
	} else {
		emailAccount := "chromeos-toolchain"
		if isAndroidConfig() {
			emailAccount = "android-llvm"
		}
		fmt.Fprintf(writer,
			"Internal error. Please report to %s@google.com.\n%s\n",
			emailAccount, compilerErr)
	}
}

func needStdinTee(inputCmd *command) bool {
	lastArg := ""
	for _, arg := range inputCmd.Args {
		if arg == "-" && lastArg != "-o" {
			return true
		}
		lastArg = arg
	}
	return false
}

func prebufferStdinIfNeeded(env env, inputCmd *command) (getStdin func() io.Reader, err error) {
	// We pre-buffer the entirety of stdin, since the compiler may exit mid-invocation with an
	// error, which may leave stdin partially read.
	if !needStdinTee(inputCmd) {
		// This won't produce deterministic input to the compiler, but stdin shouldn't
		// matter in this case, so...
		return env.stdin, nil
	}

	stdinBuffer := &bytes.Buffer{}
	if _, err := stdinBuffer.ReadFrom(env.stdin()); err != nil {
		return nil, wrapErrorwithSourceLocf(err, "prebuffering stdin")
	}

	return func() io.Reader { return bytes.NewReader(stdinBuffer.Bytes()) }, nil
}
