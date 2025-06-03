class Solution {
public:
    void bfs(int i ,int j,vector<vector<char>> &grid,int n,int m){
        if(i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '1') {
            grid[i][j] = '0';
            if(i + 1 < n) bfs(i+1,j,grid,n,m);
            if(j + 1 < m) bfs(i,j+1,grid,n,m);
            if(i - 1 >= 0) bfs(i-1,j,grid,n,m);
            if(j - 1 >= 0) bfs(i,j-1,grid,n,m);
        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    bfs(i,j,grid,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};