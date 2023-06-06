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
import problem3 as problem

def load_cards(filename):
    '''
    Load the cards from the given file.

    Parameters:
        -   filename (str): The path to the file containing the cards.

    Returns:
        -   hand1 (list[str]): The cards in hand 1.
        -   hand2 (list[str]): The cards in hand 2.
    '''
    hand1 = []
    hand2 = []

    with open(filename) as file:
        lines = file.readlines()

    hand1 = lines[1].strip().split()
    hand2 = lines[2].strip().split()

    return hand1, hand2


if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the cold solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)

        for test_file in test_files:
            # Get the test data
            hand1, hand2 = load_cards(test_file)

            # Read the results file
            expected = th.read_results_file(test_file)
            expected = expected.strip()

            # Compute the actual result
            actual = problem.tricky(hand1, hand2)

            # Print the results
            th.print_results(test_file, expected, actual)
    
    elif args.test_file is not None:
        test_file = args.test_file

        hand1, hand2 = load_cards(test_file)

        expected = th.read_results_file(test_file)
        expected = expected.strip()

        actual = problem.tricky(hand1, hand2)

        th.print_results_autograder(expected, actual)

    else:
        raise ValueError('Must provide either a test file or a test directory.')