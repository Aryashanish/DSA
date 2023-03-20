//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int healper(vector<int>& height, int n , vector<int>& dp){
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
            
        int onestep = healper(height,n-1,dp) + abs(height[n]-height[n-1]);
        int twostep = 1e9;
        if(n>1)
            twostep = healper(height,n-2,dp) + abs(height[n]-height[n-2]);
        
        return dp[n] = min(onestep , twostep);
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1 , -1);
        return healper(height , n-1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends