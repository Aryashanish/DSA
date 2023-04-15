class Solution {
public:
    string healper(string s){
        if(s.size() <= 1)
            return "";
        
        unordered_set<char> st;
        st.insert(s.begin() , s.end());
        
        for(int i=0; i<s.size(); i++){
            char t1 = tolower(s[i]);
            char t2 = toupper(s[i]);
            
            if(st.find(t1) == st.end() or st.find(t2) == st.end()){
                string left = healper(s.substr(0,i));
                string right = healper(s.substr(i+1,s.size()));
                
                if(left.size() == right.size())
                    return left;
                else if(left.size() > right.size())
                    return left;
                else
                    return right;
            }
        }
        return s;
    }
    string longestNiceSubstring(string s) {
        return healper(s);
    }
};