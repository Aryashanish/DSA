class Solution {
public:
    int nCr(int n, int r , vector<vector<int>>& dp){
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;
        
        if(dp[n][r] != -1)
            return dp[n][r];
        
        return dp[n][r] = nCr(n - 1, r - 1,dp) + nCr(n - 1, r,dp);
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1 , vector<int> (rowIndex+1 , -1));
        vector<int> ans ;
        for(int i=0; i<=rowIndex; i++){
            int temp = nCr(rowIndex,i,dp);
            ans.push_back(temp);
        }
        return ans;
    }
};