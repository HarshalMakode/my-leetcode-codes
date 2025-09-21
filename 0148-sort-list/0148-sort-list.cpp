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
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> v1;
//         ListNode* temp = head;
//         while(temp != nullptr) {
//             v1.push_back(temp->val);
//             temp = temp->next;
//         }

//         sort(v1.begin(), v1.end());
//         int i = 0;
//         temp = head;
//         while(temp != NULL) {
//             temp->val = v1[i];
//             temp = temp->next;
//             i++;
//         }

//         return head;

//     }
// };

class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if(list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return dummy->next;

    }


    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};