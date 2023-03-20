class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(len == 1 && flowerbed[0] == 0)
            return 1;
        
        if(n == 0)
            return true;
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            n--;
            flowerbed[0] = 1;
        }
        
        if(n==0)
            return true;
        
        for(int i=1; i<len; i++){
            if(flowerbed[i] == 0 && i+1<len && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                n--;
                flowerbed[i] = 1;
                if(n == 0)
                    return true;
                // cout<<i<<" ";
            }
        }
        
        if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0){
            n--;
            cout<<n-1<<" ";
        }
        
        if(n==0)
            return true;
        
        return false;
    }
};