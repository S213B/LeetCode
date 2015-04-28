package algorithm_9;

public class PalindromeNum {
    public boolean isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int y = 0, t = x;
        while(t != 0) {
            y *= 10;
            y += t%10;
            t /= 10;
        }
        
        return y == x;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PalindromeNum s = new PalindromeNum();
		System.out.println(s.isPalindrome(1999999993));
	}

}
