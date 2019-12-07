package algorithm_200;

public class NumOfIslands {
	
    public int numIslands(char[][] grid) {
    	if(grid.length == 0) {
    		return 0;
    	}
    	int r = 0;
    	
    	for(int i = 0; i < grid.length; i++) {
    	    for(int j = 0; j < grid[0].length; j++) {
    	        if(grid[i][j] == '1') {
    	            r++;
    	            paint(i, j, grid);
    	        }
    	    }
    	}
        
        return r;
    }
    
    private void paint(int i, int j, char[][] grid) {
        if(grid[i][j] == '1') {
            grid[i][j] = '0';
            if(i != 0) {
                paint(i-1, j, grid);
            }
            if(j != 0) {
                paint(i, j-1, grid);
            }
            if(i != grid.length-1) {
                paint(i+1, j, grid);
            }
            if(j != grid[0].length-1) {
                paint(i, j+1, grid);
            }
        }
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char[][] a = {"1001".toCharArray(), "1001".toCharArray(), "1111".toCharArray(), "0010".toCharArray()};
		NumOfIslands s = new NumOfIslands();
		System.out.println(s.numIslands(a));
	}

}
