/*
 * Don't allow exceptions to leave destructors
 * 
 * A Dtor is called:
 *  1) Object is destroyed via going out of scope (stack semantics) or deleted
 *  2) Stack unwinding due to exception propagation
 *  
 * -> Due to (2) above, within a dtor, there is no way of knowing if an exception is active already or not!
 * Can't have multiple exceptions active at same time, so must assume there is already one active -> Can't let exception leave dtors!
 * 
 * Also, if a dtor throws an exception, it won't run to completion therefore wont fully clean up object!
 *
 *
 * Solution: Have try and catch block inside dtors that may throw
 *
 *
 * Summary:
 *  - Never allow dtors to propogate an exception
 *  - Have try and catch within dtors that can throw
 *  
 *  Why?
 *      - Dtors can be called via stack unwinding due to exceptions, means an exception may already be active within a dtor
 *      - Can't have >1 active at the same time else terminate is called
 *
 */


namespace item11
{
    class Widget
    {
        // Signifies that this dtor will not propogate an exception from within!
        ~Widget() noexcept
        {
            try
            {
                // ... some cleanup code that can throw
            }
            catch(...)
            {
                // Catches anything
            }
        }
    };
}