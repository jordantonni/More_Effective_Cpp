/*
 * Know the different meanings of new and delete
 *
 * new operator
 *  - i.e. string* st = new string("Hello");
 *  - Built into the language
 *  - Does 2 things
 *      - Allocates enough memory to hold the object (by invoke operator new)
 *      - Calls the constructor on the object to initialize the now allocated memory
 * 
 * operator new
 *  - void* operator new (size_t size)
 *  - Invoked from new operator
 *  - Allocates memory, doesnt call any ctor
 *  - Can call it by itself to just allocate some memory for you
 *  - Can modify it to default initialize the memory
 * 
 * placement new
 *  - void* operator new (size_t, void* location)
 *  - Allows you to pass a pointer to some pre-existing allocated memory
 *  - Will just return a pointer to that memory
 *  - Operator new will then just invoke ctor on that area
 *  - TLDR: Replaces operator new in the 1st stage of new operator, therefore not allocating new memory, just using provided memory, then calls ctor
 *      - Basically just lets you call ctor directly on some object, to initialize some pre allocated memory
 *  NOTE:   
 *      - Don't free up memory from placement new with delete operator, undefined
 *      - Instead invoke dtor on the object there
 *      - Then call operator delete
 *
 *    
 * 
 * delete operator
 *  - delete ptr;
 *  - Will call destructor of object ptr points to
 *  - Deallocate memory (via calling operator delete)
 * 
 * operator delete
 *  - void operator delete (void* memory)
 *  - Will deallocate the memory
 *  - Invoke this directly if you are just dealloacting some raw allocted memory that isn't initialized with an object
 *  
 * 
 * What each does, in TLDR:
 *  - invoke new operator:                          Allocate memory and initialize object on heap
 *  - invoke operator new:                          Only allocate memory
 *  - modify operator new and invoke new operator:  Customize how memory is allocted and then initialize object on heap (i.e. pre init memory with vals)
 *  - invoke placement new:                         Initializre object in pre allocated memory
 *      
 *
 * Summary:
 *  - operator new is whats called when you do a new
 *  - It calls the new operator to allocate memory, then invokes ctor
 *  - 
 */

#include <string>
namespace item08
{
    std::string *ps = new std::string("test");  // Would invoke new operator -> then invoke operator new -> then invoke string::string() ctor

    // vvvvvvvvvvvvvv Would look something like this vvvvvvvvvv

    void *raw_memory = operator new(sizeof(std::string));       // Allocate enough memory for a string
    // Invoke std::string::string("test") ctor on *raw_memory
    std::string *pss = static_cast<std::string*>(raw_memory);   // Make your string pointer point to the new string in raw allocated memory
    

    void test()
    {
        
        
    }
    
}