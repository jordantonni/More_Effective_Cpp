/*
 * Know the different meanings of new and delete
 *
 * new operator
 *  - i.e. string* st = new string("Hello");
 *  - Built into the language
 *  - Does 2 things
 *      - Allocates enough memory to hold the object (invoke operator new)
 *      - Calls the constructor on the object to initialize the now allocated memory
 * 
 * operator new
 *  - void* operator new (size_t size)
 *  - Invoked from new operator
 *  - Allocates memory, doesnt call any ctor
 *  - Can call it itself to just allocate some memory for you
 *  - Can modify it to default initialize the memory
 * 
 * placement new
 *  
 * 
 * delete operator
 * 
 * oeprator delete
 * 
 *
 * Summary:
 * 
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