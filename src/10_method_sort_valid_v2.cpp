#if (__cplusplus >= 201103L)

#include <utility>
#include <type_traits>

// template<typename T> using void_t = void;
template<class...> using void_t = void;

template<typename T>
using test_sort = decltype(
    std::declval<T&>().sort()
);

template<typename T, typename = void>
struct HasSort : std::false_type {};

template<typename T>
struct HasSort<T, void_t<test_sort<T>>> : std::true_type {};

class ClassWithSort {
public:
    void sort();
};

class ClassWithBadSort {
public:
    void sort(int);
};

class ClassWithoutSort {
};

int main() {
    static_assert(HasSort<ClassWithSort>::value == true);
    static_assert(HasSort<ClassWithBadSort>::value == false);
    static_assert(HasSort<ClassWithoutSort>::value == false);
}

#else 
int main() {}
#endif