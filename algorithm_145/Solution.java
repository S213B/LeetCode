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
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> r = new LinkedList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        if(root != null) {
            stack.push(root);
        }
        
        while(!stack.isEmpty()) {
            r.addFirst(root.val);
            stack.push(root.left);
            root = root.right;
            while(root == null && !stack.isEmpty()) {
                root = stack.pop();
            }
        }
        
        return r;
    }
}
