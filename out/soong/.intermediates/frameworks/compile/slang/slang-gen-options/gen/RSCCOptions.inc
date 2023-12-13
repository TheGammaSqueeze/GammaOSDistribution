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
OPTION(nullptr, "M group>", M_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr)
OPTION(nullptr, "<output type group>", Output_Type_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr)

//////////
// Options

OPTION(prefix_0, "<input>", INPUT, Input, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_0, "<unknown>", UNKNOWN, Unknown, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "additional-dep-target", additional_dep_target, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Additional targets to show up in dependencies output", nullptr)
OPTION(prefix_1, "allow-rs-prefix", allow_rs_prefix, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Allow user-defined function prefixed with 'rs'", nullptr)
OPTION(prefix_1, "ast-print", ast_print, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print clang AST prior to llvm IR generation", nullptr)
OPTION(prefix_1, "a", _additional_dep_target, Separate, INVALID, additional_dep_target, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "bitcode-storage", bitcode_storage, Separate, INVALID, INVALID, nullptr, 0, 0,
       "<value> should be 'ar' or 'jc'", "<value>")
OPTION(prefix_1, "debug", debug, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Enable debug output", nullptr)
OPTION(prefix_1, "d", _output_dep_dir, Separate, INVALID, output_dep_dir, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "emit-asm", emit_asm, Flag, Output_Type_Group, INVALID, nullptr, 0, 0,
       "Emit target assembly files", nullptr)
OPTION(prefix_1, "emit-bc", emit_bc, Flag, Output_Type_Group, INVALID, nullptr, 0, 0,
       "Build ASTs then convert to LLVM, emit .bc file", nullptr)
OPTION(prefix_1, "emit-dep", emit_dep, Flag, M_Group, M, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "emit-llvm", emit_llvm, Flag, Output_Type_Group, INVALID, nullptr, 0, 0,
       "Build ASTs then convert to LLVM, emit .ll file", nullptr)
OPTION(prefix_1, "emit-nothing", emit_nothing, Flag, Output_Type_Group, INVALID, nullptr, 0, 0,
       "Build ASTs then convert to LLVM, but emit nothing", nullptr)
OPTION(prefix_1, "g", emit_g, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Emit LLVM Debug Metadata", nullptr)
OPTION(prefix_2, "help", _help, Flag, INVALID, help, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "help", help, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print this help text", nullptr)
OPTION(prefix_1, "h", __help, Flag, INVALID, help, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_3, "include-path", _I, Separate, INVALID, I, nullptr, 0, 0, nullptr, "<directory>")
OPTION(prefix_1, "I", I, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0,
       "Add directory to include search path", "<directory>")
OPTION(prefix_1, "java-reflection-package-name", java_reflection_package_name, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Specify the package name that reflected Java files belong to", nullptr)
OPTION(prefix_1, "java-reflection-path-base", java_reflection_path_base, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Base directory for output reflected Java files", "<directory>")
OPTION(prefix_1, "j", _java_reflection_package_name, Separate, INVALID, java_reflection_package_name, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "m32", m32, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Emit 32-bit code (only for C++, unless eng build)", nullptr)
OPTION(prefix_1, "m64", m64, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Emit 64-bit code (only for C++, unless eng build)", nullptr)
OPTION(prefix_1, "MD", MD, Flag, M_Group, INVALID, nullptr, 0, 0,
       "Emit .d dependency files", nullptr)
OPTION(prefix_1, "MP", MP, Flag, M_Group, INVALID, nullptr, 0, 0,
       "Also emit phony target for dependency files", nullptr)
OPTION(prefix_1, "M", M, Flag, M_Group, INVALID, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "no-link", no_link, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "output-dep-dir", output_dep_dir, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Specify output directory for dependencies output", "<directory>")
OPTION(prefix_1, "O", optimization_level, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0,
       "<optimization-level> can be one of '0' or '3' (default)", "<optimization-level>")
OPTION(prefix_1, "o", o, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Specify output directory", "<directory>")
OPTION(prefix_1, "print-after-all", print_after_all, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print llvm IR after each pass", nullptr)
OPTION(prefix_1, "print-before-all", print_before_all, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print llvm IR before each pass", nullptr)
OPTION(prefix_1, "p", _java_reflection_path_base, Separate, INVALID, java_reflection_path_base, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "reflect-c++", reflect_cpp, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Reflect C++ classes", nullptr)
OPTION(prefix_1, "rs-package-name=", rs_package_name_EQ, Joined, INVALID, rs_package_name, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "rs-package-name", rs_package_name, Separate, INVALID, INVALID, nullptr, 0, 0,
       "package name for referencing RS classes", "<package_name>")
OPTION(prefix_1, "S", _emit_asm, Flag, Output_Type_Group, emit_asm, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "s", _bitcode_storage, Separate, INVALID, bitcode_storage, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "target-api=", target_api_EQ, Joined, INVALID, target_api, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "target-api", target_api, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Specify target API level (e.g. 14)", nullptr)
OPTION(prefix_2, "verbose", __verbose, Flag, INVALID, verbose, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "verbose", _verbose, Flag, INVALID, verbose, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_2, "version", _version, Flag, INVALID, version, nullptr, 0, 0, nullptr, nullptr)
OPTION(prefix_1, "version", version, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the assembler version", nullptr)
OPTION(prefix_1, "v", verbose, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Display verbose information during the compilation", nullptr)
OPTION(prefix_1, "W", W, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Enable the specified warning", nullptr)
OPTION(prefix_1, "w", w, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Suppress all warnings", nullptr)
#endif // OPTION
