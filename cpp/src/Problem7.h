#ifndef _Problem7_
#define _Problem7_
#include <vector>

/**
@class Problem7 
*/
class Problem7 {
public:

    /**
    Performs a fill operation on the vector, replacing all continuous elements 
    with same value as array[i] with x.
    
    Note that this function works recursively.
    
    @param values a array of integers
    @param i an integer
    @param x an integer
    **/
    static void fill(std::vector<int>& values, int i, int x);
};

#endif
