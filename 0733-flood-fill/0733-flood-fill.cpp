class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> vis(n , vector<int>(m,0));
        vector<vector<int>> ans = image;
        
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        
        queue<pair<int,int>> q;
        int initcolor = image[sr][sc];
        q.push({sr,sc});
        ans[sr][sc] = color;
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int drow = r + dx[i];
                int dcol = c + dy[i];
                
                if(drow>=0 && drow<n && dcol>=0 && dcol<m && vis[drow][dcol] == 0 &&
                  image[drow][dcol] == initcolor){
                    q.push({drow,dcol});
                    vis[drow][dcol] = 1;
                    ans[drow][dcol] = color;
                }
            }
        }
        return ans;
    }
};