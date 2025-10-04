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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr != nullptr) {
            if(curr->val >= prev->val) {
                prev = curr;
                curr = curr->next;
                continue;
            }

            ListNode* temp = dummy;

            while(curr->val > temp->next->val) {
                temp = temp->next;
            }

            prev->next = curr->next;
            curr->next = temp->next;
            temp->next = curr;
            curr = prev->next;
        }
        
        return dummy->next;
    }
};