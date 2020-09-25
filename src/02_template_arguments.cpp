template<unsigned N> struct EstPair {
    enum {
        value = (N%2) ? 0 : 1
    };
};

int main() {
    static_assert(EstPair<12>::value == 1);
    static_assert(EstPair<1>::value == 0);
}