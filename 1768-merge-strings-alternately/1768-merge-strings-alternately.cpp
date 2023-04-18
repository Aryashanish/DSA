class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0 , j = 0;
        bool w1 = true;
        string ans = "";
        
        while(i<n && j<m){
            if(w1)
                ans += word1[i++];
            else
                ans += word2[j++];
            w1 = !w1;
        }
        
        for(;i<n; i++)
            ans += word1[i];
        for(;j<m; j++)
            ans += word2[j];
        
        return ans;
    }
};