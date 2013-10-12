#include <iostream>
#include "functional.h"
#include "tester.h"
//---------------------------------------------------------------------------
void test_ptr_fun_arity0_1()
{
    // do nothing
}
//---------------------------------------------------------------------------
int test_ptr_fun_arity0_2()
{
    return 4679;
}
//---------------------------------------------------------------------------
void test_ptr_fun_arity1_1(int x)
{
    // do nothing
}
//---------------------------------------------------------------------------
int test_ptr_fun_arity1_2(int x)
{
    return x / 2;
}
//---------------------------------------------------------------------------
void test_ptr_fun_arity1_3(double x)
{
    x *= 2;
}
//---------------------------------------------------------------------------
int main()
{
    tester<std::ostream>    t(std::cout);

    /* Test ptr_fun() */
    {
        using DarkPath::ptr_fun;

        t.beginSection("Test Suite - ptr_fun");
        /*  Test 1 - arity 0, no return.
            Will not compile if it doesn't pass
        */
        {
            ptr_fun(test_ptr_fun_arity0_1)();
            t.test("arity 0, no return", true);
        }

        /*  Test 2 - arity 0, int return.
        */
        {
            t.test(
                "arity 0, int return",
                ptr_fun(test_ptr_fun_arity0_2)() == 4679
            );
        }

        /*  Test 3 - arity 1, no return.
            Will not compile if it doesn't pass
        */
        {
            ptr_fun(test_ptr_fun_arity1_1)(1);
            t.test("arity 1, no return", true);
        }

        /*  Test 4 - arity 1, int return.
        */
        {
            t.test(
                "arity 1, int return",
                ptr_fun(test_ptr_fun_arity1_2)(514) == 257
            );
        }

        /*  Test 5 - arity 1, STL compat - for_each
            Won't compile if it doesn't pass.
        */
        {
            std::vector<double> x;
            x.push_back(1.0);
            x.push_back(2.0);
            x.push_back(3.14159);
            x.push_back(4.5);
            x.push_back(5.78);
            for_each(x.begin(), x.end(), ptr_fun(test_ptr_fun_arity1_3));
            t.test(
                "arity 1, STL compat - for_each",
                true
            );
        }

    }


    return 0;
}
//---------------------------------------------------------------------------

