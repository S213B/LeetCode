package algorithm_070;

public class ClimbStair {
	
    public int climbStairs(int n) {
        int a = 1, b = 2;
        if(n == 1) {
            return a;
        }
        for(int i = 0; i < n-2; i++) {
            b += a;
            a = b-a;
        }
        return b;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ClimbStair s = new ClimbStair();
	}

}
