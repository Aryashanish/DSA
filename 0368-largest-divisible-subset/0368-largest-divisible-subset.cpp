class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
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