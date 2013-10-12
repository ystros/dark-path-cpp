//----------------------------------------------------------------------------
#ifndef DARKPATH_utility_inlinecontainerH
#define DARKPATH_utility_inlinecontainerH
//----------------------------------------------------------------------------
#include <vector>
//----------------------------------------------------------------------------
namespace DarkPath
{
    //========================================================================
    template <typename T, typename container>
    class inline_container :
        public container
    {
        public:
            inline_container& operator()(
                const T& a1
            )
            {
                push_back(a1);
                return *this;
            }

            inline_container& operator()(
                const T& a1, const T& a2
            )
            {
                push_back(a1);
                push_back(a2);
                return *this;
            }

//          ...

    };
    //========================================================================
    template <typename T>
    inline_container< T, std::vector<T> > make_vector(const T& a1)
    {
        return
            inline_container< T, std::vector<T> >()(
                a1
            );
    }

    template <typename T>
    inline_container< T, std::vector<T> > make_vector(const T& a1, const T& a2)
    {
        return
            inline_container< T, std::vector<T> >()(
                a1, a2
            );
    }

    // ...
    //========================================================================
}
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

