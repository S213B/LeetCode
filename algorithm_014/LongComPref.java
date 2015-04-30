package algorithm_014;

public class LongComPref {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < strs[0].length(); i++) {
        	for(int j = 1; j < strs.length; j++) {
        		if(i == strs[j].length() || strs[j].charAt(i) != strs[0].charAt(i)) {
        			return sb.toString();
        		}
        	}
        	sb.append(strs[0].charAt(i));
        }
        
        return strs[0];
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] strs = {"asdjlzxnv", "asd12374", "asdcbnvc"};
		LongComPref s = new LongComPref();
		System.out.println(s.longestCommonPrefix(strs));
	}

}
