class Solution {
public:
    int lcs(string &s1 , string &s2 , int i , int j , vector<vector<int>>& dp){
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + lcs(s1,s2,i-1,j-1,dp);
            
        int f1 = lcs(s1,s2,i-1,j,dp);
        int f2 = lcs(s1,s2,i,j-1,dp);
        
        return dp[i][j] = max(f1,f2);
    }
    
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        
        string str = s;
        reverse(s.begin() , s.end());
        
        int lps = lcs(s,str,n-1,n-1,dp);
        return (n-lps);
    }
};