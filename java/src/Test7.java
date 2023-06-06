import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.NoSuchElementException;

public class Test7 extends Test {
    public boolean runTest(File f, boolean verbose) {
	String inputFilename = f.getPath();
	Scanner scanner = null;
	try {
	    scanner = new Scanner(f);
	} catch (FileNotFoundException e) {
	    if (verbose) {
		System.out.println("Results file not found:" + inputFilename);
	    }
	    return false;
	}

	// Format: number of values, index, replacement value
	List<Integer> params = TestHelpers.getIntegerListFromFile(scanner, 3, inputFilename);
	int[] values = TestHelpers.convertIntegerListToArray(TestHelpers.getIntegerListFromFile(scanner, params.get(0), inputFilename));
	Problem7.fill(values, params.get(1), params.get(2));
	File resultsFile = TestHelpers.getResultsFile(f);
	int[] expected = TestHelpers.convertIntegerListToArray(TestHelpers.getIntegerListFromFile(resultsFile, values.length));

	if (expected == null) {
	    if (verbose) {
		System.out.println("Bad results file:" + resultsFile.getPath());
	    }
	    // bad results file.
	    return false;
	}

	if (values == null) {
	    if (verbose) {
		System.out.println("Failed: actual result is null");
	    }
	    return false;
	} else {
	    for (int i = 0; i < values.length; i++) {
		if (values[i] != expected[i]) {
		    if (verbose) {
			System.out.println(String.format("  Actual and expected results do not match at index: %d", i));
			System.out.println(String.format("    actual @ index %d is %d", i, values[i]));
			System.out.println(String.format("    expected @ index %d is %d", i, expected[i]));
		    }
		    return false;
		}
	    }
	    return true;
	}
    }


    public static void main(String[] args) {
	System.exit(TestHelpers.doTests(args, new Test7()));	
    }
}
