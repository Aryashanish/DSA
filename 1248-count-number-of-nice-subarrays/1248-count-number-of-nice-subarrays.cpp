class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i = 0 , j = 0;
        int noofodd = 0;
        int prefix = 0;
        
        while(j<n){
            if(nums[j]%2 != 0){
                noofodd++;
                prefix = 0;
            }
            
            while(noofodd == k && i<=j){
                if(nums[i]%2 != 0)
                    noofodd--;
                prefix++;
                i++;
            }
            ans += prefix;
            j++;
        }
        return ans;
    }
};