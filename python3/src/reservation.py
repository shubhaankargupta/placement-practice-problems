'''
Distribution file of the restaurants problem containing the Reservation class.

Please do not modify this file. Your solution should be placed in restaurant.py.
'''

from typing import List

class Reservation:
    '''
    Class for representing requests for restaurant reservations.

    Public attributes:
        -   restaurant_name (str): The name of the restaurant.
        -   party_name (str): The name of the party.
        -   party_size (int): The size of the party.

    Public methods:
        -   assign_tables: Assign tables to this reservation.
        -   confirm_tables: Confirm the tables assigned to this reservation.
    '''
    def __init__(self, restaurant_name: str, party_name: str, party_size: int) -> None:
        '''
        Constructor for Reservation class.

        Parameters:
            -   restaurant_name (str): The name of the restaurant.
            -   party_name (str): The name of the party.
            -   party_size (int): The size of the party.

        Returns:
            None
        '''
        self.restaurant_name = restaurant_name
        self.party_name = party_name
        self.party_size = party_size
        self.__tables = []

    def assign_tables(self, tables: List[int]) -> None:
        '''
        Assign tables to this reservation, using a deep copy of the list of
        tables.
        
        Parameters:
            -   tables (List[int]): The tables to assign to this reservation.

        Returns:
            None
        '''
        self.__tables = tables.copy()

    def confirm_tables(self, tables: List[int]) -> bool:
        '''
        Confirm the given tables were assigned to this reservation.
        
        Parameters:
            -   tables (List[int]): The tables to confirm.

        Returns:
            True if the tables were assigned to this reservation, False
            otherwise.
        '''
        # We have to loop over the tables as we cannot compare lists directly,
        # even if they contain the same elements since they could be in 
        # different orders.
        for table in tables:
            if table not in self.__tables:
                return False
        
        return True