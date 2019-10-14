/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* rev(ListNode* curr) {
    ListNode *prev = NULL;
    while(curr) {
        ListNode *next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
int Solution::lPalin(ListNode* A) {
    ListNode *slow = A, *prev = NULL, *fast = A;
    if(!A || !A -> next)
        return 1;
    while(fast && fast -> next) {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    prev -> next = NULL;
    ListNode* B = rev(slow);    
    while(A && B) {
        if(A -> val != B -> val)
            return 0;
        A = A -> next;
        B = B -> next;
    }
    return 1;
}

