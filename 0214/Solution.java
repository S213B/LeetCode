public class Solution {
    public String shortestPalindrome(String s) {
        char[] _s = s.toCharArray();
        for(int i = 0; i < (_s.length+1)/2; i++) {
            char t = _s[i];
            _s[i] = _s[_s.length-1-i];
            _s[_s.length-1-i] = t;
        }
        
        String str = new String(), _str = new String();
        for(int i = 0; i < _s.length; i++) {
            str = new String(_s, i, _s.length-i);
            _str = new String(_s, 0, i);
            if(s.startsWith(str)) {
                break;
            }
        }
        
        return _str+s;
    }
}
