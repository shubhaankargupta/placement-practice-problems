#include "TestHelpers.h"
#include "Restaurant.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>  
#include <unordered_map>

class Test {

static std::vector<std::string> getData(std::string& f) {
    std::string dataFileName = TestHelpers::getDataFile(f);
    std::vector<std::string> res;
    int num_values;

    std::ifstream ifs(dataFileName);

    if (ifs) {
        std::string communityName;
        ifs >> communityName >> num_values;
        res.push_back(communityName);
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
        return std::vector<std::string>();
    }

    for (int i = 0; i < num_values; ++i) {
        std::string temp;
        ifs >> temp;
        res.push_back(temp);
    }
    
    if (res.size() != num_values + 1) {
        std::cout << "Format error: Actual and expected number of values do not match: " << dataFileName << std::endl;;
        exit(1);
    }

    return res;
}  


public: static bool runTest(std::string f) {
    std::string dataFileName = TestHelpers::getDataFile(f);
    std::unordered_map<std::string, Restaurant*> Restaurants;
    int numOfRes = 0, numOfParties = 0;
    int unconfirmed = 0;
    int i;
    Restaurant* r;

    std::ifstream ifs(dataFileName);
    if (ifs) {
        ifs >> numOfRes >> numOfParties;
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
    }
    
    for (i = 0; i < numOfRes; ++i) {
        std::string resName;
        int numOfTables;
        ifs >> resName >> numOfTables;
        Restaurants[resName] = new Restaurant(resName, numOfTables);
    }


    for (i = 0; i < numOfParties; ++i) {
        std::string resName, partyName;
        int partySize;
        ifs >> resName >> partyName >> partySize;
        Reservation *Reserve = new Reservation(resName, partyName, partySize);
        if (Restaurants.find(resName) != Restaurants.end()) {
            r = Restaurants[resName];
            if (!r->makeReservation(*Reserve)) {
                unconfirmed++;
            }
        } else {
            std::cout << "Cannot find restaurant for " << resName << "when making reservation\n";
	    return false;
        }
    }

    std::string resultFileName = TestHelpers::getResultsFile(f);
    std::ifstream ifs2(resultFileName);
    int expectedUnconfirmed;
    if (ifs2) {
        ifs2 >> expectedUnconfirmed;
        ifs2.ignore();
        if (unconfirmed != expectedUnconfirmed) {
            std::cout << "Actual value for the number of unconfirmed reservations (" << unconfirmed << ") ";
            std::cout << "does not match the expected value of unconfirmed reservations (" << expectedUnconfirmed << ")\n";
	    return false;
        }

        for (size_t k = 0 ; k < numOfParties - expectedUnconfirmed; ++k) {
            std::string temp;
            std::getline(ifs2, temp);
            std::string resName, partyName;
            std::istringstream iss(temp);
            iss >> resName >> partyName;
            std::vector<int> tables;
            while (!iss.eof()) {
                int table;
                iss >> table;
                tables.push_back(table);
            }

            if (Restaurants.find(resName) != Restaurants.end()) {
                Restaurant* res = Restaurants[resName];
                if(!res->checkReservation(partyName, tables)) {
                    std::cout << "Reservation for " << partyName << " at " << resName << " is not correct.\n";
		    return false;
                }
            } else {
                std::cout << "Cannot find restaurant for " << resName << "\n";
		return false;
            }
        }
    } else {
        std::cout << resultFileName << " failed to be read" << std::endl;;
	return false;
    }
    return true;
}

};

int main (int argc, char* argv[]) {
    std::vector<std::string> files = TestHelpers::getFiles(argc, argv);
    if (files.size() == 0) {
        std::cout << "no test files found"; 
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
