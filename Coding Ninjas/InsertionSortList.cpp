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

node* insertion_sort_LinkedList_itr(node* head) {
    node *ret = new node(0);
    while(head) {
        node* it = ret;
        while(it -> next && it -> next -> data < head -> data) {
            it = it -> next;
        }
        node* next = head -> next;
        head -> next = it -> next;
        it -> next = head;
        head = next;
    }
    return ret -> next;
}

