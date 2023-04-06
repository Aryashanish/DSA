class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mp;
        int sum = 0 , ans = INT_MIN;
        int i = 0 , j = 0;
        
        while(j<nums.size()){
            if(mp[nums[j]] == 1){
                ans = max(ans , sum);
                while(i<j && nums[i] != nums[j]){
                    mp[nums[i]]--;
                    sum -= nums[i];
                    i++;
                }
                sum -= nums[i];
                i++;
                sum += nums[j];
            }else{
                sum += nums[j];
                mp[nums[j]]++;
            }
            j++;
        }
        ans = max(ans , sum);
        return ans;
    }
};