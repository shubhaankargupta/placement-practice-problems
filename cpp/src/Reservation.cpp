#include "Reservation.h"
#include <vector>
#include <string>


/**
    Class for representing requests for restaurant reservations.

    Public attributes:
    partyName: the name of the party making the reservation represented as a string
    partySize: the number of people in the party represented as an integer

    Public methods:
    assignTables: update the tables assigned to a reservation.

    confirmTables: confirm the tables assigned to a given reservation.
*/
Reservation::Reservation(std::string& _restaurantName,
                         std::string& _partyName,
                         int _partySize): restaurantName(_restaurantName),
                                          partyName(_partyName),
                                          partySize(_partySize),
                                          assignedTables(std::vector<int>(0, 0)) {}

/**
assign specific tables to the reservation.

 @param tables an array of integer table numbers to be assigned to the reservation.
**/
void Reservation::assignTables(std::vector<int> tables) {
    for (int i = 0; i < tables.size(); ++i) {
        assignedTables.push_back(tables[i]);
    }
}

/**
confirm that the specified tables have been assigned to the reservation
(in the order given).

 @param tables an array of integer table numbers to be assigned to the reservation.

 @return True, if the tables assigned to the reservation match the specified tables.
    False, otherwise.
**/
bool Reservation::confirmTables(std::vector<int> tables) {
    if ((assignedTables.size() == 0) || assignedTables.size() != tables.size()) {
        return false;
    }

    for (int i = 0; i < tables.size(); ++i) {
        if (assignedTables[i] != tables[i]) {
            return false;
        }
    }
    return true;
}
