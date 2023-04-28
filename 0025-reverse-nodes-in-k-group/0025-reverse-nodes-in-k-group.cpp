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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        
        int cnt = count/k;
        ListNode* p = head;
        temp = head;
        stack<int> st;
        int t = k;
        
        while(temp){
            st.push(temp->val);
            t--;
            
            if(t == 0){
                while(!st.empty()){
                    p->val = st.top();
                    st.pop();
                    p = p->next;
                }
                t = k;
                cnt--;
            }
            
            if(cnt == 0)
                break;
            
            temp = temp->next;
        }
        
        return head;
    }
};