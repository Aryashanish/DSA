class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowlen = matrix.size();
        int collen = matrix[0].size();
        
        map<int,int> row;
        map<int,int> col;
        
        for(int i=0; i<rowlen; i++){
            for(int j=0; j<collen; j++){
                if(matrix[i][j] == 0){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for(int i=0; i<rowlen; i++){
            for(int j=0; j<collen; j++){
                if(row[i] != 0 || col[j] != 0)
                    // cout<<"1"<<" ";
                    matrix[i][j] = 0;
            }
        }
    }
};