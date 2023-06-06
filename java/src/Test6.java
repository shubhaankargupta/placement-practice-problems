import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.*;
import java.util.Set;
import java.util.HashSet;
import java.util.NoSuchElementException;

public class Test6 extends Test {
    /**
     * runTest: run the test specified in the file
     *
     * Arguments:
     *   f: a file containing the test
     *   verbose: true, if more than just pass/fail should be printed
     *
     * Returns: True, if the test passed, false otherwise.
     **/
    public boolean runTest(File f, boolean verbose) {
	String inputFilename = f.getPath();
	int i, j;
	int line = 0;
	int numProfessors = 0;
	int numCommittees = 0;
	HashMap<String, Professor> professors = new HashMap<String, Professor>();
	List<Committee> committees = new ArrayList<Committee>();


	try {
	    Scanner scanner = new Scanner(f);
	    String[] parameters = scanner.nextLine().split(" ");
	    numProfessors = Integer.parseInt(parameters[0]);
	    numCommittees = Integer.parseInt(parameters[1]);
	    String[] data;

	    for (i = 0; i < numProfessors; i++) {
		line++;
		// format: name, T/F, field names separated by spaces
		data = scanner.nextLine().split(" ");
		// constrct the array of fields
		String[] areas = new String[data.length - 2];
		for (j = 2; j < data.length; j++) {
		    areas[j - 2] = data[j];
		}

		// Add professor to the hashtable for later use.
		Professor p = new Professor(data[0], data[1].equals("T"), areas);
		professors.put(data[0], p);
	    }

	    // Construct the committees
	    for (i = 0; i < numCommittees; i++) {
		line++;		
		// format: committee name, names of committee members separated by spaces
		String nl = scanner.nextLine();
		data = nl.split(" ");
		String committeeName = data[0];
		Committee c = new Committee(committeeName);
		for (j = 1; j < data.length; j++) {
		    if (!c.addMember(professors.get(data[j]))) {
			if (verbose) {
			    System.out.println(String.format("Attempt to add %s to %s should have succeeded", data[j], committeeName));
			}
			return false;
		    }
		}

		// check dups
		for (j = 1; j < data.length; j++) {
		    if (c.addMember(professors.get(data[j]))) {
			if (verbose) {
			    System.out.println(String.format("Attempt to add %s a second time to %s should have failed", data[j], committeeName));
			}
			return false;
		    }
		}
		committees.add(c);
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
	} catch (Exception e) {
	    if (verbose) {
		System.out.println("Caught unexpected exception: " + e);
	    }
	    return false;
	}


	File resultsFile = TestHelpers.getResultsFile(f);
	Set<String> invalidCommittees = new HashSet<String>();
	line = 0;
	try {
	    Scanner scanner = new Scanner(resultsFile);
	    while (scanner.hasNextLine()) {
		String cname = scanner.nextLine();
		if (cname.equals("NONE")) {
		    break;
		} else {
		    invalidCommittees.add(cname);
		}
	    }
	} catch (FileNotFoundException e) {
	    if (verbose) {
		System.out.println("Results file not found:" + inputFilename);
	    }
	    return false;
	} catch (Exception e) {
	    if (verbose) {
		System.out.println("Caught unexpected exception:" + e);
	    }
	    return false;
	}


	try {
	    for (Committee c: committees) {
		if (invalidCommittees.contains(c.name)) {
		    if (!c.isBadCommittee()) {
			if (verbose) {
			    System.out.println(String.format("Committee %s should be labelled as invalid", c.name));
			}
			return false;
		    }
		} else {
		    if (c.isBadCommittee()) {
			if (verbose) {
			    System.out.println(String.format("Committee %s should not be labelled as invalid", c.name));
			}
			return false;
		    }
		}
	    }
	} catch (Exception e) {
	    if (verbose) {
		System.out.println("Caught unexpected exception: " + e);
	    }
	    return false;
	}
	
	return true;
    }


    public static void main(String[] args) {
	System.exit(TestHelpers.doTests(args, new Test6()));
    }
}

