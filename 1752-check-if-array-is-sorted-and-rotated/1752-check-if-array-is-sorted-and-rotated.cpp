class Solution {
public:
    bool check(vector<int>& nums) {
        int flus = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1])
                flus++;
        }
        
        if(nums[0] < nums[nums.size()-1])
            flus++;
        
        return (flus <= 1);
    }
};