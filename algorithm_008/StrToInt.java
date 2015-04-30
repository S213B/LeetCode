package algorithm_008;

public class StrToInt {
    public int atoi(String str) {
    	if(str.length() == 0) {
    		return 0;
    	}
    	int r = 0, i = 0, neg = 1;
    	
    	for(; str.charAt(i) == ' '; i++);
    	if(str.charAt(i) == '-' || str.charAt(i) == '+') {
    		neg -= str.charAt(i++)-'+';
    	}
    	for(; i < str.length(); i++) {
    		if(str.charAt(i) < '0' || str.charAt(i) > '9') {
        		break;
        	}
    		if(r > Integer.MAX_VALUE/10 || (r == Integer.MAX_VALUE/10 && str.charAt(i)-'0' > 7)) {
    			if(neg == 1) {
    				return Integer.MAX_VALUE;
    			} else {
    				return Integer.MIN_VALUE;
    			}
    		}
    		r *= 10;
    		r += str.charAt(i)-'0';
    	}
    	
        return r*neg;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StrToInt s = new StrToInt();
		String t = "-1";
		System.out.println(s.atoi(t));
	}

}
