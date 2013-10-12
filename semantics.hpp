//----------------------------------------------------------------------------
#ifndef DARKPATH_semanticsH
#define DARKPATH_semanticsH
//----------------------------------------------------------------------------
namespace DarkPath
{

    // Traits
    class NumberInteger {};
    class NumberReal    {};

    // Semantic
    namespace Semantics
    {
        namespace Numeric
        {
            class Percentage    {};
            class Currency      {};
        }

        namespace Functional
        {
            class Counter {};
            class Iterator {};
        }
    }
    class Percentage    {};
    class Range         {};
    class Counter       {};

    template <typename T, typename Semantic>
    struct HasSemantic
    {
        enum { R = false };
    };

    template <>
    struct HasSemantic<int, Numeric::Integer> { enum { R = true; }; };
    template <>
    struct HasSemantic<int, Functional::Counter> { enum { R = true; }; };
    template <>
    struct HasSemantic<int, Numeric::Percentage> { enum { R = true; }; };


    /*
        int sum = 0;
        for (int x = 0; x < 10; ++x)
        {
            sum += x;
        }

        Sum<int> sum = 0;
        for (Counter<int> x(0, 10, 1);  !x.finished(); x.next())
        {
            sum.add(as<Number>(x));
        }

        int s = 0, x = 0;
        for(
            counter(x).start(0);
            counter(x).lessThan(10);
            counter(x).increment())
        {
            sum(s).of(x);
        }

        Counter c = counter().
                        start       (0).
                        finish      (OpenBound(10)).
                        increment   (1);
        Sum<int> sum = initial(0).of(c);
    */

    /* COUNTER
        Relationships
            * GOES from START VALUE to FINISH CONDITION
        Implementation examination
            * MAY be implemented as a rational number
        Implementation requirements
            * MUST be able to increment OR MUST be able to decrement the counter
            * MUST be able to convert to numeric types.

        counter(variable).initialize(startValue);
        counter(variable).increment();
        counter(variable).decrement();
    */
    /* PERCENTAGES
        Relationships
            - Absolute - PART out of WHOLE
            - Relative - CHANGE from VALUE1 to VALUE2
        Implementation examination
            * MAY be implemented as an unbounded real number
            * MAY be implemented as a bounded real number
            * MAY be implemented as a bounded rational number
        Implementation requirements
            * MUST be able to convert to and from fixed or floating point,
              where 1.00 = 100%
            * MAY store whether it is an absolute percentage [0 to 100%] OR a
              relative percentage [- Inf.% to + Inf.%]

        percent(p) = part(3) / whole(4); 3 / 4
        percent(p) = change(1000, 1100); (1100 - 1000) / 1000
        percent(p) = real(0.525);
    */

    template <typename T>
    class PartImpl
    {
        private:
            const T& _part;
        public:
            PartImpl(const T& value) :
                _part(value)
            {
            }

            const T& value() const
            {
                return _part;
            }
    };

    PartImpl<T> part(const T& value)
    {
        return PartImpl<T>(value);
    }

    template <typename T>
    class WholeImpl;

    template <typename T>
    class ChangeImpl
    {
        private:
            const T& _oldValue;
            const T& _newValue;
        public:
            ChangeImpl(const T& oldValue, const T& newValue) :
                _oldValue(oldValue), _newValue(newValue)
            {
            }

            const T& oldValue() const
            {
                return _oldValue;
            }

            const T& newValue() const
            {
                return _newValue;
            }
    };

    template <typename T>
    ChangeImpl<T> change(const T& oldValue, const T& newValue)
    {
        return ChangeImpl<T>(oldValue, newValue);
    }

    template <typename T>
    class PercentImpl
    {
        private:
            T& _value;
        public:
            explicit PercentImpl(T& v) :
                _value(v)
            {
            }

            template <typename U>
            PercentImpl& operator =(const ChangeImpl<U>& ch)
            {
                _value = (ch.newValue() - ch.oldValue()) / ch.oldValue();
                return *this;
            }

            double realValue() const
            {
                return 0.0;
            }

            T value() const
            {
                return _value;
            }
    };

    template <typename T>
    PercentImpl<T> percent(T& value)
    {
        return PercentImpl<T>(value);
    }

    template <typename T, typename U>
    PartImpl<U> operator * (const PercentImpl<T>& p, const WholeImpl<U>& w)
    {
        return PartImpl<U>(p.realValue() * w.value());
    }

    template <typename T, typename U>
    PartImpl<U> operator * (const WholeImpl<U>& w, const PercentImpl<T>& p)
    {
        return PartImpl<U>(p.realValue() * w.value());
    }

    template <typename P, typename T>
    T partPercentOfWhole(const P& percent, const T& whole)
    {
        return T(percent * whole);
    }

    template <typename T>
    class PercentageImpl
    {
        public:
            compile_assert(HasSemantic<T, Numeric::Percentage>::R);

            template <typename U>
            static U convertToReal(const T& orig)
            {
                compile_assert(HasSemantic<U, Numeric::Real>::R);

            }

            template <typename U>
            static T convertFromReal(const U& orig)
            {
                compile_assert(HasSemantic<U, Numeric::Real>::R);

                return T(orig);
            }

            template <typename U>
            static U convertTo(const T& orig)
            {
                compile_assert(HasSemantic<U, Numeric::Percentage>::R);

                return
                    PercentageImpl<U>::convertFromReal(
                        convertToReal<double>(orig)
                    );
            }
    };

    /* ANGLES
        Relationships
            -

        Implementation requirements
            * MUST be able to convert to radians in a 


    */
    //



    template <typename T, T min, T max>
    class Ranged
    {
        private:
            T   value;
    };

    

}
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------

