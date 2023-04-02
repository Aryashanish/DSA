class Solution {
public:
    int healper(vector<int> nums , int n){
        int s = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%n == 0)
                s += nums[i]/n;
            else{
                int t = nums[i]/n+1;
                s += t;
            }
        }
        return s;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = nums[0];
        for(int i=1; i<nums.size(); i++)
            maxi = max(maxi , nums[i]);
        
        int i=1 , j=maxi;
        int mid;
        int ans = threshold;
        
        while(i<=j){
            mid = j+(i-j)/2;
            int divSum = healper(nums,mid);
            // cout<<mid<<" "<<divSum<<endl;
            if(divSum <= threshold){
                ans = mid;
                j = mid-1;
            }else if(divSum > threshold)
                i = mid+1;
        }
        
        return ans;
    }
};