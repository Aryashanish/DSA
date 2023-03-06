class Solution {
public:
    int disNum(vector<int> nums){
        set<int> s;
        for(int i=0; i<nums.size(); i++)
            s.insert(nums[i]);
        return s.size();
    }
    
    int partitionArray(vector<int>& nums, int k) {
        if(k == 0)
            return disNum(nums);
        
        sort(nums.begin() , nums.end());     
        int i = 0 , j = 1 , ans = 0;
        while(j<nums.size()){
            if(abs(nums[i]-nums[j]) < k)
                j++;
            else if(abs(nums[i]-nums[j]) == k){
                ans++;
                while(j+1<nums.size() && nums[j] == nums[j+1])
                    j++;
                j++;
                i = j;
            }else{
                ans++;
                i = j;
            }
        }
        if(ans == 0 && k == 1)
            return disNum(nums);
        
        if(i<nums.size())
            return ans+1;
        return ans;
    }
};