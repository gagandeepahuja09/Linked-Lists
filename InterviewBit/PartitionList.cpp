/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *lesser = NULL, *greater = NULL, *head = NULL, *temp = NULL;
    while(A) {
        if(A -> val < B) {
            if(!lesser) {
                lesser = A;
                head = lesser;
            }
            else {
                lesser -> next = A;
                lesser = lesser -> next;
            }
        }
        else {
            if(!greater) {
                greater = A;
                temp = greater;
            }
            else {
                greater -> next = A;
                greater = greater -> next;
            }
        }
        A = A -> next;
    }
    if(greater)
        greater -> next = NULL;
    if(!lesser)
        return temp;
    lesser -> next = temp;
    return head;
}

