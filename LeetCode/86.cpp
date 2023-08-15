/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public: 
    ListNode* partition(ListNode* head, int x) {
        // Key thing: first head are declared 
        // Tail and head point to the same node
        // Then where tail is pointing keeps on changing
        // This also changes where head is pointing
        // Then tail changes which doesn't change head. 

        // We also keep a new ListNode which simplifies a lot of things
        // During implementation
        ListNode *lessHead = new ListNode(0);
        ListNode *grtHead = new ListNode(0); 
        ListNode *lessTail = lessHead;
        ListNode *grtTail = grtHead;
        while (head != NULL) {
            if (head -> val < x) {
                lessTail -> next = head;
                lessTail = lessTail -> next;
            } else {
                grtTail -> next = head;
                grtTail = grtTail -> next;
            }
            head = head -> next;
        }
        lessTail -> next = grtHead -> next;
        grtTail -> next = NULL;
        return lessHead -> next;
    }
};
