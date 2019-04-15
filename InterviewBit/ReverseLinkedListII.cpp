/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    ListNode *prev, *curr = A, *next, *start, *startPrev = NULL, *end, 
    *endNext;
    if(!A)
        return A;
    int i = 0;
    while(i < m) {
        i++;
        if(i == m - 1)
            startPrev =  curr;
        if(i == m)
            start = curr;
        prev = curr;
        curr = curr -> next;
    }
    while(i < n) {
        i++;
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        if(i == n) {
            endNext = curr;
            end = prev;
            start -> next = endNext;
            if(startPrev)
                startPrev -> next = end;
            else
                A = end;
        }
    }
    return A;
}

