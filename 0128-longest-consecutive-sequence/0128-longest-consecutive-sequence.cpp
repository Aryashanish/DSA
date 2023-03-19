class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums)
            mp[it]++;
        
        int ans = 0 , temp ;
        int i=0;
        int prev;
        for(auto it : mp){
            int val = it.first;
            // cout<<val<<" ";
            if(i++ == 0){
                prev = val;
                temp = 1;
            }
            else{
                if(prev == val-1){
                    temp++; 
                    prev = val;   
                }else{
                    temp = 1;
                    prev = val;
                }
                i++;
            }
            ans = max(ans , temp);
        }
        return ans;
    }
};