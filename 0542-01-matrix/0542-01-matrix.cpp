class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0}); 
                    vis[i][j] = 1;
                }
            }
        }
        
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans[r][c] = t;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = r + dx[i];
                int ncol = c + dy[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return ans;
    }
};