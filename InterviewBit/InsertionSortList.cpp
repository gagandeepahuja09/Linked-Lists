/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *temp = A, *Aprev = NULL;
    if(!A || !A -> next)
        return A;
    while(A) {
        ListNode* head = temp;
        ListNode* prev = NULL;    
        while(head != A && head -> val <= A -> val) {
            prev = head;
            head = head -> next;
        }
        if(head == A) {
            Aprev = A;
            A = A -> next;
        } 
        else {
            // Slp case => Change head of LL
            if(!prev)
                temp = A;
            else    
                prev -> next = A;
            Aprev -> next = A -> next;
            A -> next = head;
            A = Aprev -> next;
        }
    }
    return temp;
}

