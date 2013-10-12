//----------------------------------------------------------------------------
#ifndef DARKPATH_vectorHpp
#define DARKPATH_vectorHpp
//----------------------------------------------------------------------------
#include <sstream>
//----------------------------------------------------------------------------
namespace DarkPath {
    //========================================================================
    /*
        Vector of T
        Indexing constants
            start  - default 0
            max    - ???
        Indexing policy
            quick  - no range check
            safe   - check range, throw on out of bounds
            wrap   - check range, newIndex = (index % size + start)
            resize - check range, if over then resize.
        Sizing policy
            fixed   - cannot resize after initial allocation
            sizable - can resize
        Allocator
    */
    template <
        typename T,
        template <typename> class StoragePolicy,
        template <typename> class IndexPolicy
    >
    class Array :
        public StoragePolicy<T>,
        public Indexable<T, typename StoragePolicy<T>::size_type>
    {
        public:
            typedef
                typename StoragePolicy< T, SizeT, AllocatorT<T> >
                storage_policy;
            typedef
                typename IndexPolicy<SizeT>
                index_policy;
            typedef
                SizeT
                size_type;

        public:
            explicit Array(const allocator_type& alloc = allocator_type()) :
                storage_policy(alloc)
            {
            }

            explicit Array(size_type num, const T& val = T(),
                const allocator_type& alloc = allocator_type()) :
                storage_policy(num, val, alloc)
            {
            }

            ~Array()
            {
            }

        public:
            Array& assign(Array rhs)
            {
                swap(rhs);
                return (*this);
            }

            virtual T& at(SizeT index)
            {
                index_policy::OnIndex(*this, index, size());
                return getIndex(index);
            }

            virtual const T& at(SizeT index) const
            {
                index_policy::OnIndex(*this, index, size());
                return getIndex(index);
            }
    };

    //========================================================================
}
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

