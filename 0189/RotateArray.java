package algorithm_189;

public class RotateArray {
	
    private void reverse(int[] nums, int start, int end) {
        while(start < end) {
            int t;
            t = nums[start];
            nums[start] = nums[end];
            nums[end] = t;
            start++;
            end--;
        }
    }
    
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        if(k == 0) {
            return;
        }
        reverse(nums, nums.length-k, nums.length-1);
        reverse(nums, 0, nums.length-k-1);
        reverse(nums, 0, nums.length-1);
    }
    
}
