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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }
        // 0 1 1 1 2 2 3
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* curr = dummy;
        while (curr -> next && curr -> next -> next) {
            ListNode *temp = curr -> next -> next;
            // cout << curr -> next -> val << " " << temp -> val << endl;
            if (curr -> next -> val == temp -> val) {
                // while we keep getting the same value
                while(curr && curr -> next && curr -> next -> val == temp -> val) {
                    curr -> next = curr -> next -> next;    
                }
            } else {
                curr = curr -> next;
            }
        }
        return dummy -> next;
    }
};
