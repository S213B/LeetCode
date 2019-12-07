package algorithm_165;

import java.util.ArrayList;

public class CompareVersionNumbers {
    public int compareVersion(String version1, String version2) {
	    ArrayList<Integer> v1 = new ArrayList<Integer>(), v2 = new ArrayList<Integer>();
	    String[] t1 = version1.split("\\.");
	    for(int i = 0; i < t1.length; i++) {
	    	v1.add(new Integer(t1[i]));
	    }
	    String[] t2 = version2.split("\\.");
	    for(int i = 0; i < t2.length; i++) {
	    	v2.add(new Integer(t2[i]));
	    }
	    
	    int i;
	    for(i = 0; i < v1.size() && i < v2.size(); i++) {
	    	if(v1.get(i) > v2.get(i)) {
	    		return 1;
	    	} else if(v1.get(i) < v2.get(i)) {
	    		return -1;
	    	} else if(i == v1.size()-1 && i == v2.size()-1) {
	    		return 0;
	    	}
	    }
	    
	    if(i == v2.size()) {
	    	for(; i < v1.size(); i++) {
	    		if(v1.get(i) > 0) {
	    			return 1;
	    		}
	    	}
	    	return 0;
	    } else {
	    	for(; i < v2.size(); i++) {
	    		if(v2.get(i) > 0) {
	    			return -1;
	    		}
	    	}
	    	return 0;
	    }
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long start = System.currentTimeMillis();
		CompareVersionNumbers s = new CompareVersionNumbers();
		System.out.println(s.compareVersion("12.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.12", "12.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.1212.12.12.12"));
		long end = System.currentTimeMillis();
		System.out.println(end-start);
	}

}
