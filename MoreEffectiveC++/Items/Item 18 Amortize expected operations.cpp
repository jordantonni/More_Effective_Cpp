/*
 * Amortize the cost of expected computations
 * 
 * Opposite idea of lazy evaluation
 *  - Instead, do more!
 *
 * For the methods below, there are 3 ways to implement them:
 *  
 *  (1) Eager Evaluation: Compute the data as soon as the function is invoked
 *  (2) Lazy Evaluation: Return a proxy data structure that only computes the value once it is asked for it/used
 *  (3) Over-Eager Evaluation: Keep each value up-to-date as the collection is modified. Return the value simply once invoked
 *
 * CACHING values within the data structue as it is modified
 *  - Map is a good data structure for these kinds of things
 * 
 * PREFETCHING values
 *  - Allocating more data for an extensible data structre (table doubling)
 *  - Takes advantge of locality of reference
 * 
 *
 * Summary:
 *  Lazy Evaluation -> Improve performance when operations values may not always be needed
 *  
 *  Over-Eager Evaluation -> Improve performance when values are always needed or values needed more than once
 *
 */

namespace item18
{

    
    template <typename DataType>
    class Collection
    {
    public:
        double min();
        double max();
        double avg();
    };
}
