#ifndef _Problem1_
#define _Problem1_

#include <vector>

class Problem1 {
public:
/**
	This function takes a vector of temperatures.  It returns a vector
    of three integers: the number of times the temperature went
    down, the number of times the temperature remained the same,
    and the number of times the temperature went up.

    @param temperatures a vector of temperatures represented as integers

	@return A vector of three integers representing the number of
    times the temperature went down, the number of times the
    temperature remained the same, and the number of times the
    temperature went up.
*/
static std::vector<int> itshotitscold(std::vector<int> temperatures);

};


#endif
