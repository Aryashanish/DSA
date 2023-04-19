class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0 , mid;
        int h = arr.size() - 1;
        int ans = -1;
        while(l <= h){
            mid = l + (h - l) / 2;
            if(arr[mid]>arr[mid+1] && arr[mid] > arr[mid-1]){
                ans = mid;
                break;
            }
            else if(arr[mid] < arr[mid+1])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return ans;
    }
};