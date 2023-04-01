//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&nums) {
        // Code here

        vector<int> dp(n , 1) , count(n,1);
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i] && 1+dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if(nums[j] <= nums[i] && 1+dp[j] == dp[i]){
                    count[i] += count[j];
                }
            }
            maxi = max(maxi , dp[i]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi)
                ans += count[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends