/*
 * Prefer assignment versions of operators over standalone operators
 *  
 * Implement oeprator+ using operator+=
 *  - Only need to maintain one function
 *
 * Assignment operators are more efficient:
 *  - Don't need to create and return a temporary
 *  - Better support for RVO
 *
 * Summary: 
 *  - Use operator+= over operator=
 *  
 *
 */

namespace item22
{
    class Rational
    {
        int num;
        int den;

    public:

        Rational& operator+=(const Rational& rhs)
        {
            num += rhs.num;
            den += rhs.den;
            return (*this);
        }
    };

    // returns a const so you can't chain and get unexpected result (i.e. chaning wouldnt increment twice)
    const Rational operator+(const Rational& lhs, const Rational& rhs)
    {
        return Rational(lhs) += rhs;    // Implemented using operator+= and allows for RVO
    }
}