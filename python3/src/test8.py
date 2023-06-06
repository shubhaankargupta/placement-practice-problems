'''
Skeleton code to read input from files and test the solution.

The script will look for a complementary results file in the same directory as
the test file. The results file should have the same name as the test file,
except with a .ans extension. If the results file is not found, the script
will raise a warning and continue.

Usage:
    python skeleton.py <test_file>
'''

# Handle the fact that the test code may not
# be in the same directory as the solution code
import os
import sys
sys.path.insert(0, os.getcwd())

import test_helpers as th
from tree import Tree
import problem8 as problem

def load_tree(filename):
    '''
    Loads the employee tree from a file.

    Parameters:
        -   filename (str): The name of the file to load the tree from.

    Returns:
        The root of the tree.
    '''
    input_lines = th.get_test_string(filename).strip().split('\n')
    employee_count = int(input_lines[0])

    # Create the tree nodes
    employees = {}
    for line in input_lines[1:1 + employee_count]:
        employee_num, salary = (int(x) for x in line.split())
        employees[employee_num] = Tree(employee_num, salary)

    # Structure the tree
    for line in input_lines[1 + employee_count:]:
        boss, subordinate = (int(x) for x in line.split())
        employees[boss].add_direct_report(employees[subordinate])

    return employees[1]


if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the cold solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)

        for test_file in test_files:
            # Get the test data
            tree_root = load_tree(test_file)

            # Read the results file
            expected = th.read_results_file(test_file)
            expected = int(expected.strip())

            # Compute the actual result
            actual = problem.solve(tree_root)

            # Print the results
            th.print_results(test_file, expected, actual)
    
    elif args.test_file is not None:
        test_file = args.test_file

        tree_root = load_tree(test_file)

        expected = th.read_results_file(test_file)
        expected = int(expected.strip())

        actual = problem.solve(tree_root)

        th.print_results_autograder(expected, actual)

    else:
        raise ValueError('Must provide either a test file or a test directory.')