//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    // int prevOne = -1;
    // long long ans = 0;
    // int j;
    // for(int i=0; i<n; i++){
    //     if(arr[i] == 1){
        
    //         if(prevOne == -1)
    //             j = i-0;
    //         else
    //             j = i-prevOne-1;
                
    //         long long temp = (j*(j+1))/2;
    //         ans += temp;
            
    //         prevOne = i;
    //     }
    // }
    
    // if(prevOne == -1 && n != 1)
    //     j = n;
    // else
    //     j = n-prevOne-1;
        
    // long long temp = (j*(j+1))/2;
    // ans += temp;
    
    // return ans;
    
        long ans=0;
        long cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cnt++;
            }else{
                ans=ans+(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        if(cnt!=0){
            ans=ans+(cnt*(cnt+1))/2;
        }
        return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends