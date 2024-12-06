class Solution {
public:
    static bool comparator(const pair<long long, long long>& l, const pair<long long, long long>& r) {
        return (l.first - l.second) < (r.first - r.second);
    }
    long long dfs(int i, int j, int parent, vector<vector<pair<int, int>>>& adj, vector<vector<long long>>& dp, int k) {
        if (dp[i][j] != -1) return dp[i][j];

        int opsToDo = max(0, (int)adj[i].size() - k - j);
        long long answer = 0;

        vector<pair<long long, long long>> children;

        for (const pair<int, int>& edge : adj[i]) {
            int neigh = edge.first;
            int weight = edge.second;

            if (neigh != parent) {
                long long take = dfs(neigh, 0, i, adj, dp, k) + weight;
                long long notTake = dfs(neigh, 1, i, adj, dp, k);
                children.emplace_back(take, notTake);
            }
        }

        // sort(children.begin(), children.end(), [](const pair<long long, long long>& l, const pair<long long, long long>& r) {
        //     return l.first - l.second < r.first - r.second;
        // });

        sort(children.begin(), children.end(), comparator);

        for (int idx = 0; idx < children.size(); idx++) {
            if (idx < opsToDo)
                answer += children[idx].second;
            else
                answer += max(children[idx].first, children[idx].second);
        }

        return dp[i][j] = answer;
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;

        vector<vector<pair<int, int>>> adj(n);

        for (auto& i : edges) {
            adj[i[0]].emplace_back(i[1], i[2]);
            adj[i[1]].emplace_back(i[0], i[2]);
        }

        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return dfs(0, 0, -1, adj, dp, k);
    }
};
