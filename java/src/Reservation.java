import java.util.Arrays;

/**
 * Class for representing requests for restaurant reservations.
 *
 * Public attributes:
 *   partyName: the name of the party making the reservation represented as a string
 *   partySize: the number of people in the party represented as an integer
 *
 * Public methods:
 *   assignTables: update the tables assigned to a reservation.
 *
 *   confirmTables: confirm the tables assigned to a given reservation.
 */
class Reservation {
    public String restaurantName;
    public String partyName;
    public int partySize;
    private int[] assignedTables;

    /**
     * Constructor for Reservation
     *
     * Arguments:
     *   partyName: the name of the party making the reservation represented as a string
     *   partySize: the number of people in the party represented as an integer
     **/
    public Reservation(String restaurantName, String partyName, int partySize) {
        this.restaurantName = restaurantName;
        this.partyName = partyName;
        this.partySize = partySize;
        this.assignedTables = null;
    }


    /**
     * assignTables: assign specific tables to the reservation.
     *
     * Argument:
     *   tables: an array of integer table numbers to be assigned to the reservation.
     *
     **/
    public void assignTables(int[] tables) {
        this.assignedTables = new int[tables.length];
        for (int i = 0; i < tables.length; i++) { 
            this.assignedTables[i] = tables[i];
        }
    }


    /**
     * confirmAssignment: confirm that the specified tables have been
     *   assigned to the reservation (in the order given).
     *
     * Argument:
     *   tables: an array of integer table numbers to be assigned to the reservation.
     *
     * Returns: True, if the tables assigned to the reservation match
     *   the specified tables.  False, otherwise.
     **/
    public boolean confirmTables(int[] tables) {
        if ((this.assignedTables == null) ||
            (this.assignedTables.length != tables.length)) {
            return false;
        }

        for (int i = 0; i < tables.length; i++) {
            if (this.assignedTables[i] != tables[i]) {
                return false;
            } 
        }

        return true;
    }
}
