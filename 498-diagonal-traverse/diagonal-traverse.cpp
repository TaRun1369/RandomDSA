class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // 0, 0
        // 1,0 0,1
        // 2,0  1, 1  0,2
        // 2,1 1,2
        // 2,2
        int n = mat.size(),m = mat[0].size();
        map<int,vector<int>> pre_ans;
        for(int i = n-1;i>=0;i--)
        {
            for(int j = m - 1;j >= 0; j--){
                pre_ans[i + j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(auto it : pre_ans){
            if(it.first & 1) reverse(it.second.begin(),it.second.end());
            for(auto i : it.second)

            ans.push_back(i);
        }
        return ans;

    }
};