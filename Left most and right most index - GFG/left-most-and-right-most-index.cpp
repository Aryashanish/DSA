//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int foccur(vector<long long> nums, long long target){
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
    
    int loccur(vector<long long> nums, long long target){
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
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        int fo = foccur(v,x);
        int lo = loccur(v,x);
        return {fo,lo};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends