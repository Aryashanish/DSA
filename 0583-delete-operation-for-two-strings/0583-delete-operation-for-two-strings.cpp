class Solution {
public:
    int healper(string &s1 , string &s2 , int i , int j , vector<vector<int>>& dp){
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + healper(s1,s2,i-1,j-1,dp);
            
        int f1 = healper(s1,s2,i-1,j,dp);
        int f2 = healper(s1,s2,i,j-1,dp);
        
        return dp[i][j] = max(f1,f2);
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));
        
        int lcs = healper(word1,word2,n-1,m-1,dp);
        
        int ans = n+m-2*lcs;
        return ans;
    }
};