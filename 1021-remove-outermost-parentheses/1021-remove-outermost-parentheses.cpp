class Solution {
public:
    string removeOuterParentheses(string s) {
        string str = "";
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                if(st.size()>0)
                    str += '(';
                st.push('(');
            }else{
                st.pop();
                if(st.size() > 0)
                    str += ')';
            }
        }
        return str;
    }
};