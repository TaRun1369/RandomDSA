// class Solution {
// public:
//     int n;
//     int recur(int stockhold,int ind,vector<int> p,int mtran, vector<vector<vector<int>>> &dp){
//         if(ind >= n || mtran == 0) return 0;

//         int ans = 0;
//         if(dp[ind][mtran][stockhold] != -1) return dp[ind][mtran][stockhold];
//         if(stockhold == 0){
//             ans = max(ans,recur(1,ind + 1,p,mtran,dp) - p[ind]);
//         }
//         else{
//             ans = max(ans,recur(0,ind + 1,p,mtran-1,dp) + p[ind]);
//         }
//         ans = max(ans,recur(stockhold,ind + 1,p,mtran,dp));
//         return dp[ind][mtran][stockhold] = ans;
//     }
//     int maxProfit(vector<int>& prices) {
//         n = prices.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
//         return recur(0,0,prices,2,dp);
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                dp[0][j][k]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    int profit=0;
                    if(j){
                        int pick=-prices[i]+dp[i+1][false][k];
                        int notPick=0+dp[i+1][true][k];
                        profit=max(pick,notPick);
                    }
                    else{
                        int pick=prices[i]+dp[i+1][true][k-1];
                        int notPick=dp[i+1][false][k];
                        profit=max(pick,notPick);
                    }
                    dp[i][j][k]=profit;
                }
            }
        }
        return dp[0][true][2];
    }
};