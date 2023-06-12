'''
Helper functions for the test driver module.
'''

import argparse
import os
import sys
from collections.abc import Iterable

def create_parser(description):
    '''
    Create an argument parser for the test driver.

    Parameters:
        -   description (str): The description of the program.

    Returns:
        -   parser (argparse.ArgumentParser): The argument parser.
    '''
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('-t', '--test_file', type=str,
                        default=None,
                        help='The path to the test file.')
    parser.add_argument('-a', '--test_dir', type=str,
                        default=None,
                        help='The path to the test directory.')
    return parser


def read_results_file(results_file):
    '''
    Read the results file and return the lines as a string. Note that this function
    does not do any sanity checking or parsing of the input.

    Parameters:
        -   results_file (str): The path to the results file.

    Returns:
        -   expected (str): The expected results.
    '''
    try:
        with open(results_file.replace('.in', '.ans')) as results_file:
            expected = results_file.read()
    except FileNotFoundError:
        print('Warning: results file not found.')
        expected = None

    return expected


def print_results(test_file, expected, actual):
    '''
    Print the results of the test. If the test passed, only print that the test
    passed along with the test file name. If the test failed, print the difference
    between the expected and actual results.

    Arguments:
        -  test_file (str): The path to the test file.
        -   expected (str): The expected results.
        -   actual (str): The actual results.

    Returns:
        -   None
    '''
    if expected == actual:
        print(f'Test {test_file} passed.')
    else:
        # Scalar value comparison
        if isinstance(expected, (float, int, str, bool)):
            print(f'Test {test_file} failed. Expected {expected}, got {actual}.')

        # Iterable value comparison, determine index of first difference
        elif isinstance(expected, Iterable):
            if not isinstance(actual, Iterable):
                print(f'Test {test_file} failed. Expected a list of values, but got {actual}.')
                return

            check_len = min(len(expected), len(actual))
            for i in range(check_len):
                if expected[i] != actual[i]:
                    print(f'Test {test_file} failed. First difference at index {i}.')
                    return

        # Miscellaneous errors
        else:
            print(f'Test {test_file} failed.')

    return


def print_results_autograder(expected, actual):
    if expected == actual:
        print('PASSED')
        sys.exit(42)
    else:
        print('FAILED')
        sys.exit(0)


def get_test_files(test_dir):
    '''
    Get the list of test files in the given directory.

    Parameters:
        -   test_dir (str): The path to the test directory.

    Returns:
        -   test_files (list): The list of test files.
    '''
    test_files = []

    for file in os.listdir(test_dir):
        if file.endswith('.in'):
            test_files.append(f'{test_dir}/{file}')

    return test_files


def get_test_string(test_file):
    '''
    Get the test string from the given test file.

    Parameters:
        -   test_file (str): The path to the test file.

    Returns:
        -   test_string (str): The test string.
    '''
    with open(test_file) as test_file:
        test_string = test_file.read()

    return test_string


def get_int_list_from_file(filename):
    '''
    Read the data from a file that contains a list of integers formatted as:
        number_of_values
        value value value...

        or

        value value value...

    Arguments:
        -   filename (str): The path to the file.

    Returns:
        -  values (list): The list of values.
    '''
    values = None

    with open(filename) as file:
        lines = file.readlines()

    if len(lines) == 2:
        values = lines[1].split()
        values = [int(value) for value in values]

        assert len(values) == int(lines[0]), \
            'Number of values does not match number of values in file.'
    else:
        values = [int(line) for line in lines[0].split()]

    return values