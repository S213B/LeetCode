package algorithm_143;

import java.util.ArrayList;

public class ReorderList {
	
	class ListNode {
		int val;
		ListNode next;
		ListNode(int x) { val = x; }
	}

    public void reorderList(ListNode head) {
        ArrayList<ListNode> arr = new ArrayList<ListNode>();
        while(head != null) {
            arr.add(head);
            head = head.next;
        }
        if(arr.size() == 0) {
            return;
        }
        
        int start = 0, end = arr.size()-1;
        while(true) {
            if(start == end) {
                arr.get(start).next = null;
                break;
            } else {
                arr.get(start++).next = arr.get(end);
            }
            if(start == end) {
                arr.get(end).next = null;
                break;
            } else {
                arr.get(end--).next = arr.get(start);
            }
        }
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
