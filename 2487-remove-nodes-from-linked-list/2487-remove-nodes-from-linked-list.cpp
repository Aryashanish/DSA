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
    ListNode* reverse(ListNode* tmp){
         ListNode *prev=NULL,*nxt=tmp;
         while(tmp)
          {
            nxt=tmp->next;
            tmp->next=prev;
            prev=tmp;
            tmp=nxt;
          }
        
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* tmp = head;
        ListNode* newList = new ListNode(0);
        ListNode* ans = newList;
        
        tmp = reverse(head);
        int mx = tmp->val;
        while(tmp){
            mx = max(mx , tmp->val);
            
            if(tmp->val >= mx){
                ListNode* node = new ListNode(tmp->val);
                newList->next = node;
                newList = newList->next;
            }
            tmp = tmp->next;
        }
        
        tmp = reverse(ans->next);
        return tmp;
    }
};