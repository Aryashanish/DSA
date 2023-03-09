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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        map<ListNode*,int> mp;
        ListNode* p = head;
        while(p){
            mp[p]++;
            if(mp[p] > 1)
                return p;
            p = p->next;
        }
        return NULL;
    }
};