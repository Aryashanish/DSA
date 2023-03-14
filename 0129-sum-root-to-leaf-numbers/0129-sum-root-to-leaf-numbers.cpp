/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        string str = "";
        int sum = 0;
        healper(root , str , sum);
        return sum;
    }
    
    void healper(TreeNode* root , string str , int &sum){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            str += to_string(root->val);
            sum += stoi(str);
            return;
        }
        
        healper(root->left , str+to_string(root->val) , sum);
        healper(root->right , str+to_string(root->val) , sum);
    }
};