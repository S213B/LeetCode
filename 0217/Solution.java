public class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Boolean> r = new HashMap<Integer, Boolean>();
        for(int i = 0; i < nums.length; i++) {
            if(r.put(nums[i], true) != null) {
                return true;
            }
        }
        
        return false;
    }
}
