package algorithm_10;

import java.util.Stack;

public class RegularExpressionMatching {
    public boolean isMatch(String s, String p) {
    	
    	
    	
        return s.matches(p);
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
    	long start = System.currentTimeMillis();
    	RegularExpressionMatching s = new RegularExpressionMatching();
    	System.out.println(s.isMatch("ff", ".."));
    	long end = System.currentTimeMillis();
    	System.out.println(end - start); 
	}
}
