#include <iostream>
#include <typeinfo>

template <typename A>
class Blah { };

template <unsigned int num> struct WrapU {};
// Arity 1 types
template <template <class> class one> struct WrapT1_T {};
template <template <unsigned int> class one> struct WrapT1_U {};
template <template <template <class> class> class one> struct WrapT1_T1_T {};

// Arity 2 types
template <template <class, class> class one> struct WrapT2_TT {};
template <template <class, unsigned int> class one> struct WrapT2_TU {};
template <template <unsigned int, class> class one> struct WrapT2_UT {};
template <template <unsigned int, unsigned int> class one> struct WrapT2_UU {};
template <template <class, template <class> class> class one> struct WrapT2_TT1_T {};
template <template <template <class> class, class> class one> struct WrapT2_T1_TT {};
template <template <template <class> class, template <class> class> class one> struct WrapT2_T1_TT1_T {};

// unsigned int
// class
// template <class> class
// template <unsigned int> class


template <typename A, unsigned int pos, typename B>
struct bind;

template <template <class> class A, typename B>
struct bind< WrapT1_T<A>, 0, B>
{   typedef A<B> result; };

template <template <unsigned int> class A, unsigned int B>
struct bind< WrapT1_U<A>, 0, WrapU<B> >
{   typedef A<B> result; };

template <template <template <class> class> class A, template <class> class B>
struct bind< WrapT1_T1_T<A>, 0, WrapT1_T<B> >
{   typedef A<B> result; };

template <template <class, unsigned int> class A, unsigned int B>
struct bind< WrapT2_TU<A>, 1, WrapU<B> >
{
    template <class T> struct result_intermediate
    {   typedef A<T, B> result; };

    typedef WrapT1_T<result_intermediate> result;
};

template <typename T>
struct unbind
{   typedef T result; };

template <typename A, unsigned int i, typename B>
struct unbind< bind<A, i, B> >
{
    typedef
        typename unbind<typename bind<A, i, B>::result>::result
        result;
};

template <typename A, unsigned int i, typename B, typename T>
struct unbind< typename bind<A, i, B>::template result_intermediate<T> >
{
    typedef
        typename unbind< typename bind<A, i, B>::template result_intermediate<T>::result >::result
        result;
};

template <typename A, unsigned size>
class FixedStack { };

/*
    bind<WrapT2_T_U<FixedStack>, 1, WrapU<10> >
        result_intermediate<T>::result = FixedStack<T, 10>
        result = WrapT1_T<result_intermediate>

        bind<WrapT1_T<result_intermediate>, 0, T>
            result = result_intermediate<T>
            NEED result_intermediate<T>::result

*/

int main()
{
    typedef
        bind<WrapT2_TU<FixedStack>, 1, WrapU<10> >::result
        FixedStack10;
    bind<WrapT1_T<Blah>, 0, int>::result tmp;
    bind<FixedStack10, 0, int>::result tmp2;

    std::cout << typeid(unbind<FixedStack10>::result).name() << std::endl;
    return 0;
}
