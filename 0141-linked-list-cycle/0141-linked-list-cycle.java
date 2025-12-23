/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {

        HashSet<ListNode> mp = new HashSet<>();

        while(head != null) {
            if(mp.contains(head)) {
                return true;
                
            } 
            mp.add(head);
            head = head.next;
        }
        return false;
    }
}