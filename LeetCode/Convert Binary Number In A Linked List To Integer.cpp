/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s;
        while(head) {
            s += (head -> val + '0');
            head = head -> next;
        }
        long long ans = stoll(s, NULL, 2);
        return (int)ans;
    }
};
