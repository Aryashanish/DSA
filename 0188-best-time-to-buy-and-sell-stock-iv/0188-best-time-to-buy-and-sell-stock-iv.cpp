class Solution {
public:
    int healper(vector<int>& p , int i , int buy ,int cap , vector<vector<vector<int>>>& dp){
        if(i == p.size() || cap == 0)
            return 0;
        
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        
        int profit = 0;
        if(buy){
            profit = max(-p[i] + healper(p,i+1,0,cap,dp) , 
                            0  + healper(p,i+1,1,cap,dp));
        }else
            profit = max(p[i] + healper(p,i+1,1,cap-1,dp) , 
                            0  + healper(p,i+1,0,cap,dp));
        
        return dp[i][buy][cap] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2, vector<int>(k+1,-1)));
        return healper(prices,0,1,k,dp);
    }
};