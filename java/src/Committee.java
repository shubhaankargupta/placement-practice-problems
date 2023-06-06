import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

/**
 * Class for representing Committees
 *
 * Public attributes:
 *   name: the name of the committee
 *   members:a list of the Professors assigned to the committee
 *
 * Public methods:
 *   addMember: add a Professor as a member to the committee, if they are not already
 *     on the committee.
 *   isInvalidCommittee: determine whether the committee as currently constituted is "bad"
 *
 **/
public class Committee {
    public String name;
    private List<Professor> members;

    /**
     * Constructor: the constructor for Committee
     *
     * Arguments:
     *   name: the name of the committee represented as a string
     **/
    public Committee(String name) {
        // COMPLETE THIS METHOD
    }

    /**
     * addMember: add a Professor to the committee, if they are not
     *   already on the committee.
     *
     * Arguments:
     *   possible: a possible member of the committee represented as a Professor
     *
     * Returns: true, if the specified Professor is not already on the
     *   committee, false otherwise.
     **/
    public boolean addMember(Professor possible) {
        // COMPLETE THIS METHOD
        // return included to allow the skeleton code to compile
        return false;
    }

    /**
     * numMembers: computes the number of committee members
     **/
    private int numMembers() {
        // COMPLETE THIS METHOD
        // return included to allow the skeleton code to compile
        return 0;
    }

    /**
     * numMembers: computes the number of tenured committee members
     **/
    private int numTenured() {
        // COMPLETE THIS METHOD
        // return included to allow the skeleton code to compile
        return 0;
    }


    /**
     * getUniqueFields: computes a set of the unique fields represented
     *   by the committee.
     **/
    private Set<String> getUniqueFields() {
        // COMPLETE THIS METHOD
        // return included to allow the skeleton code to compile
        return null;
    }


    /**
     * isInvalidCommittee: determine whether the committee as
     *   currently constituted is "bad".
     *
     * Returns: true, if the committee meets the definition of bads
     *   (fewer than two unique fields represented and an insufficient
     *   number of tenured professors), false otherwise.
     **/
    public boolean isBadCommittee() {
        // COMPLETE THIS METHOD
        // return included to allow the skeleton code to compile
        return false;
    }
}
