#ifndef _Professor_
#define _Professor_
#include <unordered_set>
#include <string>
#include <vector>


/**
Class for representing a professor.

 Public attributes:
  name: the professor's name represented as a string.
  tenured: a boolean that will be true, if the professor has tenure and false 
    otherwise.
  fields: a set of the names of the fields the professor works in
 **/
class Professor {
public:
std::string name;
bool tenured;
std::unordered_set<std::string> fields;

/**
Constructor:

 @param name the Professor's name represented as a string
 @param tenures a boolean that will be true, if the process has tenure and 
    false otherwise.
 @param fields an array of strings with the names of the fields the professor 
    works in
**/
Professor(std::string _name, bool _tenured, std::vector<std::string> _fields);

};

#endif