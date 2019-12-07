package algorithm_115;

import java.util.ArrayList;
import java.util.HashMap;

public class DistinctSubsequnce {
	
	public int numDistinct(String s, String t) {
		HashMap<Character, ArrayList<Integer>> hash = new HashMap<Character, ArrayList<Integer>>();
		int[] r = new int[t.length()+1];
		r[0] = 1;
		
		for(int i = 1; i < t.length()+1; i++) {
			r[i] = 0;
		}
		
		for(int i = 0; i < t.length(); i++) {
			if(hash.containsKey(t.charAt(i))) {
				hash.get(t.charAt(i)).add(i+1);
			} else {
				ArrayList<Integer> arr = new ArrayList<Integer>();
				arr.add(i+1);
				hash.put(t.charAt(i), arr);
			}
		}
		
		for(int i = 0; i < s.length(); i++)	{
			if(hash.containsKey(s.charAt(i))){
				ArrayList<Integer> arr = hash.get(s.charAt(i));
				for(int j = arr.size()-1; j >= 0; j--) {
					r[arr.get(j)] += r[arr.get(j)-1];
				}
			}
		}
		
		return r[t.length()];
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DistinctSubsequnce ins = new DistinctSubsequnce();
		String s = "rabbbit";
		String t = "rabbit";
		System.out.println(ins.numDistinct(s, t));
	}

}
