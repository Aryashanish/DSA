class Solution {
public:
    map<int,int> mp;
    int healper(vector<int>& num1 , vector<int>& num2 , int i , int j , vector<vector<int>>& dp){
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(num1[i] == num2[j])
            return dp[i][j] = (1 + healper(num1,num2,i-1,j-1,dp));
        
        int a = healper(num1,num2,i-1,j,dp);
        int b = healper(num1,num2,i,j-1,dp);
        return dp[i][j] = max(a,b);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp (n , vector<int>(m , -1));
        return healper(nums1,nums2,n-1,m-1,dp);
    }
};