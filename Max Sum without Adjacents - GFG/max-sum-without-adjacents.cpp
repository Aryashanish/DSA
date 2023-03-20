//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int healper(int *arr , int n , vector<int>& dp){
        if(n<0)
            return 0;
        if(n==0)
            return arr[n];
            
        if(dp[n] != -1)
            return dp[n];
        
        int taken = arr[n] + healper(arr,n-2,dp);
        int nottaken = 0 + healper(arr,n-1,dp);
        
        return dp[n] = max(taken,nottaken);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n , -1);
	    return healper(arr,n-1,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends