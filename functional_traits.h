//----------------------------------------------------------------------------
#ifndef DARKPATH_functional_traitsH
#define DARKPATH_functional_traitsH
//----------------------------------------------------------------------------
#include "functional_naryfunction.h"
#include "typelist.h"
//----------------------------------------------------------------------------
namespace DarkPath
{
    //========================================================================
    /*! @class  function_traits
        @brief  Traits structure for C++ function pointers and DarkPath
                adaptable function objects.
        @param  f   Function pointer type or a DarkPath adaptable function
                    object. 


        Extracts return and parameter type information from a plain C++
        function pointer and formats it as in the n_ary_function class.
    */
    //========================================================================
    template <typename f>
    struct function_traits
    {
        /*! The type of the function pointer or AFO object that we are
            determining the traits of.
        */
        typedef
            f
            function_type;
        
        /*! A typelist containing the parameter types of \c function_type in
            sequential order.
        */
        typedef
            typename f::argument_typelist
            argument_typelist;

        /*! The return type of \c function_type
        */
        typedef
            typename f::result_type
            result_type;

        enum
        {
            /*!< The number of parameters \c function_type takes. */
            arity = argument_typelist::length
        };

        /*! If \c function_type is a member function, \c member_of_type is the
            type of its parent.  Otherwise, \c member_of_type is \c void.
        */
        typedef
            typename f::member_of_type
            member_of_type;

        /*! Provided for STL compatibility.  If the arity of \c function_type
            is less than 1, \c argument_type is \c void.
        */
        typedef
            typename argument_typelist::at_nonstrict<0, void>::result
            argument_type;

        /*! Provided for STL compatibility.  If the arity of \c function_type
            is less than 1, \c argument_type is \c void.
        */
        typedef
            typename argument_typelist::at_nonstrict<0, void>::result
            first_argument_type;

        /*! Provided for STL compatibility.  If the arity of \c function_type
            is less than 2, \c argument_type is \c void.
        */
        typedef
            typename argument_typelist::at_nonstrict<1, void>::result
            second_argument_type;
    };

#   ifndef DOXYGEN_SHOULD_SKIP
    //========================================================================
    /*  SPECIALIZATIONS OF function_traits FOR function pointers

        Each specialization of function_traits for function pointers inherits 
        from n_ary_function for the appropriate typedefs and enum values.
    */
    //========================================================================

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 0
    //------------------------------------------------------------------------
    template <typename RT>
    struct function_traits< RT (*)() > :
        public n_ary_function<NULL_typelist, RT>
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 1
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1
    >
    struct function_traits<
      RT (*)(
        a1
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_1(
            a1
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 2
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2
    >
    struct function_traits<
      RT (*)(
        a1, a2
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_2(
            a1, a2
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 3
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_3(
            a1, a2, a3
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 4
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_4(
            a1, a2, a3, a4
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 5
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_5(
            a1, a2, a3, a4, a5
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 6
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_6(
            a1, a2, a3, a4, a5, a6
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 7
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_7(
            a1, a2, a3, a4, a5, a6, a7
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 8
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_8(
            a1, a2, a3, a4, a5, a6, a7, a8
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 9
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_9(
            a1, a2, a3, a4, a5, a6, a7, a8, a9
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 10
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_10(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 11
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_11(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 12
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_12(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 13
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_13(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 14
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_14(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 15
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_15(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 16
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_16(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 17
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16, typename a17
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
        a16, a17
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_17(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16, a17
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 18
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16, typename a17, typename a18
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
        a16, a17, a18
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_18(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16, a17, a18
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 19
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16, typename a17, typename a18, typename a19
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
        a16, a17, a18, a19
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_19(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16, a17, a18, a19
          ) >,
          RT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for function pointers of arity 20
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16, typename a17, typename a18, typename a19, typename a20
    >
    struct function_traits<
      RT (*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
        a16, a17, a18, a19, a20
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_20(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16, a17, a18, a19, a20
          ) >,
          RT
        >
    {
    };

    //========================================================================
    /*  SPECIALIZATIONS OF function_traits FOR member function pointers

        Each specialization of function_traits for member function pointers
        inherits from n_ary_function for the appropriate typedefs and enum
        values.
    */
    //========================================================================

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 0
    //------------------------------------------------------------------------
    template <typename RT, typename MT>
    struct function_traits< RT (MT::*)() > :
        public n_ary_function<NULL_typelist, RT, MT>
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 1
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_1(
            a1
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 2
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_2(
            a1, a2
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 3
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_3(
            a1, a2, a3
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 4
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_4(
            a1, a2, a3, a4
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 5
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_5(
            a1, a2, a3, a4, a5
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 6
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_6(
            a1, a2, a3, a4, a5, a6
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 7
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_7(
            a1, a2, a3, a4, a5, a6, a7
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 8
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_8(
            a1, a2, a3, a4, a5, a6, a7, a8
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 9
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_9(
            a1, a2, a3, a4, a5, a6, a7, a8, a9
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 10
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_10(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 11
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_11(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 12
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_12(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 13
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_13(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 14
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_14(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 15
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_15(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 16
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_16(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 17
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16, typename a17,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
        a16, a17
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_17(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16, a17
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 18
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16, typename a17, typename a18,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
        a16, a17, a18
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_18(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16, a17, a18
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 19
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16, typename a17, typename a18, typename a19,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
        a16, a17, a18, a19
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_19(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16, a17, a18, a19
          ) >,
          RT,
          MT
        >
    {
    };

    //------------------------------------------------------------------------
    //  Specialization for member function pointers of arity 20
    //------------------------------------------------------------------------
    template <
        typename RT,
        typename a1, typename a2, typename a3, typename a4, typename a5, 
        typename a6, typename a7, typename a8, typename a9, typename a10, 
        typename a11, typename a12, typename a13, typename a14, typename a15, 
        typename a16, typename a17, typename a18, typename a19, typename a20,
        typename MT
    >
    struct function_traits<
      RT (MT::*)(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
        a16, a17, a18, a19, a20
      )
    > :
        public n_ary_function<
          typelist< TYPELIST_20(
            a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 
            a16, a17, a18, a19, a20
          ) >,
          RT,
          MT
        >
    {
    };

#   endif    
    //========================================================================
} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

