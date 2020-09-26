#if (__cplusplus < 201103L)
#include "assert_c++03.hpp"
// C++03
template<typename T> struct ConstType {
    typedef const T type;
};

#else

// C++11
template<typename T> struct ConstType {
    using type = const T;
};

#endif

int main() {
    ConstType<int>::type x = 10;
}