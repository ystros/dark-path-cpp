#include <iostream>
#include <typeinfo>

#define DP_COMPAT_partial_template_specialization
#define DP_COMPAT_nested_keyword_template

#include "types_wrap.hpp"

using DarkPath::Types::Wrap;
using DarkPath::Types::Unwind;

template <class T> struct Bar { };

template <template <class> class F>
struct Foo
{
    typedef typename Unwind< F<int> >::R FooType;

    void print()
    {
        std::cout << typeid(F<int>).name() << " -> " << typeid(FooType).name() << std::endl;
    }
};

int main()
{
    Foo<Bar>                a;
    Foo<Wrap::T1<Bar>::T>   b;

    a.print();
    b.print();

    char c;

    std::cin >> c;

    return 0;
}
