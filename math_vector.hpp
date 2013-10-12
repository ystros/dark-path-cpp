//----------------------------------------------------------------------------
#ifndef DARKPATH_math_vectorHpp
#define DARKPATH_math_vectorHpp
//----------------------------------------------------------------------------
namespace DarkPath { namespace Math {

template <typename T, unsigned int dimensions>
class Vector
{
    public:
        typedef T               value_type;
        typedef unsigned int    dimensions_type;
    private:
        T* _components;
    public:

        Vector& normalize()
        {
            return (*this /= magnitude());
        }

        value_type magnitude() const
        {
            value_type value;

            for (unsigned int i = 0; i < dimensions; ++i)
            {
                value += _components[i] * _components[i];
            }

            return sqrt(value);
        }

        value_type dot(const Vector& rhs) const
        {
            T value;

            for (unsigned int i = 0; i < dimensions; ++i)
            {
                value += _components[i] * rhs._components[i];
            }

            return value;
        }
};

template <typename T>
Vector<T, 2> normal(const Vector<T, 2>& orig)
{
    return Vector<T, 2>(orig[1], -orig[0]);
}

template <typename T>
Vector<T, 3> cross(const Vector<T, 3>& lhs, const Vector<T, 3>& rhs)
{
    Vector<T, 3> result;

    result[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
    result[1] = lhs[0] * rhs[2] - lhs[2] * rhs[0];
    result[2] = lhs[1] * rhs[0] - lhs[0] * rhs[1];

    return result;
}

template <typename T, unsigned int m, unsigned int n>
class Matrix
{
    private:
        // Storage
    public:
        Matrix()
        {
        }
};

template <typename T, unsigned int m, unsigned int n, unsigned m2>
Matrix<T, m, m2> operator * (const Matrix<T, m, n>& lhs, const Matrix<T, m2, m>& rhs)
{
}

} } // namespace DarkPath.Math
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
