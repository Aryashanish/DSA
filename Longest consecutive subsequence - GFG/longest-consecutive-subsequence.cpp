//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        map<int,int> mp;
        for(int i=0; i<N; i++)
            mp[arr[i]]++;
        
        int ans = 0 , temp ;
        int i=0;
        int prev;
        for(auto it : mp){
            int val = it.first;
            // cout<<val<<" ";
            if(i++ == 0){
                prev = val;
                temp = 1;
            }
            else{
                if(prev == val-1){
                    temp++; 
                    prev = val;   
                }else{
                    temp = 1;
                    prev = val;
                }
                i++;
            }
            ans = max(ans , temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends