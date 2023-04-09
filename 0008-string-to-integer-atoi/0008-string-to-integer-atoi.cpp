class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        
        //trim space
        while(s[i] == ' ')
            i++;
        
        //check sign before number
        int sign = 1;
        if(s[i] == '+' || s[i] == '-'){
            if(s[i] == '-')
                sign = -1;
            i++;
        }
        
        int ans = 0;
        //get number
        while(i<s.size()){
            if(!isdigit(s[i]))
                return ans;
            int dig = (s[i] - '0')*sign;
            
            //very risky part (to handle overflows)
            if(sign== 1 && (ans> INT_MAX/10  || (ans==INT_MAX/10 && dig>(INT_MAX%10)))) return INT_MAX;
            if(sign== -1 && (ans< INT_MIN/10 || (ans==INT_MIN/10 && dig<(INT_MIN%10)))) return INT_MIN;
            
            ans= (1LL*ans*10)+ dig;
            i++;
        }
        return ans;
    }
};