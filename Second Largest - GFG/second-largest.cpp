//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int lar = arr[0];
	    int slar = -1;
	    
	    for(int i=0; i<n; i++){
	        if(arr[i] > lar){
	            slar = lar;
	            lar = arr[i];
	        }else if(slar < arr[i] && lar > arr[i])
	            slar = arr[i];
	    }
	    
	    return slar;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends