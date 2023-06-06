#include "Restaurant.h"
#include <vector>
#include <string>

/**
    Class for representing restaurants.

    Public attributes:
    name: the name of the restaurant represented as a string

    Public methods:
    makeReservation: assign tables if the reservation is feasible
    based on the number of people in the party and the number of
    tables available.

    checkReservation: verify that the table assigned to a given party.
**/
Restaurant::Restaurant(std::string _name, int _numTables) {
    // COMPLETE THIS METHOD
}

/**
assign tables if the reservation is feasible based on the number of people 
in the party and the number of tables available.

  @param res a reservation request represented as a Reservation

  @return True if the reservation tables are assigned, false otherwise.
**/
bool Restaurant::makeReservation(Reservation res) {
    // COMPLETE THIS METHOD
    // Return included to allow the sketelon code to complile
    return false;
}

/**
verify the tables assigned to a given party.

 @param partyName the name of the party associated with a reservation
 @param tables an array of table numbers

 @return True if the tables listed in the reservation for the specified 
 party matches the specified tables. False, otherwise.
**/
bool Restaurant::checkReservation(std::string partyName, std::vector<int> tables) {
    // COMPLETE THIS METHOD
    // Return included to allow the sketelon code to complile
    return false;
}
