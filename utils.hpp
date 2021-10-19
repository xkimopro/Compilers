#pragma once

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

template <typename T>
inline std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  bool first = true;
  for (T t : v) {
    if (!first) out << ", ";
    first = false;
    out << *t;
  }
  return out;
}

inline void semanticError(std::string msg) {
  std::cerr << msg << std::endl;
  exit(1);
}