/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> r = new ArrayList<List<Integer>>();
        
        dfs(r, root, sum, new ArrayList<Integer>());
        
        return r;
    }
    
    private void dfs(List<List<Integer>> r, TreeNode node, int sum, ArrayList<Integer> x) {
        if(node == null) {
            return;
        }
        
        sum -= node.val;
        x.add(node.val);
        if(node.left == null && node.right == null && sum == 0) {
            r.add(x);
        } else {
            dfs(r, node.left, sum, (ArrayList<Integer>) x.clone());
            dfs(r, node.right, sum, x);
        }
    }
}
