/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_map<ListNode*, int> mp;

//         int pos = 0;

//         while(head != nullptr) {
//             if(mp.find(head) == mp.end()) {
//                 mp[head] = pos;
//             } else {
//                 return head;
//             }
//             head = head->next;
//             pos++;
//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};