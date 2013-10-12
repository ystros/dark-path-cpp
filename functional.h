//---------------------------------------------------------------------------
/*! @file   functional.h
    @brief  Contains classes and functions dealing with DarkPath adaptable
            function objects.
    x.
*/
//---------------------------------------------------------------------------
#ifndef DARKPATH_functionalH
#define DARKPATH_functionalH
//---------------------------------------------------------------------------
#include "functional_naryfunction.h"
#include "functional_traits.h"
#include "functional_naryfunctioninterface.h"
#include "functional_pointertonary.h"
#include "functional_binder.h"
//---------------------------------------------------------------------------
namespace DarkPath
{

    template <typename f>
    n_ary_function_interface<
        typename function_traits<f>::argument_typelist,
        typename function_traits<f>::result_type
    >*
    indirect_fun(f function)
    {
        return new pointer_to_n_ary_function<f>(function);
    }

    //========================================================================
    /*! @fn     pointer_to_n_ary_function<f> ptr_fun(f func)
        @brief  Takes a function pointer and makes it a DarkPath AFO.
        @param  func Function pointer to adapt.
        @return An adaptable function object that uses \a func as its
                implementation.
    */
    //========================================================================
    template <typename f>
    pointer_to_n_ary_function<f> ptr_fun(f func)
    {
        return pointer_to_n_ary_function<f>(func);
    }

    template <unsigned int n, typename FT, typename AT>
    function_binder<FT, AT, n> bind(FT func, AT arg)
    {
        return function_binder<FT, AT, n>(func, arg);
    }

    //========================================================================
    /*
        member_function_pointer_to_afo<FunctionPointerType>
        Changes a plain C++ function pointer into an adaptable function object.

        See function_pointer_traits documentation for maximum arity support.
    */
    //========================================================================
/*
    template <typename f>
    class member_function_pointer_to_afo :
        public n_ary_function<
            typename Loki::Typelist<
                typename function_pointer_traits<f>::member_of_type,
                typename function_pointer_traits<f>::ArgumentTypeList
            >,
            typename function_pointer_traits<f>::result_type
        >
    {
        private:
            typedef function_pointer_traits<f> p;

            f   mf_Func;
        public:
            explicit member_function_pointer_to_afo(f func) :
                mf_Func(func)
            {
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj
            ) const
            {
                return ((*obj).*mf_Func)();
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 0) a0
            ) const
            {
                return ((*obj).*mf_Func)(a0);
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 0) a0,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 1) a1
            ) const
            {
                return ((*obj).*mf_Func)(a0, a1);
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 0) a0,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 1) a1,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 2) a2
            ) const
            {
                return ((*obj).*mf_Func)(a0, a1, a2);
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 0) a0,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 1) a1,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 2) a2,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 3) a3
            ) const
            {
                return ((*obj).*mf_Func)(a0, a1, a2, a3);
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 0) a0,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 1) a1,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 2) a2,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 3) a3,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 4) a4
            ) const
            {
                return ((*obj).*mf_Func)(a0, a1, a2, a3, a4);
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 0) a0,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 1) a1,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 2) a2,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 3) a3,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 4) a4,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 5) a5
            ) const
            {
                return ((*obj).*mf_Func)(a0, a1, a2, a3, a4, a5);
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 0) a0,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 1) a1,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 2) a2,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 3) a3,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 4) a4,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 5) a5,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 6) a6
            ) const
            {
                return ((*obj).*mf_Func)(a0, a1, a2, a3, a4, a5, a6);
            }

            typename p::result_type operator () (
                typename p::member_of_type* obj,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 0) a0,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 1) a1,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 2) a2,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 3) a3,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 4) a4,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 5) a5,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 6) a6,
                LOKI_TL_TypeAtNonStrict(typename p::ArgumentTypeList, 7) a7
            ) const
            {
                return ((*obj).*mf_Func)(a0, a1, a2, a3, a4, a5, a6, a7);
            }
    };

    template <typename f>
    member_function_pointer_to_afo<f> mem_fun(f function)
    {
        return member_function_pointer_to_afo<f>(function);
    }
*/
    //========================================================================
}
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

