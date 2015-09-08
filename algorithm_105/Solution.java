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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0 || inorder.length == 0) {
            return null;
        }
        
        TreeNode root = new TreeNode(preorder[0]);
        int idx1;
        
        for(idx1 = 0; inorder[idx1] != preorder[0]; idx1++);        //idx1:index of root in inorder
        foo(root, preorder, 1, 1+idx1, inorder, 0, idx1, true);
        foo(root, preorder, 1+idx1, preorder.length, inorder, idx1+1, inorder.length, false);
        
        return root;
    }
    
    private void foo(TreeNode root, int[] preorder, int a, int b, int[] inorder, int c, int d, boolean child) {
        if(a == b || c == d) {
            return;
        }
        
        if(child) {
            root.left = new TreeNode(preorder[a]);
            root = root.left;
        } else {
            root.right = new TreeNode(preorder[a]);
            root = root.right;
        }
        
        int idx1;
        for(idx1 = 0; inorder[c+idx1] != preorder[a]; idx1++);        //idx1:index of root in inorder
        foo(root, preorder, a+1, a+1+idx1, inorder, c, c+idx1, true);
        foo(root, preorder, a+1+idx1, b, inorder, idx1+1+c, d, false);
    }
}
