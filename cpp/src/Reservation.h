#ifndef _Reservation_
#define _Reservation_
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
class Reservation {
public:
std::string restaurantName;
std::string partyName;
int partySize;

/**
Constructor for Reservation

 @param partyName the name of the party making the reservation represented as a string
 @param partySize the number of people in the party represented as an integer
**/

Reservation(std::string& restaurantName, std::string& partyName, int partySize);


/**
assign specific tables to the reservation.

 @param tables an array of integer table numbers to be assigned to the reservation.
**/
void assignTables(std::vector<int> tables);

/**
confirm that the specified tables have been assigned to the reservation
(in the order given).

 @param tables an array of integer table numbers to be assigned to the reservation.

 @return True, if the tables assigned to the reservation match the specified tables.
    False, otherwise.
**/
bool confirmTables(std::vector<int> tables);


private:
std::vector<int> assignedTables;
};

#endif