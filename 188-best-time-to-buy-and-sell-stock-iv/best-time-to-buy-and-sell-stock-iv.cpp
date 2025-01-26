class Solution {
public:
    int n;
    int recur(int stockhold,int ind,vector<int> &p,int mtran, vector<vector<vector<int>>> &dp){
        if(ind >= n || mtran == 0) return 0;

        int ans = 0;
        if(dp[ind][mtran][stockhold] != -1) return dp[ind][mtran][stockhold];
        if(stockhold == 0){
            ans = max(ans,recur(1,ind + 1,p,mtran,dp) - p[ind]);
        }
        else{
            ans = max(ans,recur(0,ind + 1,p,mtran-1,dp) + p[ind]);
        }
        ans = max(ans,recur(stockhold,ind + 1,p,mtran,dp));
        return dp[ind][mtran][stockhold] = ans;
    }
    int maxProfit(int k,vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return recur(0,0,prices,k,dp);
    }
};