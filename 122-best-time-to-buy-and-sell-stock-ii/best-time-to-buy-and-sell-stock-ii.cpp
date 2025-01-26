class Solution {
public:
    int recur(int stock,vector<int> &prices,int ind,vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        int ans = 0;
        if(dp[ind][stock] != -1) return dp[ind][stock];
        if(stock == 0){
            ans = max(ans,recur(1,prices,ind+1,dp) - prices[ind]);
            ans = max(ans,recur(0,prices,ind + 1,dp));
        }
        else{
            ans = max(ans,recur(0,prices,ind + 1,dp) + prices[ind]);
            ans = max(ans,recur(1,prices,ind+1,dp));

        }
        return dp[ind][stock] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1) );
        return recur(0,prices,0,dp);
    }
};