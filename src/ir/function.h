
#ifndef COMPILER_FUNCTION_H
#define COMPILER_FUNCTION_H

#include "base_block.h"
#include "helpers/type_helper.h"


#include <string>
#include <vector>

class function;
class variable;
class arguments;
class type;

class variable
{
public:
private:
    std::string id;
    type* _type;
};

class arguments{
public:
private:
    function* _parent;
    unsigned _arg_number;
    std::vector<variable*> _argument_list;
};


class function {
public:
    function(type* _type,std::string id,arguments* _args):_type(_type),_id(id),_args(_args){};

private:
    type* _type;
    std::string _id;
    arguments* _args;
    std::vector<base_block*> _base_block_list;

};
#endif//COMPILER_FUNCTION_H
