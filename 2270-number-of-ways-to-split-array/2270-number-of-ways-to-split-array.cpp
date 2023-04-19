class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n) , suf(n);
        
        for(int i=0; i<n; i++){
            if(i == 0)
                pre[i] = nums[i];
            else
                pre[i] = pre[i-1] + nums[i];
        }
        
        for(int i=n-1; i>=0; i--){
            if(i == n-1)
                suf[i] = nums[i];
            else
                suf[i] = suf[i+1] + nums[i];
        }
        
        int i = 0 , j = 1;
        int cnt = 0;
        while(j<n){
            if(pre[i] >= suf[j])
                cnt++;
            i++;
            j++;
        }
        return cnt;
    }
};