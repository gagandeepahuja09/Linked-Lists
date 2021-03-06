class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        mp[0] = dummy;
        ListNode* temp = dummy -> next, *prev = dummy;
        int sum = 0;
        while(temp) {
            sum += (temp -> val);
            if(mp.find(sum) != mp.end()) {
                ListNode* sprev = mp[sum];
                ListNode* t = sprev -> next;
                int c = sum;
                while(t && t != temp) {
                    c += (t -> val);
                    mp.erase(c);
                    t = t -> next;
                }
                sprev -> next = temp -> next;
                if(prev != sprev)
                    prev -> next = NULL;
            }
            else
                mp[sum] = temp;
            prev = temp;
            temp = temp -> next;
        }
        temp = dummy -> next;
        return temp;
    }
};

