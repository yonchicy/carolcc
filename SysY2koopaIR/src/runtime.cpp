#include "../include/runtime.h"
#include <cstdio>
std::unordered_map<std::string, VaribleInfo> VaribleTable;
std::unordered_map<std::string, FunctionInfo> FunctionTable;
int scope_offset;
int test(int argc, char *argv[]) { return 0; }

int getStackOff() { return 3+scope_offset++; }

VaribleInfo::VaribleInfo(std::string &type)
    : type(type), offset(getStackOff()) {}

FunctionInfo::FunctionInfo(
    std::string type, 
    std::unordered_map<std::string, VaribleInfo>& VaribleTable)
    : type(type), stack_size(0), VaribleTable(VaribleTable) {
  stack_size = (VaribleTable.size() + 2) * 4;
};
