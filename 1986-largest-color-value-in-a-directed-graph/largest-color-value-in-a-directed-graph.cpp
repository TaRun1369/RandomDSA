class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size() ;
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        int count  = 0,ans = 0;
        vector<vector<int>> t(n,vector<int> (26,0));
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indeg[i] == 0) {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        while(!q.empty()){
            int fr = q.front();
            q.pop();
            count++;
            ans = max(ans,t[fr][colors[fr] - 'a']);
            for(auto it : adj[fr]){
                for(int i = 0;i<26;i++){
                    t[it][i] = max(t[it][i] , t[fr][i] + ((colors[it] - 'a')== i));
                }
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);

            }

        }

        if(count < n) return -1;

        return ans;

    }
};