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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int max_width = 1;
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});
        
        while(!q.empty()){
            int level_size = q.size();
            long long s_ind = q.front().second;
            long long e_ind = q.back().second;
            max_width = max(max_width , (int)(e_ind-s_ind+1));
            
            for(int i=0; i<level_size; i++){
                auto p = q.front();
                TreeNode* node = p.first;
                q.pop();
                long long node_ind = p.second - s_ind;
                
                if(node->left)
                    q.push({node->left , 2*node_ind+1});
                
                if(node->right)
                    q.push({node->right , 2*node_ind+2});
            }
        }
        return max_width;
    }
};