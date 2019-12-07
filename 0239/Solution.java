public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length == 0) {
            return new int[0];
        }
        
        LinkedList<Integer> queue = new LinkedList<Integer>();
        int[] max = new int[nums.length], r = new int[nums.length-k+1];
        
        queue.add(nums[0]);
        for(int i = 1; i < k; i++) {
            while(!queue.isEmpty() && nums[i] > queue.getLast()) {
                queue.removeLast();
            }
            queue.add(nums[i]);
        }
        r[0] = queue.getFirst();
        
        for(int i = k, j = 1; i < nums.length; i++, j++) {
            if(nums[i-k] == queue.getFirst()) {
                queue.removeFirst();
            }
            while(!queue.isEmpty() && nums[i] > queue.getLast()) {
                queue.removeLast();
            }
            queue.add(nums[i]);
            r[j] = queue.getFirst();
        }
        
        return r;
    }
}
