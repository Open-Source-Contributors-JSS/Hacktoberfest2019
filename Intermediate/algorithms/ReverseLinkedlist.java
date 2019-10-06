package Intermediate.algorithms;

import java.util.*;

public class ReverseLinkedlist{
    public class ListNode {
             int val;
             ListNode next;
             ListNode(int x) { val = x; }
        }
    //Logic for reversing the list node
    public ListNode reverseList(ListNode head){
        ListNode curr = head;
        ListNode prev = null;

        while(curr != null){
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
}