public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] r = new int[n];
        for(int i = 0; i < n; i ++) {
            r[i] = 0;
        }
        
        for(int i = n-1; i > 0; i--) {
            for(int j = 0; j < i; j++) {
                int a = r[j] + triangle.get(i).get(j);
                int b = r[j+1] + triangle.get(i).get(j+1);
                r[j] = a < b ? a : b;
            }
        }
        
        return r[0]+triangle.get(0).get(0);
    }
}
