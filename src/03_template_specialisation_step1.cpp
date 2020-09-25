template<typename T> struct IsChar {
    enum { value = 0 };
};

template<> struct IsChar<char> {
    enum { value = 1 };
};

template<> struct IsChar<unsigned char> {
    enum { value = 1 };
};

int main() {
    static_assert(IsChar<char>::value == 1);
    static_assert(IsChar<unsigned char>::value == 1);
    static_assert(IsChar<const char>::value == 0); // const char != char
    static_assert(IsChar<volatile char>::value == 0); // volatile char != char
    static_assert(IsChar<int>::value == 0);
    return 0;
}