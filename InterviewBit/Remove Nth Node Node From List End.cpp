/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // if(A && A -> next == NULL && B == 1)
     //   return NULL;
    ListNode *curr = A, *prev = NULL, *temp = A;
    while(curr && B--) {
        curr = curr -> next;
    }
    if(!curr)
        return A -> next;
    while(curr) {
        curr = curr -> next;
        prev = A;
        A = A -> next;
    }
    if(prev) {
        prev -> next = A -> next;
        return temp;
    }
    return A -> next;
}

