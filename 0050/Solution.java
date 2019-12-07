class Solution {
    public double myPow(double x, int n) {
        if(n == 0 || x == 1.0) {
            return (double)1;
        }
        
        long t = n < 0 ? -(long)n : n, i;
        double[] st = new double[33];
        double r = 1;
        int j;
        
        for(i = 1, j = 0; i <= t; i*=2, x*=x, j++) {
            st[j] = x;
        }
        for(i /= 2, j--; t != 0; i /= 2, j--) {
            if(t >= i) {
                t -= i;
                r *= st[j];
            }
        }
        
        return n < 0 ? (1/r) : r;
    }
}
