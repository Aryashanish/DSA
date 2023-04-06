class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0 , j=0;
        int w = 0 , b = 0;
        int ans = INT_MAX;
        
        while(j<blocks.size()){
            if(blocks[j] == 'W')
                w++;
            else
                b++;
            
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                // cout<<w<<" "<<b<<endl;
                ans = min(ans , w);
                if(blocks[i] == 'W')
                    w--;
                else
                    b--;
                i++;
                j++;
            }
        }
        return ans;
    }
};