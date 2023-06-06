'''
Distribution file of the restaurants problem containing the Restaurant class.

Please write your solution in the methods with TODO blocks.
'''

from typing import List
from reservation import Reservation


class Restaurant:
    '''
    Class for representing restaurants.
    
    Public attributes:
        -   name (str): The name of the restaurant.
    
    Public methods:
        -   make_reservation: Make a reservation at this restaurant for the 
            given party if possible.
        -   confirm_reservation: Confirm the reservation
    '''
    def __init__(self, name: str, num_tables: int) -> None:
        '''
        Constructor for Restaurant class.
        
        Parameters:
            -   name (str): The name of the restaurant.
            -   num_tables (int): The number of tables at the restaurant.
        
        Returns:
            None
        '''
        # TODO: Implement this method.
        pass

    def make_reservation(self, reservation: Reservation) -> bool:
        '''
        Assign tables if the reservation is feasible based on the number of 
        people in the party and the number of tables available.

        Parameters:
            -   reservation (Reservation): The reservation to make.

        Returns:
            True if the reservation was made, False otherwise.
        '''
        # TODO: Implement this method.
        pass

    def confirm_reservation(self, party_name: str, tables: List[int]) -> bool:
        '''
        Verify if the tables were assigned to a given party.
        
        Parameters:
            -   party_name (str): The name of the party.
            -   tables (List[int]): The tables to confirm.

        Returns:
            True if the tables listed in the reservation for the specified party 
            matches the specified tables. False otherwise.
        '''
        # TODO: Implement this method.
        pass