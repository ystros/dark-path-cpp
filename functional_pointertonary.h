//----------------------------------------------------------------------------
#ifndef DARKPATH_functional_pointertonaryH
#define DARKPATH_functional_pointertonaryH
//----------------------------------------------------------------------------
#include "functional_traits.h"
//----------------------------------------------------------------------------
namespace DarkPath
{
    //========================================================================
    /*! @class  pointer_to_n_ary_function
        @brief  Takes a function pointer and makes it into a DarkPath format
                adaptable function object.

        x
    */
    //========================================================================
    template <typename f>
    class pointer_to_n_ary_function
    {
        //--------------------------------------------------------------------
        // Typedefs
        //--------------------------------------------------------------------
        private:
            typedef
                function_traits<f>
                traits;
        public:
            typedef
                typename traits::argument_typelist
                argument_typelist;
            typedef
                typename traits::result_type
                result_type;
            typedef
                typename traits::member_of_type
                member_of_type;
            enum {
                arity = traits::arity
            };
            typedef
                typename traits::argument_type
                argument_type;
            typedef
                typename traits::first_argument_type
                first_argument_type;
            typedef
                typename traits::second_argument_type
                second_argument_type;

        //--------------------------------------------------------------------
        // Data
        //--------------------------------------------------------------------
        private:
            /* compose */
            f   mf_Func;

        //--------------------------------------------------------------------
        // 'structors
        //--------------------------------------------------------------------
        public:
            explicit pointer_to_n_ary_function(f func) :
                mf_Func(func)
            {
            }

        //--------------------------------------------------------------------
        // Methods/Operators
        //--------------------------------------------------------------------
        public:
            result_type operator () () const
            {
                return mf_Func();
            }

            result_type operator () (
                typename argument_typelist::at_nonstrict<0, empty>::result a0
            ) const
            {
                return mf_Func(
                    a0
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1
            ) const
            {
                return mf_Func(
                    a0, a1
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2
            ) const
            {
                return mf_Func(
                    a0, a1, a2
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11, 
                typename argument_typelist::at_nonstrict<12, empty>::result a12
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11, 
                typename argument_typelist::at_nonstrict<12, empty>::result a12, 
                typename argument_typelist::at_nonstrict<13, empty>::result a13
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11, 
                typename argument_typelist::at_nonstrict<12, empty>::result a12, 
                typename argument_typelist::at_nonstrict<13, empty>::result a13, 
                typename argument_typelist::at_nonstrict<14, empty>::result a14
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, 
                    a13, a14
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11, 
                typename argument_typelist::at_nonstrict<12, empty>::result a12, 
                typename argument_typelist::at_nonstrict<13, empty>::result a13, 
                typename argument_typelist::at_nonstrict<14, empty>::result a14, 
                typename argument_typelist::at_nonstrict<15, empty>::result a15
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, 
                    a13, a14, a15
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11, 
                typename argument_typelist::at_nonstrict<12, empty>::result a12, 
                typename argument_typelist::at_nonstrict<13, empty>::result a13, 
                typename argument_typelist::at_nonstrict<14, empty>::result a14, 
                typename argument_typelist::at_nonstrict<15, empty>::result a15, 
                typename argument_typelist::at_nonstrict<16, empty>::result a16
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, 
                    a13, a14, a15, a16
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11, 
                typename argument_typelist::at_nonstrict<12, empty>::result a12, 
                typename argument_typelist::at_nonstrict<13, empty>::result a13, 
                typename argument_typelist::at_nonstrict<14, empty>::result a14, 
                typename argument_typelist::at_nonstrict<15, empty>::result a15, 
                typename argument_typelist::at_nonstrict<16, empty>::result a16, 
                typename argument_typelist::at_nonstrict<17, empty>::result a17
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, 
                    a13, a14, a15, a16, a17
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11, 
                typename argument_typelist::at_nonstrict<12, empty>::result a12, 
                typename argument_typelist::at_nonstrict<13, empty>::result a13, 
                typename argument_typelist::at_nonstrict<14, empty>::result a14, 
                typename argument_typelist::at_nonstrict<15, empty>::result a15, 
                typename argument_typelist::at_nonstrict<16, empty>::result a16, 
                typename argument_typelist::at_nonstrict<17, empty>::result a17, 
                typename argument_typelist::at_nonstrict<18, empty>::result a18
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, 
                    a13, a14, a15, a16, a17, a18
                  );
            }

            result_type operator () (
                
                typename argument_typelist::at_nonstrict<0, empty>::result a0, 
                typename argument_typelist::at_nonstrict<1, empty>::result a1, 
                typename argument_typelist::at_nonstrict<2, empty>::result a2, 
                typename argument_typelist::at_nonstrict<3, empty>::result a3, 
                typename argument_typelist::at_nonstrict<4, empty>::result a4, 
                typename argument_typelist::at_nonstrict<5, empty>::result a5, 
                typename argument_typelist::at_nonstrict<6, empty>::result a6, 
                typename argument_typelist::at_nonstrict<7, empty>::result a7, 
                typename argument_typelist::at_nonstrict<8, empty>::result a8, 
                typename argument_typelist::at_nonstrict<9, empty>::result a9, 
                typename argument_typelist::at_nonstrict<10, empty>::result a10, 
                typename argument_typelist::at_nonstrict<11, empty>::result a11, 
                typename argument_typelist::at_nonstrict<12, empty>::result a12, 
                typename argument_typelist::at_nonstrict<13, empty>::result a13, 
                typename argument_typelist::at_nonstrict<14, empty>::result a14, 
                typename argument_typelist::at_nonstrict<15, empty>::result a15, 
                typename argument_typelist::at_nonstrict<16, empty>::result a16, 
                typename argument_typelist::at_nonstrict<17, empty>::result a17, 
                typename argument_typelist::at_nonstrict<18, empty>::result a18, 
                typename argument_typelist::at_nonstrict<19, empty>::result a19
            ) const
            {
                return mf_Func(
                    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, 
                    a13, a14, a15, a16, a17, a18, a19
                  );
            }

    };

    //========================================================================

    template <typename f, template <typename> class memberPolicy>
    class member_pointer_to_n_ary_function
    {

    };

    //========================================================================
} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

