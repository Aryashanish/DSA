class Solution {
public:
    void healper(set<vector<int>> &ans , vector<int> temp , int i , vector<int> &nums){
        if(i == nums.size()){
            sort(temp.begin() , temp.end());
            if(ans.find(temp) == ans.end())
                ans.insert(temp);
            return;
        }
        
        healper(ans,temp,i+1,nums);
        temp.push_back(nums[i]);
        healper(ans,temp,i+1,nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> t;
        
        healper(ans , t , 0 , nums);
        
        vector<vector<int>> res; 
        for(auto it : ans)
            res.push_back(it);
        
        return res;
    }
};