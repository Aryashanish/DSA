class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        long long int i=0 , j=0 , sum=0 , avg=0;
        int ws = 2*k+1;
        
        if(n < ws)
            return ans;
        if(k == 0)
            return nums;
        
        while(j<n){
            sum += nums[j];
            if(j-i+1 < ws)
                j++;
            else if(j-i+1 == ws){
                avg = sum/ws;
                ans[j-k] = avg;
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};