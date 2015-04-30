package algorithm_015;

import java.util.*;

public class ThreeSum {    
    public List<List<Integer>> threeSum(int[] num) {
        List<List<Integer>> r = new LinkedList<List<Integer>>();
        HashMap<Integer, Stack<Integer>> map = new HashMap<Integer, Stack<Integer>>();
        Stack<Integer> t;
        
        if(num.length < 3) {
        	return r;
        }
        
        qsort(num, 0, num.length);
        
        for(int i = 1, d = 1; i < num.length; i++) {
        	if(num[i] == num[i-1]) {
        		d++;
        		if(d == 2) {
    	        	t = map.get(0-num[i]);
    	        	if(t != null && !t.empty()) {
    	        		ArrayList<Integer> tadd = new ArrayList<Integer>();
    	        		tadd.add(t.pop());
    	        		tadd.add(t.pop());
    	        		tadd.add(num[i]);
	        			r.add(tadd);
    	        	}
	        		t = map.get(num[i] + num[i]);
	        		if(t == null) {
	        			Stack<Integer> tadd = new Stack<Integer>();
	        			tadd.add(num[i]);
	        			tadd.add(num[i]);
	        			map.put(num[i] + num[i], tadd);
	        		} else {
	        			t.add(num[i]);
	        			t.add(num[i]);
	        		}
        		} else if(d == 3) {
        			if(num[i] == 0) {
        				ArrayList<Integer> tadd = new ArrayList<Integer>();
        				for(int k = 0; k < d; k++) {
        					tadd.add(0);
        				}
        				r.add(tadd);
        			}
        		}
        	} else {
	        	d = 1;
	        	t = map.get(0-num[i]);
	        	if(t != null) {
	        		while(t.size() != 0) {
	        			ArrayList<Integer> tadd = new ArrayList<Integer>();
	        			tadd.add(t.pop());
	        			tadd.add(t.pop());
	        			tadd.add(num[i]);
	        			r.add(tadd);
	        		}
	        	}
	        	for(int j = i-1; j > -1; j--) {
	        		if(num[j] != num[j+1]) {
	        			t = map.get(num[i] + num[j]);
	            		if(t == null) {
	            			Stack<Integer> tadd = new Stack<Integer>();
	            			tadd.add(num[i]);
	            			tadd.add(num[j]);
	            			map.put(num[i] + num[j], tadd);
	            		} else {
	            			t.add(num[i]);
	            			t.add(num[j]);
	            		}
	        		}
	        	}
        	}
        }
        
        return r;
    }
    
    public List<List<Integer>> threeSum2(int[] num) {
        Arrays.sort(num);
        List<List<Integer>> res = new LinkedList<List<Integer>>(); 
        for (int i = 0; i < num.length-2; i++) {
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                int lo = i+1, hi = num.length-1, sum = 0 - num[i];
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        res.add(Arrays.asList(num[i], num[lo], num[hi]));
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        lo++; hi--;
                    } else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }

	private void qsort(int[] num, int i, int length) {
		// TODO Auto-generated method stub
		if(i+1 >= length) {
			return;
		}
		int start = i, end = length, sentry = i;
		while(true) {
			while(num[--end] >= num[sentry] && start < end);
			if(!(start < end)) {
				break;
			}
			num[end] ^= num[sentry];
			num[sentry] ^= num[end];
			num[end] ^= num[sentry];
			sentry = end;
			while(num[++start] <= num[sentry] && start < end);
			if(!(start < end)) {
				break;
			}
			num[start] ^= num[sentry];
			num[sentry] ^= num[start];
			num[start] ^= num[sentry];
			sentry = start;
		}
		qsort(num, i, sentry);
		qsort(num, sentry+1, length);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = new int[1000];
		for(int i = 0; i < a.length; i++) {
			a[i] = (int) (Math.random()*20000-10000);
		}
		ThreeSum s = new ThreeSum();
		long start = System.currentTimeMillis();
//		System.out.println(s.threeSum(a));
		s.threeSum(a);
		System.out.println(System.currentTimeMillis() - start);
		long start2 = System.currentTimeMillis();
//		System.out.println(s.threeSum2(a));
		s.threeSum2(a);
		System.out.println(System.currentTimeMillis() - start2);
	}

}
