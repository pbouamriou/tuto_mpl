#if (__cplusplus < 201103L)
#include "assert_c++03.hpp"

template<bool C, typename T, typename F> struct If {
    typedef T type;
};

template<typename T, typename F> struct If<false, T, F> {
    typedef F type;
};

template<typename T1, typename T2> struct isSameType {
    enum { value = false };
};

template<typename T1> struct isSameType<T1, T1> {
    enum { value = true };
};

#else
template<bool C, typename T, typename F> struct If {
    using type = T;
};

template<typename T, typename F> struct If<false, T, F> {
    using type = F;
};

template<typename T1, typename T2> struct isSameType {
    static constexpr const auto value = false;
};

template<typename T1> struct isSameType<T1, T1> {
    static constexpr const auto value = true;
};

#endif

int main() {
#if (__cplusplus < 201103L)
#define x 10
    static_assert((isSameType<If<(x > 0), int, bool>::type, int>::value));
    static_assert((isSameType<If<(x < 0), int, bool>::type, bool>::value));
#else
    constexpr const auto x = 10;
    static_assert(isSameType<If<(x > 0), int, bool>::type, int>::value);
    static_assert(isSameType<If<(x < 0), int, bool>::type, bool>::value);
#endif
    return 0;
}
