package algorithm_055;

public class JumpGame {
	
    public boolean canJump(int[] nums) {
        int end = 0, i;
        
        for(i = 0; i < nums.length && i <= end; i++) {
            int t = i+nums[i];
            end = end > t ? end : t;
        }
        
        return i == nums.length;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
