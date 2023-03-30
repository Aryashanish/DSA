//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int healper(vector<int>& v , int mid){
        
        int s = 0;
        for(int i=0; i<v.size(); i++)
            s += (v[i]/mid) + ((v[i]%mid) != 0);
        
        return s;
    }
    int Solve(int N, vector<int>& piles, int h) {
        // Code here
        int maxi = piles[0];
        for(int i=1; i<piles.size(); i++){
            maxi = max(maxi , piles[i]);
        }
        
        int i=1 , j=maxi;
        int ans = 0;
        while(i<=j){
            int mid = i+(j-i)/2;
            
            if(healper(piles,mid) <= h){
                ans = mid;
                j = mid-1;
            }else if(healper(piles,mid) > h)
                i  = mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends