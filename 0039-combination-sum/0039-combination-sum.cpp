class Solution {
public:
    void healper(vector<vector<int>>& ans , vector<int> t , int sum , int i , vector<int>& v){
        if(sum == 0){
            ans.push_back(t);
            return;
        }
        if(i == v.size())
            return;
        
        healper(ans , t , sum , i+1 , v);
        if(sum - v[i] >= 0){
            t.push_back(v[i]);
            healper(ans , t , sum-v[i] , i , v);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        healper(ans , temp , target , 0 , candidates);
        return ans;
    }
};