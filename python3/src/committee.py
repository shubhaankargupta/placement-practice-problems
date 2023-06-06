'''
Distribution file for the committees problem containing the Committee class.

Please implement your solution in this file by filling in the TODOs.
'''

from typing import List, Set
from professor import Professor

class Committee:
    '''
    Class encapsulating information about a committee.

    Public attributes:
        -   name (str): The name of the committee.
        -   members (List[Professor]): The professors on the committee.

    Public methods:
        -   add_member: Add a professor to the committee.
        -   is_bad_committee: Check if the committee is invalid according to
            the criteria in the problem statement.
    '''
    def __init__(self, name: str) -> None:
        '''
        Constructor for Committee class.

        Parameters:
            -   name (str): The name of the committee.

        Returns:
            None
        '''
        # TODO: Implement this method
        pass

    def add_member(self, professor: Professor) -> bool:
        '''
        Add a professor to the committee if the professor is not already on the
        committee.

        Parameters:
            -   professor (Professor): The professor to add.

        Returns:
            True if the professor was added, False otherwise.
        '''
        # TODO: Implement this method
        pass

    def __num_member(self) -> int:
        '''
        Return the number of members on this committee.

        Parameters:
            None

        Returns:
            The number of members on this committee.
        '''
        # TODO: Implement this method
        pass

    def __num_tenured(self) -> int:
        '''
        Return the number of tenured professors on this committee.

        Parameters:
            None

        Returns:
            The number of tenured professors on this committee.
        '''
        # TODO: Implement this method
        pass

    def __get_unique_fields(self) -> Set[str]:
        '''
        Return the unique fields of the professors on this committee.

        Parameters:
            None

        Returns:
            The unique fields of the professors on this committee.
        '''
        # TODO: Implement this method
        pass

    def is_bad_committee(self) -> bool:
        '''
        Check if this committee is bad according to the criteria in the
        problem statement.

        Parameters:
            None

        Returns:
            True if this committee is invalid, False otherwise.
        '''
        # TODO: Implement this method
        pass