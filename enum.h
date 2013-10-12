//----------------------------------------------------------------------------
#ifndef DARKPATH_enumH
#define DARKPATH_enumH
//----------------------------------------------------------------------------
namespace DarkPath
{
    //========================================================================
    /*

    */

    template <typename T>
    class InputIterator
    {
        public:
            virtual ~InputIterator();    
        public:
            virtual InputIterator& nextValue() = 0;
            virtual T& deref() = 0;
            virtual const T& deref() const = 0;
    };

    template <typename T>
    class Enumeration
    {
        private:
        public:

    };

    template <typename T>
    class Enumerable
    {
        public:
            virtual T& nextValue() = 0;
            virtual T& prevValue() = 0;

            T& operator ++()
            {
                return nextValue();
            }

            T operator ++(int)
            {
                T x = *this;
                nextValue();
                return x;
            }

            T& operator --()
            {
                return prevValue();
            }

            T operator --(int)
            {
                T x = *this;
                prevValue();
                return x;
            }
    };

    template <typename T, typename S>
    class enumeration
    {
        public:
            typedef T   stored_type;
            typedef S   string_type;
        public:

    };

    template <typename ET>
    class enumerable_type
    {

    };


    //========================================================================
}
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

