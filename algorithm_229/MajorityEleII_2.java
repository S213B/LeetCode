public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        LinkedList<Integer> r = new LinkedList<Integer>();
        int len = nums.length;
        
        for(int i = 0; len != 0 && i < 10; i++) {
            int cnt = 0;
            int rand = nums[(int)(Math.random()*len)];
            if(r.size() != 0 && r.get(0) == rand) {
                continue;
            }
            for(int j = 0; j < len; j++) {
                if(nums[j] == rand) {
                    cnt++;
                }
            }
            if(cnt > len/3) {
                r.add(rand);
                if(r.size() == 2) {
                    return r;
                }
            }
        }
        
        return r;
    }
}
