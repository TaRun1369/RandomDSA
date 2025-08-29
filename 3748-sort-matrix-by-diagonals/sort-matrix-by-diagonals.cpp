class Solution {
public:
    
     vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int, vector<int>> diagMap;
        int n = grid.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diagMap[i - j].push_back(grid[i][j]);
            }
        }
        
        for (auto& [key, values] : diagMap) {
            if (key >= 0) {
                sort(values.begin(), values.end());
            } else {
                sort(values.rbegin(), values.rend());
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = diagMap[i - j].back();
                diagMap[i - j].pop_back();
            }
        }
        
        return ans;
    }
};
