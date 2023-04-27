//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeros = NULL;
        Node* ones = NULL;
        Node* twos = NULL;
        Node* zeroe = NULL;
        Node* onee = NULL;
        Node* twoe = NULL;
        
        Node* p = head;
        while(p){
            if(p->data == 0){
                if(zeros == NULL){
                    zeros = p;
                    zeroe = p;
                }else{
                    zeroe->next = p;
                    zeroe = p;
                }
            }
            else if(p->data == 1){
                if(ones == NULL){
                    ones = p;
                    onee = p;
                }else{
                    onee->next = p;
                    onee = p;
                }
            }
            else if(p->data == 2){
                if(twos == NULL){
                    twos = p;
                    twoe = p;
                }else{
                    twoe->next = p;
                    twoe = p;
                }
            }
            
            p = p->next;
        }
        
        
        if(zeros && ones && twos){
            zeroe->next = ones;
            onee->next = twos;
            twoe->next = NULL;
            return zeros;
        }
        else if(zeros && ones){
            zeroe->next = ones;
            onee->next = NULL;
            return zeros;
        }
        else if(zeros && twos){
            zeroe->next = twos;
            twoe->next = NULL;
            return zeros;
        }
        else if(ones && twos){
            onee->next = twos;
            twoe->next = NULL;
            return ones;
        }else if(ones && !twos && !zeros){
            return ones;
        }else if(twos && !ones && !zeros){
            return twos;
        }else if(zeros && !ones && !twos){
            return zeros;
        }
        
        return NULL;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends