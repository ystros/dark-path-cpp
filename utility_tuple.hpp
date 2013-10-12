//----------------------------------------------------------------------------
#ifndef DARKPATH_utility_tupleHpp
#define DARKPATH_utility_tupleHpp
//----------------------------------------------------------------------------
namespace DarkPath
{
    template <typename TL>
    class tuple;

    template <typename TL, unsigned int size>
    class tuple_impl :
        public tuple_impl<
            typename TL::pop_front::result::pop_front::result
                       ::pop_front::result::pop_front::result,
            size - 4
        >
    {
        //--------------------------------------------------------------------
        // Typedefs
        //--------------------------------------------------------------------
        public:
            typedef
                typename  TL::pop_front::result
                            ::pop_front::result
                            ::pop_front::result
                            ::pop_front::result
                remaining_typelist;
            typedef
                typename tuple_impl<remaining_typelist, size - 4>
                parent_type;

        //--------------------------------------------------------------------
        // Data
        //--------------------------------------------------------------------
//        private:
        public:
            typename TL::at<0>::result  m_0;
            typename TL::at<1>::result  m_1;
            typename TL::at<2>::result  m_2;
            typename TL::at<3>::result  m_3;
    };

    template <typename TL>
    class tuple_impl : public tuple_impl<TL, 1>
    {
        //--------------------------------------------------------------------
        // Data
        //--------------------------------------------------------------------
        public:
            typename TL::at<0>::result  m_0;
    };

    template <typename TL>
    class tuple_impl : public tuple_impl<TL, 2>
    {
        //--------------------------------------------------------------------
        // Data
        //--------------------------------------------------------------------
        public:
            typename TL::at<0>::result  m_0;
            typename TL::at<1>::result  m_1;
    };

    template <typename TL>
    class tuple_impl : public tuple_impl<TL, 3>
    {
        //--------------------------------------------------------------------
        // Data
        //--------------------------------------------------------------------
        public:
            typename TL::at<0>::result  m_0;
            typename TL::at<1>::result  m_1;
            typename TL::at<2>::result  m_2;
    };

    template <typename TL>
    class tuple_impl : public tuple_impl<TL, 4>
    {
        //--------------------------------------------------------------------
        // Data
        //--------------------------------------------------------------------
        public:
            typename TL::at<0>::result  m_0;
            typename TL::at<1>::result  m_1;
            typename TL::at<2>::result  m_2;
            typename TL::at<3>::result  m_3;
    };

    template <typename TL>
    class tuple
    {
        public:
            template <unsigned int index>
            typename TL::at<index>::result& at()
            {
                if (index > 3)
                {
                    return m_impl
                }
            }
    };


} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

