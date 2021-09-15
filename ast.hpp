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

class Expr: public AST {

};

class Int_Expr: public Expr {
public:
  Int_Expr(int n): num(n) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Int_Expr(" << num << ")";
  }
private:
  int num;
};

class Float_Expr: public Expr {
public:
  Float_Expr(float n): num(n) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Float_Expr(" << num << ")";
  }
private:
  float num;
};

class Char_Expr: public Expr {
public:
  Char_Expr(char c): chr(c) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Char_Expr(" << chr << ")";
  }
private:
  char chr;
};

class Str_Expr: public Expr {
public:
  Str_Expr(std::string s): str(s) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Str_Expr(" << str << ")";
  }
private:
  std::string str;
};

class Bool_Expr: public Expr {
public:
  Bool_Expr(bool b): var(b) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Bool_Expr(" << var << ")";
  }
private:
  bool var;
};

class Unit: public Expr {
public:
  Unit() {}
  virtual void printOn(std::ostream &out) const override {
    out << "Unit()";
  }
};

class Array: public Expr {
public:
  Array(std::string s, std::vector<Expr *> *v): var(s), expr_vec(v) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Array(" << var << ", [" << *expr_vec << "])";
  }
private:
  std::string var;
  std::vector<Expr *> *expr_vec;
};

class Dim: public Expr {
public:
  Dim(std::string s, int i = 1): var(s), ind(i) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Dim(" << ind << ", "<< var << ")";
  }
private:
  std::string var;
  int ind;
};

class id: public Expr {
public:
  id(std::string s): var(s) {}
  virtual void printOn(std::ostream &out) const override {
    out << "id(" << var << ")";
  }
private:
  std::string var;
};

class Id: public Expr {
public:
  Id(std::string s): var(s) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Id(" << var << ")";
  }
private:
  std::string var;
};

class Exclamation: public Expr {
public:
  Exclamation(Expr *e): expr(e) {}
  virtual void printOn(std::ostream &out) const override {
    out << "!(" << *expr << ")";
  }
private:
  Expr *expr;
};

class While: public Expr {
public:
  While(Expr *e1, Expr *e2): cond(e1), stmt(e2) {}
  virtual void printOn(std::ostream &out) const override {
    out << "While(" << *cond << ", " << *stmt << ")";
  }
private:
  Expr *cond, *stmt;
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
  Constr() {}
  virtual void printOn(std::ostream &out) const override
  {
    out << "Constr("
        << ")";
  }
};

class Par : public AST
{
public:
  Par() {}

  virtual void printOn(std::ostream &out) const override
  {
    out << "Par("
        << ")";
  }
};

class TDef : public AST
{
public:
  TDef(std::vector<Constr *> *v) : constr_vec(v) {}

  virtual void printOn(std::ostream &out) const override
  {
    out << "TDef(" << *constr_vec << ")";
  }

private:
  std::vector<Constr *> *constr_vec;
};

class TypeDef : public Stmt
{
public:
  TypeDef(std::vector<TDef *> *v) : tdef_vec(v) {}

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
  MutableDef() {}

  virtual void printOn(std::ostream &out) const override
  {
    out << "MutableDef("
        << ")";
  }
};

class NormalDef : public Def
{
public:
  NormalDef(std::vector<Par *> *v, Expr *e) : par_vec(v), expr(e) {}

  virtual void printOn(std::ostream &out) const override
  {
    out << "Def(" << *par_vec << *expr << ")";
  }

private:
  std::vector<Par *> *par_vec;
  Expr *expr;
};

class LetDef : public Stmt
{
public:
  LetDef(std::vector<Def *> *v) : def_vec(v) {}

  virtual void printOn(std::ostream &out) const override
  {
    out << "Letdef(" << *def_vec << ")";
  }

private:
  std::vector<Def *> *def_vec;
};