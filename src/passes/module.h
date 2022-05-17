#ifndef COMPILER_MODULE_H
#define COMPILER_MODULE_H

#include "ir/function.h"
#include<vector>

class function;
class varible;
class module
{
public:
    module(/* args */)=default;
    ~module()=default;
private:
    std::vector<function*> _func_list;
    std::vector<varible*> _global_variable_list;
};


#endif // !COMPILER_MODULE_H