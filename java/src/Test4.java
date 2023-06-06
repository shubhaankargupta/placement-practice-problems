import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.*;
import java.util.NoSuchElementException;

public class Test4 extends Test {
    public boolean runTest(File f, boolean verbose) {
	String inputFilename = f.getPath();
	String seq = "";
	int line = 0;
	int i = 0;
	int K = 0;
	String[] mers = null;
	int numKmers;

	try {
	    Scanner scanner = new Scanner(f);
	    String[] parameters = scanner.nextLine().split(" ");
	    int numTestLines = Integer.parseInt(parameters[0]);
	    K = Integer.parseInt(parameters[2]);
	    numKmers = Integer.parseInt(parameters[3]);	    

	    for (i = 0; i < numTestLines; i++) {
		line = line + 1;
		String data = scanner.nextLine();
		seq = seq + data;
	    }

	    mers = new String[numKmers];
	    for (i = 0; i < numKmers; i++) {
		String mer = scanner.nextLine();
		mers[i] = mer;
		if (i < 10) {
		}
	    }
	} catch (FileNotFoundException e) {
	    if (verbose) {
		System.out.println("Results file not found:" + inputFilename);
	    }
	    return false;
	} catch (NumberFormatException e) {
	    if (verbose) {
		System.out.println("Format error: line 0");
	    }
	    return false;	    
	}

	int[] actual = Problem4.kmers(seq, K, mers);
	if (actual == null) {
	    if (verbose) {
		System.out.println("Actual is null.");
	    }
	    return false;
	}


	File resultsFile = TestHelpers.getResultsFile(f);
	try {
	    Scanner scanner = new Scanner(resultsFile);
	    for (i = 0; i < numKmers; i++) {
		String[] values = scanner.nextLine().split(" ");
		String mer = values[0];
		int expected_count = Integer.parseInt(values[1]);
		if (actual[i] != expected_count) {
		    if (verbose) {
			System.out.println(String.format("Actual value for mer at index %d does not match the expected value", mer, i));
			System.out.println("    mer: " + mer);
			System.out.println(String.format("    actual[%d]: %d", i, actual[i]));
			System.out.println(String.format("    expected[%d]: %d", i, expected_count));
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
	}
    }


    public static void main(String[] args) {
	System.exit(TestHelpers.doTests(args, new Test4()));
    }
}
