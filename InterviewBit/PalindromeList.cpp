/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(!A || !(A -> next))
        return 1;
    ListNode *slow = A, *prevSlow = NULL, *fast = A;
    while(fast && fast -> next) {
        prevSlow = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    prevSlow -> next = NULL;
    ListNode *prev = NULL, *curr = slow;
    while(curr) {
        ListNode* next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    while(prev && A) {
        if(prev -> val != A -> val) {
            return 0;
        }
        prev = prev -> next;
        A = A -> next;
    }
    return 1;
}

