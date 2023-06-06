'''
Distribution file for the committees problem containing the Professor class.

Your solution should be placed in committees.py, not this file.
'''

from typing import List, Set

class Professor:
    '''
    Class encapsulating information about a professor.

    Public attributes:
        -   name (str): The name of the professor.
        -   tenured (bool): Whether the professor is tenured.
        -   fields (Set[str]): The fields the professor works in.
    '''
    def __init__(self, name: str, tenured: bool, fields: List[str]) -> None:
        '''
        Constructor for Professor class.

        Parameters:
            -   name (str): The name of the professor.
            -   tenured (bool): Whether the professor is tenured.
            -   fields (List[str]): The fields the professor works in.

        Returns:
            None
        '''
        self.name = name
        self.tenured = tenured
        self.fields = set(fields)