class Solution {
public:
    int healper(vector<int>& w , int n){
        int daysNeeded = 1, currWeight = 0;
        for (int weight : w) {
            if (currWeight + weight > n) {
                daysNeeded++;
                currWeight = 0;
            }
            currWeight = currWeight + weight;
        }
        return daysNeeded;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int maxi = weights[0];
        for(int i=0; i<weights.size(); i++){
            s += weights[i];
            maxi = max(maxi , weights[i]);
        }
        
        int i = maxi  , j = s;
        int mid;

        while(i<=j){
            mid = j+(i-j)/2;
            int d = healper(weights,mid);

            if(d > days)
                i = mid+1;
            else
                j = mid-1;
        }
        return i;
    }
};