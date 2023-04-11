class Solution {
public:
    int healper(int ind , vector<int> v){
        if(ind == 0)
            return 1;
        
        int ans = 0;
        for(int i=1; i<v.size(); i++){
            if(v[i] == 0 && (ind%i == 0 || i%ind == 0)){
                v[i] = ind;
                ans += healper(ind-1,v);
                v[i] = 0;
            }
        }
        
        return ans;
    }
    int countArrangement(int n) {
        vector<int> v(n+1);
        return healper(n,v);
    }
};