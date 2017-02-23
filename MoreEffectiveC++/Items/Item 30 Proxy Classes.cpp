/*
 * Proxy Classes
 * 
 * Proxy Class:
 *  - Object that stands for another object
 *  - e.g. A class could return another type, the proxy class, that the client doesnt know about, allowing it to act differently
 *
 *
 * Distinguihing reads from writes in operator[]:
 *  - Reads are rvalue usages, only need the value
 *  - Writes are lvalue usages, need the address to write to
 *  
 *  By returning a proxy class that represents / holds / refernce to a value from some real classes operator[]
 *      - Proxy class has implicit conversion to value it holds, to use it as a rvalue it just invokes this implicit conversion
 *      - Proxy class has operator=, this is invoked if the proxy returned from op[] is used in an lvalue context
 *
 *
 * Summary:
 *   - Returning proxy classes that represent values or parts of another type can allow you to handle them differently
 *
 */

#include <iostream>
namespace item30
{
    void test()
    {
        
    }
}
