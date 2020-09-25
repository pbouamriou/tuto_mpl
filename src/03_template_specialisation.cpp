template<typename T> struct IsChar {
    enum { value = 0 };
};

template<> struct IsChar<char> {
    enum { value = 1 };
};

template<> struct IsChar<unsigned char> {
    enum { value = 1 };
};

template<typename T> struct NoCV {
    typedef T type;
};

template<typename T> struct NoCV<const T> {
    typedef T type;
};

template<typename T> struct NoCV<const volatile T> {
    typedef T type;
};

template<typename T> struct NoCV<volatile T> {
    typedef T type;
};

template<typename T> struct IsAnyChar {
    enum {
        value = IsChar<typename NoCV<T>::type>::value
    };
};



int main() {
    static_assert(IsChar<char>::value == 1);
    static_assert(IsChar<unsigned char>::value == 1);
    static_assert(IsChar<int>::value == 0);
    static_assert(IsAnyChar<const char>::value == 1);
    return 0;
}