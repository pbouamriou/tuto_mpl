#if (__cplusplus < 201103L)
#include "assert_c++03.hpp"
// C++03
template<typename T> struct SizeOf {
    enum { value = sizeof(T) };
};

#else

// C++11
template<typename T> struct SizeOf {
    static constexpr auto value = sizeof(T);
};

#endif

int main() {
    static_assert(SizeOf<int>::value == 4);
    static_assert(SizeOf<double>::value == 8);
}