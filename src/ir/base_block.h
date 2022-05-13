
#ifndef COMPILER_BASE_BLOCK_H
#define COMPILER_BASE_BLOCK_H
#include "instruction.h"
#include <list>
#include <memory>
class base_block {
private:
    std::list<instruction*> _instructions;
public:
};


#endif//COMPILER_BASE_BLOCK_H
