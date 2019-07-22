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

node* skipMdeleteN(node  *head, int M, int N) {
    node *temp = head, *prev = NULL;
    while(temp) {
        int k = M;
        while(temp && k--) {
            prev = temp;
            temp = temp -> next;
        }
        k = N;
        node* del = NULL;
        while(temp && k--) {
            del = temp;
            temp = temp -> next;
            delete(del);
        }
        if(prev)
            prev -> next = temp;
    }
    return head;
}

