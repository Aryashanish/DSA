//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        if(n<7)
            return n;
            
        vector<int> v;
        int t = n;
        while(t>0){
            v.push_back(t%2);
            t = t/2;
        }
        
        reverse(v.begin() , v.end());
            
        for(int i=1; i<v.size()-1; i++){
            if(v[i]){
                if(v[i-1] && v[i+1])
                    v[i+1] = 0;
            }
        }
        
        int ans = 0;
        int s = v.size()-1;
        for(int i=s; i>=0; i--){
            if(v[i]){
                ans += pow(2,s-i);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends