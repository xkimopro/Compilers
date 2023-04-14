using namespace llvm;

LLVMContext AST::TheContext;
IRBuilder<> AST::Builder(TheContext);
std::unique_ptr<Module> AST::TheModule;
std::unique_ptr<legacy::FunctionPassManager> AST::TheFPM;

GlobalVariable *AST::TheVars;
GlobalVariable *AST::TheNL;

// Write Functions
Function *AST::TheWriteBoolean;
Function *AST::TheWriteInteger;
Function *AST::TheWriteChar;
Function *AST::TheWriteString;
Function *AST::TheWriteReal;

// Read Functions
Function *AST::TheReadInteger;
Function *AST::TheReadBoolean;
Function *AST::TheReadChar;
Function *AST::TheReadReal;
Function *AST::TheReadString;

// Math Functions
Function *AST::abs;
Function *AST::fabs;
Function *AST::sqrt;
Function *AST::cos;
Function *AST::tan;
Function *AST::atan;
Function *AST::exp;
Function *AST::ln;
Function *AST::pi;

// Type Declarations
llvm::Type *AST::i1;
llvm::Type *AST::i8;
llvm::Type *AST::i32;
llvm::Type *AST::i64;
llvm::Type *AST::ifloat;

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
  i1 = IntegerType::get(TheContext, 1);
  i8 = IntegerType::get(TheContext, 8);
  i32 = IntegerType::get(TheContext, 32);
  i64 = IntegerType::get(TheContext, 64);
  ifloat = llvm::Type::getX86_FP80Ty(TheContext);

  // Initialize global variables
  ArrayType *vars_type = ArrayType::get(i32, 26);
  TheVars = new GlobalVariable(*TheModule, vars_type, false,
                               GlobalValue::PrivateLinkage,
                               ConstantAggregateZero::get(vars_type), "vars");
  ArrayType *nl_type = ArrayType::get(i8, 2);
  TheNL = new GlobalVariable(
      *TheModule, nl_type, true, GlobalValue::PrivateLinkage,
      ConstantArray::get(nl_type, {c8('\n') , c8('\0')}), "nl");

  // Initialize Write Library Functions
  FunctionType *writeInteger_type =
      FunctionType::get(llvm::Type::getVoidTy(TheContext), {i64}, false);
  TheWriteInteger =
      Function::Create(writeInteger_type, Function::ExternalLinkage,
                       "writeInteger", TheModule.get());
  FunctionType *writeBoolean_type =
      FunctionType::get(llvm::Type::getVoidTy(TheContext), {i1}, false);
  TheWriteBoolean =
      Function::Create(writeBoolean_type, Function::ExternalLinkage,
                       "writeBoolean", TheModule.get());
  FunctionType *writeChar_type =
      FunctionType::get(llvm::Type::getVoidTy(TheContext), {i8}, false);
  TheWriteChar = Function::Create(writeChar_type, Function::ExternalLinkage,
                                  "writeChar", TheModule.get());
  FunctionType *writeReal_type =
      FunctionType::get(llvm::Type::getVoidTy(TheContext),
                        {ifloat}, false);
  TheWriteReal = Function::Create(writeReal_type, Function::ExternalLinkage,
                                  "writeReal", TheModule.get());
  FunctionType *writeString_type = FunctionType::get(
      llvm::Type::getVoidTy(TheContext), {PointerType::get(i8, 0)}, false);
  TheWriteString = Function::Create(writeString_type, Function::ExternalLinkage,
                                    "writeString", TheModule.get());

  // Initialize Read Library Functions
  FunctionType *ReadInteger_type = FunctionType::get(i64, {}, false);
  TheReadInteger = Function::Create(ReadInteger_type, Function::ExternalLinkage,
                                    "readInteger", TheModule.get());
  FunctionType *ReadBoolean_type = FunctionType::get(i1, {}, false);
  TheReadBoolean = Function::Create(ReadBoolean_type, Function::ExternalLinkage,
                                    "readBoolean", TheModule.get());
  FunctionType *ReadChar_type = FunctionType::get(i8, {}, false);
  TheReadChar = Function::Create(ReadChar_type, Function::ExternalLinkage,
                                    "readChar", TheModule.get()); ;;
  FunctionType *ReadReal_type = FunctionType::get(ifloat, {}, false);
  TheReadReal = Function::Create(ReadReal_type, Function::ExternalLinkage,
                                    "readReal", TheModule.get());
  FunctionType *ReadString_type = FunctionType::get(PointerType::get(PointerType::get(i8, 0), 0), {}, false);
  TheReadString = Function::Create(ReadString_type, Function::ExternalLinkage,
                                    "readString", TheModule.get());

  // Initialize Math Functions










  // Define and start the main function.
  FunctionType *main_type = FunctionType::get(i64, {}, false);
  Function *main = Function::Create(main_type, Function::ExternalLinkage,
                                    "main", TheModule.get());
  BasicBlock *BB = BasicBlock::Create(TheContext, "entry", main);
  Builder.SetInsertPoint(BB);
  // Emit the program code.
  compile();
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

Value *Program::compile() const {
  // Compile each statement
  for (Stmt *stmt : *statements) {
    stmt->compile();
  }
  return nullptr;
}

Value *LetDef::compile() const {
  Value *n = c64(33);
  // Value *f = cfloat(4.4);
  Builder.CreateCall(TheWriteInteger, std::vector<Value *>{n});
  // Builder.CreateCall(TheWriteReal, std::vector<Value *>{f});

  // Value *nl =
  //     Builder.CreateGEP(TheNL, std::vector<Value *>{c32(0), c32(0)}, "");
  // Builder.CreateCall(TheWriteString, std::vector<Value *>{nl});

  // Value *ret = Builder.CreateCall(TheReadString, std::vector<Value *>{}, "x");
  // Value *ret_ptr =  Builder.CreateGEP(ret,   std::vector<Value *>{}  , "y");
  // Builder.CreateCall(TheWriteString, std::vector<Value *>{ret_ptr});

  return nullptr;
}