public class Solution {
    public int countDigitOne(int n) {
        if(n < 10) {
            return n >= 1 ? 1 : 0;
        }
        
        int zero = 0, digit = n, pow = 1, r;
        
        while(digit > 9) {
            digit /= 10;
            zero++;
            pow *= 10;
        }
        
        if(digit == 1) {
            r = zero*(pow/10) + (n-pow+1);
        } else {
            r = digit*zero*(pow/10) + pow;
        }
        
        return r+countDigitOne(n - digit*pow);
    }
}
