import java.util.List;
import java.util.ArrayList;

/**
 * Class for representing an employee and the people who report to them.
 *
 * Public attributes:
 *   empNum: the employee's employee number represented as an integer
 *   salary: the employee's salary represented as an integer
 *   children: a list of the employee's direct reports
 *
 * Public methods:
 *   addDirectReport: add a new direct report to the tree
 *   printTree: print the contents of the tree.
 **/
public class Tree {
    public int empNum;
    public int salary;
    public List<Tree> children;

    /**
     * Constructor for Tree
     * Arguments:
     *   empNum: the employee's employee number represented as an integer
     *   salary: the employee's salary represented as an integer
     **/
    public Tree(int empNum, int salary) {
        this.empNum = empNum;
        this.salary = salary;
        this.children = new ArrayList<Tree>();
    }

    /** 
     * addDirectReport: add a new direct report
     *
     * Arguments:
     *   t: the new direct report represented as a Tree
     **/
    public void addDirectReport(Tree t) {
        this.children.add(t);
    }

    /**
     * printTree: print the contents of the tree, indented
     *   to illustrate the tree structure
     *
     * Arguments:
     *   tabs: a string with spaces that tracks the indentation level
     **/
    public void printTree(String tabs) {
        System.out.println(tabs + this.empNum + " " + this.salary);
        for (Tree t : this.children) {
            t.printTree(tabs + "  ");
        }
    }
}
