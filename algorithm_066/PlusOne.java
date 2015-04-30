package algorithm_066;

public class PlusOne {
	
    public int[] plusOne(int[] digits) {
        int len = digits.length;

        for(int i = len-1; i >= 0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        
        int[] r = new int[len+1];
        for(int i = 1; i < len+1; i++) {
            r[i] = digits[i-1];
        }
        r[0] = 1;
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
