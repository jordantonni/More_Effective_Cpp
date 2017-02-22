/*
 * Costs of exception handling
 *
 * ID objects to destroy
 * note each entry and exit of try block
 * track associated catch blocks with each try and exceptions each catch can handle
 * 
 * Costs even if you dont use exceptions:
 *  - Space and time to keep data structures holding what objects would need to be destroyed if exception was thrown at some time
 *  
 * Cost of Try block only:
 *  - 5-10% increase in runtime and size of program just for having a try block
 *  
 * Throwing an exception:
 *  - ~ 30x slower than a function call
 * 
 *
 *
 * Summary:
 *      - Exceptions are expensive yo!
 *
 */