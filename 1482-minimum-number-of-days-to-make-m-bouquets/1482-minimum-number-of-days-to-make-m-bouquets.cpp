class Solution {
public:
    int healper(vector<int>& v , int d , int k){
        int n = v.size();
        int adj = 0;
        int i=0;
        while(i<n){
            if(v[i] <= d){
                int j = i+1;
                int t = 1;
                while(j<n && v[j] <= d){
                    t++;
                    j++;
                }
                adj += t/k;
                i = j;
            }else
                i++;
        }
        return adj;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        int maxi = bloomDay[0];
        
        for(int it : bloomDay)
            maxi = max(maxi,it);
        
        int i=1 , j=maxi;
        int mid;
        int ans = -1;
        while(i<=j){
            mid = j+(i-j)/2;
            int make = healper(bloomDay,mid,k);
            // cout<<mid<<" "<<make<<endl;
            if(make < m)
                i = mid+1;
            else if(make > m){
                ans = mid;
                j = mid-1;
            }
            else{
                ans = mid;
                j = mid-1;
            }
        }
        return ans;
    }
};