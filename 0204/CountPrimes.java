package algorithm_204;

public class CountPrimes {
	
    public int countPrimes(int n) {
        boolean[] num = new boolean[n];
        int r = 0;
        
        for(int i = 2; i < n; i++) {
            num[i] = true;
        }
        for(int i = 2; i < n; i++) {
            if(num[i]) {
                r++;
                for(int j = i+i; j < n; j+=i) {
                    num[j] = false;
                }
            }
        }
    
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
