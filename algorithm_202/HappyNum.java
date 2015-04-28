package algorithm_202;

public class HappyNum {
	
    public boolean isHappy(int n) {
    	int[] loop = new int[1000];
    	
    	while(n != 1) {
    		int t = 0;
    		while(n != 0) {
    			t += (n%10) * (n%10);
    			n /= 10;
    		}
    		n = t;
//    		System.out.println(n);
    		if(loop[n] != 0) {
    			return false;
    		}
    		loop[n]++;
    	}
    	
        return true;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HappyNum s = new HappyNum();
		System.out.println(s.isHappy(18));
	}

}
