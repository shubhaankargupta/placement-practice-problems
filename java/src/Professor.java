import java.util.Set;
import java.util.HashSet;

/**
 * Class for representing a professor.
 *
 * Public attributes:
 *  name: the professor's name represented as a string.
 *  tenured: a boolean that will be true, if the professor has tenure and
 *    false otherwise.
 *  fields: a set of the names of the fields the professor works in
 **/
public class Professor {
    public String name;
    public boolean tenured;
    public HashSet<String> fields;

    /**
     * Constructor:
     *
     * Arguments:
     *   name: the Professor's name represented as a string
     *   tenures: a boolean that will be true, if the process has tenure
     *     and false otherwise.
     *   fields: an array of strings with the names of the fields the
     *     professor works in
     **/
    public Professor(String name, boolean tenured, String[] fields) {
        this.name = name;
        this.tenured = tenured;
        this.fields = new HashSet<String>();
        for (String field : fields) {
            this.fields.add(field);
        }
    }
}


    
