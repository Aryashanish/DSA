class Solution {
public:
    int healper(string &s1 , string &s2 , int i , int j , vector<vector<int>>& dp){
        if(i<0)
            return 1+j;
        
        if(j<0)
            return 1+i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = healper(s1,s2,i-1,j-1,dp);
        
        int a = 1 + healper(s1,s2,i,j-1,dp);
        int b = 1 + healper(s1,s2,i-1,j,dp);
        int c = 1 + healper(s1,s2,i-1,j-1,dp);
        
        return dp[i][j] = min(a,min(b,c));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n , vector<int>(m,-1));
        return healper(word1,word2,n-1,m-1,dp);
    }
};