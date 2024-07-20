class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int i = 0,j = 0;
        int n = rowSum.size(),m = colSum.size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            int curr = rowSum[i];
            for(int j = 0;i<n;j++){
                int mini = min(curr,colSum[j]);
                ans[i][j] = mini;
                 colSum[j] -= mini;
                 curr -= mini;
                if(curr == 0) break;
            }
        }
        return ans;
    }
};