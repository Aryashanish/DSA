class Solution {
public:
    string frequencySort(string s) {
        
        map<char , int> mp;
        
        for(int i=0; i<s.size(); i++)
            mp[s[i]]++;
        
        vector<pair<int,char>> vx;

        for(auto i=mp.begin(); i!=mp.end(); i++)   
            vx.push_back(make_pair(i->second, i->first)); 

        sort(vx.rbegin(),vx.rend());
        
        string ans = "";
        for(int i=0; i<vx.size(); i++){
            int freq = vx[i].first;
            while(freq > 0){
                ans += vx[i].second;
                freq--;
            }
        }
        return ans;
    }
};