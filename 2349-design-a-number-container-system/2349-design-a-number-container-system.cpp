class NumberContainers {
public:
    unordered_map<int,set<int>>mp;
    unordered_map<int,int>mp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp2.find(index)!=mp2.end()){
            int val=mp2[index];
            mp[val].erase(index);
            if(!mp[val].size())mp.erase(val);
        }
        mp[number].insert(index);
        mp2[index]=number;
        
    }
    
    int find(int number) {
        if(mp.find(number)==mp.end())
            return -1;
        auto it=mp[number].begin();
        return *it;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */