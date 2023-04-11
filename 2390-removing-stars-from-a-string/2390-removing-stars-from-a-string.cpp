class Solution {
public:
    void healper(string &s , int i){
        if(i == s.size())
            return;
        
        if(s[i] != '*')
            healper(s,i+1);
        else{
            string left = s.substr(0,i-1);
            string right = s.substr(i+1);
            s = left+right;
            healper(s,i-1);
        }
    }
    string removeStars(string s) {
        
        stack<char> st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] != '*')
                st.push(s[i]);
            else{
                st.pop();
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};