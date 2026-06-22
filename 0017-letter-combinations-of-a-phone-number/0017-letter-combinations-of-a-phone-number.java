import java.util.*;

class Solution {

    private List<String> result = new ArrayList<>();

    private String[] map = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {

        if (digits == null || digits.length() == 0) {
            return result;
        }

        backtrack(digits, 0, new StringBuilder());

        return result;
    }

    private void backtrack(String digits,
                           int index,
                           StringBuilder current) {

        if (index == digits.length()) {
            result.add(current.toString());
            return;
        }

        String letters = map[digits.charAt(index) - '0'];

        for (char c : letters.toCharArray()) {

            current.append(c);

            backtrack(digits, index + 1, current);

            current.deleteCharAt(current.length() - 1);
        }
    }
}
