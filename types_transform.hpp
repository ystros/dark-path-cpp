//----------------------------------------------------------------------------
#ifndef DARKPATH_types_transformHpp
#define DARKPATH_types_transformHpp
//----------------------------------------------------------------------------
namespace DarkPath { namespace Types {

    template <class T>
    struct Identity
    {
        typedef T R;
    };

    template <class T>
    struct QualifyR
    {
        typedef typename T::R R;
    };

} }
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

