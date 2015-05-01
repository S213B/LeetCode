package algorithm_078;

import java.util.*;

public class Subsets {
	
    @SuppressWarnings("unchecked")
	public List<List<Integer>> subsets(int[] nums) {
        ArrayList<List<Integer>> r = new ArrayList<List<Integer>>();
        ArrayList<Integer> t;
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length; i++) {
            int size = r.size();
            for(int j = 0; j < size; j++) {
                t = (ArrayList<Integer>) r.get(j);
                t = (ArrayList<Integer>) t.clone();
                t.add(nums[i]);
                r.add(t);
            }
            t = new ArrayList<Integer>();
            t.add(nums[i]);
            r.add(t);
        }
        r.add(new ArrayList<Integer>());
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	}

}
