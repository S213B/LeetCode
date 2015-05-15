package algorithm_203;

public class RmLinkedListEle {

	class ListNode {
		int val;
		ListNode next;
		ListNode(int x) { val = x; }
	}
	
    public ListNode removeElements(ListNode head, int val) {
        ListNode r = null, list = null;
        boolean isHead = true;
        
        while(head != null) {
            if(head.val == val) {
                if(!isHead) {
                    list.next = head.next;
                }
            } else {
                if(isHead) {
                    r = list = head;
                    isHead = false;
                } else {
                    list = head;
                }
            }
            head = head.next;
        }
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

}
