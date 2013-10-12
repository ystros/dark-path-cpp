//----------------------------------------------------------------------------
#ifndef DARKPATH_system_interfacesHpp
#define DARKPATH_system_interfacesHpp
//----------------------------------------------------------------------------
namespace DarkPath
{
    namespace System
    {
        //====================================================================
        /*
        */
        //====================================================================
//        template <typename T>
        class Identity // ???????
        {
            public:
                virtual ~Identity();
            public:
                virtual bool identity(Identity& rhs)
                {
                    return (this == &rhs);
                }
        };

        template <typename T>
        class Equatable
        {
            public:
                virtual ~Equatable();
            public:
                virtual bool equals(const T&) = 0;

                bool operator == (const T& rhs)
                {
                    return equals(rhs);
                }

                bool operator != (const T& rhs)
                {
                    return !equals(rhs);
                }
        };

        template <typename T, typename CompareResultT>
        class Comparable : virtual public Equatable<T>
        {
            public:
                typedef
                    CompareResultT
                    compare_result_type;
            public:
                virtual ~Comparable();

            public:
                virtual compare_result_type compare(const T&) = 0;

                virtual bool lessThan(const T& rhs)
                {
                    return compare(rhs) < 0;
                }

                virtual bool greaterThan(const T& rhs)
                {
                    return compare(rhs) > 0;
                }

                bool operator < (const T& rhs)
                {
                    return compare(rhs) < 0;
                }

                bool operator <= (const T& rhs)
                {
                    return compare(rhs) <= 0;
                }

                bool operator > (const T& rhs)
                {
                    return compare(rhs) > 0;
                }

                bool operator < (const T& rhs)
                {
                    return compare(rhs) >= 0;
                }
        };

        template <typename T, typename SizeT>
        class Indexable
        {
            public:
                virtual ~Indexable();

            public:
                virtual T& at(SizeT index) = 0;
                virtual const T& at(SizeT index) const = 0;

                T& operator [] (SizeT index)
                {
                    return at(index);
                }

                const T& operator [] (SizeT index) const
                {
                    return at(index);
                }
        };

        //====================================================================
    } // namespace System
} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
