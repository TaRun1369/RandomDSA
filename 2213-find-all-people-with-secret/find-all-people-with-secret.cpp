class Solution {
public:
    class dsu {
    public:
        vector<int> parent, rank;

        dsu(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findUPar(int x) {
            if (x == parent[x]) return x;
            return parent[x] = findUPar(parent[x]);
        }

        void unionByRank(int u, int v) {
            int pu = findUPar(u);
            int pv = findUPar(v);
            if (pu == pv) return;

            if (rank[pu] < rank[pv])
                parent[pu] = pv;
            else if (rank[pv] < rank[pu])
                parent[pv] = pu;
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }

        void reset(int x) {
            parent[x] = x;
            rank[x] = 0;
        }
    };

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        dsu ds(n);

        ds.unionByRank(0, firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> people;

            while (i < meetings.size() && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                ds.unionByRank(x, y);
                people.push_back(x);
                people.push_back(y);
                i++;
            }

            for (int p : people) {
                if (ds.findUPar(p) != ds.findUPar(0)) {
                    ds.reset(p);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == ds.findUPar(0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
