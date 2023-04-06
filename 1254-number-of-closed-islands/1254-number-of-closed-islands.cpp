class Solution {
public:
    void dfs(int r , int c , vector<vector<int>>& vis , vector<vector<int>>& grid){
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        
        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 0 && vis[nr][nc] == 0)
                dfs(nr,nc,vis,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        int ans = 0;
        
        //row wise 
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0 && vis[i][0] == 0)
                dfs(i,0,vis,grid);
            if(grid[i][m-1] == 0 && vis[i][m-1] == 0)
                dfs(i,m-1,vis,grid);
        }
        
        //col wise 
        for(int i=0; i<m; i++){
            if(grid[0][i] == 0 && vis[0][i] == 0)
                dfs(0,i,vis,grid);
            if(grid[n-1][i] == 0 && vis[n-1][i] == 0)
                dfs(n-1,i,vis,grid);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 0){
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};