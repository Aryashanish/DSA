//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        int i=0 , j=n-1;
        int mid;
        int ans = -1;
        while(i<=j){
            mid = i + (j-i)/2;
            if(v[mid] <= x){
                ans =v[mid];
                i = mid+1;
            }else
                j = mid-1;
        }
        if(ans == -1)
            return -1;
        return ans;
    }
    
int findCeil(vector<long long> v, long long n, long long x){
        
        // Your code here
        int i=0 , j=n-1;
        int mid;
        int ans = -1;
        while(i<=j){
            mid = i + (j-i)/2;
            if(v[mid] >= x){
                ans = v[mid];
                j = mid-1;
            }else
                i = mid+1;
        }
        if(ans == -1)
            return -1;
        return ans;
    }

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    vector<long long> v;
    
    for(int i=0; i<n; i++)
        v.push_back(arr[i]);
        
    sort(v.begin() , v.end());
    
    int a = findFloor(v,n,x);
    int b = findCeil(v,n,x);
    return {a,b};
}