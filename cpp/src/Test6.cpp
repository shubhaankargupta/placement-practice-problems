#include "TestHelpers.h"
#include "Committee.h"
#include "Professor.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Test {
public:
static bool runTest(std::string f) {
    std::string dataFileName = TestHelpers::getDataFile(f);
    int i, j;
    int numProf = 0, numComm = 0;
    std::unordered_map<std::string, Professor*> profs;
    std::vector<Committee*> comms;

    std::ifstream ifs(dataFileName);
    if (ifs) {
        ifs >> numProf >> numComm;
        ifs.ignore();
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
	return false;
    }

    for (i = 0; i < numProf; ++i) {
        std::string temp;
        std::getline(ifs, temp);
        std::istringstream iss(temp);
        std::string profName, tenure;
        iss >> profName >> tenure;
        std::vector<std::string> areas;
        while (!iss.eof()) {
            std::string area;
            iss >> area;
            areas.push_back(area);
        }
        profs[profName] = new Professor(profName, tenure == "T", areas);
    }

    for (i = 0; i < numComm; ++i) {
        std::string temp;
        std::getline(ifs, temp);
        std::istringstream iss(temp);
        std::string comName;
        iss >> comName;
        Committee* c = new Committee(comName);
        
        std::vector<std::string> members;
        while (!iss.eof()) {
            std::string prof;
            iss >> prof;
            members.push_back(prof);
            if (profs.find(prof) != profs.end()) {
                if (!c->addMember(profs[prof])) {
                    std::cout << "Test: " << f << ": ";
                    std::cout << "Attempt to add " << prof << " to " << c << " should have succeeded\n";
		    return false;
                }
            } else {
                std::cout << "Unable to find " << prof << "\n";
		return false;
            }
        }

        for (j = 0; j < members.size(); ++j) {
            if (profs.find(members[j]) != profs.end()) {
                if (c->addMember(profs[members[j]])) {
                    std::cout << "Attempt to add " << members[j] << " a second time to " << c->name << " should have failed\n";
		    return false;
                }
            } else {
                std::cout << "Unable to find " << members[j] << "\n";
		return false;
            }
        }
        comms.push_back(c);
    }
    
    std::string resultFileName = TestHelpers::getResultsFile(f);
    std::ifstream ifs2(resultFileName);
    std::unordered_set<std::string> invalidCommittees;
    if (ifs2) {
        while (ifs2) {
            std::string cname;
            ifs2 >> cname;
            if (cname == "NONE") {
                break;
            } else {
                invalidCommittees.insert(cname);
            }
        }
    } else {
        std::cout << resultFileName << " failed to be read" << std::endl;;
	return false;
    }

    for (Committee* c : comms) {
        if (invalidCommittees.find(c->name) !=  invalidCommittees.end()) {
            if (!c->isBadCommittee()) {
                std::cout << "Committee " << c->name << " should be labelled as invalid\n";
		return false;
            }
        } else {
            if (c->isBadCommittee()) {
                std::cout << "Committee " << c->name << " should not be labelled as invalid\n";
		return false;
            }
        }
    }
    return true;
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
