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
    private static int max;
    public int maxPathSum(TreeNode root) {
        max = Integer.MIN_VALUE;
        int r = foo(root);
        
        return max > r ? max : r;
    }
    
    private int foo(TreeNode root) {
        int left = Integer.MIN_VALUE, right = Integer.MIN_VALUE;
        
        if(root.left == null && root.right == null) {
            max = root.val < max ? max : root.val;
            return root.val;
        }
        
        if(root.left == null) {
            right = foo(root.right);
            max = right < max ? max : right;
            return root.val < (right+root.val) ? (right+root.val) : root.val;
        }
        
        if(root.right == null) {
            left = foo(root.left);
            max = left < max ? max : left;
            return root.val < (left+root.val) ? (left+root.val) : root.val;
        }
        
        int t;
        left = foo(root.left);
        right = foo(root.right);
        
        t = left < right ? right : left;
        t = t < (left+right+root.val) ? (left+right+root.val) : t;
        max = t < max ? max : t;
        
        t = (left+root.val) < (right+root.val) ? (right+root.val) : (left+root.val);
        t = t < root.val ? root.val : t;
        return t;
    }
}
