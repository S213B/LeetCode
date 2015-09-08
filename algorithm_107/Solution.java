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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> r = new LinkedList<List<Integer>>();
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        int cnt = 1;
        if(root != null) {
            queue.add(root);
        }
        
        while(!queue.isEmpty()) {
            LinkedList<Integer> ele = new LinkedList<Integer>();
            while(cnt != 0) {
                TreeNode n = queue.poll();
                ele.add(n.val);
                if(n.left != null) {
                    queue.add(n.left);
                }
                if(n.right != null) {
                    queue.add(n.right);
                }
                cnt--;
            }
            cnt = queue.size();
            r.addFirst(ele);
        }
        
        return r;
    }
}
