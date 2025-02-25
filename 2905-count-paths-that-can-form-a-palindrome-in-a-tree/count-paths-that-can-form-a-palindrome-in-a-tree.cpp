class Solution {
public:
    vector<vector<pair<int,char>>> g;
    unordered_map<int,int> freq;
    void dfs(int node,int path){
        freq[path]++;

        for(auto it : g[node]){
            int ch = it.second - 'a';

            path ^= (1<<ch);
            dfs(it.first,path);
            path ^= (1<<ch);
        }
    }


    long long countPalindromePaths(vector<int>& parent, string s) {
        g.clear();freq.clear();
        int n = parent.size();

        g.resize(n);
        for(int i = 1;i<n;i++){
            g[parent[i]].push_back({i,s[i]});
        }
        dfs(0,0);

        long long ans = 0;

        for(auto it : freq){
            long long path = it.first,cnt = it.second;

            // even palindrome 
            ans += (cnt * (cnt - 1)); // divide by 2 last mein karenge bcoz odd mein bhi hai divide by 2 ka jangjat
            for(int i = 0;i<26;i++){
                long long other = path ^ (1 << i);
                if(freq.find(other) == freq.end()) continue;
                ans += (cnt * freq[other]);

            }

        }
        return ans/2;
    }
};