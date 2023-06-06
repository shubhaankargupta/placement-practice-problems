#ifndef _Committee_
#define _Committee_
#include <vector>
#include <string>
#include <unordered_set>
#include "Professor.h"

/**
Class for representing Committees

 Public attributes:
  name: the name of the committee
  members:a list of the Professors assigned to the committee

 Public methods:
  addMember: add a Professor as a member to the committee, if they are not 
      already on the committee.
  isBadCommittee: determine whether the committee as currently constituted is "bad"
 **/
class Committee {
public:
std::string name;

/**
Constructor: the constructor for Committee

 @param name the name of the committee represented as a string
**/
Committee(std::string _name);

/**
add a Professor to the committee, if they are not already on the committee.

 @param possible a possible member of the committee represented as a Professor

 @return true, if the specified Professor is not already on the committee, 
      false otherwise.
**/
bool addMember(Professor* possible);

/**
determine whether the committee as currently constituted is "bad".

 @return true, if the committee meets the definition of bads (fewer than two 
      unique fields represented
      and an insufficient number of tenured professors), false otherwise.
**/
bool isBadCommittee();


private:
std::vector<Professor*> members;

/**
 * 	numMembers: computes the number of tenured committee members
 **/
int numMembers();

/**
 * 	numTenured: computes the number of tenured committee members
 **/
int numTenured();

std::unordered_set<std::string> getUniqueFields();
};

#endif
