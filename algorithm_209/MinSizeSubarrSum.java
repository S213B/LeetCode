package algorithm_209;

public class MinSizeSubarrSum {
	
    public int minSubArrayLen(int s, int[] nums) {
        int sum = 0, start = 0, end = 0, r;
        
        while(sum < s && end < nums.length) {
            sum += nums[end++];
        }
        if(sum < s) {
            return 0;
        }
        while(sum >= s) {
            sum -= nums[start++];
        }
        r = end-start+1;
        
        while(end != nums.length) {
            sum += nums[end++];
            sum -= nums[start++];
            if(sum >= s) {
                while(sum >= s) {
                    sum -= nums[start++];
                }
                r = end-start+1;
            }
        }
        
        return r;
    }
    
    public int minSubArrayLen2(int s, int[] nums) {
        int sum = 0, r = nums.length+1, start = 0, end = 0;
        
        while(end != nums.length) {
            while(sum < s && end < nums.length) {
                sum += nums[end++];
            }
            if(sum < s) {
                break;
            }
            while(sum >= s) {
                sum -= nums[start++];
            }
            r = r < (end-start+1) ? r : (end-start+1);
        }
        
        return r == (nums.length+1) ? 0 : r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
