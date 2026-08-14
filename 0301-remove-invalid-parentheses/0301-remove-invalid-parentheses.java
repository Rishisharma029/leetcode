import java.util.*;

class Solution {

    public List<String> removeInvalidParentheses(String s) {

        List<String> result = new ArrayList<>();

        if (s == null) {
            return result;
        }

        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.offer(s);
        visited.add(s);

        boolean found = false;

        while (!queue.isEmpty()) {

            String current = queue.poll();

            if (isValid(current)) {
                result.add(current);
                found = true;
            }

            if (found) {
                continue;
            }

            for (int i = 0; i < current.length(); i++) {

                char c = current.charAt(i);

                if (c != '(' && c != ')') {
                    continue;
                }

                String next =
                        current.substring(0, i)
                      + current.substring(i + 1);

                if (!visited.contains(next)) {
                    visited.add(next);
                    queue.offer(next);
                }
            }
        }

        return result;
    }

    private boolean isValid(String s) {

        int balance = 0;

        for (char c : s.toCharArray()) {

            if (c == '(') {
                balance++;
            }

            else if (c == ')') {

                if (balance == 0) {
                    return false;
                }

                balance--;
            }
        }

        return balance == 0;
    }
}