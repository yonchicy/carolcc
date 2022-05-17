//
// Created by Administrator on 2022/5/1.
//

#ifndef COMPILER_TYPE_HELPER_H
#define COMPILER_TYPE_HELPER_H

enum class type_helper{
    INT,
    FLOAT,
    VOID
};
class type {
public:
    explicit type(type_helper _type):_type(_type){}
private :
    type_helper _type;
};
#endif//COMPILER_TYPE_HELPER_H
