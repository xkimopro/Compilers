#include "ast.hpp"

void Program::printOn(std::ostream &out) const {
  std::cout << "AST( " << *statements << ")";
}
void Program::sem() {
  for (Stmt *stmt  : *statements) {
       stmt->sem();
     }
}

// Types Classes

// Class Type_Unit

void Type_Unit::printOn(std::ostream &out) const { out << "Type_Unit()"; }

main_type Type_Unit::get_type() { return type_unit; }

// Class Type_Int

void Type_Int::printOn(std::ostream &out) const { out << "Type_Int()"; }

main_type Type_Int::get_type() { return type_int; }

// Class Type_Float

void Type_Float::printOn(std::ostream &out) const { out << "Type_Float()"; }

main_type Type_Float::get_type() { return type_float; }

// Class Type_Char

void Type_Char::printOn(std::ostream &out) const { out << "Type_Char()"; }

main_type Type_Char::get_type() { return type_char; }

// Class Type_Bool

void Type_Bool::printOn(std::ostream &out) const { out << "Type_Bool()"; }

main_type Type_Bool::get_type() { return type_bool; }

// Class Type_Func

void Type_Func::printOn(std::ostream &out) const {
  out << "Type_Func(" << *from << ", " << *to << ")";
}

main_type Type_Func::get_type() { return type_func; }

::Type *Type_Func::getChild1() { return from; }

::Type *Type_Func::getChild2() { return to; }

bool Type_Func::equals(::Type *other) {
  if (other == nullptr) return false;
  if (this->get_type() != other->get_type()) return false;
  return from->equals(other->getChild1()) && to->equals(other->getChild2());
}

void Type_Func::sem() {
  from->sem();
  to->sem();
}

// Class Type_Ref

void Type_Ref::printOn(std::ostream &out) const {
  out << "Type_Ref(" << *t << ")";
}

main_type Type_Ref::get_type() { return type_ref; }

::Type *Type_Ref::getChild1() { return t; }

bool Type_Ref::equals(::Type *other) {
  if (other == nullptr) return false;
  if (this->get_type() != other->get_type()) return false;
  return t->equals(other->getChild1());
}

void Type_Ref::sem() { t->sem(); }

// Class Type_Array

void Type_Array::printOn(std::ostream &out) const {
  out << "Type_Array(" << dim << ", " << *t << ")";
}

main_type Type_Array::get_type() { return type_array; }

::Type *Type_Array::getChild1() { return t; }

long unsigned int Type_Array::getDimensions() { return dim; }

bool Type_Array::equals(::Type *other) {
  if (other == nullptr) return false;
  if (this->get_type() != other->get_type()) return false;
  return t->equals(other->getChild1()) && dim == other->getDimensions();
}
void Type_Array::sem() { t->sem(); }

// Class Type_id

void Type_id::printOn(std::ostream &out) const {
  out << "Type_id(" << id << ")";
}

main_type Type_id::get_type() { return type_id; }

std::string Type_id::get_id() { return id; }

bool Type_id::equals(::Type *other) {
  if (other == nullptr) return false;
  if (this->get_type() != other->get_type()) return false;
  return id == other->get_id();
}

void Type_id::sem() { tt.lookup(id); }

// class Int_Expr

void Int_Expr::printOn(std::ostream &out) const {
  out << "Int_Expr(" << num << ")";
}

::Type *Int_Expr::getType() { return new Type_Int(); }

// class Float_Expr

void Float_Expr::printOn(std::ostream &out) const {
  out << "Float_Expr(" << num << ")";
}

::Type *Float_Expr::getType() { return new Type_Float(); }

// class Char_Expr

void Char_Expr::printOn(std::ostream &out) const {
  out << "Char_Expr(" << chr << ")";
}

::Type *Char_Expr::getType() { return new Type_Char(); }

// class Str_Expr

void Str_Expr::printOn(std::ostream &out) const {
  out << "Str_Expr(" << str << ")";
}

::Type *Str_Expr::getType() {
  return new Type_Array(str.length() + 1, new Type_Char());
}

// class Bool_Expr

void Bool_Expr::printOn(std::ostream &out) const {
  out << "Bool_Expr(" << var << ")";
}

::Type *Bool_Expr::getType() { return new Type_Bool(); }

// class Unit_Expr

void Unit_Expr::printOn(std::ostream &out) const { out << "Unit_Expr()"; }

::Type *Unit_Expr::getType() { return new Type_Unit(); }

// class Array

void Array::printOn(std::ostream &out) const {
  out << "Array(" << var << ", [" << *expr_vec << "])";
}

void Array::sem() {
  SymbolEntry *se = st.lookup(var);
  t = se->type;
  if (t->get_type() != type_array)
    semanticError("Array: ::Type mismatch");
  else if (t->getDimensions() != expr_vec->size())
    semanticError("Array dimensions mismatch");
  else
    for (Expr *e : *expr_vec) {
      e->sem();
      e->type_check(new Type_Int());
    }
}

::Type *Array::getType() { return new Type_Ref(t->getChild1()); }

// class Dim

void Dim::printOn(std::ostream &out) const {
  out << "Dim(" << ind << ", " << var << ")";
}

void Dim::sem() {
  SymbolEntry *se = st.lookup(var);
  if (se->type->get_type() != type_array)
    semanticError("Dim: Type mismatch");
  else if (ind < 1 || ind > se->type->getDimensions())
    semanticError("Array dimensions mismatch");
}

::Type *Dim::getType() { return new Type_Int(); }

// class id

void id::printOn(std::ostream &out) const { out << "id(" << var << ")"; }

void id::sem() { st.lookup(var); }

::Type *id::getType() { return st.lookup(var)->type; }

// class Id

void Id::printOn(std::ostream &out) const { out << "Id(" << var << ")"; }

void Id::sem() { st.lookup(var); }

::Type *Id::getType() { return st.lookup(var)->type; }

// class While

void While::printOn(std::ostream &out) const {
  out << "While(" << *cond << ", " << *stmt << ")";
}

void While::sem() {
  cond->sem();
  cond->type_check(new Type_Bool());
  stmt->sem();
}

::Type *While::getType() { return new Type_Unit(); }

// class For

void For::printOn(std::ostream &out) const {
  std::string for_str = down ? " down to " : " to ";
  out << "For(" << id << " from " << *start << for_str << *end << ") do ("
      << *do_stmt << ")";
}

void For::sem() {
  start->sem();
  start->type_check(new Type_Int());
  end->sem();
  end->type_check(new Type_Int());
  st.openScope();
  st.insert(id, new Type_Int());
  do_stmt->sem();
  st.closeScope();
}

::Type *For::getType() { return new Type_Unit(); }

// class call

void call::printOn(std::ostream &out) const {
  out << "call(" << fun_name << ", (" << *expr_vec << "))";
}

void call::sem() {
  ::Type *tmp = st.lookup(fun_name)->type;
  for (Expr *e : *expr_vec) {
    e->sem();
    if (tmp->get_type() != type_func) {
      semanticError("Parameter number mismatch");
    } else {
      e->type_check(tmp->getChild1());
      tmp = tmp->getChild2();
    }
  }
  if (tmp->get_type() == type_func) {
    semanticError("Parameter number mismatch");
  }
}

::Type *call::getType() {
  ::Type *tmp = st.lookup(fun_name)->type;
  while (tmp->get_type() == type_func) {
    tmp = tmp->getChild2();
  }
  return tmp;
}

// class UnOp

void UnOp::printOn(std::ostream &out) const {
  out << "Unop(" << op << ", " << *e << ")";
}

void UnOp::sem() {
  e->sem();
  switch (op) {
    case unop_plus:
    case unop_minus:
      e->type_check(new Type_Int());
      break;
    case unop_float_plus:
    case unop_float_minus:
      e->type_check(new Type_Float());
      break;
    case unop_exclamation:
      if (e->getType()->get_type() != type_ref)
        semanticError("exclamation: ::Type mismatch");
      break;
    case unop_not:
      e->type_check(new Type_Bool());
      break;
    case unop_delete:
      if (e->getType()->get_type() != type_ref)
        semanticError("delete: ::Type mismatch");
      break;
    default:
      semanticError("Unary operator not allowed for expression");
      break;
  }
}

::Type *UnOp::getType() {
  switch (op) {
    case unop_plus:
    case unop_minus:
      return new Type_Int();
      break;
    case unop_float_plus:
    case unop_float_minus:
      return new Type_Float();
      break;
    case unop_exclamation:
      return e->getType()->getChild1();
      break;
    case unop_not:
      return new Type_Bool();
      break;
    case unop_delete:
      return new Type_Unit();
      break;
    default:
      semanticError("Unary operator not allowed. Cant read type.");
      break;
  }
  return nullptr;
}

//  class BinOp

void BinOp::printOn(std::ostream &out) const {
  out << "Binop(" << *left << ", " << op << ", " << *right << ")";
}

void BinOp::sem() {
  left->sem();
  right->sem();
  switch (op) {
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
      switch (left->getType()->get_type()) {
        case type_array:
        case type_func:
          semanticError("Type not allowed");
          break;
        default:
          break;
      }
      break;
    case binop_l:
    case binop_g:
    case binop_leq:
    case binop_geq:
      left->type_check(right->getType());
      switch (left->getType()->get_type()) {
        case type_int:
        case type_float:
        case type_char:
          break;
        default:
          semanticError("Type not allowed");
          break;
      }
      break;
    case binop_and:
    case binop_or:
      left->type_check(new Type_Bool);
      right->type_check(new Type_Bool);
      break;
    case binop_assign:
      left->type_check(new Type_Ref(right->getType()));
      break;
    case binop_semicolon:
      break;
  }
}

::Type *BinOp::getType() {
  switch (op) {
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
  return nullptr;

}

// class If

void If::printOn(std::ostream &out) const {
  std::string ifelse = (expr3 != nullptr ? "If_Else(" : "If(");
  out << ifelse << *expr1 << ", " << *expr2;
  if (expr3 != nullptr) out << ", " << *expr3;
  out << ")";
}

void If::sem() {
  expr1->sem();
  expr1->type_check(new Type_Bool());
  expr2->sem();
  if (expr3 != nullptr) {
    expr3->sem();
    expr2->type_check(expr3->getType());
  }
}

::Type *If::getType() { return expr2->getType(); }

//   class New

void New::printOn(std::ostream &out) const { out << "New(" << *typ << ")"; }

void New::sem() {
  if (typ->get_type() == type_array)
    semanticError("Reference cannot be of Type array");
  typ->sem();
}

::Type *New::getType() { return new Type_Ref(typ); }

//   class Pattern_Int_Expr
 
void Pattern_Int_Expr::printOn(std::ostream &out) const {
  out << "Pattern_Int_Expr(" << num << ")";
}

void Pattern_Int_Expr::sem(::Type *t) {
  if (t->get_type() != type_int) semanticError("Type mismatch");
}

//   class Pattern_Float_Expr

void Pattern_Float_Expr::printOn(std::ostream &out) const {
  out << "Pattern_Float_Expr(" << num << ")";
}

void Pattern_Float_Expr::sem(::Type *t) {
  if (t->get_type() != type_float) semanticError("Type mismatch");
}

//   class Pattern_Char_Expr

void Pattern_Char_Expr::printOn(std::ostream &out) const {
  out << "Pattern_Char_Expr(" << chr << ")";
}

void Pattern_Char_Expr::sem(::Type *t) {
  if (t->get_type() != type_char) semanticError("Type mismatch");
}

// class Pattern_Bool_Expr

void Pattern_Bool_Expr::printOn(std::ostream &out) const {
  out << "Pattern_Bool_Expr(" << var << ")";
}

void Pattern_Bool_Expr::sem(::Type *t) {
  if (t->get_type() != type_bool) semanticError("Type mismatch");
}

// class Pattern_id

void Pattern_id::printOn(std::ostream &out) const {
  out << "Pattern_id(" << var << ")";
}

void Pattern_id::sem(::Type *t) { st.insert(var, t); }

// class Pattern_Id

void Pattern_Id::printOn(std::ostream &out) const {
  out << "Pattern_Id(" << var << ")";
}

// class Pattern_Call

void Pattern_Call::printOn(std::ostream &out) const {
  out << "Pattern_Call(" << Id << ", (" << *pattern_vec << "))";
}

// class Clause

void Clause::printOn(std::ostream &out) const {
  out << "Clause(" << *p << ", " << *e << ")";
}

//   class Match

void Match::printOn(std::ostream &out) const {
  out << "Match(" << *e << ", " << *vec << ")";
}

void Match::sem() {
  e->sem();
  ::Type *t1 = e->getType();
  ((*vec)[0])->e->sem();
  ::Type *t2 = ((*vec)[0])->e->getType();
  st.openScope();
  for (Clause *cl : *vec) {
    cl->p->sem(t1);
    cl->e->sem();
    cl->e->type_check(t2);
  }
  st.closeScope();
}

// class Constr

void Constr::printOn(std::ostream &out) const {
  out << "Constr(" << Id;
  if (type_vec != nullptr) out << ", " << *type_vec;
  out << ")";
}

void Constr::sem(std::string id) {
  ::Type *tmp = new Type_id(id);
  for (auto i = type_vec->rbegin(); i != type_vec->rend(); i++)
    tmp = new Type_Func(*i, tmp);
  st.insert(Id, tmp);
}

// class Par

void Par::printOn(std::ostream &out) const {
  out << "Par(" << id;
  if (typ != nullptr) out << ", " << *typ;
  out << ")";
}

void Par::sem() {
  if (typ == nullptr) semanticError("No Type specified for parameter " + id);
  typ->sem();
  st.insert(id, typ);
}

::Type *Par::getType() { return typ; }

// class TDef

void TDef::printOn(std::ostream &out) const {
  out << "TDef(" << id << ", " << *constr_vec << ")";
}

void TDef::sem() { tt.insert(id); }

void TDef::sem2() {
  for (Constr *c : *constr_vec) {
    c->sem(id);
  }
}

// class TypeDef

void TypeDef::sem() {
  if (tdef_vec == nullptr) return;
  for (TDef *tdef : *tdef_vec) {
    tdef->sem();
  }
  for (TDef *tdef : *tdef_vec) {
    tdef->sem2();
  }
}

void TypeDef::printOn(std::ostream &out) const {
  out << "Typedef(" << *tdef_vec << ")";
}

// class MutableDef

void MutableDef::printOn(std::ostream &out) const {
  out << "MutableDef(" << id;
  if (expr_vec != nullptr) out << ", [" << *expr_vec << "]";
  if (typ != nullptr) out << ", " << *typ;
  out << ")";
}

void MutableDef::sem() {
  if (typ == nullptr) semanticError("Missing mutable type");
  typ->sem();
  if (expr_vec == nullptr)
    st.insert(id, new Type_Ref(typ));
  else {
    for (Expr *e : *expr_vec) {
      e->sem();
      e->type_check(new Type_Int()); 
    }
    st.insert(id, new Type_Array(expr_vec->size(), typ));
  }
}

// class NormalDef

void NormalDef::printOn(std::ostream &out) const {
  out << "Def(" << id << ", [" << *par_vec << "], ";
  if (typ != nullptr) out << *typ << ", ";
  out << *expr << ")";
}

void NormalDef::sem() {
  if (typ == nullptr) semanticError("Missing function type");
  typ->sem();
  ::Type *tmp = typ;
  for (auto i = par_vec->rbegin(); i != par_vec->rend(); i++) {
    tmp = new Type_Func((*i)->getType(), tmp);
  }
  st.insert(id, tmp);
}

void NormalDef::sem2() {
  st.openScope();
  for (Par *par : *par_vec) {
    par->sem();
  }
  expr->sem();
  if (typ != nullptr) expr->type_check(typ);
  st.closeScope();
}

// class LetDef

void LetDef::printOn(std::ostream &out) const {
  out << "Letdef(" << rec << ", " << *def_vec << ")";
}

void LetDef::sem() {
  st.openScope();
  if (rec) {
    for (Def *def : *def_vec) {
      def->sem();
    }
    for (Def *def : *def_vec) {
      def->sem2();
    }
  } else {
    for (Def *def : *def_vec) {
      def->sem2();
    }
    for (Def *def : *def_vec) {
      def->sem();
    }
  }
}

// class LetIn

void LetIn::printOn(std::ostream &out) const {
  out << "LetIn(" << *def << ", " << *expr << ")";
}

void LetIn::sem() {
  def->sem();
  expr->sem();
  t = expr->getType();
  st.closeScope();
}

::Type *LetIn::getType() { return t; }