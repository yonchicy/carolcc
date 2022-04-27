#ifndef _RUNTIME_H_
#define _RUNTIME_H_
#include <string>
#include <unordered_map>

int getStackOff();
class VaribleInfo {
public:
  std::string type;
  int offset;
  VaribleInfo() = default;
  VaribleInfo(VaribleInfo &&) = default;
  VaribleInfo(const VaribleInfo &) = default;
  VaribleInfo &operator=(VaribleInfo &&) = default;
  VaribleInfo &operator=(const VaribleInfo &) = default;
  VaribleInfo(std::string &type);
};
class FunctionInfo {
public:
  std::string type;
  int stack_size;
  std::unordered_map<std::string, VaribleInfo> VaribleTable;
  FunctionInfo() = default;
  FunctionInfo(FunctionInfo &&) = default;
  FunctionInfo(const FunctionInfo &) = default;
  FunctionInfo &operator=(FunctionInfo &&) = default;
  FunctionInfo &operator=(const FunctionInfo &) = default;
  FunctionInfo(std::string type,
               std::unordered_map<std::string, VaribleInfo> &VaribleTable);
};
extern std::unordered_map<std::string, VaribleInfo> VaribleTable;
extern std::unordered_map<std::string, FunctionInfo> FunctionTable;

#endif // !_RUNTIME_H_
