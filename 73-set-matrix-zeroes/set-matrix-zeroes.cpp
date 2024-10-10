class Solution {
public:
    
    void setZeroes(vector<vector<int>>& mat) {
        // hehe(mat);
        int n = mat.size();
        int m = mat[0].size();
        vector<int> r,c;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }

        for(auto it : r){
            for(int i = 0;i<m;i++){
                mat[it][i] = 0;
            }
        }

        for(auto it : c){
            for(int i = 0;i<n;i++){
                mat[i][it] = 0;
            }
        }

       
    }

};