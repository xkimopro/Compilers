#pragma once

#include <cstdlib>
#include <vector>
#include <map>

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

class Scope {
public:
  Scope() : locals() {}
  SymbolEntry * lookup(std::string id) {
    if (locals.find(id) == locals.end()) return nullptr;
    return &locals[id];
  }
  void insert(std::string id, Type *t) {
    if (locals.find(id) != locals.end()) semanticError("Identifier " + id + " redeclared");
    locals[id] = SymbolEntry(t);
  }
private:
  std::map<std::string, SymbolEntry> locals;
};

class SymbolTable {
public:
  void openScope() {
    scopes.push_back(Scope());
  }
  void closeScope() {
    scopes.pop_back();
  }
  SymbolEntry * lookup(std::string id) {
    for (auto i = scopes.rbegin(); i != scopes.rend(); ++i) {
      SymbolEntry *e = i->lookup(id);
      if (e != nullptr) return e;
    }
    semanticError("Variable " + id + "  not found");
    return nullptr;
  }
  void insert(std::string id, Type *t) {
    scopes.back().insert(id, t);
  }
  
private:
  std::vector<Scope> scopes;
};

//class SymbolTable
//{
//public:
//    SymbolTable() {}
//    SymbolEntry *lookup(std::string id)
//    {
//        if (globals.find(id) != globals.end())
//            return &globals[id];
//        return nullptr;
//    }
//    void insert(std::string id, Type *t)
//    {
//        if (globals.find(id) != globals.end())
//        {
//            std::cerr << "Duplicate variable " << id << std::endl;
//            exit(1);
//        }
//        globals[id] = SymbolEntry(t);
//    }
//
//private:
//    std::map<std::string, SymbolEntry> globals;
//};

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
