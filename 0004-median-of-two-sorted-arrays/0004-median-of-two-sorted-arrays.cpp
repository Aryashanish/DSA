class Solution {
public:
    void merge(vector<int>& n1 , vector<int>& n2 , vector<int>&v){
        int i=0 , j=0;
        while(i<n1.size() && j<n2.size()){
            if(n1[i] < n2[j])
                v.push_back(n1[i++]);
            else if(n1[i] > n2[j])
                v.push_back(n2[j++]);
            else{
                v.push_back(n1[i]);
                v.push_back(n1[i]);
                i++ , j++;
            }
        }
        
        for(; i<n1.size(); i++)
            v.push_back(n1[i]);
        
        for(; j<n2.size(); j++)
            v.push_back(n2[j]);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        merge(nums1,nums2,v);
        
        // cout<<nums1.size()<<" "<<nums2.size()<<" "<<v.size()<<endl;
        // for(int i=0; i<v.size(); i++)
        //     cout<<v[i]<<" ";
        // cout<<endl;
        
        double ans;
        if(v.size()%2 != 0)
            ans = v[v.size()/2];
        else
            ans = (v[v.size()/2] + v[v.size()/2-1])/2.0;
        
        return ans;
    }
};