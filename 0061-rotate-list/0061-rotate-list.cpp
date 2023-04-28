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
    
    int length(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0)
            return head;
        
        int l = length(head);
        int cnt = l - k%l;
        
        if(l == k || l == cnt)
            return head;
        
        ListNode* p = head;
        ListNode* q = head;
        
        while(cnt > 1){
            cnt--;
            p = p->next;
        }
        
        ListNode* l2 = p->next;
        p->next = NULL;
        p = l2;
        while(p->next != NULL)
            p = p->next;
        
        p->next = q;
        return l2;
    }
};