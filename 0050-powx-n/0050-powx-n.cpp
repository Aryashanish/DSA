class Solution {
public:
    double healper(double x , int n){
        if(n == 0)
            return 1;
        
        return (x * myPow(x,n-1));
    }
    double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        
        if(n < 0){
            double temp = healper(x,-n);
            return (1.0/temp);
        }
        
        return healper(x,n);
    }
};