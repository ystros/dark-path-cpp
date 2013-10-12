#include <iostream>
#include <typeinfo>

/*
    bind<WrapT2_T_U<FixedStack>, 1, WrapU<10> >
        result_intermediate<T>::result = FixedStack<T, 10>
        result = WrapT1_T<result_intermediate>

        bind<WrapT1_T<result_intermediate>, 0, T>
            result = result_intermediate<T>
            NEED result_intermediate<T>::result

*/
/*
template <template <class, class> class x> struct Wrap2 {};
template <template <class> class x> struct Wrap1 {};

template <typename A, unsigned int i, typename B>
struct Bind;

template <template <class> class A, typename B>
struct Bind< Wrap1<A>, 0, B >
{
    typedef A<B> result;
};

template <template <class, class> class A, typename B>
struct Bind< Wrap2<A>, 1, B >
{
    template <typename T>
    struct temp
    {
        typedef
            A<T, B>
            result;
    };

    typedef Wrap1<temp> result;
};

template <typename T>
struct Unwind
{
    typedef T result;
};

template <typename A, unsigned int i, typename B>
struct Unwind< Bind<A, i, B> >
{
    typedef
        typename Unwind<typename Bind<A, i, B>::result>::result
        result;
};

template <typename A, unsigned int i, typename B, typename T>
struct Unwind< typename Bind<A, i, B>::template temp<T> >
{
    typedef
        typename Unwind<typename Bind<A, i, B>::template temp<T>::result>::result
        result;
};*/

template <class, class> struct Foo {};

typedef Foo Foo2;

int main()
{
    Foo<int, char> x;
    Foo2<int, char> y;
//    typedef Bind<Wrap2<Foo>, 1, int>::result Bound2Foo;
//    typedef Bind<Bound2Foo, 0, double>::result Bound21Foo;
//    typedef Unwind<Bound21Foo>::result  FooUnleashed;
//    std::cout << typeid(Bound2Foo).name() << std::endl;
//    std::cout << typeid(Bound21Foo).name() << std::endl;
//    typedef Unwind<Bound21Foo>::result BoundFoo;

//    BoundFoo tmp;

    return 0;
}
