import java.util.List;
import java.util.HashMap;

public class Problem3 {

    private static HashMap<String, Integer> mkCardMap() {
        HashMap<String, Integer> cardMap = new HashMap<String, Integer>();
        for (int i=2; i < 10; i++) {
            cardMap.put(Integer.toString(i),  i);
        }
        cardMap.put("J",  10);
        cardMap.put("Q",  11);
        cardMap.put("K",  12);
        cardMap.put("A",  13);
        return cardMap;
    }

    /**
     * Play a game of Tricky as described in the problem statement.
     *
     * Arguments:
     *   player1: list of cards as strings
     *   player2: list of cards as strings
     *
     * Result: The string "PLAYER 1 WINS", if player 1 has a higher score
     *   at the end of the game, the "PLAYER 2 WINS", if player 2 has a higher
     *   score at the end of the game, or "TIE", if the players have the same score.
     **/
    public static String tricky(String[] player1, String[] player2) {
        // YOUR CODE HERE
        // Return included to allow the skeleton code to compile
        return null;
    }
}
