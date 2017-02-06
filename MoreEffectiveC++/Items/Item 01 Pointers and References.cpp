/*
 *
 * Distinguish between pointers and references
 * 
 * Reference: 
 *  - Must refer to something
 *  - Must be initialized
 *  - References one thing, forever
 *  
 * Pointer:
 *  - Can be null
 *  - Can point to different things over its lifetime
 * 
 * 
 * Summary:
 *  - Reference when:
 *      - You know you have something to refer to
 *      - Never want to refer to anything else
 *      - Syntatically nicer, i.e. as return type of operator[]
 *      
 *  - Pointer when:
 *      - Possibly nothing to point to, then null pointer
 *      - Want to point to different things
 *
 */