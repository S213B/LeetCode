package algorithm_199;

import java.util.*;

public class BinTreeRightView {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> r = new ArrayList<Integer>();
        LinkedList<TreeNode> heap = new LinkedList<TreeNode>();
        heap.add(root);
        
        while(!heap.isEmpty()) {
        	TreeNode t = heap.getLast();
        	if(t != null) {
        		r.add(t.val);
        		int cnt = heap.size();
        		for(int i = 0; i < cnt; i++) {
        			t = heap.poll();
        			if(t != null) {
        				heap.add(t.left);
        				heap.add(t.right);
        			}
        		}
        	} else {
        		heap.removeLast();
        	}
        }
        
        return r;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

	class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
}
