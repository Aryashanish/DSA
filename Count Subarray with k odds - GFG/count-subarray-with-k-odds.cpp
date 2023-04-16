//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
    
        int ans = 0;
        int i = 0 , j = 0;
        int noofodd = 0;
        int prefix = 0;
        
        while(j<n){
            if(nums[j]%2 != 0){
                noofodd++;
                prefix = 0;
            }
            
            while(noofodd == k && i<=j){
                if(nums[i]%2 != 0)
                    noofodd--;
                prefix++;
                i++;
            }
            ans += prefix;
            j++;
        }
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
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends