/*
 * Limiting the number of objects instaniated from a class
 * 
 * Zero or one objects:
 *  - Zero -> Make ctor and copy ctor private or delete
 *  - One -> Private ctor is invoked from method that returns a reference to a static object of class
 *  
 * Static:
 *  - Static member in a class is always created before main executes
 *  - Static variable in a function is only created the first time the function is invoked
 * 
 * Multiple Objects:
 *  - ctors checks class static counter to see if more objects are allowed to be created
 *  - Throws exception if limit is reached
 *  
 * Object Creation Contexts:
 *  - Objects can be created in three different contexts:
 *      - on their own
 *      - as part of another class ( composition ) 
 *      - as base part of another class ( derivation )
 *  - Hard to limit creation of objects to only their own instantiaions, but allow unlimited use for composition and inheritance
 *
 * Object counting base class:
 *  - Templated class that has static counters
 *  - Inherit from this using CRTP and Mixin inheritance
 *  - Seeing as the base class ctor is called automatically for each derived clas ctor, all counting logic can be put in the base template
 *
 * Summary:
 *
 */
#include <iostream>
namespace item26
{
    class Widget
    {
    public:
        int id;

        // Only 1 widget is ever created 
        static Widget& TheWidget()
        {
            static Widget w { 1 };
            return w;
        }

    private:
        explicit Widget(const int id)
            : id { id }
        {}
    };


    void test()
    {
        auto& w = Widget::TheWidget();
        using namespace std;

    }
}
