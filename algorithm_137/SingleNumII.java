package algorithm_137;

public class SingleNumII {
    public int singleNumber(int[] nums) {
        int r1 = 0, r2 = 0, r3 = 0, t1, t2, t3, t;
        for(int i = 0; i < nums.length; i++) {
            t1 = r1 & nums[i];
            t2 = r2 & nums[i];
            t3 = r3 & nums[i];
            t = ~(r1 | r2 | r3) & nums[i];
            r1 = t | t3 | (t1 ^ r1);
            r2 = t1 | (t2 ^ r2);
            r3 = t2 | (t3 ^ r3);
        }
        return r1;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SingleNumII s = new SingleNumII();
		int[] a = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
		System.out.println(s.singleNumber(a));
	}

}
