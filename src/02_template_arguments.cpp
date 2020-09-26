#if (__cplusplus < 201103L)
#include "assert_c++03.hpp"
#endif

template<unsigned N> struct IsEven {
    enum {
        value = (N%2) ? 0 : 1
    };
};

int main() {
    static_assert(IsEven<12>::value == 1);
    static_assert(IsEven<1>::value == 0);
}