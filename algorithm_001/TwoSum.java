package algorithm_1;

import java.util.HashMap;

public class TwoSum {
    public int[] twoSum(int[] numbers, int target) {
        int[] r = new int[2];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < numbers.length; i++) {
        	Integer t = map.get(target - numbers[i]);
        	if(t == null) {
        		map.put(numbers[i], i);
        	} else {
        		r[0] = t+1;
        		r[1] = i+1;
        		break;
        	}
        }
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
    	long start = System.currentTimeMillis();
    	TwoSum s = new TwoSum();
    	int[] in = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100}, out;
    	out = s.twoSum(in, 101);
    	for(int i = 0; i < out.length; i++) {
    		System.out.println(out[i]);
    	}
    	long end = System.currentTimeMillis();
    	System.out.println(end - start); 
	}

}
