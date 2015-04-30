package algorithm_036;

public class ValidSudoku {
	
    public boolean isValidSudoku(char[][] board) {
    	if(board.length !=9 || board[0].length != 9) {
    		return false;
    	}
    	
        boolean[][] rowValid = new boolean[9][12], colValid = new boolean[9][12];
        boolean[][][] val = new boolean[3][3][12];
        
        for(int i = 0; i < 9; i++) {
        	for(int j = 0; j < 12; j++) {
        		rowValid[i][j] = false;
        		colValid[i][j] = false;
        	}
        }
        for(int i = 0; i < 3; i++) {
        	for(int j = 0; j < 3; j++) {
        		for(int k = 0; k < 12; k++) {
        			val[i][j][k] = false;
        		}
        	}
        }
        
        for(int i = 0; i < board.length; i++) {
        	for(int j = 0; j < board.length; j++) {
        	    int t = board[i][j]-'.';
        	    if(t != 0) {
	        		if(rowValid[i][t] || colValid[j][t] || val[i/3][j/3][t]) {
	        			return false;
	        		}
        	    }
        		rowValid[i][t] = true;
        		colValid[j][t] = true;
        		val[i/3][j/3][t] = true;
        	}
        }
        
        return true;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ValidSudoku s = new ValidSudoku();
		char[][] a = {".87654321".toCharArray(),"2........".toCharArray(),"3........".toCharArray(),"4........".toCharArray(),"5........".toCharArray(),"6........".toCharArray(),"7........".toCharArray(),"8........".toCharArray(),"9........".toCharArray()};
		System.out.println(s.isValidSudoku(a));
	}

}