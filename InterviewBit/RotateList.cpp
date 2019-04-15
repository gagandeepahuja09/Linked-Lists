/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode *head = A, *prev = NULL;
    if(!A || !A -> next)
        return A;
    int sz = 0;
    while(A) {
        A = A -> next;
        sz++;
    }
    A = head;
    B = B % sz;
    if(!B)
        return A;
    B = sz - B;    
    while(A && B--) {
        prev = A;
        A = A -> next;
    }
    prev -> next = NULL;
    ListNode* curr = A;
    while(A -> next) {
        A = A -> next;
    }
    A -> next = head;
    return curr;
}

