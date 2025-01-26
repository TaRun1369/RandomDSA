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
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return recur(0,0,prices,2,dp);
    }
};
// class Solution {
//     int solve(int index,int buy,int cnt,int n,vector<int> &prices,vector<vector<vector<int>>> &dp){
//         if(index==n){
//             return 0;
//         }
//         if(cnt==0){
//             return 0;
//         }
//         if(dp[index][buy][cnt]!=-1){
//             return dp[index][buy][cnt];
//         }
//         int profit=0;
//         if(buy){
//             int pick=-prices[index]+solve(index+1,false,cnt,n,prices,dp);
//             int notPick=0+solve(index+1,true,cnt,n,prices,dp);
//             profit=max(pick,notPick);
//         }
//         else{
//             int pick=prices[index]+solve(index+1,true,cnt-1,n,prices,dp);
//             int notPick=solve(index+1,false,cnt,n,prices,dp);
//             profit=max(pick,notPick);
//         }
//         return dp[index][buy][cnt]=profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
//         return solve(0,true,2,n,prices,dp);
//     }
// };