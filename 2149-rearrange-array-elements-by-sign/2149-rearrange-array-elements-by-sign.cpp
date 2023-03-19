class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<n;i++){
            if(nums[i]>=0) 
                pos.push_back(nums[i]);
            else 
                neg.push_back(nums[i]);
        }
        
        vector<int> ans;
        
        if(pos.size() != 0 && neg.size() != 0){
            int i = 1 , j = 0;
            bool flag = 1;
            ans.push_back(pos[0]);
            while(i<pos.size() && j<neg.size()){
                if(flag){
                    ans.push_back(neg[j++]);
                    flag = !flag;
                }else{
                    ans.push_back(pos[i++]);
                    flag = !flag;
                }
            }
            
            while(i<pos.size())
                ans.push_back(pos[i++]);
            while(j<pos.size())
                ans.push_back(neg[j++]);
        }
        return ans;
    }
};