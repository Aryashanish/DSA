class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int c = matrix.size()-1;
        int n = matrix.size();
        int temp[n][n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                temp[j][c] = matrix[i][j];
            c--;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                matrix[i][j] = temp[i][j];
        }
    }
};