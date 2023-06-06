#include "TestHelpers.h"
#include "Problem1.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Test {
public:
static bool runTest(std::string f, bool verbose) {
    std::vector<int> temperatures = TestHelpers::getData(f);
    std::vector<int> actual = Problem1::itshotitscold(temperatures);
    std::vector<int> expected = TestHelpers::getResult(f);
    

    if (expected.size() == 0) {
        return false;
    }

    if (actual.size() == 0) {
        if (verbose) {
  	    std::cout << "Test: " << f << ": ";
            std::cout << "Failed: actual result is null\n";
        }  
	return false;
    } else if (actual == expected) {
        return true;
    } else {
      if (verbose) {
          std::cout << "Test: " << f << ": ";
          std::cout << "Failed actual result and expected result do not match\n";
          printDiff(actual, expected);
      }
      return false;
    }
}

static void printDiff(const std::vector<int>& actual, const std::vector<int>& expected) {
    if (actual.size() != expected.size()) {
        std::cout << "Actual length (" << actual.size() << ") and expected length (";
        std::cout << expected.size() << ") do not match";
        return;
    }

    for (int i = 0; i < actual.size(); ++i) {
        if (actual[i] != expected[i]) {
            std::cout << "  Actual and expected results do not match at index: " << i << std::endl;
            std::cout << "    actual @ index " << i << " is " << actual[i] << std::endl;
            std::cout << "    expected @ index " << i << " is " << expected[i] << std::endl;
            return;
        }
    }
    return;
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
        if (Test::runTest(f, true)) {
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
