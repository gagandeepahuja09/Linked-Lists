/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int la = 0, lb = 0;
    ListNode *ha = A, *hb = B;
    if(!A || !B)
        return NULL;
    while(A -> next) {
        A  = A -> next;
        la++;
    }
    while(B -> next) {
        B  = B -> next;
        lb++;
    }
    int mov = abs(la - lb);
    if(la > lb) {
        while(mov-- && ha) {
            ha = ha -> next;
        }
    }
    else {
        while(mov-- && hb) {
            hb = hb -> next;
        }
    }
    while(ha && hb) {
        if(ha == hb)
            return ha;
        ha = ha -> next;
        hb = hb -> next;
    }
    return hb;
}

