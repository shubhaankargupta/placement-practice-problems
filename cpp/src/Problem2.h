#ifndef _Problem2_
#define _Problem2_
#include <vector>
#include <optional>

/**
@class Problem2 
*/
class Problem2 {
public:

    /**
	This function takes a list of rainfall measurements and
    computes the average rainfall. The function only considers
    measurements that are greater than or equal to 0. If only
    negative measurements are given, the function returns null.

    @param measurements A list of measurements.

	@return The average rainfall as an integer (round down). If only
    negative measurements are given, the function returns optional<int>.
    */
    static std::optional<int> raindrops(std::vector<int> measurements);
};

#endif
