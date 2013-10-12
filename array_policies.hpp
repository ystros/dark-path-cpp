//----------------------------------------------------------------------------
#ifndef DARKPATH_array_policiesHpp
#define DARKPATH_array_policiesHpp
//----------------------------------------------------------------------------
namespace DarkPath { namespace Policy { namespace Array {

        //====================================================================
        /*  policy
        */
        //====================================================================
        template <unsigned int i>
        struct IndexStartPolicy {
            enum {
                StartingIndex = i
            }
        };

        typedef IndexStartPolicy<0> ZeroBasedIndexPolicy;
        typedef IndexStartPolicy<1> OneBasedIndexPolicy;

        template <typename SizeT,
            typename IndexConstantPolicy = ZeroBasedIndexPolicy>
        struct QuickIndex
        {
            void OnIndex(SizeT& index, SizeT size) throw ()
            {
                index -= IndexConstantPolicy::StartingIndex;
            }
        };

        template <typename SizeT,
            typename IndexConstantPolicy = ZeroBasedIndexPolicy>
        struct SafeExceptionIndex
        {
            void OnIndex(SizeT& index, SizeT size)
                throw (std::out_of_range)
            {
                index -= IndexConstantPolicy::StartingIndex;
                if (index < 0 || index > size)
                {
                    std::ostringstream s;
                    s   << "Policy.SafeExceptionIndex: Index "
                        << index + IndexConstantPolicy::StartingIndex
                        << " is not within bounds ["
                        << IndexConstantPolicy::StartingIndex
                        << ", "
                        << IndexConstantPolicy::StartingIndex + size
                        << "].";
                    throw std::out_of_range(s.str());
                }
            }
        };

        template <typename SizeT,
            typename IndexConstantPolicy = ZeroBasedIndexPolicy>
        struct SafeAssertIndex
        {
            void OnIndex(SizeT& index, SizeT size)
                throw ()
            {
                index -= IndexConstantPolicy::StartingIndex;
                std::assert(0 <= index && index < size);
            }
        };

        template <typename SizeT,
            typename IndexConstantPolicy = ZeroBasedIndexPolicy>
        struct WrapIndex
        {
            void OnIndex(SizeT& index, SizeT size)
                throw ()
            {
                index -= IndexConstantPolicy::StartingIndex;
                index %= size;
            }
        };

        template <typename SizeT,
            typename IndexConstantPolicy = ZeroBasedIndexPolicy>
        struct ResizeIndex
        {
            void OnIndex(SizeT& index, SizeT size)
                throw ()
            {
                index -= IndexConstantPolicy::StartingIndex;
                if (index >= size)
                {
                    // resize(index)
                }
            }
        };

    //====================================================================
    /*  policy group Array.Storage
    */
    //====================================================================
    namespace Storage {
        //====================================================================
        /*  policy Array.Storage.FixedStack
        */
        //====================================================================
        template <typename T, typename WrappedSize>
        class FixedStack;

        template <typename T, unsigned int size>
        class FixedStack< T, WrapU<size> >
        {
            private:
                T               m_b[size];

            private:
                T& getIndex(size_type index)
                {
                    return m_b[index];
                }

                const T& getIndex(size_type index) const
                {
                    return m_b[index];
                }

            public:
                FixedStack()
                {
                }

        };

        //====================================================================
        /*  policy Array.Storage.FixedHeap
        */
        //====================================================================
        template <typename T, typename AllocatorT>
        class FixedHeap
        {
            private:
                T*              m_b;
                size_type       m_sSize;
                allocator_type  m_aAlloc;
            protected:
                T& getIndex(size_type index)
                {
                    return m_b[index];
                }

                const T& getIndex(size_type index) const
                {
                    return m_b[index];
                }

            public:
                explicit FixedHeap(const AllocatorT& alloc = AllocatorT())
                {
                    // COMPILE TIME ERROR
                    BAD!!!!!!!
                }

                explicit FixedHeap(size_type size, const T& val = T(),
                    const AllocatorT& alloc = AllocatorT()) :
                    m_b(0), m_sSize(size), m_aAlloc(alloc)
                {
                    m_b = m_aAlloc.allocate(m_sSize);
                    uninitialized_fill_n(m_b, m_sSize, val);
                }

                ~FixedHeap()
                {
                    for (T* p = m_b;  p != m_e; ++p)
                    {
                        m_aAlloc.destroy(p);
                    }

                    m_aAlloc.deallocate(m_b);
                }
        };

        //====================================================================
        /*  policy Array.Storage.DynamicHeap
        */
        //====================================================================
        template <typename T, typename AllocatorT>
        class DynamicHeap
        {
            private:
                T*              m_b;
                T*              m_e;
                size_type       m_sCapacity;
                allocator_type  m_aAlloc;
            protected:
                T& getIndex(size_type index)
                {
                    return m_b[index];
                }

                const T& getIndex(size_type index) const
                {
                    return m_b[index];
                }

            public:
                explicit DynamicHeap(const AllocatorT& alloc = AllocatorT()) :
                    m_b(0), m_e(0), m_sCapacity(0), m_aAlloc(alloc)
                {
                }

                explicit DynamicHeap(size_type size, const T& val = T(),
                    const AllocatorT& alloc = AllocatorT()) :
                    m_b(0), m_e(0), m_sCapacity(size), m_aAlloc(alloc)
                {
                    m_b = m_aAlloc.allocate(m_sCapacity);
                    m_e = m_b + m_sCapacity;
                    uninitialized_fill_n(m_b, m_sCapacity, val);
                }

                ~DynamicHeap()
                {
                    for (T* p = m_b;  p != m_e; ++p)
                    {
                        m_aAlloc.destroy(p);
                    }

                    m_aAlloc.deallocate(m_b);
                }
            public:
            

        };

        /*
        template <typename T>
        struct DynamicHeapStdAlloc
        {
            typedef DynamicHeap< T, std::allocator<T> >
                    result;
        };
        */
        //============================================================
    } // namespace Storage
} } } // namespace DarkPath.Policy.Array
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

