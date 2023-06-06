'''
Code to read input from the test files and test the solution.

The script will look for a complementary results file in the same directory as
the test file. The results file should have the same name as the test file,
except with a .ans extension. If the results file is not found, the script
will raise a warning and continue.

To run all tests in the tests directory, use the -a flag and indicate the
directory as the test file. For example, to run all tests in the tests
directory, use the following command:

    python test.py tests -a

Usage:
    python test.py <test_file> [-a]
'''


# Handle the fact that the test code may not
# be in the same directory as the solution code
import os
import sys
sys.path.insert(0, os.getcwd())

import test_helpers as th
import problem7 as problem


def get_test_data(test_file):
    '''
    Read the test file and return the test data.

    Parameters:
        -   test_file (str): The path to the test file.

    Returns:
        -   readings (int): The number of temperature readings.
        -   temperatures (list): The list of temperatures.
    '''
    # Read the test file
    with open(test_file) as input_file:
        lines = input_file.readlines()
        header = lines[0].split()
        lst = [int(x) for x in lines[1].split()]

    # Sanity check
    if len(header) != 3:
        raise ValueError('Invalid header.')
    
    # Getting header data
    length = int(header[0])
    i = int(header[1])
    x = int(header[2])

    if length != len(lst):
        raise ValueError('Invalid data length.')

    return lst, i, x


if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the cold solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)
        
        for test_file in test_files:
            # Get the test data
            lst, i, x = get_test_data(test_file)

            # Read the results file
            expected = th.get_int_list_from_file(test_file.replace('.in', '.ans'))

            # Compute the actual result
            problem.fill(lst, i, x)

            # Print the results
            th.print_results(test_file, expected, lst)

    elif args.test_file is not None:
        test_file = args.test_file
        lst, i, x = get_test_data(test_file)
        expected = th.get_int_list_from_file(test_file.replace('.in', '.ans'))
        problem.fill(lst, i, x)
        
        th.print_results_autograder(expected, lst)

    else:
        raise ValueError('Must provide either a test file or a test directory.')