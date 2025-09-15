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
//     bool hasCycle(ListNode *head) {
//         unordered_map<int, int> mp;

//         bool present = false;

//         int pos = -1;

//         while(head != NULL && head->next != NULL) {
//             if(mp.find(pos) != mp.end()) {
//                 mp[pos]++;
//             } else {
//                 present = true;
//                 break;
//             }
//             head = head->next;
//             pos++;
//         }

//         return present;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;

        while (head != nullptr) {
            if (visited[head]) {
                return true; 
            }
            visited[head] = true;
            head = head->next;
        }
        return false;
    }
};