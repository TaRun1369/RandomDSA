class Solution {
public:
    int recur(vector<int> &cost,int ind,vector<int> &dp){
        if(ind >= cost.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        // one step
        int one  = cost[ind] + recur(cost , ind + 1,dp);
        // two step
        int two = cost[ind] + recur(cost,ind + 2,dp);

        return dp[ind] = min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(recur(cost,0,dp),recur(cost,1,dp));
    }
};