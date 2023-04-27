//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseList(Node* head) {
        // code here
        Node* p = head;
        Node* q = p->next;
        while (q != NULL) {
            p->next = q->next;
            q->next = head;
            head = q;
            q = p->next;
        }
        return head;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverseList(head);
        Node* q = head;
        Node* p = q;
        int c = 1;
        while(p){
            int s = p->data + c;
            if(s > 9){
                int d = s%10;
                p->data = d;
                c = s/10;
            }else{
                p->data += c;
                c = 0;
            }
            if(p->next)
                p = p->next;
            else
                break;
        }
        
        if(c > 0){
            p->next = new Node(c);
        }
        
        return reverseList(q);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends