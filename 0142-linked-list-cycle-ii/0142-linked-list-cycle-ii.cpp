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
        if(head == NULL || head->next == NULL) 
            return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        map<ListNode* , int> mp;
        
        do{
            mp[slow]++; 
            slow = slow->next;
            if(fast->next != NULL)
                fast = fast->next->next;
        }while(fast && fast->next && mp[slow] < 2);

        if(mp[slow] >= 2)
            return slow;
        
        return NULL;
    }
};