import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.*;
import java.util.NoSuchElementException;

public class Test5 extends Test {
    /**
     * runTest: run the test specified in the file
     *
     * Arguments:
     *   f: a file containing the test
     *   version: true, if more than pass/fail should be printed
     *
     * Returns: True, if the test passed, failed otherwise.
     **/
    public boolean runTest(File f, boolean verbose) {
	String inputFilename = f.getPath();
	int line = 0;
	HashMap<String, Restaurant> restaurants = new HashMap<String, Restaurant>();
	int unconfirmed = 0;
	int numRestaurants = 0;
	int numReservations = 0;
	int i;
	Restaurant r;

	try {
	    Scanner scanner = new Scanner(f);
	    String[] parameters = scanner.nextLine().split(" ");
	    numRestaurants = Integer.parseInt(parameters[0]);
	    numReservations = Integer.parseInt(parameters[1]);
	    String[] data;

	    for (i = 0; i < numRestaurants; i++) {
		line++;
		data = scanner.nextLine().split(" ");
		r = new Restaurant(data[0], Integer.parseInt(data[1]));
		restaurants.put(data[0], r);
	    }

	    for (i = 0; i < numReservations; i++) {
		line++;		
		data = scanner.nextLine().split(" ");
		if (!restaurants.containsKey(data[0])) {
		    if (verbose) {
			System.out.println(String.format("Bad reservation at line %d", line));
		    }
		    return false;
		}
		r = restaurants.get(data[0]);
		Reservation res = new Reservation(data[0], data[1], Integer.parseInt(data[2]));
		if (!r.makeReservation(res)) {
		    unconfirmed++;
		}
	    }
	} catch (FileNotFoundException e) {
	    if (verbose) {
		System.out.println("File not found:" + inputFilename);
	    }
	    return false;
	} catch (NumberFormatException e) {
	    if (verbose) {
		System.out.println("Format error: line " + line);
	    }
	    return false;
	} catch (ArrayIndexOutOfBoundsException e) {
	    if (verbose) {
		System.out.println("Format error: line " + line);
	    }
	    return false;
	}


	File resultsFile = TestHelpers.getResultsFile(f);
	line = 0;
	try {
	    Scanner scanner = new Scanner(resultsFile);
	    int expected_unconfirmed = Integer.parseInt(scanner.nextLine());

	    if (unconfirmed != expected_unconfirmed) {
		if (verbose) {
		    System.out.println(String.format("Actual value for the number of unconfirmed reservations (%d) does not match the expected value of unconfirmed reservations (%d)", unconfirmed, expected_unconfirmed));
		}
		return false;
	    }

	    for (i = 0; i < numReservations - unconfirmed; i++) {
		line++;
		String[] values = scanner.nextLine().split(" ");
		String rname = values[0];
		String pname = values[1];
		if (!restaurants.containsKey(rname)) {
		    if (verbose) {
			System.out.println(String.format("Cannot find restaurant for %s", rname));
		    }
		    return false;
		}
		r = restaurants.get(rname);
		int[] tables = new int[values.length - 2];
		for (int j = 2; j < values.length; j++) {
		    tables[j - 2] = Integer.parseInt(values[j]);
		}

		if (!r.confirmReservation(pname, tables)) {
		    if (verbose) {
			System.out.println(String.format("Reservation for %s @ %s is not correct.", pname, rname));
		    }
		    return false;
		}
	    }
	    return true;
	} catch (FileNotFoundException e) {
	    if (verbose) {
		System.out.println("Results file not found:" + inputFilename);
	    }
	    return false;
	} catch (NumberFormatException e) {
	    if (verbose) {
		System.out.println("Results file format error: line " + line);
	    }
	    return false;
	} catch (ArrayIndexOutOfBoundsException e) {
	    if (verbose) {
		System.out.println("Results file format error: line " + line);
	    }
	    return false;
	}
    }


    public static void main(String[] args) {
	System.exit(TestHelpers.doTests(args, new Test5()));	
    }
}
