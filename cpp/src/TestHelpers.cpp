#include "TestHelpers.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;



void printHelp(int argc, char* argv[]) {
    // Print the help message and exit
    std::cout << "usage: "<< argv[0] << " [-h] [-a] <directory> | [-t] <filename>\n";
    std::cout << " -h: generate a usage message\n";
    std::cout << " -t <filename>: run the test in the specified file.\n";
    std::cout << " -a <directory>: run all the tests in the specified directory\n";
    exit(0);
}


std::vector<std::string> TestHelpers::getFiles(int argc, char* argv[]) {
    /* Returns a list of filepaths with the input files to run the tests from
       the command line arguments */

    std::vector<std::string> filesToProcess;

     // Create a map to store the options in
    std::map<std::string, std::string> options;

    // Loop through all the command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (arg == "-t") {  // Run a single test
            if (i + 1 < argc) {
                options["filename"] = argv[i + 1];
                ++i;
            } else {
                std::cout << "Missing a test filename for -t option." << std::endl;
            }
        }

        else if (arg == "-a") { // Run all the tests in a directory
            if (i + 1 < argc) {
                options["directory"] = argv[i + 1];
                ++i;  
            } else {
                std::cout << "Missing directory for -a option." << std::endl;
            }
        }
            
        else if (arg == "-h") {
            printHelp(argc, argv);
        }

        else {
            std::cout << "Unknown option: " << arg << std::endl;
            printHelp(argc, argv);
        }
    }

    // If the user specified a directory, get all the files in the directory
    if (options.find("directory") != options.end()) {
        std::string dir = options["directory"];
        for (auto& p : std::filesystem::directory_iterator(dir)) {
            // Check if filename ends with .in
            if (p.path().extension() == ".in") {
                filesToProcess.push_back(p.path().string());
            }
        }
    }

    // If the user specified a file, add it to the vector
    else if (options.find("filename") != options.end()) {
        filesToProcess.push_back(std::filesystem::path(options["filename"]).string());
    }

    else{
        std::cout << "No test files specified." << std::endl;
        printHelp(argc, argv);
    }

    return filesToProcess;
}

std::string TestHelpers::getResultsFile(std::string& f) {
    // Make a copy of the string
    std::string resultsFile = f;
    // Replace the extension with .ans
    resultsFile.replace(resultsFile.end() - 3, resultsFile.end(), ".ans");
    return resultsFile;
}

std::string TestHelpers::getDataFile(std::string& f) {
    // Make a copy of the string
    std::string dataFile = f;
    // Replace the extension with .in
    dataFile.replace(dataFile.end() - 3, dataFile.end(), ".in");
    return dataFile;
}


std::vector<int> TestHelpers::getResult(std::string& f) {
    std::vector<int> data;

    std::string resultsFileName = getResultsFile(f);
    
    std::ifstream ifs(resultsFileName);
    if (ifs) {
        int res;
        while (ifs >> res) {
            data.push_back(res);
        }
    } else {
        std::cout << "Results file not found: " << resultsFileName << std::endl;;
        exit(1);
    }
    return data;
}


std::vector<int> TestHelpers::getData(std::string& f) {
    std::string dataFileName = getDataFile(f);
    std::vector<int> data;
    int num_values = -1;

    std::ifstream ifs(dataFileName);

    if (ifs) {
        ifs >> num_values;
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
        return std::vector<int>();
    }

    for (int i = 0; i < num_values; ++i) {
        int temp;
        ifs >> temp;
        data.push_back(temp);
    }
    
    if (data.size() != num_values) {
        std::cout << "Format error: Actual and expected number of values do not match: " << dataFileName << std::endl;;
        exit(1);
    }

    return data;
}

