class Solution {
public:
    void dfs(int r , int c , vector<vector<int>>&vis , vector<vector<char>> board){
        int m = board.size();
        int n = board[0].size();
        vis[r][c] = 1;
        int drow[] = {0,-1,0,+1};
        int dcol[] = {-1,0,+1,0};
        
        for(int i=0; i<4; i++){
            int row = r+drow[i];
            int col = c+dcol[i];
            
            if(row>=0 && row<m && col>=0 && col<n && !vis[row][col] && 
              board[row][col] == 'X')
                dfs(row,col,vis,board);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m , vector<int>(n,0));
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    dfs(i,j,vis,board);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};