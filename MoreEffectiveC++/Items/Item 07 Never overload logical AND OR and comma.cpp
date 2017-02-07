/*
 * Never overload &&, || or ,
 *
 * Short-Circuit evaluation
 *  - Boolean expressions stop evaluating once their truth has been determined
 *      - ( (EXPR1) && (EXPR2) )    If EXPR1 is false, EXPR2 will never be evaluated as this statement can't be true
 *     
 * Some styles of programming rely on this feature for correct code, i.e.
 *  - if ( (p != nullptr) && (strlen(p) > 101 )
 *  - Relies on short circuit to stop the strlen to invoke on a nullptr
 *  
 * Overloading these operators is BAD
 * Why?
 *  - It replaces short ciruit evaluation with function call semantics
 *      -> All expressions always get evaluated
 *      -> No predefined order in what expressions (parameters) get evaluated first
 *      
 * Comma operator
 *  - for (int i=0, j=10; i<10; ++i, --j) Note the comma operators
 *  - They allow multiple statements to form a single expression
 *      - Returns the value of the last statement in the expression
 *  - Always eval left to right
 *  - Can't enforce that ^ using function call semantics, SO DONT OVERLOAD
 *
 * Summary:
 * - Don't overload &&, || or , operators
 * - They use short circuit evaluation that you can't replicate with function call semantics of overloading
 */

namespace item07
{
    
}