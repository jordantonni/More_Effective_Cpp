/*
 * Difference between prefix and postfix increment/decrement operators
 * 
 * Prefix (++val)
 *  - Increment and fetch
 *  - More efficient
 *  - int& operator++();
 *  
 * Postfix (val++)
 *  - Fetch and increment
 *  - Less efficient
 *  - const int& operator++(int)
 *
 *
 * Note:
 *  - Prefix returns reference to the object
 *  - Post fix takes an int, that the compiler itself will pass a 0 to (otherwise would be unable to overload between prefix and postfix)
 *  - Post fix returns a const ref, otherwise you could chain calls via val++++
 *      - This would call postfix operator++(int) twice, but only increment once! So const stops this chaining
 *      
 * Summary:
 *  - Prefer prefix 
 *  - Implement postfix in terms of prefix
 *  - Postfix should return const ref, to stop its returned old value from being chained
 */

namespace item06
{
    class Widget
    {
        int val;
    public:
        explicit Widget(int va)
            : val { va }
        {}

        // Prefix 
        Widget& operator++()
        {
            ++val;
            return *this;
        }

        //Postfix
        const Widget& operator++(int)
        {
            Widget oldVal = *this;
            ++(*this);
            return oldVal;
        }

    };
}
