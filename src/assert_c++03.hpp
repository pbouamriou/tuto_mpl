#ifndef ASSERT_CPP03_H
#define ASSERT_CPP03_H


#if (__cplusplus < 201103L)

template<bool>
struct static_assertion;

template<>
struct static_assertion<true> {};

#define static_assert(condition) static_assertion<condition>()
#endif

#endif