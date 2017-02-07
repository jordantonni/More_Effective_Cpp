/*
 * Be wary of user defined conversion functions
 * 
 * Implicit conversions: Ones that you don't have to specify yourself
 *  - Passing a short to a function that takes a double
 *  
 * Single-Argument Constructors
 *  - Either one paramter or paramters with default values allowing only 1 argument
 *  - They convert the parameter type to that object being constructed
 *  - Stop this via prefacing ctor with explicit
 *  
 * Implicit type conversion operator
 *  - Member function
 *  - operator double() const       // Would convert the type to a double
 *  - Instead just create your own asDouble() const function
 *      - Call this when you want a conversion, explicitly
 *  
 *  
 * You typically don't want to provide these at all
 *
 *
 * Summary:
 *      - User defined conversion functions are either
 *          - Single argument ctors without explicit keyword
 *          - operator TYPE() member functions
 *          
 *      - Typically, best practise not to use these
 */