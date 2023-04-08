class Solution {
public:
    static bool comp(pair<int,int>p,pair<int,int>q){
      if(p.first==q.first)
      {
      return p.second>q.second;
      }

      return p.first<q.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int , int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        vector<pair<int,int>> vx;

        for(auto i : mp)   
            vx.push_back(make_pair(i.second, i.first)); 

        sort(vx.begin(),vx.end(),comp);
        
        vector<int> ans;
        for(int i=0; i<vx.size(); i++){
            int freq = vx[i].first;
            while(freq > 0){
                ans.push_back(vx[i].second);
                freq--;
            }
        }
        return ans;
    }
};