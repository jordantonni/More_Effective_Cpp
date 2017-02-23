/*
 * Functions being virtual with respect to more than one object type
 *
 * Say we have a base class called Gameobject and other classes derive from it, want to handle collisions between differernt type differently
 *
 * Virtual Functions and RTTI:
 *  - Object has collide virtual function, taking another gameObject ref
 *  - Get RTTI of rhs, if/elses determine what to do
 *  - BAD: Each new class needs another else clause
 *  
 * Virtual Functions only:
 *  - Two virtual function calls
 *      - First determines dynamic type of one
 *      - Second determines dynamic type of other
 *
 * Visitor Pattern:
 *  
 *
 * Summary:
 *  
 *
 */