/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* nxt = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        while(p){
            count++;
            p = p->next;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* t = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            t = slow;
            slow = slow->next;
        }
        
        if(count%2 != 0)
            slow = slow->next;
        
        t->next = NULL;
        
        slow = reverseList(slow);
        
        ListNode* rp = slow;
        ListNode* q = head;
        while(rp && q){
            if(rp->val != q->val)
                return false;
            rp = rp->next;
            q = q->next;
        }
        return true;
    }
};