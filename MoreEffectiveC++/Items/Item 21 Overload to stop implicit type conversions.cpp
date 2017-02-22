/*
 * Overload functions to avoid implicit type conversions
 * 
 * Functions taking types that have converting constructors can result in temporary objects being created
 *
 * By creating overloaded functions that take both the types you want + the types that would result in implicit conversions
 * you can stop temporary objects being created to bind with the parameters.
 * 
 * Note: Every operator overload must have at least 1 user defined type as a param. Not legal to overload ops on only primitive types
 *  i.e. Widget operator+ (int lhs, int rhs); NOT ALLOWED
 *
 *
 * Summary:
 *  - Create overloaded functions that take all types you are willing to take
 *      - i.e. Types that could be implicitly converted to the original type via its ctor
 *      
 *  - This stops implicit type conversion to a temporary object for the parameter
 *
 */
