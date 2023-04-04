class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        map<char,int> mp;
        while(i<n){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]]++;
                i++;
            }
            else{
                ans++;
                mp.clear();
            }
        }
        if(mp.size() > 0)
            ans++;
            
        return ans;
    }
};