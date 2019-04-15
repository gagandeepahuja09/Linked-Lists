/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead -> next = A;
    ListNode *prev = dummyHead, *head = A;
    while(A) {
        while(A -> next && A -> val == A -> next -> val)
            A = A -> next;
        if(prev -> next == A)
            prev = prev -> next;
        else 
            prev -> next = A -> next;
        A -> next;    
    }
    return dummyHead -> next;
}

