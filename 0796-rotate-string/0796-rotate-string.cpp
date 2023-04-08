class Solution {
public:
    void leftrotate(string &s, int d){
        reverse(s.begin(), s.begin()+d);
        reverse(s.begin()+d, s.end());
        reverse(s.begin(), s.end());
    }

    bool rotateString(string s, string goal) {
        if(s == goal)
            return true;
        
        for(int i=0; i<s.size(); i++){
            string t = s;
            leftrotate(t,i);
            if(t == goal)
                return true;
        }
        return false;
    }
};