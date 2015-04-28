package algorithm_5;
import java.util.ArrayList;

public class Manacher {
    public String longestPalindrome(String s) {
    	String str = prePro(s);
    	int[] r = new int[str.length()];
    	int maxlen = 1, mid = 1, max = 1, idx = 1;
    	
    	r[0] = r[1] = 1;
    	for(int i = 2; i < str.length()-1; i++)	{
    		if(i <= maxlen) {
    			if((2*mid-i - r[2*mid-i] +1) < (2*mid-maxlen)) {
    				r[i] = maxlen - i +1;
    				continue;
    			} else if((2*mid-i - r[2*mid-i] +1) > (2*mid-maxlen)) {
    				r[i] = r[2*mid-i];
    				continue;
    			} else {
    				r[i] = maxlen - i +1;
    			}
    		} else {
    			r[i] = 1;
    		}
    		while(str.charAt(i+r[i]) == str.charAt(i-r[i])) {
    			r[i]++;
    		}
    		mid = i;
    		maxlen = i+r[i]-1;
    		if(r[i] > max) {
    			max = r[i];
    			idx = i;
    		}
    	}
    	
        return str.substring(idx-max+1, idx+max).replaceAll("#", "");
    }
    
	private String prePro(String s) {
		// TODO Auto-generated method stub
		char[] r = new char[s.length()*2+3];
		for(int i = 0; i < s.length(); i++) {
			r[2*i+1] = '#';
			r[2*i+2] = s.charAt(i);
		}
		r[0] = '!';
		r[s.length()*2+1] = '#';
		r[s.length()*2+2] = '@';
		return new String(r);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long start = System.currentTimeMillis();
		Manacher s = new Manacher();
		System.out.println(s.longestPalindrome("aabbb"));
		long end = System.currentTimeMillis();
		System.out.println(end-start);
	}


}
