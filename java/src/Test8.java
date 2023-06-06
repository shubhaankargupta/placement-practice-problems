/* Solution to paths problem.
 * Version w/ integer assignment ids
 */

import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.io.*;

public class Test8 extends Test {
    /**
     * runTest: run the test in the specified file.  Returns true, if the test passes
     *   and false otherwise.
     **/
    public boolean runTest(File f, boolean verbose) {
	Tree root = null;
	List<Tree> nodes = loadData(f, verbose);
	int expected = getResults(f, verbose);
	int actual = -1;

	if ((nodes == null) || (expected < 0)) {
	    return false;
	}

	try {
	    actual = Problem8.solve(nodes.get(1));
	} catch (Exception e) {
	    if (verbose) {
		System.out.println("Expected exception: " + e);
	    }
	    return false;
	}

	if (actual == expected) {
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

    /**
     * loadData: load the company data into a Tree.
     **/
    private static List<Tree> loadData(File f, boolean verbose) {
	ArrayList<Tree> nodes = null;
	String[] line;
	// Read the data
	try {
	    Scanner scanner = new Scanner(f);
	    String[] line0 = scanner.nextLine().split(" ");
	    int num_nodes = Integer.parseInt(line0[0]);

	    nodes = new ArrayList<Tree>();
	    for (int i = 0; i < num_nodes + 1; i++) {
		nodes.add(null);
	    }

	    for (int i = 0; i < num_nodes; i++) {
		line = scanner.nextLine().split(" ");
		int num = Integer.parseInt(line[0]);
		int salary = Integer.parseInt(line[1]);
		nodes.set(num, new Tree(num, salary));
	    }

	    for (int i = 0; i < num_nodes-1; i++) {
		line = scanner.nextLine().split(" ");
		int source = Integer.parseInt(line[0]);
		int sink = Integer.parseInt(line[1]);
		nodes.get(source).addDirectReport(nodes.get(sink));
	    }
	} catch (FileNotFoundException e) {
	    if (verbose) {
		System.out.println("Results file not found:" + f.getPath());
	    }
	    return null;
	} catch (NumberFormatException e) {
	    if (verbose) {
		System.out.println("Format error: line 0");
	    }
	    return null;
	} catch (Exception e) {
	    if (verbose) {
		System.out.println("Unexpected exception: " + e);
	    }
	    return null;
	}
	return nodes;
    }

    /**
     * getResults: get the expected results from the results file.
     **/
    private static Integer getResults(File inputFile, boolean verbose) {
	Integer result = -1;
	Scanner scanner = TestHelpers.getResultsFileScanner(inputFile);

	if (scanner == null) {
	    return result;
	}

	try {
	    String data = scanner.nextLine();
	    result = Integer.parseInt(data);
	} catch (NumberFormatException e) {
	    if (verbose) {
		System.out.println("Results file has the wrong format");
	    }
	    return -1;
	} catch (Exception e) {
	    if (verbose) {
		System.out.println("Expected exceptions: " + e);
	    }
	    return -1;
	}
	return result;
    }
    
    public static void main(String[] args) {
	System.exit(TestHelpers.doTests(args, new Test8()));
    }
    

}

