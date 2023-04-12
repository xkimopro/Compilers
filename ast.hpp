#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "symbol.hpp"

// llvm includes
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Transforms/Utils.h>

extern SymbolTable st;
extern TypeDefTable tt;
extern ConstrTable ct;

using namespace llvm;

typedef enum {
  unop_plus,
  unop_minus,
  unop_float_plus,
  unop_float_minus,
  unop_exclamation,
  unop_not,
  unop_delete
} unop_enum;

typedef enum {
  binop_plus,
  binop_minus,
  binop_mult,
  binop_div,
  binop_float_plus,
  binop_float_minus,
  binop_float_mult,
  binop_float_div,
  binop_mod,
  binop_pow,
  binop_single_eq,
  binop_struct_diff,
  binop_l,
  binop_g,
  binop_leq,
  binop_geq,
  binop_double_eq,
  binop_diff,
  binop_and,
  binop_or,
  binop_semicolon,
  binop_assign
} binop_enum;

typedef enum {
  type_unit,
  type_int,
  type_char,
  type_bool,
  type_float,
  type_func,
  type_ref,
  type_array,
  type_id,
  type_undefined
} main_type;

class AST
{
public:
  virtual ~AST() {}
  virtual void printOn(std::ostream &out) const = 0;
  virtual void sem() {}
  virtual Value *compile() const { return nullptr; }

protected:
  static LLVMContext TheContext;
  static IRBuilder<> Builder;

  static std::unique_ptr<Module> TheModule;
  static std::unique_ptr<legacy::FunctionPassManager> TheFPM;

  static GlobalVariable *TheVars;
  static GlobalVariable *TheNL;

  // Write Functions
  static Function *TheWriteInteger;
  static Function *TheWriteBoolean;
  static Function *TheWriteChar;
  static Function *TheWriteReal;
  static Function *TheWriteString;

  // Read Functions
  static Function *TheReadInteger;
  static Function *TheReadBoolean;
  static Function *TheReadChar;
  static Function *TheReadReal;
  static Function *TheReadString;

  // Math Functions
  static Function *abs;
  static Function *fabs;
  static Function *sqrt;
  static Function *cos;
  static Function *tan;
  static Function *atan;
  static Function *exp;
  static Function *ln;
  static Function *pi;

  // Type Shortcuts
  static llvm::Type *i1;
  static llvm::Type *i8;
  static llvm::Type *i32;
  static llvm::Type *i64;
  static llvm::Type *ifloat;

  static ConstantInt *c8(char c)
  {
    return ConstantInt::get(TheContext, APInt(8, c, true));
  }
  static ConstantInt *c32(int n)
  {
    return ConstantInt::get(TheContext, APInt(32, n, true));
  }
  static ConstantInt *c64(int n)
  {
    return ConstantInt::get(TheContext, APInt(64, n, true));
  }

  static llvm::Constant *cfloat(float f) {
    return llvm::ConstantFP::get(llvm::Type::getX86_FP80Ty(TheContext), f);
  }
};

inline std::ostream &operator<<(std::ostream &out, const AST &t)
{
  t.printOn(out);
  return out;
}

class Stmt : public AST
{
};

class Program : public AST
{
public:
  Program(std::vector<Stmt *> *s) : statements(s) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;
  virtual Value *compile() const override;
  void llvm_compile_and_dump(bool optimize);

 private:
  std::vector<Stmt *> *statements;
};

class Type : public AST
{
public:
  virtual main_type get_type() { return type_undefined; }
  virtual ::Type *getChild1() { return nullptr; }
  virtual ::Type *getChild2() { return nullptr; }
  virtual long unsigned int getDimensions() { return 0; }
  virtual std::string get_id() { return ""; }
  virtual bool equals(::Type *other)
  {
    if (other == nullptr)
      return false;
    if (other->get_type() == type_undefined)
      return other->equals(this);
    return this->get_type() == other->get_type();
  }
};

class Type_Unit : public ::Type
{
public:
  Type_Unit() {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
};

class Type_Int : public ::Type
{
public:
  Type_Int() {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
};

class Type_Float : public ::Type
{
public:
  Type_Float() {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
};

class Type_Char : public ::Type
{
public:
  Type_Char() {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
};

class Type_Bool : public ::Type
{
public:
  Type_Bool() {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
};

class Type_Func : public ::Type
{
public:
  Type_Func(::Type *t1, ::Type *t2) : from(t1), to(t2) {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
  virtual ::Type *getChild1() override;
  virtual ::Type *getChild2() override;
  virtual bool equals(::Type *other) override;
  virtual void sem() override;

private:
  ::Type *from, *to;
};

class Type_Ref : public ::Type
{
public:
  Type_Ref(::Type *t) : t(t) {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
  virtual ::Type *getChild1() override;
  virtual bool equals(::Type *other) override;
  virtual void sem() override;

private:
  ::Type *t;
};

class Type_Array : public ::Type
{
public:
  Type_Array(long unsigned int i, ::Type *t1) : dim(i), t(t1) {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
  virtual ::Type *getChild1() override;
  virtual long unsigned int getDimensions() override;
  virtual bool equals(::Type *other) override;
  virtual void sem() override;

private:
  long unsigned int dim;
  ::Type *t;
};

class Type_id : public ::Type
{
public:
  Type_id(std::string s) : id(s) {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
  virtual std::string get_id() override;
  virtual bool equals(::Type *other) override;
  virtual void sem() override;

private:
  std::string id;
};

class Type_Undefined : public ::Type
{
public:
  Type_Undefined() : t(nullptr) {}
  virtual void printOn(std::ostream &out) const override;
  virtual main_type get_type() override;
  virtual ::Type *getChild1() override;
  virtual ::Type *getChild2() override;
  virtual long unsigned int getDimensions() override;
  virtual std::string get_id() override;
  virtual bool equals(::Type *other) override;

private:
  ::Type *t;
};

class Expr : public AST
{
public:
  virtual void type_check(::Type *t);
  ::Type *t;
};

class Int_Expr : public Expr
{
public:
  Int_Expr(int n) : num(n) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  int num;
};

class Float_Expr : public Expr
{
public:
  Float_Expr(float n) : num(n) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  float num;
};

class Char_Expr : public Expr
{
public:
  Char_Expr(char c) : chr(c) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  char chr;
};

class Str_Expr : public Expr
{
public:
  Str_Expr(std::string s) : str(s.substr(1, s.size() - 2)) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string str;
};

class Bool_Expr : public Expr
{
public:
  Bool_Expr(bool b) : var(b) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  bool var;
};

class Unit_Expr : public Expr
{
public:
  Unit_Expr() {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;
};

class Array : public Expr
{
public:
  Array(std::string s, std::vector<Expr *> *v) : var(s), expr_vec(v) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string var;
  std::vector<Expr *> *expr_vec;
};

class Dim : public Expr
{
public:
  Dim(std::string s, unsigned long int i = 1) : var(s), ind(i) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string var;
  unsigned long int ind;
};

class id : public Expr
{
public:
  id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string var;
};

class Id : public Expr
{
public:
  Id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string var;
};

class While : public Expr
{
public:
  While(Expr *e1, Expr *e2) : cond(e1), stmt(e2) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  Expr *cond, *stmt;
};

class For : public Expr
{
public:
  For(std::string id1, Expr *start1, Expr *end1, Expr *do_stmt1, bool down1)
      : id(id1), start(start1), end(end1), do_stmt(do_stmt1), down(down1) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string id;
  Expr *start, *end, *do_stmt;
  bool down;
};

class call : public Expr
{
public:
  call(std::string s, std::vector<Expr *> *v) : fun_name(s), expr_vec(v) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string fun_name;
  std::vector<Expr *> *expr_vec;
};

// class Call : public Expr
// {
// public:
//   Call(std::string s, std::vector<Expr *> *v) : fun_name(s), expr_vec(v) {}
//   virtual void printOn(std::ostream &out) const override
//   {
//     out << "Call(" << fun_name << ", (" << *expr_vec << "))";
//   }

// private:
//   std::string fun_name;
//   std::vector<Expr *> *expr_vec;
// };

class UnOp : public Expr
{
public:
  UnOp(unop_enum op1, Expr *e1) : op(op1), e(e1) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  unop_enum op;
  Expr *e;
};

class BinOp : public Expr
{
public:
  BinOp(Expr *e1, binop_enum op1, Expr *e2) : left(e1), op(op1), right(e2) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  Expr *left;
  binop_enum op;
  Expr *right;
};

class If : public Expr
{
public:
  If(Expr *e1, Expr *e2, Expr *e3) : expr1(e1), expr2(e2), expr3(e3) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  Expr *expr1, *expr2, *expr3;
};

class New : public Expr
{
public:
  New(::Type *t) : typ(t) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  ::Type *typ;
};

class Pattern : public AST
{
public:
  virtual void sem() {}
  ::Type *t;
};

class Pattern_Int_Expr : public Pattern
{
public:
  Pattern_Int_Expr(int n) : num(n) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  int num;
};

class Pattern_Float_Expr : public Pattern
{
public:
  Pattern_Float_Expr(float n) : num(n) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  float num;
};

class Pattern_Char_Expr : public Pattern
{
public:
  Pattern_Char_Expr(char c) : chr(c) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  char chr;
};

class Pattern_Bool_Expr : public Pattern
{
public:
  Pattern_Bool_Expr(bool b) : var(b) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  bool var;
};

class Pattern_id : public Pattern
{
public:
  Pattern_id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string var;
};

class Pattern_Id : public Pattern
{
public:
  Pattern_Id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string var;
};

class Pattern_Call : public Pattern
{
public:
  Pattern_Call(std::string s, std::vector<Pattern *> *v)
      : var(s), pattern_vec(v) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string var;
  std::vector<Pattern *> *pattern_vec;
};

class Clause : public AST
{
public:
  Clause(Pattern *p1, Expr *e1) : p(p1), e(e1) {}
  virtual void printOn(std::ostream &out) const override;
  Pattern *p;
  Expr *e;
};

class Match : public Expr
{
public:
  Match(Expr *e1, std::vector<Clause *> *v) : e(e1), vec(v) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  Expr *e;
  std::vector<Clause *> *vec;
};

class Constr : public AST
{
public:
  Constr(std::string s, std::vector<::Type *> *v) : Id(s), type_vec(v) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem(std::string id);

private:
  std::string Id;
  std::vector<::Type *> *type_vec;
};

class Par : public AST
{
public:
  Par(std::string s, ::Type *typ) : t(typ), id(s) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;
  ::Type *t;

private:
  std::string id;
};

class TDef : public AST
{
public:
  TDef(std::string s, std::vector<Constr *> *v) : id(s), constr_vec(v) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;
  virtual void sem2();

private:
  std::string id;
  std::vector<Constr *> *constr_vec;
};

class TypeDef : public Stmt
{
public:
  TypeDef(std::vector<TDef *> *v) : tdef_vec(v) {}
  virtual void sem() override;
  virtual void printOn(std::ostream &out) const override;

private:
  std::vector<TDef *> *tdef_vec;
};

class Def : public AST
{
public:
  virtual void sem2(){};
};

class MutableDef : public Def
{
public:
  MutableDef(std::string s, std::vector<Expr *> *e, ::Type *t)
      : id(s), expr_vec(e), typ(t) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  std::string id;
  std::vector<Expr *> *expr_vec;
  ::Type *typ;
};

class NormalDef : public Def
{
public:
  NormalDef(std::string id1, std::vector<Par *> *v, ::Type *t, Expr *e)
      : id(id1), par_vec(v), typ(t), expr(e) {}

  virtual void sem() override;
  virtual void sem2() override;
  virtual void printOn(std::ostream &out) const override;

private:
  std::string id;
  std::vector<Par *> *par_vec;
  ::Type *typ;
  Expr *expr;
};

class LetDef : public Stmt
{
public:
  LetDef(bool b, std::vector<Def *> *v) : rec(b), def_vec(v) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;
  virtual Value *compile() const override;

 private:
  bool rec;
  std::vector<Def *> *def_vec;
};

class LetIn : public Expr
{
public:
  LetIn(LetDef *d, Expr *e1) : def(d), expr(e1) {}
  virtual void printOn(std::ostream &out) const override;
  virtual void sem() override;

private:
  LetDef *def;
  Expr *expr;
};