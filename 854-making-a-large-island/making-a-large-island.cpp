// class Solution {
// public:
//     int largestIsland(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int siz = n*n;
//         int ans = 0;
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<n;j++){
//                 if(grid[i][j] == 0){
//                     int curr = 0;
//                     unordered_set<int> s;
//                     if(i - 1 >= 0 && grid[i-1][j] == 1){
//                         int UlPar = dsu.findupar(i-1,j,);
//                         s.insert(UlPar);
//                         curr += dsu.size[UlPar];
//                     }
//                     if( i + 1 < n && grid[i + 1][j] == 1 && s.find(dsu.findupar(i + 1,j) ) == s.end() )   {
//                         int Ulpar = dsu.findupar(i + 1,j);
//                         s.insert(Ulpar);
//                         curr += dsu.size[Ulpar];
//                     }
//                     if(j - 1 >= 0 && grid[i][j - 1] == 1 && s.find(dsu.findupar(i,j - 1)) == s.end())         {
//                         int Ulpar = dsu.findupar(i,j - 1);
//                         s.insert(Ulpar);
//                         curr += dsu.size[Ulpar];
//                     }
//                     if(j + 1 < n && grid[i][j + 1] == 1 && s.find(dsu.findupar(i , j + 1)) == s.end())     {
//                         int Ulpar = dsu.findupar(i,j + 1);
//                         // s.insert(Ulpar);
//                         curr += dsu.size[Ulpar];
//                     }
//                     ans = max(ans,curr + 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class dsu {
    vector<int> parent, rank, size;
public:
    dsu(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int getSize(int node) {
        return size[findUPar(node)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        dsu ds(n * n);
        
        auto getIndex = [&](int i, int j) { return i * n + j; };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (i + 1 < n && grid[i + 1][j] == 1) {
                        ds.unionBySize(getIndex(i, j), getIndex(i + 1, j));
                    }
                    if (j + 1 < n && grid[i][j + 1] == 1) {
                        ds.unionBySize(getIndex(i, j), getIndex(i, j + 1));
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int curr = 1;
                    unordered_set<int> s;
                    
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        int up = ds.findUPar(getIndex(i - 1, j));
                        s.insert(up);
                        curr += ds.getSize(up);
                    }
                    if (i + 1 < n && grid[i + 1][j] == 1) {
                        int down = ds.findUPar(getIndex(i + 1, j));
                        if (s.find(down) == s.end()) {
                            s.insert(down);
                            curr += ds.getSize(down);
                        }
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        int left = ds.findUPar(getIndex(i, j - 1));
                        if (s.find(left) == s.end()) {
                            s.insert(left);
                            curr += ds.getSize(left);
                        }
                    }
                    if (j + 1 < n && grid[i][j + 1] == 1) {
                        int right = ds.findUPar(getIndex(i, j + 1));
                        if (s.find(right) == s.end()) {
                            s.insert(right);
                            curr += ds.getSize(right);
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        
        return ans == 0 ? n * n : ans; // If no 0s were changed, return full grid size
    }
};
