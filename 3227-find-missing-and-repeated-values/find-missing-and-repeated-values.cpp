class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int miss,twice;
        int n = grid.size();
        vector<int> vis(n*n,0);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                vis[grid[i][j] - 1]++;
            }
        }
        for(int i = 0;i<n*n;i++){
            if(vis[i] == 0) miss = i + 1;
            if(vis[i] == 2) twice = i + 1;
        }
        return {twice,miss};
    }
};