public class Solution {
    private void paint(char[][] board, int x, int y) {
        board[x][y] = '1';
        if(board[x-1][y] == 'O') {
            paint(board, x-1, y);
        }
        if(board[x][y-1] == 'O') {
            paint(board, x, y-1);
        }
        if(board[x+1][y] == 'O') {
            paint(board, x+1, y);
        }
        if(board[x][y+1] == 'O') {
            paint(board, x, y+1);
        }
    }
    
    public void solve(char[][] board) {
        if(board.length < 3 || board[0].length < 3) {
            return;
        }
        int row = board.length, col = board[0].length;
        for(int i = 0; i < col; i++) {
            if(board[0][i] == 'O') {
                board[0][i] = '1';
                // paint(board, 0, i);
            }
            if(board[row-1][i] == 'O') {
                board[row-1][i] = '1';
                // paint(board, row-1, i);
            }
        }
        for(int i = 0; i < row; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = '1';
                // paint(board, i, 0);
            }
            if(board[i][col-1] == 'O') {
                board[i][col-1] = '1';
                // paint(board, i, col-1);
            }
        }
        
        for(int i = 1; i < row-1; i++) {
            for(int j = 1; j < col-1; j++) {
                if(board[i][j] == 'O') {
                    if(board[i-1][j] == '1' || board[i][j-1] == '1') {
                        board[i][j] = '1';
                    }
                }
            }
        }
        for(int i = row-2; i > 0; i--) {
            for(int j = col-2; j > 0; j--) {
                if(board[i][j] == 'O') {
                    if(board[i+1][j] == '1' || board[i][j+1] == '1') {
                        board[i][j] = '1';
                    }
                }
            }
        }
        
        for(int i = 1; i < row-1; i++) {
            for(int j = 1; j < col-1; j++) {
                if(board[i][j] == 'O') {
                    if(board[i-1][j] == '1' || board[i+1][j] == '1' || board[i][j-1] == '1' || board[i][j+1] == '1') {
                        paint(board, i, j);
                    }
                }
            }
        }
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == '1') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
}
