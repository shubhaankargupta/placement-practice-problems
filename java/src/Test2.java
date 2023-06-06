import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.NoSuchElementException;

public class Test2 extends Test {
    public boolean runTest(File f, boolean verbose) {
	List<Integer> measurements = TestHelpers.getIntegerListFromFile(f);
	Integer expected = getResults(f, verbose);
	Integer actual = -1;

	if ((expected != null) && (expected < 0)) {
	    // bad results file
	    return false;
	}

	try {
	    actual = Problem2.raindrops(measurements);
	} catch (Exception e) {
	    if (verbose) {
		System.out.println("Unexpected exception: " + e);
	    }
	    return false;
	}

	if (actual == null) {
	    if (expected == null) {
		return true;
	    } else {
		if (verbose) {
		    System.out.println("Failed: actual result is null");
		}
		return false;
	    }
	} else if (actual.equals(expected)) {
	    return true;
	} else {
	    if (verbose) {
		System.out.println("Failed actual result and expected result do not match");
		System.out.println(String.format("    actual is %d", actual));
		System.out.println(String.format("    expected is %d", expected));
	    }
	    return false;
	}
    }

    private static Integer getResults(File inputFile, boolean verbose) {
	Integer result = -1;
	Scanner scanner = TestHelpers.getResultsFileScanner(inputFile);

	if (scanner == null) {
	    return result;
	}

	try {
	    String data = scanner.nextLine();
	    if (data.equals("INSUFFICIENT DATA")) {
		result = null;
	    } else {
		result = Integer.parseInt(data);
	    }
	} catch (NumberFormatException e) {
	    if (verbose) {
		System.out.println("Results file has the wrong format");
	    }
	}

	return result;
    }

    public static void main(String[] args) {
	System.exit(TestHelpers.doTests(args, new Test2()));
    }
}
