/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int healper(Node* root){
        if(root == NULL)
            return 0;
        
        int x = 0;
        for(auto it : root->children){
            x = max(x , 1 + healper(it));
        }
        
        return x;
    }
    
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        return 1+healper(root);
    }
};