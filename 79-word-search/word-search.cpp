class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>> &b,string word,int ind,int n,int m,vector<vector<int>> &vis){
        if(word.size() == ind) return true;
        if(i < 0 || j < 0 || i >=n || j >= m || b[i][j] != word[ind] ||vis[i][j] == 1 ) return false;
        bool ans = false;
        // b[i][j] = '#';
        vis[i][j] = 1;
        ans |= dfs(i+1,j,b,word,ind+1,n,m,vis);
        ans |= dfs(i,j+1,b,word,ind+1,n,m,vis);
        ans |= dfs(i,j-1,b,word,ind+1,n,m,vis);
        ans |= dfs(i-1,j,b,word,ind+1,n,m,vis);

        vis[i][j] = 0;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m = board[0].size();
       
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                 vector<vector<int>> vis(n,vector<int> (m,0));
                if(board[i][j] == word[0] && dfs(i,j,board,word,0,n,m,vis) == true){
                    return true;
                }
            }
        }
        return false;
    }
};