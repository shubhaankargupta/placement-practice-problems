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
import problem4 as problem

def load_problem_data(filename):
    '''
    Load the problem data from the given file and a string, the length of the
    k-mers, and a list of k-mers.

    Arguments:
        -   filename (str): The path to the file.

    Returns:
        -   seq (str): The sequence of letters.
        -   k (int): The length of the k-mers.
        -   k_mers (list): The list of k-mers.
    '''
    input_string = th.get_test_string(filename)
    lines = input_string.strip().split('\n')

    # Header
    seq_line_num, _, kmer_len, _ = (int(value) for value in lines[0].split())

    # Loading the sequence
    seq = ''.join(lines[1:seq_line_num + 1])

    # Loading the k-mers
    k_mers = lines[seq_line_num + 1:]

    return seq, kmer_len, k_mers


def load_results_data(filename):
    '''
    Load the results data from the given file and return a dictionary of k-mers
    and their counts.

    Arguments:
        -   filename (str): The path to the file.

    Returns:
        -   k_mer_counts (dict): A dictionary of k-mers and their counts.
    '''
    input_string = th.get_test_string(filename)
    lines = input_string.strip().split('\n')

    # Loading the k-mer counts
    k_mer_counts = {}

    for line in lines:
        k_mer, count = line.split()
        k_mer_counts[k_mer] = int(count)

    return k_mer_counts


if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the cold solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)

        for test_file in test_files:
            # Get the test data
            seq, k, k_mers = load_problem_data(test_file)

            # Read the results file
            expected = load_results_data(test_file.replace('.in', '.ans'))

            # Compute the actual result
            actual = problem.kmers(seq, k, k_mers)
            actual = dict(zip(k_mers, actual))

            # Print the results
            th.print_results(test_file, expected, actual)
    elif args.test_file is not None:
        test_file = args.test_file

        # Get the test data
        seq, k, k_mers = load_problem_data(test_file)

        # Read the results file
        expected = load_results_data(test_file.replace('.in', '.ans'))

        # Compute the actual result
        actual = problem.kmers(seq, k, k_mers)
        actual = dict(zip(k_mers, actual))

        # Print the results
        th.print_results_autograder(expected, actual)

    else:
        raise ValueError('Must provide either a test file or a test directory.')