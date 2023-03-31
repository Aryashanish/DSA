//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n , 1) , hash(n , 1);
        sort(arr.begin() , arr.end());
        
        int maxi = -1;
        int lastind = 0;
        
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev<i; prev++){
                if((arr[i]%arr[prev] == 0) && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastind = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(arr[lastind]);
        
        while(hash[lastind] != lastind){
            lastind = hash[lastind];
            ans.push_back(arr[lastind]);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends