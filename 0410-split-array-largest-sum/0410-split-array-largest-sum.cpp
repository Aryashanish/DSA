class Solution {
public:
    bool isvalid(vector<int>& A , int M, int mid){
        int studentcount=1;
        int sumofpages=0;
        
        for(int i=0;i<A.size();i++){
            if(sumofpages +A[i]<=mid){
                sumofpages+=A[i];
              
            }
            else{
                studentcount++;
                if(studentcount > M || A[i]>mid) return false;
                    sumofpages=A[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& A, int k) {
        int n = A.size();
        
        if(k > n)
            return -1;
            
        int low = A[0];
        int high = 0;
        
        for(int i=0; i<n; i++){
            low = min(low , A[i]);
            high += A[i];
        }
        
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isvalid(A , k , mid)){
                ans = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        }
        return ans;
    }
};