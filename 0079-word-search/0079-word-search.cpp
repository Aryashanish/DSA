class Solution {
public:
    bool healper(vector<vector<char>>& board , int r , int c , string word , int i , vector<vector<bool>>& vis){
        // cout<<word[i]<<" ("<<r<<","<<c<<")"<<" "<<i<<endl;
        if(i == word.size()-1)
            return true;
        
        int n = board.size();
        int m = board[0].size();
        int drow[] = {0,0,1,-1};
        int dcol[] = {1,-1,0,0};

        for(int j=0; j<4; j++){
            int nr = r+drow[j];
            int nc = c+dcol[j];

        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc] == word[i+1]){
                vis[nr][nc] = true;
                if(healper(board , nr , nc , word , i+1, vis))
                    return true;
                vis[nr][nc] = false;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = true;
                    if(healper(board , i , j , word ,0, vis))
                        return true;
                    vis[i][j] = false;
                    cout<<endl;
                }
            }
        }
        
        return false;
    }
};