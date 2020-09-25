#if (__cplusplus < 201103L)
// C++03
template<typename T> struct TailleDe {
    enum { value = sizeof(T) };
};

#else

// C++11
template<typename T> struct TailleDe {
    static constexpr auto value = sizeof(T);
};

#endif

int main() {
    static_assert(TailleDe<int>::value == 4);
    static_assert(TailleDe<double>::value == 8);
}