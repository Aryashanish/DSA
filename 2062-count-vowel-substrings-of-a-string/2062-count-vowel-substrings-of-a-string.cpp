class Solution {
public:
    int countVowelSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        map<char , int> mp;
        
        while(i<n){
            mp[s[i]]++;
            int j = i+1;
            while(j<n){
                mp[s[j]]++;
                
                if(mp.size() == 5 && mp['a'] && mp['e'] && mp['i'] && mp['o'] && mp['u'])
                    ans++;
                
                j++;
            }
            mp.clear();
            i++;
        }
        return ans;
    }
};