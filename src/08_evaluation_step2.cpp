#include <iostream>

struct X {
    static const int* pvalue;
};

int main() {
    std::cout << sizeof(*(X().pvalue)) << std::endl;
}
