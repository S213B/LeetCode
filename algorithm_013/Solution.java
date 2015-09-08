class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        map.put('M', 1000);
        map.put('D', 500);
        map.put('C', 100);
        map.put('L', 50);
        map.put('X', 10);
        map.put('V', 5);
        map.put('I', 1);
        int r = map.get(s.charAt(s.length()-1)), last = r;
        
        for(int i = s.length()-2; i >= 0; i--) {
            int t = map.get(s.charAt(i));
            if(t >= last) {
                r += t;
            } else {
                r -= t;
            }
            last = t;
        }
        
        return r;
    }
}
