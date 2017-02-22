/*
 * Avoid gratuitous default constructors
 * 
 * Ctor -> Purpose is to initialize objects.
 * Default ctor:
 *              -> Takes NO arguments
 *              -> Purpose is to allow an object to be initialized without passing any data to it from where it is being initialized from
 *              
 * If class doesnt provide a default ctor, it can't easily be stored in an array, why?
 *  - Creating an array of objects calls their default ctor, can't pass arguments to objects in array at initializion of array!
 * 
 *
 *
 * Summary:
 *  - Creating an array calls the default ctor on its data type members -> If no default ctor you need to do extra work
 *  - Template classes, such as containers, often make an array of the type T -> If so, they cant store types with no default ctor 
 *  
 *  - Dont create virtual base classes with no default ctor, means ALL derived classes have to provide the data to initialize the base
 * 
 */

namespace item04
{
    class Widget
    {
    public:
        Widget(int x)
        {}
    };

    void test()
    {
//                Widget* fail = new Widget[5];    //Fails as it tries to call default ctor

        Widget* bestWidgets[10]; // Array of 10 pointers to Widget on stack, doesnt call ctor
        Widget** moreWidgets = new Widget*[10]; // Pointer to an array of 10 pointers to Widget on heap, same
    }
}
