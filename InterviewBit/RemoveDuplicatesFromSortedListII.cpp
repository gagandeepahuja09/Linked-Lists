/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *head = NULL, *p;
    while(A) {
        if(A -> next && A -> val == A -> next -> val) {
            int num = A -> val;
            while(A && A -> val == num) {
                A = A -> next;
            }
        }
        else {
            if(!head) {
                head = A;
                p = head;
            }
            else {
                p -> next = A;
                p = p -> next;
            }
            A = A -> next;
        }
    }
    p -> next = NULL;
    return head;
}

