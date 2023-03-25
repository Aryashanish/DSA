//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int healper(int price[] , int n , int len , vector<vector<int>>& dp){
        if(n == 0){
            return len*price[0];
        }
        
        if(dp[n][len] != -1)
            return dp[n][len];
        
        int nottake = healper(price , n-1 , len,dp);
        int take = INT_MIN;
        if(n+1 <= len)
            take = price[n] + healper(price , n , len-n-1,dp);
        
        return dp[n][len] = max(take,nottake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return healper(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends