#pragma once

#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

#include "symbol.hpp"

// inline std::ostream& operator<<(std::ostream &out, Type t) {
//   switch (t) {
//   case TYPE_int: out << "int"; break;
//   case TYPE_bool: out << "bool"; break;
//   }
//   return out;
// }

class AST {
public:
  virtual ~AST() {}
  virtual void printOn(std::ostream &out) const = 0;
  virtual void sem() {}
};

inline std::ostream& operator<<(std::ostream &out, const AST &t) {
  t.printOn(out);
  return out;
}


class Stmt: public AST {
    

};

// class Expr: public AST {
// public:
//   virtual int eval() const = 0;
//   void type_check(Type t) {
//     sem();
//     if (type != t) {
//       std::cerr << "Type mismatch" << std::endl;
//       exit(1);
//     }
//   }
// protected:
//   Type type;
// };



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

// class Block: public Stmt {
// public:
//   Block(): decl_list(), stmt_list(), size(0) {}
//   ~Block() {
//     for (Decl *d : decl_list) delete d;
//     for (Stmt *s : stmt_list) delete s;
//   }
//   void append_decl(Decl *d) { decl_list.push_back(d); }
//   void append_stmt(Stmt *s) { stmt_list.push_back(s); }
//   void merge(Block *b) {
//     stmt_list = b->stmt_list;
//     b->stmt_list.clear();
//     delete b;
//   }
//   virtual void printOn(std::ostream &out) const override {
//     out << "Block(";
//     bool first = true;
//     for (Decl *d : decl_list) {
//       if (!first) out << ", ";
//       first = false;
//       out << *d;
//     }
//     for (Stmt *s : stmt_list) {
//       if (!first) out << ", ";
//       first = false;
//       out << *s;
//     }
//     out << ")";
//   }
//   virtual void sem() override {
//     st.openScope();
//     for (Decl *d : decl_list) d->sem();
//     for (Stmt *s : stmt_list) s->sem();
//     size = st.getSizeOfCurrentScope();
//     st.closeScope();
//   }
//   virtual void run() const override {
//     for (int i = 0; i < size; ++i) rt_stack.push_back(0);
//     for (Stmt *s : stmt_list) s->run();
//     for (int i = 0; i < size; ++i) rt_stack.pop_back();
//   }
// private:
//   std::vector<Decl *> decl_list;
//   std::vector<Stmt *> stmt_list;
//   int size;
// };

class Constr: public AST {
  public:
        Constr() {}
    virtual void printOn(std::ostream &out) const override {
            out << "Constr(";
            // bool first = true;
            // for (Stmt *s : stmt_vec) {
            // if (!first) out << ", ";
            // first = false;
            // out << *s;
            // }
            out << ")";
    }
};

class Par: public AST {
    public:
        Par() {}

    virtual void printOn(std::ostream &out) const override {
            out << "Par(";
            // bool first = true;
            // for (Stmt *s : stmt_vec) {
            // if (!first) out << ", ";
            // first = false;
            // out << *s;
            // }
            out << ")";
    }
};


class ParList: public AST {
public:
  
  ParList(): par_vec() {}
  
  ~ParList() {
    for (Par *p : par_vec) delete p;
  }
  
  void append_par(Par *p) { par_vec.push_back(p); }

  virtual void printOn(std::ostream &out) const override {
    bool first = true;
    for (Par *p : par_vec) {
      if (!first) out << ", ";
      first = false;
      out << *p;
    }
  }

  virtual void sem() override {
    
  }
  
  std::vector<Par *> par_vec;
};

class TDef: public AST {
    public:
        TDef() {}

        void append_constr(Constr* c) { constr_vec.push_back(c); }
        void append_front_constr(Constr* c) { constr_vec.insert(constr_vec.begin(),c); }
        virtual void printOn(std::ostream &out) const override {
            out << "TDef(";
            bool first = true;
            for (Constr *c : constr_vec) {
              if (!first) out << ", ";
              first = false;
              out << *c;
            }
            out << ")";
        }
    private:
      std::vector<Constr *> constr_vec;  
};

class Def: public AST {
    public:
        Def() {}

    virtual void printOn(std::ostream &out) const override {
            out << "Def(";
            // bool first = true;
            // for (Stmt *s : stmt_vec) {
            // if (!first) out << ", ";
            // first = false;
            // out << *s;
            // }
            out << ")";
    }      
};

class MutableDef: public Def {
    public:
        MutableDef() {}

    virtual void printOn(std::ostream &out) const override {
            out << "MutableDef(";
            // bool first = true;
            // for (Stmt *s : stmt_vec) {
            // if (!first) out << ", ";
            // first = false;
            // out << *s;
            // }
            out << ")";
    }
};

class NormalDef: public Def {
    public:
        NormalDef() {}

        void set_my_params(ParList *p){
          my_params = p;
        }

    virtual void printOn(std::ostream &out) const override {
            out << "NormalDef(";
            out << *my_params;
            out << ")";
    }


    private:
        ParList* my_params;
};

class TypeDef: public Stmt {
    public:
        TypeDef():  typedef_vec() {}

        void append_tdef(TDef *td){
            typedef_vec.push_back(td);
        }
        void append_front_tdef(TDef *td){
            typedef_vec.insert(typedef_vec.begin(), td);
        }

        virtual void printOn(std::ostream &out) const override {
            out << "Typedef(";
            bool first = true;
            for (TDef *td : typedef_vec) {
             if (!first) out << ", ";
             first = false;
             out << *td;
            }
            out << ")";
        }

    private:
        std::vector<TDef *> typedef_vec;
};

class LetDef: public Stmt {
    public:
        LetDef():  letdef_vec() {}

        virtual void printOn(std::ostream &out) const override {
            out << "Letdef(";
            bool first = true;
            for (Def *d : letdef_vec) {
            if (!first) out << ", ";
            first = false;
            out << *d;
            }
            out << ")";
        }

        void append_def(Def *d){
            letdef_vec.push_back(d);
        }
        void append_front_def(Def *d){
            letdef_vec.insert(letdef_vec.begin(), d);
        }

    private:
        std::vector<Def *> letdef_vec;

};

class Stmt_list: public AST {
public:
  
  Stmt_list(): stmt_vec() {}
  
  ~Stmt_list() {
    for (Stmt *s : stmt_vec) delete s;
  }
  
  void append_stmt(Stmt *s) { stmt_vec.push_back(s); }

  virtual void printOn(std::ostream &out) const override {
    out << "Stmt_list(";
    bool first = true;
    for (Stmt *s : stmt_vec) {
      if (!first) out << ", ";
      first = false;
      out << *s;
    }
    out << ")";
  }

  virtual void sem() override {
    
  }
private:
  std::vector<Stmt *> stmt_vec;
};