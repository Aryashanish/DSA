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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
    	if(root == NULL)
    	    return result;
    	    
    	queue<TreeNode*> q;
    	q.push(root);
    	bool lefttoright = true;
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> temp(size);
    	    
    	    //Level Process
    	    for(int i=0; i<size; i++){
    	        TreeNode* frontNode = q.front();
    	        q.pop();
    	        
    	        //Normal or Reverse Insertion
    	        int index = lefttoright ? i : size-i-1;
    	        temp[index] = frontNode->val;
    	        
    	        if(frontNode->left)
    	            q.push(frontNode->left);
    	           
    	        if(frontNode->right)
    	            q.push(frontNode->right);
    	    }
    	    //direction change
    	    lefttoright = !lefttoright;
    	    
    	    result.push_back(temp);
    	}
    	return result;
    }
};