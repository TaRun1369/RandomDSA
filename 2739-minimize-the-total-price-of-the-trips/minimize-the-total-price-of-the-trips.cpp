class Solution {
public:
    vector<int> count;
    bool getcount(int start,int end,int par,vector<vector<int>> &adj){
        // dfs for count of nodes in that trip
        if(start == end) return true;
        for(auto it : adj[start]){
            if(it != par){
                if(getcount(it,end,start,adj)){
                    count[it]++;
                    return true;
                }
            }
        }
        return false;
    }
    int dp[51][2];
    int dfs(bool taken,int node,int par,vector<int> &price,vector<vector<int>> &adj){
        if(dp[node][taken] != -1) return dp[node][taken];
        int kitnebache = 0;
        for(auto it : adj[node]){
            if(it != par) kitnebache++;
        }

        if(kitnebache == 0){
            if(taken){
               return dp[node][taken] = count[node] * price[node];
            }
            return dp[node][taken] = count[node] * (price[node]/2);
        }
        if(taken){
            int ans = 0;
            for(auto it : adj[node]){
                if(it != par){
                    ans += dfs(false,it,node,price,adj);
                }

            }
            ans += count[node] * price[node];
            return dp[node][taken] = ans;

        }
        int ans1 = 0,ans2 = 0;
        for(auto it : adj[node]){
            if(it != par){
                ans1 += dfs(true,it,node,price,adj);
                ans2 += dfs(false,it,node,price,adj);
            }
           
        }
         ans1 += count[node] * price[node]/2;
            ans2 += count[node] * price[node];
            return dp[node][taken] = min(ans1,ans2);
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        count.resize(n,0);
        for(auto it : trips){
            count[it[0]]++;
            getcount(it[0],it[1],-1,adj);
        }
        return dfs(false,0,-1,price,adj);
    }
};