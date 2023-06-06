import java.util.List;
import java.util.ArrayList;

/**
 * Class for representing restaurants.
 *
 * Public attributes:
 *   name: the name of the restaurant represented as a string
 * 
 * Public methods:
 * makeReservation: assign tables if the reservation is feasible
 *   based on the number of people in the party and the number of
 *   tables available.
 * 
 * checkReservation: verify that the table assigned to a given party.
 **/
public class Restaurant {
    public String name;
    public int numTablesAvailable;

    // Additional attributes.

    /**
     * Constructor for Restaurant
     *
     * Arguments:
     *   name: the name of the restaurant represented as a string
     *   numTables: the number of tables in the restaurant
     */
    public Restaurant(String name, int numTables) {
        // COMPLETE THIS METHOD
    }

    /**
     * makeReservation: assign tables if the reservation is feasible
     *   based on the number of people in the party and the number of
     *   tables available.
     *   
     * Arguments
     *   res: a reservation request represented as a Reservation
     *
     * Returns: True if the reservation tables are assigned, false
     *   otherwise.
     **/
    public boolean makeReservation(Reservation res) {
        // COMPLETE THIS METHOD
        // Return included to allow the skeleton code to compile
        return false;
    }

    
    /**
     * checkReservations: verify the tables assigned to
     *   a given party.
     *
     * Arguments:
     *   partyName: the name of the party associated with a reservation
     *   tables: an array of table numbers
     *
     * Returns: True if the tables listed in the reservation for the
     *   specified party matches the specified tables. False,
     *   otherwise.
     **/
    public boolean confirmReservation(String partyName, int[] tables) {
        // COMPLETE THIS METHOD
        // Return included to allow the skeleton code to compile
        return false;
    }
}

