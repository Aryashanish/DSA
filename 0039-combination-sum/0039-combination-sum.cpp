class Solution {
public:
    void healper(vector<vector<int>>&ans , vector<int> &A , int sum , int i, vector<int> &v){
        if(sum == 0)
            ans.push_back(v);
        
        if(i == A.size())
            return;
        
        while(i < A.size() && sum-A[i] >= 0){
            v.push_back(A[i]);
            healper(ans , A , sum-A[i] , i , v);
            i++;
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        healper(ans , candidates , target , 0 , temp);
        
        return ans;
    }
};