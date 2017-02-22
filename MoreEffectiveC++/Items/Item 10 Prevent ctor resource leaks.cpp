/*
 * Prevent resource leaks in constructors
 * 
 * Problem: C++ only calls destructor to delete FULLY CONSTRUCTED OBJECTS
 *          - If within a ctor an exception occurs, the dtor of the class will not be called. 
 *          - If resources were acquired in the ctor, they will be leaked!
 *          
 * Naive Solution: Try/catch block in ctor to free resources so far acquired in ctor
 *                  - Problem is that if objects are initialized using member list initialization, we can't wrap that in try block
 *  
 * Solution: Use smart pointers to hold pointer class members
 *  
 *
 *
 *
 * Summary:
 *  - Replace pointers in classes with smart pointers
 *      - Makes their cleanup safe during ctor exceptions
 *      - No need to manually delete them in dtors
 *      - Can allow for const members to be initialized in member initialization list without working around the try block needed!
 *
 */
