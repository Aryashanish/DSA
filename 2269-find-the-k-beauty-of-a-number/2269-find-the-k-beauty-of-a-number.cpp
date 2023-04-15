class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int n = str.size();
        int i = 0 , j = 0;
        int ans = 0;
        
        while(j<n){
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k){
                string tstr = str.substr(i,k);
                int n = stoi(tstr);
                if(n != 0 && num%n == 0)
                    ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};