/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* curr = A;
    while(curr) {
        RandomListNode* temp = new RandomListNode(curr -> label);
        temp -> next = curr -> next;
        curr -> next = temp;
        curr = curr -> next -> next;
    }
    curr = A;
    while(curr) {
        if(curr -> next) {
            if(curr -> random)
                curr -> next -> random = curr -> random -> next;
            curr = curr -> next -> next;    
        }
        else
            curr = curr -> next;
    }
    RandomListNode* copy = A -> next;
    curr = A -> next;
    while(curr) {
        if(curr -> next)
            curr -> next = curr -> next -> next;
        curr = curr -> next;
    }
    return copy;
}

