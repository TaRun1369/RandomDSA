class Solution {
public:
    vector<int> path;

    bool dfs(int start,int par,vector<vector<int>> &adj,int d){
        if(start == 0){
            return true;
        }

        for(auto it : adj[start]){
            if(it != par && path[it] == -1){
                // nb.push_back(start);
                path[it] = d;
                if(dfs(it,start,adj,d+1)) return true;
                path[it] = -1;
            }
        }
        return false;
    }
    int solve(int node,int par,vector<vector<int>> &adj,int d,vector<int> &amount){
        int maxi = INT_MIN;
        int x = 0;
        if(path[node] == -1 || path[node] > d ) x+= amount[node];
        else if(path[node] == d) x += amount[node]/2;

        for(auto it : adj[node]){
            if(it != par){
                maxi = max(maxi,solve(it,node,adj,d+1,amount) + x);
            }
        }
        if(maxi == INT_MIN) return x;
        return maxi;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        path.resize(n,-1);
        path[bob] = 0;
        dfs(bob,-1,adj,1);
        int ans = solve(0,-1,adj,0,amount);
        return ans;
    }
};