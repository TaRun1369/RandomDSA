class Solution {
public:
    vector<int> prime(){
        vector<int> prim(1e4,0);
        prim[0] = 1,prim[1] = 1;
        for(int i = 2;i<1e4;i++){
            if(prim[i] == 0){
                for(int j = 2;j * i < 1e4;j++){
                    prim[j*i] = 1;
                }
            }
        }
        return prim;
    }

    vector<int> neigh(int n){
        vector<int> ans;
        for(int base = 1;base <= n;base *= 10){
            int d = (n/base)%10;
            if(d > 0){
                ans.push_back(n - base);
            }
            if(d < 9){
                ans.push_back(n + base);
            }
        }
        return ans;
    }
    int minOperations(int n, int m) {
        vector<int> isprime = prime();
        vector<int> dis ( 1e4 , 1e9);
        if(isprime[n] == 0 || isprime[m] == 0) return -1;

        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,n});
        dis[n] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            if(d != dis[u]) continue;

            for(auto it : neigh(u)){
                if(isprime[it] == 0) continue;
                if(dis[it] > dis[u] + u){
                    dis[it] = dis[u] + u;
                    pq.push({dis[it],it});
                }
            }
        }

        if(dis[m] == 1e9) return -1;

        return  dis[m] + m;

    }
};