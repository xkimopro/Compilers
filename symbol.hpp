#pragma once

#include <cstdlib>
#include <vector>
#include <map>
#include <unordered_set>

#include "ast.hpp"

void semanticError(std::string msg);

class Type;

class SymbolEntry
{
public:
  SymbolEntry(Type *t) : type(t) {}
  SymbolEntry() {}
  Type *type;
};

class Scope
{
public:
  Scope() : locals() {}
  SymbolEntry *lookup(std::string id)
  {
    if (locals.find(id) == locals.end())
      return nullptr;
    return &locals[id];
  }
  void insert(std::string id, Type *t)
  {
    if (locals.find(id) != locals.end())
      semanticError("Identifier " + id + " redeclared");
    locals[id] = SymbolEntry(t);
  }

private:
  std::map<std::string, SymbolEntry> locals;
};

class SymbolTable
{
public:
  void openScope()
  {
    scopes.push_back(Scope());
  }
  void closeScope()
  {
    scopes.pop_back();
  }
  SymbolEntry *lookup(std::string id)
  {
    for (auto i = scopes.rbegin(); i != scopes.rend(); ++i)
    {
      SymbolEntry *e = i->lookup(id);
      if (e != nullptr)
        return e;
    }
    semanticError("Variable " + id + " not found");
    return nullptr;
  }
  void insert(std::string id, Type *t)
  {
    scopes.back().insert(id, t);
  }

private:
  std::vector<Scope> scopes;
};

class TypeDefTable
{
public:
  void insert(std::string id)
  {
    if (types.count(id) > 0)
      semanticError("User defined type " + id + " already declared");
    types.insert(id);
  }

  void lookup(std::string id)
  {
    if (types.count(id) == 0)
      semanticError("User defined type " + id + " has not been declared");
  }

private:
  std::unordered_set<std::string> types = {};
};

class ConstrEntry
{
public:
  ConstrEntry(Type *t, std::vector<Type *> *v) : type(t), type_vec(v) {}
  ConstrEntry() {}
  Type *type;
  std::vector<Type *> *type_vec;
};

class ConstrTable
{
public:
  ConstrEntry *lookup(std::string id)
  {
    if (locals.find(id) == locals.end())
    {
      semanticError("Constructor " + id + " not found");
      return nullptr;
    }
    return &locals[id];
  }
  void insert(std::string id, Type *t, std::vector<Type *> *v)
  {
    if (locals.find(id) != locals.end())
      semanticError("Constructor " + id + " redeclared");
    locals[id] = ConstrEntry(t, v);
  }

private:
  std::map<std::string, ConstrEntry> locals;
};

// struct SymbolEntry {
//   Type *type;
//   int offset;
//   SymbolEntry(Type t, int ofs) : type(t), offset(ofs) {}
// };

// class Scope {
// public:
//   Scope() : locals(), offset(-1), size(0) {}
//   Scope(int ofs) : locals(), offset(ofs), size(0) {}
//   int getOffset() const { return offset; }
//   int getSize() const { return size; }
//   SymbolEntry *lookup(char c) {
//     if (locals.find(c) == locals.end()) return nullptr;
//     return &(locals[c]);
//   }
//   void insert(char c, Type t) {
//     if (locals.find(c) != locals.end()) {
//       std::cerr << "Duplicate variable " << c << std::endl;
//       exit(1);
//     }
//     locals[c] = SymbolEntry(t, offset++);
//     ++size;
//   }
// private:
//   std::map<char, SymbolEntry> locals;
//   int offset;
//   int size;
// };

// class SymbolTable {
// public:
//   void openScope() {
//     int ofs = scopes.empty() ? 0 : scopes.back().getOffset();
//     scopes.push_back(Scope(ofs));
//   }
//   void closeScope() { scopes.pop_back(); };
//   SymbolEntry *lookup(char c) {
//     for (auto i = scopes.rbegin(); i != scopes.rend(); ++i) {
//       SymbolEntry *e = i->lookup(c);
//       if (e != nullptr) return e;
//     }
//     std::cerr << "Unknown variable " << c << std::endl;
//     exit(1);
//   }
//   int getSizeOfCurrentScope() const { return scopes.back().getSize(); }
//   void insert(char c, Type t) { scopes.back().insert(c, t); }
// private:
//   std::vector<Scope> scopes;
// };
