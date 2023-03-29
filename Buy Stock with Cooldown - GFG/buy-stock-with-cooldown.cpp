//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long healper(vector<long long>& p , int i , int buy , vector<vector<long long>>& dp){
        if(i >= p.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int profit = 0;
        if(buy){
            profit = max(-p[i] + healper(p,i+1,0,dp) , 
                            0  + healper(p,i+1,1,dp));
        }else
            profit = max(p[i] + healper(p,i+2,1,dp) , 
                            0  + healper(p,i+1,0,dp));
        
        return dp[i][buy] = profit;
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n+1 , vector<long long>(2,-1));
        return healper(prices,0,1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends