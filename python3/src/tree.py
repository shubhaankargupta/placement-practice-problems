'''
Tree class for representing an employee and their subordinates. Used in the 
inversion problem.

Please do not modify this file. Your solution should be implemented in the
corresponding problem.py file.
'''

from typing import List

class Tree:
    '''
    Class encapsulating information about an employee and their subordinates.

    Public attributes:
        -   employee_num (int): The employee number of the employee.
        -   salary (int): The salary of the employee.
        -   children (List[Tree]): The subordinates of the employee.

    Public methods:
        -    add_direct_report: Add a new direct report to the tree
        -    print_tree: Print the contents of the tree
    '''    
    def __init__(self, name: int, salary: int) -> None:
        '''
        Constructor for Tree class.
        
        Parameters:
            -   name (str): The name of the employee.
            -   salary (int): The salary of the employee.
            
        Returns:
            None
        '''
        self.name = name 
        self.salary = salary  
        self.children: List['Tree'] = []

    def add_direct_report(self, other_tree: 'Tree') -> None:
        '''
        Add a child to this tree corresponding to a subordinate employee of the
        parent tree.

        Parameters:
            -   other_tree (Tree): The tree to add as a child.

        Returns:
            None
        '''
        self.children.append(other_tree)
    
    def print_tree(self, indent: int = 0) -> None:
        '''
        Print the contents of this tree.
        
        Parameters:
            -   indent (int): The number of spaces to indent the tree by.
            
        Returns:
            None
        '''
        print(" " * indent + f"{self.name} {self.salary}")

        for child in self.children:
            child.print_tree(indent + 4)
