#include "Committee.h"
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
Committee::Committee(std::string _name) {
    // COMPLETE THIS METHOD
}

/**
add a Professor to the committee, if they are not already on the committee.

 @param possible a possible member of the committee represented as a Professor

 @return true, if the specified Professor is not already on the committee, 
 	false otherwise.
**/
bool Committee::addMember(Professor* possible) {
    // COMPLETE THIS METHOD
	// return included to allow the skeleton code to compile
	return false;
}

/**
 * 	numMembers: computes the number of committee members
 **/
int Committee::numMembers() {
	// COMPLETE THIS METHOD
	// return included to allow the skeleton code to compile
	return 0;
}


/**
 * 	numTenured: computes the number of tenured committee members
 **/
int Committee::numTenured() {
	// COMPLETE THIS METHOD
	// return included to allow the skeleton code to compile
	return 0;
}

std::unordered_set<std::string> Committee::getUniqueFields() {
	// COMPLETE THIS METHOD
	// return included to allow the skeleton code to compile
	return std::unordered_set<std::string>();
}

/**
determine whether the committee as currently constituted is "bad".

 @return true, if the committee meets the definition of bads (fewer than two 
 	  unique fields represented and an insufficient number of 
	  tenured professors), false otherwise.
**/
bool Committee::isBadCommittee() {
	// COMPLETE THIS METHOD
	// return included to allow the skeleton code to compile
	return false;
}
