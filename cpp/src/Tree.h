#ifndef _Tree_
#define _Tree_
#include <vector>
#include <string>

/**
Class for representing an employee and the people who report to them.

Public attributes:
 empNum: the employee's employee number represented as an integer
 salary: the employee's salary represented as an integer
 children: a list of the employee's direct reports

 Public methods:
  addDirectReport: add a new direct report to the tree
  printTree: print the contents of the tree.
 **/
class Tree {
public:
int empNum;
int salary;
std::vector<Tree*> children;

/**
Constructor for Tree

 @param empNum the employee's employee number represented as an integer
 @param salary the employee's salary represented as an integer
**/
Tree(int _empNum, int _salary);

/** 
add a new direct report

 @param t the new direct report represented as a Tree
**/
void addDirectReport(Tree* t);

/**
print the contents of the tree, indented to illustrate the tree structure

 @param tabs a string with spaces that tracks the indentation level
**/
void printTree(std::string tabs);
};

#endif