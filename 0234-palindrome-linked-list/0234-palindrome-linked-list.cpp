/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        
        while(second != nullptr && second->next != nullptr) {
            first = first->next;
            second = second->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = first;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }

        ListNode* head2 = prev;
        bool vaild = true;

        while(head2 != nullptr) {
            if(head->val != head2->val) {
                vaild = false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return vaild;
    }
};