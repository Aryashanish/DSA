//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int a = 0;
        int b = 1;
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return 1;
        }
        int c;
        for(int i=2;i<=n;i++)
        {
            c = (a%1000000007+b%1000000007)%1000000007;
            a=b;
            b=c;
        }
        return b;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends