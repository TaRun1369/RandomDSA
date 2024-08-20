class Solution {
public:
    int recur(int ind,int m,vector<int> &piles,int turn, vector<vector<vector<int>>> &dp){
        if(ind == piles.size()) return 0;
        if(dp[turn][ind][m] != -1) return dp[turn][ind][m];
        int score = 0;
        int res = turn == 0? -1:INT_MAX;
        for(int i = 1;i<=min(2*m,(int)piles.size() - ind);i++){
            score += piles[i + ind -1];
            if(turn == 0){
                // alice
                res = max(res,score + recur(ind + i,max(m,i),piles,1,dp));
            }   
            else{
                // bob
                res = min(res,recur(ind + i,max(m,i),piles,0,dp));
            }
        }
        return dp[turn][ind][m] = res;
        
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp (2,vector<vector<int>> (n+1,vector<int>(n+1,-1)));
        return recur(0,1,piles,0,dp);
    }
};