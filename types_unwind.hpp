//----------------------------------------------------------------------------
#ifndef DARKPATH_types_unwindHpp
#define DARKPATH_types_unwindHpp
//----------------------------------------------------------------------------
namespace DarkPath { namespace Types {

#   ifdef DP_COMPAT_partial_template_specialization
    template <class T>
    struct Unwind
    {
        typedef T R;
    };

#   else
#       error DarkPath.Types.Unwind can only be used if your compiler supports partial template specialization. 
#   endif

} } // namespace DarkPath.Types
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

