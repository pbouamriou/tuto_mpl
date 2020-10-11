#if (__cplusplus >= 201103L)

template<typename T>
struct HasSort {
   using yes = char;
   using no = char[2];

   template<typename U> static auto test(void*) -> decltype(&U::sort, yes());
   template<typename U> static no& test(...);

   static constexpr bool value = sizeof(HasSort::test<T>(nullptr)) == sizeof(HasSort::yes);
};

class ClassWithSort {
public:
    void sort();
};

class ClassWithoutSort {
};

int main() {
    static_assert(HasSort<ClassWithSort>::value == true);
    static_assert(HasSort<ClassWithoutSort>::value == false);
}

#else 
int main() {}
#endif
