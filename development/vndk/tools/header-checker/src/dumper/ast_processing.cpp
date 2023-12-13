// Copyright (C) 2016 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "dumper/ast_processing.h"

#include "dumper/abi_wrappers.h"
#include "repr/ir_dumper.h"
#include "utils/header_abi_util.h"

#include <clang/AST/PrettyPrinter.h>
#include <clang/AST/QualTypeNames.h>
#include <clang/Lex/Token.h>

#include <fstream>
#include <iostream>
#include <string>


namespace header_checker {
namespace dumper {


class PrintNormalizedPath : public clang::PrintingCallbacks {
 public:
  PrintNormalizedPath(const std::string root_dir) : root_dir_(root_dir) {}

  std::string remapPath(llvm::StringRef path) const {
    return utils::NormalizePath(path.str(), root_dir_);
  }

 private:
  const std::string root_dir_;
};

HeaderASTVisitor::HeaderASTVisitor(
    const HeaderCheckerOptions &options, clang::MangleContext *mangle_contextp,
    clang::ASTContext *ast_contextp,
    const clang::CompilerInstance *compiler_instance_p,
    const clang::Decl *tu_decl, repr::ModuleIR *module,
    ASTCaches *ast_caches)
    : options_(options), mangle_contextp_(mangle_contextp),
      ast_contextp_(ast_contextp), cip_(compiler_instance_p), tu_decl_(tu_decl),
      module_(module), ast_caches_(ast_caches) {}

bool HeaderASTVisitor::VisitRecordDecl(const clang::RecordDecl *decl) {
  // Avoid segmentation fault in getASTRecordLayout.
  if (decl->isInvalidDecl()) {
    return true;
  }
  // Skip forward declarations, dependent records. Also skip anonymous records
  // as they will be traversed through record fields.
  if (!decl->isThisDeclarationADefinition() ||
      decl->getTypeForDecl()->isDependentType() ||
      decl->isAnonymousStructOrUnion() ||
      !decl->hasNameForLinkage() ||
      !decl->isExternallyVisible()) {
    return true;
  }
  RecordDeclWrapper record_decl_wrapper(
      mangle_contextp_, ast_contextp_, cip_, decl, module_, ast_caches_);
  return record_decl_wrapper.GetRecordDecl();
}

bool HeaderASTVisitor::VisitEnumDecl(const clang::EnumDecl *decl) {
  if (!decl->isThisDeclarationADefinition() ||
      decl->getTypeForDecl()->isDependentType()) {
    return true;
  }
  EnumDeclWrapper enum_decl_wrapper(
      mangle_contextp_, ast_contextp_, cip_, decl, module_, ast_caches_);
  return enum_decl_wrapper.GetEnumDecl();
}

static bool MutateFunctionWithLinkageName(const repr::FunctionIR *function,
                                          repr::ModuleIR *module,
                                          std::string &linkage_name) {
  auto added_function = std::make_unique<repr::FunctionIR>();
  *added_function = *function;
  added_function->SetLinkerSetKey(linkage_name);
  return module->AddLinkableMessage(*added_function);
}

static bool AddMangledFunctions(const repr::FunctionIR *function,
                                repr:: ModuleIR *module,
                                std::vector<std::string> &manglings) {
  for (auto &&mangling : manglings) {
    if (!MutateFunctionWithLinkageName(function, module, mangling)) {
      return false;
    }
  }
  return true;
}

bool HeaderASTVisitor::ShouldSkipFunctionDecl(const clang::FunctionDecl *decl) {
  if (!decl->getDefinition()) {
    if (!options_.dump_function_declarations_ ||
        options_.source_file_ !=
            ABIWrapper::GetDeclSourceFile(decl, cip_, options_.root_dir_)) {
      return true;
    }
  }
  // Skip explicitly deleted functions such as `Foo operator=(Foo) = delete;`.
  if (decl->isDeleted()) {
    return true;
  }
  if (decl->getLinkageAndVisibility().getLinkage() !=
      clang::Linkage::ExternalLinkage) {
    return true;
  }
  if (const clang::CXXMethodDecl *method_decl =
      llvm::dyn_cast<clang::CXXMethodDecl>(decl)) {
    const clang::CXXRecordDecl *record_decl = method_decl->getParent();
    // Avoid segmentation fault in getThunkInfo in getAllManglings.
    if (method_decl->isVirtual() && record_decl->isInvalidDecl()) {
      return true;
    }
    if (record_decl->getTypeForDecl()->isDependentType()) {
      return true;
    }
  }
  clang::FunctionDecl::TemplatedKind tkind = decl->getTemplatedKind();
  switch (tkind) {
    case clang::FunctionDecl::TK_NonTemplate:
    case clang::FunctionDecl::TK_FunctionTemplateSpecialization:
    case clang::FunctionDecl::TK_MemberSpecialization:
      return false;
    default:
      return true;
  }
}

bool HeaderASTVisitor::VisitFunctionDecl(const clang::FunctionDecl *decl) {
  if (ShouldSkipFunctionDecl(decl)) {
    return true;
  }
  FunctionDeclWrapper function_decl_wrapper(
      mangle_contextp_, ast_contextp_, cip_, decl, module_, ast_caches_);
  auto function_wrapper = function_decl_wrapper.GetFunctionDecl();
  // Destructors and Constructors can have more than 1 symbol generated from the
  // same Decl.
  clang::ASTNameGenerator cg(*ast_contextp_);
  std::vector<std::string> manglings = cg.getAllManglings(decl);
  if (!manglings.empty()) {
    return AddMangledFunctions(function_wrapper.get(), module_, manglings);
  }
  std::string linkage_name =
      ABIWrapper::GetMangledNameDecl(decl, mangle_contextp_);
  return MutateFunctionWithLinkageName(function_wrapper.get(), module_,
                                       linkage_name);
}

bool HeaderASTVisitor::VisitVarDecl(const clang::VarDecl *decl) {
  if (!decl->hasGlobalStorage() ||
      decl->getType().getTypePtr()->isDependentType()) {
    // Non global / static variable declarations don't need to be dumped.
    return true;
  }
  GlobalVarDeclWrapper global_var_decl_wrapper(
      mangle_contextp_, ast_contextp_, cip_, decl, module_, ast_caches_);
  return global_var_decl_wrapper.GetGlobalVarDecl();
}

// We don't need to recurse into Declarations which are not exported.
bool HeaderASTVisitor::TraverseDecl(clang::Decl *decl) {
  if (!decl) {
    return true;
  }
  std::string source_file =
      ABIWrapper::GetDeclSourceFile(decl, cip_, options_.root_dir_);
  ast_caches_->decl_to_source_file_cache_.insert(
      std::make_pair(decl, source_file));
  // If no exported headers are specified we assume the whole AST is exported.
  const auto &exported_headers = options_.exported_headers_;
  if ((decl != tu_decl_) && options_.dump_exported_only_ &&
      source_file != ast_caches_->translation_unit_source_ &&
      (exported_headers.find(source_file) == exported_headers.end())) {
    return true;
  }
  // If at all we're looking at the source file's AST decl node, it should be a
  // function decl node.
  if ((decl != tu_decl_) &&
      (source_file == ast_caches_->translation_unit_source_) &&
      !decl->isFunctionOrFunctionTemplate()) {
    return true;
  }
  return RecursiveASTVisitor<HeaderASTVisitor>::TraverseDecl(decl);
}

HeaderASTConsumer::HeaderASTConsumer(
    clang::CompilerInstance *compiler_instancep, HeaderCheckerOptions &options)
    : cip_(compiler_instancep), options_(options) {}

void HeaderASTConsumer::HandleTranslationUnit(clang::ASTContext &ctx) {
  clang::PrintingPolicy old_policy(ctx.getPrintingPolicy());
  clang::PrintingPolicy policy(old_policy);
  // Suppress 'struct' keyword for C source files while getting QualType string
  // names to avoid inconsistency between C and C++ (for C++ files, this is true
  // by default)
  policy.SuppressTagKeyword = true;
  PrintNormalizedPath callbacks(options_.root_dir_);
  policy.Callbacks = &callbacks;
  ctx.setPrintingPolicy(policy);
  clang::TranslationUnitDecl *translation_unit = ctx.getTranslationUnitDecl();
  std::unique_ptr<clang::MangleContext> mangle_contextp(
      ctx.createMangleContext());
  ASTCaches ast_caches(
      ABIWrapper::GetDeclSourceFile(translation_unit, cip_, options_.root_dir_),
      options_.root_dir_);

  std::unique_ptr<repr::ModuleIR> module(
      new repr::ModuleIR(nullptr /*FIXME*/));

  HeaderASTVisitor v(options_, mangle_contextp.get(), &ctx, cip_,
                     translation_unit, module.get(), &ast_caches);
  if (!v.TraverseDecl(translation_unit)) {
    llvm::errs() << "ABI extraction failed\n";
    ::exit(1);
  }

  std::unique_ptr<repr::IRDumper> ir_dumper =
      repr::IRDumper::CreateIRDumper(options_.text_format_,
                                     options_.dump_name_);
  if (!ir_dumper->Dump(*module)) {
    llvm::errs() << "Serialization failed\n";
    ::exit(1);
  }

  ctx.setPrintingPolicy(old_policy);
}


}  // dumper
}  // header_checker
