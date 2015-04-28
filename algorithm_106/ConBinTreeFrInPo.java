package algorithm_106;

public class ConBinTreeFrInPo {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
    	if(inorder.length == 0) {
    		return null;
    	}
    	
        TreeNode tree = new TreeNode(postorder[postorder.length-1]);
        makeTree(tree, inorder, 0, inorder.length, postorder, 0, postorder.length);
        
        return tree;
    }

	private void makeTree(TreeNode tree, int[] inorder, int inStart, int inEnd, int[] postorder, int postStart, int postEnd) {
		if(inEnd - inStart == 1) {
			return;
		}
		int root = tree.val, i, j;
		for(i = inStart; i < inEnd; i++) {
			if(inorder[i] == root) {
				break;
			}
		}
		j = postStart + (i - inStart);
		if(i == inEnd-1) {
			tree.left = new TreeNode(postorder[postEnd-2]);
			makeTree(tree.left, inorder, inStart, i, postorder, postStart, postEnd-1);
		} else if(i == inStart) {
			tree.right = new TreeNode(postorder[postEnd-2]);
			makeTree(tree.right, inorder, i+1, inEnd, postorder, postStart, postEnd-1);
		} else {
			tree.left = new TreeNode(postorder[j-1]);
			tree.right = new TreeNode(postorder[postEnd-2]);
			makeTree(tree.left, inorder, inStart, i, postorder, postStart, j);
			makeTree(tree.right, inorder, i+1, inEnd, postorder, j, postEnd-1);
		}
		
		return;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ConBinTreeFrInPo s = new ConBinTreeFrInPo();
		int[] a = {1, 3, 2}, b = {3, 2, 1}, c = {1, 2, 3, 4, 6, 5}, d = {1, 3, 2, 6, 5, 4};
		s.buildTree(a, b);
		s.buildTree(c, d);
	}
	
	class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
}
