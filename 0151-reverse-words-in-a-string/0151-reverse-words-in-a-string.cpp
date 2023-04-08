class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        int i=0;
        while(s[i] == ' ')
            i++;
        
        while(i<s.size()){
            if(s[i] == ' '){
                if(temp != ""){
                    st.push(temp);
                    temp = "";
                }
            }else
                temp += s[i];
            i++;
        }
        if(temp != "")
            st.push(temp);
        
        temp = "";
        while(!st.empty()){
            temp += st.top();
            st.pop();
            if(st.size() > 0)
                temp += ' ';
        }
        return temp;
    }
};