public class Solution {
    public int firstMissingPositive(int[] nums) {
        for(int i = 0; i < nums.length; i++) {
            int t = nums[i];
            if(t != i+1) {
                nums[i] = -1;
                while(true) {
                    if(t < 1 || t > nums.length || nums[t-1] == t) {
                        break;
                    }
                    int tt = nums[t-1];
                    nums[t-1] = t;
                    t = tt;
                }
            }
        }
        
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == -1) {
                return i+1;
            }
        }
        return nums.length+1;
    }
}
