class Solution {
public:
    bool odd(int n){
        if(n%2 != 0)
            return true;
        return false;
    }
    string largestOddNumber(string num) {
        int ind;
        for(int i=num.size()-1; i>=0; i--){
            if(odd(num[i]-'0')){
                ind = i;
                break;
            }
        }
        
        return num.substr(0,ind+1);
    }
};