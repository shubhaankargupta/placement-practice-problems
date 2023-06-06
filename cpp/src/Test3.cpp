#include "TestHelpers.h"
#include "Problem3.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Test {
public:
static std::string getData(std::string& f) {
    std::string dataFileName = TestHelpers::getDataFile(f);
    std::string res;
    int num_values;

    std::ifstream ifs(dataFileName);

    if (ifs) {
        ifs >> num_values;
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
        return "";
    }

    for (int i = 0; i < 2 * num_values; ++i) {
        char temp;
        ifs >> temp;
        res += temp;
    }
    
    if (res.size() != num_values * 2) {
        std::cout << "Format error: Actual and expected number of values do not match: " << dataFileName << std::endl;;
        exit(1);
    }

    return res;
}

static std::string getResult3(std::string& f) {
    std::string resultsFileName = TestHelpers::getResultsFile(f);
    std::ifstream ifs(resultsFileName);

    std::string result = "";
    if (ifs) {   
        std::getline(ifs, result);
    } else {
        std::cout << "Results file not found: " << resultsFileName << std::endl;;
        exit(1);
    }
    return result;
}

static bool runTest(std::string f) {
    std::string data = getData(f);
    int N = int(data.size()/2);
    std::string player1 = data.substr(0, N);
    std::string player2 = data.substr(N, N);
    std::string actual = Problem3::tricky(player1, player2);
    std::string expected = getResult3(f);


    if (expected.size() == 0) {
        return false;
    }
    
    if (actual.size() == 0) {
        std::cout << "Test: " << f << ": ";
        std::cout << "Failed: actual result is null\n";
	return false;
    } else if (actual.compare(expected) == 0) {
        return true;
    } else {
        std::cout << "Test: " << f << ": ";
        std::cout << "Failed actual result and expected result do not match\n";
        std::cout << "    actual: " << actual << "\n";
        std::cout << "    expected: " << expected << "\n";
	return false;
    }
}



};

int main (int argc, char* argv[]) {
    std::vector<std::string> files = TestHelpers::getFiles(argc, argv);
    if (files.size() == 0) {
        std::cout << "no test file found"; 
        exit(1);
    } 

    int count = 0;
    for (size_t i = 0; i < files.size(); ++i) {
        std::string f = files[i];
	std::cout << "Test " << f << ": ";	 	
        if (Test::runTest(f)) {
	  std::cout << "PASSED\n";	  
	  count++;
	} else {
	  std::cout << "FAILED\n";	  
	}
    }

    if (count == files.size()) {
      return 42;
    } else {
      return 0;
    }
}
