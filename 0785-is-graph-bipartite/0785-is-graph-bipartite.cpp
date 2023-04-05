class Solution {
public:
    bool dfs(int i , int col , vector<vector<int>> g , vector<int>& color){
        color[i] = col;
        for(int it : g[i]){
            if(color[it] == -1){
                if(dfs(it,!col,g,color) == false)
                    return false;
            }
            else if(color[it] == col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0; i<n; i++){
            if(color[i] == -1)
                if(dfs(i,1,graph,color) == false)
                    return false;
        }
        return true;
    }
};