class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long ans = 0 , sum = 0;
        for(int i=0;i<nums.size();sum+=nums[i],i++)
            if(nums[i]>ans)ans=max(ans,(long )ceil((double)(sum+nums[i])/(i+1)));
        
        return (int)ans;
    }
};