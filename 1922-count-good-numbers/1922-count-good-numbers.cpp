class Solution {
public:
    int mod = 1e9+7;
    
    long long power(int a, long long b) {
        if(b == 0)
            return 1;
        
        long long x = power(a, b/2);
        
        if(b % 2 == 0)
            return (x * x) % mod;
        else
            return (((a * x) % mod) * x) % mod;
    }
    
    int countGoodNumbers(long long n) {
        return (power(5,(n+1)/2) * power(4,n/2))%mod;
    }
};