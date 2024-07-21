class Solution {
public:
    vector<int> topo(vector<vector<int>>& edges,int k){
        vector<int> indegree(k + 1,0);
        vector<vector<int>> adj(k + 1);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        int count = 0; // to check loop
        for(int i = 1;i<= k;i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                    count++;
                }
            }
        }
        if(count != k){
            return {};
        }

        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> orderRow = topo(rowConditions,k);
        vector<int> orderCol = topo(colConditions,k);
        vector<vector<int>> ans(k,vector<int> (k,0));
        if(orderRow.empty() || orderCol.empty()) return {};

        for(int i = 0;i<k;i++){
            for(int j = 0;j<k;j++){
                if(orderRow[i] == orderCol[j]){
                    ans[i][j] = orderRow[i];
                }
            }
        }

        
        
        return ans;
    }
};