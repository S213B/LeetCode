package algorithm_77;

import java.util.ArrayList;
import java.util.List;

public class Combinations {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> r = new ArrayList<List<Integer>>(), tr;
        
        if(k == 1) {
        	while(n > 0) {
        		ArrayList<Integer> t = new ArrayList<Integer>();
        		t.add(n--);
        		r.add(t);
        	}
        } else if(n == k){
        	ArrayList<Integer> t = new ArrayList<Integer>();
        	int i = 1;
        	while(i < n+1) {
        		t.add(i++);
        	}
        	r.add(t);
        } else {
        	r = combine(n-1, k);
        	tr = combine(n-1, k-1);
        	for(int i = 0; i < tr.size(); i++) {
        		tr.get(i).add(n);
        		r.add(tr.get(i));
        	}
        }
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Combinations s = new Combinations();
		System.out.println(s.combine(8, 4));
	}

}
