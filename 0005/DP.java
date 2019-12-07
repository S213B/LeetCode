package algorithm_005;

import java.util.ArrayList;

public class DP {
    public String longestPalindrome(String s) {
    	ArrayList<Integer>[] dp = new ArrayList[s.length()];
    	dp[0] = new ArrayList<Integer>();
    	dp[0].add(1);
        for(int i = 1; i < s.length(); i++) {
        	dp[i] = new ArrayList<Integer>();
        	if(s.charAt(i) == s.charAt(i-1)) {
        		dp[i].add(dp[i-1].get(0)+1);
        	} else {
        		dp[i].add(1);
        	}
        }
        
        for(int i = 2; i < s.length(); i++) {
        	for(int j = 0; j < dp[i-1].size(); j++) {
        		int start = i-dp[i-1].get(j)-1;
        		if(start >= 0 && s.charAt(i) == s.charAt(start)) {
        			dp[i].add(i-start+1);
        		}
        	}
        }
        
        int max = 0, idx = 0;
        for(int i = 0; i < s.length(); i++) {
        	int t = dp[i].get(dp[i].size()-1);
        	if(t > max) {
        		max = t;
        		idx = i;
        	}
        }
        
        return s.substring(idx-max+1, idx+1);
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long start = System.currentTimeMillis();
		DP s = new DP();
		System.out.println(s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
		long end = System.currentTimeMillis();
		System.out.println(end-start);
	}

}
