public class Solution {
    public void rotate(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        
        for(int i = 0; i <= (row-1)/2; i++) {
            for(int j = 0; j < col; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[row-1-i][j];
                matrix[row-1-i][j] = t;
            }
        }
        
        for(int i = 0; i < row; i++) {
            for(int j = i+1; j < col; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
}
