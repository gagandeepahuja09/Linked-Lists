//head is the head of the linked list, n is number of elements to be reversed
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/

node* kReverse(node*head,int n)
{
    if(!head)
        return head;
    node *curr = head, *prev = NULL;
    int k = n;
    while(curr && k--) {
        node *next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head -> next = kReverse(curr, n);
    return prev;        
}

