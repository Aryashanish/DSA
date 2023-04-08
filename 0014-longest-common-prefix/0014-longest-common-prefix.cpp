class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string , int> mp;
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            string t = "";
            int j=0; 
            while(j<str.size()){
                t += str[j];
                mp[t]++;
                j++;
            }
        }
        
        string ans = "";
        int t = 0;
        for(auto it : mp){
            string tstr = it.first;
            int freq = it.second;
            if(freq >= strs.size() && freq>=t){
                if(tstr.size() > ans.size())
                    ans = tstr;
                t = freq;
            }
        }
        return ans;
    }
};