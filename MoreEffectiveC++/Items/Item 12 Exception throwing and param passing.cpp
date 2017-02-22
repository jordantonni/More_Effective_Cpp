/*
 * Difference between throwing an exception from passing param or calling virtual function
 * 
 * Calling a function, control returns to the call site.
 * Throwing an excpetion to a catch clause, control does NOT return to throw site.
 *
 * Exceptions are always copied, even when passed by pointer or reference, as the original would go out of scope!
 *  - It is this copy that is then either copied again into the by value parameter, or bound to by the pointer or reference
 *  -> Catching by value results in TWO copies!
 *
 * Summary:
 *  - Exceptions are always copied at least once, regardless of how they are caught (via value, ptr or ref)
 *      - As the origianl object would be deleted due to exception stack unwinding
 *      - Copy ctor is called, which one depends on the objects Static Type
 *      - Exceptions are slower then function calls
 *  - Only inheritance type conversions are applied to exceptions being thrown and catch arguments
 *  - Catch clauses are matched in order they appear, not most specialised unlike functions
 *  
 *  
 *
 */

namespace item12
{
    class Widget
    {};

    class SpecialWidget : public Widget
    {};

    void foo()
    {
        try
        { }
//        catch (Widget& w )
//        {
////            throw; // Throws the original exception, not the copy of it , w
//        }
        catch (Widget& w)
        {
            throw w; // Throws a copy of the original exception, w
        }
    }
}
