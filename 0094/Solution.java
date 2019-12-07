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
    public List<Integer> inorderTraversal(TreeNode root) {
        LinkedList<Integer> r = new LinkedList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);
        
        while(!stack.empty()) {
            root = stack.pop();
            while(root != null) {
                stack.push(root.right);
                stack.push(root);
                root = root.left;
            }
            
            if(!stack.empty()) {
                root = stack.pop();
                r.add(root.val);
            } else {
                break;
            }
        }
        
        return r;
    }
}
