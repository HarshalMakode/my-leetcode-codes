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
    int pairSum(ListNode* head) {
        int result = 0;

        vector<int> v1;

        while(head) {
            v1.push_back(head->val);
            head = head->next;
        }

        int first = 0;

        int last = v1.size() - 1;

        while(first <= last) {
            result = max(result, v1[first] + v1[last]);
            first++;
            last--;
        }
        return result; 
    }
};