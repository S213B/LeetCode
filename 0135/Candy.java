package algorithm_135;

public class Candy {
	
    public int candy(int[] ratings) {
        
        if(ratings.length == 0) {
            return 0;
        }
        
        int r = 1, cur = 1, compensate = 0;
        
        for(int i = 1; i < ratings.length; i++) {
            if(ratings[i-1] < ratings[i]) {
                if(compensate != 0) {
                    int t = 1-cur;
                    if(t < 0) {
                        r += (compensate) * t;
                    } else {
                        r += (compensate+1) * t;
                    }
                    cur = 1;
                    compensate = 0;
                }
                r += ++cur;
            } else if(ratings[i-1] == ratings[i]) {
                if(compensate != 0) {
                    int t = 1-cur;
                    if(t < 0) {
                        r += (compensate) * t;
                    } else {
                        r += (compensate+1) * t;
                    }
                    compensate = 0;
                }
                cur = 1;
                r += cur;
            } else {
                r += --cur;
                compensate++;
            }
        }
        if(compensate != 0) {
            int t = 1-cur;
            if(t < 0) {
                r += (compensate) * t;
            } else {
                r += (compensate+1) * t;
            }
        }
        
        return r;
        
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
