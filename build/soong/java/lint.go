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

import (
	"fmt"
	"sort"
	"strings"

	"github.com/google/blueprint/proptools"

	"android/soong/android"
	"android/soong/java/config"
	"android/soong/remoteexec"
)

// lint checks automatically enforced for modules that have different min_sdk_version than
// sdk_version
var updatabilityChecks = []string{"NewApi"}

type LintProperties struct {
	// Controls for running Android Lint on the module.
	Lint struct {

		// If true, run Android Lint on the module.  Defaults to true.
		Enabled *bool

		// Flags to pass to the Android Lint tool.
		Flags []string

		// Checks that should be treated as fatal.
		Fatal_checks []string

		// Checks that should be treated as errors.
		Error_checks []string

		// Checks that should be treated as warnings.
		Warning_checks []string

		// Checks that should be skipped.
		Disabled_checks []string

		// Modules that provide extra lint checks
		Extra_check_modules []string

		// Name of the file that lint uses as the baseline. Defaults to "lint-baseline.xml".
		Baseline_filename *string

		// If true, baselining updatability lint checks (e.g. NewApi) is prohibited. Defaults to false.
		Strict_updatability_linting *bool
	}
}

type linter struct {
	name                    string
	manifest                android.Path
	mergedManifest          android.Path
	srcs                    android.Paths
	srcJars                 android.Paths
	resources               android.Paths
	classpath               android.Paths
	classes                 android.Path
	extraLintCheckJars      android.Paths
	test                    bool
	library                 bool
	minSdkVersion           string
	targetSdkVersion        string
	compileSdkVersion       string
	compileSdkKind          android.SdkKind
	javaLanguageLevel       string
	kotlinLanguageLevel     string
	outputs                 lintOutputs
	properties              LintProperties
	extraMainlineLintErrors []string

	reports android.Paths

	buildModuleReportZip bool
}

type lintOutputs struct {
	html android.Path
	text android.Path
	xml  android.Path

	depSets LintDepSets
}

type lintOutputsIntf interface {
	lintOutputs() *lintOutputs
}

type lintDepSetsIntf interface {
	LintDepSets() LintDepSets

	// Methods used to propagate strict_updatability_linting values.
	getStrictUpdatabilityLinting() bool
	setStrictUpdatabilityLinting(bool)
}

type LintDepSets struct {
	HTML, Text, XML *android.DepSet
}

type LintDepSetsBuilder struct {
	HTML, Text, XML *android.DepSetBuilder
}

func NewLintDepSetBuilder() LintDepSetsBuilder {
	return LintDepSetsBuilder{
		HTML: android.NewDepSetBuilder(android.POSTORDER),
		Text: android.NewDepSetBuilder(android.POSTORDER),
		XML:  android.NewDepSetBuilder(android.POSTORDER),
	}
}

func (l LintDepSetsBuilder) Direct(html, text, xml android.Path) LintDepSetsBuilder {
	l.HTML.Direct(html)
	l.Text.Direct(text)
	l.XML.Direct(xml)
	return l
}

func (l LintDepSetsBuilder) Transitive(depSets LintDepSets) LintDepSetsBuilder {
	if depSets.HTML != nil {
		l.HTML.Transitive(depSets.HTML)
	}
	if depSets.Text != nil {
		l.Text.Transitive(depSets.Text)
	}
	if depSets.XML != nil {
		l.XML.Transitive(depSets.XML)
	}
	return l
}

func (l LintDepSetsBuilder) Build() LintDepSets {
	return LintDepSets{
		HTML: l.HTML.Build(),
		Text: l.Text.Build(),
		XML:  l.XML.Build(),
	}
}

func (l *linter) LintDepSets() LintDepSets {
	return l.outputs.depSets
}

func (l *linter) getStrictUpdatabilityLinting() bool {
	return BoolDefault(l.properties.Lint.Strict_updatability_linting, false)
}

func (l *linter) setStrictUpdatabilityLinting(strictLinting bool) {
	l.properties.Lint.Strict_updatability_linting = &strictLinting
}

var _ lintDepSetsIntf = (*linter)(nil)

var _ lintOutputsIntf = (*linter)(nil)

func (l *linter) lintOutputs() *lintOutputs {
	return &l.outputs
}

func (l *linter) enabled() bool {
	return BoolDefault(l.properties.Lint.Enabled, true)
}

func (l *linter) deps(ctx android.BottomUpMutatorContext) {
	if !l.enabled() {
		return
	}

	extraCheckModules := l.properties.Lint.Extra_check_modules

	if checkOnly := ctx.Config().Getenv("ANDROID_LINT_CHECK"); checkOnly != "" {
		if checkOnlyModules := ctx.Config().Getenv("ANDROID_LINT_CHECK_EXTRA_MODULES"); checkOnlyModules != "" {
			extraCheckModules = strings.Split(checkOnlyModules, ",")
		}
	}

	ctx.AddFarVariationDependencies(ctx.Config().BuildOSCommonTarget.Variations(),
		extraLintCheckTag, extraCheckModules...)
}

// lintPaths contains the paths to lint's inputs and outputs to make it easier to pass them
// around.
type lintPaths struct {
	projectXML android.WritablePath
	configXML  android.WritablePath
	cacheDir   android.WritablePath
	homeDir    android.WritablePath
	srcjarDir  android.WritablePath
}

func lintRBEExecStrategy(ctx android.ModuleContext) string {
	return ctx.Config().GetenvWithDefault("RBE_LINT_EXEC_STRATEGY", remoteexec.LocalExecStrategy)
}

func (l *linter) writeLintProjectXML(ctx android.ModuleContext, rule *android.RuleBuilder) lintPaths {
	projectXMLPath := android.PathForModuleOut(ctx, "lint", "project.xml")
	// Lint looks for a lint.xml file next to the project.xml file, give it one.
	configXMLPath := android.PathForModuleOut(ctx, "lint", "lint.xml")
	cacheDir := android.PathForModuleOut(ctx, "lint", "cache")
	homeDir := android.PathForModuleOut(ctx, "lint", "home")

	srcJarDir := android.PathForModuleOut(ctx, "lint", "srcjars")
	srcJarList := zipSyncCmd(ctx, rule, srcJarDir, l.srcJars)

	cmd := rule.Command().
		BuiltTool("lint_project_xml").
		FlagWithOutput("--project_out ", projectXMLPath).
		FlagWithOutput("--config_out ", configXMLPath).
		FlagWithArg("--name ", ctx.ModuleName())

	if l.library {
		cmd.Flag("--library")
	}
	if l.test {
		cmd.Flag("--test")
	}
	if l.manifest != nil {
		cmd.FlagWithInput("--manifest ", l.manifest)
	}
	if l.mergedManifest != nil {
		cmd.FlagWithInput("--merged_manifest ", l.mergedManifest)
	}

	// TODO(ccross): some of the files in l.srcs are generated sources and should be passed to
	// lint separately.
	srcsList := android.PathForModuleOut(ctx, "lint-srcs.list")
	cmd.FlagWithRspFileInputList("--srcs ", srcsList, l.srcs)

	cmd.FlagWithInput("--generated_srcs ", srcJarList)

	if len(l.resources) > 0 {
		resourcesList := android.PathForModuleOut(ctx, "lint-resources.list")
		cmd.FlagWithRspFileInputList("--resources ", resourcesList, l.resources)
	}

	if l.classes != nil {
		cmd.FlagWithInput("--classes ", l.classes)
	}

	cmd.FlagForEachInput("--classpath ", l.classpath)

	cmd.FlagForEachInput("--extra_checks_jar ", l.extraLintCheckJars)

	cmd.FlagWithArg("--root_dir ", "$PWD")

	// The cache tag in project.xml is relative to the root dir, or the project.xml file if
	// the root dir is not set.
	cmd.FlagWithArg("--cache_dir ", cacheDir.String())

	cmd.FlagWithInput("@",
		android.PathForSource(ctx, "build/soong/java/lint_defaults.txt"))

	cmd.FlagForEachArg("--error_check ", l.extraMainlineLintErrors)
	cmd.FlagForEachArg("--disable_check ", l.properties.Lint.Disabled_checks)
	cmd.FlagForEachArg("--warning_check ", l.properties.Lint.Warning_checks)
	cmd.FlagForEachArg("--error_check ", l.properties.Lint.Error_checks)
	cmd.FlagForEachArg("--fatal_check ", l.properties.Lint.Fatal_checks)

	if l.getStrictUpdatabilityLinting() {
		// Verify the module does not baseline issues that endanger safe updatability.
		if baselinePath := l.getBaselineFilepath(ctx); baselinePath.Valid() {
			cmd.FlagWithInput("--baseline ", baselinePath.Path())
			cmd.FlagForEachArg("--disallowed_issues ", updatabilityChecks)
		}
	}

	return lintPaths{
		projectXML: projectXMLPath,
		configXML:  configXMLPath,
		cacheDir:   cacheDir,
		homeDir:    homeDir,
	}

}

// generateManifest adds a command to the rule to write a simple manifest that contains the
// minSdkVersion and targetSdkVersion for modules (like java_library) that don't have a manifest.
func (l *linter) generateManifest(ctx android.ModuleContext, rule *android.RuleBuilder) android.WritablePath {
	manifestPath := android.PathForModuleOut(ctx, "lint", "AndroidManifest.xml")

	rule.Command().Text("(").
		Text(`echo "<?xml version='1.0' encoding='utf-8'?>" &&`).
		Text(`echo "<manifest xmlns:android='http://schemas.android.com/apk/res/android'" &&`).
		Text(`echo "    android:versionCode='1' android:versionName='1' >" &&`).
		Textf(`echo "  <uses-sdk android:minSdkVersion='%s' android:targetSdkVersion='%s'/>" &&`,
			l.minSdkVersion, l.targetSdkVersion).
		Text(`echo "</manifest>"`).
		Text(") >").Output(manifestPath)

	return manifestPath
}

func (l *linter) getBaselineFilepath(ctx android.ModuleContext) android.OptionalPath {
	var lintBaseline android.OptionalPath
	if lintFilename := proptools.StringDefault(l.properties.Lint.Baseline_filename, "lint-baseline.xml"); lintFilename != "" {
		if String(l.properties.Lint.Baseline_filename) != "" {
			// if manually specified, we require the file to exist
			lintBaseline = android.OptionalPathForPath(android.PathForModuleSrc(ctx, lintFilename))
		} else {
			lintBaseline = android.ExistentPathForSource(ctx, ctx.ModuleDir(), lintFilename)
		}
	}
	return lintBaseline
}

func (l *linter) lint(ctx android.ModuleContext) {
	if !l.enabled() {
		return
	}

	if l.minSdkVersion != l.compileSdkVersion {
		l.extraMainlineLintErrors = append(l.extraMainlineLintErrors, updatabilityChecks...)
		_, filtered := android.FilterList(l.properties.Lint.Warning_checks, updatabilityChecks)
		if len(filtered) != 0 {
			ctx.PropertyErrorf("lint.warning_checks",
				"Can't treat %v checks as warnings if min_sdk_version is different from sdk_version.", filtered)
		}
		_, filtered = android.FilterList(l.properties.Lint.Disabled_checks, updatabilityChecks)
		if len(filtered) != 0 {
			ctx.PropertyErrorf("lint.disabled_checks",
				"Can't disable %v checks if min_sdk_version is different from sdk_version.", filtered)
		}
	}

	extraLintCheckModules := ctx.GetDirectDepsWithTag(extraLintCheckTag)
	for _, extraLintCheckModule := range extraLintCheckModules {
		if ctx.OtherModuleHasProvider(extraLintCheckModule, JavaInfoProvider) {
			dep := ctx.OtherModuleProvider(extraLintCheckModule, JavaInfoProvider).(JavaInfo)
			l.extraLintCheckJars = append(l.extraLintCheckJars, dep.ImplementationAndResourcesJars...)
		} else {
			ctx.PropertyErrorf("lint.extra_check_modules",
				"%s is not a java module", ctx.OtherModuleName(extraLintCheckModule))
		}
	}

	rule := android.NewRuleBuilder(pctx, ctx).
		Sbox(android.PathForModuleOut(ctx, "lint"),
			android.PathForModuleOut(ctx, "lint.sbox.textproto")).
		SandboxInputs()

	if ctx.Config().UseRBE() && ctx.Config().IsEnvTrue("RBE_LINT") {
		pool := ctx.Config().GetenvWithDefault("RBE_LINT_POOL", "java16")
		rule.Remoteable(android.RemoteRuleSupports{RBE: true})
		rule.Rewrapper(&remoteexec.REParams{
			Labels:          map[string]string{"type": "tool", "name": "lint"},
			ExecStrategy:    lintRBEExecStrategy(ctx),
			ToolchainInputs: []string{config.JavaCmd(ctx).String()},
			Platform:        map[string]string{remoteexec.PoolKey: pool},
		})
	}

	if l.manifest == nil {
		manifest := l.generateManifest(ctx, rule)
		l.manifest = manifest
		rule.Temporary(manifest)
	}

	lintPaths := l.writeLintProjectXML(ctx, rule)

	html := android.PathForModuleOut(ctx, "lint", "lint-report.html")
	text := android.PathForModuleOut(ctx, "lint", "lint-report.txt")
	xml := android.PathForModuleOut(ctx, "lint", "lint-report.xml")

	depSetsBuilder := NewLintDepSetBuilder().Direct(html, text, xml)

	ctx.VisitDirectDepsWithTag(staticLibTag, func(dep android.Module) {
		if depLint, ok := dep.(lintDepSetsIntf); ok {
			depSetsBuilder.Transitive(depLint.LintDepSets())
		}
	})

	rule.Command().Text("rm -rf").Flag(lintPaths.cacheDir.String()).Flag(lintPaths.homeDir.String())
	rule.Command().Text("mkdir -p").Flag(lintPaths.cacheDir.String()).Flag(lintPaths.homeDir.String())
	rule.Command().Text("rm -f").Output(html).Output(text).Output(xml)

	var apiVersionsName, apiVersionsPrebuilt string
	if l.compileSdkKind == android.SdkModule || l.compileSdkKind == android.SdkSystemServer {
		// When compiling an SDK module (or system server) we use the filtered
		// database because otherwise lint's
		// NewApi check produces too many false positives; This database excludes information
		// about classes created in mainline modules hence removing those false positives.
		apiVersionsName = "api_versions_public_filtered.xml"
		apiVersionsPrebuilt = "prebuilts/sdk/current/public/data/api-versions-filtered.xml"
	} else {
		apiVersionsName = "api_versions.xml"
		apiVersionsPrebuilt = "prebuilts/sdk/current/public/data/api-versions.xml"
	}

	var annotationsZipPath, apiVersionsXMLPath android.Path
	if ctx.Config().AlwaysUsePrebuiltSdks() {
		annotationsZipPath = android.PathForSource(ctx, "prebuilts/sdk/current/public/data/annotations.zip")
		apiVersionsXMLPath = android.PathForSource(ctx, apiVersionsPrebuilt)
	} else {
		annotationsZipPath = copiedAnnotationsZipPath(ctx)
		apiVersionsXMLPath = copiedAPIVersionsXmlPath(ctx, apiVersionsName)
	}

	cmd := rule.Command()

	cmd.Flag(`JAVA_OPTS="-Xmx3072m --add-opens java.base/java.util=ALL-UNNAMED"`).
		FlagWithArg("ANDROID_SDK_HOME=", lintPaths.homeDir.String()).
		FlagWithInput("SDK_ANNOTATIONS=", annotationsZipPath).
		FlagWithInput("LINT_OPTS=-DLINT_API_DATABASE=", apiVersionsXMLPath)

	cmd.BuiltTool("lint").ImplicitTool(ctx.Config().HostJavaToolPath(ctx, "lint.jar")).
		Flag("--quiet").
		FlagWithInput("--project ", lintPaths.projectXML).
		FlagWithInput("--config ", lintPaths.configXML).
		FlagWithOutput("--html ", html).
		FlagWithOutput("--text ", text).
		FlagWithOutput("--xml ", xml).
		FlagWithArg("--compile-sdk-version ", l.compileSdkVersion).
		FlagWithArg("--java-language-level ", l.javaLanguageLevel).
		FlagWithArg("--kotlin-language-level ", l.kotlinLanguageLevel).
		FlagWithArg("--url ", fmt.Sprintf(".=.,%s=out", android.PathForOutput(ctx).String())).
		Flag("--exitcode").
		Flags(l.properties.Lint.Flags).
		Implicit(annotationsZipPath).
		Implicit(apiVersionsXMLPath)

	rule.Temporary(lintPaths.projectXML)
	rule.Temporary(lintPaths.configXML)

	if checkOnly := ctx.Config().Getenv("ANDROID_LINT_CHECK"); checkOnly != "" {
		cmd.FlagWithArg("--check ", checkOnly)
	}

	lintBaseline := l.getBaselineFilepath(ctx)
	if lintBaseline.Valid() {
		cmd.FlagWithInput("--baseline ", lintBaseline.Path())
	}

	cmd.Text("|| (").Text("if [ -e").Input(text).Text("]; then cat").Input(text).Text("; fi; exit 7)")

	rule.Command().Text("rm -rf").Flag(lintPaths.cacheDir.String()).Flag(lintPaths.homeDir.String())

	// The HTML output contains a date, remove it to make the output deterministic.
	rule.Command().Text(`sed -i.tmp -e 's|Check performed at .*\(</nav>\)|\1|'`).Output(html)

	rule.Build("lint", "lint")

	l.outputs = lintOutputs{
		html: html,
		text: text,
		xml:  xml,

		depSets: depSetsBuilder.Build(),
	}

	if l.buildModuleReportZip {
		l.reports = BuildModuleLintReportZips(ctx, l.LintDepSets())
	}
}

func BuildModuleLintReportZips(ctx android.ModuleContext, depSets LintDepSets) android.Paths {
	htmlList := depSets.HTML.ToSortedList()
	textList := depSets.Text.ToSortedList()
	xmlList := depSets.XML.ToSortedList()

	if len(htmlList) == 0 && len(textList) == 0 && len(xmlList) == 0 {
		return nil
	}

	htmlZip := android.PathForModuleOut(ctx, "lint-report-html.zip")
	lintZip(ctx, htmlList, htmlZip)

	textZip := android.PathForModuleOut(ctx, "lint-report-text.zip")
	lintZip(ctx, textList, textZip)

	xmlZip := android.PathForModuleOut(ctx, "lint-report-xml.zip")
	lintZip(ctx, xmlList, xmlZip)

	return android.Paths{htmlZip, textZip, xmlZip}
}

type lintSingleton struct {
	htmlZip android.WritablePath
	textZip android.WritablePath
	xmlZip  android.WritablePath
}

func (l *lintSingleton) GenerateBuildActions(ctx android.SingletonContext) {
	l.generateLintReportZips(ctx)
	l.copyLintDependencies(ctx)
}

func findModuleOrErr(ctx android.SingletonContext, moduleName string) android.Module {
	var res android.Module
	ctx.VisitAllModules(func(m android.Module) {
		if ctx.ModuleName(m) == moduleName {
			if res == nil {
				res = m
			} else {
				ctx.Errorf("lint: multiple %s modules found: %s and %s", moduleName,
					ctx.ModuleSubDir(m), ctx.ModuleSubDir(res))
			}
		}
	})
	return res
}

func (l *lintSingleton) copyLintDependencies(ctx android.SingletonContext) {
	if ctx.Config().AlwaysUsePrebuiltSdks() {
		return
	}

	frameworkDocStubs := findModuleOrErr(ctx, "framework-doc-stubs")
	if frameworkDocStubs == nil {
		if !ctx.Config().AllowMissingDependencies() {
			ctx.Errorf("lint: missing framework-doc-stubs")
		}
		return
	}

	filteredDb := findModuleOrErr(ctx, "api-versions-xml-public-filtered")
	if filteredDb == nil {
		if !ctx.Config().AllowMissingDependencies() {
			ctx.Errorf("lint: missing api-versions-xml-public-filtered")
		}
		return
	}

	ctx.Build(pctx, android.BuildParams{
		Rule:   android.CpIfChanged,
		Input:  android.OutputFileForModule(ctx, frameworkDocStubs, ".annotations.zip"),
		Output: copiedAnnotationsZipPath(ctx),
	})

	ctx.Build(pctx, android.BuildParams{
		Rule:   android.CpIfChanged,
		Input:  android.OutputFileForModule(ctx, frameworkDocStubs, ".api_versions.xml"),
		Output: copiedAPIVersionsXmlPath(ctx, "api_versions.xml"),
	})

	ctx.Build(pctx, android.BuildParams{
		Rule:   android.CpIfChanged,
		Input:  android.OutputFileForModule(ctx, filteredDb, ""),
		Output: copiedAPIVersionsXmlPath(ctx, "api_versions_public_filtered.xml"),
	})
}

func copiedAnnotationsZipPath(ctx android.PathContext) android.WritablePath {
	return android.PathForOutput(ctx, "lint", "annotations.zip")
}

func copiedAPIVersionsXmlPath(ctx android.PathContext, name string) android.WritablePath {
	return android.PathForOutput(ctx, "lint", name)
}

func (l *lintSingleton) generateLintReportZips(ctx android.SingletonContext) {
	if ctx.Config().UnbundledBuild() {
		return
	}

	var outputs []*lintOutputs
	var dirs []string
	ctx.VisitAllModules(func(m android.Module) {
		if ctx.Config().KatiEnabled() && !m.ExportedToMake() {
			return
		}

		if apex, ok := m.(android.ApexModule); ok && apex.NotAvailableForPlatform() {
			apexInfo := ctx.ModuleProvider(m, android.ApexInfoProvider).(android.ApexInfo)
			if apexInfo.IsForPlatform() {
				// There are stray platform variants of modules in apexes that are not available for
				// the platform, and they sometimes can't be built.  Don't depend on them.
				return
			}
		}

		if l, ok := m.(lintOutputsIntf); ok {
			outputs = append(outputs, l.lintOutputs())
		}
	})

	dirs = android.SortedUniqueStrings(dirs)

	zip := func(outputPath android.WritablePath, get func(*lintOutputs) android.Path) {
		var paths android.Paths

		for _, output := range outputs {
			if p := get(output); p != nil {
				paths = append(paths, p)
			}
		}

		lintZip(ctx, paths, outputPath)
	}

	l.htmlZip = android.PathForOutput(ctx, "lint-report-html.zip")
	zip(l.htmlZip, func(l *lintOutputs) android.Path { return l.html })

	l.textZip = android.PathForOutput(ctx, "lint-report-text.zip")
	zip(l.textZip, func(l *lintOutputs) android.Path { return l.text })

	l.xmlZip = android.PathForOutput(ctx, "lint-report-xml.zip")
	zip(l.xmlZip, func(l *lintOutputs) android.Path { return l.xml })

	ctx.Phony("lint-check", l.htmlZip, l.textZip, l.xmlZip)
}

func (l *lintSingleton) MakeVars(ctx android.MakeVarsContext) {
	if !ctx.Config().UnbundledBuild() {
		ctx.DistForGoal("lint-check", l.htmlZip, l.textZip, l.xmlZip)
	}
}

var _ android.SingletonMakeVarsProvider = (*lintSingleton)(nil)

func init() {
	android.RegisterSingletonType("lint",
		func() android.Singleton { return &lintSingleton{} })

	registerLintBuildComponents(android.InitRegistrationContext)
}

func registerLintBuildComponents(ctx android.RegistrationContext) {
	ctx.PostDepsMutators(func(ctx android.RegisterMutatorsContext) {
		ctx.TopDown("enforce_strict_updatability_linting", enforceStrictUpdatabilityLintingMutator).Parallel()
	})
}

func lintZip(ctx android.BuilderContext, paths android.Paths, outputPath android.WritablePath) {
	paths = android.SortedUniquePaths(android.CopyOfPaths(paths))

	sort.Slice(paths, func(i, j int) bool {
		return paths[i].String() < paths[j].String()
	})

	rule := android.NewRuleBuilder(pctx, ctx)

	rule.Command().BuiltTool("soong_zip").
		FlagWithOutput("-o ", outputPath).
		FlagWithArg("-C ", android.PathForIntermediates(ctx).String()).
		FlagWithRspFileInputList("-r ", outputPath.ReplaceExtension(ctx, "rsp"), paths)

	rule.Build(outputPath.Base(), outputPath.Base())
}

// Enforce the strict updatability linting to all applicable transitive dependencies.
func enforceStrictUpdatabilityLintingMutator(ctx android.TopDownMutatorContext) {
	m := ctx.Module()
	if d, ok := m.(lintDepSetsIntf); ok && d.getStrictUpdatabilityLinting() {
		ctx.VisitDirectDepsWithTag(staticLibTag, func(d android.Module) {
			if a, ok := d.(lintDepSetsIntf); ok {
				a.setStrictUpdatabilityLinting(true)
			}
		})
	}
}
