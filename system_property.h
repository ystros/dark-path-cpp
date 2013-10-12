//----------------------------------------------------------------------------
#ifndef DARKPATH_system_propertyH
#define DARKPATH_system_propertyH
//----------------------------------------------------------------------------
//#include "functional_naryfunctioninterface.h"
//----------------------------------------------------------------------------
namespace DarkPath
{
    template <
        typename T,
        typename GetType = n_ary_function_interface<NULL_typelist, T>,
        typename SetType = n_ary_function_interface<TYPELIST_1(const T&), void>
    >
    class property
    {
        //--------------------------------------------------------------------
        // Typedefs
        //--------------------------------------------------------------------
        public:
            typedef
                typename n_ary_function_interface<ATL, RT>*
                event_type;
            typedef
                GetType
                getter_function_type;
            typedef
                SetType
                setter_function_type;

        //--------------------------------------------------------------------
        // Data
        //--------------------------------------------------------------------
        protected:
            getter_function_type*   m_gfGetter;
            setter_function_type*   m_sfSetter;
            //std::list<event_type>   mlstEvents;
            // Priority queue?

        //--------------------------------------------------------------------
        // 'structors
        //--------------------------------------------------------------------

        //--------------------------------------------------------------------
        // Methods
        //--------------------------------------------------------------------
        public:
            typename getter_function_type::result_type get() const
            {
                return (*m_gfGetter)();
            }

            typename setter_function_type::result_type set(
                typename setter_function_type::argumnet_typelist::at<0>::result
                newValue
            )
            {
                return (*m_sfSetter)(newValue);
            }

    };
    //========================================================================
} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
