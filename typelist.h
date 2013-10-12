//---------------------------------------------------------------------------
#ifndef DARKPATH_typelistH
#define DARKPATH_typelistH
//---------------------------------------------------------------------------
#include "loki/typelist.h"
//---------------------------------------------------------------------------
namespace DarkPath
{
    namespace LokiTL
    {
        template <typename TL, unsigned int pos, unsigned int len>
        struct TypelistBDIterator
        {
            typedef
                TL
                _loki;

            typedef
                typename ::Loki::TL::TypeAt<_loki, pos>::Result
                deref;

            typedef
                TypelistBDIterator<TL, pos + 1, len>
                next;

            typedef
                TypelistBDIterator<TL, pos - 1, len>
                previous;
        };

        template <typename TL, unsigned int len>
        struct TypelistBDIterator<TL, 0, len>
        {
            typedef
                TL
                _loki;

            typedef
                typename ::Loki::TL::TypeAt<_loki, 0>::Result
                deref;

            typedef
                TypelistBDIterator<TL, 1, len>
                next;
        };

        template <typename TL, unsigned int len>
        struct TypelistBDIterator<TL, len, len>
        {
            typedef
                TL
                _loki;

            typedef
                TypelistBDIterator<TL, len - 1, len>
                previous;
        };

        template <typename TL> struct Head;

        template <typename H, typename T>
        struct Head< ::Loki::Typelist<H, T> >
        {
            typedef
                H
                Result;
        };

        template <typename TL> struct Tail;

        template <typename H, typename T>
        struct Tail< ::Loki::Typelist<H, T> >
        {
            typedef
                T
                Result;
        };

        template <typename TL, unsigned int index>
        struct At
        {
            private:
                typedef
                    typename Tail<TL>::Result
                    _tail;
            public:
                typedef
                    typename At<_tail, index - 1>::Result
                    Result;
        };

        template <typename TL>
        struct At<TL, 0>
        {
            typedef
                typename Head<TL>::Result
                Result;
        };

        template <typename TL, unsigned int index>
        struct SubList
        {
            typedef
                typename SubList<typename TL::Tail, index - 1>::Result
                Result;
        };

        template <unsigned int index>
        struct SubList< ::Loki::NullType, index>
        {
            typedef
                ::Loki::NullType
                Result;
        };

        template <typename TL>
        struct SubList<TL, 0>
        {
            typedef
                TL
                Result;
        };


        template <typename TL>
        struct Last;

        template <typename H, typename T>
        struct Last< ::Loki::Typelist<H, T> >
        {
            typedef
                typename Last<T>::Result
                Result;
        };

        template <typename H>
        struct Last< ::Loki::Typelist<H, ::Loki::NullType> >
        {
            typedef
                H
                Result;
        };
    }

    namespace Private
    {
        class empty_dummy { };
    }

    class empty
    {
        friend class Private::empty_dummy;
        ~empty();
    };

    /*  typelist interface
        All typelists used within the DarkPath library must conform to the
        following interface.

        unsigned integer    size
        bool                empty

        type                front
        type                back

        type method         at<unsigned int index>
        type method         at_nonstrict<unsigned int index>
        type method         erase<unsigned int pos>
        type method         find<type T>
        type method         insert<unsigned int pos, type T>
        type method         pop_back
        type method         pop_front
        type method         push_back<type newType>
        type method         push_front<type newType>
        type method         remove<type T>
        type method         replace<type oldT, type newT>

    */
    template <typename TL>
    struct typelist
    {
        typedef
            TL
            _loki;

        enum
        {
            size  =  ::Loki::TL::Length<_loki>::value,
            empty = (::Loki::TL::Length<_loki>::value == 0)
        };


        typedef
            LokiTL::TypelistBDIterator<_loki, 0, size>
            begin;
        typedef
            LokiTL::TypelistBDIterator<_loki, size, size>
            end;

        template <unsigned int index>
        struct at
        {
            typedef
                typename ::Loki::TL::TypeAt<_loki, index>::Result
                result;
        };

        template <unsigned int index, typename defaultType>
        struct at_nonstrict
        {
            typedef
                typename ::Loki::TL::TypeAtNonStrict<
                    _loki, index, defaultType
                >::Result
                result;
        };

        struct back
        {
            typedef
                typename LokiTL::Last<_loki>::Result
                result;
        };

        template <typename value, unsigned int pos = 0>
        struct find
        {
            enum {
                result =
                    ::Loki::TL::IndexOf<
                        typename LokiTL::SubList<_loki, pos>::Result, value
                    >::value
            };
        };

        struct front
        {
            typedef
                typename LokiTL::Head<_loki>::Result
                result;
        };

        template <typename T>
        struct push_back
        {
            typedef
                typelist<typename ::Loki::TL::Append<_loki, T>::Result>
                result;
        };

        template <typename T>
        struct push_front
        {
            typedef
                typelist< ::Loki::Typelist<T, _loki> >
                result;
        };

        template <typename oldvalue, typename newvalue>
        struct replace
        {

        };
    };

    typedef typelist< ::Loki::NullType >
        NULL_typelist;


} // namespace DarkPath
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------


