#include <cstdlib>
#include <vector>
#include <map>
#include <unordered_set>

void semanticError(std::string msg);
class Type;

class SymbolEntry
{
public:
  SymbolEntry(Type *t, int ofs) : type(t), offset(ofs) {}
  SymbolEntry() {}
  Type *type;
  int offset;
};

class Scope
{
public:
  Scope() : locals(), offset(-1), size(0) {}
  Scope(int ofs) : locals(), offset(ofs), size(0) {}
  SymbolEntry *lookup(std::string &id)
  {
    if (locals.find(id) == locals.end())
      return nullptr;
    return &locals[id];
  }
  void insert(std::string &id, Type *t)
  {
    if (locals.find(id) != locals.end())
      semanticError("Redeclared identifier " + id);
    locals[id] = SymbolEntry(t, offset++);
    ++size;
  }

private:
  std::map<std::string, SymbolEntry> locals;

public:
  int offset;
  int size;
};

class SymbolTable
{
public:
  void openScope()
  {
    int ofs = scopes.empty() ? 0 : scopes.back().offset;
    scopes.push_back(Scope(ofs));
  }
  void closeScope()
  {
    int ofs = scopes.back().offset;
    scopes.pop_back();
    scopes.back().offset = ofs;
  }
  SymbolEntry *lookup(std::string &id)
  {
    for (auto i = scopes.rbegin(); i != scopes.rend(); ++i)
    {
      SymbolEntry *e = i->lookup(id);
      if (e != nullptr)
      {
        id = id + "_" + std::to_string(e->offset);
        return e;
      }
    }
    semanticError("Unknown identifier " + id);
    return nullptr;
  }
  void insert(std::string &id, Type *t)
  {
    scopes.back().insert(id, t);
    id = id + "_" + std::to_string(scopes.back().offset - 1);
  }

private:
  std::vector<Scope> scopes;
};

class TypeDefTable
{
public:
  void lookup(std::string &id)
  {
    if (types.count(id) == 0)
      semanticError("Unknown identifier " + id);
  }
  void insert(std::string &id)
  {
    if (types.count(id) > 0)
      semanticError("Redeclared identifier " + id);
    types.insert(id);
  }

private:
  std::unordered_set<std::string> types = {};
};

// class ConstrEntry
// {
// public:
//   ConstrEntry(Type *t, std::vector<Type *> *v) : type(t), type_vec(v) {}
//   ConstrEntry() {}
//   Type *type;
//   std::vector<Type *> *type_vec;
// };

// class ConstrTable
// {
// public:
//   ConstrEntry *lookup(std::string &id)
//   {
//     if (locals.find(id) == locals.end())
//     {
//       semanticError("Unknown identifier " + id);
//       return nullptr;
//     }
//     return &locals[id];
//   }
//   void insert(std::string &id, Type *t, std::vector<Type *> *v)
//   {
//     if (locals.find(id) != locals.end())
//       semanticError("Redeclared identifier " + id);
//     locals[id] = ConstrEntry(t, v);
//   }

// private:
//   std::map<std::string, ConstrEntry> locals;
// };
