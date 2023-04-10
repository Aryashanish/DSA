class Solution {
public:
    string sortSentence(string s) {
        int space = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ')
                space++;
        }
        
        vector<string> v(space+1);
        int i=0;
        string word = "";
        while(i<s.size()){
    
            if(isdigit(s[i])){
                int ind = s[i]-'0';
                v[ind-1] = word;
                word = "";
            }
            if(s[i] != ' ' && !isdigit(s[i]))
                word += s[i];
            i++;
        }
        
        string ans = "";
        for(int i=0; i<v.size(); i++)
            ans += v[i] + ' ';
        
        return ans.substr(0,ans.size()-1);
    }
};