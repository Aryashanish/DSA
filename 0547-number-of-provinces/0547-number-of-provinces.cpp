class Solution {
public:
    void dfs(vector<int> adj[] , vector<int>& vis , int src){
        vis[src] = 1;
        for(int it : adj[src]){
            if(!vis[it])
                dfs(adj,vis,it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n+1];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        
        int ans = 0;
        vector<int> vis(n+1,0);
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                ans++;
                dfs(adj,vis,i);
            }
        }
        
        return ans;
    }
};