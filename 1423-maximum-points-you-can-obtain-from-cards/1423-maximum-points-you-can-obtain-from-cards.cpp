class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int pre[n];
        pre[0] = cardPoints[0];
        
        for(int i=1; i<n; i++)
            pre[i] = pre[i-1]+cardPoints[i];
        
        if(n == k)
            return pre[n-1];
        
        int s = n - k;
        int i = 0 , j = s;
        int ans = pre[n-1] - pre[j-1];
        
        while(j<n){
            int subSum = pre[j] - pre[i];
            int takeElesum = pre[n-1] - subSum;
            ans = max(ans , takeElesum);
            i++;
            j++;
        }
        return ans;
    }
};