class Solution {
public:
    int binaryS(vector<int>& v , int n , long long s){
        int i = 0 , j = v.size()-1;
        int mid;
        int ans = -1;
        while(i<=j){
            mid = j + (i-j)/2;
            long long t = (long long)v[mid]*n;
            if(t < s)
                i = mid+1;
            else if(t >= s){
                ans = mid;
                j = mid-1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        vector<int> ans;
        sort(potions.begin() , potions.end());
        
        for(int i=0; i<spells.size(); i++){
            int ind = binaryS(potions,spells[i],success);
            if(ind != -1)
                ans.push_back(n-ind);
            else
                ans.push_back(0);
        }
        
        return ans;
    }
};