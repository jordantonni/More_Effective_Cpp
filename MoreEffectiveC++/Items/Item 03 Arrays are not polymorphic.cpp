/*
 * Never treat arrays polymorphically
 *
 * Inheritance and polymorphisim:
 *  - Public Inheritance hierarchy means more derived type IS-A base type ( + more )
 *  - Manipulating derived types though a base pointer or reference -> Polymorphic behaviour on the pointer / reference
 *      - The referneces / pointers act as though they have many types (poly morph)
 *      
 *      
 * Arrays in c++ can be treated this way also, but NEVER do it
 *  - Arrays devolve into pointers, all indexing is done via pointer arithmetic
 *  - array[i] === *(array + ( i * sizeof(type) )
 *  
 *      -> All indexing uses the static type of the array for pointer arithmetic, not the dynamic type!
 *      -  delete [] wont work correctly either, will try to call the static type ~dtor()
 *
 * Summary:
 *  - Arrays devolve into pointers:
 *      - all indexing done with pointer arithmetic using sizeof(static_type) -> indexing a different dynamic type wont work
 *      - delete [] will call static type dtor, not dynamic type dtor
 *      
 *  - Never work with array polymorphically
 *  - Never inherit from concrete classes, only from abstract classes
 */

#include <iostream>

namespace item03
{
    void test()
    {
        int* array = new int[10]{ 1,2,3,4,5,6,7,8,9,10 };
        delete [] array;

        // delete [] array implementation
        for (int i = 10; i >= 0; --i)
        {
            // array[i].STATIC_TYPE::~STAIC_TYPE();      // Invoke the dtor for each object in the array, in reverse order from how they were initialized
        }
    }

    // Note: ^^ Would call the static type the array was defined with, if it held derived object only the base dtor would run!
}
