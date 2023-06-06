import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.NoSuchElementException;

public class Test3 extends Test {
    public boolean runTest(File f, boolean verbose) {
	String inputFilename = f.getPath();
	int rounds;
	String[] player1;
	String[] player2;	

	try {
	    Scanner scanner = new Scanner(f);
	    rounds = Integer.parseInt(scanner.nextLine());
	    player1 = scanner.nextLine().split(" ");
	    player2 = scanner.nextLine().split(" ");	    
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
	} catch (Exception e) {
	    if (verbose) {
		System.out.println("Unexpected exception: "  + e);
	    }
	    return false;
	}

	if ((player1.length != player2.length) || (player1.length != rounds)) {
	    if (verbose) {
		System.out.println("Format error");
	    }
	    return false;
	}

	String actual = Problem3.tricky(player1, player2);
	File resultsFile = TestHelpers.getResultsFile(f);
	String expected = "";
	try {
	    Scanner scanner = new Scanner(resultsFile);
	    expected = scanner.nextLine();
	} catch (FileNotFoundException e) {
	    if (verbose) {
		System.out.println("Results file not found:" + inputFilename);
	    }
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
		System.out.println(String.format("  Actual and expected results do not match"));
		System.out.println(String.format("    actual: %s", actual));
		System.out.println(String.format("    expected: %s", expected));
	    }
	    return false;
	}
    }


    public static void main(String[] args) {
	System.exit(TestHelpers.doTests(args, new Test3()));
    }
}
