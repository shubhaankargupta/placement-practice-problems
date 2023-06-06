import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.Collections;

public class TestHelpers {
    /**
     * Parse the arguments and return a list of Files.
     *  -h yields null
     *  filename yields a list with one file
     *  -a directory yields a list of Files, one per test input filename (extension .in)
     *
     * Arguments:
     *   args: the command-line arguments as a list of strings
     *
     * Returns: list of Files or null.
     **/
    public static ArrayList<File> getFiles(String[] args) {
	ArrayList<File> filesToProcess = new ArrayList<File>();

	if ((args.length == 1) && (args[0].equals("-h"))) {
	    return null;
	} else if ((args.length == 2) && (args[0].equals("-t"))) {
	    File file = new File(args[1]);
	    if (!file.exists()) {
		System.err.println("File not found: " + args[1]);
		return null;
	    }
	    filesToProcess.add(file);
	} else if ((args.length == 2) && (args[0].equals("-a"))) {
	    File folder = new File(args[1]);
	    File[] listOfFiles = folder.listFiles();

	    if (listOfFiles == null) {
		System.err.println("Test directory not found:" + folder);
		return null;
	    }

	    for (File file : listOfFiles) {
		if (file.isFile()) {
		    String temp = file.getName();
		    if (temp.endsWith("in")) {
			filesToProcess.add(file);
		    }
		}
	    }
	    Collections.sort(filesToProcess);
	} else if (args.length == 1) {
	    File file = new File(args[0]);
	    if (!file.exists()) {
		System.err.println("File not found: " + args[0]);
		return null;
	    }
	    filesToProcess.add(file);
	} else {
	    return null;
	}
	return filesToProcess;
    }

    
    public static int doTests(String[] args, Test t) {
	List<File> files = getFiles(args);
	if (files == null) {
	    System.err.println("usage: java Test [-h | -a <directory> | -t <test file> | <test file>]");
	    System.exit(1);
	}

	boolean verbose = (args.length != 2) || (!args[0].equals("-t"));
	int passed = 0;
	
	for (File f : files) {
	    String filename = f.getPath().replace(".in", "");
	    if (verbose) {
		System.out.print("Test: " + filename + ": ");
	    }

	    try {
		if (t.runTest(f, verbose)) {
		    passed++;
		    System.out.println("PASSED");
		} else if (!verbose) {
		    System.out.println("FAILED");
		}
	    } catch (Exception e) {
		if (verbose) {
		    System.out.println("Caught unexpected exception: " + e);
		}
		return 0;
	    }		
	}

	if (passed == files.size()) {
	    return 42;
	} else {
	    return 0;
	}
    }

    /**
     * Given an input File, return a File for the corresponding results file.
     *    TEST_FILE.in => TEST_FILE.ans
     * 
     * Arguments:
     *   inputFile: the input File
     *
     * Returns: a File for the corresponding results file.
     **/
    public static File getResultsFile(File inputFile) {
	String resultsFileName = inputFile.getPath().replace(".in", ".ans");
	return new File(resultsFileName);
    }    


    /**
     * Given an input File, return a Scanner for the corresponding results file.
     *    TEST_FILE.in => TEST_FILE.ans
     * 
     * Arguments:
     *   inputFile: the input File
     *
     * Returns: a Scanner for the corresponding results file.
     **/
    public static Scanner getResultsFileScanner(File inputFile) {
	String resultsFileName = inputFile.getPath().replace(".in", ".ans");
	Scanner scanner = null;

	try {
	    File f = new File(resultsFileName);
	    scanner = new Scanner(f);
	} catch (FileNotFoundException e) {
	    System.out.println("Results file not found:" + resultsFileName);
	    System.exit(0);
	} catch (Exception e) {
	    System.out.println("Caught unexpected exception: " + e);
	    System.exit(0);
	}

	return scanner;
    }    


    /**
     * Read the data from a file that contains a list of integers formatted as:
     *   number_of_values
     *   value value value...
     *
     * Arguments:
     *   inputFile: a File with data formatted as shown above
     *
     * Returns: a list of integers or null, if the file is formatted incorrectly.
     **/
    public static List<Integer> getIntegerListFromFile(File inputFile) {
	List data = null;
	String line = "";
	int num_values = -1;
	String filename = inputFile.getName();
	Scanner scanner = null;


	try {
	    scanner = new Scanner(inputFile);
	    line = scanner.nextLine();
	    num_values = Integer.parseInt(line);
	} catch (NumberFormatException e) {
	    System.out.println("Format error: " + line);
	    return null;
	} catch (FileNotFoundException e) {
	    System.out.println("File not found:" + filename);
	    return null;
	}

	return getIntegerListFromFile(scanner, num_values, filename);

    }


    /**
     * Read the data from a file that contains a list of integers formatted as:
     *   value value value...
     *
     * Arguments:
     *   inputFile: a File with data formatted as shown above
     *   num_values: the expected number of values in the file
     *
     * Returns: a list of integers or null, if the file is formatted incorrectly.
     **/
    public static List<Integer> getIntegerListFromFile(File inputFile, int num_values) {
	String filename = inputFile.getName();
	Scanner scanner = null;
	
	try {
	    scanner = new Scanner(inputFile);
	} catch (FileNotFoundException e) {
	    System.out.println("File not found:" + inputFile.getName());
	    System.exit(1);
	}

	return getIntegerListFromFile(scanner, num_values, filename);
    }


    /**
     * Read a list of integers separated by spaces from scanner
     *
     * Arguments:
     *   scanner: a scanner
     *
     * Returns: a list of integers or null, if the file associated
     *   with the scanner is formatted incorrectly.
     **/
    public static List<Integer> getIntegerListFromFile(Scanner scanner, int num_values, String filename) {
	List<Integer> data = new ArrayList<Integer>();
	String line = "";
	
	try {
	    String[] values = scanner.nextLine().split(" ");
	    for (String item : values) {
		int temp = Integer.parseInt(item);
		data.add(temp);
	    }
	} catch (NumberFormatException e) {
	    System.out.println("Format error: " + line);
	    System.exit(1);
	}
	
	if (data.size() != num_values) {
	    System.out.println("Format error: Actual and expected number of values do not match:" + filename);
	    System.exit(1);
	}

	return data;
    }

    public static int[] convertIntegerListToArray(List<Integer> values) {
	int[] ret = new int[values.size()];
	for(int i = 0; i < ret.length; i++)
	    ret[i] = values.get(i);
	return ret;
    }


    public static List<String> getStringListFromFile(File inputFile) {
	List<String> data = new ArrayList<String>();
	String inputFileName = inputFile.getPath();

	try {
	    Scanner scanner = new Scanner(inputFile);
	    String[] values = scanner.nextLine().split(" ");
	    for (String item : values) {
		data.add(item);
	    }
	} catch (FileNotFoundException e) {
	    System.out.println("Results file not found:" + inputFileName);
	    System.exit(1);
	}

	return data;
    }    
	

    

}


