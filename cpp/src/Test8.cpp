#include "TestHelpers.h"
#include "Tree.h"
#include "Problem8.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>



class Test {
private:
static int getResult(std::string& f) {
     std::string resultsFileName = TestHelpers::getResultsFile(f);
     std::ifstream ifs(resultsFileName);
     int res;

     std::string data;
     if (ifs) {
         ifs >> data;
         if (std::isdigit(data[0])) {
             res = std::stoi(data);
         } else {
	   res = -1;
         }
     } else {
         std::cout << "Results file not found: " << resultsFileName << std::endl;;
         exit(1);
     }
     return res;
 }

static std::vector<Tree*> getTree(std::string& f) {
  std::string dataFileName = TestHelpers::getDataFile(f);

    int num_nodes;
    std::ifstream ifs(dataFileName);
    if (ifs) {
        ifs >> num_nodes;
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
        return std::vector<Tree*>();
    }
    
    std::vector<Tree*> nodes(num_nodes+1, nullptr);
    for (int i = 0; i < num_nodes; ++i) {
        int num, salary;
        ifs >> num >> salary;
        nodes[num] = new Tree(num, salary);
    }
    
    for (int i = 0; i < num_nodes - 1; ++i) {
        int source, sink;
        ifs >> source >> sink;
        if (source >= num_nodes+1 || sink >= num_nodes+1) {
        } else {
            nodes[source]->addDirectReport(nodes[sink]);
        }
        
    }

    return nodes;
}

public:
static bool runTest(std::string f) {
    std::string dataFileName = TestHelpers::getDataFile(f);
    Tree* root = nullptr;
    std::vector<Tree*> nodes = getTree(f);
    int expected = getResult(f);
    int actual = -1;

    if ((nodes.size() == 0) || (expected < 0)) {
      return false;
    }

    actual = Problem8::solve(nodes[1]);

    if (actual == expected) {
        return true;
    } else {
        std::cout << "Failed actual result and expected result do not match" << "\n";
        std::cout << "    actual is " << actual << "\n";
        std::cout << "    expected is " << expected << "\n";
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
