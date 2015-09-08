public class Solution {
    public String intToRoman(int num) {
        StringBuilder r = new StringBuilder();
        String[] b1000 = {"", "M", "MM", "MMM"}, b100 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        b10 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        b1 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        int t;
        
        t = num/1000;
        r.append(b1000[t]);
        num -= t*1000;
        
        t = num/100;
        r.append(b100[t]);
        num -= t*100;
        
        t = num/10;
        r.append(b10[t]);
        num -= t*10;
        
        r.append(b1[num]);
        
        return r.toString();
    }
}
