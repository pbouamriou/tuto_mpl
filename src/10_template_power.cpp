#include <math.h>
#if (__cplusplus < 201103L)
#include "assert_c++03.hpp"
#else

#endif

int main() {
    for( long long unsigned i = 0; i < (1UL<<60); ++i) {
        double x = drand48()/drand48();
        pow(x, 16);
    }
}