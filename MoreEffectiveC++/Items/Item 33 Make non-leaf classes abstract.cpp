/*
 * Make non-leaf classes abstract
 *  
 * 
 * Why?:
 *  - Stops partial copying or partial assignment
 *  
 * If you derive one class from another base class, what are you saying?
 *  - They have something in common
 *  
 * So, Get the common features, put that into an abstract base class (interface)
 *  - Have both inherit from that
 *  - You have now explicity stated programatically the abstracts that are common between the classes, and made it into an interface
 *
 *
 * Summary:
 *  - Relating two concrete classes by public inheritance, usually means:
 *      - You need a base abstract class that represents this shared functionality explicitly
 *
 */