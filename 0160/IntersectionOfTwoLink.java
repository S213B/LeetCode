package algorithm_160;

public class IntersectionOfTwoLink {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lena = 0, lenb = 0, dis;
        ListNode ha = headA, hb = headB;
        while(ha != null) {
            lena++;
            ha = ha.next;
        }
        while(hb != null) {
            lenb++;
            hb = hb.next;
        }
        dis = lenb-lena;
        
        while(dis != 0) {
            if(dis > 0) {
                headB = headB.next;
                dis--;
            } else {
                headA = headA.next;
                dis++;
            }
        }
        while(headA != headB) {
            headA = headA.next;
            headB = headB.next;
        }
        return headA;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	class ListNode {
	 	int val;
	 	ListNode next;
	 	ListNode(int x) {
		 	val = x;
		 	next = null;
	 	}
	}
}
