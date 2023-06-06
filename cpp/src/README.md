This directory contains the skeleton code for working on the practice problems.
To solve the problems, you must only edit the following files.

- **Problem 1**: `Problem1.cpp`  
- **Problem 2**: `Problem2.cpp`  
- **Problem 3**: `Problem3.cpp`  
- **Problem 4**: `Problem4.cpp`
- **Problem 5**: `Restaurant.cpp`
- **Problem 6**: `Committee.cpp`
- **Problem 7**: `Problem7.cpp`  
- **Problem 8**: `Problem8.cpp`  

You will find additional files in this directory. **Do not** edit those files (they
are auxiliary files needed to run and test your code).

For each problem, we have provided a testing program that checks your
solution against some test data.  Here are instructions for compiling the
test code for each problem:

- **Problem 1**: `c++ --std=gnu++17 Problem1.cpp Test1.cpp TestHelpers.cpp -o test1`
- **Problem 2**: `c++ --std=gnu++17 Problem2.cpp Test2.cpp TestHelpers.cpp -o test2`
- **Problem 3**: `c++ --std=gnu++17 Problem3.cpp Test3.cpp TestHelpers.cpp -o test3`
- **Problem 4**: `c++ --std=gnu++17 Problem4.cpp Test4.cpp TestHelpers.cpp -o test4`
- **Problem 5**: `c++ --std=gnu++17 Restaurant.cpp Reservation.cpp Test5.cpp TestHelpers.cpp -o test5`
- **Problem 6**: `c++ --std=gnu++17 Committee.cpp Professor.cpp Test6.cpp TestHelpers.cpp -o test6`
- **Problem 7**: `c++ --std=gnu++17 Problem7.cpp Test7.cpp TestHelpers.cpp -o test7`
- **Problem 8**: `c++ --std=gnu++17 Problem8.cpp Test8.cpp TestHelpers.cpp Tree.cpp -o test8`

The command-line interface is the same for all the test programs. For
example, to run the (compiled) test code for problem 1, on a single
test file, run:

    ./test1 -t <path to test file>

e.g.

    ./test1 -t ../test-data/problem1/001.in

To run all the tests for problem 1, run:

    ./test1 -a ../test-data/problem1

