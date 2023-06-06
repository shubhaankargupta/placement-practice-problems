#include "TestHelpers.h"
#include "Problem2.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <optional>

class Test {
public:
static std::optional<int> getResult(std::string& f) {
     std::string resultsFileName = TestHelpers::getResultsFile(f);
     std::ifstream ifs(resultsFileName);
     std::optional<int> res;

     std::string data;
     if (ifs) {
         ifs >> data;
         if (std::isdigit(data[0])) {
             res = std::stoi(data);
         } else {
             res = std::nullopt;
         }
     } else {
         std::cout << "Results file not found: " << resultsFileName << std::endl;;
         exit(1);
     }
     return res;
 }

static bool runTest(std::string f) {
    std::vector<int> measurements = TestHelpers::getData(f);
    std::optional<int> actual = Problem2::raindrops(measurements);
    std::optional<int> expected = getResult(f);

    if (actual == std::nullopt) {
        if (expected == std::nullopt) {
            return true;
        } else {
            std::cout << "Failed: actual result is null\n";
	    return false;
        }
    } else if (actual == expected) {
        return true;
    } else {
        std::cout << "Failed actual result and expected result do not match\n";
        std::string actualVal = actual ? std::to_string(actual.value()) : "null";
        std::string expectedVal = expected ? std::to_string(expected.value()) : "null";
        std::cout << "    actual is " << actualVal << std::endl;
        std::cout << "    expected is " << expectedVal << std::endl;
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

    std::cout << "Files: " << files.size();
    std::cout << "count: " << count;
    if (count == files.size()) {
      return 42;
    } else {
      return 0;
    }
}
