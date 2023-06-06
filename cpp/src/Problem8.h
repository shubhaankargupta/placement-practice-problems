#ifndef _Problem8_
#define _Problem8_
#include "Tree.h"
#include <string>
#include <vector>

class Problem8 {
public:

/**
 * @brief   find the number of Workers (ie. employees with no direct reports) 
 *          who make more than at least one of their bosses. 
 * 
 * @param   t the root of the tree
 * @return  the number of workers who make more than at least one of their bosses 
 */
static int solve(Tree* t);
};

#endif
