//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void healper(vector<vector<int>>& ans , vector<int>& t ,int k , int sum , int i , vector<int>& v){
        if(sum == 0 && t.size() == k){
            ans.push_back(t);
            return;
        }
        if(i == v.size())
            return;
        
        healper(ans , t ,k , sum , i+1 , v);
        if(sum - v[i] >= 0){
            t.push_back(v[i]);
            healper(ans , t ,k, sum-v[i] , i+1 , v);
            t.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
        vector<int> v(9);
        for(int i=0; i<9; i++)
            v[i] = i+1;
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        healper(ans , temp ,k , n , 0 , v);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends