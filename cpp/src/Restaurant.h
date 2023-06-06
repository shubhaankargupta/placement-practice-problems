#ifndef _Restaurant_
#define _Restaurant_
#include <vector>
#include <string>
#include "Reservation.h"

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
class Restaurant {
public:
std::string name;
int numTablesAvailable;

/**
Constructor for Restaurant

 @param name the name of the restaurant represented as a string
 @param numTables the number of tables in the restaurant
     */
Restaurant(std::string name, int numTables);

/**
assign tables if the reservation is feasible based on the number of people 
in the party and the number of tables available.

  @param res a reservation request represented as a Reservation

  @return True if the reservation tables are assigned, false otherwise.
**/
bool makeReservation(Reservation res);

/**
verify the tables assigned to a given party.

 @param partyName the name of the party associated with a reservation
 @param tables an array of table numbers

 @return True if the tables listed in the reservation for the specified 
 party matches the specified tables. False, otherwise.
**/
bool checkReservation(std::string partyName, std::vector<int> tables);

private:
int nextTable;
std::vector<Reservation> reservations;
};

#endif