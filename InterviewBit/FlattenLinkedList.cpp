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
