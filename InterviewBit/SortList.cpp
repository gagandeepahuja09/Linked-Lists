/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* mergeList(ListNode* l, ListNode* r) {
    ListNode* temp = NULL, *head = NULL;
    while(l && r) {
        if(l -> val <= r -> val) {
            if(!temp) {
                temp = l;
                head = l;
            }
            else {
                temp -> next = l;
                temp = temp -> next;
            }
            l = l -> next;
        }
        else {
            if(!temp) {
                temp = r;
                head = r;
            }
            else {
                temp -> next = r;
                temp = temp -> next;
            }
            r = r -> next;
        }    
    }
    if(r)
        temp -> next = r;
    if(l)
        temp -> next = l;
    return head;
}
 
ListNode* Solution::sortList(ListNode* A) {
    if(!A || !A -> next)
        return A;
    ListNode *slow = A, *fast = A, *prev = NULL;
    while(fast && fast -> next) {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(prev)
        prev -> next = NULL;
    ListNode* l = sortList(A);
    ListNode* r = sortList(slow);
    return mergeList(l, r);
}

