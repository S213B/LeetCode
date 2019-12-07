public class Solution {
    public boolean isPalindrome(String s) {
        char[] str = new char[s.length()];
        int end = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                str[end++] = s.charAt(i);
            }
            if(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                str[end++] = (char) (s.charAt(i)+32);
            }
            if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                str[end++] = s.charAt(i);
            }
        }
        
        for(int i = 0, _end = end-1; i < (end/2); i++, _end--) {
            if(str[i] != str[_end]) {
                return false;
            }
        }
        
        return true;
    }
}
