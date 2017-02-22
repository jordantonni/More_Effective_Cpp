/*
 * Use destructors to prevent resource leaks
 * 
 * Problem: If an excpetion is thrown between acquiting a resource ( new ) and freeing that resource ( delete )
 *          the delete will never run. Resulting in a memory leak
 * 
 * Naive Solution: Wrap the use of resource and acquisition in a try catch block. Delete the resource in both the try and catch
 *                  -> Code duplication
 * 
 * Solution: Smart Pointers
 *              - Encapsulate resources in objects, use their destructors to free the objects via stack semantics.
 *
 *
 *
 * Summary:
 *  - Wrapping resources in objects, acquiring them in ctor and freeing them in dtor means no memory leaks from exceptions.
 *  - Use Smart Pointers
 *  Why?
 *      - Exceptions result in stack unwinding, calling the dtors of all objects in each stack frame!
 *
 */