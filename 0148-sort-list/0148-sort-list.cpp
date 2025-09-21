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
    ListNode* sortList(ListNode* head) {
        vector<int> v1;
        ListNode* temp = head;
        while(temp != nullptr) {
            v1.push_back(temp->val);
            temp = temp->next;
        }

        sort(v1.begin(), v1.end());
        int i = 0;
        temp = head;
        while(temp != NULL) {
            temp->val = v1[i];
            temp = temp->next;
            i++;
        }

        return head;

    }
};