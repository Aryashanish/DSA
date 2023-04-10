class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pre(n) , suf(n);
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            pre[i] = cnt;
            if(s[i] == 'b')
                cnt++;
        }
        cnt = 0;
        for(int i=n-1; i>=0; i--){
            suf[i] = cnt;
            if(s[i] == 'a')
                cnt++;
        }
        
        int ans = 1e9;
        for(int i=0; i<n; i++){
            ans = min(ans , pre[i]+suf[i]);
        }
        return ans;
    }
};