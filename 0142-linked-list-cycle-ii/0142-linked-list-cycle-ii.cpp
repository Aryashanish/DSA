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
        
        do{
            slow = slow->next;
            if(fast->next != NULL)
                fast = fast->next->next;
        }while(fast && fast->next && fast != slow);

        if(slow == fast){
            ListNode* t = head;
            while(t != slow){
                t = t->next;
                slow = slow->next;
            }
            
            if(slow == t)
                return t;
        }
        
        return NULL;
    }
};