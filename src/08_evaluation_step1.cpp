#include <iostream>

class X;

#if (__cplusplus < 201103L)
template<typename T>
struct Ptr {
    typedef T* type;
};
#else

template<typename T>
struct Ptr {
    using type = T*;
};

#endif



int main() {
    std::cout << sizeof(Ptr<X>::type) << std::endl;
}