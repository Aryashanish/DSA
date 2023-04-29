class Solution {
public:
    void healper(vector<vector<int>> &ans , vector<int> temp , int i , vector<int> &nums){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        healper(ans,temp,i+1,nums);
        temp.push_back(nums[i]);
        healper(ans,temp,i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        healper(ans , t , 0 , nums);
        
        return ans;
    }
};