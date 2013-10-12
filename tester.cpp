#include <iostream>
#include <typeinfo>
#include "functional.h"
//---------------------------------------------------------------------------
void one(int) {}
char two(int, double) { return 'A'; }
float three(int, double, char*) { return 1.0; }

class B
{
    public:
        void mone(int) {}
        char mtwo(int, double) { return 'A'; }
        float mthree(int, double, char*) { return 1.0; }
};

class C :
    public DarkPath::n_ary_function_interface_bysize<
        DarkPath::typelist< TYPELIST_2(int, double&) >,
        void,
        2
      >
{
    public:
        virtual void operator ()(int x, double& y)
        {
            y *= x;
        }
};



template <typename f>
DarkPath::function_pointer_traits<f> get_traits(f x)
{
    return DarkPath::function_pointer_traits<f>();
}

int main()
{
    C c;
    double y = 3.14159;

    c(2, y);
    std::cout << "c(2, y) = " << y << std:: endl;

    get_traits(main);
    get_traits(one);
    get_traits(two);
    get_traits(three);
    get_traits(&B::mone);
    get_traits(&B::mtwo);
    get_traits(&B::mthree);

    typedef DarkPath::typelist<TYPELIST_3(int, char, double) > my_typelist;
    typedef
        DarkPath::type::reverse<
            my_typelist::begin, my_typelist::end, DarkPath::NULL_typelist
        >::result
        myreversed_typelist;

    std::cout << "Loki:   " << typeid(my_typelist::_loki).name() << std::endl;
//    std::cout << "Head:   " << typeid(my_typelist::head).name() << std::endl;
//    std::cout << "Tail:   " << typeid(my_typelist::tail).name() << std::endl;
    std::cout << "Front:  " << typeid(my_typelist::front::result).name() << std::endl;
    std::cout << "Back:   " << typeid(my_typelist::back::result).name() << std::endl;
    std::cout << "At[1]:  " << typeid(my_typelist::at<1>::result).name() << std::endl;
    std::cout << "Length: " << my_typelist::size << std::endl;
    std::cout << "Empty:  " << my_typelist::empty << std::endl;

    char pause;
    std::cin >> pause;

    return 0;
}

