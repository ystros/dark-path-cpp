//----------------------------------------------------------------------------
#ifndef DARKPATH_types_wrapHpp
#define DARKPATH_types_wrapHpp
//----------------------------------------------------------------------------
#include "types_unwind.hpp"
#include "types_transform.hpp"
//----------------------------------------------------------------------------
namespace DarkPath { namespace Types {
    //========================================================================
    //========================================================================
    namespace Wrap {
        template <int t> struct I
        {
            enum { R = t };
        };

        template <unsigned int t> struct U
        {
            enum { R = t };
        };

        template <template <class> class A,
            template <class> class Op = Identity>
        struct T1
        {
            template <class P1>
            struct T
            {
                typedef typename Op< A<P1> >::R R;
            };
        };

        template <template <class, class> class A,
            template <class> class Op = Identity>
        struct T2
        {
            template <class P1, class P2>
            struct T
            {
                typedef typename Op< A<P1, P2> >::R R;
            };
        };

        template <template <class, class, class> class A,
            template <class> class Op = Identity>
        struct T3
        {
            template <class P1, class P2, class P3>
            struct T
            {
                typedef typename Op< A<P1, P2, P3> >::R R;
            };
        };

        template <template <class, class, class, class> class A,
            template <class> class Op = Identity>
        struct T4
        {
            template <class P1, class P2, class P3, class P4>
            struct T
            {
                typedef typename Op< A<P1, P2, P3, P4> >::R R;
            };
        };

        template <template <class, class, class, class, class> class A,
            template <class> class Op = Identity>
        struct T5
        {
            template <class P1, class P2, class P3, class P4, class P5>
            struct T
            {
                typedef typename Op< A<P1, P2, P3, P4, P5> >::R R;
            };
        };

    } // namespace Wrap


#if defined(DP_COMPAT_partial_template_specialization) && \
    defined(DP_COMPAT_nested_keyword_template)

    template <template <class> class A, template <class> class Op, class P1>
    struct Unwind< typename Wrap::T1<A, Op>::template T<P1> >
    {
        typedef typename Wrap::T1<A, Op>::template T<P1>::R
                temp;
        typedef int //typename Unwind<temp>::R
                R;
    };
#endif

    //========================================================================
} } // namespace DarkPath.Types
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

