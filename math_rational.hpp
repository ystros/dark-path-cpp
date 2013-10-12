//----------------------------------------------------------------------------
#ifndef DARKPATH_math_rationalHpp
#define DARKPATH_math_rationalHpp
//----------------------------------------------------------------------------
#include "traits_math.hpp"
//----------------------------------------------------------------------------
namespace DarkPath { namespace Math {

    template <typename T>
    T lcd(T a, T b)
    {
        if (a % b == 0)
        {
            return a;
        } else if (b % a == 0)
        {
            return b;
        }

    }

    template <typename T, typename II, typename f>
    T fold(II b, II e, T value, f func)
    {
        while (b != e)
        {
            value = func(value, *b);
            ++b;
        }

        return value;
    }

    template <typename T>
    class PrimeGenerator
    {
        private:
            std::vector<T>  _primes;
            T               _lastValue;

        private:

        bool isNextPrime(T value) const
        /*
                        comparisons     arithmatic
            efficiency  O()             O()
        */
        {
            using std::vector<T>::const_iterator;

            if (value % 2 == 0)
            {
                return false;
            }

            for (
                const_iterator i = _primes.begin();
                i != _primes.end() && (*i <= (value / *i));
                ++i
            )
            {
                if (value % *i == 0)
                    return false;
            }

            return true;
        }

        public:
            PrimeGenerator(T start = 1) :
                _primes(), _lastValue((start < 1) ? 1 : start)
            {
            }

        public:
            T next()
            {
                if (_lastValue == 1)
                {
                    _lastValue += 2;
                    return 2;
                }

                while (!isNextPrime(_lastValue))
                {
                    _lastValue += 2;
                }
            }

    };

    template <typename T, typename M>
    void factor(T value, M& f)
    {
        PrimeGenerator<T> primes;
        T curPrime = primes.next();

        while (curPrime < value)
        {
            if (value % curPrime == 0)
            {
                value /= curPrime;
                ++f[curPrime];
            } else
            {
                curPrime = primes.next();
            }
        }
    }

    template <typename T, typename M>
    T gcf(T a, T b, M& f)
    {
        M factorsA, factorsB;
        T commonFactor = 1;

        factor(a, factorsA);
        factor(b, factorsB);

        // Intersection
        for (M::iterator i = factorsA.begin(); i != factorsA.end(); ++i)
        {
            M::iterator j = factorsB.find(i->first);
            if (j != factorsB.end())
            {
                T power       = min(i->second, j->second);
                f[i->first]   = power;
                commonFactor *= pow(i->first, power);
            }
        }

        return commonFactor;
    }

    template <typename T>
    class Rational
    {
        public:
            typedef T value_type;
        private:
            value_type _numerator;
            value_type _denominator;
        public:
            Rational() :
                _numerator(0), _denominator(1)
            {
            }

            Rational(value_type numerator, value_type denominator) :
                _numerator(numberator), _denominator(denominator)
            {
                simplify();
            }

            Rational(const Rational& orig) :
                _numerator(orig._numerator), _denominator(orig._denominator)
            {
            }

            template <typename copy_value_type>
            Rational(const Rational<copy_value_type>& orig) :
                _numerator(orig._numerator), _denominator(orig._denominator)
            {
            }

            Rational& operator = (const Rational& rhs)
            {
                _numerator   = rhs._numerator;
                _denominator = rhs._denominator;
                return *this;
            }

            template <typename copy_value_type>
            Rational& operator = (const Rational<copy_value_type>& rhs)
            {
                _numerator   = rhs._numerator;
                _denominator = rhs._denominator;
                return *this;
            }

        private:
            bool valid() const
            {
                const bool positiveDenominator = (_denominator > 0);
                
                return positiveDenominator;
            }

            void simplify()
            {
                if (_numerator == 0)
                {
                    _denominator = 1;
                    return;
                }

                if (_denominator < 0)
                {
                    _denominator *= -1;
                    _numerator   *= -1;
                }

                const value_type commonFactor = gcf(_numerator, _denominator);

                _numerator   /= commonFactor;
                _denominator /= commonFactor;
            }

        public:
            Rational& operator += (const Rational& rhs)
            {
                const value_type commonDenom =
                    lcd(_denominator, rhs._denominator);
                const value_type scaleLHS = commonDenom / _denominator;
                const value_type scaleRHS = commonDenom / rhs._denominator;

                _numerator   = _numerator * scaleLHS + rhs._numerator * scaleRHS;
                _denominator = commonDenom;

                simplify();

                return *this;
            }

            Rational& operator -= (const Rational& rhs)
            {
                const value_type commonDenom =
                    lcd(_denominator, rhs._denominator);
                const value_type scaleLHS = commonDenom / _denominator;
                const value_type scaleRHS = commonDenom / rhs._denominator;

                _numerator   = _numerator * scaleLHS - rhs._numerator * scaleRHS;
                _denominator = commonDenom;

                simplify();

                return *this;
            }

            Rational& operator *= (const Rational& rhs)
            {
                _numerator   *= rhs._numerator;
                _denominator *= rhs._denominator;

                simplify();

                return *this;
            }

            Rational& operator /= (const Rational& rhs)
            {
                _numerator   *= rhs._denominator;
                _denominator *= rhs._numerator;

                simplify();

                return *this;
            }

            Rational& operator %= (const Rational& rhs)
            {
                const value_type commonDenom =
                    lcd(_denominator, rhs._denominator);
                const value_type scaleLHS = commonDenom / _denominator;
                const value_type scaleRHS = commonDenom / rhs._denominator;

                _numerator   = _numerator * scaleLHS % rhs._numerator * scaleRHS;
                _denominator = commonDenom;

                simplify();

                return *this;
            }

        public:
            template <typename out_stream>
            out_stream& output(out_stream& out) const
            {
                return (out << _numerator << "/" << _denominator);
            }
    };

    template <typename T>
    Rational<T> operator + (Rational<T> lhs, const Rational<T>& rhs)
    {
        return lhs += rhs;
    }

    template <typename T>
    Rational<T> operator - (Rational<T> lhs, const Rational<T>& rhs)
    {
        return lhs -= rhs;
    }

    template <typename T>
    Rational<T> operator * (Rational<T> lhs, const Rational<T>& rhs)
    {
        return lhs *= rhs;
    }

    template <typename T>
    Rational<T> operator / (Rational<T> lhs, const Rational<T>& rhs)
    {
        return lhs /= rhs;
    }

    template <typename T>
    Rational<T> operator % (Rational<T> lhs, const Rational<T>& rhs)
    {
        return lhs %= rhs;
    }
    template <typename T>
    std::ostream& operator << (std::ostream& out, const Rational<T>& r)
    {
        return r.output(out);
    }

} // namespace DarkPath.Math

namespace Traits { namespace Math {

    template <typename T>
    struct IsSignedType< Rational<T> >
    { enum { value = IsSignedType<T>::value }; };

} } } // namespace DarkPath.Traits.Math
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
