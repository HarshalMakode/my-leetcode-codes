// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {

//         vector<int> v1;

//         ListNode* temp = head;
//         while (temp != nullptr) {
//             v1.push_back(temp->val);
//             if (temp->next == nullptr) break; 
//             temp = temp->next->next;
//         }

//         ListNode* temp1 = head->next;
//         while (temp1 != nullptr) {
//             v1.push_back(temp1->val);
//             if (temp1->next == nullptr) break;
//             temp1 = temp1->next->next;
//         }

//         ListNode* curr = head;
//         int i = 0;
//         while (curr != nullptr && i < v1.size()) {
//             curr->val = v1[i];
//             curr = curr->next;
//             i++;
//         }
        

//         return head; 
//     }
// };


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* odd = head;               
        ListNode* even = head->next;        
        ListNode* evenHead = even;          

        while (even && even->next) {
            odd->next = even->next;   
            odd = odd->next;          
            even->next = odd->next;   
            even = even->next;        
        }

        odd->next = evenHead; 

        return head;
    }
};
