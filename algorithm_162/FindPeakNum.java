package algorithm_162;

import java.util.List;

public class FindPeakNum {
	
    public int findPeakElement(List<Integer> nums) {
        nums.add(0, Integer.MIN_VALUE);
        nums.add(Integer.MIN_VALUE);
        if(nums.get(1) >= nums.get(2)) {
            return 0;
        }
        if(nums.get(nums.size()-2) >= nums.get(nums.size()-3)) {
            return nums.size()-3;
        }
        int a = 2, b = nums.size()-5;
        while(b != 0) {
            if(nums.get(a+b-1) < nums.get(a+b) && nums.get(a+b) < nums.get(a+b+1)) {
                a += b;
            } else {
                b >>= 1;
            }
        }
        
        return a;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

}
