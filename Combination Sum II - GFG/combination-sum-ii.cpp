//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void healper(vector<vector<int>>& ans , vector<int>& t , int sum , int i , vector<int>& v){
        if(sum == 0){
            ans.push_back(t);
            return;
        }
        if(i == v.size())
            return;
        
        int c = 0;
        for(int j=i; j<v.size(); j++){
            
            if(sum - v[j] >= 0){
                if(v[j] != c){
                    c = v[j];
                    t.push_back(v[j]);
                    healper(ans , t , sum-v[j] ,j+1 , v);
                    t.pop_back();
                }
            }
            else 
                return;
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        healper(ans , temp , target , 0 , candidates);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends