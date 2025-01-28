class Solution {
public:
    int n,m;
    int dfs(int i ,int j,vector<vector<int>> &grid){
        int ans = grid[i][j];
        grid[i][j] = 0;
        
        if(i - 1 >= 0 && grid[i-1][j] >0)ans += dfs(i-1,j,grid);
        if(i + 1 < n && grid[i + 1][j] > 0) ans += dfs(i + 1,j,grid);
        if(j - 1 >= 0 && grid[i][j - 1] > 0) ans += dfs(i,j - 1,grid);
        if(j + 1 < m && grid[i][j + 1] > 0 )ans +=  dfs(i,j + 1,grid);

        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] > 0){
                    cout<<i<<" "<<j<<" ";
                    int dfsans = dfs(i,j,grid);
                    cout<<dfsans<<endl;
                    ans = max(ans,dfsans);
                }
            }
        }
        return ans;
    }
};