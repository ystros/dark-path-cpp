//----------------------------------------------------------------------------
#ifndef DARKPATH_functional_naryfunctionH
#define DARKPATH_functional_naryfunctionH
//----------------------------------------------------------------------------
namespace DarkPath
{
    //========================================================================
    /*! @class  n_ary_function
        @brief  Traits class to extract function information.

        Compatible with STL algorithms and adaptors.
    */
    //========================================================================
    template <typename ATL, typename RT, typename MT = void>
    struct n_ary_function
    {
        typedef
            ATL
            argument_typelist;
        typedef
            RT
            result_type;
        enum
        {
            arity = ATL::size
        };
        typedef
            MT
            member_of_type;

        typedef
            typename ATL::at_nonstrict<0, void>::result
            argument_type;

        typedef
            typename ATL::at_nonstrict<0, void>::result
            first_argument_type;

        typedef
            typename ATL::at_nonstrict<1, void>::result
            second_argument_type;
    };
    //========================================================================
} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

