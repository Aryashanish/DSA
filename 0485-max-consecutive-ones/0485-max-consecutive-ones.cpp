class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0;
        int i=0 , tcnt;
        while(i<n){
            if(nums[i] == 1){
                tcnt = 0;
                while(i<n && nums[i++] == 1)
                    tcnt++;
                cnt = max(cnt,tcnt);
            }else
                i++;
        }
        return cnt;
    }
};