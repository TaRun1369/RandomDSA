
// // grenn - 0
// // red - 1
// #define p pair<int,int>
// class Solution {
// public:

//     int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
//         vector<vector<vector<int>>> dist;
//         vector<vector<int>> adj(n+1);
//         for(auto it : edges){
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }

//         vector<int> d1(n+1,INT_MAX),d2 (n+1,INT_MAX);
//         priority_queue<p,vector<p>,greater<p>> pq;
//         pq.push({0,1});
//         d1[1] = 0;

//         while(!pq.empty()){
//             auto t = pq.top();
//             pq.pop();

//             int timepassed = t.first;
//             int node = t.second;

//             if(node == n && d2[n] != INT_MAX){
//                 return d2[n];
//             }

//             int div = timepassed/change;
//             if(div % 2 == 1){ // odd - red signal
//                 timepassed = change * (div + 1);

//             }
//             for(auto it : adj[node]){
//                 if(d1[it] > timepassed + time){
//                     d2[it] = d1[it];
//                     d1[it] = timepassed + time;
//                 }
//                 else if(d2[it] > timepassed + time && d1[it] != timepassed + time){
//                     d2[it] = timepassed + time;
//                     pq.push({timepassed + time,it});

//                 } 
//             }

//         }

// return -1;
//     }
// };
#define p pair<int,int>
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Initialize adjacency list with n + 1 elements
        vector<vector<int>> adj(n + 1); // Fix 1: Properly initialize the adjacency list
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> d1(n + 1, INT_MAX), d2(n + 1, INT_MAX);
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 1});
        d1[1] = 0;

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();

            int timepassed = t.first;
            int node = t.second;

            if(node == n && d2[n] != INT_MAX){
                return d2[n];
            }

            int div = timepassed / change;
            if(div % 2 == 1) { // odd - red signal
                timepassed = change * (div + 1);
            }

            for(auto it : adj[node]){
                if(d1[it] > timepassed + time){
                    d2[it] = d1[it];
                    d1[it] = timepassed + time;
                    pq.push({d1[it], it}); // Fix 2: Always update priority queue when d1[it] is updated
                } else if(d2[it] > timepassed + time && d1[it] != timepassed + time){
                    d2[it] = timepassed + time;
                    pq.push({d2[it], it}); // Fix 3: Always update priority queue when d2[it] is updated
                }
            }
        }
        return -1;
    }
};
