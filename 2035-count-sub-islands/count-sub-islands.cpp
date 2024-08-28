class Solution {
public:
    int n,m;
    vector<int> di = {1,0,-1,0},dj = {0,1,0,-1};
    bool valid(int i,int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,bool &bol){
        for(int ind = 0;ind<4;ind++){
            int ni = i + di[ind];
            int nj = j + dj[ind];
            if(valid(ni,nj) && grid2[ni][nj] == 1){
                grid2[ni][nj] = 2;
                dfs(grid1,grid2,ni,nj,bol);
                if(grid1[ni][nj] == 0) bol = false;
            }
        }

        // bol = true;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid2[i][j] == 1 && grid1[i][j] == 1){
                    bool bol = true;
                    
                    dfs(grid1,grid2,i,j,bol);
                    if(bol == true) ans++;
                }
            }
        }
        return ans;
    }
};