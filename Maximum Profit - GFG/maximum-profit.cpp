//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int healper(int p[] , int n , int i , int buy ,int cap , vector<vector<vector<int>>>& dp){
        if(i == n || cap == 0)
            return 0;
        
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        
        int profit = 0;
        if(buy){
            profit = max(-p[i] + healper(p,n,i+1,0,cap,dp) , 
                            0  + healper(p,n,i+1,1,cap,dp));
        }else
            profit = max(p[i] + healper(p,n,i+1,1,cap-1,dp) , 
                            0  + healper(p,n,i+1,0,cap,dp));
        
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(N , vector<vector<int>>(2, vector<int>(K+1,-1)));
        return healper(A,N,0,1,K,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends