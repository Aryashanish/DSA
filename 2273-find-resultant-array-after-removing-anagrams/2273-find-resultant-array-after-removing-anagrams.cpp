class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char , int> mp;
        
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
        for(int i=0; i<t.size(); i++){
            if(mp[t[i]] == 0 or mp[t[i]] < 0)
                return false;
            else
                mp[t[i]]--;
        }
        
        return true;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        int i = 1;
        vector<string>::iterator it;
        
        while(i<n){
            if(isAnagram(words[i] , words[i-1])){
                it = words.begin()+i;
                words.erase(it);
                n--;
            }else
                i++;
        }
        return words;
    }
};