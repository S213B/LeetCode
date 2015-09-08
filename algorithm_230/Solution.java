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
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        
        while(true) {
            while(true) {
                if(root == null) {
                    break;
                }
                stack.push(root.right);
                stack.push(root);
                root = root.left;
            }
            
            root = stack.pop();
            k--;
            if(k == 0) {
                return root.val;
            }
            
            root = stack.pop();
        }
        
    }
}
