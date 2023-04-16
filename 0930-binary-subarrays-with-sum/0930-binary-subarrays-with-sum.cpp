class Solution {
public:
    int healper(vector<int>& nums , int goal){
        if(goal < 0)
            return 0;
        
        int n = nums.size();
        int i = 0 , j = 0 , sum =0;
        int ans = 0;
        while(j<n){
            sum += nums[j];
            while(sum > goal){
                sum -= nums[i];
                i++;
            }
            
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (healper(nums,goal)-healper(nums,goal-1));
    }
};