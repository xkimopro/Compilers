inline void semanticError(std::string msg) {
  std::cerr << msg << std::endl;
  exit(1);
}

std::string str_print_int = "print_int";
std::string str_print_float = "print_float";
std::string str_print_string = "print_string";
std::string str_read_int = "read_int";
std::string str_incr = "incr";
std::string str_float_of_int = "float_of_int";
std::string str_strlen = "strlen";

// class Program

void Program::sem()
{
  st.openScope();
  st.insert(str_print_int, new Type_Func(new Type_Int(), new Type_Unit()));
  st.insert(str_print_float, new Type_Func(new Type_Float(), new Type_Unit()));
  st.insert(str_print_string, new Type_Func(new Type_Array(1, new Type_Char()), new Type_Unit()));
  st.insert(str_read_int, new Type_Func(new Type_Unit(), new Type_Int()));
  st.insert(str_incr, new Type_Func(new Type_Ref(new Type_Int), new Type_Unit()));
  st.insert(str_float_of_int, new Type_Func(new Type_Int(), new Type_Float()));
  st.insert(str_strlen, new Type_Func(new Type_Array(1, new Type_Char()), new Type_Int()));
  for (Stmt *stmt : *statements)
  {
    stmt->sem();
  }
}

// class Type_Unit

main_type Type_Unit::get_type() { return type_unit; }

// class Type_Int

main_type Type_Int::get_type() { return type_int; }

// class Type_Float

main_type Type_Float::get_type() { return type_float; }

// class Type_Char

main_type Type_Char::get_type() { return type_char; }

// class Type_Bool

main_type Type_Bool::get_type() { return type_bool; }

// class Type_Func

main_type Type_Func::get_type() { return type_func; }

::Type *Type_Func::getChild1() { return from; }

::Type *Type_Func::getChild2() { return to; }

bool Type_Func::equals(::Type *other)
{
  if (other == nullptr)
    return false;
  if (other->get_type() == type_undefined)
    return other->equals(this);
  if (this->get_type() != other->get_type())
    return false;
  return from->equals(other->getChild1()) && to->equals(other->getChild2());
}

void Type_Func::sem()
{
  from->sem();
  to->sem();
}

// class Type_Ref

main_type Type_Ref::get_type() { return type_ref; }

::Type *Type_Ref::getChild1() { return t; }

bool Type_Ref::equals(::Type *other)
{
  if (other == nullptr)
    return false;
  if (other->get_type() == type_undefined)
    return other->equals(this);
  if (this->get_type() != other->get_type())
    return false;
  return t->equals(other->getChild1());
}

void Type_Ref::sem() { t->sem(); }

// class Type_Array

main_type Type_Array::get_type() { return type_array; }

::Type *Type_Array::getChild1() { return t; }

long unsigned int Type_Array::getDimensions() { return dim; }

bool Type_Array::equals(::Type *other)
{
  if (other == nullptr)
    return false;
  if (other->get_type() == type_undefined)
    return other->equals(this);
  if (this->get_type() != other->get_type())
    return false;
  return t->equals(other->getChild1()) && dim == other->getDimensions();
}
void Type_Array::sem() { t->sem(); }

// class Type_id

main_type Type_id::get_type() { return type_id; }

std::string Type_id::get_id() { return id; }

bool Type_id::equals(::Type *other)
{
  if (other == nullptr)
    return false;
  if (other->get_type() == type_undefined)
    return other->equals(this);
  if (this->get_type() != other->get_type())
    return false;
  return id == other->get_id();
}

void Type_id::sem() { tt.lookup(id); }

// class Type_Undefined

main_type Type_Undefined::get_type()
{
  return t == nullptr ? type_undefined : t->get_type();
}

::Type *Type_Undefined::getChild1()
{
  return t == nullptr ? this : t->getChild1();
}

::Type *Type_Undefined::getChild2()
{
  return t == nullptr ? nullptr : t->getChild2();
}

long unsigned int Type_Undefined::getDimensions()
{
  return t == nullptr ? 0 : t->getDimensions();
}

std::string Type_Undefined::get_id()
{
  return t == nullptr ? "" : t->get_id();
}

bool Type_Undefined::equals(::Type *other)
{
  //std::cerr << *this << " " << *other << std::endl;
  if (other->get_type() == type_undefined)
    other = other->getChild1();
  if (this == other) return 1;
  if (t == nullptr)
  {
    t = other;
    //std::cerr << *this << std::endl;
    return 1;
  }
  else
    return t->equals(other);
}

// class Expr

void Expr::type_check(::Type *t)
{
  if (!t->equals(this->t))
  {
    std::cerr << *this;
    semanticError("Type mismatch");
  }
};

// class Int_Expr

void Int_Expr::sem() { t = new Type_Int(); }

// class Float_Expr

void Float_Expr::sem() { t = new Type_Float(); }

// class Char_Expr

void Char_Expr::sem() { t = new Type_Char(); }

// class Str_Expr

void Str_Expr::sem()
{
  t = new Type_Array(1, new Type_Char());
}

// class Bool_Expr

void Bool_Expr::sem() { t = new Type_Bool(); }

// class Unit_Expr

void Unit_Expr::sem() { t = new Type_Unit(); }

// class Array

void Array::sem()
{
  SymbolEntry *se = st.lookup(id);
  t = se->type;
  if (!t->equals(new Type_Array(expr_vec->size(), new Type_Undefined())))
    semanticError("Array: Type mismatch");
  for (Expr *e : *expr_vec)
  {
    e->sem();
    e->type_check(new Type_Int());
  }
  t = new Type_Ref(t->getChild1());
}

// class Dim

void Dim::sem()
{
  SymbolEntry *se = st.lookup(id);
  if (se->type->get_type() != type_undefined)
  {
    if (se->type->get_type() != type_array)
      semanticError("Dim: Type mismatch");
    else if (ind < 1 || ind > se->type->getDimensions())
      semanticError("Array dimensions mismatch");
  }
  t = new Type_Int();
}

// class id

void id::sem() { t = st.lookup(var)->type; }

// class Id

void Id::sem() { t = st.lookup(id)->type; }

// class While

void While::sem()
{
  cond->sem();
  cond->type_check(new Type_Bool());
  stmt->sem();
  t = new Type_Unit();
}

// class For

void For::sem()
{
  start->sem();
  start->type_check(new Type_Int());
  end->sem();
  end->type_check(new Type_Int());
  st.openScope();
  st.insert(id, new Type_Int());
  do_stmt->sem();
  st.closeScope();
  t = new Type_Unit();
}

// class call

void call::sem()
{
  ::Type *tmp = st.lookup(id)->type;
  for (Expr *e : *expr_vec)
  {
    e->sem();
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
  t = tmp;
}

// class UnOp

void UnOp::sem()
{
  e->sem();
  switch (op)
  {
  case unop_plus:
  case unop_minus:
    e->type_check(new Type_Int());
    t = new Type_Int();
    break;
  case unop_float_plus:
  case unop_float_minus:
    e->type_check(new Type_Float());
    t = new Type_Float();
    break;
  case unop_exclamation:
    if (e->t->get_type() == type_undefined)
      e->type_check(new Type_Ref(new Type_Undefined()));
    else if (e->t->get_type() != type_ref)
      semanticError("exclamation: Type mismatch");
    t = e->t->getChild1();
    break;
  case unop_not:
    e->type_check(new Type_Bool());
    t = new Type_Bool();
    break;
  case unop_delete:
    if (e->t->get_type() == type_undefined)
      e->type_check(new Type_Ref(new Type_Undefined()));
    else if (e->t->get_type() != type_ref)
      semanticError("delete: Type mismatch");
    t = new Type_Unit();
    break;
  default:
    semanticError("Unary operator not allowed for expression");
    break;
  }
}

//  class BinOp

void BinOp::sem()
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
    t = new Type_Int();
    break;
  case binop_float_plus:
  case binop_float_minus:
  case binop_float_mult:
  case binop_float_div:
  case binop_pow:
    left->type_check(new Type_Float);
    right->type_check(new Type_Float);
    t = new Type_Float();
    break;
  case binop_single_eq:
  case binop_struct_diff:
  case binop_double_eq:
  case binop_diff:
    left->type_check(right->t);
    switch (left->t->get_type())
    {
    case type_array:
    case type_func:
      semanticError("Type not allowed");
      break;
    default:
      break;
    }
    t = new Type_Bool();
    break;
  case binop_l:
  case binop_g:
  case binop_leq:
  case binop_geq:
    left->type_check(right->t);
    switch (left->t->get_type())
    {
    case type_int:
    case type_float:
    case type_char:
    case type_undefined:
      break;
    default:
      semanticError("Type not allowed");
      break;
    }
    t = new Type_Bool();
    break;
  case binop_and:
  case binop_or:
    left->type_check(new Type_Bool);
    right->type_check(new Type_Bool);
    t = new Type_Bool();
    break;
  case binop_assign:
    left->type_check(new Type_Ref(right->t));
    t = new Type_Unit();
    break;
  case binop_semicolon:
    t = right->t;
    break;
  }
}

// class If

void If::sem()
{
  expr1->sem();
  expr1->type_check(new Type_Bool());
  expr2->sem();
  if (expr3 != nullptr)
  {
    expr3->sem();
    expr2->type_check(expr3->t);
  }
  t = expr2->t;
}

//   class New

void New::sem()
{
  if (typ->get_type() == type_array)
    semanticError("Reference cannot be of Type array");
  typ->sem();
  t = new Type_Ref(typ);
}

//   class Pattern_Int_Expr

void Pattern_Int_Expr::sem()
{
  t = new Type_Int();
}

//   class Pattern_Float_Expr

void Pattern_Float_Expr::sem()
{
  t = new Type_Float();
}

//   class Pattern_Char_Expr

void Pattern_Char_Expr::sem()
{
  t = new Type_Char();
}

// class Pattern_Bool_Expr

void Pattern_Bool_Expr::sem()
{
  t = new Type_Bool();
}

// class Pattern_id

void Pattern_id::sem()
{
  t = new Type_Undefined();
  st.insert(id, t);
}

// class Pattern_Id

void Pattern_Id::sem()
{
  t = st.lookup(id)->type;
}

// class Pattern_Call

void Pattern_Call::sem()
{
  ::Type *tmp = st.lookup(id)->type;
  for (Pattern *p : *pattern_vec)
  {
    p->sem();
    if (tmp->get_type() != type_func)
    {
      semanticError("Parameter number mismatch");
    }
    else
    {
      if (!p->t->equals(tmp->getChild1()))
        semanticError("Type mismatch");
      tmp = tmp->getChild2();
    }
  }
  if (tmp->get_type() == type_func)
  {
    semanticError("Parameter number mismatch");
  }
  t = tmp;
}

// class Clause

//   class Match

void Match::sem()
{
  e->sem();
  ::Type *typ = new Type_Undefined();
  st.openScope();
  for (Clause *cl : *vec)
  {
    cl->p->sem();
    e->type_check(cl->p->t);
    cl->e->sem();
    cl->e->type_check(typ);
  }
  st.closeScope();
  t = ((*vec)[0])->e->t;
}

// class Constr

void Constr::sem(std::string id)
{
  ::Type *tmp = new Type_id(id);
  for (auto i = type_vec->rbegin(); i != type_vec->rend(); i++)
    tmp = new Type_Func(*i, tmp);
  st.insert(Id, tmp);
}

// class Par

void Par::sem()
{
  t->sem();
  st.insert(id, t);
}

// class TDef

void TDef::sem() { tt.insert(id); }

void TDef::sem2()
{
  for (Constr *c : *constr_vec)
  {
    c->sem(id);
  }
}

// class TypeDef

void TypeDef::sem()
{
  if (tdef_vec == nullptr)
    return;
  for (TDef *tdef : *tdef_vec)
  {
    tdef->sem();
  }
  for (TDef *tdef : *tdef_vec)
  {
    tdef->sem2();
  }
}

// class MutableDef

void MutableDef::sem()
{
  typ->sem();
  if (expr_vec == nullptr)
    st.insert(id, new Type_Ref(typ));
  else
  {
    for (Expr *e : *expr_vec)
    {
      e->sem();
      e->type_check(new Type_Int());
    }
    st.insert(id, new Type_Array(expr_vec->size(), typ));
  }
}

// class NormalDef

void NormalDef::sem()
{
  typ->sem();
  ::Type *tmp = typ;
  for (auto i = par_vec->rbegin(); i != par_vec->rend(); i++)
  {
    tmp = new Type_Func((*i)->t, tmp);
  }
  st.insert(id, tmp);
}

void NormalDef::sem2()
{
  st.openScope();
  for (Par *par : *par_vec)
  {
    par->sem();
  }
  expr->sem();
  expr->type_check(typ);
  st.closeScope();
}

// class LetDef

void LetDef::sem()
{
  if (rec)
  {
    for (Def *def : *def_vec)
    {
      def->sem();
    }
    for (Def *def : *def_vec)
    {
      def->sem2();
    }
  }
  else
  {
    for (Def *def : *def_vec)
    {
      def->sem2();
    }
    for (Def *def : *def_vec)
    {
      def->sem();
    }
  }
}

// class LetIn

void LetIn::sem()
{
  st.openScope();
  def->sem();
  expr->sem();
  t = expr->t;
  st.closeScope();
}