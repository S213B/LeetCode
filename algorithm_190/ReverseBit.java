package algorithm_190;

public class ReverseBit {
    public int reverseBits(int n) {
        int i = 0, r = 0;
        while(n != 0) {
            r = (r << 1) | (n & 0x00000001);
            n = n >>> 1;
            i++;
        }
        r = r << (32-i);
        return r;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ReverseBit s = new ReverseBit();
		System.out.print(s.reverseBits((1<<31)+(1<<29)));
	}

}
