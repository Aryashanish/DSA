class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> st;
        
        for(int i=0; i<n; i++){
            if(i>indexDiff)
                st.erase(nums[i-indexDiff-1]);
            
            auto pos = st.lower_bound(nums[i]-valueDiff);
            
            if(pos != st.end() && abs(*pos - nums[i]) <= valueDiff)
                return true;
            
            st.insert(nums[i]);
        }
        return false;
    }
};