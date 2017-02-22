/*
 * Lazy evaluation
 *
 * Defer creation, initialization, deserialization, computation etc of a object until when its value is actually needed
 * 
 * Methods:
 *  - Reference Counting:
 *      - Share the values of different objects, only make a copy when one object wants to mutate the data
 *  
 *  - Distinguising Reads from Writes: 
 *      - Depending on if operator[] is used to just read a value or write we don't need to make a copy of the data
 *      - How?
 *          - Achieved via reference counting the object itself
 *          - opertor[] returning a proxy class that represent the value. If used in an lvalue way, we the copy the underlying data
 *  
 *  - Lazy Fetching:
 *      - Don't retrieve all parts of an object, only the parts needed for the function working on it
 *      - How?
 *          - Getter methods populate member pointers to the data only when they are accessed.
 *          -> Only the specific members asked for are populated
 *          
 *
 * Summary:
 *  - Lazy Eval is good when:
 *      - Avoid unnecessary copying 
 *      - Distinguising reads from writes on objects data
 *      - Unnecessary database and network reads to make entire objects
 *      
 *  - But not useful if all the data would be needed anyway!, only good when there is a chance things might not be necessary
 *  
 *
 */