class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        set<long> s;
        long ans = 0;
        vector<vector<long long>> r(n + 1),c(n + 1);
        for(auto it : b){
            r[it[0]].push_back(1LL* it[0] * n + it[1]);
            c[it[1]].push_back(1LL* it[0] * n + it[1]);
        }

        for(auto &it : r){
            sort(it.begin(),it.end());
        }

        for(auto &it : c){
           sort(it.begin(),it.end());
        }

        for(long i = 1;i<=n ;i++){
            if(r[i].size() > 2){
                long siz = r[i].size();
                for(long j = 1;j<siz - 1;j++)
                s.insert(r[i][j]);
            }
        }


for(long i = 1;i<=n ;i++){
            if(c[i].size() > 2){
                long siz = c[i].size();
                for(long j = 1;j<siz - 1;j++){
                    if(s.find(c[i][j]) != s.end()) ans++;
                }
            }
        }



return ans;
        
    }
};