/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;

        int pos = 0;

        while(head != nullptr) {
            if(mp.find(head) == mp.end()) {
                mp[head] = pos;
            } else {
                return head;
            }
            head = head->next;
            pos++;
        }
        return nullptr;
    }
};