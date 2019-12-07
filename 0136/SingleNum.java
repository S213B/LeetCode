package algorithm_136;

public class SingleNum {
	
    public int singleNumber(int[] A) {
        int r = 0;
        
        for(int i = 0; i < A.length; i++) {
            r ^= A[i];
        }
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
