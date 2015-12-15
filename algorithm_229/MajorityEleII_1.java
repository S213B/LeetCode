public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        LinkedList<Integer> r = new LinkedList<Integer>();
        int start = 0, len = nums.length;
        
        while(len != 0) {
            int rand = (int)(Math.random()*(len-start-1));
            int x = nums[start+rand], cnt = 1;
            nums[start+rand] = nums[start];
            nums[start] = x;
            start++;
            for(int i = start; i < len; i++) {
                if(nums[i] == x) {
                    nums[i] = nums[start];
                    start++;
                    cnt++;
                }
            }
            if(cnt > len/3) {
                r.add(x);
            }
            if(len-start <= len/3) {
                break;
            }
        }
        
        return r;
    }
}
