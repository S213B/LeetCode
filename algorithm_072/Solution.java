public class Solution {
    public int minDistance(String word1, String word2) {
        int[] dp = new int[word1.length()+1];
        for(int i = 0; i <= word1.length(); i++) {
            dp[i] = i;
        }
        
        for(int i = 1; i <= word2.length(); i++) {
            int pre = i;
            for(int j = 1; j <= word1.length(); j++) {
                int cur;
                if(word1.charAt(j-1) == word2.charAt(i-1)) {
                    cur = dp[j-1];
                } else {
                    cur = min(dp[j-1]+1, dp[j]+1, pre+1);
                }
                dp[j-1] = pre;
                pre = cur;
            }
            dp[word1.length()] = pre;
        }
        
        return dp[word1.length()];
    }
    
    private int min(int a, int b, int c) {
        int t = a < b ? a : b;
        return t < c ? t : c;
    }
}
