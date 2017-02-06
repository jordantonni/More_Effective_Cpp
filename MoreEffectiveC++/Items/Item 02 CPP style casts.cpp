/*
 * Prefer c++ style casts
 * 
 * Old Style:
 *  (TYPE) Expression
 *  
 * New Style:
 *  static_cast<TYPE> (Expression)
 *  
 * 
 * dynamic_cast<TYPE> (Expr)
 *  - Safely casts to pointer or reference to a more derived type
 *  - Fails well if objects dynamic type isnt really what you cast to
 *      - Pointer -> null
 *      - Reference -> Exception
 *
 * 
 * Summary:
 *  - C++ style casts limit what they can cast and convey their casting meaning clearly
 *  - Static Casts  -> Casting object not in inheritance hierarcy
 *  - Dynamic Casts -> Casting down from base class to dervied class safely
 *  - Const Casts   -> Remove or add Const / Volatile to variable
 *  - Reinterpret   -> Non portable, usefull to change function pointer types
 * 
 */

#include <string>

namespace item02
{

    // Static Cast
    int num = 12;
    int den = 20;
    double rat = static_cast<double>(num) / den;    // Casts result of int division to floating point

    // Const Cast
    void foo(std::string& s)
    { }

    void const_test()
    {
        const std::string s("hello");
        foo(const_cast<std::string&>(s)); // Removes the const from s, allowing it to bind to non const refernce 
    }

    // Dynamic Cast
    class base
    {
    public:
        virtual ~base() = default;
    };

    class der : public base
    {};
    
    void bar(der& d)
    {
        
    }

    void dynamic_test()
    {
        base* b = new der;
        bar(dynamic_cast<der&>(*b));     // Safely casts to derived memeber which it is, would throw exception if b wasnt really a der (null ptr of pass by null)
    }

    // Reinterpret Cast
    


    void test()
    {
        dynamic_test();
    }
}
