#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "symbol.hpp"

template <typename T>
inline std::ostream &operator<<(std::ostream &out, const std::vector<T> &v)
{
  bool first = true;
  for (T t : v)
  {
    if (!first)
      out << ", ";
    first = false;
    out << *t;
  }
  return out;
}

inline void semanticError(std::string msg)
{
  std::cerr << msg << std::endl;
  exit(1);
}

typedef enum
{
  unop_plus,
  unop_minus,
  unop_float_plus,
  unop_float_minus,
  unop_exclamation,
  unop_not,
  unop_delete
} unop_enum;

typedef enum
{
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

typedef enum
{
  variable_definition,
  function_definition
} normal_definition;

typedef enum  {
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
};

inline std::ostream &operator<<(std::ostream &out, const AST &t)
{
  t.printOn(out);
  return out;
}

class Stmt : public AST
{
};

class Expr : public AST
{
};

class Int_Expr : public Expr
{
public:
  Int_Expr(int n) : num(n) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Int_Expr(" << num << ")";
  }

private:
  int num;
};

class Float_Expr : public Expr
{
public:
  Float_Expr(float n) : num(n) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Float_Expr(" << num << ")";
  }

private:
  float num;
};

class Char_Expr : public Expr
{
public:
  Char_Expr(char c) : chr(c) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Char_Expr(" << chr << ")";
  }

private:
  char chr;
};

class Str_Expr : public Expr
{
public:
  Str_Expr(std::string s) : str(s.substr(1, s.size() - 2)) {}
  virtual void printOn(std::ostream &out) const override
  {

    out << "Str_Expr(" << str << ")";
  }

private:
  std::string str;
};

class Bool_Expr : public Expr
{
public:
  Bool_Expr(bool b) : var(b) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Bool_Expr(" << var << ")";
  }

private:
  bool var;
};

class Unit : public Expr
{
public:
  Unit() {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Unit()";
  }
};

class Array : public Expr
{
public:
  Array(std::string s, std::vector<Expr *> *v) : var(s), expr_vec(v) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Array(" << var << ", [" << *expr_vec << "])";
  }

private:
  std::string var;
  std::vector<Expr *> *expr_vec;
};

class Dim : public Expr
{
public:
  Dim(std::string s, int i = 1) : var(s), ind(i) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Dim(" << ind << ", " << var << ")";
  }

private:
  std::string var;
  int ind;
};

class id : public Expr
{
public:
  id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "id(" << var << ")";
  }

private:
  std::string var;
};

class Id : public Expr
{
public:
  Id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Id(" << var << ")";
  }

private:
  std::string var;
};

class While : public Expr
{
public:
  While(Expr *e1, Expr *e2) : cond(e1), stmt(e2) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "While(" << *cond << ", " << *stmt << ")";
  }

private:
  Expr *cond, *stmt;
};

class For : public Expr
{
public:
  For(std::string id1, Expr *start1, Expr *end1, Expr *do_stmt1, bool down1) : id(id1), start(start1), end(end1), do_stmt(do_stmt1), down(down1) {}
  virtual void printOn(std::ostream &out) const override
  {
    std::string for_str = down ? " down to " : " to ";
    out << "For(" << id << " from " << *start << for_str << *end << ") do (" << *do_stmt << ")";
  }

private:
  std::string id;
  Expr *start, *end, *do_stmt;
  bool down;
};

class call : public Expr
{
public:
  call(std::string s, std::vector<Expr *> *v) : fun_name(s), expr_vec(v) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "call(" << fun_name << ", (" << *expr_vec << "))";
  }

private:
  std::string fun_name;
  std::vector<Expr *> *expr_vec;
};

class Call : public Expr
{
public:
  Call(std::string s, std::vector<Expr *> *v) : fun_name(s), expr_vec(v) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Call(" << fun_name << ", (" << *expr_vec << "))";
  }

private:
  std::string fun_name;
  std::vector<Expr *> *expr_vec;
};

class UnOp : public Expr
{
public:
  UnOp(unop_enum op1, Expr *e1) : op(op1), e(e1) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Unop(" << op << ", " << *e << ")";
  }

private:
  unop_enum op;
  Expr *e;
};

class BinOp : public Expr
{
public:
  BinOp(Expr *e1, binop_enum op1, Expr *e2) : expr1(e1), op(op1), expr2(e2) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Binop(" << *expr1 << ", " << op << ", " << *expr2 << ")";
  }

private:
  binop_enum op;
  Expr *expr1, *expr2;
};

class If : public Expr
{
public:
  If(Expr *e1, Expr *e2, Expr *e3) : expr1(e1), expr2(e2), expr3(e3) {}
  virtual void printOn(std::ostream &out) const override
  {
    std::string ifelse = (expr3 != nullptr ? "If_Else(" : "If(");
    out << ifelse << *expr1 << ", " << *expr2;
    if (expr3 != nullptr)
      out << ", " << *expr3;
    out << ")";
  }

private:
  Expr *expr1, *expr2, *expr3;
};

class Pattern : public AST
{
};

class Pattern_Int_Expr : public Pattern
{
public:
  Pattern_Int_Expr(int n) : num(n) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Pattern_Int_Expr(" << num << ")";
  }

private:
  int num;
};

class Pattern_Float_Expr : public Pattern
{
public:
  Pattern_Float_Expr(float n) : num(n) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Pattern_Float_Expr(" << num << ")";
  }

private:
  float num;
};

class Pattern_Char_Expr : public Pattern
{
public:
  Pattern_Char_Expr(char c) : chr(c) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Pattern_Char_Expr(" << chr << ")";
  }

private:
  char chr;
};

class Pattern_Bool_Expr : public Pattern
{
public:
  Pattern_Bool_Expr(bool b) : var(b) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Pattern_Bool_Expr(" << var << ")";
  }

private:
  bool var;
};

class Pattern_id : public Pattern
{
public:
  Pattern_id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Pattern_id(" << var << ")";
  }

private:
  std::string var;
};

class Pattern_Id : public Pattern
{
public:
  Pattern_Id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Pattern_Id(" << var << ")";
  }

private:
  std::string var;
};

class Pattern_Call : public Pattern
{
public:
  Pattern_Call(std::string s, std::vector<Pattern *> *v) : fun_name(s), pattern_vec(v) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Pattern_Call(" << fun_name << ", (" << *pattern_vec << "))";
  }

private:
  std::string fun_name;
  std::vector<Pattern *> *pattern_vec;
};

class Clause : public AST
{
public:
  Clause(Pattern *p1, Expr *e1) : p(p1), e(e1) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Clause(" << *p << ", " << *e << ")";
  }

private:
  Pattern *p;
  Expr *e;
};

class Match : public Expr
{
public:
  Match(Expr *e1, std::vector<Clause *> *v) : e(e1), vec(v) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Match(" << *e << ", " << *vec << ")";
  }

private:
  Expr *e;
  std::vector<Clause *> *vec;
};

class Type : public AST
{
};

class Type_Unit : public Type
{
public:
  Type_Unit() : my_type(type_unit) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Unit()";
  }

  private:
    main_type my_type;
};

class Type_Int : public Type
{
public:
  Type_Int() : my_type(type_int) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Int()";
  }

private:
    main_type my_type;
  
};

class Type_Char : public Type
{
public:
  Type_Char() : my_type(type_char) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Char()";
  }

  private:
    main_type my_type;
};

class Type_Float : public Type
{
public:
  Type_Float() : my_type(type_float) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Float()";
  }

private:
  main_type my_type;
};

class Type_Bool : public Type
{
public:
  Type_Bool(): my_type(type_bool) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Bool()";
  }

  private:
    main_type my_type;
};






class Type_Func : public Type
{
public:
  Type_Func(Type *t1, Type *t2) : my_type(type_func) , from(t1), to(t2) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Func(" << *from << ", " << *to << ")";
  }

private:
  Type *from, *to;
  main_type my_type;

};

class Type_Ref : public Type
{
public:
  Type_Ref(Type *t1) : my_type(type_ref) , t(t1) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Ref(" << *t << ")";
  }

private:
  Type *t;
  main_type my_type;
  
};

class Type_Array : public Type
{
public:
  Type_Array(int i, Type *t1) : my_type(my_type), dim(i), t(t1) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Array(" << dim << ", " << *t << ")";
  }

private:
  int dim;
  Type *t;
  main_type my_type;
  
};

class Type_id : public Type
{
public:
  Type_id(std::string s) : my_type(type_id) , var(s) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_id(" << var << ")";
  }

private:
  std::string var;
  main_type my_type;

};

class New : public Expr
{
public:
  New(Type *t) : typ(t) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "New(" << *typ << ")";
  }

private:
  Type *typ;
};
// extern std::vector<int> rt_stack;

// class Id: public Expr {
// public:
//   Id(char v): var(v), offset(-1) {}
//   virtual void printOn(std::ostream &out) const override {
//     out << "Id(" << var << "@" << offset << ")";
//   }
//   virtual int eval() const override {
//     return rt_stack[offset];
//   }
//   virtual void sem() override {
//     SymbolEntry *e = st.lookup(var);
//     type = e->type;
//     offset = e->offset;
//   }
// private:
//   char var;
//   int offset;
// };

// class Const: public Expr {
// public:
//   Const(int n): num(n) {}
//   virtual void printOn(std::ostream &out) const override {
//     out << "Const(" << num << ")";
//   }
//   virtual int eval() const override { return num; }
//   virtual void sem() override { type = TYPE_int; }
// private:
//   int num;
// };

// class BinOp: public Expr {
// public:
//   BinOp(Expr *l, char o, Expr *r): left(l), op(o), right(r) {}
//   ~BinOp() { delete left; delete right; }
//   virtual void printOn(std::ostream &out) const override {
//     out << op << "(" << *left << ", " << *right << ")";
//   }
//   virtual void sem() override {
//     left->type_check(TYPE_int);
//     right->type_check(TYPE_int);
//     switch (op) {
//     case '+': case '-': case '*': case '/': case '%':
//       type = TYPE_int; break;
//     case '=': case '<': case '>':
//       type = TYPE_bool; break;
//     }
//   }
//   virtual int eval() const override {
//     switch (op) {
//     case '+': return left->eval() + right->eval();
//     case '-': return left->eval() - right->eval();
//     case '*': return left->eval() * right->eval();
//     case '/': return left->eval() / right->eval();
//     case '%': return left->eval() % right->eval();
//     case '=': return left->eval() == right->eval();
//     case '<': return left->eval() < right->eval();
//     case '>': return left->eval() > right->eval();
//     }
//     return 0;  // this will never be reached.
//   }
// private:
//   Expr *left;
//   char op;
//   Expr *right;
// };

// class Let: public Stmt {
// public:
//   Let(char v, Expr *e): var(v), offset(-1), expr(e) {}
//   ~Let() { delete expr; }
//   virtual void printOn(std::ostream &out) const override {
//     out << "Let(" << var << "@" << offset << " = " << *expr << ")";
//   }
//   virtual void sem() override {
//     SymbolEntry *lhs = st.lookup(var);
//     expr->type_check(lhs->type);
//     offset = lhs->offset;
//   }
//   virtual void run() const override {
//     rt_stack[offset] = expr->eval();
//   }
// private:
//   char var;
//   int offset;
//   Expr *expr;
// };

// class Print: public Stmt {
// public:
//   Print(Expr *e): expr(e) {}
//   ~Print() { delete expr; }
//   virtual void printOn(std::ostream &out) const override {
//     out << "Print(" << *expr << ")";
//   }
//   virtual void sem() override {
//     expr->type_check(TYPE_int);
//   }
//   virtual void run() const override {
//     std::cout << expr->eval() << std::endl;
//   }
// private:
//   Expr *expr;
// };

// class If: public Stmt {
// public:
//   If(Expr *c, Stmt *s1, Stmt *s2 = nullptr):
//     cond(c), stmt1(s1), stmt2(s2) {}
//   ~If() { delete cond; delete stmt1; delete stmt2; }
//   virtual void printOn(std::ostream &out) const override {
//     out << "If(" << *cond << ", " << *stmt1;
//     if (stmt2 != nullptr) out << ", " << *stmt2;
//     out << ")";
//   }
//   virtual void sem() override {
//     cond->type_check(TYPE_bool);
//     stmt1->sem();
//     if (stmt2 != nullptr) stmt2->sem();
//   }
//   virtual void run() const override {
//     if (cond->eval())
//       stmt1->run();
//     else if (stmt2 != nullptr)
//       stmt2->run();
//   }
// private:
//   Expr *cond;
//   Stmt *stmt1;
//   Stmt *stmt2;
// };

// class For: public Stmt {
// public:
//   For(Expr *e, Stmt *s): expr(e), stmt(s) {}
//   ~For() { delete expr; delete stmt; }
//   virtual void printOn(std::ostream &out) const override {
//     out << "For(" << *expr << ", " << *stmt << ")";
//   }
//   virtual void sem() override {
//     expr->type_check(TYPE_int);
//     stmt->sem();
//   }
//   virtual void run() const override {
//     for (int times = expr->eval(), i = 0; i < times; ++i)
//       stmt->run();
//   }
// private:
//   Expr *expr;
//   Stmt *stmt;
// };

// class Decl: public AST {
// public:
//   Decl(char c, Type t): var(c), type(t) {}
//   virtual void printOn(std::ostream &out) const override {
//     out << "Decl(" << var << " : " << type << ")";
//   }
//   virtual void sem() override { st.insert(var, type); }
// private:
//   char var;
//   Type type;
// };

class Constr : public AST
{
public:
  Constr(std::string s, std::vector<Type *> *v) : Id(s), type_vec(v) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Constr(" << Id;
    if (type_vec != nullptr)
      out << ", " << *type_vec;
    out << ")";
  }

private:
  std::string Id;
  std::vector<Type *> *type_vec;
};

class Par : public AST
{
public:
  Par(std::string s, Type *t) : id(s), typ(t) {}

  virtual void printOn(std::ostream &out) const override
  {
    out << "Par(" << id;
    if (typ != nullptr)
      out << ", " << *typ;
    out << ")";
  }

  virtual void sem() override {
    if (typ == nullptr) semanticError("No type specified for parameter " + id);
    
  }

private:
  std::string id;
  Type *typ;
};

class TDef : public AST
{
public:
  TDef(std::string s, std::vector<Constr *> *v) : id(s), constr_vec(v) {}

  virtual void printOn(std::ostream &out) const override
  {
    out << "TDef(" << id << ", " << *constr_vec << ")";
  }

private:
  std::string id;
  std::vector<Constr *> *constr_vec;
};

class TypeDef : public Stmt
{
public:
  TypeDef(std::vector<TDef *> *v) : tdef_vec(v) {}

  virtual void sem() override
  {
    if (tdef_vec == nullptr)
      return;
    for (TDef *tdef : *tdef_vec)
    {
      tdef->sem();
    }
  }

  virtual void printOn(std::ostream &out) const override
  {
    out << "Typedef(" << *tdef_vec << ")";
  }

private:
  std::vector<TDef *> *tdef_vec;
};

class Def : public AST
{
};

class MutableDef : public Def
{
public:
  MutableDef(std::string s, std::vector<Expr *> *e, Type *t) : id(s), expr_vec(e), typ(t) {}

  virtual void printOn(std::ostream &out) const override
  {
    out << "MutableDef(" << id;
    if (expr_vec != nullptr)
      out << ", [" << *expr_vec << "]";
    if (typ != nullptr)
      out << ", " << *typ;
    out << ")";
  }

private:
  std::string id;
  std::vector<Expr *> *expr_vec;
  Type *typ;
};

class NormalDef : public Def
{
public:
  NormalDef(std::string id1, std::vector<Par *> *v, Type *t, Expr *e) : id(id1), par_vec(v), typ(t), expr(e) {}

  virtual void sem() override
  {
    normal_def_type = par_vec == nullptr ? variable_definition : function_definition;

    if (normal_def_type == function_definition){
      if (typ == nullptr) semanticError("No type specified for function " + id);
      for (Par *par : *par_vec){
        par->sem();  
      }
      // Check that type of result = type of expression
    }
    else{
        
    }
  }

  virtual void printOn(std::ostream &out) const override
  {
    out << "Def(" << id << ", [" << *par_vec << "], ";
    if (typ != nullptr)
      out << *typ << ", ";
    out << *expr << ")";
  }

private:
  normal_definition normal_def_type;
  std::vector<Par *> *par_vec;
  std::string id;
  Type *typ;
  Expr *expr;
};

class LetDef : public Stmt
{
public:
  LetDef(bool b, std::vector<Def *> *v) : rec(b), def_vec(v) {}

  virtual void sem() override
  {

    if (def_vec == nullptr)
      return;

    for (Def *def : *def_vec)
    {
      def->sem();
    }

    // std::cout << "Letdef" << std::endl;
  }

  virtual void printOn(std::ostream &out) const override
  {
    out << "Letdef(" << rec << ", " << *def_vec << ")";
  }

private:
  bool rec;
  std::vector<Def *> *def_vec;
};

class LetIn : public Expr
{
public:
  LetIn(LetDef *d, Expr *e1) : def(d), expr(e1) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "LetIn(" << *def << ", " << *expr << ")";
  }

private:
  LetDef *def;
  Expr *expr;
};
