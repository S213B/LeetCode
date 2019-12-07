package algorithm_090;

import java.util.*;

public class SubsetsII {
	
    @SuppressWarnings("unchecked")
	public List<List<Integer>> subsetsWithDup(int[] nums) {
        ArrayList<List<Integer>> r = new ArrayList<List<Integer>>();
        r.add(new ArrayList<Integer>());
        ArrayList<Integer> t;
        int dupOp = 0;
        Arrays.sort(nums);
        
        if(nums.length != 0) {
            t = new ArrayList<Integer>();
            t.add(nums[0]);
            r.add(t);
            if(nums.length != 1 && nums[0] == nums[1]) {
                dupOp++;
            }
        }
        for(int i = 1; i < nums.length; i++) {
            int size = r.size();
            if(nums[i-1] != nums[i]) {
                dupOp = size;
            }
            for(int j = size-1; j >= size-dupOp; j--) {
                t = (ArrayList<Integer>) r.get(j);
                t = (ArrayList<Integer>) t.clone();
                t.add(nums[i]);
                r.add(t);
            }
            
        }
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
