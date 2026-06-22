import java.util.*;

class Solution {

    private List<List<String>> result = new ArrayList<>();

    private Set<Integer> columns = new HashSet<>();
    private Set<Integer> diagonal1 = new HashSet<>();
    private Set<Integer> diagonal2 = new HashSet<>();

    public List<List<String>> solveNQueens(int n) {

        char[][] board = new char[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }

        backtrack(0, n, board);

        return result;
    }

    private void backtrack(int row,
                           int n,
                           char[][] board) {

        if (row == n) {

            List<String> solution = new ArrayList<>();

            for (char[] r : board) {
                solution.add(new String(r));
            }

            result.add(solution);
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

            board[row][col] = 'Q';

            backtrack(row + 1, n, board);

            board[row][col] = '.';

            columns.remove(col);
            diagonal1.remove(row - col);
            diagonal2.remove(row + col);
        }
    }
}