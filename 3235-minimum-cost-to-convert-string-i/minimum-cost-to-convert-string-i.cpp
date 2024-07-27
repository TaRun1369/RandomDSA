// class Solution {
// public:
//     long long minimumCost(string s, string t, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         int n = cost.size();
//         // vector<vector<pair<int,int>>> adj(n);

//         // for(int i = 0;i<n;i++){
//         //     adj[].push_back({,cost[i]});
//         // }

//         vector<vector<long long>> dist(26,vector<long long>(26,LLONG_MAX));
//         for(int i= 0;i<26;i++) dist[i][i] = 0;

//         for(int i = 0;i<n;i++){
//             int a = original[i] - 'a';
//             int b = changed[i] - 'a';
//             int c = cost[i];
//             dist[a][b] = c;
//         }

//         for(int via = 0;via < 26;via++){
//             for(int i = 0;i<26;i++){
//                 for(int j = 0;j<26;j++){
//                     if(dist[i][via] < LLONG_MAX && dist[via][j] < LLONG_MAX){
//                         dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
//                     }
//                 }
//             }
//         }
//         long long ans= 0;
//         for(int i = 0;i<s.size();i++){
//             if(s[i] != t[i]) {
//                 if(dist[s[i] - 'a'][t[i] - 'a'] >= LLONG_MAX) return -1;
//                 ans += dist[s[i] - 'a'][t[i] - 'a'];
//             }
//         }

//         return ans;



//     }
// };
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = cost.size();
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        for (int i = 0; i < n; i++) {
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            int c = cost[i];
            dist[a][b] = min(dist[a][b], (long long)c);
        }

        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][via] < LLONG_MAX && dist[via][j] < LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                if (dist[s[i] - 'a'][t[i] - 'a'] == LLONG_MAX) return -1;
                ans += dist[s[i] - 'a'][t[i] - 'a'];
            }
        }

        return ans;
    }
};
