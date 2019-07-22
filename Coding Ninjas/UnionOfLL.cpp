#include<bits/stdc++.h>
using namespace std;

/*class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};
*/
ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
{
    ListNode<int>* temp = head1;
    ListNode<int>* ret = new ListNode<int>(0);
    ListNode<int>* curr = ret;
    unordered_map<int, int> mp;
    while(temp) {
        curr -> next = temp;
        curr = curr -> next;
        mp[temp -> data]++;
        temp = temp -> next;
    }
    temp = head2;
    while(temp) {
        if(mp[temp -> data]) {
            mp[temp -> data]--;
        }
        else {
            curr -> next = temp;
            curr = curr -> next;
        }
        temp = temp -> next;
    }
    curr -> next = NULL;
    return ret -> next;
}

