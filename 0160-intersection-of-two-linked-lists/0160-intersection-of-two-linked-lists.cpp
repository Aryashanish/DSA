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
    ListNode * comp(ListNode* p , ListNode* q){
        while(p && q){
            if(p == q)
                return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0;
        int l2 = 0;
        ListNode* p = headA;
        while(p){
            l1++;
            p = p->next;
        }
        
        p = headB;
        while(p){
            l2++;
            p = p->next;
        }
        
        int diff = abs(l1 - l2);
        if(l1 > l2){
            p = headA;
            while(diff){
                p = p->next;
                diff--;
            }
            
            return comp(p , headB);
        }else{
            p = headB;
            while(diff){
                p = p->next;
                diff--;
            }
            
            return comp(headA , p);
        }
        
        return NULL;
    }
};