package algorithm_4;

public class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int A[], int B[]) {
    	
    	int m, n, l_mid, s_mid, start = 1, end;
    	int[] l, s;
    	if(A.length > B.length) {
    		l = new int[A.length+2];
    		for(int i = 1; i <= A.length; i++) {
    			l[i] = A[i-1];
    		}
    		s = new int[B.length+2];
    		for(int i = 1; i <= B.length; i++) {
    			s[i] = B[i-1];
    		}
    	} else {
    		l = new int[B.length+2];
    		for(int i = 1; i <= B.length; i++) {
    			l[i] = B[i-1];
    		}
    		s = new int[A.length+2];
    		for(int i = 1; i <= A.length; i++) {
    			s[i] = A[i-1];
    		}
    	}
    	l[0] = s[0] = Integer.MIN_VALUE;
    	l[l.length-1] = s[s.length-1] = Integer.MAX_VALUE;
    	
    	if(s.length%2 == 0 && l.length%2 ==0) {
    		l_mid = l.length/2-1;
    	} else {
    		l_mid = l.length/2;
    	}
    	s_mid = s.length/2;
    	end = s.length-1;
    	
    	while(true) {
    		if(s[s_mid-1] > l[l_mid]) {
    			end = s_mid;
    		} else if(l[l_mid-1] > s[s_mid]) {
    			start = s_mid+1;
    		} else {
    			if(l[l_mid] >= s[s_mid]) {
    				if(s_mid+1 < s.length) {
    					m = l[l_mid] < s[s_mid+1] ? l[l_mid] : s[s_mid+1];
    				} else {
    					m = l[l_mid];
    				}
    				n = s[s_mid];
    			} else {
    				if(l_mid+1 < l.length) {
    					m = s[s_mid] < l[l_mid+1] ? s[s_mid] : l[l_mid+1];
    				} else {
    					m = s[s_mid];
    				}
    				n = l[l_mid];
    			}
    			break;
    		}
    		int pre = s_mid;
    		s_mid = (start+end)/2;
    		l_mid += pre-s_mid;
    	}
    	
    	if(l.length%2 == 0 && s.length%2 == 0) {
    		return (double)(m+n)/2;
    	} else if(l.length%2 == 1 && s.length%2 == 1) {
    		return (double)(m+n)/2;
    	} else {
    		return n;
    	}
    }
    
    public static void main(String[] args) {
    	long start = System.currentTimeMillis();
    	MedianOfTwoSortedArrays s = new MedianOfTwoSortedArrays();
    	int[] A = {1, 2, 3}, B = {4, 5, 6};
    	System.out.println(s.findMedianSortedArrays(A, B));
    	long end = System.currentTimeMillis();
    	System.out.println(end - start); 
    }
}