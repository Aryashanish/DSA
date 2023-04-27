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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* oddstr = head;
        ListNode* evenstr = head->next;
        
        ListNode* p = evenstr->next;
        ListNode* oddend = oddstr;
        ListNode* evenend = evenstr;
        int i = 3;
        while(p){
            if(i%2 != 0){
                oddend->next = p;
                oddend = p;
            }
            if(i%2 == 0){
                evenend->next = p;
                evenend = p;
            }
            p = p->next;
            i++;
        }
        
        oddend->next = evenstr;
        evenend->next = NULL;
        return head;
    }
};