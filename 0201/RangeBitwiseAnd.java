package algorithm_201;

public class RangeBitwiseAnd {
    public int rangeBitwiseAnd(int m, int n) {
        int r = 0, ml = 0, nl = 0;
        int[] level = new int[31];
        for(int i = 0; i < 31; i++) {
        	level[i] = 1 << i;
        }
        
        while(m != 0) {
	        for(int i = 0; i < 31; i++) {
	        	if(m >= level[i]) {
	        		ml = i;
	        	} else {
	        		break;
	        	}
	        }
	        for(int i = ml; i < 31; i++) {
	        	if(n >= level[i]) {
	        		nl = i;
	        	} else {
	        		break;
	        	}
	        }
	        
	        if(ml == nl) {
	        	r |= level[ml];
	        	m ^= level[ml];
	        	n ^= level[nl];
	        } else {
	        	break;
	        }
        }
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RangeBitwiseAnd s = new RangeBitwiseAnd();
		System.out.println(s.rangeBitwiseAnd(100, 127));
	}

}
