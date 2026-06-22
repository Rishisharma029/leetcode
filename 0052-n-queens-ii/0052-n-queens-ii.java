import java.util.*;

class Solution {

    private int count = 0;

    private Set<Integer> columns = new HashSet<>();
    private Set<Integer> diagonal1 = new HashSet<>();
    private Set<Integer> diagonal2 = new HashSet<>();

    public int totalNQueens(int n) {

        backtrack(0, n);

        return count;
    }

    private void backtrack(int row, int n) {

        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {

            if (columns.contains(col) ||
                diagonal1.contains(row - col) ||
                diagonal2.contains(row + col)) {
                continue;
            }

            columns.add(col);
            diagonal1.add(row - col);
            diagonal2.add(row + col);

            backtrack(row + 1, n);

            columns.remove(col);
            diagonal1.remove(row - col);
            diagonal2.remove(row + col);
        }
    }
}