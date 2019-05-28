/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int maxLength(ListNode *start, ListNode *end) {
    int cnt = 0;
    while(start && end && (start -> val == end -> val)) {
        start = start -> next;
        end = end -> next;
        // cout << start -> val << " " << end -> val << " " << cnt << " )";
        cnt++;
    }
    return cnt;
} 
 
int Solution::solve(ListNode* A) {
    int maxLen = 0;
    ListNode *prev = NULL, *curr = A;
    while(curr) {
        ListNode *next = curr -> next;
        curr -> next = prev;
        int cnt = 0;
        maxLen = max(maxLen, 2 * maxLength(prev, next) + 1);
        maxLen = max(maxLen, 2 * maxLength(curr, next));
        prev = curr;
        curr = next;
    }
    return maxLen;
}

