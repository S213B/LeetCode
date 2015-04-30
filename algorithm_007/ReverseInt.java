package algorithm_007;

public class ReverseInt {
    public int reverse(int x) {
    	int r = 0, of = x > 0 ? Integer.MAX_VALUE/10 : Integer.MIN_VALUE/10;
    	while(x != 0) {
    		if(x > 0 && r > of) {
    			return 0;
    		} else if(x < 0 && r < of) {
    			return 0;
    		}
    		r *= 10;
    		r += x%10;
    		x /= 10;
    	}
        return r;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ReverseInt s = new ReverseInt();
		System.out.println(s.reverse(1534236469));
	}

}
