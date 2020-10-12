#if (__cplusplus >= 201103L)

template <int First, int... Rest>
struct Sum
{
    static constexpr auto value = First + Sum<Rest...>::value;
};

template <int First>
struct Sum<First>
{
    static constexpr auto value = First;
};

int main()
{
    static_assert(Sum<5, 10, 20>::value == 35);
}

#else

int main() {}

#endif