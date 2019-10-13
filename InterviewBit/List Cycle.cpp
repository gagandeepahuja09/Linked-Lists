/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if(!A || !A -> next)
        return NULL;
    ListNode *slow = A, *fast = A;
    slow = slow -> next;
    fast = fast -> next -> next;
    while(fast && fast -> next) {
        if(slow == fast)
            break;
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    if(slow != fast)
        return NULL;
    slow = A;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

