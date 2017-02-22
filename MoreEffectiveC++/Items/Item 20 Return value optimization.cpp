/*
 *  Help the Return Value Optimization
 *  
 *  
 * Return object from a function has its own memory. 
 * A copy of the object to return is made and put into this area. (This area is basically where the "return blahblah" is)
 * 
 * To remove this unnecessary copy of a local object to the functions' return value object
 *  - Construct the return object in the return statement via its ctor
 *  - i.e. return Widget("Value");
 *
 * Compilers can remove both:
 *  - The temporary object inside the function
 *  - The tempoary copy of the object to return on the return statement
 *  -> Instead: Construct the object inside the memory of the object that is invoking the function
 *
 * Summary:
 *  - Don't create function local object then return them
 *  - Instead, Create the object and return constructor arguments in the same return statement.
 * 
 */

#include <iostream>
#include <string>

namespace item19
{
    struct Widget
    {
        std::string x;

        Widget(std::string v = "Temp")
            : x { v }
        {
            std::cout << "Widget " << x << " ctor()" << std::endl;
        }

        Widget(const Widget& rhs)
            : x{ rhs.x + "-COPIED" }
        {
            std::cout << "Widget " << rhs.x << " copy ctor()" << std::endl;
        }

        ~Widget()
        {
            std::cout << "Widget " << x << " dtor()" << std::endl;
        }
    };

    // RVO enabled  
    Widget foo()
    {
        return Widget("ret"); // Creates a temporary Widget object. Return value optimization should create this object in the memory of object
        // Invoking this function
    }

    // Non RVO 
    Widget bar()
    {
        Widget ret("ret"); // Creates local variable ret
        return ret; // Copies it into return value of bar function 
    } // destroy local ret and return value object && copy return value into the object invoking this bar() function

    void test()
    {
        Widget ret = bar();

        Widget other = foo();
    }
}
