public class Solution {
    public boolean isNumber(String s) {
        if(s == null) {
            return false;
        }
        
        s = s.toLowerCase();
        return s.matches("\\s*(\\+|-)?((\\d*\\.?\\d+)|(\\d+\\.?\\d*))(e(\\+|-)?\\d+)?\\s*");
    }
}
