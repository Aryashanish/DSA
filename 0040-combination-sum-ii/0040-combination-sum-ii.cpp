class Solution {
public:
    void healper(vector<vector<int>>&ans , vector<int> &A , int sum , int i, vector<int> &v){
        if(sum == 0)
            ans.push_back(v);
        
        if(i == A.size() || sum<0)
            return;
        
        for(int j=i; j<A.size(); j++){
            if(sum - A[j] < 0)
                break;
            
            v.push_back(A[j]);
            healper(ans , A , sum-A[j] , j+1 , v);
            v.pop_back();
            //skip dublicates
            while(j+1<A.size() && A[j] == A[j+1])
                j++;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        healper(ans , candidates , target , 0 , temp);
        
        return ans;
    }
};