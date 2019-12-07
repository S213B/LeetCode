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
    public int countNodes(TreeNode root) {
        if(root == null) {
            return 0;
        }
        
        int r = 0, level = -1, curLvl = 0;
        TreeNode _root = root, rightBro = root;
        while(_root != null) {
            level++;
            _root = _root.left;
        }
        r += (1 << level)-1;
        
        while(curLvl != level) {
            _root = root;
            int _lvl = -1;
            while(_root != null) {
                _lvl++;
                _root = _root.right;
            }
            if(_lvl == level-curLvl) {
                if(curLvl == 0) {
                    return r+r+1;
                }
                r += (1 << _lvl);
                root = rightBro;
            } else {
                rightBro = root.right;
                root = root.left;
                curLvl++;
            }
        }
        
        return root == null ? r : r+1;
    }
}
