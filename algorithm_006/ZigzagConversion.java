package algorithm_6;

public class ZigzagConversion {
    public String convert(String s, int nRows) {
    	if(nRows == 1) {
    		return s;
    	}
    	
        StringBuilder br = new StringBuilder();
        int dis = (nRows-1)*2;
        
        for(int i = 0; i < nRows; i ++) {
        	int j = i, step = dis-i*2;
        	if(i == nRows-1) {
        		step = dis;
        	}
        	while(j < s.length()) {
        		br.append(s.charAt(j));
        		j += step;
        		if(dis != step) {
        			step = dis - step;
        		}
        	}
        }
        
        return br.toString();
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ZigzagConversion s = new ZigzagConversion(); 
		System.out.println(s.convert("PAYPALISHIRING", 4));
	}

}
