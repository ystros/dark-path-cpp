//----------------------------------------------------------------------------
#ifndef DARKPATH_graphics_colorH
#define DARKPATH_graphics_colorH
//----------------------------------------------------------------------------
namespace DarkPath
{
    //========================================================================
    /*

    */
    template <unsigned int bits>
    class integer
    {
    };

    template <class ComponentClass, class ValueType>
    class Component
    {
        public:
            typedef ValueType value_type;
        public:

    };

    template <typename ComponentClassTL>
    class ColorComponentModel
    {
    };

    template <typename Model>
    class ColorImplementation
    {
    };

    class Win32_COLORREF
    {
        public:
            typedef ModelRGB    ComponentModel;
    };


    // RGB
    class Red {};
    class Green {};
    class Blue {};

    typedef ColorComponentModel< TYPELIST_3(Red, Green, Blue) >
            ModelRGB;



    // HSV
    class Hue {};
    class Saturation {};
    class Value {};

    typedef ColorComponentModel< TYPELIST_3(Hue, Saturation, Value) >
            HSV;



    // CMYK
    class Cyan {};
    class Magenta {};
    class Yellow {};
    class Black {};

    // Alpha
    class Alpha {};

    template <typename ImplB, typename ImplA>
    ImplB convertTo(const ImplA& orig)
    {
        typedef typename ImplA::ComponentModel ComponentModelA;
        typedef typename ImplB::ComponentModel ComponentModelB;

        return convertTo<ImplB>(orig, ComponentModelA(), ComponentModelB());
    }

    template <typename ImplB, typename ImplA, typename ModelA, typename ModelB>
    ImplB convertTo(const ImplA& orig, RGB, HSV)
    {
        using ImplA::ComponentType<Red>::Result     RedT;
        using ImplA::ComponentType<Green>::Result   GreenT;
        using ImplA::ComponentType<Blue>::Result    BlueT;

        ImplB res;

        RedT    r = orig.get<Red>();
        GreenT  g = orig.get<Green>();
        BlueT   b = orig.get<Blue>();

        maxComponent = max(max(r, g), b);
        minComponent = min(min(r, g), b);

        res.set(Value, maxComponent);

        if (maxComponent != 0.0)
        {
            res.set(Saturation, (maxComponent - minComponent) / maxComponent);
        } else
        {
            res.set(Saturation, 0);
            res.set(Hue, 0);
            return res;
        }

        return res;
    }

    // Paletized - n bits
    // RGB Color - 16 bits
    // RGB Color - 32 bits

    //========================================================================
}
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

