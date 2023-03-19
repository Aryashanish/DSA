class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum = 0 , ans = 0;
        mp[sum] = 1;
        
        for(auto it : nums){
            sum += it;
            int f = sum - k;
            if(mp.find(f) != mp.end())
                ans += mp[f];
            mp[sum]++;
        }
        
        return ans;
    }
};