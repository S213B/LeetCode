package algorithm_134;

public class GasStation {

    public int canCompleteCircuit(int[] gas, int[] cost) {
        int r = 0;
        for(int i = 0; i < gas.length; i++) {
        	gas[i] -= cost[i];
        	r += gas[i];
        }
        if(r < 0) {
        	return -1;
        }
        int[] g = new int[gas.length*2];
        for(int i = 0; i < gas.length; i++) {
        	g[i] = g[i+gas.length] = gas[i];
        }
        
        int t = 0, max = Integer.MIN_VALUE, idx = 0;
        for(int i = gas.length-1; i >= 0; i--) {
        	t += g[i];
        	if(t > max) {
        		max = t;
        		idx = i;
        	}
        }
        int tmax = max, tidx = idx;
        for(int i = gas.length; i < gas.length*2-1; i++) {
        	if(tmax <= 0) {
        		tmax = g[i];
        		tidx = i-gas.length;
        	} else {
        		tmax += g[i];
        		if(tmax > max) {
        			max = tmax;
        			idx = tidx;
        		}
        	}
        }
        
        return idx;
    }
    
    public int canCompleteCircuit2(int[] gas, int[] cost) {
        int r = 0, can = 0;
        for(int i = 0, t = 0; i < gas.length; i++) {
        	t += gas[i] - cost[i];
        	can += t;
        	if(t < 0) {
        		r = i+1;
        		t = 0;
        	}
        }
        
        if(can < 0){
        	return -1;
        } else {
        	return r;
        }
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GasStation s = new GasStation();
		int[] a = {1,1,2,1,1}, b = {1,2,1,1,1};
		System.out.println(s.canCompleteCircuit2(a, b) == s.canCompleteCircuit(a, b));
	}

}
