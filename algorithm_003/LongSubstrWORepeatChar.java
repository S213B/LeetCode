package algorithm_3;

public class LongSubstrWORepeatChar {
    public int lengthOfLongestSubstring(String s) {
        int[] idx = new int[Byte.MAX_VALUE];
        int t = 0, max = 0, start = 0;

        for(int i = 0; i < s.length(); i++) {
        	if(idx[s.charAt(i)] == 0 || idx[s.charAt(i)] < start) {
        		t++;
        		idx[s.charAt(i)] = i+1;
        	} else {
        		if(t > max) {
        			max = t;
        			if(max == Byte.MAX_VALUE) {
        				break;
        			}
        		}
        		start = idx[s.charAt(i)]+1;
        		t = i-idx[s.charAt(i)]+1;
        		idx[s.charAt(i)] = i+1;
        	}
        }
        
        return (max > t ? max : t);
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LongSubstrWORepeatChar s = new LongSubstrWORepeatChar();
		System.out.print(s.lengthOfLongestSubstring("aa"));
		System.out.print(s.lengthOfLongestSubstring("aab"));
	}

}
