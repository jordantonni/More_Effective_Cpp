/*
 * Catch exceptions by reference
 * 
 * Exception objects are copied twice if caught by value:
 *  - Once to copy the object so that it doesnt go out of scope when the stack frame is unwinded
 *  - Second to copy that temporary into value param
 * Catching by refernce stops the secone copy
 * Catching by pointer meaning only the pointer is copied into a temporary (Danger is that the original object will be deleted if not static or on heap!)
 * 
 * Exceptions passed by value also fall to the Slicing problem, where only their base components will be copied!
 * 
 *
 *
 *
 * Summary:
 *  - Always catch exceptions by reference
 *  Why?
 *      - Don't have to worry about pointers to deleted objects or deleting the heap object
 *      - No slicing
 *      - Not as many copies as by value!
 *
 */