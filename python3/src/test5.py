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
from restaurant import Restaurant
from reservation import Reservation


def load_problem_file(filename):
    '''
    Load the problem file and return the list of restaurants. Applies the 
    given reservation to the restaurants.

    Args:
        filename: Name of the file containing the problem data.

    Returns:
        Dictionary of Restaurant objects.
    '''
    # Read the file header
    input = th.get_test_string(filename)
    input = input.split('\n')
    header = input[0]
    restaurant_num, _ = map(int, header.split())

    # Read the restaurants
    restaurants = {}
    for restaurant in input[1:restaurant_num + 1]:
        restaurant = restaurant.split()
        restaurants[restaurant[0]] = Restaurant(restaurant[0], int(restaurant[1]))

    # Read and apply the reservations
    for reservation in input[restaurant_num + 1:]:
        reservation = reservation.split()
        restaurant_name = reservation[0]
        party_name = reservation[1]
        party_size = int(reservation[2])

        reservation_obj = Reservation(restaurant_name, party_name, party_size)
        restaurants[restaurant_name].make_reservation(reservation_obj)

    return restaurants


def load_results_file(filename):
    '''
    Load the results file and return the list of expected reservations.
    
    Args:
        filename: Name of the file containing the results data.

    Returns:
        List of tuples containing a reservations restaurant name, party name,
        and a list of assigned tables.
    '''
    input_str = th.get_test_string(filename)
    input_lines = input_str.split('\n')

    # Read the reservations
    reservations = []
    for line in input_lines[1:]:
        line = line.split()
        restaurant_name = line[0]
        party_name = line[1]
        tables = list(map(int, line[2:]))
        reservations.append((restaurant_name, party_name, tables))

    return reservations


def test_restaurants(filename):
    '''
    Test the restaurants problem. Abstracts away the details of reading the
    input and results files.

    Args:
        filename: Name of the file containing the problem data.

    Returns:
        True if the test passed, False otherwise.
    '''
    # Load the problem file
    restaurants = load_problem_file(filename + '.in')

    # Load the results file
    expected_reservations = load_results_file(filename + '.ans')

    # Check reservations
    for expected_reservation in expected_reservations:
        # Unpack the expected reservation
        restaurant_name, party_name, tables = expected_reservation

        # Get the restaurant
        restaurant = restaurants[restaurant_name]
        if not restaurant.confirm_reservation(party_name, tables):
            return False
        
    return True


if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the restaurant solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)

        for test_file in test_files:
            test_file = test_file.replace('.in', '')
            results = test_restaurants(test_file)

            if results:
                print(f'Test {test_file} passed.')
            else:
                print(f'Test {test_file} failed.')
    
    elif args.test_file is not None:
        test_file = args.test_file.replace('.in', '')
        results = test_restaurants(test_file)

        if results:
            print('PASSED')
            sys.exit(42)
        else:
            print('FAILED')
            sys.exit(0)