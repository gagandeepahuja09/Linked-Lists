/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A)
        return A;
    ListNode *head, *prev = NULL, *curr = A;
    int k = B;
    while(curr && B--) {
        ListNode* next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    A -> next = reverseList(curr, k);
    return prev;
}

