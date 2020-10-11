#if (__cplusplus < 201103L)
#include "assert_c++03.hpp"

template<bool C, typename T, typename F> struct If {
    typedef T type;
};

template<typename T, typename F> struct If<false, T, F> {
    typedef F type;
};

template<class T, T v>
struct IntegralConstant {
    enum {
       value = v
    };
    typedef T value_type;
    typedef IntegralConstant<T,v> type;
};

struct TrueType : IntegralConstant<bool, true> {};
struct FalseType : IntegralConstant<bool, false> {};

template<typename T1, typename T2> struct isSameType : FalseType {}; 
template<typename T1> struct isSameType<T1, T1> : TrueType {};

#else
template<bool C, typename T, typename F> struct If {
    using type = T;
};

template<typename T, typename F> struct If<false, T, F> {
    using type = F;
};

template<class T, T v>
struct IntegralConstant {
    static constexpr const T value = v;
    using value_type = T;
    using type = IntegralConstant<T,v>;
};

struct TrueType : IntegralConstant<bool, true> {};
struct FalseType : IntegralConstant<bool, false> {};

template<typename T1, typename T2> struct isSameType : FalseType {};
template<typename T1> struct isSameType<T1, T1> : TrueType {};

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
