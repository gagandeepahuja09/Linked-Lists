/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 */

ListNode* Solution::deleteDuplicates(ListNode* A) {
    bool flag = false;
    ListNode *head = NULL, *p;
    while(A) {
        if(!head) {
            if((A -> next && A -> val != A -> next -> val) || !(A -> next)) {
                head = A;
                p = head;
            }
        }
        else {
            if((A -> next && A -> val != A -> next -> val) || !(A -> next)) {
                p -> next = A;
                p = p -> next;
            }
        }
        A = A -> next;
    }
    return head;
}

