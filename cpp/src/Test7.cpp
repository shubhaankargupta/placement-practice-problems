#include "TestHelpers.h"
#include "Problem7.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Test7 {
private:
static std::vector<int> getData(std::string& f) {
    std::string dataFileName = TestHelpers::getDataFile(f);
    std::vector<int> res;
    int num_values, i, x;

    std::ifstream ifs(dataFileName);

    if (ifs) {
        ifs >> num_values >> i >> x;
        res.push_back(i);
        res.push_back(x);
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
        return std::vector<int>();
    }

    for (int i = 0; i < num_values; ++i) {
        int temp;
        ifs >> temp;
        res.push_back(temp);
    }
    
    if (res.size() != num_values + 2) {
        std::cout << "Format error: Actual and expected number of values do not match: " << dataFileName << std::endl;;
        exit(1);
    }

    return res;
}

public:
static bool runTest(std::string f) {
    std::vector<int> data = getData(f);
    int i = data[0], x = data[1];
    std::vector<int> values = {};
    for (size_t j = 2; j < data.size(); ++j) {
        values.push_back(data[j]);
    }
    Problem7::fill(values, i, x);
    std::vector<int> expected = TestHelpers::getResult(f);


    if (expected.size() == 0) {
        return false;
    }
    
    if (values.size() == 0) {
        std::cout << "Failed: actual result is null\n";
	return false;
    } else if (values == expected) {
        return true;
    } else {
        std::cout << "Failed actual result and expected result do not match\n";
        printDiff(values, expected);
	return false;
    }
}

static void printDiff(const std::vector<int>& actual, const std::vector<int>& expected) {
    if (actual.size() != expected.size()) {
        std::cout << "Actual length (" << actual.size() << ") and expected length (";
        std::cout << expected.size() << ") do not match\n";
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
        std::cout << "no test file found\n"; 
        exit(1);
    } 

    int count = 0;
    for (size_t i = 0; i < files.size(); ++i) {
        std::string f = files[i];
	std::cout << "Test " << f << ": ";	 	
        if (Test7::runTest(f)) {
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
