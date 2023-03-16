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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int , int> mp;
        int n = inorder.size()-1;
        
        for(int i=0; i<=n; i++)
            mp[inorder[i]] = i;
    
        // TreeNode *root = healper(inorder , 0 , n-1 , postorder , 0 , n-1 , mp);
        TreeNode *root = constructtree(mp , inorder , 0 , inorder.size()-1 , postorder , postorder.size()-1 , 0);
        return root;
    }
//     TreeNode* healper(vector<int> in , int is , int ie , vector<int> post , int ps , int pe, unordered_map<int , int> mp){
        
//         if(ps > pe || is > ie)
//             return NULL;
        
//         TreeNode* root = new TreeNode(post[pe]);
//         int iroot = mp[root->val];
//         int numleft = iroot - is;
        
//         root->left = healper(in , is , iroot-1 , post , ps , ps+numleft-1 , mp);
//         root->right = healper(in , iroot+1 , ie , post , ps+numleft , pe-1 , mp);
        
//         return root;
//     }
    
    TreeNode* constructtree(unordered_map<int,int> &mp,vector<int> &inorder,int instart,int inend,vector<int> &postorder,int poststart,int postend){
        
        if(instart>inend || postend>poststart) return NULL;
        
        TreeNode* root=new TreeNode(postorder[poststart]);
        
        int posrootin=mp[postorder[poststart]];
        int remnums=inend-posrootin;
        
        
        root->left=constructtree(mp,inorder,instart,posrootin-1,postorder,poststart-remnums-1,postend);
        root->right=constructtree(mp,inorder,instart+1,inend,postorder,poststart-1,poststart-remnums);
        
        return root;
    }
};