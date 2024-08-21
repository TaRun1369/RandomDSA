class Solution {
public:
int  recur(int l,int r,string &s,vector<vector<int>> &dp){
    if(l == r) return 1;
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int i = l+1;
    while(i <= r && s[i] == s[l]){
        i++;
    }

    int normal = 1 + recur(i,r,s,dp);
    int lalach = INT_MAX;
    for(int j = i;j<=r;j++){
        if(s[j] == s[l]){
            int ans = recur(i,j-1,s,dp) + recur(j,r,s,dp);
            lalach = min(lalach,ans);
        }
    }
    return dp[l][r] =  min(normal,lalach);
}
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));

        return recur(0,n-1,s,dp);
    }
};