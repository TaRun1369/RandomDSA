class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> diff(row,vector<int> (col,0));
        vector<int> onerows(row,0),zerorows(row,0),onecol(col,0),zerocol(col,0);

        for(int i = 0;i<row;i++){
            for(int j = 0;j< col;j++){
                if(grid[i][j] == 1){
                    onerows[i]++;
                    onecol[j]++;
                }
                else{
                    zerorows[i]++;
                    zerocol[j]++;
                }
            }
        }

        for(int i = 0;i<row;i++){
            for(int j = 0;j< col;j++){
                diff[i][j] = onerows[i] + onecol[j] - zerorows[i] - zerocol[j];
            }
        }
        return diff;
    }
};