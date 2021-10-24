// #pragma once

#include "ast.hpp"

using namespace llvm;

LLVMContext AST::TheContext;
IRBuilder<> AST::Builder(TheContext);
std::unique_ptr<Module> AST::TheModule;
std::unique_ptr<legacy::FunctionPassManager> AST::TheFPM;

GlobalVariable *AST::TheVars;
GlobalVariable *AST::TheNL;
Function *AST::TheWriteInteger;
Function *AST::TheWriteString;
Function *AST::TheWriteReal;

llvm::Type *AST::i8;
llvm::Type *AST::i32;
llvm::Type *AST::i64;

void Program::llvm_compile_and_dump(bool optimize = false) {
  // Initialize
  TheModule = std::make_unique<Module>("Llama program", TheContext);
  TheFPM = std::make_unique<legacy::FunctionPassManager>(TheModule.get());

  if (optimize) {
    TheFPM->add(createPromoteMemoryToRegisterPass());
    TheFPM->add(createInstructionCombiningPass());
    TheFPM->add(createReassociatePass());
    TheFPM->add(createGVNPass());
    TheFPM->add(createCFGSimplificationPass());
  }
  TheFPM->doInitialization();
  // Initialize types
  i8 = IntegerType::get(TheContext, 8);
  i32 = IntegerType::get(TheContext, 32);
  i64 = IntegerType::get(TheContext, 64);

  // Initialize global variables
  ArrayType *vars_type = ArrayType::get(i32, 26);
  TheVars = new GlobalVariable(*TheModule, vars_type, false,
                               GlobalValue::PrivateLinkage,
                               ConstantAggregateZero::get(vars_type), "vars");

  // TheVars->setAlignment(16);

  ArrayType *nl_type = ArrayType::get(i8, 2);
  TheNL = new GlobalVariable(
      *TheModule, nl_type, true, GlobalValue::PrivateLinkage,
      ConstantArray::get(nl_type, {c8('\n'), c8('\0')}), "nl");

  // TheNL->setAlignment(1);

  // Initialize library functions
  FunctionType *writeInteger_type =
      FunctionType::get(llvm::Type::getVoidTy(TheContext), {i64}, false);

  TheWriteInteger =
      Function::Create(writeInteger_type, Function::ExternalLinkage,
                       "writeInteger", TheModule.get());
                       
  FunctionType *writeReal_type =
      FunctionType::get(llvm::Type::getVoidTy(TheContext), {llvm::Type::getDoubleTy(TheContext)}, false);

  TheWriteReal =
      Function::Create(writeReal_type, Function::ExternalLinkage,
                       "writeReal", TheModule.get());

  FunctionType *writeString_type = FunctionType::get(
      llvm::Type::getVoidTy(TheContext), {PointerType::get(i8, 0)}, false);

  TheWriteString = Function::Create(writeString_type, Function::ExternalLinkage,
                                    "writeString", TheModule.get());
  // Defint and start the main function.
  FunctionType *main_type = FunctionType::get(i64, {}, false);

  Function *main = Function::Create(main_type, Function::ExternalLinkage,
                                    "main", TheModule.get());
  BasicBlock *BB = BasicBlock::Create(TheContext, "entry", main);
  Builder.SetInsertPoint(BB);
  // Emit the program code.

  // Compile each statement
  for (Stmt *stmt : *statements) {
    stmt->compile();
  }

  Builder.CreateRet(c64(0));
  // Verify the IR.
  bool bad = verifyModule(*TheModule, &errs());
  if (bad) {
    std::cout << std::endl << std::endl << std::endl;
    std::cerr << "The IR is bad!" << std::endl;
    TheModule->print(errs(), nullptr);
    std::exit(1);
  }
  // Optimize!
  TheFPM->run(*main);
  // Print out the IR.
  TheModule->print(outs(), nullptr);
}

Value *LetDef::compile() const {
  Value *n = c64(33);
  Value *f = cfloat(4.4);
  //Builder.CreateCall(TheWriteInteger, std::vector<Value *>{n});
  Builder.CreateCall(TheWriteReal, std::vector<Value *>{f});
  Value *nl =
      Builder.CreateGEP(TheNL, std::vector<Value *>{c32(0), c32(0)}, "nl");
  Builder.CreateCall(TheWriteString, std::vector<Value *>{nl});
  return nullptr;
}