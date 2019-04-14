/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    ListNode* remaining = head -> next -> next;
    ListNode* newHead = head -> next;
    newHead -> next = head;
    head -> next = swapPairs(remaining);
    return newHead;
}

