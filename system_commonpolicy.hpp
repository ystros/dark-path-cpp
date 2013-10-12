//----------------------------------------------------------------------------
#ifndef DARKPATH_system_commonpolicyHpp
#define DARKPATH_system_commonpolicyHpp
//----------------------------------------------------------------------------
namespace DarkPath
{
    namespace Policy
    {
        //====================================================================
        /*  policy group Copy
        */
        //====================================================================
        namespace Copy
        {
            //================================================================
            /*  policy NoCopy
            */
            //================================================================
            template <typename T>
            struct NoCopy
            {
                static void copy(const T& origObj, const T& newObj)
                {
                }
            };

            //================================================================
            /*  policy CopyAssign
            */
            //================================================================
            template <typename T>
            struct CopyAssign
            {
                static void copy(T origObj, T& newObj)
                {
                    newObj = origObj;
                }
            };

            template <typename T>
            struct CopyAssign<T*>
            {
                static void copy(const T* origObj, T*& newObj)
                {
                    newObj = new T(*origObj);
                }
            };

            //================================================================
            /*  policy Clone
            */
            //================================================================
            template <typename T>
            struct Clone;

            template <typename T>
            struct Clone<T*>
            {
                static void copy(const T* origObj, T*& newObj)
                {
                    newObj = origObj->clone();
                }
            };
            
            //================================================================
        } // namespace Copy

        //====================================================================
    } // namespace Policy
} // namespace DarkPath
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
