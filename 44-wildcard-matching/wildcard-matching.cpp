class Solution {
public:
    int ns ,np;
    bool recur(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        if(i == ns && j == np) return true;
        if( j == np) return false;
        if(i == ns){
            if(p[j] == '*') return recur(i,j+1,s,p,dp);
            else return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool res = false;
        if(p[j] == '*'){   
            // cout<<i<<" "<<j<<endl;
            res |= (recur(i+1,j,s,p,dp) || recur(i,j+1,s,p,dp));
        }
        else if(p[j] == '?'){
            res |= (recur(i+1,j+1,s,p,dp));
        }
        else{
            if(s[i] == p[j]){
                res |= recur(i+1,j+1,s,p,dp);
            }
            else return false;
        }
        return dp[i][j] = res;
    }
    bool isMatch(string s, string p) {
        ns = s.size(),np = p.size();
        vector<vector<int>> dp(ns,vector<int> (np,-1));
        return recur(0,0,s,p,dp);
    }
};