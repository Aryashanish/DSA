class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0 , j=0;
        int sum = 0;
        double ans = INT_MIN;
        while(j<n){
            sum += nums[j];
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                double avg = (double)sum/k;
                ans = max(ans , avg);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};