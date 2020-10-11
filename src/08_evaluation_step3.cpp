#include <utility>
#include <iostream>

#if (__cplusplus >= 201103L)

struct Default { int foo() const { return 1; } };
 
struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};

int main()
{
    //std::cout << typeid(decltype(NonDefault().foo())).name() << std::endl;
    std::cout << typeid(decltype(std::declval<NonDefault>().foo())).name() << std::endl;
}

#else
int main() {}
#endif