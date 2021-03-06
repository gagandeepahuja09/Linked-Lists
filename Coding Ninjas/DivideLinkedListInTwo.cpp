/*************
 Following is the Node structure already written.

 template <typename T>
 class Node {
	public:
	T data;
	Node* next;
 
	Node(T data) {
     next = NULL;
     this->data = data;
	}
 
	~Node() {
 if (next != NULL) {
 delete next;
 }
	}
 };
 
*************/

/*
    Divide linked list in two
Send Feedback
Write a function that takes one list and divides up its nodes to create two smaller lists A and B. The sub lists should be made from alternating elements in the original list.
Nodes should be in the reverse order of which they occurred in the source list.
Print both linked lists in different lines.
Input format :

Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :

Line 1 : Output Linked List 1 elements (separated by space)
Line 2 : Output Linked List 2 elements (separated by space)

Constraints :
1 <= n <= 10^4
Sample Input :

 8 2 5 9 1 4 3 7 -1

Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 8.
Sample Output :

 3 1 5 8
 7 4 9 2

*/


void AlternatingSplit(Node<int>* head) {
	Node<int> *oddHead = NULL, *evenHead = NULL;
    int k = 0;
    while(head) {
        Node<int>* nxt = head -> next;
        if(k % 2 == 0) {
            if(!evenHead) {
                evenHead = head;
                evenHead -> next = NULL;
            }
            else {
                Node<int>* temp = head;
                temp -> next = evenHead;
                evenHead = temp;
            }
        }
        else {
            if(!oddHead) {
                oddHead = head;
                oddHead -> next = NULL;
            }
            else {
                Node<int>* temp = head;
                temp -> next = oddHead;
                oddHead = temp;
            }    
        }
        head = nxt;
        k++;
    }
    while(evenHead) {
        cout << evenHead -> data << " ";
        evenHead = evenHead -> next;
    }
    cout << endl;
    
    while(oddHead) {
        cout << oddHead -> data << " ";
        oddHead = oddHead -> next;
    }
}

