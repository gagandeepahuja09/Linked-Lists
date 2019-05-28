/*

Flatten a linked list

Given a linked list where every node represents a linked list and contains two pointers of its type:

    Pointer to next node in the main list (right pointer)
    Pointer to a linked list where this node is head (down pointer). All linked lists are sorted.

You are asked to flatten the linked list into a single list. Use down pointer to link nodes of the flattened list. The flattened linked list should also be sorted.


Input Format

The only argument given is head pointer of the doubly linked list.

Output Format

Return the head pointer of the Flattened list. 

Constraints

1 <= Total nodes in the list <= 100000
1 <= Value of node <= 10^9

For Example

Input 1:
       3 -> 4 -> 20 -> 20 ->30
       |    |    |     |    |
       7    11   22    20   31
       |               |    |
       7               28   39
       |               |
       8               39

Output 1:
3 -> 4 -> 7 -> 7 -> 8 -> 11 -> 20 -> 20 -> 20 -> 22 -> 28 -> 30 -> 31 -> 39 -> 39 

*/
/*
struct ListNode {
    int val;
    ListNode *right,*down;
    ListNode(int x) {
        val = x;
        right = down = NULL;
    }
};
*/

ListNode* merge(ListNode* a, ListNode* b) {
    ListNode *head;
    if(a -> val < b -> val) {
        head = a;
        a = a -> down;
    }
    else {
        head = b;
        b = b -> down;
    }
    ListNode *p = head;
    while(a && b) {
        if(a -> val < b -> val) {
            p -> down = a;
            p = p -> down;
            a = a -> down;
        }
        else {
            p -> down = b;
            p = p -> down;
            b = b -> down;
        }
    }
    if(a)
        p -> down = a;
    else
        p -> down = b;
    return head;
}


ListNode* flat (ListNode* root) {
    if(!root || !root -> right)
        return root;
    return merge(root, flat(root -> right));
}

ListNode* flatten (ListNode* root) {
    ListNode* res = flat(root);
    ListNode *head = res;
    while(res) {
        if(res -> down)
            res -> right = res -> down;
        res = res -> right;    
    }
    return head;
}
