#include "TestHelpers.h"
#include "Problem4.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Test {
public:

static std::vector<std::string> getData(std::string& f) {
  std::string dataFileName = TestHelpers::getDataFile(f);
    std::vector<std::string> res;
    int line, length, k, numOfMers;

    std::ifstream ifs(dataFileName);
    if (ifs) {
        ifs >> line >> length >> k >> numOfMers;
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
        return std::vector<std::string>();
    }

    std::string seq;
    for (int i = 0; i < line; ++i) {
        std::string temp;
        ifs >> temp;
        seq += temp;
    }
    res.push_back(seq);

    if (seq.size() != length) {
        std::cout << "Format error: Actual and expected length of seq do not match: " << dataFileName << std::endl;
        std::cout << "seq: " << seq << "\n"; 
	return res;
    }


    for (int j = 0; j < numOfMers; ++j) {
        std::string mer;
        ifs >> mer;
        res.push_back(mer);
    }
    
    if (res.size() != numOfMers + 1) {
        std::cout << "Format error: Actual and expected number of values do not match: " << dataFileName << std::endl;;
	return res;
    }

    return res;
}


static std::vector<int> getResult(std::string& f) {
    std::vector<int> data;

    std::string resultsFileName = TestHelpers::getResultsFile(f);
    std::ifstream ifs(resultsFileName);
    if (ifs) {
        int num;
        std::string mer;
        while (ifs >> mer >> num) {
            data.push_back(num);
        }
    } else {
        std::cout << "Results file not found: " << resultsFileName << std::endl;;
    }
    return data;
}


static bool runTest(std::string f) {
    std::vector<std::string> data = getData(f);
    std::string seq = data[0];
    std::vector<std::string> mers = {};
    for (size_t j = 1; j < data.size(); ++j) {
        mers.push_back(data[j]);
    }
    std::vector<int> actual = Problem4::kmers(seq, mers[0].size(), mers);
    std::vector<int> expected = getResult(f);

    if (expected.size() == 0) {
        std::cout << "\nProblem with expected...\n";
        return false;
    }
    
    if (actual.size() == 0) {
        std::cout << "Failed: actual result is null\n";
	return false;
    } else if (actual == expected) {
        return true;
    } else {
        std::cout << "Failed actual result and expected result do not match\n";
        printDiff(actual, expected);
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
