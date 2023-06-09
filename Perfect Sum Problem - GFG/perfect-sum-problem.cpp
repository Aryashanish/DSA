//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	
	int healper(int arr[] , int n , int tar , vector<vector<int>>& dp){
	    if(n == 0){
	        if(tar == 0 && arr[0] == 0)
	            return 2;
	        else if(tar == 0 || arr[0] == tar)
	            return 1;
	        else
	            return 0;
	    }
	    
	    if(dp[n][tar] != -1)
	        return dp[n][tar];
	    
	    int nottake = healper(arr , n-1 , tar , dp);
	    int take = 0;
	    if(tar >= arr[n])
	        take = healper(arr , n-1 , tar-arr[n] , dp);
	        
	    return dp[n][tar] = (take%mod+nottake%mod)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1 , vector<int>(sum+1 , -1));
        return healper(arr , n-1 , sum , dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends