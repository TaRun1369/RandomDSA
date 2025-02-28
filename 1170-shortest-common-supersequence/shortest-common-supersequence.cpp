class Solution {
public:
    
    string shortestCommonSupersequence(string s1, string s2) {
        string res = "";

        int n = s1.size(),m = s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<m + 1;j++){
                if(i == 0 || j == 0) {
                    dp[i][j] = i + j;
                }
                else if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = 1+ min(dp[i-1][j] , dp[i][j - 1]);

                }

            }
        }
        int i = n,j = m;
        while(i > 0 && j > 0){
            if(s1[i - 1] == s2[j - 1]){
                res.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] < dp[i][j - 1]){
                    res.push_back(s1[i-1]);
                    i--;
                }
                else{
                    res.push_back(s2[j - 1]);
                    j--;
                }
            }
        }

        while(i > 0){
            res.push_back(s1[i-1]);
            i--;
        }
        while(j > 0){
            res.push_back(s2[j-1]);
            j--;
        }
        reverse(res.begin(),res.end());
        return res;

    }
};