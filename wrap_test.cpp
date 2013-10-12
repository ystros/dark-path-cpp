#include <iostream>
#include <typeinfo>

#define DP_COMPAT_partial_template_specialization
#define DP_COMPAT_nested_keyword_template

#include "types_wrap.hpp"

using DarkPath::Types::Wrap;
using DarkPath::Types::Unwind;

template <class T> struct Bar {
    void print()
    {
        std::cout << "This should work." << std::endl;
    }

};

template <template <class> class F>
struct Foo
{
    typedef F<int>                       FType;
    typedef typename Unwind< F<int> >::R FooType;

    void print()
    {
        std::cout << typeid(FType).name() << " => " << typeid(FooType).name() << std::endl;
    }
};

int main()
{
    Foo<Bar>                        a;
    Foo<Wrap::T1<Bar>::T>           b;
//    Foo<Bar>::FooType               c;
//    Foo<Wrap::T1<Bar>::T>::FooType  d;

    a.print();
    b.print();
//    c.print();
//    d.print();

    return 0;
}
