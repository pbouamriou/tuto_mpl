#include <iostream>

#if (__cplusplus < 201103L)
class SansAliasType {};
struct AvecAliasType { typedef SansAliasType type; };
#else
class SansAliasType {};
struct AvecAliasType { using type = SansAliasType; };
#endif

template <class T> void f(T) { // version générale
      std::cout << "f(T)" << std::endl;
}

template <class T> void f(typename T::type) { // version plus spécifique
      std::cout << "f(T::type)" << std::endl;
}

int main() {
   f<SansAliasType>(SansAliasType());
   f<AvecAliasType>(SansAliasType());
}