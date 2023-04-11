class Solution {
public:
//     int isValid(string s){
//         map<char , int> mp;
//         int minfreq = 500;
//         int maxfreq = 0;
        
//         for(int i=0; i<s.size(); i++){
//             mp[s[i]]++;
//             minfreq = min(minfreq , mp[s[i]]);
//             maxfreq = max(maxfreq , mp[s[i]]);
//         }
//         if(mp.size() < 2 || mp.size() == s.size())
//             return 0;
        
//         return (maxfreq-minfreq);
//     }
    
    int beautySum(string s) {
        map<char , int> mp;
        int cnt = 0 , mx = 0 , mi = 500;
        for(int i=0; i<s.size(); i++){
            
            for(int j=i; j<s.size(); j++){
                mp[s[j]]++;
                
                for(auto it : mp){
                    mx = max(mx , it.second);
                    mi = min(mi , it.second);
                }
                
                cnt += mx-mi;
                mx = 0 , mi = 500;
            }
            mp.clear();
        }
        return cnt;
    }
};