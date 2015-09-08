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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) {
            return false;
        }
        
        return dfs(root, sum);
    }
    
    private boolean dfs(TreeNode node, int sum) {
        if(node == null) {
            return false;
        }
        
        sum -= node.val;
        if(node.left == null && node.right == null && sum == 0) {
            return true;
        } else {
            return (dfs(node.left, sum) | dfs(node.right, sum));
        }
    }
}
