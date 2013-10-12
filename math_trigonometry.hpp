//----------------------------------------------------------------------------
#ifndef DARKPATH_math_trigonometryHpp
#define DARKPATH_math_trigonometryHpp
//----------------------------------------------------------------------------
namespace DarkPath { namespace Math {

template <typename T, typename CoefficientII, typename PowerII>
T taylor_series(CoefficientII bCo, CoefficientII eCo, PowerII bPo, PowerII ePo,
    const T& value)
/*
    result = sum (co = bCo to eCo, po = bPo to ePo) co * (value ^ po);
*/
{
    assert(distance(bCo, eCo) <= distance(bPo, ePo));

    if (bCo == eCo)
    {
        return 0;
    }

    T result = 0;

    while (bCo != eCo)
    {
        result += (*bCo) * pow(value, *bPo);
        ++bPo;
        ++bCo;
    }

    return result;
}

template <typename T>
T sin(const T& x)
{
    require(!IsIntegerType<T>::value);
}

} } // namespace DarkPath.Math
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
