//----------------------------------------------------------------------------
#ifndef DARKPATH_types_bindHpp
#define DARKPATH_types_bindHpp
//----------------------------------------------------------------------------
#include "types_wrap.hpp"
//----------------------------------------------------------------------------
namespace DarkPath { namespace Types {
    //========================================================================
    /* type function Bind
    */
    //========================================================================
    template <unsigned int Pos, class Temp, class Param>
    struct Bind;

    template <template <class> class Temp, class Param>
    struct Bind<0, Wrap::T1<Temp>, Param>
    {
        typedef Temp<Param> R;
    };

    template <template <class> class Temp, template <class> class Param>
    struct Bind<0, Wrap::T1<Temp>, Param>
    {
        template <class T>
        struct R
        {
            typedef Temp<typename Unwind< Param<T> >::R>
                    R;
        };
        typedef Wrap::T1<R> wrapped;
    };

    template <template <class> class Temp, template <class, class> class Param>
    struct Bind<0, Wrap::T1<Temp>, Param>
    {
        template <class T, class U>
        struct R
        {
            typedef Temp<typename Unwind< Param<T, U> >::R>
                    R;
        };
        typedef Wrap::T2<R> wrapped;
    };



    template <unsigned int p1, unsigned int p2, class A>
    struct UnifyParam;

    template <template <class, class> class A>
    struct UnifyParam< 0, 1, Wrap::T2<A> >
    {
        template <typename T> struct result
        {   typedef A<T, T> result;    };
    };

    /*
        // define DynamicHeapStdAlloc<T> = DynamicHeap<T, std::allocator<T>>;
        typedef
            UnifyParam<0, 1,
                Bind<1, Wrap::T2<DynamicHeap>, Wrap::T1<std::allocator> >::wrapped
            >::result
            DynamicHeapStdAlloc;
    */

    template <unsigned int i, typename A, typename B>
    struct Unwind< Bind<i, A, B> >
    {
        typedef typename Unwind< typename Bind<i, A, B>::result >::result
                result;
    };

    template <unsigned int i, typename A, typename B, typename T>
    struct Unwind< typename Bind<i, A, B>::template result_intermediate<T> >
    {
        typedef
            typename Unwind<
                typename Bind<i, A, B>::template result_intermediate<T>::result
            >::result
            result;
    };

    template <unsigned int i, typename A, typename B, typename T, typename U>
    struct Unwind< typename Bind<i, A, B>::template result_intermediate<T, U> >
    {
        typedef
            typename Unwind<
                typename Bind<i, A, B>::template
                    result_intermediate<T, U>::result
            >::result
            result;
    };
    
    //========================================================================
    template <class T>
    struct Rebind;

    template <template <class> class Template, class T>
    struct Rebind< Template<T> >
    {
        template <class T2>
        struct Param1
        {
            typedef Template<T2> R;
        };
    };

    template <template <class, class> class Template, class T, class U>
    struct Rebind< Template<T, U> >
    {
        template <class T2>
        struct Param1
        {
            typedef Template<T2, U> R;
            typedef Rebind<R>       and;
        };

        template <class U2>
        struct Param2
        {
            typedef Template<T, U2> R;
            typedef Rebind<R>       and;
        };
    };
/*
    typename
        Rebind< std::pair<bool, int> >::
          Param1<int>::and::
          Param2<bool>::R
*/

} } // namespace DarkPath.Types
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

