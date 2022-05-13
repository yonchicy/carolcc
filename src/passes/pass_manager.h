
#ifndef COMPILER_PASS_MANAGER_H
#define COMPILER_PASS_MANAGER_H
#include "pass.h"
#include "module.h"
#include <vector>
class pass_manager
{
private:
    std::vector<pass*> passes;
    std::shared_ptr<module> _m;
public:
    pass_manager(module m);
    ~pass_manager();
    template <typename pass_type> void add_pass(){
        passes.push_back(new pass_type(typeid(pass_type).name(),_m));
    }
};
pass_manager::pass_manager(module m):_m(m){}


#endif//COMPILER_PASS_MANAGER_H