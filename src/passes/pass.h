#ifndef COMPILER_PASS_H
#define COMPILER_PASS_H

#include "module.h"
#include <string>
#include <memory>
class pass
{
private:
    std::string _name;
    std::shared_ptr<module> _m;
public:
    pass(std::string name,std::shared_ptr<module> m):_name(name),_m(m){};
    void set_name(std::string name){
        _name =  name;
    }

    ~pass();
};


#endif // COMPILER_PASS_H