class Solution {
public:
    int healper(vector<int>& nums , int ind , int p_ind , vector<vector<int>>& dp){
        if(ind == nums.size())
            return 0;
        
        if(dp[ind][p_ind+1] != -1)
            return dp[ind][p_ind+1];
        
        int len = 0;
        len = 0 + healper(nums,ind+1,p_ind,dp);
        if(p_ind == -1 || nums[ind] > nums[p_ind])
            len = max(len , 1+healper(nums,ind+1,ind,dp));
        
        return dp[ind][p_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        // return healper(nums,0,-1,dp);
        
        //Binary Search Method
        int len = 1;
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind = lower_bound(temp.begin() , temp.end() , nums[i])-temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};