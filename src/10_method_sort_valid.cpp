#if (__cplusplus >= 201103L)

#include <utility>

template<typename T>
struct HasSort {
   using yes = char;
   using no = char[2];

   template<typename U> static auto test_sort(U& x) -> decltype(x.sort(), yes());
   template<typename U> static no& test_sort(...);

   static constexpr bool value = sizeof(HasSort::test_sort<T>(std::declval<T&>())) == sizeof(HasSort::yes);
};

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