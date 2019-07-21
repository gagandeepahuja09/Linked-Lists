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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ret = new ListNode(0);
        while(head) {
            ListNode* it = ret;
            while(it -> next && it -> next -> val < head -> val) {
                it = it -> next;
            }
            ListNode* next = head -> next;
            head -> next = it -> next;
            it -> next = head;
            head = next;
        }
        return ret -> next;
    }
};
