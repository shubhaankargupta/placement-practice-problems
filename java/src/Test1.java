import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.NoSuchElementException;

public class Test1 extends Test {
    public boolean runTest(File f, boolean verbose) {
	List<Integer> temperatures = TestHelpers.getIntegerListFromFile(f);
	List<Integer> actual = Problem1.itshotitscold(temperatures);
	File resultsFile = TestHelpers.getResultsFile(f);
	List<Integer> expected = TestHelpers.getIntegerListFromFile(resultsFile, 3);

	if (expected == null) {
	    // bad results file.
	    return false;
	}

	if (actual == null) {
	    if (verbose) {
		System.out.println("Failed: actual result is null");		
	    }
	    return false;
	} else if (actual.equals(expected)) {
	    return true;	    
	} else {
	    if (verbose) {
		System.out.println("Failed actual result and expected result do not match");
		printDiff(actual, expected);
	    }
	    return false;	    
	}
    }

    private static void printDiff(List<Integer> actual, List<Integer> expected) {
	if (actual.size() != expected.size()) {
	    String err = String.format("Actual length (%d) and expected length (%d) do not match",
				       actual.size(), expected.size());
	    System.out.println(err);
	    return;
	}

	for (int i = 0; i < actual.size(); i++) {
	    if (actual.get(i) != expected.get(i)) {
		System.out.println(String.format("  Actual and expected results do not match at index: %d", i));
		System.out.println(String.format("    actual @ index %d is %d", i, actual.get(i)));
		System.out.println(String.format("    expected @ index %d is %d", i, expected.get(i)));
		return;
	    }
	}
	return;
    }

    public static void main(String[] args) {
	System.exit(TestHelpers.doTests(args, new Test1()));
    }
}
