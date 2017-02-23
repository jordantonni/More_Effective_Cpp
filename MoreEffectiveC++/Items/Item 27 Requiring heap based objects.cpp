/*
 * Requiring or prohibiting heap-based objects
 *  
 * Only heap:
 *  - Stack objects implicitly call ctor on declaration and dtor when scope closes
 *      - Making dtor private means compilation error for any stack objects as the compiler generated invocation to dtor is illegal
 *  - Make pseudo method that calls dtor, heap based object can just delete it via it:
 *      - smart pointers can set that to be their deleter
 *      
 * Problem:
 *  - Impossible to really determine if an object is on the heap or not
 *  
 *  
 * Only Stack:
 *  - Make operator new private
 *
 *
 *
 * Summary:
 *  - Make dtor private and have another method invoke it 
 *      - This allows for only heap based objects
 *  - Make operator new / new[] / delete / delete [] private
 *      - Allows for only stack based objects
 *
 */

namespace item27
{
    class Widget
    {
    private:
        Widget() {}
    };

    void test()
    {
        // Widget *w = new Widget;
    }
}