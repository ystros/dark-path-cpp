//----------------------------------------------------------------------------
#ifndef DARKPATH_functional_binderH
#define DARKPATH_functional_binderH
//----------------------------------------------------------------------------
#include "functional_traits.h"
//----------------------------------------------------------------------------
namespace DarkPath
{
    template <typename FT, typename AT, unsigned int argIndex>
    class function_binder;

    template <typename FT, typename AT>
    class function_binder<FT, AT, 1>
    {
        //--------------------------------------------------------------------
        // Typedefs
        //--------------------------------------------------------------------
        private:
            typedef
                function_traits<FT>
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
            typedef
                AT
                stored_argument_type;
            typedef
                FT
                function_type;

        //--------------------------------------------------------------------
        // Data
        //--------------------------------------------------------------------
        private:
            /* compose */
            function_type           m_fImpl;
            stored_argument_type    m_saArg;

        //--------------------------------------------------------------------
        // 'structors
        //--------------------------------------------------------------------
        public:
            function_binder(function_type func, stored_argument_type arg) :
                m_fImpl(func), m_saArg(arg)
            {
            }

        //--------------------------------------------------------------------
        // Method/Operators
        //--------------------------------------------------------------------
        public:
            result_type operator()()
            {
                return m_fImpl(m_saArg);
            }

            result_type operator()(
                typename argument_typelist::at_nonstrict<1, empty>::result a1
            )
            {
                return m_fImpl(m_saArg, a1);
            }

            result_type operator()(
                typename argument_typelist::at_nonstrict<1, empty>::result a1,
                typename argument_typelist::at_nonstrict<1, empty>::result a2
            )
            {
                return m_fImpl(m_saArg, a1, a2);
            }
    };

/*
    namespace Private
    {
        template <int n, typename f, template <typename> typename storage>
        struct GetBinderStoredType
        {
            typedef
                typename
                ::Loki::TL::TypeAt<typename f::argument_typelist, 0>::Result
                argument_type;
            typedef
                typename storage<argument_type>::result
                stored_type;
        };
    }

*/
}
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

