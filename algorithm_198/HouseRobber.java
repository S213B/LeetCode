package algorithm_198;

public class HouseRobber {
    public int rob(int[] num) {
    	if(num.length == 0) {
    		return 0;
    	}
    	
        int pick = num[0], noPick = 0;
        
    	for(int i = 1; i < num.length; i++) {
    		int _pick = noPick + num[i];
    		int _noPick = pick > noPick ? pick : noPick;
    		pick = _pick;
    		noPick = _noPick;
    	}
    	
    	return (pick > noPick ? pick : noPick);
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = {2, 1, 3, 6};
		HouseRobber s = new HouseRobber();
		System.out.println(s.rob(a));
	}

}
