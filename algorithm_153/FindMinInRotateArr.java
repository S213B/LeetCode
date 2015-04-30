package algorithm_153;

public class FindMinInRotateArr {
	
    public int findMin(int[] num) {
        int end = num.length-1, start = 0, mid = start+(end-start)/2;
        if(num[0] < num[end] || end == 0) {
            return num[0];
        }
        while(start < end) {
            if(num[mid] < num[end]) {
            	end = mid;
            } else {
                start = ++mid;
            }
                mid = start+(end-start)/2;
        }
        
        return num[end];
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
