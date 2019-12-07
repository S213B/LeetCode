package algorithm_169;

public class MajorityEle {
	
    public int majorityElement(int[] nums) {
        int x = 0, r = nums[0];
        
        for(int i = 0; i < nums.length; i++) {
            if(r == nums[i]) {
                x++;
            } else if(x == 1){
                r = nums[i];
            } else {
                x--;
            }
        }
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
