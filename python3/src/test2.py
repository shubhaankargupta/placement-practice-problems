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
import problem2 as problem


if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the cold solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)

        for test_file in test_files:
            # Get the test data
            measurements = th.get_int_list_from_file(test_file)

            # Read the results file
            expected = th.read_results_file(test_file)
            # Account for the fact that the expected result may be a string
            try:
                expected = int(expected.strip())
            except ValueError:
                expected = None

            # Compute the actual result
            actual = problem.raindrops(measurements)

            # Print the results
            th.print_results(test_file, expected, actual)
        
    elif args.test_file is not None:
        test_file = args.test_file

        measurements = th.get_int_list_from_file(test_file)

        expected = th.read_results_file(test_file)
        try:
            expected = int(expected.strip())
        except ValueError:
            expected = None

        actual = problem.raindrops(measurements)

        th.print_results_autograder(expected, actual)

    else:
        raise ValueError('Either a test file or a test directory must be provided.')