#if (__cplusplus < 201103L)
#include "assert_c++03.hpp"

template<int N> struct Sum {
    enum {
        value = N + Sum<N-1>::value
    };
};

template<> struct Sum<0> {
    enum {
        value = 0
    };
};
#else
template<int N> struct Sum {
    static constexpr auto value = N + Sum<N-1>::value;
};

template<> struct Sum<0> {
    static constexpr auto value = 0;
};

#endif

int main() {
    static_assert(Sum<0>::value == 0);
    static_assert(Sum<1>::value == 1);
    static_assert(Sum<10>::value == 55);
}