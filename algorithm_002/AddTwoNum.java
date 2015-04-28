package algorithm_2;

public class AddTwoNum {
	
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int c = 0;
        ListNode r = l1, pre = l1;
        while(l1 != null) {
        	if(l2 != null) {
        		l1.val += l2.val+c;
        		l2 = l2.next;
        	} else {
        		l1.val += c;
        	}
        	c = l1.val/10;
        	l1.val %= 10;
        	pre = l1;
        	l1 = l1.next;
        }
        pre.next = l2;
        while(l2 != null) {
        	if(c == 0) {
        		break;
        	} else if(l2.val == 9){
        		l2.val = 0;
        		pre = l2;
        		l2 = l2.next;
        	} else {
        		l2.val++;
        		c = 0;
        		break;
        	}
        }
        if(c != 0) {
        	if(pre.next == null) {
        		pre.next = new ListNode(1);
        	}
        }
        
        return r;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		AddTwoNum s = new AddTwoNum();
		ListNode l1 = new ListNode(1);
		ListNode l2 = new ListNode(9), l3 = l2;
		for(int i = 0; i < 3; i++) {
			l3.next = new ListNode(9);
			l3 = l3.next;
		}
		ListNode r = s.addTwoNumbers(l1, l2);
		while(r != null) {
			System.out.print(r.val);
			r = r.next;
		}
	}

}

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}