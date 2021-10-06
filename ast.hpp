#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "symbol.hpp"

extern SymbolTable st;

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

class Type : public AST
{
public:
  virtual main_type get_type(){};
  virtual Type *getChild1()
  {
    return nullptr;
  }
  virtual Type *getChild2()
  {
    return nullptr;
  }
  virtual int getDimension()
  {
    return 0;
  }
  virtual std::string get_id()
  {
    return "";
  }
  virtual bool equals(Type *other)
  {
    if (other == nullptr)
      return false;
    return this->get_type() == other->get_type();
  }
};

class Type_Unit : public Type
{
public:
  Type_Unit() {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Unit()";
  }
  virtual main_type get_type() override
  {
    return type_unit;
  }
};

class Type_Int : public Type
{
public:
  Type_Int() {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Int()";
  }
  virtual main_type get_type() override
  {
    return type_int;
  }
};

class Type_Float : public Type
{
public:
  Type_Float() {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Float()";
  }
  virtual main_type get_type() override
  {
    return type_float;
  }
};

class Type_Char : public Type
{
public:
  Type_Char() {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Char()";
  }
  virtual main_type get_type() override
  {
    return type_char;
  }
};

class Type_Bool : public Type
{
public:
  Type_Bool() {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Bool()";
  }
  virtual main_type get_type() override
  {
    return type_bool;
  }
};

class Type_Func : public Type
{
public:
  Type_Func(Type *t1, Type *t2) : from(t1), to(t2) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Func(" << *from << ", " << *to << ")";
  }
  virtual main_type get_type() override
  {
    return type_func;
  }
  virtual Type *getChild1() override
  {
    return from;
  }
  virtual Type *getChild2() override
  {
    return to;
  }
  virtual bool equals(Type *other) override
  {
    if (other == nullptr)
      return false;
    if (this->get_type() != other->get_type())
      return false;
    return from->equals(other->getChild1()) && to->equals(other->getChild2());
  };

private:
  Type *from, *to;
};

class Type_Ref : public Type
{
public:
  Type_Ref(Type *t) : t(t) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Ref(" << *t << ")";
  }
  virtual main_type get_type() override
  {
    return type_ref;
  }
  virtual Type *getChild1() override
  {
    return t;
  }
  virtual bool equals(Type *other) override
  {
    if (other == nullptr)
      return false;
    if (this->get_type() != other->get_type())
      return false;
    return t->equals(other->getChild1());
  };

private:
  Type *t;
};

class Type_Array : public Type
{
public:
  Type_Array(int i, Type *t1) : dim(i), t(t1) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_Array(" << dim << ", " << *t << ")";
  }
  virtual main_type get_type() override
  {
    return type_array;
  }
  virtual Type *getChild1() override
  {
    return t;
  }
  virtual int getDimension() override { return dim; }
  virtual bool equals(Type *other) override
  {
    if (other == nullptr)
      return false;
    if (this->get_type() != other->get_type())
      return false;
    return t->equals(other->getChild1()) && dim == other->getDimension();
  };

private:
  int dim;
  Type *t;
};

class Type_id : public Type
{
public:
  Type_id(std::string s) : var(s) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Type_id(" << var << ")";
  }
  virtual main_type get_type() override
  {
    return type_id;
  }

private:
  std::string var;
};

class Expr : public AST
{
public:
  virtual Type *getType(){};
  virtual void type_check(Type *t)
  {
    if (!t->equals(this->getType()))
      semanticError("Type mismatch");
  };
};

class Int_Expr : public Expr
{
public:
  Int_Expr(int n) : num(n) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Int_Expr(" << num << ")";
  }
  virtual Type *getType() override
  {
    return new Type_Int();
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
  virtual Type *getType() override
  {
    return new Type_Float();
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
  virtual Type *getType() override
  {
    return new Type_Char();
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
  virtual Type *getType() override
  {
    return new Type_Bool();
  }

private:
  bool var;
};

class Unit_Expr : public Expr
{
public:
  Unit_Expr() {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Unit_Expr()";
  }
  virtual Type *getType() override
  {
    return new Type_Unit();
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
  virtual void sem() override
  {
    if (st.lookup(var) == nullptr)
      semanticError("Unknown variable");
    switch(st.lookup(var)->type->get_type())
    {
      case type_func:
        semanticError("Function called with no arguments");
        break;
      default:
        break;
    }
  }
  virtual Type *getType() override
  {
    return st.lookup(var)->type;
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
  virtual void sem() override
  {
    if (st.lookup(fun_name) == nullptr)
      semanticError("Call to Undefined function");
    Type *tmp = st.lookup(fun_name)->type;
    if (tmp == nullptr)
      semanticError("Unknown variable");
    for (Expr *e : *expr_vec)
    {
      if (tmp->get_type() != type_func)
      {
        semanticError("Parameter number mismatch");
      }
      else
      {
        e->type_check(tmp->getChild1());
        tmp = tmp->getChild2();
      }
    }
    if (tmp->get_type() == type_func)
    {
      semanticError("Parameter number mismatch");
    }
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
  BinOp(Expr *e1, binop_enum op1, Expr *e2) : left(e1), op(op1), right(e2) {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Binop(" << *left << ", " << op << ", " << *right << ")";
  }
  virtual void sem() override
  {
    left->sem();
    right->sem();
    switch (op)
    {
    case binop_plus:
    case binop_minus:
    case binop_mult:
    case binop_div:
    case binop_mod:
      left->type_check(new Type_Int);
      right->type_check(new Type_Int);
      break;
    case binop_float_plus:
    case binop_float_minus:
    case binop_float_mult:
    case binop_float_div:
    case binop_pow:
      left->type_check(new Type_Float);
      right->type_check(new Type_Float);
      break;
    case binop_single_eq:
    case binop_struct_diff:
    case binop_double_eq:
    case binop_diff:
      left->type_check(right->getType());
      switch (left->getType()->get_type())
      {
      case type_array:
      case type_func:
        semanticError("Type not allowed");
        break;
      }
    case binop_l:
    case binop_g:
    case binop_leq:
    case binop_geq:
      left->type_check(right->getType());
      switch (left->getType()->get_type())
      {
      case type_int:
      case type_float:
      case type_char:
        break;
      default:
        semanticError("Type not allowed");
        break;
      }
    case binop_and:
    case binop_or:
      left->type_check(new Type_Bool);
      right->type_check(new Type_Bool);
      break;
    case binop_assign:
      left->type_check(new Type_Ref(right->getType()));
      break;
    }
  }
  virtual Type *getType() override
  {
    switch (op)
    {
    case binop_plus:
    case binop_minus:
    case binop_mult:
    case binop_div:
    case binop_mod:
      return new Type_Int();
    case binop_float_plus:
    case binop_float_minus:
    case binop_float_mult:
    case binop_float_div:
    case binop_pow:
      return new Type_Float();
    case binop_single_eq:
    case binop_struct_diff:
    case binop_l:
    case binop_g:
    case binop_leq:
    case binop_geq:
    case binop_double_eq:
    case binop_diff:
    case binop_and:
    case binop_or:
      return new Type_Bool();
    case binop_assign:
      return new Type_Unit();
    case binop_semicolon:
      return right->getType();
    }
  };

private:
  binop_enum op;
  Expr *left, *right;
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

  virtual void sem() override
  {
    if (typ == nullptr)
      semanticError("No type specified for parameter " + id);
    if (st.lookup(id) != nullptr)
      semanticError("Function parameter redeclared");
    st.insert(id, typ);
  }
  virtual Type *getType()
  {
    return typ;
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
    if (par_vec->empty()) //variable
    {
      expr->sem();
      if (typ != nullptr)
        expr->type_check(typ);
      if (st.lookup(id) == nullptr)
        st.insert(id, expr->getType());
      else
        semanticError("Variable redeclared");
    }
    else
    {
      for (Par *par : *par_vec)
      {
        par->sem();
      }
      Type *tmp = typ;

      for (auto i = par_vec->rbegin();
           i != par_vec->rend(); ++i)
      {
        tmp = new Type_Func((*i)->getType(), tmp);
      }
      if (st.lookup(id) == nullptr)
        st.insert(id, tmp);
      else
        semanticError("Variable redeclared");
      expr->sem();
      if (typ != nullptr)
        expr->type_check(typ);
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
