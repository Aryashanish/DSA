class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int mx = arr[n-1];
        vector<bool> temp(mx+1,true); 
        
        for(int i=0; i<n; i++)
            temp[arr[i]] = false;
        
        for(int i=1; i<=mx; i++){
            if(temp[i]){
                k--;
                if(k == 0)
                    return i;
            }
        }
        return arr[n-1]+k;
    }
};