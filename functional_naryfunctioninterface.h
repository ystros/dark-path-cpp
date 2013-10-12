//----------------------------------------------------------------------------
#ifndef DARKPATH_functional_naryfunctioninterfaceH
#define DARKPATH_functional_naryfunctioninterfaceH
//----------------------------------------------------------------------------
#include "functional_naryfunction.h"
//----------------------------------------------------------------------------
namespace DarkPath
{
    //========================================================================
    /*! @class  n_ary_function_interface
        @brief  Interface for an n-ary adaptable function object.

        Pure virtual interface for function objects.

        Currently supported up to function arity 8.
    */
    //========================================================================
    template <typename ATL, typename RT, unsigned int>
    class n_ary_function_interface_bysize;

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 0> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(

              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 1> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 2> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 3> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 4> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 5> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 6> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 7> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 8> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 9> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 10> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 11> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result, 
                typename ATL::at<10>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 12> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result, 
                typename ATL::at<10>::result, typename ATL::at<11>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 13> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result,
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result,
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result, 
                typename ATL::at<10>::result, typename ATL::at<11>::result, 
                typename ATL::at<12>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 14> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result, 
                typename ATL::at<10>::result, typename ATL::at<11>::result, 
                typename ATL::at<12>::result, typename ATL::at<13>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 15> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result, 
                typename ATL::at<10>::result, typename ATL::at<11>::result, 
                typename ATL::at<12>::result, typename ATL::at<13>::result, 
                typename ATL::at<14>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 16> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result,
                typename ATL::at<10>::result, typename ATL::at<11>::result, 
                typename ATL::at<12>::result, typename ATL::at<13>::result,
                typename ATL::at<14>::result, typename ATL::at<15>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 17> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result, 
                typename ATL::at<10>::result, typename ATL::at<11>::result, 
                typename ATL::at<12>::result, typename ATL::at<13>::result, 
                typename ATL::at<14>::result, typename ATL::at<15>::result, 
                typename ATL::at<16>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 18> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result,
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result, 
                typename ATL::at<6>::result, typename ATL::at<7>::result, 
                typename ATL::at<8>::result, typename ATL::at<9>::result, 
                typename ATL::at<10>::result, typename ATL::at<11>::result, 
                typename ATL::at<12>::result, typename ATL::at<13>::result, 
                typename ATL::at<14>::result, typename ATL::at<15>::result, 
                typename ATL::at<16>::result, typename ATL::at<17>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 19> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result, 
                typename ATL::at<2>::result, typename ATL::at<3>::result, 
                typename ATL::at<4>::result, typename ATL::at<5>::result,
                typename ATL::at<6>::result, typename ATL::at<7>::result,
                typename ATL::at<8>::result, typename ATL::at<9>::result,
                typename ATL::at<10>::result, typename ATL::at<11>::result,
                typename ATL::at<12>::result, typename ATL::at<13>::result,
                typename ATL::at<14>::result, typename ATL::at<15>::result,
                typename ATL::at<16>::result, typename ATL::at<17>::result,
                typename ATL::at<18>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface_bysize<ATL, RT, 20> :
        public n_ary_function<ATL, RT>
    {
        public:
            virtual ~n_ary_function_interface_bysize()
            { /* empty destructor */ }

            virtual RT operator ()(
                typename ATL::at<0>::result, typename ATL::at<1>::result,
                typename ATL::at<2>::result, typename ATL::at<3>::result,
                typename ATL::at<4>::result, typename ATL::at<5>::result,
                typename ATL::at<6>::result, typename ATL::at<7>::result,
                typename ATL::at<8>::result, typename ATL::at<9>::result,
                typename ATL::at<10>::result, typename ATL::at<11>::result,
                typename ATL::at<12>::result, typename ATL::at<13>::result,
                typename ATL::at<14>::result, typename ATL::at<15>::result,
                typename ATL::at<16>::result, typename ATL::at<17>::result,
                typename ATL::at<18>::result, typename ATL::at<19>::result
              ) = 0;
    };

    template <typename ATL, typename RT>
    class n_ary_function_interface :
        public virtual n_ary_function_interface_bysize<ATL, RT, ATL::size>
    {
    };

    //========================================================================
} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
