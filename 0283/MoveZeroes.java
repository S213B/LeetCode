public class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0, j;
        while( i < nums.length && nums[i] != 0 ) i++;
        j = i+1;
        while( j < nums.length && nums[j] == 0 ) j++;
        while( j < nums.length ) {
            nums[i] = nums[j];
            nums[j] = 0;
            i++;
            j++;
            while( j < nums.length && nums[j] == 0 ) j++;
        }
    }
}
