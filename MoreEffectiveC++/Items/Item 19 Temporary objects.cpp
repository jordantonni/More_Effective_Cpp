/*
 * Temporary Objects
 * 
 * Temp objects arise when a non-heap object is created but unnamed.
 * 
 * 1) Implicit type conversion for argument to parameter
 *      - Argument type is converted to parameter type using its constructor, becoming a temporary object
 *      - Temp object is destroyed when function goes out of scope
 *      
 *  Note: Only const references can bind to temp objects, non-const references cannot!
 *      Why?
 *          - If a temporary object was created, then bound to a non-const reference, the function would change the referenced object
 *            but the referenced object is only a temp that is deleted at the end of the function. 
 *            
 *          - A const reference cannot be modified, so the caller of the function doesnt expect whatever he passes to it to be modified
 *            anyway, so this is fine!
 * 
 * 2) Functions return objects
 *      - The return value of a function is a temporary.
 *      - This object is constructed, copied to the call site object (if any), then destructed each time the function is called.
 * 
 *
 * Summary:
 *  - Anytime you see a const reference as a parameter, a temp object can be created for that to bind to
 *  - Anytime a function returns a value, a temporary is object is created for that ( Not always due to RVO)
 * 
 */