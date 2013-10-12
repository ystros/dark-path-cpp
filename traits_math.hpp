//----------------------------------------------------------------------------
#ifndef DARKPATH_traits_mathHpp
#define DARKPATH_traits_mathHpp
//----------------------------------------------------------------------------
namespace DarkPath { namespace Traits { namespace Math {



template <typename T>
struct IsIntegerType { enum { value = 0 }; };

template <>
struct IsIntegerType<int> { enum { value = 1 }; };
template <>
struct IsIntegerType<unsigned int> { enum { value = 1 }; };

template <typename T>
struct IsSignedType         { enum { value = 0 }; };
template <>
struct IsSignedType<int>    { enum { value = 1 }; };
template <>
struct IsSignedType<float>  { enum { value = 1 }; };
template <>
struct IsSignedType<double> { enum { value = 1 }; };

} } } // namespace DarkPath.Traits.Math
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------