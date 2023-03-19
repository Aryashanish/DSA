//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int foccur(vector<int> nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid] == target){
                if(mid-1 >= 0 && nums[mid-1] == target)
                    r = mid - 1;
                else
                    return mid;
            }
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    
    int loccur(vector<int> nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid] == target){
                if(mid+1 < nums.size() && nums[mid+1] == target)
                    l = mid + 1;
                else
                    return mid;
            }
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxone = 0 , ans = -1;
	    for(int i=0; i<n; i++){
	        int fo = foccur(arr[i],1);
	        int lo = loccur(arr[i],1);
	        if(lo != -1 && fo != -1 && lo-fo+1 > maxone){
	            maxone = lo-fo+1;
	            ans = i;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends