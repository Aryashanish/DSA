class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0 , j=0;
        map<int , int> mp;
        while(j<n){
            if(mp[nums[j]] == 0)
                mp[nums[j]]++;
            else{
                // cout<<mp[nums[j]]<<" "<<j<<endl;
                return true;
            }
            if(j-i < k){
                j++;
            }else if(j-i == k){
                mp[nums[i]]--;
                i++;
                j++;
            }
        }
        return false;
    }
};