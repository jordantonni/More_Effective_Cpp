/*
 * Exception specifications
 * 
 * Specify what type of exceptions, if any, a function can throw
 * BAD and depreciated!
 * 
 * If function throws exception not listed in specification, std::unexpected is called, which calls std::terminate
 *
 *
 *
 * Summary:
 *  - Specifications are impossible to enforce, don't use them!
 *
 */

namespace item14
{
    void f1() throw(int);   // Will only throw exceptions of type int
    void f2() throw();      // Might throw anything
}
