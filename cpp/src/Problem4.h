#ifndef _Problem4_
#define _Problem4_
#include <vector>
#include <string>

/**
@class Problem4
*/
class Problem4 {
public:

    /**
     * Takes in a sequence of letters, a kmer length, and a list of k-mers and
     * returns a dictionary of k-mers and their counts in the sequence.
     *
     *  @param seq  A string of letters
     *  @param k    The length of the k-mers represented as an integer
     *  @param mers A vector of names as strings
     * 
     *  @return:    A vector where the ith entry is the number
     *   of times that the ith k-mer in kmers occurs on the sequence
    **/
    static std::vector<int> kmers(std::string& seq,
                                  int k,
                                  std::vector<std::string>& mers);
};

#endif
