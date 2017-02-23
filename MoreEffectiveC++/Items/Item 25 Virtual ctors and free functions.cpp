/*
 * Virtualizing ctors and non-member functions
 *
 * Virtual ctor:
 *  - A factory function that takes a some information pertaining to an object
 *      returns a base class pointer to a derived type depending on what was given as input.
 * 
 * Virtual copy ctor:
 *  - Typically called copyself, cloneself, clone etc
 *  - Define a virtual clone method in the base class
 *      - Derived classes implement clone by returning their copy construtor invoked on (*this)
 *      - C++ virtual functions allow for differing return types, this is used in the clone functions
 *
 * Virtual non-member functions
 *  - Create a virtual method in the base class, each derived class implements that specific for their type
 *  - Non virtual free function just invokes the virtual function on the object passed in
 *  
 *  
 * Summary:
 *      - Virtual ctors are just factory methods that return a base pointer to whatever derived type is specified
 *      - Make a non member function act virtual by:
 *          - Having a virtual function do the real work
 *          - Call the virtual function on the object passed in to the free function
 *
 */

#include <istream>

namespace item25
{
    struct Widget
    {
        virtual ~Widget()
        {};

        virtual Widget* clone() = 0;
    };

    struct DerivedWidgetOne : public Widget
    {
        // Clone method
        virtual DerivedWidgetOne* clone()
        {
            return new DerivedWidgetOne(*this);
        }
    };

    struct DerivedWidgetTwo : public Widget
    {};

    Widget* virtualCtor(std::istream& serializedData)
    {
        // Determine what type the serialized object is
        return new DerivedWidgetOne;

        // Or return this
        // return new DerivedWidgetTwo;
    }
}
