package algorithm_100;

import java.util.Stack;

public class SameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
		if(p == q) {
			return true;
		} else if(p != null && q != null) {
			if(p.val != q.val) {
				return false;
			} else {
				return (isSameTree(p.left, q.left) && isSameTree(p.right, q.right));
			}
		} else {
			return false;
		}
    }

    public boolean isSameTree2(TreeNode p, TreeNode q) {
		TreeNode[] a = new TreeNode[300], b = new TreeNode[300];
		TreeNode x, y;
		int i = 1, j = 1;
		a[0] = p;
		b[0] = q;
		while(i != 0) {
			x = a[--i];
			y = b[--j];
			if(x != null && y != null) {
				if(x.val != y.val) {
					return false;
				} else {
					a[i++] = x.left;
					a[i++] = x.right;
					b[j++] = y.left;
					b[j++] = y.right;
				}
			} else if(x == y) {
				;
			} else {
				return false;
			}
		}
		
		return true;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack<Integer> a = new Stack<Integer>();
		a.push(null);
		System.out.print(a.pop());
	}

	class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
}

