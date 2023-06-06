#include "Tree.h"
#include <vector>
#include <string>
#include <iostream>

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
Tree::Tree(int _empNum, int _salary): empNum(_empNum), salary(_salary),
children(std::vector<Tree*>()) {}

/** 
add a new direct report

 @param t the new direct report represented as a Tree
**/
void Tree::addDirectReport(Tree* t) {
    children.push_back(t);
}

/**
print the contents of the tree, indented to illustrate the tree structure

 @param tabs a string with spaces that tracks the indentation level
**/
void Tree::printTree(std::string tabs) {
    std::cout << tabs << empNum << " " << salary << "\n";
    for (Tree* t : children) {
        t->printTree(tabs + "  ");
    }
}