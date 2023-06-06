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
from professor import Professor
from committee import Committee


def load_problem_file(filename):
    '''
    Loads the problem data into a list of committee objects.
    
    Parameters:
        -   filename (str): The path to the problem file.

    Returns:
        -   committees (List[Committee]): The list of committees. None if the
            loading process fails the multi-addition test.
    '''
    # Load raw input
    input = th.get_test_string(filename)
    input = input.strip().split('\n')

    # Get the number of committees and professors
    num_professors, num_committees = (int(val) for val in input[0].split())

    # Get the professors
    professors = []
    for professor in input[1:1 + num_professors]:
        professor_details = professor.split()
        fields = professor_details[2:]
        tenured = professor_details[1] == 'T'
        professors.append(Professor(professor_details[0], tenured, fields))

    # Build dictionary of prof name to prof object for easy lookup in the
    # committee creation step
    professor_dict = {professor.name: professor for professor in professors}

    # Get the committees
    committees = []
    for committee in input[1 + num_professors:]:
        committee_details = committee.split()
        committee_name = committee_details[0]
        committee_obj = Committee(committee_name)
        committee_members = [professor_dict[name] for name in committee_details[1:]]

        # Check for multi-addition of professors
        for professor in committee_members:
            committee_obj.add_member(professor)

            if committee_obj.add_member(professor):
                return None
            
        committees.append(committee_obj)

    return committees


def load_results_file(filename):
    '''
    Loads the results data into a list of committee names.

    Parameters:
        -   filename (str): The path to the results file.

    Returns:
        -   results (List[str]): The list of committee names.
    '''
    # Load raw input
    input = th.get_test_string(filename)

    # Check for none
    if 'NONE' in input:
        return []

    # Make into list
    results = input.strip().split('\n')
    results = [result.strip() for result in results]

    return results
    

if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the restaurant solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)

        for test_file in test_files:
            committees = load_problem_file(test_file)

            if committees is None:
                print(f'Test {test_file} failed. Multi-addition of professors detected.')
                continue

            expected = load_results_file(test_file.replace('.in', '.ans'))

            actual = []
            for committee in committees:
                if committee.is_bad_committee():
                    actual.append(committee.name)

            th.print_results(test_file, expected, actual)
    
    elif args.test_file is not None:
        committees = load_problem_file(args.test_file)

        if committees is None:
            print('FAILED')
            sys.exit(0)

        expected = load_results_file(args.test_file.replace('.in', '.ans'))

        actual = []
        for committee in committees:
            if committee.is_bad_committee():
                actual.append(committee.name)

        th.print_results_autograder(set(expected), set(actual))

    else:
        raise ValueError('Must provide either a test file or a test directory.')