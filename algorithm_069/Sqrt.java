package algorithm_069;

public class Sqrt {
	
    public int mySqrt(int x) {
        int start = 0, len = x;
        while(len != 0) {
            if(x/(start+len) >= (start+len)) {
                start += len;
            } else {
                len = len >> 1;
            }
        }
        
        return start;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
