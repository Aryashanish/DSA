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
    bool ismatch(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL)
            return true;
        if(p != NULL && q != NULL){
            bool ls = ismatch(p->left , q->right);
            bool rs = ismatch(p->right , q->left);
            
            bool isequal = (p->val == q->val);
            
            if(ls && rs && isequal)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return ismatch(root->left , root->right);
    }
};