/*
 * Costs of virtual functions, multiple inheritance, virtual base classes, RTTI
 *
 * Virtual Functions:
 *  - Function executed depends on dyanmic type of the object, not the static type of the pointer or reference
 *  
 *      Virtual Table (VTBL)
 *          - Array of pointers to functions 
 *              - Address of the most specific function for that type 
 *              - Doesnt store address of non-virtual functions
 *          - Any class that has virtual functions or inherits from class with virtual functions has its own vtable
 *              - Vtable is shared between all instances of that class ( Usually stored in a single object file )
 *              
 *      Virtual Table Pointer (VPTR)
 *          - Each object of a class with a vtable has a vptr that points to the vtable for that class
 *          
 *          
 * Virtual function invocation:
 *  - Follow vptr to vtable 
 *      - COST: offset to vptr and indirection to vtable
 *  - Find function in vtable
 *      - COST: offset using index into vtable
 *  - Invoke function in vtable
 *      - COST: Normal function invocation
 *      
 * Note:
 *  Normal function : myWidget->foo();   // Calls foo() method
 *  
 *  Virtual function: (*myWidget->vptr[i])(myWidget) // Calls foo method, which is at index i in vtabl, passes itself pointer as this
 *      - Not much slower than normal function call
 *  
 *  COST: Main cost of virtual functions is the fact you can't inline them! (Although virtual functions can be inlined when invoked though objects...)
 *  
 *  
 *  
 *  Multiple Inheritance:
 *      - Offset to calculate vptr location more complex
 *      - Multiple vptrs in object, one for each base class
 *      - Special vtables created 
 *      
 *  Virtual Base Class:
 *      - If the same base class can be got to in multiple ways using multiple inheritance, that base class will be copied twice, NOT WHAT YOU WANT
 *      - Solution: use virtual inheritance on the base class
 *          - Implemented via each class that virtually inherits a base having a pointer to the virtual base class
 *      
 *  Run Time Type Identification (RTTI):
 *      - Gives information on the type of an object at run time
 *      - Info stored in a type_info object, retrieved using typeid operator
 *          - type_info object accessed from a pointer inside classes vtable
 *      
 *
 * Summary:
 *      - Main cost of having virtual functions is that it disallows inlining of virtual function invocation
 *      
 *
 */