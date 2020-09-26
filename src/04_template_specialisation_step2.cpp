template<typename T> struct IsChar {
    enum { value = 0 };
};

// Specialization (char)
template<> struct IsChar<char> {
    enum { value = 1 };
};

// Specialization (unsigned char)
template<> struct IsChar<unsigned char> {
    enum { value = 1 };
};

#if (__cplusplus < 201103L)
#include "assert_c++03.hpp"

// ---------------------------------------------------------------------------------
// C++03
template<typename T> struct NoCV {
    typedef T type;
};

// Specialization (const)
template<typename T> struct NoCV<const T> {
    typedef T type;
};

// Specialization (const volatile)
template<typename T> struct NoCV<const volatile T> {
    typedef T type;
};

// Specialization (volatile)
template<typename T> struct NoCV<volatile T> {
    typedef T type;
};

// Combinate IsChar and NoCV
template<typename T> struct IsAnyChar {
    enum {
        value = IsChar<typename NoCV<T>::type>::value
    };
};

// ---------------------------------------------------------------------------------

#else

// ---------------------------------------------------------------------------------
// C++11

#include <type_traits>

template<typename T> struct NoCV {
    using type =  T;
};

// Specialization (const)
template<typename T> struct NoCV<const T> {
    using type =  T;
};

// Specialization (const volatile)
template<typename T> struct NoCV<const volatile T> {
    using type =  T;
};

// Specialization (volatile)
template<typename T> struct NoCV<volatile T> {
    using type =  T;
};

// Combinate IsChar and NoCV
template<typename T> struct IsAnyChar {
    static constexpr auto value = IsChar<typename NoCV<T>::type>::value;
};

// ---------------------------------------------------------------------------------

#endif



int main() {
    static_assert(IsAnyChar<const char>::value == 1);
    return 0;
}