#include "Professor.h"
#include <unordered_set>
#include <string>
#include <vector>

/**
    Class for representing a professor.

    Public attributes:
        name: the professor's name represented as a string.
        tenured: a boolean that will be true, if the professor has tenure and 
            false otherwise.
        fields: a set of the names of the fields the professor works in
 **/
Professor::Professor(std::string _name, bool _tenured, std::vector<std::string> _fields):
name(_name), tenured(_tenured) {
    for (std::string field : _fields) {
        fields.insert(field);
    }
}