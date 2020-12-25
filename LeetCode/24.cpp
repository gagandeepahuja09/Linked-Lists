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
//     1 2 3 4 5 6 7 8 9
//     2 1 4 3 6 5 8 7 9
//     1 -> 2 -> (rest)
//     2 -> 1 -> 
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head -> next)) {
            return head; 
        } 
        ListNode* nxt = head -> next;
        ListNode* newHead = head -> next -> next;
        nxt -> next = head;
        head -> next = swapPairs(newHead);
        return nxt;
    }
};
