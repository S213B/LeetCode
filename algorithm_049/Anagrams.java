package algorithm_049;

import java.util.*;

public class Anagrams {
    class MyComparator implements Comparator<String>{
        public int compare(String o1, String o2) {  
          if (o1.length() > o2.length()) {
             return 1;
          } else if (o1.length() < o2.length()) {
             return -1;
          }
          return o1.compareTo(o2);
        }
    }
    
    public List<String> anagrams(String[] strs) {
        List<String> r = new ArrayList<String>();
        int cnt = strs.length;
        
        if(cnt < 2) {
            return r;
        }
        
        Arrays.sort(strs, new MyComparator());
        int[][] letters = new int[cnt][26];
        boolean[] ana = new boolean[cnt];
        
        for(int i = 0; i < cnt; i++) {
            for(int j = 0; j < 26; j++) {
                letters[i][j] = 0;
            }
            ana[i] = false;
        }
        
        for(int i = 0; i < cnt; i++) {
            for(char c : strs[i].toCharArray()) {
                letters[i][c-'a']++;
            }
        }
        
        boolean eq;
        
        for(int i = 0; i < cnt-1; i++) {
            eq = false;
            if(ana[i] == true) {
                continue;
            }
        	for(int j = i+1; j < cnt && strs[i].length() == strs[j].length(); j++) {
        		int k;
        		for(k = 0; k < 26; k++) {
        			if(letters[i][k] != letters[j][k]) {
        				break;
        			}
        		}
        		if(k == 26) {
        		    r.add(strs[j]);
        		    ana[j] = true;
        		    eq = true;
        		}
        	}
        	if(eq) {
        	    r.add(strs[i]);
        	}
        }
        
        return r;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
