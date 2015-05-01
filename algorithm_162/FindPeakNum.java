package algorithm_162;

public class FindPeakNum {
	
    public int findPeakElement(int nums[]) {
        if(nums.length < 2 || nums[0] > nums[1]) {
            return 0;
        }
        int a = 0, b = nums.length-1, mid;
        while(a+1 != b) {
            mid = b + ((a-b)>>1);
            if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]) {
                a = mid;
            } else {
                b = mid;
            }
        }
        
        return b;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	}

}
