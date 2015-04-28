package algorithm_191;

public class NumOf1Bit {
	
    public int hammingWeight(int n) {
        int r = 0;
        while(n != 0) {
            r += n & 0x00000001;
            n = n >>> 1;
        }
        return r;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		NumOf1Bit s = new NumOf1Bit();
		System.out.print(s.hammingWeight(1<<31));
	}

}
