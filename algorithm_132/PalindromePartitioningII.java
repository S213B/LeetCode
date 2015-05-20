package algorithm_132;

public class PalindromePartitioningII {
	
    public int minCut(String s) {
        char[] str = s.toCharArray();
        int[] dp = new int[str.length+1], op = new int[str.length];
        boolean[] same = new boolean[str.length];
        
        dp[0] = 0;
        dp[1] = -1;
        op[0] = 0;
        same[0] = true;
        for(int i = 1; i < str.length; i++) {
            int j = 0, min = i;
            for(; dp[j] != -1; j++) {
                if(dp[j] == -2) {
                    continue;
                }
                if(same[j] && str[i] == str[i-1]) {
                    if(op[i-1] < min) {
                        min = op[i-1];
                    }
                } else {
                    if(dp[j] != 0 && str[dp[j]-1] == str[i]) {
                        if(dp[j]-1 == 0) {
                            min = 0;
                        } else if(op[dp[j]-1]+1 < min) {
                            min = op[dp[j]-2]+1;
                        }
                        dp[j]--;
                        same[j] = false;
                    } else {
                        dp[j] = -2;
                    }
                }
            }
            op[i] = min < op[i-1]+1 ? min : op[i-1]+1;
            dp[j] = i;
            same[j] = true;
            dp[++j] = -1;
        }
        
        return op[str.length-1];
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PalindromePartitioningII s = new PalindromePartitioningII();
		s.minCut("cbbbcc");
	}

}
