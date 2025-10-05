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
    ListNode* removeElements(ListNode* head, int val) {

        if(!head) return NULL;

        while (head != nullptr && head->val == val) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }

        ListNode* temp = head;

        while(temp != nullptr && temp->next != nullptr) {
            if(temp->next->val == val) {
                ListNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};