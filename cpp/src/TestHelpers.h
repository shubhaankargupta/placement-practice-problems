#ifndef _TestHelpers_
#define _TestHelpers_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

class TestHelpers {
public:

/**
    This function returns the absolute path of the test-data directory

    @return string: the absolute path of the test-data directory
**/
std::string getTestDataPath(std::map<std::string, std::string> &options);



/**
    This function parses the arguments and return a vector of specified tests.
    If no test cases are specfied, all tests will be returned

    @param argv the command-line arguments as a char array
    @param argc the total number of arguments
     
    @return vector of strings of filenames or null.
**/
static std::vector<std::string> getFiles(int argc, char* argv[]);

/**
    Given a test number, this function return the name of the corresponding result file.
        TEST_NUM => TEST_NUM.ans
    
    @param f: the test number
    
    @return a result filename of the corresponding test number.
**/
static std::string getResultsFile(std::string& f);

/**
    Given a test number, this function return the name of the corresponding data file.
        TEST_NUM => TEST_NUM.in
    
    @param f: the test number
    
    @return a data filename of the corresponding test number.
**/
static std::string getDataFile(std::string& f);

/**
    Read the data from a file that contains a list of integers formatted as:
      value value value...

    @param f: a test number with data formatted as shown above

    @return a vector of integers or null, if the file is formatted incorrectly.
**/
static std::vector<int> getResult(std::string& f);

/**
    Read the data from a file that contains a list of integers formatted as:
      number_of_values
      value value value...

    @param f: a test number with data formatted as shown above

    @return a vector of integers or null, if the file is formatted incorrectly.
**/
static std::vector<int> getData(std::string& f);

friend class Test;

};

#endif
