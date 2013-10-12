//----------------------------------------------------------------------------
#ifndef DARKPATH_type_algorithmHpp
#define DARKPATH_type_algorithmHpp
//----------------------------------------------------------------------------
#define DP_TYPEIF(c, t, u) DarkPath::type::t_if<(c), t, u >::result
//----------------------------------------------------------------------------
namespace DarkPath
{
    namespace type
    {
        //====================================================================
        /*  type function t_if

        */
        //====================================================================
        template <bool condition, typename T, typename U>
        struct t_if
        {
            typedef T result;
        };

        template <typename T, typename U>
        struct t_if<false, T, U>
        {
            typedef U result;
        };

        //====================================================================
        /*  type function rebind
        */
        //====================================================================
        template <typename Orig, unsigned int index, typename T>
        struct rebind;

        template <template <class> class Temp, typename OldT, typename NewT>
        struct rebind< Temp<OldT>, 0, NewT >
        {   typedef typename Temp<NewT> result; };

        template <template <class, class> class Temp, typename T1, typename T2,
            typename NewT>
        struct rebind< Temp<T1, T2>, 0, NewT >
        {   typedef typename Temp<NewT, T2> result; };

        template <template <class, class> class Temp, typename T1, typename T2,
            typename NewT>
        struct rebind< Temp<T1, T2>, 1, NewT >
        {   typedef typename Temp<T1, NewT> result; };

        template <template <class, class, class> class Temp,
            typename T1, typename T2, typename T3,
            typename NewT
        >
        struct rebind< Temp<T1, T2, T3>, 0, NewT >
        {   typedef typename Temp<NewT, T2, T3> result; };

        template <template <class, class, class> class Temp,
            typename T1, typename T2, typename T3,
            typename NewT
        >
        struct rebind< Temp<T1, T2, T3>, 1, NewT >
        {   typedef typename Temp<T1, NewT, T3> result; };

        template <template <class, class, class> class Temp,
            typename T1, typename T2, typename T3,
            typename NewT
        >
        struct rebind< Temp<T1, T2, T3>, 2, NewT >
        {   typedef typename Temp<T1, T2, NewT> result; };


        //====================================================================
        /*  type algorithm for_each
            Input:
                type iterator           InIterB
                type iterator           InIterE
                type iterator           OutIter
                type function 1-arity   Operation
        */
        //====================================================================
        template <typename IterB, typename IterE, typename Typelist,
            template <typename> class Operation>
        struct for_each
        {
            typedef
                typename IterB::next
                IterNext;
            typedef
                typename Operation<typename IterB::deref>::Result
                CurResult;
            typedef
                typename Typelist::template push_back<CurResult>::result
                CurTypelist;

            typedef
                typename for_each<IterNext, IterE, CurTypelist, Operation>::result
                result;
        };

        template <typename IterE, typename Typelist,
            template <typename> class Operation>
        struct for_each<IterE, IterE, Typelist, Operation>
        {
            typedef
                Typelist
                result;
        };

        //====================================================================
        /*  type algorithm reverse

        */
        //====================================================================
        template <typename IterB, typename IterE, typename Typelist>
        struct reverse
        {
            typedef
                typename IterB::next
                IterNext;
            typedef
                typename Typelist::template push_front<typename IterB::deref>::result
                current_typelist;

            typedef
                typename reverse<IterNext, IterE, current_typelist>::result
                result;
        };

        template <typename IterE, typename Typelist>
        struct reverse<IterE, IterE, Typelist>
        {
            typedef
                Typelist
                result;
        };

    } // namespace type
} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

