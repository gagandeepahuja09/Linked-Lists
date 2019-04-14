/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    int k = B;
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* next = curr -> next;
    while(k-- && curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    if(next)
        A -> next = reverseList(next, B);
    return prev;
}

