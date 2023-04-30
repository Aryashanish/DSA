//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void healper(vector<int> &ans , vector<int> temp , int sum , int i , vector<int> &nums){
        if(i == nums.size()){
            ans.push_back(sum);
            return;
        }
            
        healper(ans,temp,sum,i+1,nums);
        temp.push_back(nums[i]);
        sum += nums[i];
        healper(ans,temp,sum,i+1,nums);
        sum -= temp[temp.size()-1];
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans , t;
        healper(ans , t , 0 , 0 , arr);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends