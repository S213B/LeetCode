class Solution {
public:
    string fractionToDecimal(int _numerator, int _denominator) {
        long numerator = _numerator;
        long denominator = _denominator;
        if (numerator % denominator == 0) return to_string(numerator/denominator);
        
        string ans, fra;
        unordered_map<long, int> pos;
        int p = 0;
        
        if (numerator*denominator < 0) {
            ans = '-';
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        
        ans += to_string(numerator / denominator) + '.';
        numerator = numerator % denominator;
        
        while (1) {
            numerator *= 10;
            int num = numerator / denominator;
            
            if (pos.find(numerator) == pos.end()) {
                fra += to_string(num);
                pos[numerator] = p++;
            } else {
                fra.insert(fra.begin() + pos.find(numerator)->second, '(');
                fra += ')';
                break;
            }
            
            numerator -= num * denominator;
            if (!numerator) break;
        }
        
        return ans+fra;
    }
};
