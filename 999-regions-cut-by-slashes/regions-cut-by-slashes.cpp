class Solution {
public:
int r,c;
bool valid(int i,int j){
    return i >= 0 && j >= 0 && i < r && j < c;
}
void dfs(int i,int j,vector<vector<int>> &mat){
    mat[i][j] = 2;
    if(valid(i+1,j) && mat[i+1][j] == 0){
        dfs(i+1,j,mat);
    }
    if(valid(i,j+1) && mat[i][j+1] == 0){
        dfs(i,j+1,mat);
    }
    if(valid(i-1,j) && mat[i-1][j] == 0){
        dfs(i-1,j,mat);
    }
    if(valid(i,j-1) && mat[i][j-1] == 0){
        dfs(i,j-1,mat);
    }
}
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n*3,vector<int> (n*3,0));

        r = c = 3*n;
        // for(int j = 0;j<grid.size();j++){
        //     while(i < grid[j].size()){
        //         if(grid[j][i] == '/'){
        //             mat[j][] = 1;
        //             mat[i+1][j] = 1;
        //         }
        //         else if(grid[j][i] == '\\'){
        //             mat[i+1][j+1] = 1;
        //             mat[i][j] = 1;
        //         }
        //         i++;
        //     }
        // }

        for(int i  = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '/'){
                    mat[i*3][j*3 + 2] = 1;
                    mat[i*3 + 1][j*3 + 1] = 1;
                    mat[i*3 + 2][j*3] = 1;
                }
                if(grid[i][j] == '\\'){
                    mat[i*3][j*3] = 1;
                    mat[i*3 + 1][j*3 + 1] = 1;
                    mat[i*3 + 2][j*3 + 2] = 1;
                }

            }   
        }
        int count = 0;
        for(int i = 0;i<3*n;i++){
            for(int j = 0;j<3*n;j++){
                if( mat[i][j] == 0){
                    count++;
                    dfs(i,j,mat);
                }
            }
        }
        return count;

    }
};
