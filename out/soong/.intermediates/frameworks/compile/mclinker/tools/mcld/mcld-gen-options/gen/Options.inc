/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Option Parsing Definitions                                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/////////
// Prefixes

#ifdef PREFIX
#define COMMA ,
PREFIX(prefix_0, {nullptr})
PREFIX(prefix_1, {"-" COMMA nullptr})
PREFIX(prefix_3, {"-" COMMA "--" COMMA nullptr})
PREFIX(prefix_2, {"--" COMMA nullptr})
#undef COMMA
#endif // PREFIX

/////////
// Groups

#ifdef OPTION
OPTION(nullptr, "dynamic", DynamicGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "DYNAMIC OPTIONS", nullptr)
OPTION(nullptr, "optimization", OptimizationGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "OPTIMIZATION OPTIONS", nullptr)
OPTION(nullptr, "output", OutputGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "OUTPUT OPTIONS", nullptr)
OPTION(nullptr, "positional", PositionalGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "POSITIONAL OPTIONS", nullptr)
OPTION(nullptr, "preference", PreferenceGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "PREFERENCE OPTIONS", nullptr)
OPTION(nullptr, "script", ScriptGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "SCRIPT OPTIONS", nullptr)
OPTION(nullptr, "searchpath", SearchpathGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "SEARCHPATH OPTIONS", nullptr)
OPTION(nullptr, "symbol", SymbolGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "SYMBOL OPTIONS", nullptr)
OPTION(nullptr, "target", TargetGroup, Group, INVALID, INVALID, nullptr, 0, 0,
       "TARGET OPTIONS", nullptr)

//////////
// Options

OPTION(prefix_0, "<input>", INPUT, Input, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_0, "<unknown>", UNKNOWN, Unknown, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "(", StartGroupAlias, Flag, PositionalGroup, StartGroup, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, ")", EndGroupAlias, Flag, PositionalGroup, EndGroup, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "add-needed", AddNeeded, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Deprecated", nullptr)
OPTION(prefix_2, "allow-multiple-definition", AllowMulDefs, Flag, DynamicGroup, INVALID, nullptr, 0, 0,
       "Allow multiple definitions", nullptr)
OPTION(prefix_2, "as-needed", AsNeeded, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Add the dynamic libraries mentioned to DT_NEEDED where there is a non-weak undefined symbol reference from", nullptr)
OPTION(prefix_1, "Bdynamic", Bdynamic, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Link against dynamic library", nullptr)
OPTION(prefix_1, "Bgroup", Bgroup, Flag, DynamicGroup, INVALID, nullptr, 0, 0,
       "Info the dynamic linker to lookup only inside the group", nullptr)
OPTION(prefix_1, "Bshareable", Bshareable, Flag, OutputGroup, Shared, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "Bstatic", Bstatic, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Link against static library", nullptr)
OPTION(prefix_1, "Bsymbolic", Bsymbolic, Flag, DynamicGroup, INVALID, nullptr, 0, 0,
       "Bind references within the shared library", nullptr)
OPTION(prefix_1, "b", InputFormatAlias, Separate, OutputGroup, InputFormat, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "call_shared", BdynamicAlias2, Flag, OutputGroup, Bdynamic, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "color=", Color, Joined, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Surround the result strings with the marker", nullptr)
OPTION(prefix_2, "copy-dt-needed-entries", CopyDTNeeded, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Add the dynamic libraries mentioned to DT_NEEDED", nullptr)
OPTION(prefix_1, "dc", DefineCommonAlias1, Flag, SymbolGroup, DefineCommon, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "defsym=", DefSym, Joined, ScriptGroup, INVALID, nullptr, 0, 0,
       "Define a symbol", nullptr)
OPTION(prefix_2, "discard-all", DiscardAll, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Discard all local symbols", nullptr)
OPTION(prefix_2, "discard-debug", DiscardLocals, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Discard all temporary local symbols", nullptr)
OPTION(prefix_1, "dn", BstaticAlias1, Flag, OutputGroup, Bstatic, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "dp", DefineCommonAlias2, Flag, SymbolGroup, DefineCommon, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "dynamic-linker=", Dyld, Joined, DynamicGroup, INVALID, nullptr, 0, 0,
       "Set the name of the dynamic linker", nullptr)
OPTION(prefix_1, "dynamic-linker", DyldAlias, Separate, DynamicGroup, Dyld, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "dy", BdynamicAlias1, Flag, OutputGroup, Bdynamic, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "d", DefineCommon, Flag, SymbolGroup, INVALID, nullptr, 0, 0,
       "Define common symbol", nullptr)
OPTION(prefix_2, "eh-frame-hdr", EHFrameHdr, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Request creation of .eh_frame_hdr section and PT_GNU_EH_FRAME segment", nullptr)
OPTION(prefix_2, "enable-new-dtags", EnableNewDTags, Flag, DynamicGroup, INVALID, nullptr, 0, 0,
       "Enable use of DT_RUNPATH and DT_FLAGS", nullptr)
OPTION(prefix_2, "end-group", EndGroup, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Stop recording a group of archives", nullptr)
OPTION(prefix_2, "entry=", Entry, Joined, DynamicGroup, INVALID, nullptr, 0, 0,
       "Use the explicit symbol as the entrance of your program", nullptr)
OPTION(prefix_2, "error-limit=", ErrorLimit, Joined, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Set the maximum limit of errors", nullptr)
OPTION(prefix_2, "exclude-libs", ExcludeLibs, Separate, OutputGroup, INVALID, nullptr, 0, 0,
       "Allow linking together mismatched input files", nullptr)
OPTION(prefix_2, "export-dynamic", ExportDynamic, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Export all dynamic symbols", nullptr)
OPTION(prefix_1, "E", ExportDynamicAlias, Flag, OutputGroup, ExportDynamic, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "e", EntryAlias, Separate, INVALID, Entry, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "fatal-warnings", FatalWarnings, Flag, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Turn all warnings into errors", nullptr)
OPTION(prefix_2, "fix-cortex-a53-835769", FixCA53Erratum835769, Flag, TargetGroup, INVALID, nullptr, 0, 0,
       "Enable fix for cortex a53 erratum 835769", nullptr)
OPTION(prefix_2, "fix-cortex-a53-843419", FixCA53Erratum843419, Flag, TargetGroup, INVALID, nullptr, 0, 0,
       "Enable fix for cortex a53 erratum 843419", nullptr)
OPTION(prefix_2, "format=", InputFormat, Joined, OutputGroup, INVALID, nullptr, 0, 0,
       "Specify the binary format for input object files that follow this option on the command line", nullptr)
OPTION(prefix_2, "gc-sections", GCSections, Flag, OptimizationGroup, INVALID, nullptr, 0, 0,
       "Enable garbage collection of unused input sections", nullptr)
OPTION(prefix_2, "gpsize=", GPSize, Joined, TargetGroup, INVALID, nullptr, 0, 0,
       "Set the maximum size of objects to be optimized using GP", nullptr)
OPTION(prefix_1, "G", GPSizeAlias, Separate, TargetGroup, GPSize, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "hash-style=", HashStyle, Joined, OutputGroup, INVALID, nullptr, 0, 0,
       "Set the type of linker's hash table(s)", nullptr)
OPTION(prefix_3, "help", Help, Flag, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Display available options (to standard output)", nullptr)
OPTION(prefix_1, "h", HelpAlias, Flag, PreferenceGroup, Help, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "icf-iterations", ICFIters, Separate, OptimizationGroup, INVALID, nullptr, 0, 0,
       "Set number of iterations to do ICF", nullptr)
OPTION(prefix_2, "icf=", ICF, Joined, OptimizationGroup, INVALID, nullptr, 0, 0,
       "Identical Code Folding", nullptr)
OPTION(prefix_2, "ld-generated-unwind-info", LDGeneratedUnwindInfo, Flag, OptimizationGroup, INVALID, nullptr, 0, 0,
       "Request creation of unwind info for linker generated code sections like PLT", nullptr)
OPTION(prefix_2, "library-path=", LibraryPath, Joined, SearchpathGroup, INVALID, nullptr, 0, 0,
       "Add the given directory to the list of search paths", nullptr)
OPTION(prefix_2, "library=", Namespec, Joined, PositionalGroup, INVALID, nullptr, 0, 0,
       "Add the archive or object file specified by namespec to the list of files to link", nullptr)
OPTION(prefix_1, "L", LibraryPathAlias, Joined, SearchpathGroup, LibraryPath, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "l", NamespecAlias, Joined, PositionalGroup, Namespec, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "march=", Arch, Joined, TargetGroup, INVALID, nullptr, 0, 0,
       "Architecture to generate code for", nullptr)
OPTION(prefix_1, "mcpu=", CPU, Joined, TargetGroup, INVALID, nullptr, 0, 0,
       "Set a specific cpu type", nullptr)
OPTION(prefix_1, "mtriple=", Triple, Joined, TargetGroup, INVALID, nullptr, 0, 0,
       "Override target triple for module", nullptr)
OPTION(prefix_1, "m", Emulation, Separate, TargetGroup, INVALID, nullptr, 0, 0,
       "Set GNU linker emulation", nullptr)
OPTION(prefix_2, "nmagic", NMagic, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Do not page align data", nullptr)
OPTION(prefix_2, "no-add-needed", NoAddNeeded, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Deprecated", nullptr)
OPTION(prefix_2, "no-as-needed", NoAsNeeded, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Turn off the effect of the --as-needed", nullptr)
OPTION(prefix_2, "no-copy-dt-needed-entries", NoCopyDTNeeded, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Turn off the effect of the --copy-dt-needed-entries", nullptr)
OPTION(prefix_2, "no-export-dynamic", NoExportDynamic, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Not export all dynamic symbols", nullptr)
OPTION(prefix_2, "no-fatal-warnings", NoFatalWarnings, Flag, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Do not turn all warnings into errors", nullptr)
OPTION(prefix_2, "no-gc-sections", NoGCSections, Flag, OptimizationGroup, INVALID, nullptr, 0, 0,
       "Disable garbage collection of unused input sections", nullptr)
OPTION(prefix_2, "no-ld-generated-unwind-info", NoLDGeneratedUnwindInfo, Flag, OptimizationGroup, INVALID, nullptr, 0, 0,
       "Don't create unwind info for linker generated sections to save size", nullptr)
OPTION(prefix_2, "no-print-gc-sections", NoPrintGCSections, Flag, OptimizationGroup, INVALID, nullptr, 0, 0,
       "Do not list sections removed by garbage collection", nullptr)
OPTION(prefix_2, "no-print-icf-sections", NoPrintICFSections, Flag, OptimizationGroup, INVALID, nullptr, 0, 0,
       "Do not list sections folded by ICF", nullptr)
OPTION(prefix_2, "no-undefined", NoUndef, Flag, DynamicGroup, INVALID, nullptr, 0, 0,
       "Do not allow unresolved references", nullptr)
OPTION(prefix_2, "no-warn-mismatch", NoWarnMismatch, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Allow linking together mismatched input files", nullptr)
OPTION(prefix_2, "no-whole-archive", NoWholeArchive, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Turn off the effect of the --whole-archive option", nullptr)
OPTION(prefix_1, "non_shared", BstaticAlias2, Flag, OutputGroup, Bstatic, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "nostdlib", NoStdlib, Flag, SearchpathGroup, INVALID, nullptr, 0, 0,
       "Only search lib dirs explicitly specified on cmdline", nullptr)
OPTION(prefix_1, "N", OMagicAlias, Flag, OutputGroup, OMagic, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "n", NMagicAlias, Flag, OutputGroup, NMagic, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "oformat=", OutputFormat, Joined, OutputGroup, INVALID, nullptr, 0, 0,
       "Output format", nullptr)
OPTION(prefix_2, "omagic", OMagic, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Do not page align data, do not make text readonly", nullptr)
OPTION(prefix_2, "output=", OutputAlias, Joined, OutputGroup, Output, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "o", Output, Separate, OutputGroup, INVALID, nullptr, 0, 0,
       "Output filename", nullptr)
OPTION(prefix_2, "pic-executable", PICExec, Flag, OutputGroup, PIE, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "pie", PIE, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Emit a position-independent executable file", nullptr)
OPTION(prefix_2, "portable=", Portable, Joined, ScriptGroup, INVALID, nullptr, 0, 0,
       "Use a portable function for the symbol", nullptr)
OPTION(prefix_2, "print-gc-sections", PrintGCSections, Flag, OptimizationGroup, INVALID, nullptr, 0, 0,
       "List all sections removed by garbage collection", nullptr)
OPTION(prefix_2, "print-icf-sections", PrintICFSections, Flag, OptimizationGroup, INVALID, nullptr, 0, 0,
       "List all sections folded by ICF", nullptr)
OPTION(prefix_2, "relocatable", Relocatable, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Generate relocatable output", nullptr)
OPTION(prefix_1, "rpath=", RPath, Joined, SearchpathGroup, INVALID, nullptr, 0, 0,
       "Add a directory to the runtime library search path", nullptr)
OPTION(prefix_1, "r", RelocatableAlias, Flag, OutputGroup, Relocatable, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "script=", Script, Joined, PositionalGroup, INVALID, nullptr, 0, 0,
       "Use the given file as the linker script", nullptr)
OPTION(prefix_2, "section-start=", SectionStart, Joined, ScriptGroup, INVALID, nullptr, 0, 0,
       "Locate a output section at the given absolute address", nullptr)
OPTION(prefix_1, "shared", Shared, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Create a shared library", nullptr)
OPTION(prefix_1, "soname=", SOName, Joined, DynamicGroup, INVALID, nullptr, 0, 0,
       "Set internal name of shared library", nullptr)
OPTION(prefix_1, "soname", SONameAlias, Separate, DynamicGroup, SOName, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "spare-dynamic-tags", SpareDTags, Separate, DynamicGroup, INVALID, nullptr, 0, 0,
       "Set the number of spare dyanmic tags (DT_NULL)", nullptr)
OPTION(prefix_2, "start-group", StartGroup, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Start to record a group of archives", nullptr)
OPTION(prefix_1, "static", BstaticAlias3, Flag, OutputGroup, Bstatic, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "strip-all", StripAll, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Omit all symbol information from the output file", nullptr)
OPTION(prefix_2, "strip-debug", StripDebug, Flag, OutputGroup, INVALID, nullptr, 0, 0,
       "Omit debugger symbol information from the output file", nullptr)
OPTION(prefix_2, "stub-group-size=", StubGroupSize, Joined, TargetGroup, INVALID, nullptr, 0, 0,
       "Set the group size to place stubs between sections", nullptr)
OPTION(prefix_2, "sysroot=", Sysroot, Joined, SearchpathGroup, INVALID, nullptr, 0, 0,
       "Use the given directory as the location of the sysroot", nullptr)
OPTION(prefix_1, "S", StripDebugAlias, Flag, OutputGroup, StripDebug, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "s", StripAllAlias, Flag, OutputGroup, StripAll, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "Tbss=", Tbss, Joined, ScriptGroup, INVALID, nullptr, 0, 0,
       "Set the address of the bss segment", nullptr)
OPTION(prefix_1, "Tdata=", Tdata, Joined, ScriptGroup, INVALID, nullptr, 0, 0,
       "Set the address of the data segment", nullptr)
OPTION(prefix_2, "trace", Trace, Flag, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Print the names of the input files as ld processes them", nullptr)
OPTION(prefix_1, "Ttext=", Ttext, Joined, ScriptGroup, INVALID, nullptr, 0, 0,
       "Set the address of the text segment", nullptr)
OPTION(prefix_1, "T", ScriptAlias, Separate, PositionalGroup, Script, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "t", TraceAlias, Flag, PreferenceGroup, Trace, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "undefined=", Undefined, Joined, SymbolGroup, INVALID, nullptr, 0, 0,
       "Force symbol to be undefined in the output file", nullptr)
OPTION(prefix_1, "u", UndefinedAlias, Separate, SymbolGroup, Undefined, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "verbose=", Verbose, Joined, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Set linker diagnostic output level", nullptr)
OPTION(prefix_2, "version", Version, Flag, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Display MCLinker version", nullptr)
OPTION(prefix_1, "V", VersionAlias2, Flag, PreferenceGroup, Version, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "v", VersionAlias1, Flag, PreferenceGroup, Version, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "warn-shared-textrel", WarnSharedTextrel, Flag, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Warn if there is a text relocation in the output shared object", nullptr)
OPTION(prefix_2, "warning-limit=", WarningLimit, Joined, PreferenceGroup, INVALID, nullptr, 0, 0,
       "Set the maximum limit of warnings", nullptr)
OPTION(prefix_2, "whole-archive", WholeArchive, Flag, PositionalGroup, INVALID, nullptr, 0, 0,
       "Include every object file in the archive in the link", nullptr)
OPTION(prefix_2, "wrap=", Wrap, Joined, ScriptGroup, INVALID, nullptr, 0, 0,
       "Use a wrap function for the symbol", nullptr)
OPTION(prefix_1, "X", DiscardLocalsAlias, Flag, OutputGroup, DiscardLocals, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "x", DiscardAllAlias, Flag, OutputGroup, DiscardAll, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "z", Z, Separate, DynamicGroup, INVALID, nullptr, 0, 0,
       "Extensions for GNU ld compatibility", nullptr)
#endif // OPTION
